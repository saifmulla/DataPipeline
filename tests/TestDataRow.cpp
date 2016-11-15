#include "gtest/gtest.h"
#include "datapipeline/DataRow.H"
#include <iostream>

using namespace DataPipeline;

TEST(TestDataRow, construction){
	DataRow row(3,"travelodge","Glasgow","abc","01415540098",
		"http://travelodge.co.uk/glasgow");
}

TEST(TestDataRow, copyconstruction){
	DataRow row(3,"travelodge","Glasgow","abc","01415540098",
		"http://travelodge.co.uk/glasgow");

	DataRow copyrow(row);

	ASSERT_EQ(row.getRatings(),copyrow.getRatings());
	ASSERT_EQ(row.getHotelName(),copyrow.getHotelName());
}

TEST(TestDataRow, copyassignment){
	DataRow row(3,"travelodge","Glasgow","abc","01415540098",
		"http://travelodge.co.uk/glasgow");

	DataRow copyrow = row;

	ASSERT_EQ(row.getRatings(),copyrow.getRatings());
	ASSERT_EQ(row.getHotelName(),copyrow.getHotelName());
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
