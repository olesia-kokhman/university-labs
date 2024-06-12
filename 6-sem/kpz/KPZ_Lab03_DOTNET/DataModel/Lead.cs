using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KPZ_Lab03_DOTNET.DataModel
{
    public class Lead
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Location { get; set; }
        public string Status { get; set; }
        public int ResourceId { get; set; }
        public DateTime CreatedDate { get; set; }
        public DateTime ConnectedDate { get; set; }
    }
}
