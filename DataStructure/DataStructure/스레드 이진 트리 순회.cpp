#include <iostream>

using namespace std;

struct treeNode {
	char data;
	treeNode* left;
	treeNode* right;
	int isThreadRight;
};

treeNode* makeRootNode(char data, treeNode* left, treeNode* right, int isThreadRight);
treeNode* findThreadSuccessor(treeNode* p);
void threadInorder(treeNode* root);

int main()
{
	treeNode* n7 = makeRootNode('D', nullptr, nullptr, false);
	treeNode* n6 = makeRootNode('C', nullptr, nullptr, true);
	treeNode* n5 = makeRootNode('B', nullptr, nullptr, true);
	treeNode* n4 = makeRootNode('A', nullptr, nullptr, true);
	treeNode* n3 = makeRootNode('/', n6, n7, false);
	treeNode* n2 = makeRootNode('*', n4, n5, false);
	treeNode* n1 = makeRootNode('-', n2, n3, false);

	n4->right = n2;
	n5->right = n1;
	n6->right = n3;

	cout << "스레드 이진 트리의 중위 순회 : ";
	threadInorder(n1);
}

treeNode* makeRootNode(char data, treeNode* left, treeNode* right, int isThreadRight) {
	treeNode* root = new treeNode;

	root->data = data;
	root->left = left;
	root->right = right;
	root->isThreadRight = isThreadRight;

	return root;
}

//후속자 노드를 반환하는 연산
treeNode* findThreadSuccessor(treeNode* p) {
	treeNode* q = p->right;
	if (q == nullptr) return q;
	if (p->isThreadRight == true) return q;
	while (q->left != nullptr) q = q->left;
	return q;
}

void threadInorder(treeNode* root) {
	treeNode* q;
	q = root;
	while (q->left) q = q->left;
	do {
		cout << q->data;
		q = findThreadSuccessor(q);
	} while (q);
}