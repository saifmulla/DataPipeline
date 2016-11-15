#ifndef DATAPIPELINE_DATAWRITER_H
#define DATAPIPELINE_DATAWRITER_H

#include "datapipeline/Exports.H"
#include <vector>
#include <string>

namespace DataPipeline {

class EXPORTS DataWriter{

public:

	virtual void write(const std::string fileName) = 0;

	virtual void sort(std::vector<std::string>& data) = 0;

	virtual ~DataWriter(){
		
	}

};

}//end namespace

#endif /* DataPipeline */