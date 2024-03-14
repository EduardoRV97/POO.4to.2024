#pragma once
#include "Prerequisitos.h"

class RegistroActividad {
private:
	RegistroActividad() : log() {};
public:
	~RegistroActividad();
	static RegistroActividad*
		getInstancia2() {
		if (instancia != nullptr) {
			return instancia;
		}
		else {
			instancia = new RegistroActividad;
			return instancia;
		}
	}
	void setLog(string nuevoLog) {
		log.push_back(nuevoLog);
	}
	vector<string> getLog() {
		return log;
	}
private:
	static RegistroActividad* instancia;
	vector<string> log;
};
