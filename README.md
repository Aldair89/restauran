# restauran
Este código en C++ implementa un sencillo sistema de restaurante que permite agregar platos al menú, mostrar el menú, realizar pedidos, calcular el total de un pedido y mostrar el historial de pedidos.

El programa utiliza estructuras struct para representar los platos en el menú y los pedidos realizados. A continuación, se describe qué hace cada función y la funcionalidad general del programa:

struct Plato: Representa un plato del menú y contiene los campos nombre (string) y precio (double).

struct Pedido: Representa un pedido y contiene un vector de strings llamado platos, que almacena los nombres de los platos incluidos en el pedido.

void agregarPlato(vector<Plato>& menu, const string& nombre, double precio): Esta función permite agregar un nuevo plato al menú. Toma como entrada un vector de estructuras Plato, el nombre del plato y su precio. Luego, agrega el plato al vector menu.

void mostrarMenu(const vector<Plato>& menu): Esta función muestra el menú actual. Recorre el vector menu de platos y muestra sus nombres y precios en la consola.

void realizarPedido(vector<Pedido>& pedidos, const vector<Plato>& menu, const vector<int>& opciones): Permite realizar un nuevo pedido. El usuario debe seleccionar los números correspondientes a los platos del menú que desea pedir. Luego, agrega los nombres de los platos seleccionados al vector platos de la estructura Pedido y agrega el pedido al vector pedidos.

double calcularTotal(const vector<Plato>& menu, const vector<int>& opciones): Calcula el total de un pedido basado en los platos seleccionados. Utiliza el vector opciones, que contiene los índices de los platos seleccionados del menú, y el vector menu para obtener los precios de cada plato seleccionado y sumarlos.

void mostrarHistorial(const vector<Pedido>& pedidos): Muestra el historial de pedidos realizados hasta el momento. Recorre el vector pedidos e imprime cada pedido y sus platos asociados.

La función main(): Contiene el menú principal del sistema. Permite a los usuarios elegir entre varias opciones, como agregar platos al menú, mostrar el menú, realizar pedidos, calcular el total de un pedido y mostrar el historial de pedidos. El bucle do-while se repite hasta que el usuario elija la opción para salir del programa.

El programa permite la interacción con el usuario para realizar distintas acciones en el sistema de restaurante. El menú se muestra en la consola, y el usuario puede ingresar números para seleccionar las opciones disponibles. El sistema almacena los platos y pedidos en vectores, lo que permite mantener un registro de las acciones realizadas durante la ejecución del programa.
