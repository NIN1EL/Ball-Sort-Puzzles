#pragma once
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

template <class E> // 

class DoubleNode
{
private:
	DoubleNode<E>* sig;
	DoubleNode<E>* ant;
	E e;
	int i;

public:
	DoubleNode(DoubleNode<E>*, E, int);
	~DoubleNode();
	virtual void setSig(DoubleNode<E>*);
	virtual void setAnt(DoubleNode<E>*);
	virtual DoubleNode<E>* getSig();
	virtual DoubleNode<E>* getAnt();
	virtual E getObject();
	virtual int getIndex();
	virtual void setObj(E);
	virtual void setIndex(int);
};

template<class E>
inline void DoubleNode<E>::setObj(E obj)
{
	this->e = obj;
}

template<class E>
inline DoubleNode<E>::DoubleNode(DoubleNode<E>* ant, E e, int i)
{
	this->e = e;
	this->i = i;
	this->sig = NULL;
	this->ant = ant;
}

template<class E>
inline DoubleNode<E>::~DoubleNode()
{
	//elimnar la referencia
	
}

template<class E>
inline void DoubleNode<E>::setSig(DoubleNode<E>* sig)
{
	this->sig = sig;
}

template<class E>
inline void DoubleNode<E>::setAnt(DoubleNode<E>*)
{
	this->ant = ant;
}

template<class E>
inline DoubleNode<E>* DoubleNode<E>::getSig()
{
	return sig;
}

template<class E>
inline DoubleNode<E>* DoubleNode<E>::getAnt()
{
	return ant;
}

template<class E>
inline E DoubleNode<E>::getObject()
{
	return e;
}

template<class E>
inline int DoubleNode<E>::getIndex()
{
	return i;
}

template<class E>
inline void DoubleNode<E>::setIndex(int i)
{
	this->i = i;
}
