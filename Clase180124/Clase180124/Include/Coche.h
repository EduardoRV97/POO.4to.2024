#pragma once
#include "Prerequisitos.h"

class Coche
{
public:
	Coche(string _marca, string _modelo, int _year)
		: m_marca(_marca), m_modelo(_modelo), m_year(_year) {}
	~Coche() {}

	void obtenerInformacion() {
		cout << "Marca: " << m_marca << "Modelo: " << m_modelo << " Year " << m_year << endl;
	}
	void setMarca(string _marca) {
		m_modelo = _marca;
	}
	void setModelo(string _modelo) {
		m_modelo = _modelo;
	}
	void setYear(int _year) {
		m_year = _year;
	}
	string getMarca() {
		return m_marca;
	}

	string getModelo() {
		return m_modelo;
	}
	int getYear() {
		return m_year;
	}
private:
	string m_marca;
	string m_modelo;
	int m_year;
};

class Circulo
{
public:
	Circulo(float _radio): m_radio(_radio) {}
	~Circulo() {}

	void obtenerInformacion() {
		cout << " El radio es: " << m_radio << endl;
	}
	int getRadio() {
		return m_radio;
	}
	double getArea() {

		return (m_radio * m_radio) * 3.1415;
	}
	double getPerimetro() {
		return 2 * 3.1416f * m_radio;
	}
private:
	float m_radio;
};

class Estudiante
{
public: 
	Estudiante(string _nombre, int _edad) : m_nombre(_nombre), m_edad(_edad) {}
	~Estudiante() {}

	void obtenerInformacion() {
		cout << "El alumno se llama " << m_nombre << " Y tiene la edad de " << m_edad << endl;
	}
	string getNombre() {
		return m_nombre;
	}
	int getEdad() {
		return m_edad;
	}
private:
	string m_nombre;
	int m_edad;
};