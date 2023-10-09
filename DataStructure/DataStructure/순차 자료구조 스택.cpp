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

// 스택이 비어있는지 확인하는 함수
bool isEmpty() {
	// top의 크기가 STACK_SIZE -1 과 같을 경우 꽉 차있음.
	if (top == STACK_SIZE - 1) return false;
	else return true;
}

// 스택이 꽉 차 있는지 확인하는 함수
bool isFull() {
	if (top == STACK_SIZE - 1) return true;
	else return false;
}

//삽입 연산
void push(int _iNum) {
	if (isFull()) return;
	else stack[++top] = _iNum;
}

//삭제 연산
int pop() {
	if (!isEmpty()) return 0;
	else return stack[top--];
}

// 스택의 top 원소를 검색하는 연산
int peek() {
	if (!isEmpty()) return false;
	else return stack[top];
}

// 스택의 원소를 출력하는 연산
void printStack() {
	cout << "[STACK]" << endl;
	for (int i = 0; i < top + 1; ++i)
		cout << stack[i] << ",";
	cout << endl << endl;
}