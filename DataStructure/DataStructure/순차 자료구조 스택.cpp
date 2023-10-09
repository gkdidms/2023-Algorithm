#include <iostream>
#define STACK_SIZE 100

using namespace std;


int stack[STACK_SIZE];
int top = -1;

bool isEmpty();
bool isFull();
void push(int _iNum);
int pop();
int peek();
void printStack();

int main() {
	int iNum;
	printStack();

	push(1);
	printStack();
	push(2);
	printStack();
	push(3);
	printStack();

	iNum = peek();
	cout << "peek -> " << iNum << endl;
	printStack();
	
	iNum = pop();
	cout << "pop -> " << iNum << endl;
	printStack();

	iNum = pop();
	cout << "pop -> " << iNum << endl;
	printStack();

	iNum = pop();
	cout << "pop -> " << iNum << endl;
	printStack();

}

// ������ ����ִ��� Ȯ���ϴ� �Լ�
bool isEmpty() {
	// top�� ũ�Ⱑ STACK_SIZE -1 �� ���� ��� �� ������.
	if (top == STACK_SIZE - 1) return false;
	else return true;
}

// ������ �� �� �ִ��� Ȯ���ϴ� �Լ�
bool isFull() {
	if (top == STACK_SIZE - 1) return true;
	else return false;
}

//���� ����
void push(int _iNum) {
	if (isFull()) return;
	else stack[++top] = _iNum;
}

//���� ����
int pop() {
	if (!isEmpty()) return 0;
	else return stack[top--];
}

// ������ top ���Ҹ� �˻��ϴ� ����
int peek() {
	if (!isEmpty()) return false;
	else return stack[top];
}

// ������ ���Ҹ� ����ϴ� ����
void printStack() {
	cout << "[STACK]" << endl;
	for (int i = 0; i < top + 1; ++i)
		cout << stack[i] << ",";
	cout << endl << endl;
}