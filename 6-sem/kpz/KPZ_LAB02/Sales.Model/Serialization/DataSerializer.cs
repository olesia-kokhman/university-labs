using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

using System.Runtime.Serialization;
using System.Xml;

namespace Sales.Model.Serialization
{
    public class DataSerializer
    {
        public static void SerializeData(string fileName, DataModel data)
        {
            var serializer = new DataContractSerializer(typeof(DataModel));
            using (var writer = XmlWriter.Create(fileName))
            {
                serializer.WriteObject(writer, data);
            }
        }

        public static DataModel DeserializeItem(string fileName)
        {
            if (!File.Exists(fileName))
            {
                throw new FileNotFoundException($"File '{fileName}' not found.");
            }

            var serializer = new DataContractSerializer(typeof(DataModel));
            using (var reader = XmlReader.Create(fileName))
            {
                return (DataModel)serializer.ReadObject(reader);
            }
        }

    }
}
