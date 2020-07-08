#include "BinaryTree.h"
#include <iostream>
using namespace std;

const void tree::setemptytree()
{
	for (int i = 0; i < 128; i++)
	{
		treeArray[i] = -1;
	}
}

const void tree::search(const int & value)
{
	int currentIndex = root;

	while (true)
	{
		if (treeArray[currentIndex] == -1)
		{
			cout << "The value " << value << " was not found in BST!" << endl;
			break;
		}
		else if (treeArray[currentIndex] == value)
		{
			cout << "The value " << value << " was found in BST at index loaction " << currentIndex << endl;
			break;
		}
		else if (treeArray[currentIndex] < value)
			currentIndex = (currentIndex * 2) + 2;
		else if (treeArray[currentIndex] > value)
			currentIndex = (currentIndex * 2) + 1;
		
	}
}

const int tree::findMin(const int & root)
{
	int currentIndex = root;
	int minIndex = -1;

	while (treeArray[currentIndex] != -1)
	{
		minIndex = currentIndex;
		currentIndex = (currentIndex * 2) + 1; // traversing left subtree
	}

	return treeArray[minIndex];//Min
}

const int tree::findMax(const int & root)
{
	int currentIndex = root;
	int maxIndex = -1;

	while (treeArray[currentIndex] != -1)
	{
		maxIndex = currentIndex;
		currentIndex = (currentIndex * 2) + 2; // traversing right subtree
	}

	return treeArray[maxIndex]; // Max
}

void tree::insert(const int & value)
{
	int currentIndex = root;

	while (true)
	{
		if (treeArray[currentIndex] == -1)
		{
			treeArray[currentIndex] = value;
			break;
		}
		else if (treeArray[currentIndex] <= value)
		{
			if (treeArray[currentIndex] == value) // same value, a repeat
				break;
			else
				currentIndex = (currentIndex * 2) + 2;
		}
		else if (treeArray[currentIndex] >= value)
		{
			if (treeArray[currentIndex] == value) // Same value, a repeat
				break;
			else
				currentIndex = (currentIndex * 2) + 1;
		}
	}
}



void tree::remove(const int & value)
{
	int currentIndex = root;
	int childIndex;
	int deleteIndex;

	while (true)
	{
		
		if (treeArray[currentIndex] == value)
		{
			deleteIndex = currentIndex;

			if ((treeArray[currentIndex * 2 + 1] == -1) && (treeArray[currentIndex * 2 + 2] == -1)) // No children
				treeArray[deleteIndex] = -1;
			else if (treeArray[currentIndex * 2 + 1] != -1) // left child (Max value of left subtree)
			{
				childIndex = (currentIndex * 2 + 1);
				treeArray[deleteIndex] = findMax(childIndex);
				treeArray[childIndex] = -1;
				break;
			}
			else if (treeArray[currentIndex * 2 + 2] != -1) // right child (Min value of right subtree)
			{
				childIndex = (currentIndex * 2 + 2);
				treeArray[deleteIndex] = findMin(childIndex);
				treeArray[childIndex] = -1;
				break;
			}
		}
		else if (treeArray[currentIndex] == -1)
		{
			cout << "Item not in BST!" << endl;
			break;
		}
		else if (treeArray[currentIndex] < value)
		{
			currentIndex = (currentIndex * 2) + 2;
		}
		else if (treeArray[currentIndex] > value)
		{
			currentIndex = (currentIndex * 2) + 1;
		}
	}
}

const void tree::displayInOrder(const int & root)
{
	int currentIndex = root;

	if (treeArray[currentIndex] != -1)
	{
		displayInOrder(2 * currentIndex + 1);
		cout << treeArray[currentIndex] << ", ";
		displayInOrder(2 * currentIndex + 2);
	}
}


