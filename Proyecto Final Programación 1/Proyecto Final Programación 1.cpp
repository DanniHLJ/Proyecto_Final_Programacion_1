#include <iostream>
#include "Funcionalidades.h"
using namespace std;
int main() {
    char opc;
    int opcion = 0;
    do {
        system("cls");
        cout << "Bienvenido al Menu Fase I - Proyecto final." << endl;
        cout << "Por favor elija una tabla: 1. Clientes \n 2. Puestos \n3.Empleados \n4. Marcas \n5.Proveedores \n6. Productos \n7.Compras & Compras Detalle \n8.Ventas & Ventas Detalle \n9.Busqueda Nit" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1: //Clientes
            system("cls");
            int opcionclientes;
            cout << "_____Bienvenido al CRUD de Clientes_____" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcionclientes;
            switch (opcionclientes) {
            case 1:
                C_Clientes();
                break;
            case 2:
                R_Clientes();
                break;
            case 3:
                U_Clientes();
                break;
            case 4:
                D_Clientes();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 2: //Puestos
            system("cls");
            int opcionpuestos;
            cout << "_____Bienvenido al CRUD de Puestos_____" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcionpuestos;
            switch (opcionpuestos) {
            case 1:
                C_Puestos();
                break;
            case 2:
                R_Puestos();
                break;
            case 3:
                U_Puestos();
                break;
            case 4:
                D_Puestos();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 3: //Empleados
            system("cls");
            int opcionempleados;
            cout << "_____Bienvenido al CRUD de Empleados_____" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcionempleados;
            switch (opcionempleados) {
            case 1:
                C_Empleados();
                break;
            case 2:
                R_Empleados();
                break;
            case 3:
                U_Empleados();
                break;
            case 4:
                D_Empleados();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 4: //Marcas
            system("cls");
            int opcionmarcas;
            cout << "_____Bienvenido al CRUD de Marcas_____" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcionmarcas;
            switch (opcionmarcas) {
            case 1:
                C_Marcas();
                break;
            case 2:
                R_Marcas();
                break;
            case 3:
                U_Marcas();
                break;
            case 4:
                D_Marcas();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 5: //Proveedores
            system("cls");
            int opcionproveed;
            cout << "_____Bienvenido al CRUD de Proveedores_____" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcionproveed;
            switch (opcionproveed) {
            case 1:
                C_Proveedores();
                break;
            case 2:
                R_Proveedores();
                break;
            case 3:
                U_Proveedores();
                break;
            case 4:
                D_Proveedores();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 6: //Productos
            system("cls");
            int opcionpro;
            cout << "_____Bienvenido al CRUD de Productos_____" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcionpro;
            switch (opcionpro) {
            case 1:
                C_Productos();
                break;
            case 2:
                R_Productos();
                break;
            case 3:
                U_Productos();
                break;
            case 4:
                D_Productos();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 7: //Compras
            system("cls");
            int opcioncompras;
            cout << "_____Bienvenido al CRUD de Compras_____" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcioncompras;
            switch (opcioncompras) {
            case 1:
                C_Compras();
                break;
            case 2:
                R_Compras();
                break;
            case 3:
                U_Compras();
                break;
            case 4:
                D_Compras();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 8: //Ventas
            system("cls");
            int opcionv;
            cout << "_____Bienvenido al CRUD de Ventas y Ventas Detalle!_____" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcionv;
            switch (opcionv) {
            case 1:
                C_ventas_detalle();
                break;
            case 2:
                R_ventas_detalle();
                break;
            case 3:
                U_ventas_detalle();
                break;
            case 4:
                D_ventas_detalle();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        default:
            break;
        
        cout << "Desea continuar? (s/n)";
        cin >> opc;
    } while (opc == 's' || opc == 'S');
    system("pause");
    return 0;
}