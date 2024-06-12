using Microsoft.VisualStudio.TestTools.UnitTesting;
using Sales.Model.Serialization;
using System;
using System.Collections.Generic;

namespace Sales.Model.Test
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestMethodSerialize()
        {
            var model = new DataModel();
            model.Events = new List<Event>() { new Event() { Name = "Happy birthday",
            Date = new DateTime(1980, 10, 10)} };
            model.Projects = new List<Project>() { new Project() { Name = "Some project" } };
            model.Tasks = new List<Task>() { new Task() { Name = "Task1" }, new Task() { Name = "Task2" } };

            DataSerializer.SerializeData(@"C:\university\5-sem\KPZ\testfile.dat", model);
        }

        [TestMethod]
        public void TestMethodDeSerialize()
        {
            var model = DataSerializer.DeserializeItem(@"C:\university\5-sem\KPZ\testfile.dat");
        }
    }
}