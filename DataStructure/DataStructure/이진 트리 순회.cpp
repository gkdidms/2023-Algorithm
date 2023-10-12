#include <iostream>

using namespace std;

typedef struct treeNode {
	char data;
	treeNode* left;
	treeNode* right;
} treeNode;

treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode);
void preorder(treeNode* root);
void inorder(treeNode* root);
void postorder(treeNode* root);


int main()
{
	//수식 (A*B-c/d)를 이진 트리로 만들기
	treeNode* n7 = makeRootNode('D', nullptr, nullptr);
	treeNode* n6 = makeRootNode('C', nullptr, nullptr);
	treeNode* n5 = makeRootNode('B', nullptr, nullptr);
	treeNode* n4 = makeRootNode('A', nullptr, nullptr);
	treeNode* n3 = makeRootNode('/', n6, n7);
	treeNode* n2 = makeRootNode('*', n4, n5);
	treeNode* n1 = makeRootNode('-', n2, n3);

	cout << "preorder : ";
	preorder(n1);

	cout << "\ninorder : ";
	inorder(n1);

	cout << "\npostorder : ";
	postorder(n1);
}

//data를 루트 노드로 하여 왼쪽 서브 트리와 오른쪽 서브 트리를 연결하는 연산
treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode) {
	treeNode * root = new treeNode;
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

//이진 트리에 대한 전위 순회 연산
void preorder(treeNode* root) {
	if (root) {
		cout << root->data;
		preorder(root->left);
		preorder(root->right);
	}
}

//이진 트리에 대한 중위 순회 연산
void inorder(treeNode* root) {
	if (root) {
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}
}

//이진 트리에 대한 후위 순회 연산
void postorder(treeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		cout << root->data;
	}
}



