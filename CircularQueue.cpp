#include <iostream>
#define EOF (char)(-1)
#define N 20

struct CirQueue
{
	private:
		int node[N];
		int *front, *rear;
		int count;
	public:
		CirQueue() : count(0) 
		{
			front = node;
			rear = node;
		}
		~CirQueue() { }

		void EnQueue(int num)
		{
			*rear = num;
			if(rear == &node[N-1])
				rear = node;
			else
			{
				rear++;
				count++;
			}
		}

		int DeQueue(void)
		{
			int result = *front;

			if(!IsEmpty())
			{
				if(front == &node[N-1])
					front = node;
				else
				{
					front++;
					count--;
				}
				return result;
			}
			else
			{
				std::cout << "Already Empty" << std::endl;
				return EOF;
			}
		}

		bool IsEmpty(void) { return (count == 0); }
		void show(void)
		{
			int *cur = front;
			for(int i = 0; i < count; i++)
			{
				std::cout << *cur << ' ';
				if(cur == &node[N-1])
					cur = node;
				else
					cur++;
			}

			std::cout << std::endl;
		}
};

int main(void)
{
	CirQueue cq;
	std::cout << (cq.IsEmpty() ? "Empty" : "Not Empty") << std::endl;
	cq.DeQueue();

	for(int i = 1; i < 30; i++)
		cq.EnQueue(i);

	std::cout << (cq.IsEmpty() ? "Empty" : "Not Empty") << std::endl;
	cq.DeQueue();
	cq.show();
	return 0;
}
