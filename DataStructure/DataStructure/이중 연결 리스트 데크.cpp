#include <iostream>

using namespace std;

typedef struct tDQInfo {
	int data;
	tDQInfo* llink;
	tDQInfo* rlink;
}DQNode;

typedef struct {
	DQNode* front, *rear;
}DQNodeType;

DQNodeType* CreateDQue();
bool isEmpty(DQNodeType* dq);
void insertFront(DQNodeType* dq, int _iNum);
int deleteFront(DQNodeType* dq);
void insertRear(DQNodeType* dq, int _iNum);
int deleteRear(DQNodeType* dq);
int peek(DQNodeType* dq);
void printQueue(DQNodeType* dq);

int main() {
	DQNodeType* dq = CreateDQue();

	insertFront(dq, 1);
	insertFront(dq, 2);
	insertRear(dq, 3);
	printQueue(dq);

	int iNum(0);
	iNum = deleteFront(dq);
	cout << "front delete-> " << iNum << endl;
	printQueue(dq);

	iNum = deleteRear(dq);
	cout << "rear delete -> " << iNum << endl;
	printQueue(dq);

	insertRear(dq, 4);
	printQueue(dq);
	insertFront(dq, 5);
	printQueue(dq);
	insertFront(dq, 6);
	printQueue(dq);

	iNum = peek(dq);
	cout << "peek -> " << iNum << endl << endl;

	
}

DQNodeType* CreateDQue() {
	DQNodeType* dqType = new DQNodeType;
	dqType->front = nullptr;
	dqType->rear = nullptr;
	return dqType;
}

bool isEmpty(DQNodeType* dq) {
	if (dq->front == nullptr) return true;
	else return false;
}

void insertFront(DQNodeType* dq, int _iNum) {
	DQNode* dqNode = new DQNode;
	dqNode->data = _iNum;
	if (dq->front == nullptr) {
		dq->rear = dqNode;
		dq->front = dqNode;

		dqNode->llink = nullptr;
		dqNode->rlink = nullptr;
	}
	else {
		dq->front->llink = dqNode;
		dqNode->llink = nullptr;
		dqNode->rlink = dq->front;
		dq->front = dqNode;
	}
}

int deleteFront(DQNodeType* dq) {
	DQNode* old = dq->front;
	int iNum(0);

	if (isEmpty(dq)) return false;
	else {
		iNum = old->data;
		if (dq->front->rlink == nullptr) {
			dq->front = nullptr;
			dq->rear = nullptr;
		}
		else {
			dq->front = dq->front->rlink;
			dq->front->llink = nullptr; // 맨 앞으로 나왔기 때문에 null처리
		}
		delete old;
		old = nullptr;

		return iNum;
	}
}

void insertRear(DQNodeType* dq, int _iNum) {
	DQNode* dqNode = new DQNode;
	dqNode->data = _iNum;

	if (dq->rear == nullptr) {
		dq->front = dqNode;
		dq->rear = dqNode;

		dqNode->llink = nullptr;
		dqNode->rlink = nullptr;
	}
	else {
		dq->rear->rlink = dqNode;
		dqNode->llink = dq->rear;
		dqNode->rlink = nullptr;
		dq->rear = dqNode;
	}
}

int deleteRear(DQNodeType* dq) {
	DQNode* old = dq->rear;
	int iNum(0);

	if (isEmpty(dq)) return false;
	else {
		iNum = old->data;
		if (dq->rear->llink == nullptr) {
			dq->front = nullptr;
			dq->rear = nullptr;
		}
		else {
			dq->rear = dq->rear->llink;
			dq->rear->rlink = nullptr;
		}
	}


	delete old;
	old = nullptr;

	return iNum;
}

int peek(DQNodeType* dq) {
	if (isEmpty(dq)) return false;
	else {
		return dq->front->data;
	}
}

void printQueue(DQNodeType* dq) {
	DQNode* pTemp = dq->front;
	cout << "DEQUE" << endl;
	
	while (pTemp) {
		cout << pTemp->data << " ";
		pTemp = pTemp->rlink;
	}
	cout << endl << endl;
}