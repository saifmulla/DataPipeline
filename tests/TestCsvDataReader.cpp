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

TEST(TestCsvDataReader, breakstring){
	std::string str = "The Gibson,\"63847 Lowe Knoll, East Maxine, WA 97030-4876\",5,Dr. Sinda Wyman,1-270-665-9933x1626,http://www.paucek.com/search.htm";
	std::stringstream others;
	int start = str.find('"');
	std::size_t until = str.rfind('"');
	others << str.substr(0,start-1);
	others << str.substr(until+1,str.length()-start);
	std::string address = str.substr(start+1,(until-start-1));
	std::cout << address << std::endl;
	std::cout << "Others " << others.str() << std::endl;
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}