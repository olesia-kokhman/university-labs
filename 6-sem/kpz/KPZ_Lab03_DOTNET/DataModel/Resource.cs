using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KPZ_Lab03_DOTNET.DataModel
{
    public class Resource
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int EffectiveRate { get; set; }
        public string Type { get; set; }
    }
}
