#pragma once
#include <iostream>

using namespace std;


class PersonaC {
	//atributos
protected:	string nombres, apellidos,nit,correo,fecha_ingreso, telefono, genero;
		 
		 
		 //constructo
protected:
	PersonaC() {
	}
	PersonaC(string nom, string ape, string tel, string gen,string n,string mail,string date_ing) {
		nombres = nom;
		apellidos = ape;
		telefono = tel;
		nit = n; 
		genero = gen;
		correo = mail;
		fecha_ingreso = date_ing;
	}


};
