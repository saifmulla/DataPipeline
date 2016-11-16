#include "gtest/gtest.h"
#include "datapipeline/JsonDataWriter.H"
#include "datapipeline/CsvDataReader.H"
#include <memory>

using namespace DataPipeline;

TEST(TestJsonDataWriter, construction){
	CsvDataReader reader("../data/test_1.csv");
	Data data = reader.read();
	JsonDataWriter writer;
	writer.write(data,"test_2.json");
}

TEST(TestJsonDataWriter, largefile){
	CsvDataReader reader("../data/hotels.csv");
	Data data = reader.read();
	JsonDataWriter writer;
	writer.write(data,"hotels.json");
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
