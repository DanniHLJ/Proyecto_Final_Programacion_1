#include <mysql.h>
#include <iostream>
#include "Clientes.h"
#include "Proveedores.h"
using namespace std;
int main()
{
    string nit, nombres, apellidos, direccion, fecha_nacimiento, fecha_inicio_labores, fecha_ingreso, DPI, Correo,genero;
    int telefono;
    cout << "Ingrese Nit: ";
    getline(cin, nit);
    cout << "Ingrese nombres: ";
    getline(cin, nombres);
    cout << "Ingrese apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese direccion: ";
    getline(cin, direccion);
    cout << "Ingrese telefono: ";
    cin >> telefono;
    cin.ignore();
    cout << "Ingrese fecha nacimiento: ";
    getline(cin, fecha_nacimiento);
    Clientes c = Clientes(nombres, apellidos, direccion, telefono, fecha_nacimiento, fecha_inicio_labores, fecha_ingreso,DPI,Correo,genero,nit);
    c.crear();
    c.leer();
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





