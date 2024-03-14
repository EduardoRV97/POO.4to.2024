#pragma once
#include "Prerequisitos.h"

//Manejador Base (Handle)
class Manejador {
public:
	Manejador(Manejador* siguiente) : m_siguienteManejador(siguiente) {}

	virtual void manejarSolicitud(int solicitud) {
		if (m_siguienteManejador!=nullptr) {
			m_siguienteManejador->manejarSolicitud(solicitud);
		}
	}
private:
	Manejador* m_siguienteManejador;
};

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