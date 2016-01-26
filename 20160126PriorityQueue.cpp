#include <iostream>
#define nullptr (Node*)NULL

unsigned int twoPower(unsigned int index)
{
	unsigned int result = 2;
	while(result < index)
		result *= 2;
	return result;
}

struct Node
{
	Node *LChild;
	int data;
	unsigned int index;
	Node *RChild;

	Node *Parent;
};

struct PQueue
{
//	private:
		Node *root;
		Node *cur;
		unsigned int nowIndex;

	public:
		PQueue(int init = 0) : nowIndex(2)
		{
			root = new Node;
			root -> data = init;
			root -> index = 1;
			
			root -> LChild = nullptr;
			root -> RChild = nullptr;
			root -> Parent = root;

			cur = root;
			
			/*
			std::cout << root << ", ";
			std::cout << "Index : " << root -> index << ", ";
			std::cout << "Data : " << root -> data << std::endl;
			*/
		}
		~PQueue(){}
	
		void enQueue(int num)
		{
			bool keepGoing = 1;
			int swap;
			Node *tmp = new Node;
			tmp -> data = num;
			tmp -> index = nowIndex;
			
			tmp -> LChild = nullptr;
			tmp -> RChild = nullptr;

			while(keepGoing)
			{
				if(cur -> LChild == nullptr)
				{
					cur -> LChild = tmp;
					tmp -> Parent = cur;
					keepGoing = 0;
				}
				else if(cur -> RChild == nullptr)
				{
					cur -> RChild = tmp;
					tmp -> Parent = cur;
					keepGoing = 0;
				}
				else
				{
					if(cur -> index == twoPower(cur -> index) - 1)
					{
						while(cur != root)
							cur = cur -> Parent;

						while(cur -> LChild != nullptr && cur -> RChild != nullptr)
							cur = cur -> LChild;
					}
					else if(cur == cur -> Parent -> LChild)
						cur = cur -> Parent -> RChild;
					else if(cur == cur -> Parent -> RChild)
					{
						while(cur != cur -> Parent -> LChild)
							cur = cur -> Parent;

						cur = cur -> Parent -> RChild;
						
						while(cur -> LChild != nullptr && cur -> RChild != nullptr)
							cur = cur -> LChild;
					}
				}
			}

			/*
			std::cout << tmp << ", ";
			std::cout << "Index : " << tmp -> index << ", ";
			std::cout << "Data : " << tmp -> data << ", ";
			std::cout << "Parent : " << tmp -> Parent << std::endl;
			*/
			nowIndex++;

			// while the leaf tmp is bigger than their parents
			while(tmp -> data < tmp -> Parent -> data)
			{
				// before swap
				swap = tmp -> data;
				tmp -> data = tmp -> Parent -> data;
				tmp -> Parent -> data = swap;
				tmp = tmp -> Parent;

				// after swap
				if(tmp -> LChild != nullptr && tmp -> data > tmp -> LChild -> data)
				{
					swap = tmp -> data;
					tmp -> data = tmp -> LChild -> data;
					tmp -> LChild -> data = swap;
				}
				else if(tmp -> RChild != nullptr && tmp -> data > tmp -> RChild -> data)
				{
					swap = tmp -> data;
					tmp -> data = tmp -> RChild -> data;
					tmp -> RChild -> data = swap;
				}
			}
		}

		int deQueue(void)
		{
			int result = root -> data;

			// blah blah

			return result;
		}
};

void testprint(Node *pr)
{
	if(pr == nullptr)
		return;

	std::cout << pr << ", Index : " << pr -> index << ", Data : " << pr -> data << std::endl;

	testprint(pr -> LChild);
	testprint(pr -> RChild);
}

int main(void)
{
	PQueue pq(20);

	for(int i = 20; i >= 10; i--)
	{
		pq.enQueue(i);
	}

	testprint(pq.root);
	return 0;
}
