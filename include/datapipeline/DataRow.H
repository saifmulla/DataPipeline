#ifdef DATAPIPELINE_DATAROW_H
#define DATAPIPELINE_DATAROW_H

#include "datapipeline/Exports.H"
#include <string>

namespace DataPipeline {

class EXPORTS DataRow {

private:
	int rating_; // rating for hotel column

	std::string hotelName_; // representing name of hotel 

	std::string address_; // address the hotel column

	std::string contactName_; // person of contact for hotel

	std::string phone_; // string representation of phone number

	std::string Uri_; // web address for hotel


public:
	// constructor
	explicit DataRow(

		);

};

}// end namespace

#endif /** DATAPIPELINE_DATAROW_H */