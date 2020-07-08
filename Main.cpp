#include "BinaryTree.h"
#include <iostream>
using namespace std;

//Implement a BST class using a static array.The class must support all BST operations(search, findMin, findMax, insert, delete, display with in - order traversal).
//In the client code, do the following :
//1. Insert 30, 20, 1, 10, 50, 80, 90, 40, 60, 100, 70 into a BST object;
//2. Display the smallest and the largest values;
//3. Search 100 and 88. Display a message to indicate whether a value is found;
//4. Display all values in - order;
//5. Delete 1; Then do another in - order display of all values;
//6. Delete 50; Then do another in - order display of all values;
//7. Delete 100; Then do another in - order display of all values;

int main()
{

	tree trial;
	trial.setemptytree();

	trial.insert(30);
	trial.insert(20); 
	trial.insert(1);
	trial.insert(10);
	trial.insert(50);
	trial.insert(80);
	trial.insert(90);
	trial.insert(40);
	trial.insert(60);
	trial.insert(100);
	trial.insert(70);

	cout << "Max is: " << trial.findMax(0) << endl;
	cout << "Min is: " << trial.findMin(0) << endl;

	trial.search(100);
	trial.search(88);

	trial.displayInOrder(0);
	cout << endl;

	trial.remove(1);
	trial.displayInOrder(0);
	cout << endl;

	trial.remove(50);
	trial.displayInOrder(0);
	cout << endl;

	trial.remove(100);
	trial.displayInOrder(0);
	cout << endl;

	system("pause");
	return (0);
}