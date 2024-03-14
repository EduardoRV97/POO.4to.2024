#pragma once
#include "Prerequisitos.h"

// ComponenteBase
//Se crean un metodo virtual llamado operacion que va a 0
class CComponent {
public:
	virtual void operacion() = 0;
};

//Leaf

class Leaf : public CComponent {
	//La oja sobreescribe el valor de la operacion en una impresion en pantalla
public: 
	void operacion() override {
		cout << "Operacion en hola." << endl;
	}
};

//Nodo Compuesto (Contenedor)

class Compuesto : public CComponent {
	//Se sobreescribe la funcion anterior, para imprimir en pabtalla el tamano de hojas que se hayan hecho, con un recorrido que se hara hasta llegar al total
	//Y otra funcion donde se regresa un valor nuevo al vector Leafs
public: 
	void operacion() override {
		cout << "Operacion en el compuesto. Contiene" << Leafs.size() << " hojas." << endl;
		for (CComponent* Leaf : Leafs) {
			Leaf->operacion();
		}
	}
	void agregarLeaf(CComponent* _leaf) {
		Leafs.push_back(_leaf);
	}
private:
	//Se crea un vector privado que contendra las Hojas
	vector<CComponent*> Leafs;
};