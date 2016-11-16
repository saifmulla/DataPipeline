#include "gtest/gtest.h"
#include "datapipeline/XmlDataWriter.H"
#include "datapipeline/CsvDataReader.H"
#include <memory>

using namespace DataPipeline;

TEST(TestXmlDataWriter, construction){
	CsvDataReader reader("../data/test_1.csv");
	Data data;
	reader.read(data);
	XmlDataWriter writer;
	writer.write(data,"test_2.xml");
}

TEST(TestXmlDataWriter, largefile){
	CsvDataReader reader("../data/hotels.csv");
	Data data;
	reader.read(data);
	XmlDataWriter writer;
	writer.write(data,"hotels.xml");
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
