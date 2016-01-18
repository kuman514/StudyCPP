#include <iostream>
#define nullptr NULL

struct Node
{
	int data;
	Node *next;
};

struct List
{
	private:
		Node *head;
	public:
		List() 
		{
			head = new Node;
			head -> next = nullptr;
		}
		~List() {}

		void insert(int num)
		{
			Node *tmp, *add = new Node;
			add -> data = num;

			tmp = head;
			while(tmp -> next != nullptr)
				tmp = tmp -> next;

			tmp -> next = add;
			add -> next = nullptr;
		}

		void reverse(void)
		{
			Node *tmp;
			Node *tmphead = new Node;
			// tmphead will perform like STACK
			tmphead -> next = nullptr;

			tmp = head -> next;
			while(tmp != nullptr)
			{
				head -> next = tmp -> next;
				tmp -> next = tmphead -> next;
				tmphead -> next = tmp;
				tmp = head -> next;
			}
			
			head -> next = tmphead -> next;
			tmphead -> next = nullptr;
			delete tmphead;
		}

		void show(void)
		{
			Node *tmp = head -> next;

			while(tmp != nullptr)
			{
				std::cout << tmp -> data << std::endl;
				tmp = tmp -> next;
			}
		}
};

int main(void)
{
	List list;

	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.show();

	list.reverse();
	list.show();
	return 0;
}
