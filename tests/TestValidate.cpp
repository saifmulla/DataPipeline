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

TEST(TestValidate,url){
	Data* data = new Data();
	Validate validate(data);
	std::string sample1 = "http://saifmulla.com";
	std::string sample2 = "http://saifmulla.com/index.php";
	std::string sample3 = "saifmullacom";
	ASSERT_EQ(sample1,validate.checkUrl(sample1));
	ASSERT_EQ(sample2,validate.checkUrl(sample2));
	ASSERT_EQ("",validate.checkUrl(sample3));
}


int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}