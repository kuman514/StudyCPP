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
			std::cout << root << ", ";
			std::cout << "Index : " << root -> index << ", ";
			std::cout << "Data : " << root -> data << std::endl;
		}
		~BiTree(){}
	
		void insert(int num)
		{
			// Create tmp first, then search space for tmp node.
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
						cur = cur -> Parent -> Parent;
						cur = cur -> RChild -> LChild;
					}
				}
			}

			std::cout << tmp << ", ";
			std::cout << "Index : " << tmp -> index << ", ";
			std::cout << "Data : " << tmp -> data << ", ";
			std::cout << "Parent : " << tmp -> Parent << std::endl;
			nowIndex++;
		}
		
		void showPrefix(void)
		{
			Node *show = root;
			int i = 1;
			std::cout << "Starting Prefix" << std::endl;

			while(i < nowIndex)
			{
				std::cout << "Order " << i++ << ", " << show << " : " << "Index " << show -> index << std::endl;
				
				if(show -> LChild != nullptr)
					show = show -> LChild;
				else if(show -> RChild != nullptr)
					show = show -> RChild;
				else if(show == show -> Parent -> RChild)
				{
					while(show != show -> Parent -> LChild)
					{
						show = show -> Parent;
						if(show == root)
							break;
					}

					show = show -> Parent -> RChild;
				}
				else
				{
					while(show -> RChild == nullptr)
						show = show -> Parent;

					show = show -> RChild;
				}
			}
		}
		
		void showInfix(void)
		{
			Node *show = root;
			int i = 1;
			std::cout << "Starting Infix" << std::endl;

			while(i < nowIndex)
			{
				if(show -> LChild != nullptr)
					show = show -> LChild;
				if(show -> RChild != nullptr)
					show = show -> RChild;
				else if(show == show -> Parent -> RChild)
				{
					std::cout << "Order " << i++ << ", " << show << " : " << "Index " << show -> index << std::endl;
					while(show != show -> Parent -> LChild)
					{
						show = show -> Parent;
						if(show == root)
							break;
					}

					show = show -> Parent -> RChild;
				}
				else
				{
					while(show -> RChild == nullptr)
					{
						show = show -> Parent;
						std::cout << "Order " << i++ << ", " << show << " : " << "Index " << show -> index << std::endl;
					}

					show = show -> RChild;
					std::cout << "Order " << i++ << ", " << show << " : " << "Index " << show -> index << std::endl;
				}
			}
		}
		
		void showPostfix(void)
		{
			Node *show = root;
			int i = 1;
			std::cout << "Starting Postfix" << std::endl;

			while(i < nowIndex)
			{
				if(show -> LChild != nullptr)
					show = show -> LChild;
				else if(show -> RChild != nullptr)
					show = show -> RChild;
				else if(show == show -> Parent -> RChild)
				{
					std::cout << "Order " << i++ << ", " << show << " : " << "Index " << show -> index << std::endl;
					while(show != show -> Parent -> LChild)
					{
						show = show -> Parent;
						std::cout << "Order " << i++ << ", " << show << " : " << "Index " << show -> index << std::endl;
						if(show == root)
							break;
					}

					show = show -> Parent -> RChild;
				}
				else
				{
					while(show -> RChild == nullptr)
					{
						std::cout << "Order " << i++ << ", " << show << " : " << "Index " << show -> index << std::endl;
						show = show -> Parent;
					}

					show = show -> RChild;
				}
			}
		}
};

int main(void)
{
	BiTree bt(1);
	bt.insert(2);
	bt.insert(3);
	bt.insert(4);
	bt.insert(4);
	bt.insert(4);
	bt.insert(4);
	bt.insert(4);
	bt.insert(3);
	bt.insert(3);
	bt.insert(3);
	bt.insert(3);
	bt.insert(4);
	bt.insert(4);
	bt.insert(4);
	bt.insert(4);
	bt.insert(3);
	bt.insert(3);
	bt.insert(3);
	
	std::cout << std::endl;

	//bt.showPrefix();
	bt.showInfix();
	//bt.showPostfix();
	return 0;
}
