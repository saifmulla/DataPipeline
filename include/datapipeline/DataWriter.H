#ifndef DATAPIPELINE_DATAWRITER_H
#define DATAPIPELINE_DATAWRITER_H

#include "datapipeline/Exports.H"
#include "datapipeline/Data.H"
#include <vector>
#include <string>

namespace DataPipeline {

class EXPORTS DataWriter{

public:
	enum class SortType
	{
		ASCByName,
		DESCByName,
		ASCByRating,
		DESCByRating
	};

	virtual bool write(
		const DataPipeline::Data& data,
		const std::string& fileName
		) = 0;

	virtual bool sort(DataPipeline::Data& data, SortType sort) = 0;

	virtual ~DataWriter(){
		
	}

};

}//end namespace

#endif /* DataPipeline */