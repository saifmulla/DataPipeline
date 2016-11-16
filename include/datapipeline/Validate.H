#ifndef DATAPIPELINE_VALIDATE_H
#define DATAPIPELINE_VALIDATE_H

#include "datapipeline/Exports.H"
#include "datapipeline/Data.H"
#include "datapipeline/DataRow.H"
#include <memory>
#include <cmath>

namespace DataPipeline {

class EXPORTS Validate {
private:
	// TODO: make shared_ptr<>
	DataPipeline::Data* data_;

public:
	explicit Validate(DataPipeline::Data* data);

	void checkUTF8(std::string& name);

	std::string& checkUrl(std::string& url);

	int checkRatings(const int& rating);

	void check();
};

} //end namespace
#endif