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
	//���� (A*B-c/d)�� ���� Ʈ���� �����
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

//data�� ��Ʈ ���� �Ͽ� ���� ���� Ʈ���� ������ ���� Ʈ���� �����ϴ� ����
treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode) {
	treeNode * root = new treeNode;
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

//���� Ʈ���� ���� ���� ��ȸ ����
void preorder(treeNode* root) {
	if (root) {
		cout << root->data;
		preorder(root->left);
		preorder(root->right);
	}
}

//���� Ʈ���� ���� ���� ��ȸ ����
void inorder(treeNode* root) {
	if (root) {
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}
}

//���� Ʈ���� ���� ���� ��ȸ ����
void postorder(treeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		cout << root->data;
	}
}



