#ifndef DATAPIPELINE_DATAREADER_H
#define DATAPIPELINE_DATAREADER_H

#include "datapipeline/Exports.H"
#include <vector>

namespace DataPipeline {

class EXPORTS DataReader{

private:
	std::vector<std::string> columnNames;

public:
	// read
	// this function is a pure virtual function, all subclass of DataReader
	// must implement this function. Mainly this function can be used to have 
	// different implementation of file reading based on type of file 
	// being read
	virtual void read(const std::string fileName) = 0;

	virtual unique_ptr<std::string>& getColumnName() = 0;

	virtual ~DataReader(){
	}

};

}//end namespace

#endif /* DataPipeline */