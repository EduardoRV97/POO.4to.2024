#pragma once
#include "Prerequisitos.h"

//Clase base de Vehiculo

class FMVehiculo {
public:
	virtual void descripcion() = 0;
};

//Clase base de Coche

class FMCoche : public FMVehiculo {
public:
	void descripcion() override {
		cout << "Soy un coche" << endl;
	}
};

//Clase base de Bicicleta

class FMBicicleta : public FMVehiculo {
public:
	void descripcion() override {
		cout << "Soy una bicicleta" << endl;
	}
};

//Clase base de la factorialVehiculos

class FactorialVehiculos {
public:
	virtual FMVehiculo* crearCoches() = 0;
	virtual FMVehiculo* crearBicicletas() = 0;
};

//Clase concreta de factorialVehiculos

class FactorialVehiculosConcreta : public FactorialVehiculos {
public:
	FMVehiculo* crearCoches() override {
		return new FMCoche();
	}
	FMVehiculo* crearBicicletas() override {
		return new FMBicicleta();
	}
};


