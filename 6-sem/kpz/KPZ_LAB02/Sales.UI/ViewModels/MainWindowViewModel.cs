using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using Sales.Model;

namespace Sales.UI.ViewModels
{
    public class MainWindowViewModel: ViewModelBase
    {
        public ObservableCollection<ProductViewModel> products;
        public ObservableCollection<CustomerViewModel> customers;
        public ObservableCollection<OrderViewModel> orders;

        public ICommand ChangePriceCommand { get; set; }

        public MainWindowViewModel()
        {
            ChangePriceCommand = new Command(ChangePrice);
        }

        
        ///////////////////////////////////////////////
        
        private ProductViewModel selectedProduct;
        private CustomerViewModel selectedCustomer;
        private OrderViewModel selectedOrder;

        public ProductViewModel SelectedProduct
        {
            get { return selectedProduct; }
            set 
            { 
                selectedProduct = value; 
                OnPropertyChanged(nameof(SelectedProduct));
            }
        }

        public CustomerViewModel SelectedCustomer
        {
            get { return selectedCustomer; }
            set 
            { 
                selectedCustomer = value; 
                OnPropertyChanged(nameof(SelectedCustomer)); 
            }
        }

        public OrderViewModel SelectedOrder
        {
            get { return selectedOrder; }
            set
            {
                selectedOrder = value;
                OnPropertyChanged(nameof(SelectedOrder));
            }
        }

        ///////////////////////////////////////////////

        public ObservableCollection<ProductViewModel> Products
        {
            get { return products; }
            set 
            { 
                products = value; 
                OnPropertyChanged(nameof(Products)); 
            }
        }

        public ObservableCollection <CustomerViewModel> Customers
        {
            get { return customers; }
            set 
            { 
                customers = value; 
                OnPropertyChanged(nameof(Customers)); 
            }
        }

        public ObservableCollection<OrderViewModel> Orders
        {
            get { return orders; }
            set
            {
                orders = value;
                OnPropertyChanged(nameof(Orders));
            }
        }

        ///////////////////////////////////////////////


        private void ChangePrice(object parameter)
        {
            ProductViewModel product = (ProductViewModel)parameter;
            if (product != null)
            {
                product.Price = 15.7;
            }
        }

    }
}
