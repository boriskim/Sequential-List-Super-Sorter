// .cpp files contain code definitions for methods that have been declared
// in the according .hpp file. The skeleton has been set up here for you.
// That is, the methods have been initiated, and your mission, should you 
// choose to accept it (which you should for marks), is to fill in each method
// with the appropriate code.
//
// A note about the "::" syntax: generally, this means "the thing on the right
// belongs to the thing on the left." So, SequentialList::empty() means the method
// empty() belongs to the class SequentialList. This allows empty() to access (and
// potentially change) the member variables in class SequentialList.

#include <iostream>
#include "SequentialList.hpp"

using namespace std;

// This is the constructor.
SequentialList::SequentialList(unsigned int cap)
{
	data_ = new DataType[cap];
	capacity_ = cap;
	size_= 0;
}

SequentialList::~SequentialList()
{
	delete[] data_;
}

bool SequentialList::empty() const
{
	if(size_ == 0)
		return true;
	else
		return false;
}

unsigned int SequentialList::size() const
{
	return size_;
}

unsigned int SequentialList::capacity() const
{
	return capacity_;
}

bool SequentialList::full() const
{
	if(size_ == capacity_)
		return true;
	else
		return false;
}

void SequentialList::print() const
{
	cout << " **************Print Start************** \n";

	for(int i = 0; i < size_; i++)
	{
		cout << data_[i] << endl;
	}

	cout << " **************Print End************** \n";
}

// NOTE on inserts: do NOT grow the array if we reach capacity. Simply return false.
bool SequentialList::insert_front(DataType val)
{
	if(full())
		return false;
	else if(empty())
	{
		data_[0] = val;
		size_++;

		return true;
	}
	else
	{
		for(int i = size_; i > 0; i--)
			data_[i] = data_[i-1];

		data_[0] = val;
		size_++;

		return true;
	}
}

bool SequentialList::remove_front()
{
	if(empty())
		return false;
	else
	{
		for(int i = 0; i < size_; i++)
			data_[i] = data_[i+1];

		data_[size_-1] = NULL;
		size_--;

		return true;
	}
}

bool SequentialList::insert_back(DataType val)
{
	if(full())
		return false;
	else
	{
		data_[size_] = val;
		size_++;

		return true;
	}
}

bool SequentialList::remove_back()
{
	if(empty())
		return false;
	else
	{
		data_[size_] = NULL;
		size_--;

		return true;
	}
}

bool SequentialList::insert(DataType val, unsigned int index)
{
	if(full() || index > size_)
		return false;
	else
	{
		for(int i = size_; i > index; i--)
			data_[i] = data_[i-1];

		data_[index] = val;
		size_++;

		return true;
	}
}

bool SequentialList::remove(unsigned int index)
{
	if(empty() || index >= size_)
		return false;
	else
	{
		for(int i = index; i < size_; i++)
			data_[i] = data_[i+1];

		data_[size_-1] = NULL;
		size_--;

		return true;
	}
}

unsigned int SequentialList::search(DataType val) const
{
	for(int i = 0; i < size_; i++)
	{
		if(data_[i] == val)
			return i;
	}
	return size();
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
	if(index >= size_)
		return data_[size_-1];
	else
		return data_[index];
}

bool SequentialList::replace(unsigned int index, DataType val)
{
	if(empty() || index >= size_)
		return false;
	else
	{
		data_[index] = val;

		return true;
	}
}
