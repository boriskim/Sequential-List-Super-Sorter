#include "HeapsortQueue.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

PriorityQueue::PriorityQueue(unsigned int capacity)
{
	heap_ = new DataType[capacity + 1];
	capacity_ = capacity;
	size_ = 0;
}

PriorityQueue::~PriorityQueue()
{
	delete[] heap_;
}

bool PriorityQueue::enqueue(DataType val)
{
	if(full())
		return false;

	if(size_ == 0)
	{
		size_++;
		heap_[1] = val;
		return true;
	}

	size_++;

	int insertIndex = size_;
	heap_[insertIndex] = val;

	while(insertIndex > 1 && heap_[insertIndex] > heap_[insertIndex / 2])
	{
		DataType temp = heap_[insertIndex];
		heap_[insertIndex] = heap_[insertIndex / 2];
		heap_[insertIndex / 2] = temp;

		insertIndex = insertIndex / 2;
	}
	return true;
}

bool PriorityQueue::dequeue()
{
	if(empty())
		return false;

	heap_[1] = heap_[size_];

	size_--;

	int topDown = 1;

	while(topDown <= (size_ / 2) && (heap_[topDown] < heap_[topDown * 2] || heap_[topDown] < heap_[topDown * 2 + 1]))
	{
		DataType temp = heap_[topDown];

		if(heap_[topDown * 2] > heap_[topDown * 2 + 1])
		{
			heap_[topDown] = heap_[topDown * 2];
			heap_[topDown * 2] = temp;
			topDown = topDown * 2;
		}
		else
		{
			heap_[topDown] = heap_[topDown * 2 + 1];
			heap_[topDown * 2 + 1] = temp;
			topDown = topDown * 2 + 1;
		}
	}

	return true;
}

PriorityQueue::DataType PriorityQueue::max() const
{
	return heap_[1];
}

bool PriorityQueue::empty() const
{
	if(size_ == 0)
		return true;

	return false;
}

bool PriorityQueue::full() const
{
	if(size_ >= capacity_)
		return true;

	return false;
}

unsigned int PriorityQueue::size() const
{
	return size_;
}
