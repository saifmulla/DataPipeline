#include "gtest/gtest.h"
#include "datapipeline/CsvDataReader.H"
#include <iostream>
#include <string>
#include <sstream>

using namespace DataPipeline;

TEST(TestCsvDataReader, construction){
	CsvDataReader reader("../data/test_1.csv");
	Data data = reader.read();
	ASSERT_EQ(6,data.size());
	std::vector<std::string>& columns = reader.getColumnNames();
	ASSERT_EQ(6,columns.size());
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}