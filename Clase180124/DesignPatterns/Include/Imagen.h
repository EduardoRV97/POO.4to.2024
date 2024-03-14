#pragma once
#include "Prerequisitos.h"

class Image {
public: virtual void mostrar() = 0;
};

class Imagen : public Image{
public:
	void mostrar() override{
		cout << "Mostrando la imagen" << endl;
	}
};

class ProxyImagen : public Image {
public:
	ProxyImagen() : m_imagen(nullptr) {};

	void mostrar() override {
		if (m_imagen == nullptr) {
			m_imagen = new Imagen();
			cout << "Imagen creada" << endl;
		}
		cout << " Proxy analizand datos, moviendo a Imagen->" << endl;
		m_imagen->mostrar();
	}
private:
	Imagen* m_imagen;
};