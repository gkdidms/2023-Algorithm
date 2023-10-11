#include <iostream>

using namespace std;

/*
1. ���� ���� ����Ʈ ����
2. ���� ����Ʈ ������� ���
3. ù ��° ��� ���� ����
4. pre �ڿ� ��带 �����ϴ� ����
5. ���� ���� ����Ʈ�� pre �ڿ� �ִ� ��� old�� �����ϴ� ����
6. ���� ���� ����Ʈ���� x ��带 Ž���ϴ� ����
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
	cout << "1. ���� ���� ����Ʈ �����ϱ� !" << endl;
	
	cout << "2. ���� ���� ����Ʈ�� 1 �����ϱ�" << endl;
	insertFirstNode(cl, 1);
	printList(cl);

	cout << "3. ���� ���� ����Ʈ�� 1 ��� �ڿ� 2 ��� �����ϱ�" << endl;
	p = searchNode(cl, 1);
	insertMiddleNode(cl, p, 2);
	printList(cl);

	cout << "4. ���� ���� ����Ʈ�� 2��� �ڿ� 3 �����ϱ�" << endl;
	p = searchNode(cl, 2);
	insertMiddleNode(cl, p, 3);
	printList(cl);

	cout << "5. ���� ���� ����Ʈ���� 2 ��� �����ϱ�" << endl;
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

//ù��° ��� ���� ����
void insertFirstNode(LinkedList_h* cl, int _iNum) {
	Node* newNode, * Temp;
	newNode = new Node;
	newNode->data = _iNum;

	if (cl->head == nullptr) { // ���� ���� ����Ʈ�� ������ ���
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

//pre �ڿ� ��带 �����ϴ� ����
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

//���� ���� ����Ʈ�� pre �ڿ� �ִ� ��� old�� �����ϴ� ����
void deleteNode(LinkedList_h* cl, Node* old) {
	Node* pre;
	if (cl->head == nullptr) return;
	if (cl->head->link == nullptr) { // ����Ʈ�� ��尡 �Ѱ��� �ִ� ���.
		delete cl->head;
		cl->head = nullptr;
		return;
	}
	else if (old == nullptr) return; // ������ ��尡 ���� ��� ���� ������ �ߴ�
	else {
		pre = cl->head;
		while (pre->link != old)
			pre = pre->link; // ������ ��带 ������ pre�� �̿��� ã��.

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

