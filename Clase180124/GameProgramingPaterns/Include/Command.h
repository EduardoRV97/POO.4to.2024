#pragma once
#include "Prerequisitos.h"

//Interfaz comando
class Comando {
public:
	virtual void ejecutar() = 0;//Ejecucion del comando
	virtual void deshacer() = 0;//Deshacer el comando, y vuelve al estado anterior
};

//Clase Receptora
class Luz { 
public:
	void encender() { //Funcion que prende la luz
		cout << "Luz Encendida." << endl;
	}
	void apagada() {//Funcion que apagada la lux
		cout << "Luz Apagada." << endl;
	}
};

// Comando concreto de encender la luz
class comandoEncender :public Comando {
public:
	//Se inicializa la variable del tipo Luz en el constructor
	comandoEncender(Luz& luz) : m_Luz(luz) {}
	void ejecutar() override { //Se sobreescribe el comando ejecutar, para que la variable encienda
		m_Luz.encender();
	}
	void deshacer() override {//Se sobreescribe el comando deshacer, para que la variable apage
		m_Luz.apagada();
	}
private:
	Luz& m_Luz; //Se declara una variable del tipo Luz
};

// Comando concreto de apagar la luz
class comandoApagar :public Comando {
public:
	comandoApagar(Luz& luz) : m_Luz(luz) {}
	void ejecutar() override {//Se sobreescribe el comando ejecutar, para que la variable apage
		m_Luz.apagada();
	}
	void deshacer() override {//Se sobreescribe el comando deshacer, para que la variable encienda
		m_Luz.encender();
	}
private:
	Luz& m_Luz;//Se declara una variable del tipo Luz
};

// Invocador 

class controlRemoto {
public: 
	//Se declara una funcion que al presionar un boton ejecuta un comando. y guarda ese comando en el historial
	void presionarBoton(Comando* comando) {
		comando->ejecutar();
		m_historial.push_back(comando);
	}
	//Funcion que revisa si el historial no esta vacio, si no lo esta entonces saca el ultimo elemento y ejecuta
	//el comando deshacer y luego muestra el resultado.
	void deshacerC() {
		if (!m_historial.empty()) {
			m_historial.back()->deshacer();
			m_historial.pop_back();
		}
	}
private:
	//Se declara un vector del tipo Comando, donde guardaremos el historial
	vector<Comando*> m_historial;
};

//Actividad Command

class Comandos {
public:
	virtual void ejecutar() = 0;//Ejecucion del comando
	virtual void deshacer() = 0;//Deshacer el comando, y vuelve al estado anterior
};

//Clase Receptora
class Operacion {
public:
	void Suma() { 
		num += 1;
		cout << "Valor: " << num << endl;
	}
	void Resta() {
		num -= 1;
		cout << "Valor: " << num << endl;
	}
	void Multiplicacion() {
		num *= 2;
		cout << "Valor: " << num << endl;
	}
	void Division() {
		num /= 2;
		cout << "Valor: " << num << endl;
	}
private:
	float num=0;
};

class OperacionessSum :public Comandos {
public:
	
	OperacionessSum(Operacion& operaciones) : m_operaciones(operaciones) {}
	void ejecutar() override { 
		m_operaciones.Suma();
	}
	void deshacer() override {
		m_operaciones.Resta();
	}
private:
	Operacion& m_operaciones;
};

class OperacionessRes :public Comandos {
public:
	
	OperacionessRes(Operacion& operaciones) : m_operaciones(operaciones) {}
	void ejecutar() override { 
		m_operaciones.Resta();
	}
	void deshacer() override {
		m_operaciones.Suma();
	}
private:
	Operacion& m_operaciones;
};

class OperacionessMul :public Comandos {
public:
	
	OperacionessMul(Operacion& operaciones) : m_operaciones(operaciones) {}
	void ejecutar() override { 
		m_operaciones.Multiplicacion();
	}
	void deshacer() override {
		m_operaciones.Division();
	}
private:
	Operacion& m_operaciones;
};

class OperacionessDiv :public Comandos {
public:
	
	OperacionessDiv(Operacion& operaciones) : m_operaciones(operaciones) {}
	void ejecutar() override { 
		m_operaciones.Division();
	}
	void deshacer() override {
		m_operaciones.Multiplicacion();
	}
private:
	Operacion& m_operaciones;
};

class Calculadora {
public:
	void presionarBoton(Comandos* comando) {
		comando->ejecutar();
		m_guardado.push_back(comando);
	}
	void deshacerC() {
		if (!m_guardado.empty()) {
			m_guardado.back()->deshacer();
			m_guardado.pop_back();
		}
	}
private:
	vector<Comandos*> m_guardado;
};