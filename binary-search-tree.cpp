#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

class BST {
	private:
	Node *root;
	public:
	int height = 0;
	void insert(int value);
	void printDFS(Node *node);
	void printBFS(Node *node, int height);
	void print(string type);
	void deleteRecursively(Node *node);
	~BST();
};
void BST::insert(int value) {
	int currentHeight=1;
	if(root==NULL) {
		root = new Node;
		root->data = value;
		root->left = root->right = NULL;
	} else {
		struct Node *temp = root;
		
		Node *newNode = new Node;
		newNode->data = value;
		newNode->left = newNode->right = NULL;
		
		while(temp) {
			currentHeight++;
			if(value < temp->data) {
				if(!temp->left) {
					temp->left = newNode;
					break;
				} else temp = temp->left;
			} else {
				if(!temp->right) {
					temp->right = newNode;
					break;
				} else temp = temp->right;
			}
		}
	}
	height = max(height, currentHeight);
}
void BST::printDFS(Node *node) {
	if(node) {
		cout << node->data << "  ";
		printDFS(node->left);
		printDFS(node->right);
	}
}
void BST::printBFS(Node *node, int level) {
	if(node) {
		if(level==0)
			cout << node->data << "  ";
		else {
			printBFS(node->left, level-1);
			printBFS(node->right, level-1);
		}
	}
}
void BST::print(string type="BFS") {
	if(type == "DFS") {
		cout << "DFS: ";
		printDFS(root);
		cout << "\n";
	} else {
		cout << "BFS:";
		for(int i=0; i<height; i++) {
			cout << "\tLevel" << i << ": ";
			printBFS(root, i);
			cout << "\n";
		}
	}
}
void BST::deleteRecursively(Node *node) {
	if(node) {
		deleteRecursively(node->left);
		deleteRecursively(node->right);
		delete node;
	}
}
BST::~BST() {
	deleteRecursively(root);
}

int main() {
	BST tree = BST();
	
	int n, value;
	cout << "Count: ";
	cin >> n;
	
	cout << "Values(space-separated): ";
	while(n--) {
		cin >> value;
		tree.insert(value);
	}
	
	cout << "Height: " << tree.height << "\n";
	
	tree.print("BFS");
	tree.print("DFS");
	
	return 0;
}
