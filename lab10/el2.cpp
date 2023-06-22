#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Producto {
public:
    string nombre;
    float precio;
    int cantidad;

    Producto() {}

    Producto(string nombre, float precio, int cantidad) {
        this->nombre = nombre;
        this->precio = precio;
        this->cantidad = cantidad;
    }

    void mostrarInformacion() const {
        cout << "Nombre: " << nombre << ", Precio: " << precio << ", Cantidad: " << cantidad << endl;
    }
};

void cargarInventario(vector<Producto>& inventario) {
    ifstream archivo("inventario.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo de inventario." << endl;
        return;
    }

    string nombre;
    float precio;
    int cantidad;

    while (archivo >> nombre >> precio >> cantidad) {
        Producto producto(nombre, precio, cantidad);
        inventario.push_back(producto);
    }

    archivo.close();
}

void guardarInventario(const vector<Producto>& inventario) {
    ofstream archivo("inventario.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo de inventario." << endl;
        return;
    }

    for (const auto& producto : inventario) {
        archivo << producto.nombre << " " << producto.precio << " " << producto.cantidad << endl;
    }

    archivo.close();
}

void registrarProducto(vector<Producto>& inventario) {
    // Código de registro de producto omitido por simplicidad

    // Guardar el inventario actualizado en el archivo
    guardarInventario(inventario);

    cout << "Producto registrado exitosamente." << endl;
}

void actualizarProducto(vector<Producto>& inventario) {
    // Código de actualización de producto omitido por simplicidad

    // Guardar el inventario actualizado en el archivo
    guardarInventario(inventario);

    cout << "Informacion del producto actualizada exitosamente." << endl;
}

void realizarVenta(vector<Producto>& inventario) {
    // Código de venta de producto omitido por simplicidad

    // Guardar el inventario actualizado en el archivo
    guardarInventario(inventario);

    cout << "Venta realizada exitosamente." << endl;
}

void generarInforme(const vector<Producto>& inventario) {
    cout << "Inventario:" << endl;
    for (const auto& producto : inventario) {
        producto.mostrarInformacion();
    }
}

int main() {
    		vector<Producto> inventario;

    		// Cargar el inventario desde el archivo al iniciar
    		cargarInventario(inventario);

    		while (true) {
        			cout << "\n--- Gestion de Inventario ---" << endl;
        			cout << "1. Registrar un nuevo producto" << endl;
        			cout << "2. Actualizar la informacion de un producto existente" << endl;
        			cout << "3. Realizar una venta de un producto" << endl;
        		           cout << "4. Generar un informe de inventario" << endl;
           cout << "5. Salir" << endl;

           cout << "Ingrese el numero de opcion: ";
           int opcion;
           cin >> opcion;

        switch (opcion) {
            case 1:
                registrarProducto(inventario);
                break;
            case 2:
                actualizarProducto(inventario);
                break;
            case 3:
                realizarVenta(inventario);
                break;
            case 4:
                generarInforme(inventario);
                break;
            case 5:   
                guardarInventario(inventario);
                return 0;
            default:
                cout << "Opción invalida. Intente nuevamente." << endl;
        }
    }

    return 0;
}
