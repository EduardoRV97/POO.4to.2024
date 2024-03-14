#pragma once
#include "Prerequisitos.h"

// Interfaz del sujeto
//Se crea un metodo virtual llamado operacio con valor en 0
class Sujeto {
public:
	virtual void operacion() = 0;
};

//Sujeto real (Clase concreta)
//Se sobreescribe el metodo anterior en una clase que ha heredado de Sujeto
//Donde se incluira una impresion en pantalla
class SujetoReal : public Sujeto {
public: 
	void operacion() override {
		cout << "Operacin en el sujeto real. " << endl;
	}
};

//Proxy

class Proxy : public Sujeto {
	//Se incializa la variable con un valor en Nullptr
	//Se vuelve asobreescribir la funcion en la cual si el objeto es igual a nullptr, entoncrs creara uno nuevo y lo mostrara en pantalla, despues
	//mostrara un mensaje y volvera a repetir el metodo operacion
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
	//Se crea una variable privada del tipo Sujeto Real
private:
	SujetoReal* m_sujetoReal;
};