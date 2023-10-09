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

}

LinkedList_h* CreateLinkedList_h() {

}
void printList(LinkedList_h* cl);
void insertFirstNode(LinkedList_h* cl, int _iNum);
void insertMiddleNode(LinkedList_h* cl, Node* pre, int _iNum);
void deleteNode(LinkedList_h* cl, Node* old);
Node* searchNode(LinkedList_h* cl, int _iNum);

//아 하기싫어 죽겠넴 ㅋㅋ