#include "datapipeline/XmlDataWriter.H"
// implementation of default constructor
DataPipeline::XmlDataWriter::XmlDataWriter(){

}

bool DataPipeline::XmlDataWriter::write(
	const DataPipeline::Data& data,
	const std::string& fileName
	)
{
	std::ofstream writer(fileName);
	const std::vector<DataPipeline::DataRow*>& datarows = data.getRows();

	writer << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"yes\" ?>\n";
	writer << "<Hotels>\n";
	std::for_each(
		datarows.cbegin(),
		datarows.cend(),
		[&writer] (const DataPipeline::DataRow* row){
			writer << "<Hotel>\n";
			// TODO: read the columns from columnName in  class Data
			writer << "<Name>" << row->getHotelName() << "</Name>\n";
			writer << "<Address>" << row->getAddress() << "</Address>\n";
			writer << "<Stars>" << row->getRatings() << "</Stars>\n";
			writer << "<Contact>" << row->getContact() << "</Contact>\n";
			writer << "<Phone>" << row->getPhone() << "</Phone>\n";
			writer << "<Uri>" << row->getUrl() << "</Uri>\n";
			writer << "</Hotel>\n";
		});
	writer << "</Hotels>\n";
	writer.close();

	return true;
}

bool DataPipeline::XmlDataWriter::sort(DataPipeline::Data& data, SortType sort)
{
	return true;
}

