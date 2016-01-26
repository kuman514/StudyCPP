#include <iostream>
#define nullptr (Node<T>*)NULL

// I think I misunderstood what Priority Queue means.
// What Priority Queue means, I found, is a type of QUEUE, not a Binary Tree.
// Later, my Heap will be added as soon as possible.

template <typename T>
struct Node
{
	Node<T> *prev;
	T data;
	Node<T> *next;
};

template <typename T>
struct PQueue
{
	private:
		Node<T> *head;
		Node<T> *tail;
	
	public:
		PQueue()
		{
			head = new Node<T>;
			tail = new Node<T>;

			head -> next = tail;
			head -> prev = head;

			tail -> next = tail;
			tail -> prev = head;
		}
		~PQueue()
		{
			while(head -> next != tail)
				dequeue();

			delete head;
			delete tail;
		}
		
		void enqueue(T num)
		{
			Node<T> *search = head -> next;
			Node<T> *insert = new Node<T>;
			insert -> data = num;

			while(search != tail)
			{
				if(num < search -> data)
					break;

				search = search -> next;
			}

			insert -> prev = search -> prev;
			insert -> next = search;

			search -> prev -> next = insert;
			search -> prev = insert;
		}
		
		T dequeue(void)
		{
			T pop = head -> next -> data;
			Node<T> *remove = head -> next;

			if(isEmpty())
			{
				std::cout << "Error : Empty Queue" << std::endl;
				return -1;
			}

			head -> next = remove -> next;
			remove -> next -> prev = head;

			remove -> next = nullptr;
			remove -> prev = nullptr;
			remove -> data = (T)0;

			delete remove;
			return pop;
		}

		void show(void)
		{
			Node<T> *scan = head -> next;
			int i = 1;

			while(scan != tail)
			{
				std::cout << i++ << " : " << scan -> data << std::endl;
				scan = scan -> next;
			}
		}

		bool isEmpty(void) { return (head -> next == tail); }
};

int main(void)
{
	PQueue<int> pq;
	pq.enqueue(6);
	pq.enqueue(3);
	pq.enqueue(10);
	pq.enqueue(1);
	pq.enqueue(4);
	pq.enqueue(7);
	pq.show();

	std::cout << "DEQUEUE : " << pq.dequeue() << std::endl;
	std::cout << "DEQUEUE : " << pq.dequeue() << std::endl;
	
	pq.show();
	return 0;
}
