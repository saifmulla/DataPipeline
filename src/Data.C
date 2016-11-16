#include "datapipeline/Data.H"

// constructor
DataPipeline::Data::Data()
:rows_(0),size_(0)
{

}


DataPipeline::Data::~Data()
{
	this->rows_.clear();
}

void DataPipeline::Data::addRow(DataPipeline::DataRow* row)
{
	this->rows_.push_back(row);
	++this->size_;
}

DataPipeline::DataRow& DataPipeline::Data::getRow(int index)
{
	// TODO: handle index out of bound exception
	// if(this->size()<=0)
	// 	return 0;

	if(index >= 0 && index < this->size())
		return *this->rows_[index];
	// else
	// 	return 0;
}

const int DataPipeline::Data::size() const {
	return this->rows_.size();
}

const std::vector<DataPipeline::DataRow*>& DataPipeline::Data::getRows() const
{
	return this->rows_;
}