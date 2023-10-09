#include <iostream>

typedef struct tNodeInfo {
	int data;
	tNodeInfo* link;
} listNode;

typedef struct {
	listNode* head;
} linkedList_h;

using namespace std;

/*
1. ���� ���� ����Ʈ ����
2. ���� ����Ʈ�� ��ü �޸� �����
3. ���� ����Ʈ�� ������� ���
4. ù��° ���� ����
5. ��带 pre �ڿ� ����
6. ������ ���� ����*/

linkedList_h* CreateLinkedList_h();
void deleteListPointer(linkedList_h* l);
void printList(linkedList_h* l);
void insertFirstNode(linkedList_h* l, int _iNum);
void insertMiddleNode(linkedList_h* l, listNode* pre, int _iNum);
void insertLastNode(linkedList_h* l, int _iNum);

/*
1. ����Ʈ���� ��� p�� �����ϴ� ����
2. ����Ʈ���� ��Ʈ x�� Ž���ϴ� ����
3. ����Ʈ�� ��� ������ �������� �ٲٴ� ����
*/
void deleteNode(linkedList_h* l, listNode* p);
listNode* searchNode(linkedList_h* l, int _iNum);
void reverse(linkedList_h* l);

int main() {
	linkedList_h* l = CreateLinkedList_h();
	printList(l);

	insertFirstNode(l, 1);
	printList(l);

	insertLastNode(l, 2);
	printList(l);

	insertFirstNode(l, 4);
	printList(l);

	deleteListPointer(l);
	cout << "��� delete" << endl;
	printList(l);
}

linkedList_h* CreateLinkedList_h() {
	linkedList_h* l = new linkedList_h;
	l->head = nullptr;
	return l;
}

void deleteListPointer(linkedList_h* l) {
	listNode* p;
	while (l->head != nullptr) {
		p = l->head;
		l->head = l->head->link;
		delete p;
		p = nullptr;
	}
}

void printList(linkedList_h* l) {
	listNode* p;
	p = l->head;

	cout << "[[LIST]]" << endl;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->link;
	}
	cout << endl << endl;
} 

void insertFirstNode(linkedList_h* l, int _iNum) {
	listNode* p = new listNode;
	p->data = _iNum;
	p->link = l->head;
	l->head = p;
}

void insertMiddleNode(linkedList_h* l, listNode* pre, int _iNum) {
	listNode* p = new listNode;
	p->data = _iNum;

	if (l == nullptr) {
		p->link = nullptr;
		l->head = p;
	} 
	else if (pre == nullptr) {
		l->head = p;
	}
	else {
		p->link = pre->link;
		pre->link = p;
	}
}

void insertLastNode(linkedList_h* l, int _iNum) {
	listNode* p = new listNode;
	listNode* pTemp;

	p->data = _iNum;
	p->link = nullptr;

	if (l->head == nullptr) {
		l->head = p;
		return;
	}
	
	pTemp = l->head; 
	while (pTemp->link != nullptr) pTemp = pTemp->link; // ���� ����Ʈ�� ������ ��带 ã��
	pTemp->link = p; // �� ��带 ������ ����� ���� ���� ����
}

void deleteNode(linkedList_h* l, listNode* p) {
	listNode* pre;

	if (l->head == nullptr) return;
	if (l->head->link == nullptr) {
		delete l->head;
		l->head = nullptr;
		return;
	}
	else if (p == nullptr) return;
	else {
		pre = l->head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;
		delete p;
	}
}

listNode* searchNode(linkedList_h* l, int _iNum) {
	listNode* pTemp;
	pTemp = l->head;
	while (pTemp != nullptr) {
		if (pTemp->data == _iNum) return pTemp;
		else pTemp = pTemp->link;
	}
	return pTemp;
}

void reverse(linkedList_h* l) {
	listNode* p;
	listNode* q;
	listNode* r;

	p = l->head;
	q = nullptr;
	r = nullptr;

	while (p != nullptr) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
}