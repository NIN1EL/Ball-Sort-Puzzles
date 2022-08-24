#pragma once
#include "List.h"
#include "Node.h"
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

template <class E>

class ArrayList : public List<E>
{
private:
	Node<E>* ini;
	Node<E>* last;
public:
	ArrayList();
	virtual List<E>* add(E);
	virtual List<E>* addAll(List<E>*);
	virtual E remove(int);
	virtual E get(int);
	virtual const string toString();
};

template<class E>
inline ArrayList<E>::ArrayList()
{
	this->ini = NULL;
	this->last = NULL;
	this->tam = 0;
}

template<class E>
inline List<E>* ArrayList<E>::add(E e)
{
	if (ini == NULL) {
		ini = new Node<E>( e, this->tam++ );
		last = ini;
	}
	else {
		last->setSig( new Node<E>( e, this->tam++ ) );
		last = last->getSig();
	}
	return this;
}

template<class E>
inline List<E>* ArrayList<E>::addAll(List<E>* list)
{
	for (int i = 0; i < list->size(); i++) {
		this->add(list->remove(i));
	}

	return this;
}

template<class E>
inline E ArrayList<E>::remove(int i)
{
	Node<E>* actual = ini;
	E obj = NULL;

	if (actual->getIndex() == i && actual == ini) {
		ini = actual->getSig();
		obj = actual->getObject();
		delete actual;
		this->tam--;
	}
	else {
		while (actual != NULL) {
			if (actual->getSig() != NULL && (actual->getSig())->getIndex() == i) {
				if ((actual->getSig())->getSig() != NULL) {//medio
					actual->setSig((actual->getSig())->getSig());
					actual = actual->getSig();
					obj = actual->getObject();
					delete actual;
					this->tam--;
					break;
				}
				else {//ultimo
					Node<E>* aux = actual->getSig();
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
inline E ArrayList<E>::get(int i)
{
	Node<E>* actual = ini;
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
inline const string ArrayList<E>::toString()
{
	stringstream x;
	Node<E>* actual = ini;

	if (actual == NULL) {
		x << "Lista vacia" << endl;
	}
	else {
		while (actual != NULL) {
			x << "[" << actual->getObject() << ", " << actual->getIndex() << "]" << endl;
			actual = actual->getSig();
		}
	}
	x << endl << endl;

	return x.str();
}