#include "datapipeline/Validate.H"

DataPipeline::Validate::Validate(DataPipeline::Data* data)
:data_(data)
{

}

std::string& DataPipeline::Validate::checkUrl(std::string& uri)
{

}

int DataPipeline::Validate::checkRatings(const int& rating)
{
	if(rating > 5)
		return 5;
	else if(rating < 0)
		return 0;
	else
		return rating;
}

void DataPipeline::Validate::checkUTF8(std::string& str)
{

}

void DataPipeline::Validate::check()
{

}

