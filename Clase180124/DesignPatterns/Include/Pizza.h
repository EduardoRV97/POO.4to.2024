#pragma once
#include "Prerequisitos.h"

//Clase de la pizza

class Pizza {
public:
	void agregarPasos(const string& _pasos) {
		pasos.push_back(_pasos);
	}

	void mostrar() {
		cout << "El proceso de pizza lleva el siguiente orden= ";
		for (const string& paso : pasos) {
			cout << paso << " ";
		}
		cout << endl;
	}
private:
		vector<string> pasos;
};

//Clase abstractar el constructor(builder)

class PizzaBuilder {
public:
	virtual void crearMasa() = 0;
	virtual void crearSalsa() = 0;
	virtual void crearQueso() = 0;
	virtual void crearIngredientes() = 0;
	virtual Pizza* obtenerPizza() = 0;

};

//Clase concreta de Pizza Hawaiana

class ConstructorPizzaHawaiana : public PizzaBuilder {
public:
	ConstructorPizzaHawaiana() {
		pizzaH = new Pizza();
	}

	void crearMasa() override {
		pizzaH->agregarPasos("110 gramos de masa para pizza-");
	}
	void crearSalsa() override {
		pizzaH->agregarPasos("130 gramos de salsa-");
	}
	void crearQueso() override {
		pizzaH->agregarPasos("100 gramos de queso-");
	}
	void crearIngredientes() override {
		pizzaH->agregarPasos("50 gramos de pina con 30 gramos de jamon");
	}
	Pizza* obtenerPizza() override{
		return pizzaH;
	}

private:
	Pizza* pizzaH;
};

//Clase concreta de Pizza Vegetariana

class ConstructorPizzaVegetariana : public PizzaBuilder {
public:
	ConstructorPizzaVegetariana() {
		pizzaV = new Pizza();
	}

	void crearMasa() override {
		pizzaV->agregarPasos("110 gramos de masa para pizza-");
	}
	void crearSalsa() override {
		pizzaV->agregarPasos("130 gramos de salsa-");
	}
	void crearQueso() override {
		pizzaV->agregarPasos("100 gramos de queso-");
	}
	void crearIngredientes() override {
		pizzaV->agregarPasos("20 gramos de pimiento, con 30 gramos de cebolla y 10 gramos de champi");
	}
	Pizza* obtenerPizza() override {
		return pizzaV;
	}

private:
	Pizza* pizzaV;
};

//Clase Director

class Director2 {
public:
	Director2(PizzaBuilder* _builder) : pizzabuilder(_builder) {}

	void construir() {
		pizzabuilder->crearMasa();
		pizzabuilder->crearSalsa();
		pizzabuilder->crearQueso();
		pizzabuilder->crearIngredientes();
	}
private:
	PizzaBuilder* pizzabuilder;
};