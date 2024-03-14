#pragma once
#include "Prerequisitos.h"

//Clase base del refrigerador

class Refrigerador {
public:
	void jugar() {
		inicializar();
		encender();
		apagar();
	}
protected:
	virtual void inicializar() {
		cout << "Inicializando Refrigerador" << endl;
	}
	virtual void encender() = 0;

	virtual void apagar() {
		cout << "Apagando refrigerador..." << endl;
	}
};

class RefrigeradorSamsung : public Refrigerador {
protected:
	void encender() override {
		cout << "Encendiendo Samsung Refrigereitor" << endl;
	}
};
class RefrigeradorLG : public Refrigerador {
protected:
	void encender() override {
		cout << "Encendiendo LG Refrigereitor" << endl;
	}
};

