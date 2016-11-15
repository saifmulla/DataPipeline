#include "datapipeline/CsvDataReader.H"

DataPipeline::CsvDataReader::CsvDataReader(const std::string& fileName)
:columnNames_(0),fileName_(fileName)
{
}

DataPipeline::Data DataPipeline::CsvDataReader::read()
{
	DataPipeline::Data localdata;
	// use ifstream to read data from file into file pointer
	std::ifstream inf(fileName_);
	// TODO: fix ifstream test failure issue
	if (!inf){
      // Print an error and exit
      std::cerr << "file could not be opened for reading!\n";
      exit(-1);
	  }
	/*
	 * for the purpose of clearing out the first heading line
	 * a first readline is done so this eliminate the use of branching statements
	 * in the loop
	 */
	std::string dump;
	getline(inf,dump);// read the first line in the file
	std::stringstream temp(dump);
	std::string cell;

	while(getline(temp,cell,','))
		columnNames_.push_back(cell);

	// new create datarows
	int counter = 0;

	std::string line;
	while(std::getline(inf,line))
	{
		// read data from the file into a string and print it
		// std::stringstream linerow(line);
		// basically reading from a comma seperated string/line is not 
		// straight forward therefore it requires extra string processing
		// because the address section of line is enclosed in double quotes
		// therefore here first a new string is created for address string 
		// and remaining comma seperated string is retained

		// finding first occurence of (") in line
		int first_occ = line.find('"');
		// search for final occurence from end
		int last_occ = line.rfind('"');
		// obtain address string 
		std::string address = line.substr(first_occ,(last_occ-first_occ-1));
		// next obtain the remaining comma seperated string
		std::stringstream commastr;
		commastr << line.substr(0,first_occ-1);
		commastr << line.substr(last_occ+1,line.length()-first_occ);

		//store data generated for other remaining columns
		std::vector<std::string> columns(columnNames_.size()-1);
		std::string column;
		int index = 0;
		while(getline(commastr,column,',')){
			columns[index] = column;
			index++;
		}

		// now create a data row for each line or row from file
		localdata.addRow(new DataPipeline::DataRow(
			stoi(columns[1]),
			columns[0],
			address,
			columns[2],
			columns[3],
			columns[4]
			));

	}

	inf.close();

	return localdata;
}

std::vector<std::string>& 
DataPipeline::CsvDataReader::getColumnNames()
{
	return columnNames_;
}