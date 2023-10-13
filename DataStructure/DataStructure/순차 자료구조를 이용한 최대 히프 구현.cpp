#include <iostream>
#define MAX_ELEMENT 100

using namespace std;

typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
} heapType;

heapType* createHeap();
void insertHeap(heapType* h, int item);
int deleteHeap(heapType* h);
void printHeap(heapType* h);

int main() {
	int i, n, item;
	heapType* heap = createHeap();
	insertHeap(heap, 10);
	insertHeap(heap, 45);
	insertHeap(heap, 19);
	insertHeap(heap, 11);
	insertHeap(heap, 96);

	printHeap(heap);
	cout << endl;

	n = heap->heap_size;

	for (i = 1; i <= n; i++) {
		item = deleteHeap(heap);
		cout << "delete : " << item << endl;
	}
}

//���� �� �����ϴ� ����
heapType* createHeap() {
	heapType* h = new heapType;
	h->heap_size = 0;
	return h;
}

//���� item�� �����ϴ� ����
void insertHeap(heapType* h, int item) {
	int i;
	h->heap_size = h->heap_size + 1;
	i = h->heap_size;

	while ((i != 1) && (item > h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}

	h->heap[i] = item;
}

//�� ��Ʈ�� �����Ͽ� ��ȯ�ϴ� ����
int deleteHeap(heapType* h) {
	int parent, child;
	int item, temp;
	item = h->heap[1];
	temp = h->heap[h->heap_size];
	h->heap_size -= 1;
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child]) < h->heap[child + 1]) child++;
		if (temp >= h->heap[child]) break;
		else {
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;
		}
	}
	h->heap[parent] = temp;
	return item;
}

void printHeap(heapType* h) {
	int i;
	cout << "Heap : ";
	for (i = 1; i <= h->heap_size; ++i) {
		cout << h->heap[i] << " ";
	}
}