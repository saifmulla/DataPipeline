#ifndef DATAPIPELINE_DATA_H
#define DATAPIPELINE_DATA_H

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
		Data();

		void addRow(DataPipeline::DataRow* row);

		const int size() const;

		DataPipeline::DataRow& getRow(int index){
			// TODO: handle index out of bound exception
			// if(this->size()<=0)
			// 	return 0;

			if(index >= 0 && index < this->size())
				return *this->rows_[index];
			// else
			// 	return 0;
		}

		~Data();


}; // end class

}// end namespace

#endif /** DATAPIPELINE_DATA_H */