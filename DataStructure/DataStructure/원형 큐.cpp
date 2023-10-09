#include <iostream>
#define Q_SIZE 5

using namespace std;

typedef struct tQueueInfo {
	int queue[Q_SIZE];
	int front, rear;
} QueueNode;

QueueNode* CreateQueue();
bool isEmpty(QueueNode* q);
bool isFull(QueueNode* q);
void enQueue(QueueNode* q, int _iNum);
int deQueue(QueueNode* q);
int peek(QueueNode* q);
void printQueue(QueueNode* q);


int main() {
	int iNum(0);
	QueueNode* pq = CreateQueue();
	
	enQueue(pq, 1);
	enQueue(pq, 2);
	enQueue(pq, 3);

	printQueue(pq);

	iNum = peek(pq);
	cout << "peek -> " << iNum << endl;

	for (int i = 0; i < 3; ++i) {
		iNum = deQueue(pq);
		cout << "delete -> " << iNum << endl;
		printQueue(pq);
	}
}

QueueNode* CreateQueue() {
	QueueNode* q = new QueueNode;
	q->front = 0;
	q->rear = 0;
	return q;
}

bool isEmpty(QueueNode* q) {
	if (q->rear == q->front) return true;
	else return false;
}

bool isFull(QueueNode* q) {
	if ((q->rear + 1) % Q_SIZE == q->front) return true;
	else return false;
}

void enQueue(QueueNode* q, int _iNum) {
	if (isFull(q)) return;
	else {
		q->rear = (q->rear + 1) % Q_SIZE;
		q->queue[q->rear] = _iNum;
	}
}

int deQueue(QueueNode* q) {
	if (isEmpty(q)) return -1;
	else {
		q->front = (q->front + 1) % Q_SIZE;
		return q->queue[q->front];
	}
}

int peek(QueueNode* q) {
	if (isEmpty(q)) return -1;
	else {
		return q->queue[(q->front + 1) % Q_SIZE];
	}
}

void printQueue(QueueNode* q) {
	cout << "[[QUEUE]]" << endl;

	for (int i = (q->front + 1) % Q_SIZE; i < (q->rear + 1) % Q_SIZE; ++i) {
		cout << q->queue[i] << " ";
	}
	cout << endl << endl;
}