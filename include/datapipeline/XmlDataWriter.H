#ifndef DATAPIPELINE_XMLDATAWRITER_H
#define DATAPIPELINE_XMLDATAWRITER_H

#include "datapipeline/DataWriter.H"

// this class is a child implementation of base class DataWriter,
// it implements xml data output to file for any class Data object supplied

namespace DataPipeline{

class EXPORTS XmlDataWriter : public DataWriter {

public:
	// simple default constructor
	XmlDataWriter();
	
	virtual bool write(
		const DataPipeline::Data& data,
		const std::string& fileName
		) override;

	virtual bool sort(DataPipeline::Data& data, SortType sort) override;
};//end class

}//end namespace
#endif /** DATAPIPELINE_XMLDATAWRITER_H */