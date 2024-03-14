#pragma once
#include "Prerequisitos.h"

 //Clase que representa un producto complejo

class
	BProducto {
	//Se crean dos metodos publicos, en el primero se obtienen los valores para un vector del tipo de dato string
	//Y en el segundo es un metodo para mostrar las partes del objeto que se buscan generar y que se haya guardado e el vector
public:
	void agregarParte(const string& _parte) {
		partes.push_back(_parte);
	}

	void mostrar() {
		cout << "Partes del producto: ";
		for (const string& parte :partes) {
			cout << parte << " ";

		}
		cout << endl;
	}
	//Se crea un vector privado que contendra las partes
private:
	vector<string> partes;
};

 //Clase abstracta del constructor (builder)
class Builder {
public:
	//Se crean 3 metodos virtuales en la cual 2 seran funciones y uno sera un puntero del tipo BProducto. Todos en valor 0
	virtual void construirParteA() = 0;
	virtual void construirParteB() = 0;
	virtual BProducto* obtenerProducto() = 0;
};

// Clase concreta de constructor (Builder Concreto)

class BuilderConcreto : public Builder {
	//Se crean los metodos que sobreescribiran los metodos de la clase builder, con una funcion asignada de agregarParte, que sera el extra que se incluire dependiento del objeto que se cree
public:
	BuilderConcreto() {
		producto = new BProducto();
	}
	void construirParteA() override{
		producto->agregarParte("Parte A");
	}
	void construirParteB() override{
		producto->agregarParte("Parte B");
	}
	BProducto* obtenerProducto() override {//Metodo para retornar un valor a producto y se guarde en el vector
		return producto;
	}
private:
	BProducto* producto;
};

// Clase Director, la que controla todo el proceso y marca la pauta de cuando se genera una parte

class Director {
public:
	Director(Builder* _builder) : builder(_builder) {}

	void construir() {//Llama a la variable builder que apunta a construir parte a y B, que es una variable privada
		builder->construirParteA();
		builder->construirParteB();
	}
private:
	Builder* builder;
};