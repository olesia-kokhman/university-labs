using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace Sales.UI.ViewModels
{
    public class CustomerViewModel: ViewModelBase
    {
        private int customerId;
        private string name;
        private string email; 

        public int CustomerId
        {
            get { return customerId; }
            set 
            { 
                customerId = value;
                OnPropertyChanged(nameof(CustomerId));
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

        private string Email
        {
            get { return email; }
            set
            {
                email = value;
                OnPropertyChanged(nameof(Email));
            }
        }  

    }

}
