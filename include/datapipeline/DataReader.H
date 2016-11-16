#ifndef DATAPIPELINE_DATAREADER_H
#define DATAPIPELINE_DATAREADER_H

///////////////////////////////////////////////////////////////////////////////
// DataReader
// This is a base class for all DataReaders, any class including functionality
// to read data from different formats must inherit from this base class
// and implement virtual functions of the base class in its subclass

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
	virtual bool read(DataPipeline::Data& data) = 0;

	// Get All column names
	// if the input file contains column names then read them in the 
	// list to be useful later
	virtual std::vector<std::string>& getColumnNames() = 0;

	// base class default destructor
	virtual ~DataReader(){

	}

};

}//end namespace

#endif /* DATAPIPELINE_DATAREADER_H */