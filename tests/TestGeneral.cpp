#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <regex>

TEST(TestGeneral, breakstring){
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

TEST(TestGeneral, regex){
	if (std::regex_match ("subject", std::regex("(sub)(.*)") ))
		SUCCEED();
	else
		FAIL();

	if (std::regex_match ("aubject", std::regex("(sub)(.*)") ))
		SUCCEED();
	else
		FAIL();

	std::regex validurl("#((?:https?|http)://(?:\\S*?\\.\\S*?)(?:[\\s)\\[\\]{},;\"\':<]|\\.\\s|$))#");
	if(std::regex_match("http://saifmullacom",validurl))
		SUCCEED();
	else
		FAIL();	

}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}