using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

using Sales.Model;
using Sales.UI.ViewModels;

using AutoMapper;
using Sales.UI.Mapping;

namespace Sales.UI
{

    public partial class App : Application
    {

        private DataModel _model;
        private MainWindowViewModel _mainWindowViewModel;
        private IMapper mapper;

        public App()
        {
            var config = new MapperConfiguration(cfg => cfg.AddProfile<Mapping.Mapper>());
            mapper = config.CreateMapper();
            _model = DataModel.Load();
            _mainWindowViewModel = mapper.Map<DataModel, MainWindowViewModel>(_model);
            var mainWindow = new MainWindow() { DataContext = _mainWindowViewModel };
            mainWindow.Show();
        }


        protected override void OnExit(ExitEventArgs e)
        {
            try
            {
                _model = mapper.Map<MainWindowViewModel, DataModel>(_mainWindowViewModel);
                _model.Save();
            } 
            catch(Exception) { 
            
                base.OnExit(e);
                throw;
            }
        }
    }
}
