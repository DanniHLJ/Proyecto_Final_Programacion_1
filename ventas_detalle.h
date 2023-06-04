#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>

class Ventas_detalle
{
private:
	//Variables Ventas
	int idVenta = 0, nofactura = 0, idcliente = 0, idempleado = 0;
	char serie;
	string fechafactura;
	//Variables Ventas_detalle
	int idventa_detalle = 0, idventa = 0, idproducto = 0;
	string cantidad;
	float precio_unitario = 0;
	string Nit;
public:
	//constructor
	Ventas_detalle() {

	};
	//ventas
	Ventas_detalle(int idV, int nof, char s, string fechaf, int idc, int ide, int idventa_d, int idv, int idp, string cant, float precio_u) {
		idVenta = idV;
		nofactura = nof;
		serie = s;
		fechafactura = fechaf;
		idcliente = idc;
		idempleado = ide;
		idventa_detalle = idventa_d;
		idventa = idv;
		idproducto = idp;
		cantidad = cant;
		precio_unitario = precio_u;
	};
	//constructor para validacion ventas
	Ventas_detalle(string n) {
		Nit = n;
	};
	Ventas_detalle(int idE, int no, char s) {
		idempleado = idE;
		nofactura = no;
		serie = s;
	}

	//constructor para validaciones ventas detalle
	Ventas_detalle(int idp, int idv, int idventad, string c) {
		idproducto = idp;
		idventa = idv;
		idventa_detalle = idventad;
		cantidad = c;

	};
	Ventas_detalle(int idv, int idp, int idventad, string c, float pu) {
		idventa = idp;
		idproducto = idp;
		idventa_detalle = idventad;
		cantidad = c;
		precio_unitario = pu;

	};
	//eliminar
	Ventas_detalle(int idV, int idVD) {
		idVenta = idV;
		idventa_detalle = idVD;
	};
	//get

	int getidC() { return idcliente; }
	//set
	void setidcliente(int c) { idcliente = c; }
	void setidventa(int v) { idventa = v; }
	//CRUD
	void crear() {
		//ventas
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string tt = to_string(nofactura);
			system("pause");
			string insert = "INSERT INTO ventas(nofactura, serie, fechafactura, idcliente, idempleado, fechaingreso) "
				"VALUES('" + tt + "', '" + serie + "', NOW(), '" + to_string(idcliente) + "', '" + to_string(idempleado) + "', NOW())";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				system("cls");
				cout << "Query Insert Successfuly" << endl;
			}
			else {
				system("cls");
				cout << "Query Insert Ventas got problems" << mysql_error(cn.getConectar()) << endl;
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		bool valor = leerIdVentas();
		if (!valor) {
			return;
		}
		system("pause");
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idventa);
			string tt = to_string(idproducto);
			string ttt = to_string(precio_unitario);
			string insert = "INSERT INTO ventas_detalle(idVenta,idProducto,cantidad,precio_unitario)"
				"VALUES('" + t + "','" + tt + "','" + cantidad + "','" + ttt + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				system("cls");
				cout << "Query Insert Ventas Detalle Successfuly" << endl;
			}
			else {
				system("cls");
				cout << "Query Insert Ventas got problems " << mysql_error(cn.getConectar()) << endl;
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();

		// Variables para almacenar los datos de la factura
		int idventa = 0;
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
			"WHERE v.idVenta = " + to_string(idventa);
		const char* queryFactura = consultaFactura.c_str();
		q_estado = mysql_query(cn.getConectar(), queryFactura);
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
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

	//Validaciones Ventas
	int leerNitClientes() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT max(idCliente) as id,nombres,apellidos FROM clientes WHERE NIT = '" + Nit + "'";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				if (mysql_num_rows(resultado) == 0) {
					cout << "No se encontraron resultados con el Nit: " << Nit << endl;
					return 0;
				}

				int id = 0;
				while (fila = mysql_fetch_row(resultado)) {
					id = stoi(fila[0]);
					cout << "Id Cliente:" << id << endl;
					cout << "Nombres: " << fila[1] << endl;
					cout << "Apellidos: " << fila[2] << endl;
					cout << "\n";
				}
				idcliente = id;
				cout << "\n";
				cout << "___________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems: " << mysql_error(cn.getConectar()) << endl;
				return 0;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
			return 0;
		}
		cn.cerrar_conexion();
		return idcliente;
	}

	bool leerIdEmpleados() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idempleado);
			string consulta = "SELECT nombres, apellidos FROM empleados  WHERE idEmpleado = '" + t + "'";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				if (mysql_num_rows(resultado) == 0) {
					cout << "No se encontraron resultados con el idEmpleado: " << t << endl;
					return false;
				}
				while (fila = mysql_fetch_row(resultado)) {
					cout << "Nombres: " << fila[0] << endl;
					cout << "Apellidos: " << fila[1] << endl;
					cout << "\n";
				}
				cout << "\n";
				cout << "___________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems" << mysql_error(cn.getConectar()) << endl;
				return false;
			}

		}
		else {
			cout << "Error en la conexion" << endl;
			return false;
		}
		cn.cerrar_conexion();
	};

	//Validaciones Ventas_detalle
	bool leerIdProductos() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idproducto);
			string consulta = "SELECT producto FROM productos  WHERE idProducto = '" + t + "'";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				if (mysql_num_rows(resultado) == 0) {
					cout << "No se encontraron resultados con el idProducto: " << t << endl;
					return false;
				}
				while (fila = mysql_fetch_row(resultado)) {
					cout << "Producto: " << fila[0] << endl;
					cout << "\n";
				}
				cout << "\n";
				cout << "___________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems" << mysql_error(cn.getConectar()) << endl;
				return false;
			}

		}
		else {
			cout << "Error en la conexion" << endl;
			return false;
		}
		cn.cerrar_conexion();
	};
	bool leerIdVentas() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(nofactura);
			string consulta = "SELECT idVenta FROM ventas WHERE nofactura = '" + t + "'";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				if (mysql_num_rows(resultado) == 0) {
					cout << "No se encontraron resultados con el numero de Factura: " << t << endl;
					return false;
				}
				while (fila = mysql_fetch_row(resultado)) {
					cout << "idVenta: " << fila[0] << endl;
					idventa = stoi(fila[0]);
					cout << "\n";

				}
				cout << "\n";
				cout << "___________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select tuvo problemas: " << mysql_error(cn.getConectar()) << endl;
				return false;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
			return false;
		}
		cn.cerrar_conexion();
		return true;
	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			//Tabla Ventas
			string consulta = "SELECT v.idventa, CONCAT(v.nofactura, '-', v.serie) AS correlativo, v.fechafactura, v.fechaingreso, e.idempleado, e.nombres, e.apellidos, c.idCliente, c.nombres, c.apellidos FROM ventas v JOIN empleados e ON v.idempleado = e.idempleado JOIN clientes c ON v.idcliente = c.idCliente;";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "idVenta: " << fila[0] << endl;
					cout << "Correlativo: " << fila[1] << endl;
					cout << "Fecha Factura: " << fila[2] << endl;
					cout << "Fecha Ingreso: " << fila[3] << endl;
					cout << "____Empleado____" << endl;
					cout << "idEmpleado: " << fila[4] << endl;
					cout << "Nombres: " << fila[5] << endl;
					cout << "Apellidos: " << fila[6] << endl;
					cout << "____Cliente____" << endl;
					cout << "idCliente: " << fila[7] << endl;
					cout << "Nombres: " << fila[8] << endl;
					cout << "Apellidos: " << fila[9] << endl;
					cout << "\n";
				}
				cout << "\n";
				cout << "___________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems" << mysql_error(cn.getConectar()) << endl;
			}
			system("pause");
			//Tabla ventas_detalle
			string consulta2 = "SELECT vd.idventa_detalle,vd.cantidad,vd.precio_unitario, (vd.cantidad * vd.precio_unitario) AS total, v.idVenta,v.nofactura,p.idProducto,p.producto from ventas_detalle vd JOIN ventas v ON vd.idVenta = v.idVenta JOIN productos p ON vd.idProducto = p.idProducto;";
			const char* y = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), y);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "____Ventas____" << endl;
					cout << "idVenta: " << fila[4] << endl;
					cout << "Numero Factura: " << fila[5] << endl;
					cout << "____Productos____" << endl;
					cout << "idProducto: " << fila[6] << endl;
					cout << "Producto: " << fila[7] << endl;
					cout << "_____________Ventas Detalles____________" << endl;
					cout << "idVenta_detalle:  " << fila[0] << endl;
					cout << "Cantidad: " << fila[1] << endl;
					cout << "precio_unitario: " << fila[2] << endl;
					cout << "total: " << fila[3] << endl;
				}
				cout << "\n";
				cout << "___________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems" << mysql_error(cn.getConectar()) << endl;
			}

		}
		else {
			cout << "Error en la conexion" << endl;
		}

		cn.cerrar_conexion();

	};
	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idVenta);
			string tt = to_string(nofactura);
			string ic = to_string(idcliente);
			string ie = to_string(idempleado);
			string update = "UPDATE ventas SET nofactura='" + tt + "',serie='" + serie + "',idcliente='" + ic + "',idempleado='" + ie + "' WHERE idVenta = '" + t + "'";
			const char* u = update.c_str();
			q_estado = mysql_query(cn.getConectar(), u);
			if (!q_estado) {
				system("cls");
				cout << "Query Update Successfuly" << endl;
			}
			else {
				system("cls");
				cout << "Query Update Failed: " << mysql_error(cn.getConectar()) << endl;
				return;
			}
		}
		else {
			cout << "Error al conectar" << endl;
			return;
		}
		cn.cerrar_conexion();

		//ventas detalle
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idventa);
			string tt = to_string(idproducto);
			string pu = to_string(precio_unitario);
			string vd = to_string(idventa_detalle);
			string update = "UPDATE ventas_detalle SET idVenta='" + t + "',idProducto='" + tt + "',cantidad='" + cantidad + "',precio_unitario='" + pu + "' WHERE idventa_detalle = '" + vd + "'";
			const char* u = update.c_str();
			q_estado = mysql_query(cn.getConectar(), u);
			if (!q_estado) {
				system("cls");
				cout << "Query Update Successfuly" << endl;
			}
			else {
				system("cls");
				cout << "Query Update Failed: " << mysql_error(cn.getConectar()) << endl;
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();
	};
	void eliminar()
	{
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar())
		{
			// Eliminar registro de la tabla ventas_detalle
			string t = to_string(idventa_detalle);
			string deleteQuery = "DELETE FROM ventas_detalle WHERE idventa_detalle = " + t;
			const char* d = deleteQuery.c_str();
			q_estado = mysql_query(cn.getConectar(), d);
			if (!q_estado)
			{
				cout << "Registro eliminado de ventas_detalle" << endl;
			}
			else
			{
				cout << "Error al eliminar registro de ventas_detalle: " << mysql_error(cn.getConectar()) << endl;
			}

			// Eliminar registro de la tabla ventas
			t = to_string(idVenta);
			deleteQuery = "DELETE FROM ventas WHERE idVenta = " + t;
			d = deleteQuery.c_str();
			q_estado = mysql_query(cn.getConectar(), d);
			if (!q_estado)
			{
				cout << "Registro eliminado de ventas" << endl;
			}
			else
			{
				cout << "Error al eliminar registro de ventas: " << mysql_error(cn.getConectar()) << endl;
			}
		}
		else
		{
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();
	}
};