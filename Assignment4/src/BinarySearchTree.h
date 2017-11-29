//============================================================================
// Name        : Assignment4.cpp
// Author      : Fatma Serce
// Modified by : Jordan Betcher
// Modified    : 11/29/2017
// Description : Binary Search Tree
//============================================================================

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <iostream>
#include <vector>

using namespace std;

template<class T>
struct node
{
		T data;
		node<T>* mpLeft;
		node<T>* mpRight;
};

template<class T>
class BinarySearchTree
{
	private:
		node<T>* root;
		vector<T> getInOrderByRecursion(node<T>*);
		vector<T> getPreOrderByRecursion(node<T>*);
		vector<T> getPostOrderByRecursion(node<T>*);
		int getHeightByRecursion(node<T>*);
		int getMaxNumber(int, int);
		int getNodeCountByRecursion(node<T>*);
		int getLeaveCountByRecursion(node<T>*);
		void insertByRecursion(node<T>*&, T&);
		bool containsByRecursion(node<T>*, T&);
		T searchByRecursion(node<T>*, T&);
		node<T>* getMaxNodeByRecursion(node<T>*);
		void deleteNodeByRecursion(node<T>*&, T&);
		void destroyNodeByRecursion(node<T>*);

	public:
		BinarySearchTree();
		vector<T> getInOrder();
		vector<T> getPreOrder();
		vector<T> getPostOrder();
		int getHeight();
		int getNodeCount();
		int getLeaveCount();
		void insert(T& item);
		bool contains(T& item);
		T search(T& item);
		node<T>* findMaxNode();
		void deleteNode(T& item);
		~BinarySearchTree();
};

//Create an empty Binary Search Tree
template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

//Returns the Binary Search Tree as a Vector, inOrder
template<class T>
inline vector<T> BinarySearchTree<T>::getInOrder()
{
		return getInOrderByRecursion(root);
}

//Returns the Binary Search Tree as a Vector, inOrder, does so by using recursion
template<class T>
vector<T> BinarySearchTree<T>::getInOrderByRecursion(node<T>* p)
{
	vector<T> inOrderVector;

	if (p != NULL)
	{
		vector<T> left = getInOrderByRecursion(p->mpLeft);
		inOrderVector.insert(inOrderVector.end(), left.begin(), left.end());

		inOrderVector.push_back(p->data);

		vector<T> right = getInOrderByRecursion(p->mpRight);
		inOrderVector.insert(inOrderVector.end(), right.begin(), right.end());
	}
	return inOrderVector;
}

//Returns the Binary Search Tree as a Vector, preOrder
template<class T>
inline vector<T> BinarySearchTree<T>::getPreOrder()
{
		return getPreOrderByRecursion(root);
}

//Returns the Binary Search Tree as a Vector, preOrder, does so by using recursion
template<class T>
vector<T> BinarySearchTree<T>::getPreOrderByRecursion(node<T>* p)
{
	vector<T> preOrderVector;

	if (p != NULL)
	{
		preOrderVector.push_back(p->data);

		vector<T> left = getPreOrderByRecursion(p->mpLeft);
		preOrderVector.insert(preOrderVector.end(), left.begin(), left.end());

		vector<T> right = getPreOrderByRecursion(p->mpRight);
		preOrderVector.insert(preOrderVector.end(), right.begin(), right.end());
	}

	return preOrderVector;
}

//Returns the Binary Search Tree as a Vector, postOrder
template<class T>
inline vector<T> BinarySearchTree<T>::getPostOrder()
{
		return getPostOrderByRecursion(root);
}

//Returns the Binary Search Tree as a Vector, postOrder, does so by using recursion
template<class T>
vector<T> BinarySearchTree<T>::getPostOrderByRecursion(node<T>* p)
{
	vector<T> postOrderVector;

	if (p != NULL)
	{
		vector<T> left = getPostOrderByRecursion(p->mpLeft);
		postOrderVector.insert(postOrderVector.end(), left.begin(), left.end());

		vector<T> right = getPostOrderByRecursion(p->mpRight);
		postOrderVector.insert(postOrderVector.end(), right.begin(),
		        right.end());

		postOrderVector.push_back(p->data);
	}

	return postOrderVector;
}

//Returns the height
template<class T>
inline int BinarySearchTree<T>::getHeight()
{
		return getHeightByRecursion(root);
}

//Returns the height calculated using recursion
template<class T>
int BinarySearchTree<T>::getHeightByRecursion(node<T>* p)
{
	if (p != NULL)
	{
		return 1 + getMaxNumber(getHeightByRecursion(p->mpLeft), getHeightByRecursion(p->mpRight));
	}
	return 0;
}

//Returns node count
template<class T>
inline int BinarySearchTree<T>::getNodeCount()
{
		return getNodeCountByRecursion(root);
}

//Returns node count using Recursion
template<class T>
int BinarySearchTree<T>::getNodeCountByRecursion(node<T>* p)
{
	if (p == NULL){
		return 0;
	}
	else{
		return 1 + getNodeCountByRecursion(p->mpLeft) + getNodeCountByRecursion(p->mpRight);
	}
}

//Returns leave count
template<class T>
inline int BinarySearchTree<T>::getLeaveCount()
{
		return getLeaveCountByRecursion(root);
}

//Returns leave count using recursion
template<class T>
int BinarySearchTree<T>::getLeaveCountByRecursion(node<T>* p)
{
	if (p == NULL) {
		return 0;
	}
	else if (p->mpLeft == NULL && p->mpRight == NULL){
		return 1;
	}
	else {
		return getLeaveCountByRecursion(p->mpLeft) + getLeaveCountByRecursion(p->mpRight);
	}
}

//inserts into tree
template<class T>
inline void BinarySearchTree<T>::insert(T& item)
{
		insertByRecursion(root, item);
}

//inserts into tree using recursion
template<class T>
void BinarySearchTree<T>::insertByRecursion(node<T>*& p, T& item)
{
	if (p == NULL)
	{
		p = new node<T>;
		p->data = item;
		p->mpLeft = p->mpRight = NULL;
	}
	else if (item < p->data)
	{
		insertByRecursion(p->mpLeft, item);
	}
	else
	{
		insertByRecursion(p->mpRight, item);
	}
}

//Returns whether or not the tree contains the item
template<class T>
inline bool BinarySearchTree<T>::contains(T& item)
{
		return containsByRecursion(root, item);
}

//Returns whether or not the tree contains the item using recursion
template<class T>
bool BinarySearchTree<T>::containsByRecursion(node<T>* p, T& item)
{
	if (p == NULL)
	{
		return false;
	}
	else if (item == p->data)
	{
		return true;
	}
	else if (item < p->data)
	{
		return containsByRecursion(p->mpLeft, item);
	}
	else if (item > p->data)
	{
		return containsByRecursion(p->mpRight, item);
	}
	else
	{
		return true;
	}
}

//Returns the item asked for
template<class T>
inline T BinarySearchTree<T>::search(T& item)
{
		return searchByRecursion(root, item);
}

//Returns the item asked for using recursion
template<class T>
T BinarySearchTree<T>::searchByRecursion(node<T>* p, T& item)
{
	if (item == p->data)
	{
		return p->data;
	}
	else if (item < p->data)
	{
		return searchByRecursion(p->mpLeft, item);
	}
	else if (item > p->data)
	{
		return searchByRecursion(p->mpRight, item);
	}

}

//Deletes a node
template<class T>
inline void BinarySearchTree<T>::deleteNode(T& item)
{
		return deleteNodeByRecursion(root, item);
}

//Deletes a node using recursion
template<class T>
void BinarySearchTree<T>::destroyNodeByRecursion(node<T>* p)
{
	if (p != NULL)
	{
		destroyNodeByRecursion(p->mpLeft);
		destroyNodeByRecursion(p->mpRight);
		delete p;
		p = NULL;
	}
}

//Returns the max node
template<class T>
inline node<T>* BinarySearchTree<T>::findMaxNode()
{
		getMaxNodeByRecursion(root);
}

//Returns the larger number between two number
template<class T>
int BinarySearchTree<T>::getMaxNumber(int x, int y)
{
	if (x > y) return x;
	return y;
}

//Returns the max node by recursion
template<class T>
node<T>* BinarySearchTree<T>::getMaxNodeByRecursion(node<T>* p)
{
	if (p == NULL)
	{
		return NULL;
	}
	else if (p->mpRight == NULL)
	{
		return p;
	}
	else
	{
		return getMaxNodeByRecursion(p->mpRight);
	}
}

// Deletes node using recursion
template<class T>
void BinarySearchTree<T>::deleteNodeByRecursion(node<T>*& p, T& item)
{
	if (p == NULL)
	{
		return;
	}
	else if (item < p->data)
	{
		deleteNodeByRecursion(p->mpLeft, item);
	}
	else if (item > p->data)
	{
		deleteNodeByRecursion(p->mpRight, item);
	}
	else
	{
		if (p->mpLeft != NULL && p->mpRight != NULL)
		{
			p->data = getMaxNodeByRecursion(p->mpLeft)->data;
			deleteNodeByRecursion(p->mpLeft, p->data);
		}
		else
		{
			node<T>* old = p;

			if (p->mpLeft != NULL)
			{
				p = p->mpLeft;
			}
			else
			{
				p = p->mpRight;
			}

			delete old;
		}
	}
}

//Destroys the nodes
template<class T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
		destroyNodeByRecursion(root);
}

#endif /* BINARYSEARCHTREE_H_ */
