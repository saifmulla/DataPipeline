#ifndef DATAPIPELINE_VALIDATE_H
#define DATAPIPELINE_VALIDATE_H

#include "datapipeline/Exports.H"

namespace DataPipeline {

class DataRow; //forward declaration of class DataRow

class EXPORTS Validate {

public:
	Validate();

	void checkUTF8Name(std::string& name);

	void checkUrl(std::string& url);

	void checkRatings(int& rating);

	void check()
};

} //end namespace
#endif