// depthfirst.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


struct Node {
public:
	int data;
	struct Node* leftchild;
	struct Node* rightchild;

};


Node* CreateNode(int data) {
	Node* node = new Node();
	node->data = data;
	node->leftchild = NULL;
	node->rightchild = NULL;
	return node;
}

void VisitNode(Node* node) {
	cout << "visited:";
	cout << node->data << endl;
	return;
}

class Stack {
public:
	Node* stack[10];
	int n = 10;
	int top = -1;

	void push(Node* node) {
		if (top >= n - 1)
			cout << "Stack Overflow" << endl;
		else {
			top++;
			stack[top] = node;
		}
	}
	Node* pop() {
		if (top <= -1)
			cout << "Stack Underflow" << endl;
		else {
			cout << "The popped element is " << stack[top]->data << endl;
			Node* popednode = stack[top];
			top--;
			return popednode;
		}
	}
	void display() {
		if (top >= 0) {
			cout << "Stack elements are:";
			for (int i = top; i >= 0; i--)
				cout << stack[i]->data << " ";
			cout << endl;
			return;
		}
		else {
			cout << "Stack is empty" << endl;
			return;
		}

	}
	bool isempty() {
		if (top == -1)
		{
			cout << "empty" << endl;
			return true;
		}

		return false;
	}


};

int DeapthFirstSearch(Node* root) {

	Stack* stack = new Stack();
	Node* activenode = root;
	stack->push(root);

	while (!stack->isempty()) {
		stack->display();
		Node* activenode = stack->pop();
		VisitNode(activenode);
		if (activenode->rightchild != NULL)
		{
			stack->push(activenode->rightchild);
		}
		if (activenode->leftchild != NULL)
		{
			stack->push(activenode->leftchild);
		}
	}
	return 0;
}

int main()
{
	Node* root = CreateNode(1);
	root->leftchild = CreateNode(2);
	root->leftchild->leftchild = CreateNode(4);
	root->rightchild = CreateNode(3);
	root->rightchild->leftchild = CreateNode(5);
	DeapthFirstSearch(root);
	return 0;
}







