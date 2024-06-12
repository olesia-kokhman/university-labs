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
    public class SalesManagerController : ControllerBase
    {
        private readonly SalesContext _context;

        public SalesManagerController(SalesContext context)
        {
            _context = context;
        }

        [HttpGet]
        public async Task<IEnumerable<SalesManager>> GetSales()
        {
            return await _context.Sales.ToListAsync();
        }

        [HttpGet("{id}")]
        [ProducesResponseType(typeof(SalesManager), StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        public async Task<IActionResult> GetSalesManagerById(int id)
        {
            var manager = await _context.Sales.FindAsync(id);
            return manager == null ? NotFound() : Ok(manager);
        }

        [HttpPost]
        [ProducesResponseType(StatusCodes.Status201Created)]
        public async Task<IActionResult> CreateSalesManager(SalesManager manager)
        {
            await _context.Sales.AddAsync(manager);
            await _context.SaveChangesAsync();

            return CreatedAtAction(nameof(GetSalesManagerById), new { Id = manager.Id }, manager);
        }

        [HttpPut("{id}")]
        [ProducesResponseType(StatusCodes.Status204NoContent)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        public async Task<IActionResult> UpdateSalesManager(int id, SalesManager manager)
        {
            if (id != manager.Id)
            {
                return BadRequest();
            }

            _context.Entry(manager).State = EntityState.Modified;
            await _context.SaveChangesAsync();

            return NoContent();
        }

        [HttpDelete("{id}")]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        [ProducesResponseType(StatusCodes.Status204NoContent)]
        public async Task<IActionResult> DeleteSalesManager(int id)
        {
            var deletedManager = await _context.Sales.FindAsync(id);

            if (deletedManager == null)
            {
                return NotFound();
            }
            _context.Sales.Remove(deletedManager);
            await _context.SaveChangesAsync();

            return NoContent();
        }
    }
}
