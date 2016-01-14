#include <iostream>

int stoi(char* &);
char stoop(char* &);

struct Stack
{
	int integers[10];
	char operators[10];
	int icount;
	int opcount;

	Stack() : icount(0), opcount(0) {}
	void addInt(int num)
	{
		if(num == -1)
			return;

		integers[icount] = num;
		std::cout << integers[icount] << std::endl;
		icount++;
	}
	void addOp(char op)
	{
		if(op == -1)
			return;

		operators[opcount] = op;
		std::cout << operators[opcount] << std::endl;
		opcount++;
	}
};

struct Op_Queue
{
	private:
		Stack stack;
		char opseq[10];
	public:
		void readi(char* &cur) { stack.addInt(stoi(cur)); }
		void reado(char* &cur) { stack.addOp(stoop(cur)); }
		void opSort()
		{
			int count = 0;

			for(int i = 0; i < stack.opcount; i++)
			{
				if((stack.operators[i] == '*') || (stack.operators[i] == '/'))
				{
					opseq[count] = stack.operators[i];
					count++;
				}
			}

			for(int i = 0; i < stack.opcount; i++)
			{
				if((stack.operators[i] == '+') || (stack.operators[i] == '-'))
				{
					opseq[count] = stack.operators[i];
					count++;
				}
			}
		}
		void printSeq(void)
		{
		}
		void printSeqRev(void)
		{
		}
};

int stoi(char* &input)
{
	int result = 0;

	while(!('0' <= *input && *input <= '9'))
	{
		input++;
		if(*input == '\0')
			return -1;
	}

	while('0' <= *input && *input <= '9')
	{
		result = (result * 10) + (*input - '0');
		input++;
		if(!('0' <= *input && *input <= '9'))
			break;
	}

	return result;
}

char stoop(char* &input)
{
	char result;

	while((*input != '+') && (*input != '-') && (*input != '*') && (*input != '/'))
	{
		input++;
		if(*input == '\0')
			return -1;
	}

	result = *input;
	input++;

	return result;
}

int main(void)
{
	// 1+2*3 -> "1 2 3 * +" and "+ 1 * 2 3"
	// 1*2+3 -> "1 2 * 3 +" and "+ * 1 2 3"
	// 1+2*3-4 -> "1 2 3 * + 4 -" and "- + 1 * 2 3 4"
	// 1-2+3*4 -> "1 2 - 3 4 * +" and "+ - 1 2 * 3 4"

	char input[100] = {"1+2*3-4"};		// should print "123*+" and "+1*23"
	char *cur = input;
	Op_Queue queue;

	while(*cur != '\0')
		queue.readi(cur);

	cur = input;
	while(*cur != '\0')
		queue.reado(cur);

	queue.opSort();
	queue.printSeq();
	queue.printSeqRev();

	return 0;
}
