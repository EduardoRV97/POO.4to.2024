#pragma once
#include "Prerequisitos.h"

//Clase base para los prototipos

class Prototype {
	//Se crean 3 metodos virtuales, una del tipo Prototype y dos funciones, todas en valor 0
	//Configurar se debe obetner un tipo de valor string
public:
	virtual Prototype* clonar() = 0;
	virtual void configurar(string _valor) = 0;
	virtual void mostrar() = 0;
};

//Clase concreta que hereda de Prototype

class PrototypeConcreto : public Prototype {
	//Se sobreescriben los metodos creados anteriomente con los valores que se necesitan
	//El primero creando un nuevo objeto del tipo de dato PrototypeConcreto y retornando la copia
	//El segundo, asignandole un valor string a la variable _valor
	//La tercera mostrando el valor
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
	//Variable privada de valor del tipo de dato string
private:
	string valor;
};