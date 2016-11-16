///////////////////////////////////////////////////////////////////////////////
// This is the main executable file to intereact with DataPipeline library
// on compilation this will generate an executable call 'run' whic will 
// accept command line arguments


#include "DataPipeline.H"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace DataPipeline;

int main(int argc, char* argv[])
{
	// firstly check if name of file is supplied as standard input
	// if not then the program terminates
	if(argc<=3){
		std::cerr << "Please supply name of the file to be processed,\n" <<
		" options are <filename> <format> (xml,json) <output_filename>\n exiting...";
		exit(-1);		
	}

	// if name supplied read name of the file
	std::string fileName = static_cast<std::string>(argv[1]);
	// output file name
	std::string outputfile = static_cast<std::string>(argv[3]);
	// read type of format in 3 letters similar to extensions
	std::string format = static_cast<std::string>(argv[2]);

	// TODO: 1. determine type of file supplied through extension
	// TODO: 2. if extension found then process appropriate file reader
	// TODO: use enum class to compare output format types
	// instantiating dataWriter with a appropriate subclass
	DataWriter* writer;
	// if output format is xml
	if(format == "xml" || format == "XML")
		writer = new XmlDataWriter();
	else if(format == "json" || format == "JSON")//if output is json
		writer = new JsonDataWriter();
	else
	{
		std::cerr << "Presently this format is not supported " <<
		" or is not a valid one. quitting ...\n";
		exit(-1);
	}

	// create object of DataReader to CsvDataReader
	DataReader* reader = new CsvDataReader(fileName);
	// 3. read data with datareader
	Data data;
	reader->read(data);
	// TODO: 4. validate data and remove invalid data
	// TODO: 5. choose data sorting 
	// 6. write formated data to requested data format
	writer->write(data,outputfile);

	return 0;
}