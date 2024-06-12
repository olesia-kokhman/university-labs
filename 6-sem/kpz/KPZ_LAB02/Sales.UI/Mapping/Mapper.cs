using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using AutoMapper;
using Sales.UI.ViewModels;
using Sales.Model;

namespace Sales.UI.Mapping
{
    public class Mapper : Profile
    {
        public Mapper() {
            CreateMap<MainWindowViewModel, DataModel>();
            CreateMap<DataModel, MainWindowViewModel>();

            CreateMap<Product, ProductViewModel>();
            CreateMap<ProductViewModel, Product>();

            CreateMap<Customer, CustomerViewModel>();
            CreateMap<CustomerViewModel, Customer>();

            CreateMap<Order, OrderViewModel>();
            CreateMap<OrderViewModel, Order>();
        }
    }
}
