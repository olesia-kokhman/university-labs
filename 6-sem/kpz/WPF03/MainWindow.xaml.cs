using KPZ_Lab03_DOTNET.DataModel;
using KPZ_Lab03_DOTNET.DataModel.Repositories;
using System;
using System.Collections.ObjectModel;
using System.Windows;
using System.Windows.Controls;

namespace WPF03
{
    public partial class MainWindow : Window
    {

        private readonly SalesDBContext _context;
        private LeadRepository _leadRepository;

        public ObservableCollection<Lead> Leads { get; set; }

        public MainWindow()
        {
            InitializeComponent();

            _context = new SalesDBContext();
            _leadRepository = new LeadRepository(_context);

            Leads = new ObservableCollection<Lead>(_leadRepository.readLeads());
            DataContext = this;
        }

        private void LeadsDataGrid_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            Lead selectedLead = (Lead)LeadsDataGrid.SelectedItem;

            if(selectedLead != null)
            {
                IdTextBox.Text = selectedLead.Id.ToString();
                NameTextBox.Text = selectedLead.Name;
                LocationTextBox.Text = selectedLead.Location;
                StatusTextBox.Text = selectedLead.Status;
                ResourceTextBox.Text = selectedLead.ResourceId.ToString();
                CreatedAtTextBox.Text = selectedLead.CreatedDate.ToString();
                ConnectedAtTextBox.Text = selectedLead.ConnectedDate.ToString();
            }
        }

        private void DeleteLead_Click(object sender, RoutedEventArgs e)
        {
            Lead selectedLead = (Lead)LeadsDataGrid.SelectedItem;

            if(selectedLead != null)
            {
                _leadRepository.deleteLead(selectedLead.Id);

                Leads.Remove(selectedLead);
                UpdateLeadsView();
            }
        }

        private void CreateLead_Click(object sender, RoutedEventArgs e)
        {
            Lead createdLead = GenerateLeadFromTextBoxes();

            _leadRepository.createLead(createdLead);
            Leads.Add(createdLead);
            UpdateLeadsView();
        }

        private void UpdateLead_Click(object sender, RoutedEventArgs e)
        {
            Lead updatedLead = GenerateLeadFromTextBoxes();

            _leadRepository.updateLead(updatedLead);
            UpdateLeadsView();
        }

        private Lead GenerateLeadFromTextBoxes()
        {
            Lead lead = new Lead
            {
                Id = int.Parse(IdTextBox.Text),
                Name = NameTextBox.Text,
                Location = LocationTextBox.Text,
                Status = StatusTextBox.Text,
                ResourceId = int.Parse(ResourceTextBox.Text),
                CreatedDate = DateTime.Parse(CreatedAtTextBox.Text).ToUniversalTime(),
                ConnectedDate = DateTime.Parse(ConnectedAtTextBox.Text).ToUniversalTime()
            };

            return lead;
        }

        private void UpdateLeadsView()
        {
            LeadsDataGrid.Items.Refresh();

            IdTextBox.Text = "";
            NameTextBox.Text = "";
            LocationTextBox.Text = "";
            StatusTextBox.Text = "";
            ResourceTextBox.Text = "";
            CreatedAtTextBox.Text = "";
            ConnectedAtTextBox.Text = "";
        }
    }
}
