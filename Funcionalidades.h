#pragma once
#include <string>
#include <regex>
#include <mysql.h>
#include "Clientes.h"
#include "Puestos.h"
#include "Empleados.h"
#include "Proveedores.h"
#include "Marcas.h"
#include "Productos.h"
#include "ventas_detalle.h"
#include "Compras.h"
//#include <Servo.h>
using namespace std;

/*Servo servomeca; //Servo
int MotorD = 2; // motor de la banda
int infra = 7; // receptor infrarojo
//variables globales
int valor = 0; //almacenamiento y lectura del punto serial
char a;
int b = 5;
*/
bool validarNIT(const string& nit) {
    regex formato("^\\d{5}-\\d{3}-\\d{1}$");
    if (nit == "Consumidor Final" || nit == "C/F") {
        return true;
    }
    return regex_match(nit, formato);
}
void C_Clientes() {
    char opcion;
    do {
        string NIT, nombres, apellidos, telefono, correo_electronico;
        int idCliente = 0;
        bool genero;
        cin.ignore();
        cout << "Ingrese nombres: ";
        getline(cin, nombres);
        cout << "Ingrese apellidos: ";
        getline(cin, apellidos);
        cout << "Ingrese NIT el formato debe ser 12345-123-1: ";
        getline(cin, NIT);
        while (!validarNIT(NIT)) {
            cout << "El NIT ingresado no es valido." << endl;
            cout << "Ingrese otro NIT que si sea valido: " << endl;
            getline(cin, NIT);
        }
        cout << "Ingrese genero: (0 masculino. 1 femenino)" << endl;
        cin >> genero;
        cin.ignore();
        cout << "Ingrese telefono: ";
        getline(cin, telefono);
        cout << "Ingrese correo electronico: ";
        getline(cin, correo_electronico);
        Cliente c = Cliente(idCliente, nombres, apellidos, NIT, genero, telefono, correo_electronico);
        c.crear();
        cout << "Desea continuar con esta opcion? " << endl;
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');
};
void R_Clientes() {
    Cliente l = Cliente();
    l.leer();
};
void U_Clientes() {
    string NIT, nombres, apellidos, telefono, correo_electronico;
    int idCliente = 0;
    bool genero;
    cout << "Ingrese el idCliente que desea actualizar: " << endl;
    cin >> idCliente;
    cin.ignore();
    cout << "Ingrese nuevos Nombres: " << endl;
    getline(cin, nombres);
    cout << "Ingrese nuevos Apellidos: " << endl;
    getline(cin, apellidos);
    cout << "Ingrese nuevo nit: " << endl;
    getline(cin, NIT);
    cout << "Ingrese nuevo genero: (0 masculino. 1 femenino)" << endl;
    cin >> genero;
    cin.ignore();
    cout << "Ingrese nuevo telefono: " << endl;
    getline(cin, telefono);
    cout << "Ingrese nuevo correo electronico: " << endl;
    getline(cin, correo_electronico);
    Cliente x = Cliente(idCliente, nombres, apellidos, NIT, genero, telefono, correo_electronico);
    x.actualizar();

};
void D_Clientes() {
    int idCliente = 0;
    cout << "Ingrese el idCliente a eliminar:" << endl;
    cin >> idCliente;
    cin.ignore();
    Cliente d = Cliente(idCliente);
    d.eliminar();
};
//tabla Puestos
void C_Puestos() {
    int idPuesto = 0;
    string puesto;
    cout << "Ingrese el puesto: " << endl;
    getline(cin, puesto);
    Puestos c = Puestos(idPuesto, puesto);
    c.crear();
};
void R_Puestos() {
    Puestos l = Puestos();
    l.leer();
};
void U_Puestos() {
    int idPuesto = 0;
    string puesto;
    cout << "Ingrese el idPuesto a modificar: " << endl;
    cin >> idPuesto;
    cin.ignore();
    cout << "Ingrese el nuevo puesto: " << endl;
    getline(cin, puesto);
    Puestos U = Puestos(idPuesto, puesto);
    U.actualizar();
};
void D_Puestos() {
    int idPuesto = 0;
    cout << "Ingrese el idPuesto a eliminar: " << endl;
    cin >> idPuesto;
    cin.ignore();
    Puestos D = Puestos(idPuesto);
    D.eliminar();
};

//Table Empleados
void C_Empleados() {
    int idPuesto, idEmpleado = 0;
    string nombres, apellidos, direccion, telefono, Dpi, fechanacimiento, fecha_inicio_labores;
    bool genero = 0;
    bool valor = false;

    while (!valor) {
        cout << "Ingrese el idPuesto: ";
        cin >> idPuesto;
        cin.ignore();
        Empleados l = Empleados(idPuesto, nombres);
        valor = l.leerId();
    }

    cout << "Ingrese los nombres: ";
    getline(cin, nombres);
    cout << "Ingrese los apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese la direccion : ";
    getline(cin, direccion);
    cout << "Ingrese el telefono : ";
    getline(cin, telefono);
    cout << "Ingrese el DPI: ";
    getline(cin, Dpi);
    cout << "Ingrese genero (0. masculino 1. femenino): ";
    cin >> genero;
    cin.ignore();
    cout << "Ingrese la fecha de nacimiento: ";
    getline(cin, fechanacimiento);
    cout << "Ingrese la fecha de inicio de labores: ";
    getline(cin, fecha_inicio_labores);
    Empleados c = Empleados(idEmpleado, nombres, apellidos, direccion, telefono, Dpi, genero, fechanacimiento, idPuesto, fecha_inicio_labores);
    c.crear();
};
void R_Empleados() {
    Empleados l = Empleados();
    l.leer();

};
void U_Empleados() {
    int idPuesto, idEmpleado;
    string nombres, apellidos, direccion, telefono, Dpi, fechanacimiento, fecha_inicio_labores;
    bool genero = 0;
    cout << "Ingrese el idEmpleado que quiere cambiar los datos:";
    cin >> idEmpleado;
    cin.ignore();
    cout << "Ingrese los nuevos nombres: ";
    getline(cin, nombres);
    cout << "Ingrese los nuevos apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese la nueva direccion : ";
    getline(cin, direccion);
    cout << "Ingrese el nuevo telefono : ";
    getline(cin, telefono);
    cout << "Ingrese el nuevo DPI: ";
    getline(cin, Dpi);
    cout << "Ingrese el idPuesto: ";
    cin >> idPuesto;
    cin.ignore();
    cout << "Ingrese nuevo genero (0. masculino 1. femenino): ";
    cin >> genero;
    cin.ignore();
    cout << "Ingrese la nueva fecha de nacimiento: ";
    getline(cin, fechanacimiento);
    cout << "Ingrese la nueva fecha de inicio de labores: ";
    getline(cin, fecha_inicio_labores);
    Empleados u = Empleados(idEmpleado, nombres, apellidos, direccion, telefono, Dpi, genero, fechanacimiento, idPuesto, fecha_inicio_labores);
    u.actualizar();
};
void D_Empleados() {
    int idEmpleado = 0;
    cout << "Ingrese el idEmpleado a eliminar: " << endl;
    cin >> idEmpleado;
    cin.ignore();
    Empleados D = Empleados(idEmpleado);
    D.eliminar();
};
//Table Marcas
void C_Marcas() {
    int idMarca;
    string marca;
    cout << "Ingrese el idMarca: " << endl;
    cin >> idMarca;
    cin.ignore();
    cout << "Ingrese la marca: " << endl;
    getline(cin, marca);
    Marcas C = Marcas(idMarca, marca);
    C.crear();
};
void R_Marcas() {
    Marcas l = Marcas();
    l.leer();
};
void U_Marcas() {
    int idMarca;
    string marca;
    cout << "Ingrese el idMarca a buscar: " << endl;
    cin >> idMarca;
    cin.ignore();
    cout << "Ingrese la nueva marca: " << endl;
    getline(cin, marca);
    Marcas U = Marcas(idMarca, marca);
    U.actualizar();
};
void D_Marcas() {
    int idMarca = 0;
    cout << "Ingrese el idMarca a eliminar: " << endl;
    cin >> idMarca;
    cin.ignore();
    Marcas D = Marcas(idMarca);
    D.eliminar();
}
//Table Productos
void C_Productos() {
    int idProducto = 0, idMarca, existencia;
    string producto, descripcion, imagen, fecha_ingreso;
    float precio_costo, precio_venta;

    bool valor = false;
    while (!valor) {
        cout << "Ingrese el idMarca a comprobar si existe: " << endl;
        cin >> idMarca;
        cin.ignore();
        Productos l = Productos(idMarca, producto);
        valor = l.leerId();
    }
    cout << "Ingrese el producto: " << endl;
    getline(cin, producto);
    cout << "Ingrese la descripcion: " << endl;
    getline(cin, descripcion);
    cout << "Ingrese la imagen: " << endl;
    getline(cin, imagen);
    cout << "Ingrese el precio costo: " << endl;
    cin >> precio_costo;
    cin.ignore();
    cout << "Ingrese el precio venta: " << endl;
    cin >> precio_venta;
    cin.ignore();
    cout << "Ingrese la existencia: " << endl;
    cin >> existencia;
    cin.ignore();
    Productos C = Productos(idProducto, producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
    C.crear();
};
void R_Productos() {
    Productos l = Productos();
    l.leer();
};
void U_Productos() {
    int idProducto, idMarca, existencia;
    string producto, descripcion, imagen, fecha_ingreso;
    float precio_costo, precio_venta;

    cout << "Ingrese el idProducto que desea actualizar:";
    cin >> idProducto;
    cin.ignore();
    cout << "Ingrese nuevo Producto: ";
    getline(cin, producto);
    cout << "Ingrese nuevo idMarca: ";
    cin >> idMarca;
    cin.ignore();
    cout << "Ingrese nueva descripcion : ";
    getline(cin, descripcion);
    cout << "Ingrese nueva imagen : ";
    getline(cin, imagen);
    cout << "Ingrese precio_costo: ";
    cin >> precio_costo;
    cout << "Ingrese precio_venta: ";
    cin >> precio_venta;
    cout << "Ingrese nueva existencia: ";
    cin >> existencia;
    cin.ignore();

    Productos u = Productos(idProducto, producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
    u.actualizar();
};
void D_Productos() {
    int idProducto = 0;
    cout << "Ingrese el idProducto a eliminar: " << endl;
    cin >> idProducto;
    cin.ignore();
    Productos d = Productos(idProducto);
    d.eliminar();
};
//Table Proveedores
void C_Proveedores() {
    int idProveedore;
    string proveedor, nit, direccion, telefono;

    cout << "Ingrese idProveedor: ";
    cin >> idProveedore;
    cin.ignore();
    cout << "Ingrese Proveedor: ";
    getline(cin, proveedor);
    cout << "Ingrese NIT: ";
    getline(cin, nit);
    cout << "Ingrese Direccion: ";
    getline(cin, direccion);
    cout << "Ingrese telefono: ";
    getline(cin, telefono);

    Proveedores c = Proveedores(idProveedore, proveedor, nit, direccion, telefono);
    c.crear();
};
void R_Proveedores() {
    Proveedores r = Proveedores();
    r.leer();
};
void U_Proveedores() {
    int idProveedore;
    string proveedor, nit, direccion, telefono;

    cout << "Ingrese el idProveedor que desea actualizar: ";
    cin >> idProveedore;
    cin.ignore();
    cout << "Ingrese Nuevo Proveedor: ";
    getline(cin, proveedor);
    cout << "Ingrese Nuevo NIT: ";
    getline(cin, nit);
    cout << "Ingrese NuevaDireccion: ";
    getline(cin, direccion);
    cout << "Ingrese telefono: ";
    getline(cin, telefono);

    Proveedores u = Proveedores();
    u.actualizar();
};
void D_Proveedores() {
    int idProveedore = 0;
    cout << "Ingrese el idProveedor a eliminar:" << endl;
    cin >> idProveedore;
    cin.ignore();
    Proveedores d = Proveedores(idProveedore);
    d.eliminar();
};
//Table Ventas_Detalle
void C_ventas_detalle() {

    int idVenta = 0, no_factura = 0, idempleado = 0, idcliente = 0, idproducto = 0, idventa = 0, idventa_detalle = 0;
    char serie = ' ';
    string fechafactura, Nit, cantidad;
    float precio_unitario = 0;

    cout << "Ingrese el Numero Factura: " << endl;
    cin >> no_factura;
    cin.ignore();
    cout << "Ingrese la serie (recuerde que este es solo un caracter)" << endl;
    cin >> serie;
    cin.ignore();
    cout << "Ingrese la cantidad: " << endl;
    getline(cin, cantidad);
    cout << "Ingrese el precio unitario" << endl;
    cin >> precio_unitario;
    cin.ignore();

    char opcion;
    int valClientes = 0;
    Ventas_detalle C;
    while (valClientes == 0) {
        cout << "Ingrese Nit a validar el formato debe ser 12345-123-1: " << endl;
        getline(cin, Nit);
        while (!validarNIT(Nit)) {
            cout << "El NIT ingresado no es valido." << endl;
            cout << "Ingrese Nit el formato debe ser 12345-123-1: " << endl;
            getline(cin, Nit);
        }


        Ventas_detalle VC = Ventas_detalle(Nit);
        valClientes = VC.leerNitClientes();
        idcliente = VC.getidC();
        cout << idcliente;
        if (valClientes == 0) {
            cout << "Ese Nit no existe desea crear un registro con ese Nit? (s/n)" << endl;
            cin >> opcion;
            if (opcion == 's' || opcion == 'S') {
                C_Clientes();
            }
        }
    }

    bool valEmpleados = false;
    while (!valEmpleados) {
        cout << "Ingrese idEmpleado: " << endl;
        cin >> idempleado;
        cin.ignore();
        Ventas_detalle VE = Ventas_detalle(idempleado, no_factura, serie);
        valEmpleados = VE.leerIdEmpleados();
    }

    bool valProducto = false;
    while (!valProducto) {
        cout << "Ingrese idProducto: " << endl;
        cin >> idproducto;
        cin.ignore();
        Ventas_detalle VP = Ventas_detalle(idproducto, idventa, idventa_detalle, cantidad);
        valProducto = VP.leerIdProductos();
    }
    C = Ventas_detalle(idVenta, no_factura, serie, fechafactura, idcliente, idempleado, idventa_detalle, idVenta, idproducto, cantidad, precio_unitario);
    C.crear();
};
void R_ventas_detalle() {
    Ventas_detalle r = Ventas_detalle();
    r.leer();
};
void U_ventas_detalle() {
    int idVenta = 0, no_factura = 0, idcliente = 0, idempleado = 0, idventa_detalle = 0, idproducto = 0, idventa = 0;
    char serie = ' ';
    string fechafactura, cantidad;
    float precio_unitario;

    cout << "Ingrese idVenta a modificar de la tabla Ventas: " << endl;
    cin >> idVenta;
    cin.ignore();
    cout << "Ingrese el nuevo numero de factura: " << endl;
    cin >> no_factura;
    cin.ignore();
    cout << "Ingrese el nuevo numero de serie: " << endl;
    cin >> serie;
    cin.ignore();
    cout << "Ingrese la nueva fecha de factura: " << endl;
    getline(cin, fechafactura);
    cout << "Ingrese el nuevo idcliente: " << endl;
    cin >> idcliente;
    cin.ignore();
    cout << "Ingrese el nuevo idempleado: " << endl;
    cin >> idempleado;
    cin.ignore();
    system("pause");
    system("cls");
    cout << "___Ahora necesitamos los datos de ventas detalle___" << endl;
    fflush(stdin);
    cout << "Ingrese el idventa_detalle a actualizar: " << endl;
    cin >> idventa_detalle;
    cin.ignore();
    cout << "Ingrese el nuevo idventa: " << endl;
    cin >> idventa;
    cin.ignore();
    cout << "Ingrese el nuevo idProducto: " << endl;
    cin >> idproducto;
    cin.ignore();
    cout << "Ingrese la nueva cantidad: " << endl;
    getline(cin, cantidad);
    cout << "Ingrese el nuevo precio unitario: " << endl;
    cin >> precio_unitario;
    cin.ignore();
    Ventas_detalle U = Ventas_detalle(idVenta, no_factura, serie, fechafactura, idcliente, idempleado, idventa_detalle, idventa, idproducto, cantidad, precio_unitario);
    U.actualizar();
};
void D_ventas_detalle() {
    int idVenta, idventa_detalle;
    cout << "Ingrese el idVenta a eliminar: " << endl;
    cin >> idVenta;
    cout << "Ingrese el idventa_detalle a eliminar: " << endl;
    cin >> idventa_detalle;
    Ventas_detalle D = Ventas_detalle(idVenta, idventa_detalle);
    D.eliminar();
};
//Table Compras

void C_Compras() {
    char opcion;
    //Variables Compras
    int  no_orden_compra = 0, idProveedor = 0;
    int id_compra_detalle = 0;
    string fecha_orden;
    //Variables Compras detalle
    int idproducto = 0, idcompra = 0, cantidad = 0;
    float precio_costo_unitario = 0;
    //llamar constructor

    cout << "Ingrese el No. Orden de Compra: " << endl;
    cin >> no_orden_compra;
    cin.ignore();

    bool valProveedor = false;
    while (!valProveedor) {
        cout << "Ingrese idProveedor: " << endl;
        cin >> idProveedor;
        cin.ignore();
        Compras vpr = Compras(idProveedor);
        valProveedor = vpr.leeridProveedores();
    }

    cout << "Ingrese la fecha de Orden: " << endl;
    getline(cin, fecha_orden);
    cin.ignore();

    bool valCompras = false;
    while (!valCompras) {
        cout << "Ingrese idCompras: " << endl;
        cin >> idcompra;
        cin.ignore();
        Compras VC = Compras(idcompra, id_compra_detalle, idProveedor);
        valCompras = VC.leerIdCompras();
    }

    bool valProducto = false;
    //4
    while (!valProducto) {
        cout << "Ingrese idProducto: " << endl;
        cin >> idproducto;
        cin.ignore();
        Compras VP = Compras(idcompra, idproducto, cantidad, id_compra_detalle);
        valProducto = VP.leerIdProductos();
    }

    cout << "Ingrese la cantidad: " << endl;
    cin >> cantidad;
    cin.ignore();
    cout << "Ingrese el precio costo unitario" << endl;
    cin >> precio_costo_unitario;
    cin.ignore();

    Compras C = Compras(idcompra, no_orden_compra, idProveedor, fecha_orden, id_compra_detalle, idcompra, idproducto, cantidad, precio_costo_unitario);
    C.crear();
};
void R_Compras() {
    Compras r = Compras();
    r.leer();
};
void U_Compras() {
    int idCompra = 0, no_orden_compra = 0, idProveedor = 0;
    string fecha_orden;
    int idproducto = 0, idcompra = 0, idcompra_detalle = 0, cantidad = 0;
    float precio_costo_unitario = 0;

    cout << "Ingrese idCompra a modificar de la tabla Compras: " << endl;
    cin >> idCompra;
    cin.ignore();
    cout << "Ingrese el nuevo numero de Orden de Compra: " << endl;
    cin >> no_orden_compra;
    cin.ignore();
    cout << "Ingrese el nuevo ID de Proveedor: " << endl;
    cin >> idProveedor;
    cin.ignore();
    cout << "Ingrese la nueva fecha de orden: " << endl;
    getline(cin, fecha_orden);
    cin.ignore();
    system("pause");
    system("cls");
    cout << "========== Por favor ingresar Datos de la tabla Compras-Detalle ===========" << endl;
    fflush(stdin);
    cout << "Ingrese el idcompra_detalle a actualizar: " << endl;
    cin >> idcompra_detalle;
    cin.ignore();
    cout << "Ingrese el nuevo idcompra: " << endl;
    cin >> idcompra;
    cin.ignore();
    cout << "Ingrese el nuevo idProducto: " << endl;
    cin >> idproducto;
    cin.ignore();
    cout << "Ingrese la nueva cantidad: " << endl;
    cin >> cantidad;
    cin.ignore();
    cout << "Ingrese el nuevo precio de costo unitario: " << endl;
    cin >> precio_costo_unitario;
    cin.ignore();
    Compras U = Compras(idCompra, no_orden_compra, idProveedor, fecha_orden, idcompra_detalle, idcompra, idproducto, cantidad, precio_costo_unitario);
    U.actualizar();
};
void D_Compras() {
    int idCompra, idCompra_detalle;
    cout << "Ingrese el idCompra a eliminar: " << endl;
    cin >> idCompra;
    cout << "Ingrese el idCompra_detalle a eliminar: " << endl;
    cin >> idCompra_detalle;
    Compras D = Compras(idCompra, idCompra_detalle);
    D.eliminar();
};
