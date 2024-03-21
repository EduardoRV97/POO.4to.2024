#pragma once
#include "Prerequisitos.h"

// Clase que representa la parte compartida del objeto

class Flyweight {
public:
	virtual void draw(int x, int y) = 0;
};

//Clase concreta que representa el objeto que se comparte
class ConcreteFlyweight : public Flyweight {
public:
	ConcreteFlyweight(char _symbol) : symbol(_symbol) {}

	void draw(int x, int y) override {
		cout << "Dibujando " << symbol << " en la posicion (" << x << ", " << y << ")" << endl;
	}
private:
	char symbol;
};

//Fabrica que gestionara la creacion de recursos

class FlyweightFactory {
public:
	Flyweight* getFlyweight(char symbol) {
		if (flyweights.find(symbol) == flyweights.end()) {
			flyweights[symbol] = new ConcreteFlyweight(symbol);
		}
		return flyweights[symbol];
	}

private:
	unordered_map<char, Flyweight*> flyweights;
};