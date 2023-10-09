#include <iostream>
#define QUEUE_SIZE 4

using namespace std;

typedef struct tQueue {
	char queue[QUEUE_SIZE];
	int front, rear;
} QUEUE;

/*
1. 공백 순차 큐 생성
2. 순차 큐 공백 상태 검사
3. 순차 큐 포화 상태 검사
4. 순차 큐의 원소 삽입
5. 순차 큐의 원소 삭제
6. 순차 큐의 원소 검색
*/

QUEUE* CreateQueue();
bool isEmpty(QUEUE* q);
bool isFull(QUEUE* q);
void enQueue(QUEUE* q, char _cTemp);
char deQueue(QUEUE* q);
char peek(QUEUE* q);
void printQueue(QUEUE* q);

int main() {
	char iNum;
	QUEUE* pq = CreateQueue();
	enQueue(pq, 'A');
	enQueue(pq, 'B');
	enQueue(pq, 'C');
	printQueue(pq);

	iNum = peek(pq);
	cout << "peek-> " << iNum << endl << endl;

	for (int i = 0; i < 3; ++i) {
		iNum = deQueue(pq);
		cout << "delete -> " << iNum << endl;
		printQueue(pq);
	}
	
}

QUEUE* CreateQueue() {
	QUEUE* q = new QUEUE;
	q->front = -1;
	q->rear = -1;
	return q;
}

bool isEmpty(QUEUE* q) {
	if (q->front == q->rear) return true;
	else return false;
}

bool isFull(QUEUE* q) {
	if (q->rear == QUEUE_SIZE) return true;
	else return false;
}

void enQueue(QUEUE* q, char _cTemp) {
	if (isFull(q)) return;
	else
		q->rear++;
		q->queue[q->rear] = _cTemp;
}

char deQueue(QUEUE* q) {
	if (isEmpty(q)) cout << "값 없음" << endl;
	else {
		q->front++;
		return q->queue[q->front];
	}
}

char peek(QUEUE* q) {
	if (isEmpty(q)) cout << "빈값" << endl;
	else return q->queue[q->front+1];
}

void printQueue(QUEUE* q) {
	cout << "[[QUEUE]]" << endl;
	for (int i = q->front + 1; i < q->rear + 1; ++i) {
		cout << q->queue[i];
	}
	cout << endl << endl;
}