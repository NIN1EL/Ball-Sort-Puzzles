#pragma once
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

template <class E> // 

class Node
{
private:
	Node<E>* sig;
	E e;
	int i;

public:
	Node(E, int);
	~Node();
	virtual void setSig(Node<E>*);
	virtual Node<E>* getSig();
	virtual E getObject();
	virtual int getIndex();
};

template<class E>
inline Node<E>::Node(E e, int i)
{
	this->e = e;
	this->i = i;
	this->sig = NULL; 
}

template<class E>
inline Node<E>::~Node()
{
	sig = NULL;//elimnar la referencia
}

template<class E>
inline void Node<E>::setSig(Node<E>* sig)
{
	this->sig = sig;
}

template<class E>
inline Node<E> *Node<E>::getSig()
{
	return sig;
}

template<class E>
inline E Node<E>::getObject()
{
	return e;
}

template<class E>
inline int Node<E>::getIndex()
{
	return i;
}
