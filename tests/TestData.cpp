#include "gtest/gtest.h"
#include "datapipeline/DataRow.H"
#include "datapipeline/Data.H"
#include <iostream>

using namespace DataPipeline;

TEST(TestData, construction){
	Data* data = new Data();
	if(data != nullptr)
		SUCCEED();
	else
		FAIL();
}

TEST(TestData, addrow){
	Data data;

	data.addRow(new DataRow(3,"travelodge","Glasgow","abc","01415540098",
		"http://travelodge.co.uk/glasgow"));
	data.addRow(new DataRow(3,"travelodge","Glasgow","abc","01415540098",
		"http://travelodge.co.uk/glasgow"));
	data.addRow(new DataRow(3,"travelodge","Glasgow","abc","01415540098",
		"http://travelodge.co.uk/glasgow"));

	ASSERT_EQ(3,data.size());
}

TEST(TestData, addrowwithmove){
	Data data;

	data.addRow(std::move(new DataRow(3,"travelodge","Glasgow","abc","01415540098",
		"http://travelodge.co.uk/glasgow")));
	data.addRow(std::move(new DataRow(3,"travelodge","Glasgow","abc","01415540098",
		"http://travelodge.co.uk/glasgow")));
	data.addRow(std::move(new DataRow(3,"travelodge","Glasgow","abc","01415540098",
		"http://travelodge.co.uk/glasgow")));
	ASSERT_EQ(3,data.size());

	DataRow cc = data.getRow(1);
	ASSERT_EQ(3,cc.getRatings());
}

TEST(TestData, copyconstruction){
	Data data;

	data.addRow(std::move(new DataRow(5,"travelodge","Glasgow","abc","01415540098",
		"http://travelodge.co.uk/glasgow")));
	data.addRow(std::move(new DataRow(3,"travelodge","Glasgow","abc","01415540098",
		"http://travelodge.co.uk/glasgow")));
	data.addRow(std::move(new DataRow(3,"travelodge","Glasgow","abc","01415540098",
		"http://travelodge.co.uk/glasgow")));

	Data copy(data);

	DataRow copyrow = data.getRow(0);
	ASSERT_EQ(5,copyrow.getRatings());
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
