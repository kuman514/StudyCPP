#include <iostream>
#include <cstdio>

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
		//std::cout << integers[icount] << std::endl;
		icount++;
	}
	void addOp(char op)
	{
		if(op == -1)
			return;

		operators[opcount] = op;
		//std::cout << operators[opcount] << std::endl;
		opcount++;

		operators[opcount] = -1;
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
			int i, j = 0, p = -1;
			// i for integers, j for operators, p for location of +- operators.

			std::cout << stack.integers[0] << ' ';
			for(i = 1; i < stack.icount; i++, j++)
			{
				std::cout << stack.integers[i] << ' ';

				if((stack.operators[j] == '+') || (stack.operators[j] == '-'))
				{
					if((stack.operators[j + 1] == '+') || (stack.operators[j + 1] == '-'))
						std::cout << stack.operators[j] << ' ';
					else if(j + 1 >= stack.opcount)
						std::cout << stack.operators[j] << ' ';
					else
						p = j;
				}
				else if((stack.operators[j] == '*') || (stack.operators[j] == '/'))
				{
					std::cout << stack.operators[j] << ' ';
					
					if((stack.operators[j + 1] == '+') || (stack.operators[j + 1] == '-'))
					{
						if(p != -1)
							std::cout << stack.operators[p] << ' ';
						p = -1;
					}
					else if(j + 1 >= stack.opcount)
						std::cout << stack.operators[p] << ' ';
				}
			}

			std::cout << std::endl;
		}
		
		void printSeqRev(void)
		{
			int i, md = 0;

			// 1+2-3/4*5*6+7*8 -> "+ - + 1 2 * * / 3 4 5 6 * 7 8"
			// 1*2/3+4-5/6-7*8 -> "- - + / * 1 2 3 4 / 5 6 * 7 8"
			for(i = stack.opcount - 1; i >= 0; i--)
			{
				if((stack.operators[i] == '+') || (stack.operators[i] == '-'))
					std::cout << stack.operators[i] << ' ';
			}

			i = 0;
			while(i < stack.icount)
			{
				if((stack.operators[i] == '*') || (stack.operators[i] == '/'))
				{
					md = i;
					while((stack.operators[i] != '+') && (stack.operators[i] != '-'))
					{
						if(stack.operators[i] == -1)
							break;

						i++;
					}

					for(int k = i - 1; k >= md; k--)
						std::cout << stack.operators[k] << ' ';

					i--;
				}
				
				std::cout << stack.integers[i] << ' ';
				i++;
			}

			std::cout << std::endl;
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

	char input[100];
	char *cur;
	Op_Queue queue;

	scanf("%[^\n]", input);
	
	cur = input;
	while(*cur != '\0')
		queue.readi(cur);

	cur = input;
	while(*cur != '\0')
		queue.reado(cur);

	queue.printSeq();
	queue.printSeqRev();
	return 0;

}
