#pragma once
#include "Prerequisitos.h"

// Interfaz del sujeto

class Sujeto {
public:
	virtual void operacion() = 0;
};

//Sujeto real (Clase concreta)

class SujetoReal : public Sujeto {
public: 
	void operacion() override {
		cout << "Operacin en el sujeto real. " << endl;
	}
};

//Proxy

class Proxy : public Sujeto {
public:
	Proxy() : m_sujetoReal(nullptr) {};

	void operacion() override {
		if (m_sujetoReal == nullptr) {
			m_sujetoReal = new SujetoReal();
			cout << "Se creo el objeto" << endl;
		}
		cout << "Operacion en el Proxy. Redirigiendo a sujeto real." << endl;
		m_sujetoReal->operacion();
	}
private:
	SujetoReal* m_sujetoReal;
};