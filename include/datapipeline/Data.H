#ifndef DATAPIPELINE_DATA_H
#define DATAPIPELINE_DATA_H

///////////////////////////////////////////////////////////////////////////////
// Data
// This class represents an object of complete data obtained from input csv
// file, it stores each row of data as object of DataRow

#include "datapipeline/Exports.H"
#include "datapipeline/DataRow.H"
#include <vector>
#include <memory>

namespace DataPipeline {
	
class EXPORTS Data {
	
	private:
		std::vector<DataPipeline::DataRow*> rows_;
		int size_;

	public:
		// default constructor
		Data();

		// addRow
		// append new dataRow to existing list of container
		void addRow(DataPipeline::DataRow* row);

		// Size
		// return the size of list of dataRow
		const int size() const;

		// getRow
		// return reference of a single row from list of DataRows
		DataPipeline::DataRow& getRow(int index);

		// return reference to list container of DataRows
		const std::vector<DataPipeline::DataRow*>& getRows() const;

		// use the destructor to release data
		~Data();


}; // end class

}// end namespace

#endif /** DATAPIPELINE_DATA_H */