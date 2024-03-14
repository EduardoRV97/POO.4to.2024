#pragma once
#include "Prerequisitos.h"

// Clase base para los productos
class FMPRoducto {
	//Se crean 2 metodos publicos con valores en cero, uno de ellos con los tipos de valores que debe de obtener
public:
	virtual void registrar(string _nombre, float _peso, float _precio) = 0;
	virtual void operacion() = 0;
};

//Clase base para la fabrica
class FMFabrica {
public: 
	//Metodo virtuales del tipo FMProducto que crean valors en 0
	virtual FMPRoducto* crearProducto() = 0;
	virtual FMPRoducto* crearPapas() = 0;
	virtual FMPRoducto* crearRefresco() = 0;
};

//Clase concreta del producto
class FMProductoConcreto : public FMPRoducto {
	//2 metodos publicos, en uno se inicializan los valores que se deben de obtener y en otro se sobvreescribe la funcion operacion para mostrar un valor
public:
	void registrar(string _nombre, float _peso, float _precio) {

	}
	void operacion() override {
		cout << "Operacion en Producto Concreto" << endl;
	}
};

class FMChettos : public FMPRoducto {
public: 
	string nombre;
	float peso;
	float precio;
public:
	void registrar(string _nombre, float _peso, float _precio) {
		nombre = _nombre;
		peso = _peso;
		precio = _precio;
	}
	void operacion() override{
		cout << "Nombre: " << nombre << endl << "Peso: " << peso << endl << "Precio: " << precio << endl;
	}
};

class FMPepsiBlack : public FMPRoducto {
public: 
	string nombre;
	float peso;
	float precio;
public:
	void registrar(string _nombre, float _peso, float _precio) {
		nombre = _nombre;
		peso = _peso;
		precio = _precio;
	}
	void operacion() override{
		cout << "Nombre: " << nombre << endl << "Peso: " << peso << endl << "Precio: " << precio << endl;
	}
};

//Clase concreta de la fabrica
class FMFabricaConcreta : public FMFabrica {
public:
	FMPRoducto* crearProducto() override {
		return new FMProductoConcreto();
	}
	FMPRoducto* crearPapas() override {
		return new FMChettos();
	}
	FMPRoducto* crearRefresco() override {
		return new FMPepsiBlack();
	}

};

class FMPepsico : public FMFabrica {
public:
	FMPRoducto* crearPapas() override {
		return new FMChettos();
	}
	FMPRoducto* crearRefresco() override {
		return new FMPepsiBlack();
	}
};

/*class
	Factory{
public:
	Factory();
	~Factory();

private:
};*/
