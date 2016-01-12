#include <iostream>
#include <cstring>

struct Node
{
	Node *prev;

	int num;
	char *name;

	Node *next;
};

int cmp(Node *n1, Node *n2);

class DLLEI				// Double Linked List Exchange Included
{
	private:
		Node *top;
		Node *bottom;
		void nodeExchange(Node *n1, Node *n2)
		{
			if(n1 -> next == n2)		// if ...]-[n1]-[n2]-[...
			{
				n2 -> prev = n1 -> prev;
				n1 -> prev -> next = n2;

				n1 -> prev = n2;
				n1 -> next = n2 -> next;
				n2 -> next -> prev = n1;
				n2 -> next = n1;
			}
			else						// if ...]-[n2]-[n1]-[...
			{
				n1 -> prev = n2 -> prev;
				n2 -> prev -> next = n1;

				n2 -> prev = n1;
				n2 -> next = n1 -> next;
				n1 -> next -> prev = n2;
				n1 -> next = n2;
			}
		}
	public:
		void init(void)
		{
			top = new Node;
			bottom = new Node;

			top -> prev = top;
			top -> next = bottom;
	
			bottom -> prev = top;
			bottom -> next = bottom;
		}
		void insert(int num, const char *name);
		void search(const char *search);
		void remove(const char *search);
		void sort(int (*compare)(Node *,Node *));
		void show(void)
		{
			Node *tmp = top -> next;
			while(tmp != bottom)
			{
				std::cout << tmp -> num << ' ' << tmp -> name << std::endl;
				tmp = tmp -> next;
			}
		}
		void isEmpty(void)
		{
			if(top -> next == bottom && bottom -> prev == top)
				std::cout << "EMPTY" << std::endl;
			else
				std::cout << "NOT EMPTY" << std::endl;
		}
};

void DLLEI::insert(int num, const char *name)
{
	Node *tmp = new Node;
	tmp -> num = num;
	tmp -> name = new char[strlen(name) + 1];
	strcpy(tmp -> name, name);

	tmp -> prev = bottom -> prev;
	tmp -> next = bottom;

	bottom -> prev -> next = tmp;
	bottom -> prev = tmp;

	std::cout << "Inserted : " << tmp -> name << ", " << tmp -> num << std::endl;
}

void DLLEI::search(const char *search)
{
	Node *tmp = top -> next;

	while(tmp != bottom)
	{
		if(strcmp(search, tmp -> name) == 0)
			std::cout << tmp -> num << ' ' << tmp -> name << std::endl;

		tmp = tmp -> next;
	}
}

void DLLEI::remove(const char *search)
{
	Node *tmp = top -> next;

	while(tmp != bottom)
	{
		if(strcmp(search, tmp -> name) == 0)
		{
			std::cout << "Remove : " << tmp -> name << ' ' << tmp -> num << std::endl;
			tmp -> num = 0;
			strcpy(tmp -> name, "");
			delete tmp -> name;
			tmp -> prev -> next = tmp -> next;
			tmp -> next -> prev = tmp -> prev;

			delete tmp;
			return;
		}
		
		tmp = tmp -> next;
	}

	std::cout << "No node found : " << search << std::endl;
}

void DLLEI::sort(int (*compare)(Node *, Node *))
{
	Node *itmp, *jtmp, *chtmp;

	itmp = top -> next;
	while(itmp != bottom)
	{
		jtmp = bottom -> prev;
		while((jtmp != itmp) && (itmp -> prev != jtmp))
		{
			if(compare(jtmp -> prev, jtmp) > 0)
				nodeExchange(jtmp -> prev, jtmp);
			else
				jtmp = jtmp -> prev;
		}

		itmp = itmp -> next;
	}
}

int main(void)
{
	DLLEI List;
	List.init();
	List.isEmpty();

	List.insert(514, "koishi");
	List.insert(210, "nitori");
	List.sort(cmp);
	List.isEmpty();
	List.show();

	List.remove("koishi");
	List.isEmpty();
	List.show();

	List.remove("koishi");
	List.remove("nitori");
	List.isEmpty();
	//char cinput;
	//int iinput;
	//char sinput[20];

	return 0;
}

int cmp(Node *n1, Node *n2)
{
	std::cout << "Comparing : " << n1 -> name << ' ' << n1 -> num << ", " << n2 -> name << ' ' << n2 -> num << std::endl;
	return (n1 -> num) - (n2 -> num);
}
