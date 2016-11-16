#include "datapipeline/Validate.H"
#include <iostream>
DataPipeline::Validate::Validate(DataPipeline::Data* data)
:data_(data)
{

}

std::string DataPipeline::Validate::checkUrl(std::string& uri)
{
	// TODO: perform more check for validating abc, 123 and xyx coms
	std::string blank = "";
	// perl based regex for url validation
	std::regex validurl("#((?:https?|http)://(?:\\S*?\\.\\S*?)(?:[\\s)\\[\\]{},;\"\':<]|\\.\\s|$))#");
	if(regex_match(uri,validurl))
		return uri;
	else
		return std::string(); 
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

