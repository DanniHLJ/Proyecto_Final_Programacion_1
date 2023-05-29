#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include "PersonaC.h"
#include <string>

using namespace std;
class Cliente : PersonaC {
	//atributos
private: string nit;
	   int idCliente;
	   //constructor
public:
	Cliente() {
	}
	Cliente(int idCliente, string nom, string ape, string tel, string gen, string date_ing, string n, string mail) : PersonaC(nom, ape, tel, gen, n, mail, date_ing) {
		nit = n;
	};
	//Metodos
	//set (modificar)
	void setNit(string n) { nit = n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setTelefono(int tel) { telefono = tel; }
	void setGenero(int gen) { genero = gen; }
	void setCorreo(string mail) { correo = mail; }
	void setFechaIngreso(string date_ing) { fecha_ingreso = date_ing; }
	//get (obtener)
	string getNit() { return nit; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getTelefono() { return telefono; }
	string getGenero() { return genero; }
	string getCorreo() { return correo; }
	string getFechaIngreso() { return fecha_ingreso; }

	//metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string t = to_string(idCliente);
			string insert = "INSERT INTO CLIENTES(nit,nombres,apellidos,direccion,telefono,fecha_nacimiento) VALUES('" + nit + "','" + nombres + "','" + apellidos + "','" + apellidos + "''" + t + "','" + correo + "','" + fecha_ingreso + "')";
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
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT *FROM clientes";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "id_cliente: " << fila[0] << endl;
					cout << "nit: " << fila[1] << endl;
					cout << "nombres: " << fila[2] << endl;
					cout << "apellidos: " << fila[3] << endl;
					cout << "direccion: " << fila[4] << endl;
					cout << "telefono :" << fila[5] << endl;
					cout << "fecha_nacimiento: " << fila[6] << endl;
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
			string t = to_string(idCliente);
			string update = "UPDATE clientes SET nombres='" + nombres + "',apellidos='" + apellidos + "',NIT='" + nit + "',genero='" + genero + "',correo='" + correo + "',fechaingreso='" + fecha_ingreso + "',telefono='" + telefono + "' WHERE idCliente =  '" + t + "'";
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
			string deleteQuery = "DELETE FROM clientes WHERE idCliente = '" + to_string(idCliente) + "'";
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
