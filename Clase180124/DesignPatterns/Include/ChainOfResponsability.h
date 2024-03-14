#pragma once
#include "Prerequisitos.h"

//Manejador Base (Handle)
class Manejador {
	//Se inicializa la variable manejador
	//Se crea un metodo virtual que si la variable tiene valor nulo, manda una solicitud al siguiente manejador
public:
	Manejador(Manejador* siguiente) : m_siguienteManejador(siguiente) {}

	virtual void manejarSolicitud(int solicitud) {
		if (m_siguienteManejador!=nullptr) {
			m_siguienteManejador->manejarSolicitud(solicitud);
		}
	}
private:
	//Se crea un puntero del tipo de dato manejador
	Manejador* m_siguienteManejador;
};

//Se crearon 3 manejadores que iran escalando dependiendo de cual busquemos que sea el primero en actuar
// El manejador A hace una sobreescritura del metodo manejar solicitud y si el objeto tiene un valor menor o igual a 10, manda un mensaje.
// En caso de que no, manda la solitud al siguientemanejador, el cual es el B, donde es lo mismo pero ahora los valores que busca son menores a 20
// Para terminar en el manejar C, que maneja valores superiores a 20
//Manejador concreto A

class manejadorConcretoA : public Manejador {
public:
	manejadorConcretoA(Manejador* siguiente) :Manejador(siguiente) {}

	void manejarSolicitud(int solicitud) override {
		if (solicitud <= 10) {
			cout << "Manejador A ejecuta la solicitud." << endl;
		}
		else {
			Manejador::manejarSolicitud(solicitud);
		}
	}
};

//Manejador concreto B

class manejadorConcretoB : public Manejador {
public:
	manejadorConcretoB(Manejador* siguiente) :Manejador(siguiente) {}

	void manejarSolicitud(int solicitud) override {
		if (solicitud <= 20) {
			cout << "Manejador B ejecuta la solicitud." << endl;
		}
		else {
			Manejador::manejarSolicitud(solicitud);
		}
	}
};

//Manejador concreto C

class manejadorConcretoC : public Manejador {
public:
	manejadorConcretoC(Manejador* siguiente) :Manejador(siguiente) {}

	void manejarSolicitud(int solicitud) override {
		cout << "Manejador C ejecuta la solicitud" << endl;
	}
};