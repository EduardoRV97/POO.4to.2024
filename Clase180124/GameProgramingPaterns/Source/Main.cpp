#include "Prerequisitos.h"
#include "Command.h"
#include "FlyweightPattern.h"

int main() {
	/*  Patrones de programacion de videojuegos

	1.- Command

	- El patron de diseno Command es una forma de encapsular una solicitud como un objeto, lo que permite
	parametrizar clientes con operaciones, encolar solicitudes y admitir operaciones reversibles

	Usos Comunes del Patron Command

	-Interfaz de usuario en graficos computacionales
	-sistemas de menus y barras de herramientas
	-Implementacion de funciones deshacer y rehacer
	*/
	//Command

	Luz miLuz; //Se crea el objeto que tiene las propiedades de Luz
	comandoEncender encender(miLuz); //Se crea el objeto comando de encender
	comandoApagar apagar(miLuz);//Se crea el objeto comando de encender
	controlRemoto control; //Se crea el control de los comandos
	control.presionarBoton(&encender); //Se enciende
	control.presionarBoton(&apagar); //Se apaga
	control.deshacerC(); //Hace la ultima accion guardada

	//Actividad Comando

	Operacion operacion;
	OperacionessSum sum(operacion);
	OperacionessRes res(operacion);
	OperacionessMul mul(operacion);
	OperacionessDiv div(operacion);
	Calculadora calculadora;
	calculadora.presionarBoton(&sum);
	calculadora.presionarBoton(&sum);
	calculadora.presionarBoton(&sum);
	calculadora.presionarBoton(&res);
	calculadora.presionarBoton(&mul);
	calculadora.presionarBoton(&mul);
	calculadora.presionarBoton(&div);
	calculadora.deshacerC();

	/*
		FlyWeight

		Este patron es especialmente util cuando se trabaja con un gran numero de objetos que comparten
		propiedas comunes, permitiendo ahorrar memoria y mejorar el rendimiento

		El patron Flyweight dividde los objetos en dos partes:
		-Intrinseca:Cotneien el estado que es compatido entre varias instancias. Este estado es inmutable y no depende del contexto
		especifico de la instancia
		-Extrinseca:

		Estructura del Patron Flyweight
		-Flyweight
		-FlyweightConcreto
		-Factoria Flyweight
		-

		-
	*/
	//Flyweight
	FlyweightFactory factory;

	//Crear instancias compartidas de Flyweights
	Flyweight* flyA = factory.getFlyweight('A');
	Flyweight* flyB = factory.getFlyweight('B');
	Flyweight* flyC = factory.getFlyweight('C');
	Flyweight* flyD = factory.getFlyweight('D');
	Flyweight* flyE = factory.getFlyweight('A');
	

	//Utilizar las imstancias compartidas
	flyA->draw(1, 2);
	flyB->draw(2, 2);
	flyC->draw(3, 3);
	flyD->draw(4, 4);
	flyE->draw(5, 5);

	delete flyA;
	delete flyB;
	delete flyC;
	delete flyD;
}