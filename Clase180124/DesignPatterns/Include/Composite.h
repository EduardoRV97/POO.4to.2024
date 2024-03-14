#pragma once
#include "Prerequisitos.h"

// ComponenteBase
class CComponent {
public:
	virtual void operacion() = 0;
};

//Leaf

class Leaf : public CComponent {
public: 
	void operacion() override {
		cout << "Operacion en hola." << endl;
	}
};

//Nodo Compuesto (Contenedor)

class Compuesto : public CComponent {
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
	vector<CComponent*> Leafs;
};