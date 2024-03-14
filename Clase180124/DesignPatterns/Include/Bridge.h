#pragma once
#include "Prerequisitos.h"


// Implementar la clase base
//Se crea un metodo virtual llamado operacion con valor en 0
class Implementacion {
public:
	virtual void operacion() = 0;
};

//En ambas implementaciones se sobreescribe el valor del metodo operacion, para mostrar un mensaje en pantalla, dependiendo de cual implementacio este aplicada
// Implementacion Concreta A

class ImplementacionConcretaA : public Implementacion {
public:
	void operacion() override {
		cout << "Operacion en Implementacion A" << endl;
	}
};

// Implementacion Concreta B

class ImplementacionConcretaB : public Implementacion {
public:
	void operacion() override {
		cout << "Operacion en Implementacion B" << endl;
	}
};

//Clase Abstraccion

class Abstraccion {
	//Se inicializan los valores de la variable m_implementacion y se utiliza un metodo virtual con valor en 0
public:
	Abstraccion(Implementacion* imp) : m_implementacion(imp) {};

	virtual void operacion() = 0;
	//Se crea un tipo de dato protegido, del tipo implementacion
protected:
	Implementacion* m_implementacion;
};

//Abstraccion refinada
//Se inicializa un variable del tipo implementacion imp y en el tipo abstraccion imp, haciendo un sobreescritura del valor del metodo operacion, donde la variable hace uso del metodo operacion
class AbstraccionRefinada : public Abstraccion {
public:
	AbstraccionRefinada(Implementacion* imp) : Abstraccion(imp) {}
	void operacion() override {
		m_implementacion->operacion();
	}
};