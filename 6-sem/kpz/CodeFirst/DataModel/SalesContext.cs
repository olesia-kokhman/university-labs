using Microsoft.EntityFrameworkCore;

namespace CodeFirst.DataModel
{
    public class SalesContext: DbContext
    {
        public DbSet<Lead> Leads { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseNpgsql("Host=localhost;Username=postgres;Password=somepassword;Database=salesCF;");
        }
    }
}
