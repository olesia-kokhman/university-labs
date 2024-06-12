using Microsoft.EntityFrameworkCore;

namespace KPZ_Lab03_DOTNET.DataModel
{
    public class SalesDBContext : DbContext
    {
        public DbSet<Lead> Leads { get; set; }
        public DbSet<Resource> Resources { get; set; }
        public DbSet<SalesManager> Sales { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseNpgsql("Host=localhost;Username=postgres;Password=somepassword;Database=sales;");
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Lead>(entity =>
            {
                entity.Property(e => e.Id).HasColumnName("id");

                entity.Property(e => e.Name).HasColumnName("name");

                entity.Property(e => e.Location).HasColumnName("location");

                entity.Property(e => e.Status).HasColumnName("status");

                entity.Property(e => e.ResourceId).HasColumnName("resourse_id");

                entity.Property(e => e.CreatedDate).HasColumnName("created_at");

                entity.Property(e => e.ConnectedDate).HasColumnName("connected_at");
            });

            modelBuilder.Entity<Resource>(entity =>
            {
                entity.Property(e => e.Id).HasColumnName("id");

                entity.Property(e => e.Name).HasColumnName("name");

                entity.Property(e => e.EffectiveRate).HasColumnName("effective_rate");

                entity.Property(e => e.Type).HasColumnName("type");

            });

            modelBuilder.Entity<SalesManager>(entity =>
            {
                entity.Property(e => e.Id).HasColumnName("id");

                entity.Property(e => e.Name).HasColumnName("name");

                entity.Property(e => e.ProjectNumber).HasColumnName("project_number");

            });
        }
    }
}
