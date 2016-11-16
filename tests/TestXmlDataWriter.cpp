#include "gtest/gtest.h"
#include "datapipeline/XmlDataWriter.H"

using namespace DataPipeline;

TEST(TestXmlDataWriter, construction){
	XmlDataWriter writer;
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
