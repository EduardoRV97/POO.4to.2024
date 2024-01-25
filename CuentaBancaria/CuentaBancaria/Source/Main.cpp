// Acceso publico, protegido y privado de variables y metodos.
// Hay 3 niveles de acceso, publicos, protegidos y privados
// El acceso publico, son los miembros declarados como publicos son accesibles desde cualquier parte del programa
// Acceso protegido los miembros declarados como protegidos son accesibles solo dentro de la clase y sus clase derivadas. No pueden ser accedidos desde fuera
// Acceso privado, los miebros declarados como proivados son inaccesibles desde fuera de la clase.
// Solo la propia clase puede acceder a ellos.
// Pilares del uso de punteros:
// 1.- Gestion dinamica de la memoria
// 2.- Argumentos en metodos
// 3.- Trabajar con estrcuturas de datos complejos
// 4.- Eficiencia y manipulacion directa de memoria
// 5.- Arreglos Dinamicos

#include "Prerequisitos.h"
#include "Cuerpo.h"
#include "Persona.h"

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

	Persona* persona = new Persona("Roberto", 25);
	persona->print();

	Persona* persona2 = new Persona(&persona[0]);
	persona2->print();

	Persona persona4 = new Persona("Jose",27);
	persona4.print();

	Persona persona3 = new Persona(persona4);
	persona3.print();

	delete persona;
	delete persona2;
	//delete persona3;

	const int numEstudiantes = 3;
	Estudiante** estudiantes = new Estudiante * [numEstudiantes];

	estudiantes[0] = new Estudiante("Camila", 21, 90.85);
	estudiantes[1] = new Estudiante("Pepe", 34, 76.56);
	estudiantes[2] = new Estudiante("Eduardo", 67, 67.56);

	for (int i = 0; i < numEstudiantes; ++i) {
		estudiantes[i]->mostrarInformacion();
	}

	for (int i = 0; i < numEstudiantes; ++i) {
		delete estudiantes[i];
	}

	delete[] estudiantes;

	Coche miCoche("Carrito", 2024, 4);
	miCoche.mostrarInformacionCoche();

	return 0;
}