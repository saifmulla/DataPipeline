#include "datapipeline/JsonDataWriter.H"
#include <iostream>
// implementation of default constructor
DataPipeline::JsonDataWriter::JsonDataWriter(){

}

bool DataPipeline::JsonDataWriter::write(
	const DataPipeline::Data& data,
	const std::string& fileName
	)
{
	std::ofstream writer(fileName);
	const std::vector<DataPipeline::DataRow*>& datarows = data.getRows();
	std::stringstream jsonrow;// instead of writing to writer object many times we write to variable
	writer << "{\"Hotels\":[\n";
	std::for_each(
		datarows.cbegin(),
		datarows.cend(),
		[&jsonrow] (const DataPipeline::DataRow* row){
			jsonrow << "{\n";
			// TODO: read the columns from columnName in  class Data
			jsonrow << "\"Name\":\"" << row->getHotelName() << "\",\n";
			jsonrow << "\"Address\":\"" << row->getAddress() << "\",\n";
			jsonrow << "\"Stars\":" << row->getRatings() << ",\n";
			jsonrow << "\"Contact\":\"" << row->getContact() << "\",\n";
			jsonrow << "\"Phone\":\"" << row->getPhone() << "\",\n";
			jsonrow << "\"Uri\":\"" << row->getUrl() << "\"\n";
			jsonrow << "},\n";
		});

	// there is a possibility of comma ending with no data therefore remove
	// it to generate valid json
	std::string temp = jsonrow.str();// convert to string type
	temp.replace(temp.rfind(','),1,"");// find the first occurence of ',' from end of string
	writer << temp; // append to writer
	writer << "]}\n";// close json array
	writer.close();
}

bool DataPipeline::JsonDataWriter::sort(DataPipeline::Data& data, SortType sort)
{

}

