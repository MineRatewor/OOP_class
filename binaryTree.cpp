#include<iostream>
#include<iomanip>
using namespace std;

template<typename T>
class Tree {
private:
	template<typename T>
	class Node {
	public:
		T data;
		Node* right;
		Node* left;

		Node(T d, Node*right = NULL, Node*left = NULL) {
			this->data = d;
			this->left = NULL;
			this->right = NULL;
		}
	};
	Node<T>* root;
	void deleteTree(Node<T>* node) {
		if (node == NULL) {
			return;
		}
		deleteTree(node->right);
		deleteTree(node->left);
		delete node;
	}
	Node<T>* copyTree(Node<T>* node) {
		if (node == nullptr) return nullptr;
		Node<T>* newNode = new Node<T>(node->data);
		newNode->left = copyTree(node->left);
		newNode->right = copyTree(node->right);
		return newNode;
	}

public:
	Tree();
	Tree(T d);
	Tree(Tree& other);
	Tree& operator=(Tree& other){
		this->root = copyTree(other.root);
		return *this;
	}
	Tree& operator=(Tree&& other) {
		this->root = copyTree(other.root);
		other.deleteTree();
		return *this;
	}
	Tree(Tree&& other);
	void insert(T d);
	void insertNode(T d, Node<T>* node);
	void print();
	void PrintTree(Node<T>*, int);
	void remove(T value);
	bool search(T value);
	bool searchNode(Node<T>* node, T value);
	Node<T>* findMinNode(Node<T>* node) {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}
	Node<T>* removeNode(Node<T>* node, T value) {
		if (node == NULL) return NULL;
		if (value < node->data) {
			node->left = removeNode(node->left, value);
		}
		else if (value > node->data) {
			node->right = removeNode(node->right, value);
		}
		else {
			if (node->left == NULL and node->right == NULL) {
				delete node;
				return NULL;
			}
			else if (node->left == NULL) {
				Node<T>* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == NULL) {
				Node<T>* temp = node->left;
				delete node;
				return temp;
			}
			else {
				Node<T>* minNode = findMinNode(node->right);
				node->data = minNode->data;
				node->right = removeNode(node->right, minNode->data);
			}
		}
		return node;
	}
	
	void deleteTree();
	~Tree();
};

template<typename T>
Tree<T>::Tree()
{
	root = new Node<T>(NULL);
}

template<typename T>
Tree<T>::Tree(T d)
{
	root = new Node<T>(d);
}

template<typename T>
Tree<T>::Tree(Tree& other)
{
	this->root = copyTree(other.root);
}



template<typename T>
Tree<T>::Tree(Tree&& other)
{
	this->root = copyTree(other.root);
	other.deleteTree();
}

template<typename T>
void Tree<T>::insert(T d)
{
	if (root->data == NULL) {
		root = new Node<T>(d);
		return;
	}
	else {
		insertNode(d, root);
	}
}

template<typename T>
void Tree<T>::insertNode(T d, Node<T>* node)
{
	if (d < node->data) {
		if (node->left == NULL) {
			node->left = new Node<T>(d);
		}
		else {
			insertNode(d, node->left);
		}
	}
	else {
		if (node->right == NULL) {
			node->right = new Node<T>(d);
		}
		else {
			insertNode(d, node->right);
		}
	}
}

template<typename T>
void Tree<T>::print()
{
	if (root->data == NULL) {
		cout << "Tree is empty!" << endl;
		return;
	}
	else {
		PrintTree(root, 0);
	}
	
}

template<typename T>
void Tree<T>::PrintTree(Node<T>* tree, int level)
{
	if (tree) {
		PrintTree(tree->right, level + 1);
		for (int i = 0; i < level; i++) cout << "      ";
		cout << tree->data << endl;
		
		PrintTree(tree->left, level + 1);
	}
}

template<typename T>
void Tree<T>::remove(T value)
{
	root = removeNode(root, value);
}
template<typename T>
bool Tree<T>::search(T value)
{
	return searchNode(root, value);
}
template<typename T>
bool Tree<T>::searchNode(Node<T>* node, T value)
{
	if (node == NULL) return false;
	if (node->data == value) return true;
	if (value < node->data) return searchNode(node->left, value);
	return searchNode(node->right, value);
}
template<typename T>
void Tree<T>::deleteTree()
{
	deleteTree(root);
	root = new Node<T>(NULL);
}
template<typename T>
Tree<T>::~Tree()
{
	deleteTree(root);
}

int main() {
	Tree<int> l;
	l.insert(5);
	l.insert(4);
	l.insert(7);
	l.insert(6);
	l.insert(10);
	l.insert(1);
	l.insert(4);
	l.insert(8);
	Tree<int> l2(move(l));
	l.print();

}