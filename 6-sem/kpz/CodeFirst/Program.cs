using CodeFirst.DataModel;


namespace CodeFirst 
{
    class Program
    {
        static void Main(string[] args)
        {
            SalesContext context = new SalesContext();
            Lead lead = new Lead()
            {
                Id = 1,
                Name = "John Rich",
                Status = "Qualified"
            };

            context.Leads.Add(lead);
            context.SaveChanges();
        }
    }
}