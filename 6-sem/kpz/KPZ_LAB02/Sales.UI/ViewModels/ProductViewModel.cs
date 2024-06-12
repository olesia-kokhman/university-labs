using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sales.UI.ViewModels
{
    public class ProductViewModel: ViewModelBase
    {
        private int productId;
        private string name;
        private double price; 

        public int ProductId
        {
            get { return productId; }
            set 
            { 
                productId = value;
                OnPropertyChanged(nameof(ProductId));
            }
        }

        public string Name
        {
            get { return name; }    
            set 
            { 
                name = value;
                OnPropertyChanged(nameof(Name));
            }
        }

        public double Price
        {
            get { return price; }
            set 
            { 
                price = value;
                OnPropertyChanged(nameof(Price));
            }
        }
    }
}
