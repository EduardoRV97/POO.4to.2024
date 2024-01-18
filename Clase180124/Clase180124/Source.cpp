#include "Prerequisitos.h"
#include "Coche.h"
#include <vector>

int main() {
	Coche ford("Ford", "Focus", 2022);
	ford.obtenerInformacion();
	cout << ford.getMarca() << endl;

	Circulo miCirculo(5);

	miCirculo.obtenerInformacion();
	cout << miCirculo.getArea() << endl;
	cout << miCirculo.getPerimetro() << endl;

	
	Estudiante miEstudiante[3] = {Estudiante("Eduardo", 26),Estudiante("Pepe", 27),Estudiante("Pedro", 28) };
	vector<Estudiante>miEstudiante;
	miEstudiante.push_back(Estudiante("Eduardo", 26));

	for (int i = 0; i < 3; i++) {
		miEstudiante[i].obtenerInformacion();
	}

	return 0;
}