#ifndef BINARYTREE_H
#define BINARYTREE_H


class tree
{
private:
	int treeArray[128] = { 0 };
	int root = 0;

public:
	 const void setemptytree();
	 const void search(const int & value);
	 const int findMin(const int & root);
	 const int findMax(const int & root);
	 void insert(const int & value);
	 void remove(const int & value);
	 const void displayInOrder(const int & root); //In order traversal LVR traversal 

	
};

#endif