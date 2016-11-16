#ifndef DATAPIPELINE_CSVDATAREADER_H
#define DATAPIPELINE_CSVDATAREADER_H

///////////////////////////////////////////////////////////////////////////////
// CsvDataReader
//
// this is a implementation of base class DataReader, it provides implementation
// functionality for reading csv files

#include "datapipeline/DataReader.H"
#include "datapipeline/Data.H"
#include "datapipeline/DataRow.H"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

namespace DataPipeline {

class EXPORTS CsvDataReader : public DataReader {
private:
	std::vector<std::string> columnNames_; // store names of column headings

	std::string fileName_; // name of csv file from which data must be read

public:
	// default and only way of instantiaing the class
	explicit CsvDataReader(const std::string& fileName);

	// read
	// implementation of pure virtual function read from base class
	// in to subclass
	virtual bool read(DataPipeline::Data& data) override;

	// return column names
	virtual std::vector<std::string>& getColumnNames() override;

	//
	~CsvDataReader(){
		columnNames_.clear();
		fileName_ = "";
	}

};

}// end namespace

#endif /** DATAPIPELINE_CSVDATAREADER_H */