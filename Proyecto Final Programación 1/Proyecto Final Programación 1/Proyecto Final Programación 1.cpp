#include <mysql.h>
#include <iostream>
#include "Clientes.h"
#include "Proveedores.h"

using namespace std;

string direccion;
string nit;
string fecha_nacimiento;
int main()
{
    //tabla clientes
    string  nombres, apellidos, fecha_ingreso, Correo, genero, nit, telefono;


    cout << "Ingrese Nit: ";
    getline(cin, nit);
    cout << "Ingrese nombres: ";
    getline(cin, nombres);
    cout << "Ingrese apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese genero: ";
    getline(cin, genero);
    cout << "Ingrese telefono: ";
    cin >> telefono;
    cin.ignore();
    cout << "Ingrese Correo Electronico: ";
    getline(cin, Correo);

    Clientes c = Clientes(nombres, apellidos, telefono, genero, fecha_ingreso, nit, Correo);

    c.crear();
    c.leer();

    //actualizar

    return 0;

    //tabla proveedores
    int idProveedore;
    string proveedor, telefonos;
    cout << "Ingrese el idProveedore: " << endl;
    cin >> idProveedore;
    cin.ignore();
    cout << "Ingrese el proveedor: " << endl;
    getline(cin, proveedor);
    cout << "Ingrese el nit: " << endl;
    getline(cin, nit);
    cout << "Ingrese la direccion: " << endl;
    getline(cin, direccion);
    cout << "Ingrese el telefono: " << endl;
    getline(cin, telefonos);
    Proveedores C = Proveedores(idProveedore, proveedor, nit, direccion, telefonos);
    C.Crear();
    C.Leer();

    //actualizar 
    cout << "Ingrese idProveedore: " << endl;
    cin >> idProveedore;
    cin.ignore();
    cout << "Ingrese el nuevo proveedor: " << endl;
    getline(cin, proveedor);
    cout << "Ingrese el nuevo nit: " << endl;
    getline(cin, nit);
    cout << "Ingrese la nueva direccion: " << endl;
    getline(cin, direccion);
    cout << "Ingrese el nuevo telefono: " << endl;
    getline(cin, telefonos);
    Proveedores U = Proveedores(idProveedore, proveedor, nit, direccion, telefonos);
    U.Actualizar();

    //Eliminar
    cout << "Ingrese el idProveedore a eliminar: " << endl;
    cin >> idProveedore;
    cin.ignore();
    Proveedores D = Proveedores(idProveedore);
    D.Eliminar();
}

