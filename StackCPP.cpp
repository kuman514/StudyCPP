#include <iostream>

#define YES 1
#define NO 0

// "g++ -std=c++11 StackCPP.cpp"

/*
   My Stack

   -------head-------
           :
     curr -> higher

        [curr] <-----(Current Node)

     curr -> lower
           :
   ------bottom------

   Actually, it was so confusing to use the default [tail -> prev] as the top data.
   Therefore, I decided to use some words related to altitude. (such as higher, lower, and bottom)
*/

struct Node
{
    Node *higher;
    int data;
    Node *lower;
};

class Stack
{
    public:
        Stack();                        // Make a new stack
        ~Stack();                       // Remove a stack
        void push(int num);             // Push a datum into [head -> lower]
        void pop();                     // Pop a datum at [head -> lower]
        int top();                      // I decided to show the [data] of Node [head -> lower], because that is the highest node.
        bool isEmpty();                 // Shows whether this stack is an empty stack list
        int checkSize();                // Shows the size of the stack list
    private:
        Node *head;  
        Node *bottom;
        int size;
};

Stack::Stack()
{
    head = new Node;
    bottom = new Node;
    
    head -> higher = head;
    head -> lower = bottom;

    bottom -> higher = head;
    bottom -> lower = bottom;
    
    curr = nullptr;
    size = 0;
}

Stack::~Stack()
{
    Node *tmp = head -> lower;
    
    while(tmp != bottom)
    {
        tmp -> data = 0;
        delete tmp;
        tmp = tmp -> lower;
    }
    
    delete head;
    delete bottom;
}

int main(void)
{
    Stack stack = Stack();
    char cinput = 0;
    int iinput = 0;
    std::cout << "Stack Data Storage" << std::endl;
    
    while(cinput != 'q')
    {
        std::cout << "[p]ush, p[o]p, [t]op, [c]heckSize, [e]mpty?, [q]uit" << std::endl;
        std::cout << "order : ";
        std::cin >> cinput;

        switch(cinput)
        {
            case 'p':
                std::cout << "Number? : ";
                std::cin >> iinput;
                stack.push(iinput);
                break;
            case 'o':
                stack.pop();
                break;
            case 't':
                std::cout << "Stack Top : " << stack.top() << std::endl;
                break;
            case 'c':
                std::cout << "Stack Size : " << stack.checkSize() << std::endl;
                break;
            case 'e':
                std::cout << "Is the stack EMPTY? : " << (stack.isEmpty() ? "Yes" : "No") << std::endl;
                break;
            case 'q':
                std::cout << "See you next time!" << std::endl;
                break;
            default:
                break;
        }
    }

    stack.~Stack();
    return 0;
}

void Stack::push(int num)
{
    Node *tmp = new Node;
    tmp -> data = num;

    tmp -> lower = head -> lower;
    head -> lower -> higher = tmp;

    head -> lower = tmp;
    tmp -> higher = head;

    ++size;
}

void Stack::pop()
{
    Node *tmp = head -> lower;

    if(!isEmpty())
    {
        std::cout << "pop : " << tmp -> data << std::endl;
        tmp -> data = 0;
        tmp -> lower -> higher = head;
        head -> lower = tmp -> lower;
        delete tmp;

        tmp -> higher = nullptr;
        tmp -> lower = nullptr;

        --size;
    }
    else
    {
        std::cout << "Error : Empty Stack List" << std::endl;
    }
}

bool Stack::isEmpty()
{
    if(head -> lower == bottom)
        return YES;
    else
        return NO;
}

int Stack::top()
{
    return head -> lower -> data;
}

int Stack::checkSize()
{
    return size;
}
