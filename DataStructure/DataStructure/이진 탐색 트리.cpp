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
			cout << "���� Ʈ�� ��� " << endl;
			displayInorder(root);
			cout << endl;
			break;
		case 2:
			cout << "������ ���ڸ� �Է��ϼ���" << endl;
			cin >> key;
			insertNode(root, key);
			break;
		case 3:
			cout << "������ ���ڸ� �Է��ϼ���" << endl;
			cin >> key;
			deleteNode(root, key);
			break;
		case 4:
			cout << "ã�� ���ڸ� �Է��ϼ���" << endl;
			cin >> key;
			foundNode = searchBST(root, key);
			if (foundNode != nullptr)
				cout << foundNode << "�� ã�ҽ��ϴ� ! " << endl;
			else cout << "���ڸ� ã�� ���߽��ϴ�" << endl;
			break;
		case 5:
			return 0;
		default:
			cout << "���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���." << endl;
			break;
		}
	}

}

//���� Ž�� Ʈ������ Ű ���� x�� ����� ��ġ�� Ž���ϴ� ����
treeNode* searchBST(treeNode* root, char x)
{
	treeNode* p;
	p = root;
	while (p != nullptr) {
		if (x < p->key) p = p->left;
		else if (x > p->key) p = p->right;
		else return p;
	}
	cout << "ã�� Ű�� �����ϴ� ! " << endl;
	return p;
}

// ������ p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� ����
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
	else cout << endl << "�̹� ���� Ű�� �ֽ��ϴ� !! " << endl;

	return p;
}

//��Ʈ ������ Ž���Ͽ� Ű���� ���� ��带 ã�� �����ϴ� ����
void deleteNode(treeNode* root, char key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;

	parent = nullptr;
	p = root;

	while ((p != nullptr) && (p->key != key)) { // ������ ��� ��ġ Ž��
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	//������ ��尡 ���� ���
	if (p == nullptr) {
		cout << endl << "ã�� Ű�� ���� Ʈ���� �����ϴ� !! " << endl;
		return;
	}

	//������ ��尡 �ܸ� ����� ���
	if ((p->left == nullptr) && (p->right == nullptr)) {
		if (parent != nullptr) {
			if (parent->left == p) child = p->left;
			else parent->right = nullptr;
		}
		else root = nullptr;
	}

	//������ ��尡 �ڽ� ��带 �� �� ���� ���
	else if ((p->left == nullptr) || (p->right == nullptr)) {
		if (p->left != nullptr) child = p->left;
		else child = p->right;

		if (parent != nullptr) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	//������ ��尡 �ڽ� ��带 �� �� ���� ���
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
	cout << "1. Ʈ�� ��� " << endl;
	cout << "2. ���� ����" << endl;
	cout << "3. ���� ����" << endl;
	cout << "4. ���� �˻�" << endl;
	cout << "5. ����" << endl;
	cout << "================================" << endl;
	cout << "�Ŵ� �Է� : ";
}

