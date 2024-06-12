using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KPZ_Lab03_DOTNET.DataModel.Repositories
{
    public class SalesRepository
    {
        private readonly SalesDBContext _context;

        public SalesRepository(SalesDBContext context)
        {
            _context = context;
        }

        public IEnumerable<SalesManager> readSales()
        {
            return _context.Sales.ToList();
        }

        public void createResource(SalesManager sales)
        {
            _context.Sales.Add(sales);
            _context.SaveChanges();
        }

        public void updateResource(SalesManager sales)
        {
            var existingSales = _context.Sales.Find(sales.Id);
            if (existingSales != null)
            {
                _context.Entry(existingSales).CurrentValues.SetValues(sales);
                _context.SaveChanges();
            }
        }

        public void deleteSales(int id)
        {
            var sales = _context.Sales.Find(id);
            if (sales != null)
            {
                _context.Sales.Remove(sales);
                _context.SaveChanges();
            }
        }

    }
}
