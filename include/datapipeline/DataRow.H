#ifndef DATAPIPELINE_DATAROW_H
#define DATAPIPELINE_DATAROW_H

///////////////////////////////////////////////////////////////////////////////
// DataRow
// This class represents a single Hotel, basically it stores all the information
// of a hotel stored as row in input file so it can also be tearmed as a single
// row of data

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
	// this is the only mechanism to instanstiate this class with a 
	// parameterised constructor
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

	// rating the rating for the row
	// we are storing rating as int
	const int getRatings() const;

	// get name of hotel in row
	const std::string& getHotelName() const;

	// get address
	const std::string& getAddress() const;

	// get contact name
	const std::string& getContact() const;

	// get phone number as string
	const std::string& getPhone() const;

	// get url for hotel
	const std::string& getUrl() const;


};

}// end namespace

#endif /** DATAPIPELINE_DATAROW_H */