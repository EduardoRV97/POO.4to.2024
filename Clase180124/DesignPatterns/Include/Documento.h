#pragma once
#include "Prerequisitos.h"

//Clase base para los prototipos

class DocumentoPrototype {
public:
	virtual DocumentoPrototype* clonar() = 0;
	virtual void configurar(string _contenido) = 0;
	virtual void mostrar() = 0;
};

//Clase concreta de Texto
class DocumentoTexto : public DocumentoPrototype {
public:
	DocumentoPrototype* clonar() override 
	{
	DocumentoTexto* copia = new DocumentoTexto();
	copia->configurar(contenido);
	return copia;
	}

	 void configurar(string _contenido) override {
		  contenido = _contenido;
	  }

	 void mostrar() override {
		  cout << "El texto es:  " << contenido << endl;
	  }

private:
	string contenido;
};

//Clase concreta de Imagen

class DocumentoImagen : public DocumentoPrototype {
public:
	DocumentoPrototype* clonar() override 
	{
	DocumentoImagen* copia = new DocumentoImagen();
	copia->configurar(contenido);
	return copia;
	}

	 void configurar(string _contenido) override {
		  contenido = _contenido;
	  }

	 void mostrar() override {
		  cout << "El texto es:  " << contenido << endl;
	  }

private:
	string contenido;
};


