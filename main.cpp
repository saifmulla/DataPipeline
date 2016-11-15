#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	// firstly check if name of file is supplied as standard input
	// if not then the program terminates
	if(argc<=1){
		std::cerr << "Please supply name of the file to be processed, exiting...\n";
		exit(-1);		
	}

	// if name supplied read name of the file
	std::string fileName = static_cast<std::string>(argv[1]);

	// 1. determine type of file supplied through extension
	// 2. if extension found then process appropriate file reader
	// 3. read data with datareader
	// 4. validate data and remove invalid data
	// 5. choose data sorting 
	// 6. write formated data to requested data formate

	return 0;
}