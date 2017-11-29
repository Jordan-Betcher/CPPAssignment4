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
		node<T>* left;
		node<T>* right;
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
		vector<T> inOrder();
		vector<T> preOrder();
		vector<T> postOrder();
		int height();
		int nodeCount();
		int leaveCount();
		void insert(T& item);
		bool contains(T& item);
		T search(T& item);
		node<T>* findMax();
		void deletenode(T& item);
		~BinarySearchTree();
};

template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

template<class T>
inline vector<T> BinarySearchTree<T>::inOrder()
{
		return getInOrderByRecursion(root);
}

template<class T>
vector<T> BinarySearchTree<T>::getInOrderByRecursion(node<T>* p)
{
	vector<T> inOrderVector;

	if (p != NULL)
	{
		vector<T> left = getInOrderByRecursion(p->left);
		inOrderVector.insert(inOrderVector.end(), left.begin(), left.end());

		inOrderVector.push_back(p->data);

		vector<T> right = getInOrderByRecursion(p->right);
		inOrderVector.insert(inOrderVector.end(), right.begin(), right.end());
	}
	return inOrderVector;
}

template<class T>
inline vector<T> BinarySearchTree<T>::preOrder()
{
		return getPreOrderByRecursion(root);
}

template<class T>
vector<T> BinarySearchTree<T>::getPreOrderByRecursion(node<T>* p)
{
	vector<T> preOrderVector;

	if (p != NULL)
	{
		preOrderVector.push_back(p->data);

		vector<T> left = getPreOrderByRecursion(p->left);
		preOrderVector.insert(preOrderVector.end(), left.begin(), left.end());

		vector<T> right = getPreOrderByRecursion(p->right);
		preOrderVector.insert(preOrderVector.end(), right.begin(), right.end());
	}

	return preOrderVector;
}

template<class T>
inline vector<T> BinarySearchTree<T>::postOrder()
{
		return getPostOrderByRecursion(root);
}

template<class T>
vector<T> BinarySearchTree<T>::getPostOrderByRecursion(node<T>* p)
{
	vector<T> postOrderVector;

	if (p != NULL)
	{
		vector<T> left = getPostOrderByRecursion(p->left);
		postOrderVector.insert(postOrderVector.end(), left.begin(), left.end());

		vector<T> right = getPostOrderByRecursion(p->right);
		postOrderVector.insert(postOrderVector.end(), right.begin(),
		        right.end());

		postOrderVector.push_back(p->data);
	}

	return postOrderVector;
}

template<class T>
inline int BinarySearchTree<T>::height()
{
		return getHeightByRecursion(root);
}

template<class T>
int BinarySearchTree<T>::getHeightByRecursion(node<T>* p)
{
	if (p != NULL)
	{
		return 1 + getMaxNumber(getHeightByRecursion(p->left), getHeightByRecursion(p->right));
	}
	return 0;
}

template<class T>
inline int BinarySearchTree<T>::nodeCount()
{
		return getNodeCountByRecursion(root);
}

template<class T>
int BinarySearchTree<T>::getNodeCountByRecursion(node<T>* p)
{
	if (p == NULL){
		return 0;
	}
	else{
		return 1 + getNodeCountByRecursion(p->left) + getNodeCountByRecursion(p->right);
	}
}

template<class T>
inline int BinarySearchTree<T>::leaveCount()
{
		return getLeaveCountByRecursion(root);
}

template<class T>
int BinarySearchTree<T>::getLeaveCountByRecursion(node<T>* p)
{
	if (p == NULL) {
		return 0;
	}
	else if (p->left == NULL && p->right == NULL){
		return 1;
	}
	else {
		return getLeaveCountByRecursion(p->left) + getLeaveCountByRecursion(p->right);
	}
}

template<class T>
inline void BinarySearchTree<T>::insert(T& item)
{
		insertByRecursion(root, item);
}

template<class T>
void BinarySearchTree<T>::insertByRecursion(node<T>*& p, T& item)
{
	if (p == NULL)
	{
		p = new node<T>;
		p->data = item;
		p->left = p->right = NULL;
	}
	else if (item < p->data)
	{
		insertByRecursion(p->left, item);
	}
	else
	{
		insertByRecursion(p->right, item);
	}
}

template<class T>
inline bool BinarySearchTree<T>::contains(T& item)
{
		return containsByRecursion(root, item);
}

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
		return containsByRecursion(p->left, item);
	}
	else if (item > p->data)
	{
		return containsByRecursion(p->right, item);
	}
	else
	{
		return true;
	}
}

template<class T>
inline T BinarySearchTree<T>::search(T& item)
{
		return searchByRecursion(root, item);
}

template<class T>
T BinarySearchTree<T>::searchByRecursion(node<T>* p, T& item)
{
	if (item == p->data)
	{
		return p->data;
	}
	else if (item < p->data)
	{
		return searchByRecursion(p->left, item);
	}
	else if (item > p->data)
	{
		return searchByRecursion(p->right, item);
	}

}

template<class T>
inline void BinarySearchTree<T>::deletenode(T& item)
{
		return deleteNodeByRecursion(root, item);
}

template<class T>
void BinarySearchTree<T>::destroyNodeByRecursion(node<T>* p)
{
	if (p != NULL)
	{
		destroyNodeByRecursion(p->left);
		destroyNodeByRecursion(p->right);
		delete p;
		p = NULL;
	}
}

template<class T>
inline node<T>* BinarySearchTree<T>::findMax()
{
		getMaxNodeByRecursion(root);
}

template<class T>
int BinarySearchTree<T>::getMaxNumber(int x, int y)
{
	if (x > y) return x;
	return y;
}

template<class T>
node<T>* BinarySearchTree<T>::getMaxNodeByRecursion(node<T>* p)
{
	if (p == NULL)
	{
		return NULL;
	}
	else if (p->right == NULL)
	{
		return p;
	}
	else
	{
		return getMaxNodeByRecursion(p->right);
	}
}

template<class T>
void BinarySearchTree<T>::deleteNodeByRecursion(node<T>*& p, T& item)
{
	if (p == NULL)
	{
		return;
	}
	else if (item < p->data)
	{
		deleteNodeByRecursion(p->left, item);
	}
	else if (item > p->data)
	{
		deleteNodeByRecursion(p->right, item);
	}
	else
	{
		if (p->left != NULL && p->right != NULL)
		{
			p->data = getMaxNodeByRecursion(p->left)->data;
			deleteNodeByRecursion(p->left, p->data);
		}
		else
		{
			node<T>* old = p;

			if (p->left != NULL)
			{
				p = p->left;
			}
			else
			{
				p = p->right;
			}

			delete old;
		}
	}
}

template<class T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
		destroyNodeByRecursion(root);
}

#endif /* BINARYSEARCHTREE_H_ */
