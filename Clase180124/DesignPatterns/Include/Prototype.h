#pragma once
#include "Prerequisitos.h"

//Clase base para los prototipos

class Prototype {
public:
	virtual Prototype* clonar() = 0;
	virtual void configurar(string _valor) = 0;
	virtual void mostrar() = 0;
};

//Clase concreta

class PrototypeConcreto : public Prototype {
public:
	Prototype* clonar() override {
		PrototypeConcreto* copia = new PrototypeConcreto();
		copia->configurar(valor);
		return copia;
	}

	void configurar(string _valor) override {
		valor = _valor;
	}

	void mostrar() override {
		cout << "Valor: " << valor << endl;
	}
private:
	string valor;
};