using Microsoft.EntityFrameworkCore;

namespace KPZ04.Models
{
    public class SalesContext: DbContext
    {

        public SalesContext(DbContextOptions<SalesContext> options): base(options) { }

        public DbSet<Lead> Leads { get; set; }
        public DbSet<SalesManager> Sales { get; set; }

    }
}
