using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Serialization;
using Sales.Model.Serialization;

using System.IO;

namespace Sales.Model
{
    [DataContract]
    public class DataModel
    { 

        [DataMember]
        public IEnumerable<Product> Products { get; set; }

        [DataMember]
        public IEnumerable<Customer> Customers { get; set; }

        [DataMember]
        public IEnumerable<Order> Orders { get; set; }

        public static string DataPath = @"C:\university\5-sem\KPZ\sales_model_data.dat";

        public DataModel()
        {

            Products = new List<Product>()
            {
                new Product() { ProductId = 1, Name = "Apple", Price = 5.5 }, 
                new Product() { ProductId = 2, Name = "Banana", Price = 10.7 }
            };

            Customers = new List<Customer>()
            {
                new Customer { CustomerId = 1, Name = "John Doe", Email = "john@example.com" },
                new Customer { CustomerId = 2, Name = "Jane Smith", Email = "jane@example.com" }
            };

            Orders = new List<Order>();

        }

        public static DataModel Load()
        {
            //DataModel dataModel = new DataModel();
            //DataSerializer.SerializeData(DataPath, dataModel);
            //return dataModel;

            if (File.Exists(DataPath))
            {
                return DataSerializer.DeserializeItem(DataPath);
            }

            return new DataModel();
        }

        public void Save()
        {
            DataSerializer.SerializeData(DataPath, this);
        }


    }

}
