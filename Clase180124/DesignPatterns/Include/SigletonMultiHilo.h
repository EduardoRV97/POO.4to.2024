#pragma once
#include "Prerequisitos.h"
#include <thread> //Libreria Thread
#include <mutex> // Libreria mutex
class SigletonMultihilo
{
private:
	//El costructor es privado para evitar instanciaciones externas a la clase
	SigletonMultihilo() = default;
public:
	static SigletonMultihilo& getInstance() {
		//Verificar si la instancia ya existe antes de bloquearlo
		if (m_instance == nullptr) {
			lock_guard<mutex> lock(m_mutexInstance);
			if (m_instance == nullptr) {
				m_instance = new SigletonMultihilo;
			}
		}

		return *m_instance;
	}

	void setValue(int _value) {//Funcion para definir los valores 
		m_value = _value;
	}

	int getValue() {//Funcion para obtener los valores
		return m_value;
	}
private:
	static SigletonMultihilo* m_instance;
	static mutex m_mutexInstance;
	int m_value;
};

class Configuracion {
private:
	Configuracion() = default;
public:
	static Configuracion& getInstance() {
		if (m_instance == nullptr) {
			lock_guard<mutex> lock(m_mutexInstance);
			if (m_instance == nullptr) {
				m_instance = new Configuracion;
			}
		}
		return *m_instance;
	}

void setValue(string& _value) {//Funcion para definir los valores 
		m_value = _value;
	}

string getValue() {//Funcion para obtener los valores
		return m_value;
	}
private:
	static Configuracion* m_instance;
	static mutex m_mutexInstance;
	string m_value;
};
