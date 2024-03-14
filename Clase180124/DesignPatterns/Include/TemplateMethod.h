#pragma once
#include "Prerequisitos.h"

//Clase base que define el template
//Se crean 3 funciones que se inicializan a partir del metodo jugar
//Estas se encuentran protegidas como metodos virtuales, y mostrando valores en pantalla
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
//La subclase ajedrez, que hereda de juego, sobrescribe la varible virtiual de comenzar juego, dandole un nuevo valor
class Ajedrez : public Juego {
protected:
	void comenzarJuego() override {
		cout << "Comenzar la partida de ajedrez" << endl;
	}
};
//SubClase Que implementa pasos especificos
//La subclase Monopoly, que hereda de juego, sobrescribe la varible virtiual de comenzar juego, dandole un nuevo valor
class Monopoly : public Juego {
protected:
	void comenzarJuego() override {
		cout << "Comenzar la partida de Monopoly" << endl;
	}
};