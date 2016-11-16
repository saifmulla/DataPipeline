#ifndef DATAPIPELINE_JSONDATAWRITER_H
#define DATAPIPELINE_JSONDATAWRITER_H

#include "datapipeline/DataWriter.H"

// this class is a child implementation of base class DataWriter,
// it implements JSON data output to file for any class Data object supplied

namespace DataPipeline{

class EXPORTS JsonDataWriter : public DataWriter {

public:
	// simple default constructor
	JsonDataWriter();

	virtual bool write(
		const DataPipeline::Data& data,
		const std::string& fileName
		) override;

	virtual bool sort(DataPipeline::Data& data, SortType sort) override;
};//end class

}//end namespace
#endif /** DATAPIPELINE_JSONDATAWRITER_H */