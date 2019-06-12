#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue{
public:
	Queue();
	Queue(const Queue& other);
	Queue& operator=(const Queue& other);
	~Queue();

	void enqueue(int item);
	void dequeue();
	int front() const;

private:
	//
};

#endif