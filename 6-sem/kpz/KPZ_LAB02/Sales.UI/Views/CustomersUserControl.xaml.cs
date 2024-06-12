using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using Sales.UI.ViewModels;

namespace Sales.UI.Views
{
    
    public partial class CustomersUserControl : UserControl
    {
        public static readonly DependencyProperty SelectedCustomerProperty =
            DependencyProperty.Register("SelectedCustomer", typeof(CustomerViewModel), typeof(CustomersUserControl));

        public CustomerViewModel SelectedCustomer
        {
            get { return (CustomerViewModel)GetValue(SelectedCustomerProperty); }
            set { SetValue(SelectedCustomerProperty, value); }
        }

        public CustomersUserControl()
        {
            InitializeComponent();
            SelectedCustomer = new CustomerViewModel();
        }

        private void ChangeCustomerName_Click(object sender, RoutedEventArgs e)
        {
            SelectedCustomer.Name = "Modified";
        }
    }
}
