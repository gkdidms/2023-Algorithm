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

}

LinkedList_h* CreateLinkedList_h() {

}
void printList(LinkedList_h* cl);
void insertFirstNode(LinkedList_h* cl, int _iNum);
void insertMiddleNode(LinkedList_h* cl, Node* pre, int _iNum);
void deleteNode(LinkedList_h* cl, Node* old);
Node* searchNode(LinkedList_h* cl, int _iNum);

//�� �ϱ�Ⱦ� �װڳ� ����