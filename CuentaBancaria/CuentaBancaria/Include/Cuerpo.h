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

public : 

	Rectangulo(int altura, int base) : altura (altura), base(base) {}

	~Rectangulo() {}

private :
	int base;
	int altura;

public :

	int FormulaP() {
		return (altura * base);
	}
};