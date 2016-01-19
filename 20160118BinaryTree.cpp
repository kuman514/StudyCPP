#include <iostream>
#define nullptr (Node*)NULL

struct Node
{
	Node *LChild;
	int data;
	unsigned int index;
	Node *RChild;
};

struct BiTree
{
	private:
		Node *root;
		Node *cur;
		unsigned int curIndex;
	public:
		BiTree(int init = 0) : cur(root), curIndex(2)
		{
			root = new Node;
			root -> data = init;
			root -> index = 1;
			root -> LChild = nullptr;
			root -> RChild = nullptr;
		}
		~BiTree()
		{	
			// Will be added
		}
		void insert(int num)
		{
			// Create tmp first, then search space for tmp node.
			Node *tmp = new Node;
			tmp -> data = num;
			tmp -> index = curIndex;
			tmp -> LChild = nullptr;
			tmp -> RChild = nullptr;

			if(cur -> LChild == nullptr)
				cur -> LChild = tmp;
			else if(cur -> RChild == nullptr)
				cur -> RChild = tmp;
			else
			{
				// Will be added
			}

			curIndex++;
		}
		void show(void)
		{
			// Will be added
		}
};

int main(void)
{
	BiTree bt(12);
	return 0;
}
