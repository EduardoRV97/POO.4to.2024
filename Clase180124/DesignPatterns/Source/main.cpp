#include "Prerequisitos.h" //Acceso a encabezado Prerequisitos
#include "Singleton.h" //Acceso a encabezado Singleton
#include "RegistroActividad.h"//Acceso a encabezado RegistroActividad(Actividad de Singleton)
#include "FactoryMethos.h"//Acceso a encabezado FactoryMethod
#include "Vehiculo.h"//Acceso a encabezado Vehiculo (Actividad Factory Method)
#include "Builder.h"//Acceso a encabezado Builder
#include "Pizza.h"//Acceso a encabezado Pizza (Actividad de builder)
#include "Prototype.h"//Acceso a encabezado Prototype
#include "Documento.h"//Acceso a encabezado Documento (Actividad de Prototype)
#include "Composite.h"//Acceso a encabezado Composite
#include "Archivo.h"//Acceso a encabezado Archivo (Actividad de Archivo
#include "Proxy.h"//Acceso a encabezado Proxy
#include "Imagen.h"//Acceso a encabezado Imagen (Actividad de Proxy)
#include "Bridge.h"//Acceso a encabezado Bridge
#include "ChainOfResponsability.h"//Acceso a encabezado ChainsOfResponsability
#include "ChainOfResponsabilityAct.h"//Acceso a encabezado ChainofResponsabilityAct, actividad de ChainsOfResponsability
#include "TemplateMethod.h"//Acceso a encabezado TemplateMethod
#include "TemplateMethodAct.h"//Acceso a encabezado TemplateMethodAct, Actividad de TemplateMethod
#include "Adapter.h"//Acceso a encabezado Adapter
#include "Decorator.h"//Acceso a encabezado Decorator
#include "SigletonMultiHilo.h"//Acceso a encabezado Sigleton Multihilo

SigletonMultihilo* SigletonMultihilo::m_instance = nullptr;
mutex SigletonMultihilo::m_mutexInstance;

Singleton* Singleton::instance = nullptr; //Se le da valor nulo a la instancia creada en singleton
RegistroActividad* RegistroActividad::instancia = nullptr; //Se le da valor nulo a la instancia creada por RegistroActividad
mutex mtx; //Variable del tipo Mutex

Configuracion* Configuracion::m_instance = nullptr;
mutex Configuracion::m_mutexInstance;

//Productor-Consumidor
queue<int> buffer;
mutex mtx1;
condition_variable cv;
const int bufferSize = 5;

void productor() {
	for (int i = 0; i < 10; i++) {
		unique_lock<mutex> lock(mtx1);
		cv.wait(lock, [] {return buffer.size() < bufferSize; });

		int dato = rand() % 100;
		buffer.push(dato);
		cout << "Productor: Producido " << dato << endl;
		lock.unlock();
		cv.notify_all();
	}
}

void consumidor(int id) {
	for (int i = 0; i < 10; i++) {
		unique_lock<mutex> lock(mtx1);
		cv.wait(lock, [] {return !buffer.empty(); });

		int dato = buffer.front();
		buffer.pop();
		cout << "Consumidort " << id << " consumio: " << dato << endl;
		lock.unlock();
		cv.notify_all();
	}
}

void Hilo3(int _id, string _val) {
	Configuracion& z = Configuracion::getInstance();
	z.setValue(_val);
	cout << "Se encuentra en proceso el id " << _id << endl;
}
void Hilo2(int _id, int _val) {
	SigletonMultihilo& s = SigletonMultihilo::getInstance();
	s.setValue(_val);
	//Realizar operaciones con la instancia del sigleton
	cout << "\nHilo " << _id << " acceiendo al SigletonMultihilo." << endl;
}

void Hilo(int id) {//Funcion que bloquea y desbloquea los hilos cada vez que corre una iteracion y muestra un mensaje
	for (int i = 0; i < 5; i++) {
		mtx.lock();//Bloquear el thread
		cout << "Hilo: " << id << " esta trabajando." << endl;
		mtx.unlock();// Desbloquear el thread
	}
}

int main() {
	// Singleton
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
	*/
	Singleton* s1 = Singleton::getInstancia();//Se crea una instancia del tipo Singleton llamada S1
		s1->setValue(42); // Se le da valor de 42

		Singleton* s2 = Singleton::getInstancia();//Se crea una instancia del tipo Singleton llamada S2
		cout << "Datos en Singleton 2: " << s2->getValue() << endl;//Se muestran valores en pantalla que son parte de la funcione getValue
		cout << "Datos de la instancia: " << Singleton::getInstancia()->getValue() << endl;//Se muestran valores en pantalla que son parte de la instancia generada junto con su metodo get value

	//-------Registro de actividad
	RegistroActividad* a1 = RegistroActividad::getInstancia2(); // Se crea una instancia del tipo RegistroActividad que se le dan los valores de la instancia generada
	a1->setLog("Buenos dias, bienvenido al mundo espacial");//Se define el contenido 
		RegistroActividad* a2 = RegistroActividad::getInstancia2();//Se crea una isntancia con el valore de la intstancia
		RegistroActividad* a3 = RegistroActividad::getInstancia2();//Se crea una isntancia con el valore de la intstancia
		a3->setLog("Padrisimo");//Al a3 se le agrega otra valor distinto
		//vector<string> Chat = a2->getLog();
		cout << "Ingresando al mundo virtual..." << endl;
		for (const auto& chats : a2->getLog()) { //Se muestran los valores en pantalla, usando a2 que toma los valores obtenidos en orden por el vector
			cout << chats << endl;
		}
	//Factory Method con vector
		/*Factory Method
			* EL patron Factory Method es una tecnica de diseño que se utiliza para crear objetos
			* sin especificar la clase exacta de objeto que se creara
			* En cambio, se define una interfaz que declara un metodo, generalmente llamda factoria, que se utiliza para crear objetos
			*
			* El Factory Methos es util cuando una clase no no puede anticipar la clase de objetos que debe crear.
			* Proporciona una interfaz para crear objetos en una clase base, pero permite a las subclases alterar el tipo de objetos que se crean
			*
			* Usos comunes :
		*-Cuando una clase no puede anticipar la clase de objetos que debe crear
			* -Cuando una clase quiere delegar la responsabildiad de la creacion de objetos a sus subclases
			* -Cuando una clase necesita sustraer los detalles de la implementacion de la creacion de objetos
			*/
		FMFabrica* fabrica = new FMFabricaConcreta(); //Se crea una nueva FMFrabrica
		FMPRoducto* producto = fabrica->crearProducto();//Se crea un nuevo producto, que se le asigna el valor de la fabrica que apunta a crearproducto()
		FMPRoducto* product2 = fabrica->crearProducto();//Se crea un nuevo producto, que se le asigna el valor de la fabrica que apunta a crearproducto()
		vector<FMPRoducto*> productos;//Se crea un vector que contendra a estos productos
		productos.push_back(producto);//Se llama al metodo pushback para mostrar el producto
		productos.push_back(product2);//Se llama al metodo pushback para mostrar el producto
		

	//Cheetos

		FMPRoducto* chettos = fabrica->crearPapas(); //Se crea un nuevo Producto que se le asigna el valor de el metodo crear papas
		chettos->registrar("Torciditos", 35.8f, 17.5f);//Se le asignan los valores
		productos.push_back(chettos);//Se ingresa el valor a un vector

		for (FMPRoducto* producto : productos) {//Un recorrido que muestra todos los valores en el vector
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
	/*Builder
		*
		* EL potron Builder se utiliza para crear obejtos complejos paso a paso.Proporciona una manera de construir un objeto
		* con diferentes tipos o representaciones, mientras mantiene un proceso de construccion constante
		*
		* El patron Builder es util cuando un objeto tiene uns construccion compleja y quieres separar el prodeso de construccion del objeto final
		* En lugar de crear el objeto directamente, utilizas una clase "director" que coordina el proceso de construccion a traves de una serie de "constructores"
		*
		*Usos comunes del Builder
		*
		*1. - Cuando un objeto tiene una construccion compleja y quieres separar el proceso de constraccion del objeto final
		* 2. - Para crear objetos con multiples configuraciones posibles
		* 3. - Cuando deseas evitar un constructor con muchos parametros opcionales
		*
		*(Back4Blood)Ejemplo de uso
		*/

	Builder* builder = new BuilderConcreto(); //Se crea un nuevo objeto del tipo Builder que se le asgina el valor del builder concreto
	Director director(builder);//Se crea el objeto director
	director.construir();//Se le da la instruccion de construir un producto

	BProducto* bProducto = builder->obtenerProducto();//Un objeto del tipo Producto se le asigna el valor creado por el builder
	bProducto->mostrar();//Se utiliza un metodo del producto que muestra el valor
	//Se borran os datos de memoria
	delete builder; 
	delete bProducto;

	//Builder Pizza
	//Se crean dos nuevos objetos del tipos Pizza builder, que contendran valores constructore respectivos
	PizzaBuilder* pizza1 = new ConstructorPizzaHawaiana();
	PizzaBuilder* pizza2 = new ConstructorPizzaVegetariana();
	//Se crearan los dos directores de cada pizza, y se le instruira para contruir su respectiva pizza
	Director2 director1(pizza1);
	director1.construir();
	Director2 director2(pizza2);
	director2.construir();
	//Se crean 2 objetos pizza que obtienen los valores creados por el Pizzabuilder
	Pizza* piza1 = pizza1->obtenerPizza();
	Pizza* piza2 = pizza2->obtenerPizza();
	//Se muestran los dos valores de cada objeto pizza
	piza1->mostrar();
	piza2->mostrar();
	//Se borran los datos de los builder y de los objetos pizza
	delete pizza1;
	delete pizza2;
	delete piza1;
	delete piza2;

	//Prototype
	/*Prototype(Game Programin Patern)
		*
		* El patron prototype se utiliza para crear nuevos objetos duplicando un objeto existente(prototipo) sin depender de sus clases concretas
		* Es util cuando la creacion de un objeto es mas eficiente copiando un ibjeto existente que construyendolo desde cero
		*
		* El patron prototype se basa en la idea de un objeto prototipo que sirve como modelo para crear nuevos objeto objetos.
		* El nuevo objeto se crea copiando el prototipo.Esto permite la creacion de objetos sin conocer sus clases concretas.
		*
		* Usos comunes :
		*1. - Cuando la creacion de un objetos es mas eficiente copiando un objeto existente que construyendolo desde cero
		* 2. - Para evitar la duplicacion de codigo al crear objetos similares
		* 3. - Cuando deseas desacoplar la clase que utiliza el objeto de tipo concreto del objeto
		*/
		// Se crea un nuevo objeto 'prototipo' del tipo PrototypeConcreto.
	Prototype* prototipo = new PrototypeConcreto();
	// Se configura el prototipo con un mensaje inicial.
	prototipo->configurar("Hola soy un ejemplo");

	// Se clona el prototipo para crear un nuevo objeto copia con los mismos datos.
	Prototype* copia = prototipo->clonar();
	// Se muestra el mensaje original
	prototipo->mostrar();
	// Se muestra el mensaje de la copia
	copia->mostrar();

	// Se eliminan de memoria ambos objetos
	delete prototipo;
	delete copia;

	// Actividad Prototype Documento

	// Se crea un nuevo prototipo de documento de texto.
	DocumentoPrototype* prototipoTexto = new DocumentoTexto();
	// Se configura el documento de texto con un texto de ejemplo.
	prototipoTexto->configurar("Texto de ejemplo");

	// Se crea un nuevo prototipo de documento de imagen.
	DocumentoPrototype* prototipoImagen = new DocumentoImagen();
	// Se configura el documento de imagen con el nombre de un archivo de imagen.
	prototipoImagen->configurar("imagen.png");

	// Se clona el prototipo de texto para obtener una copia modificable del documento de texto.
	DocumentoPrototype* copiaTexto = prototipoTexto->clonar();
	// Se clona el prototipo de imagen para obtener una copia modificable del documento de imagen.
	DocumentoPrototype* copiaImagen = prototipoImagen->clonar();

	// Se modifica el texto de la copia del documento de texto.
	copiaTexto->configurar("Texto Modificado");
	// Se modifica el archivo de la copia del documento de imagen.
	copiaImagen->configurar("nueva imagen.png");

	// Se reconfigura el prototipo de texto para demostrar que no afecta a la copia ya modificada.
	prototipoTexto->configurar("Texto original");
	// Se reconfigura el prototipo de imagen de la misma manera.
	prototipoImagen->configurar("Imagen Original.png");

	// Se clona y muestra un nuevo documento de texto basado en el prototipo de texto actual.
	prototipoTexto->clonar()->mostrar();
	// Se muestra el texto de la copia modificada del documento de texto.
	copiaTexto->mostrar();

	// Se clona y muestra un nuevo documento de imagen basado en el prototipo de imagen actual.
	prototipoImagen->clonar()->mostrar();
	// Se muestra la imagen de la copia modificada del documento de imagen.
	copiaImagen->mostrar();

	// Se eliminan los objetos prototipo y copias de documentos de texto e imagen de la memoria.
	delete prototipoTexto;
	delete prototipoImagen;
	delete copiaImagen;
	delete copiaTexto;

	
	//composite
	/*Composite
		*
		*
		* El patron Composite se utiliza para crear estructuras de arbpl que representan jerarquias de objetos.Permite
		* a los clientes tratar objetos individuales y composiciones de objetos de la misma manera.
		*
		* Uso comun del composite
		* -Cuando necesitas representar jerarquias de objetos en una estructura de arbol
		* -Para trata objetos individuales y composiciones de objetos de la misma manera
		* -Para implementar estructuras de arbol de manera eficiente
		*
		*El patron Composite se basa en la idea de que los obejtos individuales y las composiciones de objetos(contenedores) deben ser tratados de manera uniforme
		* La estructura de arbol se compone de nodos hoja(objetos individuales) y nodos compuestos(contenedores)
		*/
		// Creando dos hojas.
	Leaf* leaf1 = new Leaf();
	Leaf* leaf2 = new Leaf();

	// Montamos un compuesto y le metemos las hojas.
	Compuesto* compuesto = new Compuesto();
	compuesto->agregarLeaf(leaf1);
	compuesto->agregarLeaf(leaf2);

	// Ejecutamos la operación del compuesto.
	compuesto->operacion();

	// Limpiamos la memoria.
	delete leaf1;
	delete leaf2;
	delete compuesto;

	// Actividad Archivos

	// Creamos un par de archivos.
	SistemaArchivo* archivo1 = new SistemaArchivo();
	SistemaArchivo* archivo2 = new SistemaArchivo();

	// Una carpeta para organizarlos, que seria un objeto y luego se hacen su metodo de agregarSistema
	SistemaCarpeta* carpeta = new SistemaCarpeta();
	carpeta->agregarSistema(archivo1);
	carpeta->agregarSistema(archivo2);

	// Mostramos la info de la carpeta.
	carpeta->mostrarInfo();

	// Y borramos todo.
	delete archivo1;
	delete archivo2;
	delete carpeta;


	//Proxy
	/*Proxy
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
		*/

	Proxy proxy;
	//El objeto real solo se crea cuando se llama a la operacion
	proxy.operacion();
	proxy.operacion();

	//Actividad Proxy

	ProxyImagen proxys;
	proxys.mostrar();
	proxys.mostrar();

	// Bridge
	/*Bridge
		*
		*
		* El patron bridge se utiliza para separar una abstraccion de su implementacion.Esto permite que ambas partes
		* evolucionen de forma inpendiente y se combinen de manera flexible
		*
		* Usos comunos del bridge
		* -Cuando necesitas separar una abstraccion de su implementacion
		* -Para permitir cambios independientes en ambas partes
		* -Para combinar abstracciones y diferentes implementacions de manera flexible
		* -Cuando tienes multiples dimensiones de variacion en tu sistema
		*
		*El patron bridge se basa en la idea de que una clase puede tener dos jerarquias separadas, una para la abstraccion y otra para la implementacion.
		* La abstraccion se comunica con le implementacion a traves de un ibjeto de implementacion
		*/

	ImplementacionConcretaA impA;
	ImplementacionConcretaB impB;

	AbstraccionRefinada ARA(&impA);
	AbstraccionRefinada ARB(&impB);

	ARA.operacion();
	ARB.operacion();

	//Chain of Responsability
	/*Chains of Responsability
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
		*El patron chain of responsability se basa en la idea de que una solicitud debe ser manejada por uno o mas objetos, pero el cliente no necesita saber cual de ellos la manejara.
		* Crea una cadena de manejadores y cada manejador decide si procesa la solictud o la pasa al siguiente manejador
		*/

		// Primero, armamos la cadena de responsabilidades de menor a mayor. Utilizabdo 3 objetos apartir de los manejadoresConcretos
	manejadorConcretoC handleC(nullptr); // Ultimo eslabon
	manejadorConcretoB handleB(&handleC); // Si B no puede, lo intenta C
	manejadorConcretoA handleA(&handleB); // A es el primero en intentar manejar la solicitud.

	// Agregamos al handle A varios valores
	handleA.manejarSolicitud(50); 
	handleA.manejarSolicitud(5);  
	handleA.manejarSolicitud(15); 
	handleA.manejarSolicitud(19); 
	handleA.manejarSolicitud(3); 

	// Actividad ChainsofResponsability

	// Primero, armamos la cadena de responsabilidades de menor a mayor. Utilizabdo 3 objetos apartir de los manejadores
	manejadorDirectorGeneral directorGeneral(nullptr); // El jefe final
	manejadorGerente gerente(&directorGeneral); // El gerente, que pasa cosas más grandes al director.
	manejadorDirectivo directivo(&gerente); // El directivo es el primero en recibir las solicitudes.

	// Se inclyen varios valores de dinero
	directivo.getMonto(800);    
	directivo.getMonto(3500);   
	directivo.getMonto(10000);  


	// Template Method
	/*Template Method
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
		*El patron Template Method se basa en la idea de que un algoritmo puede tener una estructura general con pasos especificicos que pueden varior.
		* Se define un metodo "Plantilla" en una clase base que llama a metodos abstractos que deben ser implementados por subclases.
		*/
	//Se crean dos objetos nuevos del tipo juego, que tienen valores Ajedrez y Monopoly
	Juego* juego1 = new Ajedrez();
	Juego* juego2 = new Monopoly();
	//Se utiliza el metodo jugar en ambos objetos
	juego1->jugar();
	juego2->jugar();
	//Se borran los datos de memoria
	delete juego1;
	delete juego2;

	// Actividad de Template Method
	//Se crean dos objetos nuevos del tipo Refrigerado, que tienen valores del tipo Samusumg y LG
	Refrigerador* refri1 = new RefrigeradorSamsung;
	Refrigerador* refri2 = new RefrigeradorLG;
	//Se utiliza el metodo jugar en ambos refris
	refri1->jugar();
	refri2->jugar();
	//Se borran los datos de memoria
	delete refri1;
	delete refri2;

	//Mutex
	/*Mutex(Exclusion mutua)
		*
		*
		* Un mutex es una herramienta critica en la programacion multi - hilo que garantiza que solo un hilo acceda a un recurso compartido a la vez
		* Esto evita problemas de concurrencia y asegura que los datos compartidos no se corrompan
		*
		*Usos comunes en Mutex
		*
		*-Evitar problemas de concurrencia en programas multi - hilo
		* -Proteger el acceso a recursos compartidos, como estructuras de datos, archivos, bases de datos y etc
		* -Garantizar que solo un hilo pueda modificar un recurso a la vez
		*
		*Un mutex(Exlusion mutua) es un objeto que actua como una semaforo para controlar el acceso a un recurso compartido en un programa multi - hilo.
		* Proporciona bloqueo y desbloqueo para garantizar que solo un hilo pueda acceder al recurso compartido a la vez
		*/
	//Se crean 3 objetos, con su tipo de valor y su valor numerico
	thread hilo1(Hilo, 1);
	thread hilo2(Hilo, 2);
	thread hilo3(Hilo, 3);
	//Se utiliza el metodo join en los 3 hilos

	hilo1.join();
	hilo2.join();
	hilo3.join();
	cout << "\n--- Ejecucion 1 entre hilos" << endl;
	cout << "\n--- Ejecucion 2 entre hilos" << endl;
	cout << "\n--- Ejecucion 3 entre hilos" << endl;

	// Adapter
	/* Adapter
	* Patrón: Facilita la comunicación entre dos interfaces incompatibles, actuando como un puente entre ellas. Permite que clases con interfaces diferentes trabajen juntas sin modificar sus fuentes originales.
	* Instancia: Un adaptador envuelve una instancia de una clase con una interfaz incompatible, proporcionando una interfaz esperada por el cliente.
	* Esto permite que el cliente interactúe con esa instancia como si fuera una instancia de otra clase con una interfaz compatible.
	* Propósito del Patrón Adaptador: Se utiliza para integrar clases que no podrían trabajar juntas debido a sus interfaces incompatibles. 
	* Este patrón permite reutilizar interfaces existentes y hacer que clases no relacionadas trabajen juntas sin necesidad de reescribir su código. Es especialmente útil en sistemas donde la modificación de código fuente de las clases existentes no es deseable o posible.
	* 
	* Tipos de Adaptador:
	* Adaptador de Clase: Utiliza la herencia múltiple para adaptar una interfaz a otra. Implementa la interfaz esperada por el cliente y hereda la implementación de la interfaz incompatibles.
	* Adaptador de Objeto: Compone el objeto con la interfaz incompatibles dentro del objeto adaptador, creando una nueva interfaz para que el cliente la use.
	* Usos Comunes del Patrón Adaptador:
	* Integración de Sistemas: Facilitar la comunicación entre sistemas nuevos y sistemas antiguos, o entre sistemas externos donde no es posible alterar el código fuente.
	* Desarrollo de Software Reutilizable: Permitir que el código se reutilice en contextos donde las interfaces no coinciden, aumentando la modularidad y la flexibilidad del software.
	* Refactorización de Código: Proporcionar una capa de abstracción que permite modificar la implementación interna sin afectar a los clientes que dependen de ella
	*/
	// Creamos un objeto de una interfaz antigua.
	InterfazVieja* objetoViejo = new InterfazVieja();
	// Adaptamos el objeto viejo para que se comporte como uno con interfaz nueva.
	InterfazNueva* objetoNuevo = new Adapter(objetoViejo);

	// Usamos el nuevo método a través del adaptador.
	objetoNuevo->metodoNuevo();

	// Limpiamos los recursos asignados.
	delete objetoViejo;
	delete objetoNuevo;

	// Actividad Figuras

	// Creamos figuras básicas.
	Circulo* circulo = new Circulo();
	Cuadrado* cuadrado = new Cuadrado();

	// Adaptamos estas figuras para ser tratadas como objetos dibujables.
	Dibujable* adaptadorCirculo = new CirculoAdapter(circulo);
	Dibujable* adaptadorCuadrado = new CuadradoAdapter(cuadrado);

	// Dibujamos las figuras utilizando los adaptadores.
	adaptadorCirculo->dibujar();
	adaptadorCuadrado->dibujar();

	// Liberamos la memoria de los objetos y adaptadores creados.
	delete circulo;
	delete cuadrado;
	delete adaptadorCirculo;
	delete adaptadorCuadrado;


	// Decorator
		/*Patrón de Diseño Decorador
		* Patrón: Permite añadir dinámicamente nuevas funcionalidades a objetos individuales sin alterar la definición de las clases de los objetos que se decoran. 
		* Funciona como una alternativa flexible a la creación de subclases para extensión de funcionalidades.
		*
		* Instancia: Un decorador envuelve un objeto para proporcionar comportamientos adicionales y modificados.
		* En este contexto, una instancia decorada se diferencia de una instancia simple por las funcionalidades extra que presenta, ofreciendo una manera práctica de añadir o modificar comportamientos en tiempo de ejecución.
		*
		* Propósito del Patrón Decorador: Se utiliza para agregar responsabilidades adicionales a los objetos de forma dinámica. 
		* Ofrece una alternativa más flexible a la herencia para extender funcionalidades, promoviendo el principio de responsabilidad única y la reutilización de código. Es útil en situaciones donde modificar una clase para extender su funcionalidad no es viable, como cuando la clase es cerrada para modificaciones o cuando la extensión a través de la herencia resultaría en una explosión de subclases.
		*
		* Wrapper o Envoltorio: Los decoradores actúan como un envoltorio del objeto original, extendiendo o modificando su comportamiento.
		* Cada decorador tiene una referencia al objeto que decora, permitiendo llamar a su comportamiento original y luego añadir el suyo propio.
		* Usos Comunes del Patrón Decorador:
		* Extensión de Funcionalidades: Añadir responsabilidades adicionales a objetos individuales de manera dinámica y transparente.
		* Personalización de Objetos: Permitir una personalización detallada de un objeto mediante la adición secuencial de decoradores, cada uno añadiendo su propia funcionalidad o modificación.
		* Alternativa a Subclases: Ofrecer una solución más flexible y menos rígida a la extensión de funcionalidades en comparación con la herencia, evitando una jerarquía de clases compleja y difícil de mantener.
		*/

	// Por cada que pasa se agrega una "decoracion"
	// Se crea un objeto base o componente concreto.
	ComponenteConcreto* obj = new ComponenteConcreto();
	// Se decoran el componente concreto con funcionalidades adicionales.
	DecoratorConcretoA* DecoratorA = new DecoratorConcretoA(obj);
	DecoratorConcretoB* DecoratorB = new DecoratorConcretoB(DecoratorA);

	// Se ejecutan las operaciones para demostrar la funcionalidad extendida.
	obj->operacion();
	DecoratorA->operacion();
	DecoratorB->operacion();

	// Se liberan los recursos.
	delete obj;
	delete DecoratorA;
	delete DecoratorB;

	// Actividad Cafe

	// Se crea el componente base: una simple cafetería.
	Cafeteria* cafeteria = new Cafeteria();
	// Se añaden decoradores para extender la funcionalidad del café base.
	Leche* cafeConLeche = new Leche(cafeteria);
	Azucar* cafeConAzucar = new Azucar(cafeteria);

	// Se preparan variantes de café demostrando la extensión de funcionalidad.
	cafeteria->prepararCafe();
	cafeConLeche->prepararCafe();
	cafeConAzucar->prepararCafe();

	// Se limpia todo al final.
	delete cafeteria;
	delete cafeConLeche;
	delete cafeConAzucar;


	// Sigleton Multihilo
	// El patron de diseño Sigleton garantiza que una clase tenga una sola instancia y proporciona un punto de acceso global a esa intancia
	// El singleton multihilo asegura que, inlusc en entornos multihilo, solo se crea una unica instancia
	// Usos Comunes del Singleton Multihilo
	// -Cuando necesitas una unica instancia de una clase en entornos multihilo
	// -Para crear un punto d acceso global a una instancia compartidad en aplicaciones multihilo
	// -Evitar problemas de concurrencia al crear una unica instancia e n un entorno de multiples hilos
	// El patron sigleton Multihilo es una version segura para hilos del patron Sigleton. Garantiza que, en entornos multihilo
	// solo se crea una unica instancia de una clase

	thread hiloSingle1(Hilo2, 1, 2);
	thread hiloSingle2(Hilo2, 2, 4);
	hiloSingle1.join();
	hiloSingle2.join();
	int val = SigletonMultihilo::getInstance().getValue();
	cout << "Valor en el SigletonMultiHilo: " << val << endl;

	//Activiad Singleton Multihilos

	thread hiloAct1(Hilo3, 1, "Opciones Generales");
	thread hiloAct2(Hilo3, 2, "Graficos");
	hiloAct1.join();
	hiloAct2.join();
	string fra = Configuracion::getInstance().getValue();
	cout << "Actualmente se encuentra en " << fra << endl;


	// Producto-Consumidor

	//El problema del Producto-Consumidor es un escenario comun en programacion multihilo en el que los productores generan datos
	// y los consumidores los consumen. Para evitar conflictos y garantizar que los consumidores
	// no intenten consumir datos inexistentes, se utuliza una estructura de datos compartida y mutex para controlar el acceso
	// 
	// El problema del Producto-Consumidor se refiere a una situacion en la que uno o varios Productores generan datos y uno o varios
	// consumidores consumen esos datos. Los productores y consumidores deben operar de manera segura en un entorno multihilo
	// 
	// -Gestion de recursos compartifos en entornos multihilo
	// -Comunicacion entre hilos para procesos de produccion y consumo
	// Evitar conflictos y asegurar que los consumidores no intenten consumir datos inexistentes.

	srand(time(nullptr));
	thread HProductor(productor);
	thread HConsumidor(consumidor, 1);
	thread HConsumidor2(consumidor, 2);

	HProductor.join();
	HConsumidor.join();
	HConsumidor2.join();

	return 0;
}
