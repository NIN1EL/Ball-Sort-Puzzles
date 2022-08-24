#pragma once
#include "Bola.h"
#include "Stack.h"
#include "DoubleList.h"
#include "Objeto_Grafico.h"
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Tubo : public Stack<Bola*>,  protected DoubleList<Bola*>, public Graphic_Object
{
private:
	int i;
public:
	Tubo(int, float = 0, float = 0);
	Tubo(Tubo&);
	~Tubo();
	int getI();
	void setI(int);
	virtual Bola* pop();
	virtual Bola* top();
	virtual void push(Bola*);
	virtual int search(Bola*);
	virtual const int size() ;
	virtual const bool empty();
	virtual Iterator<Bola*>* iterator();
	virtual const string toString();
};
