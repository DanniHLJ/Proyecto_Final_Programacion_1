#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include <string>
class Proveedores
{
private:
	int idProveedore;
	string proveedor, nit, direccion, telefono;
public:
	Proveedores() {
	}
	Proveedores(int id, string p, string n, string d, string t) {
		idProveedore = id;
		proveedor = p;
		nit = n;
		direccion = d;
		telefono = t;
	}
	Proveedores(int id) {
		idProveedore = id;
	}
	//Metodos set
	void setIdProve(int id) { idProveedore = id; }
	void setProveedor(string p) { proveedor = p; }
	void setNit(string n) { nit = n; }
	void setDir(string d) { direccion = d; }
	void setTel(string t) { telefono = t; }

	//metodos get
	int getId() { return idProveedore; }
	string getProve() { return proveedor; }
	string getNit() { return nit; }
	string getDir() { return direccion; }
	string getTel() { return telefono; }
	//CRUD
	void Crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string t = to_string(idProveedore);
			string insert = "INSERT INTO proveedores(idProveedore,proveedor,nit,direccion,telefono) VALUES('" + t + "','" + proveedor + "','" + nit + "','" + direccion + "','" + telefono + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				system("cls");
				cout << "Query Insert Successfuly" << endl;
			}
			else {
				system("cls");
				cout << "Query Insert got problems";
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();
	};
	void Leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT *FROM proveedores";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "idProveedore: " << fila[0] << endl;
					cout << "proveedor: " << fila[1] << endl;
					cout << "nit: " << fila[2] << endl;
					cout << "direccion: " << fila[3] << endl;
					cout << "telefono :" << fila[4] << endl;
					cout << "\n";
				}
				cout << "\n";
				cout << "_________________________________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems" << endl;
			}

		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	void Actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idProveedore);
			string update = "UPDATE productos SET proveedor='" + proveedor + "',nit='" + nit + "',direccion='" + direccion + "',telefonos='" + telefono + "' WHERE idProducto = '" + t + "'";
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
	void Eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string deleteQuery = "DELETE FROM proveedores WHERE idProveedore = '" + to_string(idProveedore) + "'";
			const char* d = deleteQuery.c_str();
			q_estado = mysql_query(cn.getConectar(), d);
			if (!q_estado) {
				system("cls");
				cout << "Query Delete Successfuly" << endl;
			}
			else {
				system("cls");
				cout << "Query Delete got problems";
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();
	};
};
