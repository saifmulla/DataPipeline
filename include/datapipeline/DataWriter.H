#ifndef DATAPIPELINE_DATAWRITER_H
#define DATAPIPELINE_DATAWRITER_H

///////////////////////////////////////////////////////////////////////////////
// Class DataWriter
// This is an pure abstract class for all the Data writter for various formats
// to be written into files.
// all various implementation of providing formatted output must implement 
// this base class pure virtual functions

#include "datapipeline/Exports.H"
#include "datapipeline/Data.H"
#include <vector>
#include <string>

namespace DataPipeline {

class EXPORTS DataWriter{

public:
	// this enum class represents the type of sorting to be done
	enum class SortType
	{
		ASCByName,
		DESCByName,
		ASCByRating,
		DESCByRating
	};

	// write
	// a pure virtual function for writing data to file
	// all subclasses must implement this function
	// @param data
	// @param string fileName

	virtual bool write(
		const DataPipeline::Data& data,
		const std::string& fileName
		) = 0;

	// sort
	// type of sorting techique to be applied for data to be sorted
	// before storing to file
	// this is a pure virtual function therefore all subclasses must
	// implement this function
	virtual bool sort(DataPipeline::Data& data, SortType sort) = 0;

	// base class destructor
	virtual ~DataWriter(){
		
	}

};

}//end namespace

#endif /* DataPipeline */