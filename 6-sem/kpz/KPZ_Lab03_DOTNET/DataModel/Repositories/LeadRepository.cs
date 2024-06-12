using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Microsoft.EntityFrameworkCore;

namespace KPZ_Lab03_DOTNET.DataModel.Repositories
{
    public class LeadRepository
    {
        private readonly SalesDBContext _context;

        public LeadRepository(SalesDBContext context)
        {
            _context = context;
        }

        public IEnumerable<Lead> readLeads()
        {
            return _context.Leads.ToList();
        }

        public void createLead(Lead lead)
        {
            _context.Leads.Add(lead);
            _context.SaveChanges();
        }

        public void updateLead(Lead lead)
        {
            var existingLead = _context.Leads.Find(lead.Id);
            if (existingLead != null)
            {
                _context.Entry(existingLead).CurrentValues.SetValues(lead);
                _context.SaveChanges();
            }
        }

        public void deleteLead(int id)
        {
            var lead = _context.Leads.Find(id);
            if(lead != null)
            {
                _context.Leads.Remove(lead);
                _context.SaveChanges();
            }
        }

    }
}
