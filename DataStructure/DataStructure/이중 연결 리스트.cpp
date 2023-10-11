#include <iostream>

using namespace std;

typedef struct ListNode {
	ListNode* llink;
	int data;
	ListNode* rlink;
} listNode;

typedef struct {
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h();
void printList(linkedList_h* dl);
void insertNode(linkedList_h* dl, listNode* pre, int _iNum);
void deleteNode(linkedList_h* dl, listNode* old);
listNode* searchNode(linkedList_h* dl, int x);

int main()
{
	linkedList_h* dl;
	listNode* p;

	dl = createLinkedList_h();
	cout << "1. ���� ���� ����Ʈ �����ϱ� ! " << endl;
	printList(dl);

	cout << "2. ���� ���� ����Ʈ�� 1 �����ϱ�" << endl;
	insertNode(dl, nullptr, 1);
	printList(dl);

	cout << "3. ���� ���� ����Ʈ�� 1 ��� �ڿ� 2 �����ϱ�" << endl;
	p = searchNode(dl, 1);
	insertNode(dl, p, 2);
	printList(dl);

	cout << "4. ���� ���� ����Ʈ�� 2 ��� �ڿ� 3 �����ϱ�" << endl;
	p = searchNode(dl, 2);
	insertNode(dl, p, 3);
	printList(dl);

	cout << "5. ���� ���� ����Ʈ���� 2 �����ϱ�" << endl;
	p = searchNode(dl, 2);
	deleteNode(dl, p);
	printList(dl);

}

linkedList_h* createLinkedList_h() {
	linkedList_h* dl = new linkedList_h;
	dl->head = nullptr;
	return dl;
}


void printList(linkedList_h* dl) {
	listNode* p;
	p = dl->head;

	while (p != nullptr) {
		cout << p->data;
		p = p->rlink;
		if (p != nullptr) cout << ",";
	}
	cout << endl << endl;
}

void insertNode(linkedList_h* dl, listNode* pre, int _iNum)
{
	listNode* newNode = new listNode;
	newNode->data = _iNum;

	if (dl->head == nullptr) {
		newNode->rlink = nullptr;
		newNode->llink = nullptr;
		dl->head = newNode;
	}
	else {
		newNode->rlink = pre->rlink;
		pre->rlink = newNode;
		newNode->llink = pre;
		if (newNode->rlink != nullptr)
			newNode->rlink->llink = newNode;
	}
}
void deleteNode(linkedList_h* dl, listNode* old)
{
	if (dl->head == nullptr) return;
	else if (old == nullptr) return;
	else {
		old->llink->rlink = old->rlink;
		old->rlink->llink = old->llink;
		
		delete old; // �޸� ����
	}

}
listNode* searchNode(linkedList_h* dl, int x)
{
	listNode* pTemp;
	pTemp = dl->head;
	while (pTemp != nullptr) {
		if (pTemp->data == x) return pTemp;
		else pTemp = pTemp->rlink;
	}
	return pTemp;
}