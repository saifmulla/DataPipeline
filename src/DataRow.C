#include "datapipeline/DataRow.H"

// explicit parameterised constructor implementation
DataPipeline::DataRow::DataRow(
	const int rating,
	const std::string hotelname,
	const std::string address,
	const std::string contactperson,
	const std::string phone,
	const std::string url
	)
:rating_(rating),hotelName_(hotelname),hotelAddress_(address),
contactName_(contactperson),phone_(phone),Uri_(url)
{
}

// accessor functions

const int DataPipeline::DataRow::getRatings() const {
	return this->rating_;
}

const std::string& DataPipeline::DataRow::getHotelName() const {
	return this->hotelName_;
}

const std::string& DataPipeline::DataRow::getAddress() const {
	return this->hotelAddress_;
}

const std::string& DataPipeline::DataRow::getContact() const {
	return this->contactName_;
}

const std::string& DataPipeline::DataRow::getPhone() const {
	return this->phone_;
}

const std::string& DataPipeline::DataRow::getUrl() const {
	return this->Uri_;
}