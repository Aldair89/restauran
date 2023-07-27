#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar un plato en el menú
struct Plato {
    string nombre;
    double precio;
};

// Estructura para representar un pedido
struct Pedido {
    vector<string> platos;
};

// Función para agregar un plato al menú
void agregarPlato(vector<Plato>& menu, const string& nombre, double precio) {
    menu.push_back({ nombre, precio });
    cout << "Plato agregado al menú exitosamente." << endl;
}

// Función para mostrar el menú
void mostrarMenu(const vector<Plato>& menu) {
    cout << "Menú:" << endl;
    for (const auto& plato : menu) {
        cout << plato.nombre << " - $" << plato.precio << endl;
    }
}

// Función para realizar un pedido
void realizarPedido(vector<Pedido>& pedidos, const vector<Plato>& menu, const vector<int>& opciones) {
    Pedido nuevoPedido;
    for (int opcion : opciones) {
        nuevoPedido.platos.push_back(menu[opcion - 1].nombre);
    }
    pedidos.push_back(nuevoPedido);
    cout << "Pedido realizado exitosamente." << endl;
}

// Función para calcular el total de una orden
double calcularTotal(const vector<Plato>& menu, const vector<int>& opciones) {
    double total = 0;
    for (int opcion : opciones) {
        total += menu[opcion - 1].precio;
    }
    return total;
}

// Función para mostrar el historial de pedidos
void mostrarHistorial(const vector<Pedido>& pedidos) {
    cout << "Historial de pedidos:" << endl;
    for (int i = 0; i < pedidos.size(); i++) {
        cout << "Pedido " << i + 1 << ": ";
        for (const string& plato : pedidos[i].platos) {
            cout << plato << ", ";
        }
        cout << endl;
    }
}

int main() {
    vector<Plato> menu;
    vector<Pedido> pedidos;

    int opcion;
    string nombrePlato;
    double precioPlato;
    vector<int> opciones;

    do {
        cout << "======= SISTEMA DE RESTAURANTE =======" << endl;
        cout << "1. Agregar plato al menú" << endl;
        cout << "2. Mostrar menú" << endl;
        cout << "3. Realizar pedido" << endl;
        cout << "4. Calcular total de un pedido" << endl;
        cout << "5. Mostrar historial de pedidos" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del plato: ";
                cin.ignore();
                getline(cin, nombrePlato);
                cout << "Ingrese el precio del plato: ";
                cin >> precioPlato;
                agregarPlato(menu, nombrePlato, precioPlato);
                break;
            case 2:
                mostrarMenu(menu);
                break;
            case 3:
                mostrarMenu(menu);
                cout << "Ingrese los números de los platos que desea pedir (separados por espacios): ";
                int opcionPlato;
                while (cin >> opcionPlato) {
                    opciones.push_back(opcionPlato);
                }
                realizarPedido(pedidos, menu, opciones);
                opciones.clear();
                break;
            case 4:
                mostrarMenu(menu);
                cout << "Ingrese los números de los platos del pedido para calcular el total (separados por espacios): ";
                while (cin >> opcionPlato) {
                    opciones.push_back(opcionPlato);
                }
                cout << "El total del pedido es: $" << calcularTotal(menu, opciones) << endl;
                opciones.clear();
                break;
            case 5:
                mostrarHistorial(pedidos);
                break;
            case 6:
                cout << "Saliendo del sistema de restaurante." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }

        cout << endl;
    } while (opcion != 6);

    return 0;
}
