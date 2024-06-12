using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeFirst.DataModel
{
    public class Lead
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Status { get; set; }
        public double Budget { get; set; }
    }
}
