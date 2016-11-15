#ifndef DATAPIPELINE_CSVDATAREADER_H
#define DATAPIPELINE_CSVDATAREADER_H

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
	std::vector<std::string> columnNames_;

	std::string fileName_;
public:
	CsvDataReader(const std::string& fileName);

	virtual DataPipeline::Data read() override;

	virtual std::vector<std::string>& getColumnNames() override;

	~CsvDataReader(){
		columnNames_.clear();
		fileName_ = "";
	}

};

}// end namespace

#endif /** DATAPIPELINE_CSVDATAREADER_H */