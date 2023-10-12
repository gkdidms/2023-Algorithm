#include <iostream>

using namespace std;

struct treeNode {
	char key;
	treeNode* left;
	treeNode* right;
};

treeNode* searchBST(treeNode* root, char x);
treeNode* insertNode(treeNode* p, char x);
void deleteNode(treeNode* root, char key);
void displayInorder(treeNode* root);
void menu();

int main()
{
	treeNode* root = nullptr;
	treeNode* foundNode = nullptr;
	char choice, key;

	root = insertNode(root, 'G');
	insertNode(root, 'I');
	insertNode(root, 'H');
	insertNode(root, 'D');
	insertNode(root, 'B');
	insertNode(root, 'M');
	insertNode(root, 'N');
	insertNode(root, 'A');
	insertNode(root, 'J');
	insertNode(root, 'E');
	insertNode(root, 'Q');

	while (true) {
		menu();
		cin >> choice;

		switch (choice - '0') {
		case 1:
			cout << "이진 트리 출력 " << endl;
			displayInorder(root);
			cout << endl;
			break;
		case 2:
			cout << "삽입할 문자를 입력하세요" << endl;
			cin >> key;
			insertNode(root, key);
			break;
		case 3:
			cout << "삭제할 문자를 입력하세요" << endl;
			cin >> key;
			deleteNode(root, key);
			break;
		case 4:
			cout << "찾을 문자를 입력하세요" << endl;
			cin >> key;
			foundNode = searchBST(root, key);
			if (foundNode != nullptr)
				cout << foundNode << "를 찾았습니다 ! " << endl;
			else cout << "문자를 찾지 못했습니다" << endl;
			break;
		case 5:
			return 0;
		default:
			cout << "없는 메뉴입니다. 메뉴를 다시 선택하세요." << endl;
			break;
		}
	}

}

//이진 탐색 트리에서 키 값이 x인 노드의 위치를 탐색하는 연산
treeNode* searchBST(treeNode* root, char x)
{
	treeNode* p;
	p = root;
	while (p != nullptr) {
		if (x < p->key) p = p->left;
		else if (x > p->key) p = p->right;
		else return p;
	}
	cout << "찾는 키가 없습니다 ! " << endl;
	return p;
}

// 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
treeNode* insertNode(treeNode* p, char x) {
	treeNode* newNode;

	if (p == nullptr) {
		newNode = new treeNode;
		newNode->key = x;
		newNode->right = nullptr;
		newNode->left = nullptr;
		return newNode;
	}

	else if (x < p->key) p->left = insertNode(p->left, x);
	else if (x > p->key) p->right = insertNode(p->right, x);
	else cout << endl << "이미 같은 키가 있습니다 !! " << endl;

	return p;
}

//루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
void deleteNode(treeNode* root, char key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;

	parent = nullptr;
	p = root;

	while ((p != nullptr) && (p->key != key)) { // 삭제할 노드 위치 탐색
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	//삭제할 노드가 없는 경우
	if (p == nullptr) {
		cout << endl << "찾는 키가 이진 트리에 없습니다 !! " << endl;
		return;
	}

	//삭제할 노드가 단말 노드인 경우
	if ((p->left == nullptr) && (p->right == nullptr)) {
		if (parent != nullptr) {
			if (parent->left == p) child = p->left;
			else parent->right = nullptr;
		}
		else root = nullptr;
	}

	//삭제할 노드가 자식 노드를 한 개 가진 경우
	else if ((p->left == nullptr) || (p->right == nullptr)) {
		if (p->left != nullptr) child = p->left;
		else child = p->right;

		if (parent != nullptr) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	//삭제할 노드가 자식 노드를 두 개 가진 경우
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != nullptr) {
			succ_parent = succ;
			succ = succ->right;
		}

		if (succ_parent->left == succ) succ_parent->left = succ->left;
		else succ_parent->right = succ->left;
		p->key = succ->key;
		p = succ;
	}

	delete p;
}

void displayInorder(treeNode* root) {
	if (root) {
		displayInorder(root->left);
		cout << root->key;
		displayInorder(root->right);
	}
}

void menu() {
	cout << endl << "===========================" << endl;
	cout << "1. 트리 출력 " << endl;
	cout << "2. 문자 삽입" << endl;
	cout << "3. 문자 삭제" << endl;
	cout << "4. 문자 검색" << endl;
	cout << "5. 종료" << endl;
	cout << "================================" << endl;
	cout << "매뉴 입력 : ";
}

