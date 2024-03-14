#include "Prerequisitos.h"
#include "Singleton.h"
#include "RegistroActividad.h"
#include "FactoryMethos.h"
#include "Vehiculo.h"
#include "Builder.h"
#include "Pizza.h"
#include "Prototype.h"
#include "Documento.h"
#include "Composite.h"
#include "Archivo.h"
#include "Proxy.h"
#include "Imagen.h"
#include "Bridge.h"
#include "ChainOfResponsability.h"
#include "ChainOfResponsabilityAct.h"
#include "TemplateMethod.h"
#include "TemplateMethodAct.h"

//Mutex y Threads
#include <thread>
#include <mutex>

Singleton* Singleton::instance = nullptr;
RegistroActividad* RegistroActividad::instancia = nullptr;
mutex mtx;

void Hilo(int id) {
	for (int i = 0; i < 5; i++) {
		mtx.lock();//Bloquear el thread
		cout << "Hilo: " << id << " esta trabajando." << endl;
		mtx.unlock();// Desbloquear el thread
	}
}

int main() {
	// Singleton
	Singleton* s1 = Singleton::getInstancia();
		s1->setValue(42);

		Singleton* s2 = Singleton::getInstancia();
		cout << "Datos en Singleton 2: " << s2->getValue() << endl;
		cout << "Datos de la instancia: " << Singleton::getInstancia()->getValue() << endl;

	//-------Registro de actividad
	RegistroActividad* a1 = RegistroActividad::getInstancia2();
	a1->setLog("Buenos dias, bienvenido al mundo espacial");
		RegistroActividad* a2 = RegistroActividad::getInstancia2();
		RegistroActividad* a3 = RegistroActividad::getInstancia2();
		a3->setLog("Padrisimo");
		//vector<string> Chat = a2->getLog();
		cout << "Ingresando al mundo virtual..." << endl;
		for (const auto& chats : a2->getLog()) {
			cout << chats << endl;
		}
	//Factory Method con vector
		FMFabrica* fabrica = new FMFabricaConcreta();
		FMPRoducto* producto = fabrica->crearProducto();
		FMPRoducto* product2 = fabrica->crearProducto();
		vector<FMPRoducto*> productos;
		productos.push_back(producto);
		productos.push_back(product2);
		

	//Cheetos

		FMPRoducto* chettos = fabrica->crearPapas();
		chettos->registrar("Torciditos", 35.8f, 17.5f);
		productos.push_back(chettos);

		for (FMPRoducto* producto : productos) {
			producto->operacion();
		}
	//Borrar datos en memoria

	for (FMPRoducto* P : productos) {
			delete P;
		}
	delete fabrica;

	//------Actividad de Vehiculo

	FactorialVehiculos* factorialVehiculo = new FactorialVehiculosConcreta();
	FMVehiculo* coche = factorialVehiculo->crearCoches();
	coche->descripcion();
	delete coche;
	delete factorialVehiculo;

	//Builder

	Builder* builder = new BuilderConcreto();
	Director director(builder);
	director.construir();

	BProducto* bProducto = builder->obtenerProducto();
	bProducto->mostrar();

	delete builder;
	delete bProducto;

	//Builder Pizza

	PizzaBuilder* pizza1 = new ConstructorPizzaHawaiana();
	PizzaBuilder* pizza2 = new ConstructorPizzaVegetariana();
	Director2 director1(pizza1);
	director1.construir();
	Director2 director2(pizza2);
	director2.construir();

	Pizza* piza1 = pizza1->obtenerPizza();
	Pizza* piza2 = pizza2->obtenerPizza();
	piza1->mostrar();
	piza2->mostrar();

	delete pizza1;
	delete pizza2;
	delete piza1;
	delete piza2;

	//Prototype

	Prototype* prototipo = new PrototypeConcreto();
	prototipo->configurar("Hola soy un ejemplo");
	
	Prototype* copia = prototipo->clonar();
	prototipo->mostrar();
	copia->mostrar();

	delete prototipo;
	delete copia;

	//Prototipo Documento ejercicio

	DocumentoPrototype* prototipoTexto = new DocumentoTexto();
	prototipoTexto->configurar("Texto de ejemplo");
	
	DocumentoPrototype* prototipoImagen = new DocumentoImagen();
	prototipoImagen->configurar("imagen.png");

	DocumentoPrototype* copiaTexto = prototipoTexto->clonar();
	DocumentoPrototype* copiaImagen = prototipoImagen->clonar();

	copiaTexto->configurar("Texto Modificado");
	copiaImagen->configurar("nueva imagen.png");

	prototipoTexto->configurar("Texto original");
	prototipoImagen->configurar("Imagen Original.png");

	prototipoTexto->clonar()->mostrar();
	copiaTexto->mostrar();

	prototipoImagen->clonar()->mostrar();
	copiaImagen->mostrar();

	delete prototipoTexto;
	delete prototipoImagen;
	delete copiaImagen;
	delete copiaTexto;
	
	//composite
	Leaf* leaf1 = new Leaf();
	Leaf* leaf2 = new Leaf();

	Compuesto* compuesto = new Compuesto();
	compuesto->agregarLeaf(leaf1);
	compuesto->agregarLeaf(leaf2);

	compuesto->operacion();

	delete leaf1;
	delete leaf2;
	delete compuesto;

	// Ejemplo compuesto

	SistemaArchivo* archivo1 = new SistemaArchivo();
	SistemaArchivo* archivo2 = new SistemaArchivo();
	SistemaCarpeta* carpeta = new SistemaCarpeta();
	carpeta->agregarSistema(archivo1);
	carpeta->agregarSistema(archivo2);

	carpeta->mostrarInfo();
	delete archivo1;
	delete archivo2;
	delete carpeta;

	//Proxy

	Proxy proxy;
	//El objeto real solo se crea cuando se llama a la operacion
	proxy.operacion();
	proxy.operacion();

	//Actividad Proxy

	ProxyImagen proxys;
	proxys.mostrar();
	proxys.mostrar();

	// Bridge

	ImplementacionConcretaA impA;
	ImplementacionConcretaB impB;

	AbstraccionRefinada ARA(&impA);
	AbstraccionRefinada ARB(&impB);

	ARA.operacion();
	ARB.operacion();

	//Chain of Responsability

	manejadorConcretoC handleC(nullptr);
	manejadorConcretoB handleB(&handleC);
	manejadorConcretoA handleA(&handleB);

	handleA.manejarSolicitud(50);
	handleA.manejarSolicitud(5);
	handleA.manejarSolicitud(15);
	handleA.manejarSolicitud(19);
	handleA.manejarSolicitud(3);

	//Chains of responsability Actividad

	manejadorDirectorGeneral directorGeneral(nullptr);
	manejadorGerente gerente(&directorGeneral);
	manejadorDirectivo directivo(&gerente);
	directivo.getMonto(800);
	directivo.getMonto(3500);
	directivo.getMonto(10000);

	// Template Method

	Juego* juego1 = new Ajedrez();
	Juego* juego2 = new Monopoly();

	juego1->jugar();
	juego2->jugar();

	delete juego1;
	delete juego2;

	// Actividad de Template Method

	Refrigerador* refri1 = new RefrigeradorSamsung;
	Refrigerador* refri2 = new RefrigeradorLG;
	refri1->jugar();
	refri2->jugar();
	delete refri1;
	delete refri2;

	//Mutex

	thread hilo1(Hilo, 1);
	thread hilo2(Hilo, 2);
	thread hilo3(Hilo, 3);
	

	hilo1.join();
	hilo2.join();
	hilo3.join();
	cout << "\n--- Ejecucion 1 entre hilos" << endl;
	cout << "\n--- Ejecucion 2 entre hilos" << endl;
	cout << "\n--- Ejecucion 3 entre hilos" << endl;

	return 0;
}


/*Singleton
* Patron: Variables constantes que se veran identificadas en un conjuntto de datos
* Instancia: Una copia de un objeto, es mas practico que usar un objeto
* El patron Singleton se utiliza para garantizar que una clase tenga una unica insancia y proporcionar un punto
*	de acceso global a esa instancia. Es util en situaciones en las que solo debe haber una instancia de una clase en todo el programa
* 
* Constructor Privado: El constructor de la clase se declara como privado, lo que impide que se cree
* una instancia directamente desde fuera de la clase
* 
* Metodo Estatico de Acceso: Se proporciona un metodo estatico que actua como punto de acceso a la instancia unica de la clase.
* Este metodo crea la instancia si aun no existe y la devuelve
* 
* Instancia EStatica: La instancia de la clase se declara como una variable estatica dentro de la clase.
* Esto asegura que soo haya una instancia en todo el programa
* 
* Usos Comunes del Singleton
* 
* Configuracion Global: El singleton puede utilizarse para mantener configuraciones globales accesible desde cualquier parte del programa
* Registro de actividades: Puedes usar un Singleton para llevar un registro de actividad en toda la aplicacion
* Conexiones a base de datos: Util para garantizar que solo haya una conexion a la base de datos en todo el programa
* 
* 
* Factory Method
* EL patron Factory Method es una tecnica de diseño que se utiliza para crear objetos
* sin especificar la clase exacta de objeto que se creara
* En cambio, se define una interfaz que declara un metodo, generalmente llamda factoria, que se utiliza para crear objetos
* 
* El Factory Methos es util cuando una clase no no puede anticipar la clase de objetos que debe crear. 
* Proporciona una interfaz para crear objetos en una clase base, pero permite a las subclases alterar el tipo de objetos que se crean
* 
* Usos comunes: 
* -Cuando una clase no puede anticipar la clase de objetos que debe crear
* -Cuando una clase quiere delegar la responsabildiad de la creacion de objetos a sus subclases
* -Cuando una clase necesita sustraer los detalles de la implementacion de la creacion de objetos
* 
* Builder
* 
* EL potron Builder se utiliza para crear obejtos complejos paso a paso. Proporciona una manera de construir un objeto
* con diferentes tipos o representaciones, mientras mantiene un proceso de construccion constante
* 
* El patron Builder es util cuando un objeto tiene uns construccion compleja y quieres separar el prodeso de construccion del objeto final
* En lugar de crear el objeto directamente, utilizas una clase "director" que coordina el proceso de construccion a traves de una serie de "constructores"
* 
* Usos comunes del Builder
* 
* 1.- Cuando un objeto tiene una construccion compleja y quieres separar el proceso de constraccion del objeto final
* 2.- Para crear objetos con multiples configuraciones posibles
* 3.-Cuando deseas evitar un constructor con muchos parametros opcionales
* 
* (Back4Blood) Ejemplo de uso
*
*
* Prototype (Game Programin Patern)
* 
* El patron prototype se utiliza para crear nuevos objetos duplicando un objeto existente(prototipo) sin depender de sus clases concretas
* Es util cuando la creacion de un objeto es mas eficiente copiando un ibjeto existente que construyendolo desde cero
* 
* El patron prototype se basa en la idea de un objeto prototipo que sirve como modelo para crear nuevos objeto objetos.
* El nuevo objeto se crea copiando el prototipo. Esto permite la creacion de objetos sin conocer sus clases concretas.
* 
* Usos comunes:
* 1.- Cuando la creacion de un objetos es mas eficiente copiando un objeto existente que construyendolo desde cero
* 2.- Para evitar la duplicacion de codigo al crear objetos similares
* 3.-Cuando deseas desacoplar la clase que utiliza el objeto de tipo concreto del objeto
*
*
* 
* Composite
* 
* 
* El patron Composite se utiliza para crear estructuras de arbpl que representan jerarquias de objetos. Permite
* a los clientes tratar objetos individuales y composiciones de objetos de la misma manera.
* 
* Uso comun del composite
* -Cuando necesitas representar jerarquias de objetos en una estructura de arbol
* -Para trata objetos individuales y composiciones de objetos de la misma manera
* -Para implementar estructuras de arbol de manera eficiente
* 
* El patron Composite se basa en la idea de que los obejtos individuales y las composiciones de objetos(contenedores) deben ser tratados de manera uniforme
* La estructura de arbol se compone de nodos hoja (objetos individuales) y nodos compuestos (contenedores)
* 
* 
* Proxy
* 
* 
* El patron Proxy se utiliza para controlar el acceso a un objeto, agregar funionalidad adicional o restringir el acceso de un clinte a un objeto real
* Actua como una interfaz intermedia entre el cliente y el objeto real
* 
* El patron Proxy se basa en la idea de que un objeto real puedes ser costoso de crear o utilizar, y a menudo se necesita un control adicional sobre su acceso.
* El Proxy actua como una interfaz intermedia que se encarga de la creacion y gestion del objeto real.
* 
* Usos comunes del Proxy
* -Cuando deseas controlar el acceso a un objeto
* -Para restringir el acfeso a un objeto real, por ejemplo, implementando autenticacion o autorizacion
* -Para agregar funcionalidad adicional, como el registro o la gestion de recursos, al objeto real.
* -Para evitar la creacion costosa de un objeto real hasta que sea necesario
* 
* 
* Bridge
* 
* 
* El patron bridge se utiliza para separar una abstraccion de su implementacion. Esto permite que ambas partes
* evolucionen de forma inpendiente y se combinen de manera flexible
* 
* Usos comunos del bridge
* -Cuando necesitas separar una abstraccion de su implementacion
* -Para permitir cambios independientes en ambas partes
* -Para combinar abstracciones y diferentes implementacions de manera flexible
* -Cuando tienes multiples dimensiones de variacion en tu sistema
* 
* El patron bridge se basa en la idea de que una clase puede tener dos jerarquias separadas, una para la abstraccion y otra para la implementacion. 
* La abstraccion se comunica con le implementacion a traves de un ibjeto de implementacion
* 
* 
* Chains of Responsability
* 
* 
* El patron Chain of Responsability se utiliza para crear una cadena de manejadores que procesan una solicitud de manera flexible.
* Cada manejador decide si procesa la solicitud o la pasa al siguiente manejador del sistema
* 
* Usos comuns del chain of responsability
* -Cuando tienes multiples objetos qu pueden manejar una solicitud y quieres evitar acopamiento fuertes entre el cliente y los manejadores
* -Cuando quieres permitir que los objetos que manejan la solicitud varien de manera dinamica
* -Para implementar un flujo de trabajo donde diferentes etapas pueden manejar diferentes aspectos de una solicitud.
* 
* El patron chain of responsability se basa en la idea de que una solicitud debe ser manejada por uno o mas objetos, pero el cliente no necesita saber cual de ellos la manejara.
* Crea una cadena de manejadores y cada manejador decide si procesa la solictud o la pasa al siguiente manejador
* 
* 
* Template Method
* 
* 
* El patron Template Mehthod se utiliza para definir la estructura general de un algoritmo en una clase base, permitiendo
* que las subclases implementen pasos especificos de ese algoritmo
* 
* Usos Comunes del Template Method
* 
* --Cuando tienes un algoritmo con una estructura general, pero pasos especificos que puede variar
* --Para evitar duplicacion de codigo al definir una estructura general en una clase base y permitir que las subclases implementen pasos especificos
* 
* El patron Template Method se basa en la idea de que un algoritmo puede tener una estructura general con pasos especificicos que pueden varior.
* Se define un metodo "Plantilla" en una clase base que llama a metodos abstractos que deben ser implementados por subclases.
* 
* 
* Mutex (Exclusion mutua)
* 
* 
* Un mutex es una herramienta critica en la programacion multi-hilo que garantiza que solo un hilo acceda a un recurso compartido a la vez
* Esto evita problemas de concurrencia y asegura que los datos compartidos no se corrompan
* 
* Usos comunes en Mutex
* 
* -Evitar problemas de concurrencia en programas multi-hilo
* -Proteger el acceso a recursos compartidos, como estructuras de datos, archivos, bases de datos y etc
* -Garantizar que solo un hilo pueda modificar un recurso a la vez
* 
* Un mutex(Exlusion mutua) es un objeto que actua como una semaforo para controlar el acceso a un recurso compartido en un programa multi-hilo.
* Proporciona bloqueo y desbloqueo para garantizar que solo un hilo pueda acceder al recurso compartido a la vez
*/