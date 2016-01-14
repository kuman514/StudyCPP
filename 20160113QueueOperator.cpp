#include <iostream>

struct Stack
{
	int integers[10];
	char operators[10];
	int icount;
	int opcount;

	Stack() : icount(0), opcount(0) {}
	void addInt(int num)
	{
		integers[icount] = num;
		std::cout << integers[icount] << std::endl;
		icount++;
	}
	void addOp(char op)
	{
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
		void testi(int a) { stack.addInt(a); }
		void testo(char b) { stack.addOp(b); }
		void opsort()
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
			break;
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
	while((*input != '+') && (*input != '-') && (*input != '*') && (*input != '/'))
	{
		input++;
		if(*input == '\0')
			break;
	}

	return *input;
}

int main(void)
{
	char input[100] = {" 300 - 40 * 170 / 514 +"};
	char *cur = input;
	int a;
	char b;
	Op_Queue queue;

	while(*cur != '\0')
	{
		a = stoi(cur);
		queue.testi(a);
		b = stoop(cur);
		queue.testo(b);
	}

	return 0;
}
