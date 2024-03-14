#pragma once
class Singleton {
//Se agrega un valor privado con valor 0
private:
	Singleton() : value(0) {};
public:
	~Singleton();
	//Punto de acceso a la instancia unica de la clase
	//Este metodo crea una instancia si aun no existe y si no, regresa la existente
	static Singleton* //Si ya existe una instancia generada y tiene el valor null pointer, creada una instancia nueva, en caso contrario solo regresara el valor de la instancia
		getInstancia() {
		if (instance != nullptr) {
			return instance;
		}
		else {
			instance = new Singleton;
			return instance;
		}
 }
	void setValue(int _value) {//Funcion para definir los valores 
		value = _value;
	}

	int getValue() {//Funcion para obtener los valores
		return value;
	}
	//Variables privadas del tipo Singleton e int
private:
	static Singleton* instance;
	int value;
};


