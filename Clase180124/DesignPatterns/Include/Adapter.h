#pragma once
#include "Prerequisitos.h";

// Interfaz vieja
//Se crea un metodo virtual publico con un mensaje que se imprime en pantalla
class InterfazVieja {
public:
    virtual void metodoViejo() {
        cout << "Metodo viejo llamado" << endl;
    }
};

// Interfaz vieja
//Se crea un metodo virtual publico con un mensaje que se imprime en pantalla
class InterfazNueva {
public:
    virtual void metodoNuevo() {
        cout << "Metodo nuevo llamado" << endl;
    }
};

// Adpatador que las conecta
//El adaptador hereda de la interfaz nueva, inicializa los valores de la variable m_interfazvieja que es un puntro privado del tipo interfazvieja
//Y sobreescribe los valores del metodo nuevo con un mensaje en pantalla y llamada al metodoviejo
class Adapter : public InterfazNueva {
public:
    Adapter(InterfazVieja* vieja) : m_interfazVieja(vieja) {}

    virtual void metodoNuevo() override {
        cout << "Adaptador llmado al metodo nuevo" << endl;
        m_interfazVieja->metodoViejo();
    }

private:
    InterfazVieja* m_interfazVieja;
};








// Clase Circulo
class Circulo {
public:
    void dibujarCirculo() {
        cout << "Circulo dibujado" << endl;
    }
};

// Clase Cuadrado
class Cuadrado {
public:
    void dibujarCuadrado() {
        cout << "Cuadrado dibujado" << endl;
    }
};

// Interfaz Dibujable
class Dibujable {
public:
    virtual void dibujar() = 0;
};

// Adaptador para Circulo
class CirculoAdapter : public Dibujable {
public:
    CirculoAdapter(Circulo* circulo) : m_circulo(circulo) {}
    void dibujar() override {
        m_circulo->dibujarCirculo();
    }

private:
    Circulo* m_circulo;
};

// Adaptador para Cuadrado
class CuadradoAdapter : public Dibujable {
public:
    CuadradoAdapter(Cuadrado* cuadrado) : m_cuadrado(cuadrado) {}
    void dibujar() override {
        m_cuadrado->dibujarCuadrado();
    }

private:
    Cuadrado* m_cuadrado;
};