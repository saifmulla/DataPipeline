//TestExports.cpp
#include <iostream>
#include "gtest/gtest.h"
#include "datapipeline/Exports.H"

 TEST(TestExports,checkValues){
 #ifdef _MSC_VER
 	ASSERT_EQ(1,SEXPORTS);
 #elif defined(__linux__) || (__APPLE__)
 	ASSERT_EQ(0,SEXPORTS);
 #endif
 }

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}