#pragma once
#include "Prerequisitos.h"


class Sistema {
public:
	virtual void mostrarInfo() = 0;
};

class Archivo : public Sistema {
public:
	void mostrarInfo() override {
		cout << "Soy un archivo." << endl;
	}
};
class Carpeta : public Sistema {
public:
	void mostrarInfo() override {
		cout << "Soy una carpeta." << endl;
	}
};


class SistemaArchivo : public Archivo {
};

class SistemaCarpeta : public Carpeta {
public:
	void mostrarInfo() override {
		cout << "Hay un total de " << archivos.size() << " archivos." << endl;
		for (Sistema* archivo : archivos) {
			archivo->mostrarInfo();
		}
	}
	void agregarSistema(Sistema* _archivo) {
		archivos.push_back(_archivo);
	}
private:
	vector<Sistema*> archivos;
};


