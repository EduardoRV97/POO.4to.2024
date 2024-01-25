#pragma once
#include "Prerequisitos.h"

class CuentaBancaria {
public:

	CuentaBancaria(string _propietario) : m_propietario(_propietario) {}
	~CuentaBancaria() {}

public:

	void Consulta() {
		cout << "El usuario " << m_propietario 
			<<" Tiene un saldo de " << saldo << endl;
	};

	void MostrarInteres() {
		interes();
	};

	void RealizarTransacciones() {
		Transacciones();
	};

private:

	string m_propietario;
	float saldo = 89;

private:

	void interes() {
		cout << " Tiene una tasa de interes del 2% " << endl
			<< "Por lo tanto debe pagar un total de " << saldo * 0.02 <<
			" en un plazo de 15 dias" << endl;
	}

protected:

	int n_cuenta = 1;

protected:

	void Transacciones() {
		cout << "Realizando transaccion en numero de cuenta " << n_cuenta << endl;
	};
};

class Rectangulo {

public:

	Rectangulo(int altura, int base) : altura(altura), base(base) {}

	~Rectangulo() {}

private:
	int base;
	int altura;

public:

	int FormulaP() {
		return (altura * base);
	}
};
class Estudiante {
public:
	Estudiante(string _nombre, int _edad, float _calificacion) : m_nombre(_nombre), m_edad(_edad), m_calificacion(_calificacion) {}
	~Estudiante() {}
private:
	string m_nombre;
	int m_edad;
	float m_calificacion;
public:
	void mostrarInformacion() {
		cout << "El nombre del estudiante es " << m_nombre << " , tiene un edad de " << m_edad << " Y su calificacion es de " << m_calificacion << endl;
	};
};

class Vehiculo {
public:
	Vehiculo(){}
	Vehiculo(string _modelo, int _año) : m_modelo(_modelo), m_año(_año){}
	~Vehiculo(){}
protected:
	string m_modelo;
	int m_año;
};

class Coche : public Vehiculo {
public:
	Coche(string _modelo, int _año, int _puertas) : Vehiculo(_modelo, _año),m_puertas(_puertas) {}
	~Coche(){}
private:
	int m_puertas;
public:
	void mostrarInformacionCoche() {
		cout << "El coche del modelo " << m_modelo << " del año " << m_año << ", tiene un total de " << m_puertas << "puertas." << endl;
	}
};