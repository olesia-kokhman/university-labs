using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Sales.Model;

namespace Sales.UI.ViewModels
{
    public class OrderViewModel: ViewModelBase
    {

        private int orderId;
        private DateTime orderDate;
        private Customer customer;
        private IEnumerable<Product> products;

        public int OrderId
        {
            get { return orderId; }
            set 
            { 
                orderId = value; 
                OnPropertyChanged(nameof(OrderId));
            }
        }

        public DateTime OrderDate
        {
            get { return orderDate; }
            set 
            { 
                orderDate = value; 
                OnPropertyChanged(nameof(OrderDate)); 
            }
        }

        public Customer Customer
        {
            get { return customer; }
            set
            {
                customer = value;
                OnPropertyChanged(nameof(Customer));
            }
        }

        public IEnumerable<Product> Products
        {
            get { return products; }
            set
            {
                products = value;
                OnPropertyChanged(nameof(Products));
            }
        }

    }
}
