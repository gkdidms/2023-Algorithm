#include <iostream>

using namespace std;

/*
1. 원형 연결 리스트 생성
2. 연결 리스트 순서대로 출력
3. 첫 번째 노드 삽입 연산
4. pre 뒤에 노드를 삽입하는 연산
5. 원형 연결 리스트의 pre 뒤에 있는 노드 old를 삭제하는 연산
6. 원형 연결 리스트에서 x 노드를 탐색하는 연산
*/

typedef struct tInfo {
	int data;
	tInfo* link;
}Node;

typedef struct {
	Node* head;
} LinkedList_h;

LinkedList_h* CreateLinkedList_h();
void printList(LinkedList_h* cl);
void insertFirstNode(LinkedList_h* cl, int _iNum);
void insertMiddleNode(LinkedList_h* cl, Node* pre, int _iNum);
void deleteNode(LinkedList_h* cl, Node* old);
Node* searchNode(LinkedList_h* cl, int _iNum);

int main()
{
	LinkedList_h* cl;
	Node* p;

	cl = CreateLinkedList_h();
	cout << "1. 원형 연결 리스트 생성하기 !" << endl;
	
	cout << "2. 원형 연결 리스트에 1 삽입하기" << endl;
	insertFirstNode(cl, 1);
	printList(cl);

	cout << "3. 원형 연결 리스트의 1 노드 뒤에 2 노드 삽입하기" << endl;
	p = searchNode(cl, 1);
	insertMiddleNode(cl, p, 2);
	printList(cl);

	cout << "4. 원형 연결 리스트의 2노드 뒤에 3 삽입하기" << endl;
	p = searchNode(cl, 2);
	insertMiddleNode(cl, p, 3);
	printList(cl);

	cout << "5. 원형 연결 리스트에서 2 노드 삭제하기" << endl;
	p = searchNode(cl, 2);
	deleteNode(cl, p);
	printList(cl);
}

LinkedList_h* CreateLinkedList_h() {
	LinkedList_h* cl = new LinkedList_h;
	cl->head = nullptr;
	return cl;
}

void printList(LinkedList_h* cl) {
	Node* p;
	
	p = cl->head;

	do {
		cout << p->data ;
		p = p->link;
		if (p != cl->head) cout << ",";
	} while (p != cl->head);
	cout << endl << endl;
}

//첫번째 노드 삽입 연산
void insertFirstNode(LinkedList_h* cl, int _iNum) {
	Node* newNode, * Temp;
	newNode = new Node;
	newNode->data = _iNum;

	if (cl->head == nullptr) { // 원형 연결 리스트가 공백일 경우
		cl->head = newNode;
		newNode->link = newNode;
	}
	else {
		Temp = cl->head;
		while (Temp->link != cl->head)
			Temp = Temp->link;
		newNode->link = Temp->link;
		Temp->link = newNode;
		cl->head = newNode;
	}
}

//pre 뒤에 노드를 삽입하는 연산
void insertMiddleNode(LinkedList_h* cl, Node* pre, int _iNum) {
	Node* newNode = new Node;
	newNode->data = _iNum;

	if (cl == NULL) {
		cl->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

//원형 연결 리스트의 pre 뒤에 있는 노드 old를 삭제하는 연산
void deleteNode(LinkedList_h* cl, Node* old) {
	Node* pre;
	if (cl->head == nullptr) return;
	if (cl->head->link == nullptr) { // 리스트에 노드가 한개만 있는 경우.
		delete cl->head;
		cl->head = nullptr;
		return;
	}
	else if (old == nullptr) return; // 삭제할 노드가 없는 경우 삭제 연산자 중단
	else {
		pre = cl->head;
		while (pre->link != old)
			pre = pre->link; // 선행자 노드를 포인터 pre를 이용해 찾음.

		pre->link = old->link;
		if (old == cl->head)
			cl->head = old->link; 
		delete old;
	}
}

Node* searchNode(LinkedList_h* cl, int _iNum) {
	Node* pTemp;
	pTemp = cl->head;

	while (pTemp != nullptr) {
		if (pTemp->data == _iNum) return pTemp;
		else pTemp = pTemp->link;
	}

	return pTemp;
}

