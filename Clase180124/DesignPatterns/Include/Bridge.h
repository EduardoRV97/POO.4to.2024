#pragma once
#include "Prerequisitos.h"

// Implementar la clase base
class Implementacion {
public:
	virtual void operacion() = 0;
};

// Implementacion Concreta A

class ImplementacionConcretaA : public Implementacion {
public:
	void operacion() override {
		cout << "Operacion en Implementacion A" << endl;
	}
};
class ImplementacionConcretaB : public Implementacion {
public:
	void operacion() override {
		cout << "Operacion en Implementacion B" << endl;
	}
};

//Clase Abstraccion

class Abstraccion {
public:
	Abstraccion(Implementacion* imp) : m_implementacion(imp) {};

	virtual void operacion() = 0;
protected:
	Implementacion* m_implementacion;
};

//Abstraccion refinada

class AbstraccionRefinada : public Abstraccion {
public:
	AbstraccionRefinada(Implementacion* imp) : Abstraccion(imp) {}
	void operacion() override {
		m_implementacion->operacion();
	}
};