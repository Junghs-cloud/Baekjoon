#include <iostream>
using namespace std;

struct node
{
	int value;
	node* leftChild;
	node* rightChild;
	node(int v)
	{
		value = v;
		leftChild = NULL;
		rightChild = NULL;
	}
};

void postOrder(node* node)
{
	if (node->leftChild != NULL)
	{
		postOrder(node->leftChild);
	}
	if (node->rightChild != NULL)
	{
		postOrder(node->rightChild);
	}
	cout << node->value << "\n";
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	node* root = NULL;
	node* currentNode;
	int num;
	while (true)
	{
		cin >> num;
		if (cin.eof() == true)
		{
			break;
		}
		currentNode = root;
		if (currentNode == NULL)
		{
			root = new node(num);
			continue;
		}
		node* newNode = new node(num);
		node* prevNode = root;
		while (true)
		{
			prevNode = currentNode;
			if (num < currentNode->value)
			{
				currentNode = currentNode->leftChild;
				if (currentNode == NULL)
				{
					prevNode->leftChild = newNode;
					break;
				}
			}
			else
			{
				currentNode = currentNode->rightChild;
				if (currentNode == NULL)
				{
					prevNode->rightChild = newNode;
					break;
				}
			}
		}
	}
	postOrder(root);
	return 0;
}