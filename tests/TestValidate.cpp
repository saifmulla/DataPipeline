#include "gtest/gtest.h"
#include "datapipeline/Data.H"
#include "datapipeline/Validate.H"
#include <iostream>

using namespace DataPipeline;

TEST(TestValidate,constructor){
	Data* data = new Data();
	Validate validate(data);
}

TEST(TestValidate,ratings){
	Data* data = new Data();
	Validate validate(data);
	ASSERT_EQ(5,validate.checkRatings(6));
	ASSERT_EQ(0,validate.checkRatings(-2));
	ASSERT_EQ(4,validate.checkRatings(4));
}


int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}