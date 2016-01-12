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
			/*
			else						// if ...]-[n2]-[n1]-[...
			{
				n1 -> prev = n2 -> prev;
				n2 -> prev -> next = n1;

				n2 -> prev = n1;
				n2 -> next = n1 -> next;
				n1 -> next -> prev = n2;
				n1 -> next = n2;
			}
			*/
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
	// Uses Bubble Sort
	Node *itmp, *jtmp, *chtmp;

	itmp = top -> next;
	while(itmp != bottom)
	{
		jtmp = bottom -> prev;
		while((jtmp != itmp) && (itmp -> prev != jtmp))
		{
			/*
				If the position of itmp and jtmp is...
				---[itmp == jtmp]--- OR ---[jtmp]---[itmp]---,
				itmp goes to its next node.

				As jtmp is exchanged...
				from ---[   ]---[jtmp -> prev]---[jtmp]---
				into ---[   ]---[jtmp]---[jtmp -> prev]---
				(the same as current ---[jtmp -> prev]---[jtmp]---[FORMER jtmp -> prev]---),
				we don't need to set jtmp = jtmp -> prev if jtmp exchange occurs.
			*/

			if(compare(jtmp -> prev, jtmp) > 0)
				nodeExchange(jtmp -> prev, jtmp);
			else
				jtmp = jtmp -> prev;
		}

		if(itmp -> prev != jtmp)
			itmp = itmp -> next;
		/*
		   if itmp is ---[jtmp]---[itmp]--- (itmp -> prev == jtmp),
		   we don't need to set itmp = itmp -> next
		*/
	}
}

int main(void)
{
	DLLEI List;
	char cinput;
	int iinput;
	char sinput[20];

	List.init();

	std::cout << "Double Linked List ~Node Exchange Included Edition~" << std::endl;
	while(cinput != 'E')
	{
		std::cout << "[i]nsert // [r]emove // [s]earch // S[o]rt // S[h]ow List // Is [e]mpty? // [E]xit" << std::endl;
		std::cout << "Input : ";
		std::cin >> cinput;

		switch(cinput)
		{
			case 'i':
				std::cout << "New name : ";
				std::cin >> sinput;
				std::cout << "New num : ";
				std::cin >> iinput;
				List.insert(iinput, sinput);
				break;
			case 'r':
				std::cout << "Name to remove : ";
				std::cin >> sinput;
				List.remove(sinput);
				break;
			case 's':
				std::cout << "Search : ";
				std::cin >> sinput;
				List.search(sinput);
				break;
			case 'o':
				List.sort(cmp);
				break;
			case 'h':
				List.show();
				break;
			case 'e':
				List.isEmpty();
				break;
			case 'E':
				break;
			default:
				std::cout << "Input error. Try again." << std::endl;
				break;
		}
	}
	return 0;
}

int cmp(Node *n1, Node *n2)
{
	//std::cout << "Comparing : " << n1 -> name << ' ' << n1 -> num << ", " << n2 -> name << ' ' << n2 -> num << std::endl;
	return (n1 -> num) - (n2 -> num);
}
