#ifndef DATAPIPELINE_DATAREADER_H
#define DATAPIPELINE_DATAREADER_H

#include "datapipeline/Exports.H"

#include <vector>
#include <memory>
#include <string>

namespace DataPipeline {

class Data; //forward delcaration of class Data

class EXPORTS DataReader{

public:
	// read
	// this function is a pure virtual function, all subclass of DataReader
	// must implement this function. Mainly this function can be used to have 
	// different implementation of file reading based on type of file 
	// being read
	virtual DataPipeline::Data read() = 0;

	virtual std::vector<std::string>& getColumnNames() = 0;

	virtual ~DataReader(){

	}

};

}//end namespace

#endif /* DATAPIPELINE_DATAREADER_H */