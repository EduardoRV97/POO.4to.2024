#pragma once
#include "Prerequisitos.h"

//Clase base que define el template

class Juego {
public: 
	void jugar() {
		inicializar();
		comenzarJuego();
		terminarJuego();
	}
protected:
	virtual void inicializar() {
		cout << "Iniciando el juego..." << endl;
	}
	virtual void comenzarJuego() = 0;

	virtual void terminarJuego() {
		cout << "Terminando el juego!!!!" << endl;
	}
};

//SubClase Que implementa pasos especificos

class Ajedrez : public Juego {
protected:
	void comenzarJuego() override {
		cout << "Comenzar la partida de ajedrez" << endl;
	}
};
//SubClase Que implementa pasos especificos

class Monopoly : public Juego {
protected:
	void comenzarJuego() override {
		cout << "Comenzar la partida de Monopoly" << endl;
	}
};