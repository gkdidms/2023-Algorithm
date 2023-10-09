#include <iostream>

using namespace std;

typedef struct tQInfo {
	int data;
	tQInfo* link;
} QNode;

typedef struct {
	QNode*front, *rear;
} LQueneType;


LQueneType* CreateLinkedQueue();
bool isEmpty(LQueneType* lq);
void enQueue(LQueneType* lq, int _iNum);
int deQueue(LQueneType* lq);
int peek(LQueneType* lq);
void printQueue(LQueneType* lq);

int main() {
	LQueneType* lq = CreateLinkedQueue();

	enQueue(lq, 1);
	enQueue(lq, 2);
	enQueue(lq, 3);

	printQueue(lq);

	int iNum(0);
	iNum = peek(lq);
	cout << "peek -> " << iNum << endl << endl;

	for (int i = 0; i < 3; ++i) {
		iNum = deQueue(lq);
		cout << "delete -> " << iNum << endl;
		printQueue(lq);
	}
}

LQueneType* CreateLinkedQueue() {
	LQueneType* LQ = new LQueneType;
	LQ->front = nullptr;
	LQ->rear = nullptr;
	return LQ;
}

bool isEmpty(LQueneType* lq) {
	if (lq->front == nullptr) return true;
	else return false;
}

void enQueue(LQueneType* lq, int _iNum) {
	QNode* pq = new QNode;
	pq->data = _iNum;
	pq->link = nullptr;

	if (lq->front == nullptr) {
		lq->rear = pq;
		lq->front = pq;
	}
	else {
		lq->rear->link = pq;
		lq->rear = pq;
	}
}

int deQueue(LQueneType* lq) {
	if (isEmpty(lq)) return false;
	else {
		int iNum = lq->front->data;
		lq->front = lq->front->link;
		if (isEmpty(lq)) lq->rear = NULL;
		return iNum;
	}
}

int peek(LQueneType* lq) {
	if (isEmpty(lq)) return false;
	else return lq->front->data;
}

void printQueue(LQueneType* lq) {
	QNode* pTemp = lq->front;
	cout << "[[QUEUE]]" << endl;
	
	while (pTemp) {
		cout << pTemp->data << " ";
		pTemp = pTemp->link;
	}

	cout << endl << endl;
}
