using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

using Microsoft.EntityFrameworkCore;

using KPZ04.Models;
using Microsoft.AspNetCore.Cors;

namespace KPZ04.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    [EnableCors("AllowOrigin")]
    public class LeadController : ControllerBase
    {
        private readonly SalesContext _context;

        public LeadController(SalesContext context)
        {
            _context = context;
        }

        [EnableCors("AllowOrigin")]
        [HttpGet]
        public async Task<IEnumerable<Lead>> GetLeads()
        {
            return await _context.Leads.ToListAsync();
        }

        [EnableCors("AllowOrigin")]
        [HttpGet("{id}")]
        [ProducesResponseType(typeof(Lead), StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        public async Task<IActionResult> GetLeadById(int id)
        {
            var lead = await _context.Leads.FindAsync(id);
            return lead == null ? NotFound() : Ok(lead);
        }

        [EnableCors("AllowOrigin")]
        [HttpPost]
        [ProducesResponseType(StatusCodes.Status201Created)]
        public async Task<IActionResult> CreateLead(Lead createdLead)
        {
            await _context.Leads.AddAsync(createdLead);
            await _context.SaveChangesAsync();

            return CreatedAtAction(nameof(GetLeadById), new { Id = createdLead.Id }, createdLead);
        }

        [EnableCors("AllowOrigin")]
        [HttpPut("{id}")]
        [ProducesResponseType(StatusCodes.Status204NoContent)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        public async Task<IActionResult> UpdateLead(int id, Lead updatedLead)
        {
            if(id != updatedLead.Id)
            {
                return BadRequest();
            }

            _context.Entry(updatedLead).State = EntityState.Modified;
            await _context.SaveChangesAsync();

            return NoContent();
        }

        [EnableCors("AllowOrigin")]
        [HttpDelete("{id}")]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        [ProducesResponseType(StatusCodes.Status204NoContent)]
        public async Task<IActionResult> DeleteLead(int id)
        {
            var deletedLead = await _context.Leads.FindAsync(id);

            if(deletedLead == null)
            {
                return NotFound();
            }
            _context.Leads.Remove(deletedLead);
            await _context.SaveChangesAsync();

            return NoContent();
        }
    }
}
