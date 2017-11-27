/*
 * BinarySearchTree.h
 *
 *  Created on: Oct 30, 2017
 *      Author: fatma.serce
 */

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
		vector<T> inOrderT(node<T>*);
		vector<T> preOrderT(node<T>*);
		vector<T> postOrderT(node<T>*);
		void destroy(node<T>*);
		int treeHeight(node<T>*);
		int max(int, int);
		int treeNodeCount(node<T>*);
		int treeLeaveCount(node<T>*);
		void treeInsert(node<T>*&, T&);
		bool treeContains(node<T>*, T&);
		T treeSearch(node<T>*, T&);
		node<T>* findMax(node<T>*);
		void deletenode(node<T>*&, T&);

	public:
		BinarySearchTree();
		vector<T> inOrder()
		{
			return inOrderT(root);
		}
		vector<T> preOrder()
		{
			return preOrderT(root);
		}
		vector<T> postOrder()
		{
			return postOrderT(root);
		}
		int height()
		{
			return treeHeight(root);
		}
		int nodeCount()
		{
			return treeNodeCount(root);
		}
		int leaveCount()
		{
			return treeLeaveCount(root);
		}
		void insert(T& item)
		{
			treeInsert(root, item);
		}
		bool contains(T& item)
		{
			return treeContains(root, item);
		}
		T search(T& item)
		{
			return treeSearch(root, item);
		}
		node<T>* findMax()
		{
			return findMax(root);
		}
		void deletenode(T& item)
		{
			deletenode(root, item);
		}
		~BinarySearchTree()
		{
			destroy(root);
		}

};

template<class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

template<class T>
vector<T> BinarySearchTree<T>::inOrderT(node<T>* p)
{
	vector<T> inOrderVector;

	if (p != NULL)
	{
		vector<T> left = inOrderT(p->left);
		inOrderVector.insert(inOrderVector.end(), left.begin(), left.end());

		inOrderVector.push_back(p->data);

		vector<T> right = inOrderT(p->right);
		inOrderVector.insert(inOrderVector.end(), right.begin(), right.end());
	}
	return inOrderVector;
}

template<class T>
vector<T> BinarySearchTree<T>::preOrderT(node<T>* p)
{
	vector<T> preOrderVector;

	if (p != NULL)
	{
		preOrderVector.push_back(p->data);

		vector<T> left = inOrderT(p->left);
		preOrderVector.insert(preOrderVector.end(), left.begin(), left.end());

		vector<T> right = inOrderT(p->right);
		preOrderVector.insert(preOrderVector.end(), right.begin(), right.end());
	}

	return preOrderVector;
}

template<class T>
vector<T> BinarySearchTree<T>::postOrderT(node<T>* p)
{
	vector<T> postOrderVector;

	if (p != NULL)
	{
		vector<T> left = inOrderT(p->left);
		postOrderVector.insert(postOrderVector.end(), left.begin(), left.end());

		vector<T> right = inOrderT(p->right);
		postOrderVector.insert(postOrderVector.end(), right.begin(), right.end());

		postOrderVector.push_back(p->data);
	}

	return postOrderVector;
}
template<class T>
int BinarySearchTree<T>::max(int x, int y)
{
	if (x > y) return x;
	return y;
}

template<class T>
int BinarySearchTree<T>::treeHeight(node<T>* p)
{
	if (p != NULL)
	{
		return 1 + max(height(p->left, p->right));
	}
	return 0;
}

template<class T>
int BinarySearchTree<T>::treeNodeCount(node<T>* p)
{
	if (p == NULL) return 0;
	else return 1 + treeNodeCount(p->left) + treeNodeCount(p->right);
}
template<class T>
int BinarySearchTree<T>::treeLeaveCount(node<T>* p)
{
	if (p == NULL) return 0;
	else if (p->left == NULL && p->right == NULL) return 1;
	else return treeLeaveCount(p->left) + treeLeaveCount(p->right);
}
template<class T>
void BinarySearchTree<T>::destroy(node<T>* p)
{
	if (p != NULL)
	{
		destroy(p->left);
		destroy(p->right);
		delete p;
		p = NULL;
	}
}
//non recursive insert function
//template <class T>
//void BinarySearchTree<T>::insert(T& item){
//	node<T>* newnode = new node<T>();
//	newnode->data = item;
//	newnode->left = newnode->right = NULL;
//	if(root == NULL){
//		root = newnode;
//	}
//	else{
//		node<T>* p = root;
//		node<T>* q;
//		while(p!=NULL){
//			q = p;
//			if(item==p->data){
//				cout<<p->data;
//				cout<<"error"<<endl;
//				return;
//			}
//			else if (item<p->data)
//				p = p->left;
//			else
//				p = p->right;
//		}
//		if(item<q->data)
//			q->left = newnode;
//		else
//			q->right = newnode;
//	}
//
//}
template<class T>
void BinarySearchTree<T>::treeInsert(node<T>*& p, T& item)
{
	if (p == NULL)
	{
		p = new node<T>;
		p->data = item;
		p->left = p->right = NULL;
	}
	else if (item < p->data)
	{
		treeInsert(p->left, item);
	}
	else
	{
		treeInsert(p->right, item);
	}

}

template<class T>
bool BinarySearchTree<T>::treeContains(node<T>* p, T& item)
{
	if (p == NULL) return false;
	else if (item == p->data) return true;
	else if (item < p->data) return treeContains(p->left, item);
	else if (item > p->data) return treeContains(p->right, item);
	return true;
}

template<class T>
T BinarySearchTree<T>::treeSearch(node<T>* p, T& item)
{
	if (item == p->data) return p->data;
	else if (item < p->data) return treeSearch(p->left, item);
	else if (item > p->data) return treeSearch(p->right, item);

}

template<class T>
node<T>* BinarySearchTree<T>::findMax(node<T>* p)
{
	if (p == NULL) return NULL;
	else if (p->right == NULL) return p;
	else return findMax(p->right);
}

template<class T>
void BinarySearchTree<T>::deletenode(node<T>*& p, T& item)
{
	//item not found, do nothing
	if (p == NULL) return;
	else if (item < p->data)	//item is on the left subtree
	deletenode(p->left, item);
	else if (item > p->data)	//item is on the right subtree
	deletenode(p->right, item);
	else
	{	//item is equal to data,  it is found
		if (p->left != NULL && p->right != NULL)
		{	//if it is with two children
			p->data = findMax(p->left)->data;
			deletenode(p->left, p->data);
		}
		else
		{
			node<T>* old = p;
			if (p->left != NULL) p = p->left;
			else p = p->right;

			delete old;
		}
	}
}

#endif /* BINARYSEARCHTREE_H_ */
