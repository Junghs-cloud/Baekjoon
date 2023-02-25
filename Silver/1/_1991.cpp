#include <iostream>
#include <queue>
using namespace std;

struct node
{
	char data;
	node* leftNode;
	node* rightNode;
};
queue<node*> nodeQueue;
node* findNode(node* nod, char data)
{
	nodeQueue.push(nod);
	while (!nodeQueue.empty())
	{
		node* queueFront = nodeQueue.front();
		if (queueFront->data == data)
		{
			return queueFront;
		}
		if (queueFront->leftNode != NULL)
		{
			nodeQueue.push(queueFront->leftNode);
		}
		if (queueFront->rightNode != NULL)
		{
			nodeQueue.push(queueFront->rightNode);
		}
		nodeQueue.pop();
	}
	return NULL;
}

node* makeNode(char data)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;
	return newNode;
}

void preorder(node* currentNode)
{
	cout << currentNode->data;
	if (currentNode->leftNode != NULL)
	{
		preorder(currentNode->leftNode);
	}
	if (currentNode->rightNode != NULL)
	{
		preorder(currentNode->rightNode);
	}
}

void inorder(node* currentNode)
{
	if (currentNode->leftNode != NULL)
	{
		inorder(currentNode->leftNode);
	}
	cout << currentNode->data;
	if (currentNode->rightNode != NULL)
	{
		inorder(currentNode->rightNode);
	}
}

void postorder(node* currentNode)
{
	if (currentNode->leftNode != NULL)
	{
		postorder(currentNode->leftNode);
	}
	if (currentNode->rightNode != NULL)
	{
		postorder(currentNode->rightNode);
	}
	cout << currentNode->data;
}

int main()
{
	int N;
	char current, left, right;
	cin >> N;
	node* root= new node;
	root->data = 'A';
	root->leftNode = NULL;
	root->rightNode = NULL;
	for (int i = 0; i < N; i++)
	{
		cin >> current >> left >> right;
		node* currentNode = findNode(root, current);
		if (left != '.')
		{
			currentNode->leftNode = makeNode(left);
		}
		if (right != '.')
		{
			currentNode->rightNode = makeNode(right);
		}
	}
	preorder(root);
	cout << "\n";
	inorder(root);
	cout << "\n";
	postorder(root);
	cout << "\n";
	return 0;
}