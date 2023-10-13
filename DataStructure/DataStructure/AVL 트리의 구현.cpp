#include <iostream>

using namespace std;

struct treeNode {
	int key;
	treeNode* left;
	treeNode* right;
};

treeNode* LL_rotate(treeNode* parent);
treeNode* RR_rotate(treeNode* parent);
treeNode* LR_rotate(treeNode* parent);
treeNode* RL_rotate(treeNode* parent);
int getHeight(treeNode* p);
int getBF(treeNode* p);
treeNode* rebalance(treeNode** p);
treeNode* insert_AVL_Node(treeNode** root, int x);
treeNode* insert_BST_Node(treeNode* p, int x);
treeNode* searchTree(treeNode* root, int x);
void displayInorder(treeNode* root);


int main()
{
	treeNode* root_AVL = nullptr;
	treeNode* root_BST = nullptr;

	root_AVL = insert_AVL_Node(&root_AVL, 50);
	insert_AVL_Node(&root_AVL, 60);
	insert_AVL_Node(&root_AVL, 70);
	insert_AVL_Node(&root_AVL, 90);
	insert_AVL_Node(&root_AVL, 80);
	insert_AVL_Node(&root_AVL, 75);
	insert_AVL_Node(&root_AVL, 73);
	insert_AVL_Node(&root_AVL, 72);
	insert_AVL_Node(&root_AVL, 78);

	cout << "============AVL 트리 출력===============" << endl;
	displayInorder(root_AVL);

	cout << "============AVL 트리에서 80 탐색 : ";
	searchTree(root_AVL, 80);

	cout << "============AVL 트리에서 90 탐색 : ";
	searchTree(root_AVL, 90);

	cout << "============AVL 트리에서 76 탐색 : ";
	searchTree(root_AVL, 76);

	root_BST = insert_AVL_Node(&root_BST, 50);
	insert_BST_Node(root_BST, 90);
	insert_BST_Node(root_BST, 60);
	insert_BST_Node(root_BST, 70);
	insert_BST_Node(root_BST, 80);
	insert_BST_Node(root_BST, 75);
	insert_BST_Node(root_BST, 73);
	insert_BST_Node(root_BST, 72);
	insert_BST_Node(root_BST, 78);

	cout << "============BST 트리 출력===============" << endl;
	displayInorder(root_BST);

	cout << "============BST 트리에서 80 탐색 : ";
	searchTree(root_BST, 80);

	cout << "============BST 트리에서 90 탐색 : ";
	searchTree(root_BST, 90);

	cout << "============BST 트리에서 76 탐색 : ";
	searchTree(root_BST, 76);


}

treeNode* LL_rotate(treeNode* parent) {
	treeNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}

treeNode* RR_rotate(treeNode* parent) {
	treeNode* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

treeNode* LR_rotate(treeNode* parent) {
	treeNode* child = parent->left;
	parent->left = RR_rotate(child);
	return LL_rotate(parent);
}

treeNode* RL_rotate(treeNode* parent) {
	treeNode* child = parent->right;
	parent->right = LL_rotate(child);
	return RR_rotate(parent);
}

//서브 트리 높이 구하기
int getHeight(treeNode* p) {
	int height = 0;
	if (p != nullptr) height = max(getHeight(p->left), getHeight(p->right)) + 1;
	return height;
}

//서브 트리의 높이를 이용해 균형 인수 BF를 구하는 연산
int getBF(treeNode* p) {
	if (p == nullptr) return 0;
	return getHeight(p->left) - getHeight(p->right);
}

//BF를 검사하여 불균형이 발생한 경우, 회전 연산 호출 
treeNode* rebalance(treeNode** p) {
	int BF = getBF(*p);

	if (BF > 1) {
		if (getBF((*p)->left) > 0)
			*p = LL_rotate(*p);
		else *p = LR_rotate(*p);
	}
	else if (BF < -1) {
		if (getBF((*p)->right) < 0)
			*p = RR_rotate(*p);
		else *p = RL_rotate(*p);
	}

	return *p;
}

//AVL 트리에 노드를 삽입하는 연산 : 이진 탐색 연산처럼 삽입한 후에, rebalance() 호출
treeNode* insert_AVL_Node(treeNode** root, int x) {
	if (*root == nullptr) {
		*root = new treeNode;
		(*root)->key = x;
		(*root)->left = nullptr;
		(*root)->right = nullptr;
	}
	else if (x < (*root)->key) {
		(*root)->left = insert_AVL_Node(&((*root)->left), x);
		*root = rebalance(root);
	}
	else if (x > (*root)->key) {
		(*root)->right = insert_AVL_Node(&((*root)->right), x);
		*root = rebalance(root);
	}
	else {
		cout << "이미 같은 키 값이 있습니다 !! " << endl;
		exit(true);
	}
	return *root;
}

//이진 탐색 크리에 노드를 삽입하는 연산
treeNode* insert_BST_Node(treeNode* p, int x) {
	treeNode* newNode;
	if (p == nullptr) {
		newNode = new treeNode;
		newNode->key = x;
		newNode->left = nullptr;
		newNode->right = nullptr;
		return newNode;
	}
	else if (x < p->key) p->left = insert_BST_Node(p->left, x);
	else if (x > p->key) p->right = insert_BST_Node(p->right, x);
	else cout << "이미 같은 키가 있습니다 !! " << endl;

	return p;
}


//이진 탐색 트리와 AVL 트리에서 키 값 x를 탐색하는 연산
treeNode* searchTree(treeNode* root, int x) {
	treeNode* p;
	int count = 0;
	p = root;

	while (p != nullptr) {
		count++;
		if (x < p->key) p = p->left;
		else if (x == p->key) {
			cout << count << "번째에 탐색 성공" << endl;
			return p;
		}
		else p = p->right;
	}
	count++;
	cout << count << "번째에 탐색 실패! 찾는 키가 없습니다." << endl;
	return p;
}

//이진 트리를 중위 순회하면서 출력하는 연산
void displayInorder(treeNode* root) {
	if (root) {
		displayInorder(root->left);
		cout << root->key << endl;
		displayInorder(root->right);
	}
}

