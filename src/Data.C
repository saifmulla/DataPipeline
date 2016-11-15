#include "datapipeline/Data.H"

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

const int DataPipeline::Data::size() const {
	return this->rows_.size();
}