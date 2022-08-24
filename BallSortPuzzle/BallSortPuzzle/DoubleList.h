#pragma once
#include "List.h"
#include "DoubleNode.h"
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

template <class E>

class DoubleList : public List<E>
{
private:
	DoubleNode<E>* ini;
	DoubleNode<E>* last;
public:
	DoubleList();
	~DoubleList();
	virtual List<E>* add(E);
	virtual List<E>* addAll(List<E>*);
	virtual E remove(int);
	virtual void removeAll();
	virtual E removeLast();
	virtual void set(int, E);
	virtual E get(int);
	virtual E getLast();
	virtual Iterator<E>* iterator();
	virtual Iterator<E>* iteratorLast();
	virtual const string toString();
private:
	virtual void reindex(DoubleNode<E>* node);
};

template<class E>
inline DoubleList<E>::DoubleList()
{
	this->ini = NULL;
	this->last = NULL;
	this->tam = 0;
}

template<class E>
inline DoubleList<E>::~DoubleList()
{
	ini = NULL;
	last = NULL;
}

template<class E>
inline List<E>* DoubleList<E>::add(E e)
{
	if (ini == NULL) {
		ini = new DoubleNode<E>(NULL, e, this->tam++);
		last = ini;
	}else {
		last->setSig(new DoubleNode<E>(last, e, this->tam++));
		last = last->getSig();
	}
	return this;
}

template<class E>
inline List<E>* DoubleList<E>::addAll(List<E>* list)
{
	for (int i = 0; i < list->size(); i++) {
		this->add(list->remove(i));
	}
	return this;
}

template<class E>
inline E DoubleList<E>::remove(int i)//areglar poner last
{
	DoubleNode<E>* actual = ini;
	E obj = NULL;

	if (actual->getIndex() == i) {
		reindex(actual);
		ini = actual->getSig();
		ini->setAnt(NULL);
		obj = actual->getObject();
		delete actual;
		this->tam--;
	}
	else {
		while (actual != NULL) {
			if (actual->getSig() != NULL && (actual->getSig())->getIndex() == i) {
				if ((actual->getSig())->getSig() != NULL) {//medio
					reindex(actual);
					actual->setSig((actual->getSig())->getSig());
					actual->getSig()->getSig()->setAnt(actual);
					actual = actual->getSig();
					obj = actual->getObject();
					delete actual;
					this->tam--;
					break;
				}
				else {//ultimo
					DoubleNode<E>* aux = actual->getSig();
					actual->setSig(NULL);
					last = actual;
					delete aux;
					this->tam--;
					break;
				}
			}
			actual = actual->getSig();
		}
	}
	return obj;
}

template<class E>
inline void DoubleList<E>::removeAll()
{
	while (last != NULL) {
		DoubleNode<E>* aux = last;
		last = last->getAnt();
		if (last != NULL) last->setSig(NULL);
		else ini = NULL;
		delete aux;
		this->tam--;
	}
}

template<class E>
inline void DoubleList<E>::set(int i, E obj)
{
	DoubleNode<E>* actual = ini;

	while (actual != NULL) {
		if (actual->getIndex() == i) {
			actual->setObj(obj);
			break;
		}
		actual = actual->getSig();
	}
}
template<class E>
inline E DoubleList<E>::get(int i)
{
	DoubleNode<E>* actual = ini;
	E obj = NULL;

	while (actual != NULL) {
		if (actual->getIndex() == i) {
			obj = actual->getObject();
			break;
		}
		actual = actual->getSig();
	}

	return obj;
}

template<class E>
inline E DoubleList<E>::getLast()
{
	return last->getObject();
}

template<class E>
inline Iterator<E>* DoubleList<E>::iterator()
{
	return new Iterator<E>(ini);
}

template<class E>
inline Iterator<E>* DoubleList<E>::iteratorLast()
{
	return new Iterator<E>(last);
}

template<class E>
inline const string DoubleList<E>::toString()
{
	stringstream x;
	DoubleNode<E>* actual = ini;

	if (actual == NULL) {
		x << "Lista vacia" << endl;
	}
	else {
		while (actual != NULL) {
			x << "[" << actual->getObject()->toString() << ", " << actual->getIndex() << "]" << endl;
			actual = actual->getSig();
		}
	}
	x << endl << endl;

	return x.str();
}

template<class E>
inline void DoubleList<E>::reindex(DoubleNode<E>* node)
{
	int index = node->getIndex();
	node = node->getSig();
	while (node != NULL) {
		node->setIndex(index);
		node = node->getSig();
		if (node != NULL) index = node->getIndex();
	}

}

template<class E>
inline E DoubleList<E>::removeLast()
{
	E obj = last->getObject();
	DoubleNode<E>* aux = last;
	last = last->getAnt();
	if (last != NULL) last->setSig(NULL);
	else ini = NULL;
	delete aux;
	this->tam--;
	return obj;
}