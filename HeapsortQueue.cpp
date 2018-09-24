#include "HeapsortQueue.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

// Data Constructor. Initializes heap with inputted capacity.
PriorityQueue::PriorityQueue(unsigned int capacity)
{
	heap_ = new DataType[capacity + 1];
	capacity_ = capacity;
	size_ = 0;
}

// Destructor to prevent memory leaks.
PriorityQueue::~PriorityQueue()
{
	delete[] heap_;
}

// Enqueue method.
bool PriorityQueue::enqueue(DataType val)
{
	// Returns false if full.
	if(full())
		return false;

	// Sets data to index 1 if empty.
	if(size_ == 0)
	{
		size_++;
		heap_[1] = val;
		return true;
	}

	size_++;

	int insertIndex = size_;
	heap_[insertIndex] = val;

	// Finds the spot for inputted value within the heap.
	while(insertIndex > 1 && heap_[insertIndex] > heap_[insertIndex / 2])
	{
		DataType temp = heap_[insertIndex];
		heap_[insertIndex] = heap_[insertIndex / 2];
		heap_[insertIndex / 2] = temp;

		insertIndex = insertIndex / 2;
	}
	return true;
}

// Dequeue Method.
bool PriorityQueue::dequeue()
{
	if(empty())
		return false;

	//Replaces root node with boottom-right-most leaf node.
	heap_[1] = heap_[size_];

	size_--;

	int topDown = 1;

	//Continuously pushes down new root node until spot is found using top down method.
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

// Returns max value within the heap at index 1.
PriorityQueue::DataType PriorityQueue::max() const
{
	return heap_[1];
}

// Returns true if empty.
bool PriorityQueue::empty() const
{
	if(size_ == 0)
		return true;

	return false;
}


// Returns true if full.
bool PriorityQueue::full() const
{
	if(size_ >= capacity_)
		return true;

	return false;
}

// Returns size.
unsigned int PriorityQueue::size() const
{
	return size_;
}
