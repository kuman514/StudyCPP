#include <iostream>

int stoi(char* &);
char stoop(char* &);

struct Stack
{
	int integers[10];
	char operators[9];
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
	public:
		void readi(char* &cur) { stack.addInt(stoi(cur)); }
		void reado(char* &cur) { stack.addOp(stoop(cur)); }
		
		void printSeq(void)
		{
			int i, j = 0, p;

			std::cout << stack.integers[0] << ' ';
			for(i = 1; i < stack.icount; i++, j++)
			{
				std::cout << stack.integers[i] << ' ';

				if((stack.operators[j] == '+') || (stack.operators[j] == '-'))
				{
					if((stack.operators[j + 1] == '+') || (stack.operators[j + 1] == '-'))
						std::cout << stack.operators[j] << ' ';
					else
						p = j;
				}
				else if((stack.operators[j] == '*') || (stack.operators[j] == '/'))
				{
					std::cout << stack.operators[j] << ' ';
					
					if((stack.operators[j + 1] == '+') || (stack.operators[j + 1] == '-'))
						std::cout << stack.operators[p] << ' ';
				}
			}

			j++;
			if((stack.operators[j] == '+') || (stack.operators[j] == '-'))
				std::cout << stack.operators[j];
			std::cout << std::endl;
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
	// 1-2*3-4 -> "1 2 3 * - 4 -" and "- - 1 * 2 3 4"
	// 1*2-3/4 -> "1 2 * 3 4 / -" and "- * 1 2 / 3 4"

	char input[100] = {"1 + 2 - 3 * 4 * 5 /6 + 7-8"};
	char *cur = input;
	Op_Queue queue;

	while(*cur != '\0')
		queue.readi(cur);

	cur = input;
	while(*cur != '\0')
		queue.reado(cur);

	queue.printSeq();
	return 0;

}
