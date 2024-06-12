namespace KPZ04.Models
{
    public class Lead
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Location { get; set; }
        public LeadStatus Status { get; set; }
        public DateTime CreatedDate { get; set; }
        
    }

    public enum LeadStatus
    {
        Prospective, Connected, Interested, Refused, Contracted
    }
}
