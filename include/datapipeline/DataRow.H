#ifndef DATAPIPELINE_DATAROW_H
#define DATAPIPELINE_DATAROW_H

#include "datapipeline/Exports.H"
#include <string>


namespace DataPipeline {

class EXPORTS DataRow {

private:
	int rating_; // rating for hotel column

	std::string hotelName_; // representing name of hotel 

	std::string hotelAddress_; // address the hotel column

	std::string contactName_; // person of contact for hotel

	std::string phone_; // string representation of phone number

	std::string Uri_; // web address for hotel


public:
	// constructor
	explicit DataRow(
		const int rating,
		const std::string hotelname,
		const std::string address,
		const std::string contactperson,
		const std::string phone,
		const std::string url
		);

	// destructor
	~DataRow(){
		
	}

	const int getRatings() const;

	const std::string& getHotelName() const;

	const std::string& getAddress() const;

	const std::string& getContact() const;

	const std::string& getPhone() const;

	const std::string& getUrl() const;


};

}// end namespace

#endif /** DATAPIPELINE_DATAROW_H */