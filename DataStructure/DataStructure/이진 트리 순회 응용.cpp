#include <iostream>

using namespace std;

typedef struct treeNode {
	int data;
	treeNode* left;
	treeNode* right;
} treeNode;

treeNode* makeRootNode(int size, treeNode* left, treeNode* right);
int postorder_FolderSize(treeNode* root);

int iFolderSize(0);

int main()
{
	treeNode* n11 = makeRootNode(120, nullptr, nullptr);
	treeNode* n10 = makeRootNode(55, nullptr, nullptr);
	treeNode* n9 = makeRootNode(100, nullptr, nullptr);
	treeNode* n8 = makeRootNode(200, nullptr, nullptr);
	treeNode* n7 = makeRootNode(68, n10, n11);
	treeNode* n6 = makeRootNode(40, nullptr, nullptr);
	treeNode* n5 = makeRootNode(15, nullptr, nullptr);
	treeNode* n4 = makeRootNode(2, n8, n9);
	treeNode* n3 = makeRootNode(10, n6, n7);
	treeNode* n2 = makeRootNode(0, n4, n5);
	treeNode* n1 = makeRootNode(0, n2, n3);

	cout << "c:\\의 용량 : " << postorder_FolderSize(n2) << endl;
	
	iFolderSize = 0;
	cout << "D:\\의 용량 : " << postorder_FolderSize(n3) << endl;

	iFolderSize = 0;
	cout << "내 컴퓨터 전체 용량 : " << postorder_FolderSize(n1) << endl;
}

treeNode* makeRootNode(int size, treeNode* left, treeNode* right) {
	treeNode* root = new treeNode;
	root->data = size;
	root->left = left;
	root->right = right;
	return root;
}


int postorder_FolderSize(treeNode* root) {
	if (root) {
		postorder_FolderSize(root->left);
		postorder_FolderSize(root->right);
		iFolderSize += root->data;
	}
	return iFolderSize;
}