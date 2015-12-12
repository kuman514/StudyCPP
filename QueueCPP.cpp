#include <iostream>

/*
   first-----------------last
*/

struct Node
{
    int data;
    Node *next;
};

class Queue
{
    public:
        Queue();
        ~Queue();
        void enQueue(int num);
        int deQueue();
        int peak();
        bool isEmpty();
        int getCount();
    private:
        Node *first;
        Node *last;
        int count;
};

Queue::Queue()
{
    first = new Node;
    last = new Node;

    first -> next = last;
    last -> next = last;

    count = 0;
};

Queue::~Queue()
{
    Node *tmp = first -> next;
    Node *back = tmp -> next;

    if(count != 0)
    {
        while(tmp != last)
        {
            delete tmp;
            tmp = back;
            back = back -> next;
        }

        delete first;
        delete last;
        count = 0;
    }
};

int main(void)
{
    Queue queue = Queue();
    char cinput;
    int iinput;
    
    while(cinput != 'q')
    {
        std::cout << "[e]nQueue [d]eQueue [p]eak [g]etCount [i]sEmpty [c]lear [q]uit" << std::endl;
        std::cout << "input : ";
        std::cin >> cinput;
        switch(cinput)
        {
            case 'e':
                std::cin >> iinput;
                queue.enQueue(iinput);
                break;
            case 'd':
                std::cout << "deQueue : " << queue.deQueue() << std::endl;
                break;
            case 'p':
                std::cout << "Peak : " << queue.peak() << std::endl;
                break;
            case 'i':
                std::cout << "Is that queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;
                break;
            case 'c':
                queue.~Queue();
                queue = Queue();
                break;
            case 'g':
                std::cout << "Number of Queue Nodes : " << queue.getCount() << std::endl;
                break;
            default:
                break;
        }
    }

    return 0;
}

void Queue::enQueue(int num)
{
    Node *tmp = new Node, *search = first;
    tmp -> data = num;

    while(search -> next != last)
        search = search -> next;

    tmp -> next = last;
    search -> next = tmp;

    count++;
}

int Queue::deQueue()
{
    Node *tmp = first -> next;
    int box;
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        box = tmp -> data;
        first -> next = tmp -> next;
        tmp -> next = nullptr;
        delete tmp;
        tmp = nullptr;
        count--;
        return box;
    }
}

int Queue::peak()
{
    return first -> next -> data;
}

bool Queue::isEmpty()
{
    if(first -> next == last)
        return 1;
    else
        return 0;
}

int Queue::getCount()
{
    return count;
}
