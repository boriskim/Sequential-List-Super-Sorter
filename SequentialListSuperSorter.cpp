//Sequential List Super Sorter Functions
#include <iostream>

#include "SequentialListSuperSorterSuperSorter.hpp"
#include "HeapsortQueue.hpp"

using namespace std;

// Data Constructor. Initializes the array with inputted capacity.
SequentialListSuperSorter::SequentialListSuperSorter(unsigned int cap)
{
	data_ = new DataType[cap];
	capacity_ = cap;
	size_= 0;
}

// Destructor to prevent memory leaks.
SequentialListSuperSorter::~SequentialListSuperSorter()
{
	delete[] data_;
}

// Returns true if empty.
bool SequentialListSuperSorter::empty() const
{
	if(size_ == 0)
		return true;
	else
		return false;
}

// Returns size of Sequential List.
unsigned int SequentialListSuperSorter::size() const
{
	return size_;
}

// Returns capacity of Sequential List.
unsigned int SequentialListSuperSorter::capacity() const
{
	return capacity_;
}


// Returns true if full.
bool SequentialListSuperSorter::full() const
{
	if(size_ == capacity_)
		return true;
	else
		return false;
}

// Print function to see data inside.
void SequentialListSuperSorter::print() const
{
	cout << " **************Print Start************** \n";

	cout << "Capacity: " << capacity_ << "Size: " << size_ << endl;

	for(int i = 0; i < size_; i++)
	{
		cout << data_[i] << endl;
	}

	cout << " **************Print End************** \n";
}

// Insert at the front of the array.
bool SequentialListSuperSorter::insert_front(DataType val)
{
	// Returns false if the array is full.
	if(full())
		return false;
	// Inserts to index 0 if array is empty.
	else if(empty())
	{
		data_[0] = val;
		size_++;

		return true;
	}
	// Pushes all data one index up, then inserts new data in index 0.
	else
	{
		for(int i = size_; i > 0; i--)
			data_[i] = data_[i-1];

		data_[0] = val;
		size_++;

		return true;
	}
}

// Remove front.
bool SequentialListSuperSorter::remove_front()
{
	// Returns false if empty.
	if(empty())
		return false;

	// Pulls data one index forward, then assigns the previous largest index to NULL.
	else
	{
		for(int i = 0; i < size_; i++)
			data_[i] = data_[i+1];

		data_[size_-1] = NULL;
		size_--;

		return true;
	}
}

// Simple insert into end of array.
bool SequentialListSuperSorter::insert_back(DataType val)
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

// Simple remove from end of array.
bool SequentialListSuperSorter::remove_back()
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

// Inserts data at inputted index.
bool SequentialListSuperSorter::insert(DataType val, unsigned int index)
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

// Removes data at specified index.
bool SequentialListSuperSorter::remove(unsigned int index)
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


// Searches for the data value within the Sequential List.
unsigned int SequentialListSuperSorter::search(DataType val) const
{
	for(int i = 0; i < size_; i++)
	{
		if(data_[i] == val)
			return i;
	}
	return size();
}

// Returns the data at the inputted index.
SequentialListSuperSorter::DataType SequentialListSuperSorter::select(unsigned int index) const
{
	if(index >= size_)
		return data_[size_-1];
	else
		return data_[index];
}


// Replaces the data at the inputted index with new inputted data.
bool SequentialListSuperSorter::replace(unsigned int index, DataType val)
{
	if(empty() || index >= size_)
		return false;
	else
	{
		data_[index] = val;

		return true;
	}
}

// Bubble Sort.
void SequentialListSuperSorter::bubble_sort()
{
	// Initialize change counter to -1, so it does not break the loop below.
	int change_counter = -1;

	//Continues to compare and switch values within the array until no more switches are made.
	while(change_counter != 0)
	{
		change_counter = 0;

		for(int i = 0; i < size_; i++)
		{
			if(data_[i] > data_[i+1])
			{
				change_counter++;

				int temp_ = data_[i];
				data_[i] = data_[i+1];
				data_[i+1] = temp_;
			}
		}
	}
	return;
}

//Selection Sort.
void SequentialListSuperSorter::selection_sort()
{
	// Searches through the array for the smallest value and continuously pushes it to the front of the array.
	for(int i = 0; i < size_; i++)
	{
		int min_ = 999;

		for(int j = i; j < size; j++)
		{
			if(data_[j] < min_)
			{
				int temp_ = min_;
				min_ = data_[j];
				data_[j] = temp_;
			}
		}
		data_[i] = min_;
	}
	return;
}

// Insertion Sort.
void SequentialListSuperSorter::insertion_sort()
{
	int unsorted_list[size_];

	for(int i = 0; i < size_; i++)
		unsorted_list[i] = data_[i];

	for(int i = 0; i < size_; i++)
		data_[i] = 999;

	for(int i = 0; i < size_; i++)
	{
		int j = 0;

		while(unsorted_list[i] > data_[j])
			j++;

		for(int k = size_-2; k >= j; k--)
			data_[k+1] = data_[k];

		data_[j] = unsorted_list[i];
	}

	return;
}

// Merge Sort.
void SequentialListSuperSorter::merge_sort(int left, int right)
{
	if(right > left)
	{
		int mid = (left + right) / 2;

		merge_sort(left, mid);
		merge_sort(mid + 1, right);

		merge(left, mid, right);
	}

	return;
}

// Quick Sort.
void SequentialListSuperSorter::quick_sort(int low, int high)
{
	if(low < high)
	{
		int pivot = partition(low, high);
		quick_sort(low, pivot - 1);
		quick_sort(pivot + 1, high);
	}

	return;
}

// Heap Sort.
void SequentialListSuperSorter::heap_sort()
{
	PriorityQueue Q1(size);

	// Heapify the Sequential List.
	for(int i = 0; i < size_; i++)
		Q1.enqueue(data_[i]);

	int j = size - 1;

	// Continuously dequeue, giving out the next largest value each time.
	while(!Q1.empty())
	{
		data_[j] = Q1.max();
		Q1.dequeue();
		j--;
	}

	return;
}

// Partition method for Quick Sort.
int SequentialListSuperSorter::partition(int low, int high)
{
	if(high - low == 1)
	{
		if(data_[high] < data_[low])
		{
			int temp = data_[high];
			data_[high] = data_[low];
			data_[low] = temp;
		}

		return high;
	}
	else
	{
		int pivot = data_[low];

		int l = low + 1;

		int h = high;

		while(h > l)
		{
			while(data_[l] < pivot)
				l++;

			while(data_[h] > pivot)
				h--;

			if(h > l)
			{
				int temp = data_[l];
				data_[l] = data_[h];
				data_[h] = temp;
			}
		}

		int temp = data_[h];
		data_[h] = data_[low];
		data_[low] = temp;

		return h;
	}
}


// Merge method for Merge Sort.
void SequentialListSuperSorter::merge(int & left, int & mid, int & right)
{
	if(right - left == 1)
	{
		if(data_[left] > data_[right])
		{
			int temp = data_[left];
			data_[left] = data_[right];
			data_[right] = temp;
		}
	}
	else
	{
		int size_left = mid - left + 1;

		int size_right = right - mid;

		int left_array[size_left], right_array[size_right];

		int r = 0, s = 0;

		for(int i = left; i < mid + 1; i++)
		{
			left_array[r] = data_[i];
			r++;
		}

		for(int j = mid + 1; j < right + 1; j++)
		{
			right_array[s] = data_[j];
			s++;
		}

		int k = 0, l = 0, m = left;

		while(k < size_left || l < size_right)
		{
			if(k == size_left)
			{
				data_[m] = right_array[l];
				l++;
			}
			else if(l == size_right)
			{
				data_[m] = left_array[k];
				k++;
			}
			else if(left_array[k] < right_array[l])
			{
				data_[m] = left_array[k];
				k++;
			}
			else if(left_array[k] > right_array[l])
			{
				data_[m] = right_array[l];
				l++;
			}
			m++;
		}
	}
	return;
}
