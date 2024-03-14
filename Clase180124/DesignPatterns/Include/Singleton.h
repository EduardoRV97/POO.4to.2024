#pragma once
class Singleton {

private:
	Singleton() : value(0) {};
public:
	~Singleton();
	//Punto de acceso a la instancia unica de la clase
	//Este metodo crea una instancia si aun no existe y si no, regresa la existente
	static Singleton* 
		getInstancia() {
		if (instance != nullptr) {
			return instance;
		}
		else {
			instance = new Singleton;
			return instance;
		}
 }
	void setValue(int _value) {
		value = _value;
	}

	int getValue() {
		return value;
	}
private:
	static Singleton* instance;
	int value;
};


