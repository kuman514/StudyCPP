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

struct BiTree
{
	private:
		Node *root;
		Node *cur;
		unsigned int nowIndex;
	public:
		BiTree(int init = 0) : nowIndex(2)
		{
			root = new Node;
			root -> data = init;
			root -> index = 1;
			
			root -> LChild = nullptr;
			root -> RChild = nullptr;
			root -> Parent = root;

			cur = root;
			// if you want to set link node cur = root,
			// don't do anything like this : "kuman() : cur(root)"
			// cur = root should happen after creating root.
		}
		~BiTree()
		{	
			// Will be added
		}
		void insert(int num)
		{
			// Create tmp first, then search space for tmp node.
			bool keepGoing = 1;
			Node *tmp = new Node;
			tmp -> data = num;
			tmp -> index = nowIndex;
			
			tmp -> LChild = nullptr;
			tmp -> RChild = nullptr;
			tmp -> Parent = cur;

			while(keepGoing)
			{
				if(cur -> LChild == nullptr)
				{
					cur -> LChild = tmp;
					keepGoing = 0;
				}
				else if(cur -> RChild == nullptr)
				{
					cur -> RChild = tmp;
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
						cur = cur -> Parent -> Parent;
						cur = cur -> RChild -> LChild;
					}
				}
			}

			std::cout << "Index : " << tmp -> index << ", " << "Node Data : " << tmp -> data << std::endl;
			nowIndex++;
		}
		void show(void)
		{
			// Will be added
		}
};

int main(void)
{
	BiTree bt(1);
	bt.insert(2);
	bt.insert(3);
	bt.insert(4);
	return 0;
}
