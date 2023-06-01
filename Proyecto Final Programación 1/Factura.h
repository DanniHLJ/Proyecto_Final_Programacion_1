#pragma once
#include <iostream>
#include <string>
#include <mysql.h>
#include "Clientes.h"
#include "ConexionBD.h"
#include "ventas_detalle.h"
using namespace std;

void Factura();



void imprimirFactura() {
    // Variables para almacenar los datos de la factura
    int idventa;
    int no_factura, serie;
    string nombres_cliente, apellidos_cliente, direccion_cliente, nit_cliente;
    string nombres_empleado, apellidos_empleado;
    string fecha_factura;
    float suma = 0.0, IVA = 0.0, total = 0.0;

    // Consulta SELECT para obtener los datos de la factura
    // y asignarlos a las variables correspondientes
    string consultaFactura = "SELECT v.no_factura, v.serie, v.fecha_factura, c.nombres, c.apellidos, c.direccion, c.nit, e.nombres, e.apellidos "
        "FROM ventas AS v "
        "INNER JOIN clientes AS c ON v.id_cliente = c.idCliente "
        "INNER JOIN empleados AS e ON v.id_empleado = e.idEmpleado "
        "WHERE v.idVenta = " + to_string(idCliente);
    const char* queryFactura = consultaFactura.c_str();
    q_estado = mysql_query(cn.getConectar(), queryFactura);
    if (!q_estado) {
        resultado = mysql_store_result(cn.getConectar());
        if (mysql_num_rows(resultado) == 0) {
            cout << "No se encontraron resultados en la tabla ventas para el idVenta: " << idventa << endl;
            return;
        }
        else {
            // Obtener los datos de la factura
            fila = mysql_fetch_row(resultado);
            no_factura = stoi(fila[0]);
            serie = stoi(fila[1]);
            fecha_factura = fila[2];
            nombres_cliente = fila[3];
            apellidos_cliente = fila[4];
            direccion_cliente = fila[5];
            nit_cliente = fila[6];
            nombres_empleado = fila[7];
            apellidos_empleado = fila[8];

            // Imprimir la factura
            cout << "============= Factura ================" << endl;
            cout << "No factura: " << no_factura << "-" << serie << endl;
            cout << "Fecha Factura: " << fecha_factura << endl;
            cout << "NIT: " << nit_cliente << endl;
            cout << "CLIENTE: " << nombres_cliente << " " << apellidos_cliente << endl;
            cout << "Direccion: " << direccion_cliente << endl;
            cout << "============ Empleado ================" << endl;
            cout << "Empleado: " << nombres_empleado << " " << apellidos_empleado << endl;
            cout << "============ Productos ===============" << endl;
            cout << "Producto\tCantidad\tPrecio Unitario\tTotalProducto" << endl;
            cout << "---------------------------------------" << endl;

            // Consulta SELECT para obtener los datos de los productos de la venta
            string consultaProductos = "SELECT p.producto, vd.cantidad, vd.precio_unitario "
                "FROM ventas_detalle AS vd "
                "INNER JOIN productos AS p ON vd.id_producto = p.idProducto "
                "WHERE vd.idVenta = " + to_string(idventa);
            const char* queryProductos = consultaProductos.c_str();
            q_estado = mysql_query(cn.getConectar(), queryProductos);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                if (mysql_num_rows(resultado) == 0) {
                    cout << "No se encontraron productos en la tabla ventas_detalle para el idVenta: " << idventa << endl;
                }
                else {
                    while (fila = mysql_fetch_row(resultado)) {
                        string producto = fila[0];
                        int cantidad = stoi(fila[1]);
                        float precio_unitario = stof(fila[2]);
                        float total_producto = cantidad * precio_unitario;

                        cout << producto << "\t" << cantidad << "\t\t" << precio_unitario << "\t\t" << total_producto << endl;
                        suma += total_producto;
                    }

                    cout << "----------------------------------------" << endl;
                    IVA = suma * 0.12;
                    cout << "IVA:\t\t\t\t\t" << IVA << endl;
                    total = suma + IVA;
                    cout << "TOTAL:\t\t\t\t\t" << total << endl;
                    cout << "----------------------------------------" << endl;
                }
            }
            else {
                system("cls");
                cout << "Query Select tuvo problemas: " << mysql_error(cn.getConectar()) << endl;
                return;
            }
        }
    }
    else {
        system("cls");
        cout << "Query Select tuvo problemas: " << mysql_error(cn.getConectar()) << endl;
        return;
    }
}
/*FORMATO FACTURA
============ Factura ===============
No factura: - Fecha Factura:
NIT:
CLIENTE: Nombre, Apellido
Direccion:
============ Empleado ===============
Empleado: Nombre, Apellido
============ Productos ==============
Producto - Cantidad - Precio Unitario - TotalProducto
==================================
IVA    --> Suma*12%
TOTAL  --> Resultado = suma + IVA
==================================
Pago   -->
Cambio -->
*/

