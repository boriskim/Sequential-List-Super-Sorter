#ifndef HEAPSORT_QUEUE_HPP
#define HEAPSORT_QUEUE_HPP

//The elements in the heap are represented using a sequential array
//Priority Queue class made for heapsort.

class PriorityQueue
{
	public:
	  typedef int DataType;

	public:
	  // Default constructor
	  PriorityQueue(unsigned int capacity);
	  // Destructor.
	  ~PriorityQueue();

	  bool enqueue(DataType val);
	  bool dequeue();

	  DataType max() const;
	  bool empty() const;
	  bool full() const;
	  unsigned int size() const;

	private:

	  DataType* heap_;
	  // Total number of elements that the heap can store (that is, the size of the
	  // array heap_ will be initialized as size (capacity_ + 1) ).
	  unsigned int capacity_;

	  unsigned int size_;

	private:
	  PriorityQueue(const PriorityQueue& other) {}
	  PriorityQueue& operator=(const PriorityQueue& other) {}
};

#endif
