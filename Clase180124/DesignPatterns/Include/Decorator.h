#pragma once
#include "Prerequisitos.h";

// Interfaz base
//Se crean un metodo virtual publico con valor en 0
class Componente {
public:
	virtual void operacion() = 0;
};

// Clase concreta
//Clase que hereda de componente, que tiene una sobrescritura publica del metodo operacion donde se muestran valores en pantalla
class ComponenteConcreto : public Componente {
public:
	void operacion() override {
		cout << "Operacion del componente concreto" << endl;
	}
};

// Decorador base
//Clase que hereda de componente, con una variable de tipo componente protegida, y su respectiva inicizalicion
class Decorator : public Componente {
public:
	Decorator(Componente* componente) : m_componente(componente) {}

protected:
	Componente* m_componente;
};
//Se crean dos decoradores concretos los cuales heredan del decorador, e inicializacion los valores del componente
// Despues hacen una sobreescritura del metodo operacion donde la varibale m_componente apunta al metodo y despues imprime un mensaje en pantalla
// Decorator concreto
class DecoratorConcretoA : public Decorator {
public:
	DecoratorConcretoA(Componente* componente) : Decorator(componente) {}

	void operacion() override {
		m_componente->operacion();
		cout << "Operacion del decorador A" << endl;
	}
};

// Otro Decorator concreto
class DecoratorConcretoB : public Decorator {
public:
	DecoratorConcretoB(Componente* componente) : Decorator(componente) {}

	void operacion() override {
		m_componente->operacion();
		cout << "Operacion del decorador B" << endl;
	}
};




// Componente base
class Cafe {
public:
	virtual void prepararCafe() = 0;
};

// Componente concreto
class Cafeteria : public Cafe {
public:
	void prepararCafe() override {
		cout << "Caf  preparado" << endl;
	}
};

// Decorador base
class Condimento : public Cafe {
protected:
	Cafe* cafeDecorado;
public:
	Condimento(Cafe* cafe) : cafeDecorado(cafe) {}
	virtual void prepararCafe() override {
		cout << "Caf  preparado con condimento" << endl;
	}
};

// Decorador concreto para Leche
class Leche : public Condimento {
public:
	Leche(Cafe* cafe) : Condimento(cafe) {}
	virtual void prepararCafe() override {
		cout << "Caf  preparado con leche" << endl;
	}
};

// Decorador concreto para Azucar
class Azucar : public Condimento {
public:
	Azucar(Cafe* cafe) : Condimento(cafe) {}
	virtual void prepararCafe() override {
		cout << "Caf  preparado con azucar" << endl;
	}
};
