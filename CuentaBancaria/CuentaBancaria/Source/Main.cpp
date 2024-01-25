// Acceso publico, protegido y privado de variables y metodos.
// Hay 3 niveles de acceso, publicos, protegidos y privados
// El acceso publico, son los miembros declarados como publicos son accesibles desde cualquier parte del programa
// Acceso protegido los miembros declarados como protegidos son accesibles solo dentro de la clase y sus clase derivadas. No pueden ser accedidos desde fuera
// Acceso privado, los miebros declarados como proivados son inaccesibles desde fuera de la clase. Solo la propia clase puede acceder a ellos.


#include"Prerequisitos.h"
#include "Cuerpo.h"

int main() {
	CuentaBancaria CuentaBancaria("Eduardo");
	CuentaBancaria.Consulta();

	CuentaBancaria.MostrarInteres();

	CuentaBancaria.RealizarTransacciones();

	int a, b;

	cout << "Cual es el area del cuadrado " << endl;
	cin >> a;
	cout << "Cual es la base del cuadrado " << endl;
	cin >> b;
	Rectangulo Area(a, b);

	int Areaa = Area.FormulaP();
	
	cout << "El valor del area es " << Areaa << endl;

	return 0;
}