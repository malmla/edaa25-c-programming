#define N (10)
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int stack[N];
int top = -1;

bool is_empty()
{
	if (top == -1){
		return true;
	} else {
		return false;
	}
}

bool is_full()
{
	if (top == N - 1){
		return true;
	} else {
		return false;
	}
}

int peek()
{
	return stack[top];
}

int pop()
{
	if (!is_empty()) {
		int value = stack[top];
		top = top -1;
		return value;
	} else {
		return -1; // display stack was empty error msg
	}

}

bool push(int value)
{
	if (!is_full()) {
		top = top + 1;
		stack[top] = value;
		return true;
	} else {
		return false;
	}
}

unsigned char line = 1;

void skip_line(int c)
{
	while (c != '\n')
	{
		c = getchar();
	}
	line = line + 1;
	top = -1;
}

int main(void)
{
	int next = getchar();
	signed int number = -1;
	int op1 = -1;
	int op2 = -1;
	char err = 0;
	while (next != EOF)
	{
		if (isdigit(next)){
			//build number
			if (number == -1){
				number = (next - '0');
			} else {
				number = (number * 10) + (next - '0');
			}
		} else {
			if (number==-1){
			} else {
				if (is_full()){
					printf("line %d: error at %d\n",line,number);
					skip_line(next);
				} else {
					push(number);
				}
			}
			number = -1;
		}

		if (next == '+'){
			//do addition, push result
			//check for too few numbers on stack
			//print errors, skip line
			if (top<1)
			{
				printf("line %d: error at +\n",line);
				skip_line(next);
			} else {
				op2 = pop();
				op1 = pop();
				op1 = op1 + op2;
				push(op1);
			}
		} else if (next == '-'){
			//do subtraction, push result
			//check for too few numbers on stack
			//print errors, skip line
			if (top<1)
			{
				printf("line %d: error at -\n",line);
				skip_line(next);
			} else {
				op2 = pop();
				op1 = pop();
				op1 = op1 - op2;
				push(op1);
			}
		} else if (next == '*'){
			//do multiplication, push result
			//check for too few numbers on stack
			//print errors, skip line
			if (top<1)
			{
				printf("line %d: error at *\n",line);
				skip_line(next);
			} else {
				op2 = pop();
				op1 = pop();
				op1 = op1 * op2;
				push(op1);
			}
		} else if (next == '/'){
			//do division, push result
			//check for div by 0, too few numbers on stack
			//print errors, skip line
			if (top<1)
			{
				printf("line %d: error at /\n",line);
				skip_line(next);
			} else {
				op2 = pop();
				op1 = pop();
				if (op2 != 0){
					op1 = op1 / op2;
					push(op1);
				} else {
					printf("line %d: error at /\n",line);
					skip_line(next);
				}

			}
		} else if (next == '\n'){
			//print result, increase line
			//check for empty stack, more than one number on stack
			//print errors
			if (top!=0 || is_empty() == 1)
			{
				err = next;
				printf("line %d: error at \\n\n",line);
				line = line + 1;
				top = -1;
			} else {
				int result = pop();
				printf("line %d: %d\n",line,result);
				line = line +1;
				top = -1;
			}
		} else if (!isdigit(next) && next != ' ') {
			err = (char)next;
			printf("line %d: error at %c\n",line,err);
			skip_line(next);
		}
		next = getchar();
	}
	return 0;
}

