#include <iostream>

using namespace std;

typedef struct tStackNode {
	int data;
	tStackNode* link;
} stackNode;

stackNode* top; // 스택 노드의 top 포인터 저장

int iEmpty();
void push(int _iNum);
int pop();
int peek();
void printStack();

int main()
{
	int iNum(0);

	printStack();
	push(1);
	printStack();
	push(2);
	printStack();
	push(3);
	printStack();

	iNum = peek();
	cout << "peek -> " << iNum << endl;

	for (int i = 0; i < 3; ++i) {
		iNum = pop();
		cout << "pop -> " << iNum << endl;
		printStack();
	}
}

int iEmpty() {
	if (top == nullptr) return true;
	else return false;
}

void push(int _iNum) {
	stackNode* pTemp = new stackNode;
	pTemp->data = _iNum;
	pTemp->link = top;
	top = pTemp;
}

int pop() {
	int iNum;
	stackNode* pTemp = top;

	if (iEmpty()) return 0;
	else {
		iNum = pTemp->data;
		top = pTemp->link;
		delete pTemp;
		pTemp = nullptr;

		return iNum;
	}
}

//스택의 top 원소 검색
int peek() {
	if (iEmpty()) return 0;
	else return top->data;
}

//스택 원소 목록 출력
void printStack() {
	stackNode* pTemp = top;

	while (pTemp) {
		cout << pTemp->data << " ";
		pTemp = pTemp->link;
	}
	cout << endl << endl;
}