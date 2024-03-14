#pragma once
#include "Prerequisitos.h"

class Solicitud {
public:
	Solicitud(Solicitud* siguiente) : m_monto(siguiente) {}

	virtual void getMonto(int solicitud) {
		if (m_monto != nullptr) {
			m_monto->getMonto(solicitud);
		}
	};
private:
	Solicitud* m_monto;
};

class manejadorDirectivo : public Solicitud {
public:
	manejadorDirectivo(Solicitud* siguiente) :Solicitud(siguiente) {}

	void getMonto(int solicitud) override {
		cout << "El Directo Creativo esta revisando y confirmando el monto de " << solicitud << endl;
		if (solicitud < 1000) {
			cout << "El Directo Creativo La ha aceptado " << solicitud << endl;
		}
		else {
			cout << "El Directo Creativo esta revisando y confirmando el monto de " << solicitud << endl;
			Solicitud::getMonto(solicitud);
		}
	}
};

class manejadorGerente : public Solicitud {
public:
	manejadorGerente(Solicitud* siguiente) :Solicitud(siguiente) {}

	void getMonto(int solicitud) override {
		cout << "El Gerente en turno esta revisando y confirmando el monto de " << solicitud << endl;
		if (solicitud < 5000) {
			cout << "El Gerente en turno la ha acepto:  " << solicitud << endl;
		}
		else {
			cout << "El Gerente en turno lo ha rechazado, pasa al siguiente nivel" << endl;
			Solicitud::getMonto(solicitud);
		}
	}
};

class manejadorDirectorGeneral : public Solicitud {
public:
	manejadorDirectorGeneral(Solicitud* siguiente) :Solicitud(siguiente) {}

	void getMonto(int solicitud) override {
		cout << "El Gerente General esta revisando y confirmando el monto de " << solicitud << endl;
	}
};
