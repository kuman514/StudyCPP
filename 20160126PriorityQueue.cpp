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
	private:
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
				Node *Sibling = tmp -> Parent -> RChild;
				// before tmp exchange
				if(tmp == tmp -> Parent -> LChild)
				{
					Sibling -> Parent = tmp;
					tmp -> Parent = tmp -> Parent -> Parent;

					if(tmp == tmp -> Parent -> LChild -> LChild)
					{
						tmp -> Parent -> LChild -> LChild = tmp -> LChild;
						tmp -> LChild -> Parent = tmp -> Parent -> LChild;
						tmp -> Parent -> LChild -> RChild = tmp -> RChild;
						tmp -> RChild -> Parent = tmp -> Parent -> LChild;

						tmp -> RChild = Sibling;
						tmp -> LChild = tmp -> Parent -> LChild;

						tmp -> Parent -> LChild -> Parent = tmp;
						tmp -> Parent -> LChild = tmp;
					}
					else if(tmp == tmp -> Parent -> RChild -> LChild)
					{
						tmp -> Parent -> RChild -> LChild = tmp -> LChild;
						tmp -> LChild -> Parent = tmp -> Parent -> RChild;
						tmp -> Parent -> RChild -> RChild = tmp -> RChild;
						tmp -> RChild -> Parent = tmp -> Parent -> RChild;

						tmp -> RChild = Sibling;
						tmp -> LChild = tmp -> Parent -> RChild;

						tmp -> Parent -> RChild -> Parent = tmp;
						tmp -> Parent -> RChild = tmp;
					}
				}
				else if(tmp == tmp -> Parent -> RChild)
				{
				}

				// after tmp exchange
				if(tmp == root -> Parent)
					root = tmp;

				cur = cur -> Parent;
			}
		}

		int deQueue(void)
		{
			int result = root -> data;

			// blah blah

			return result;
		}
};

int main(void)
{
	PQueue pq(6);
	pq.enQueue(1);
	return 0;
}
