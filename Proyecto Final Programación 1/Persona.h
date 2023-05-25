#pragma once
#include <iostream>
using namespace std;
class Persona
{
	//atributos
protected: string nombres, apellidos, direccion, fecha_nacimiento, fecha_inicio_labores,fecha_ingreso,DPI,genero,correo;
		 int telefono = 0;
		 
		 //constructor
protected:
	Persona() {

	};
	Persona(string nom, string ape, string dir, int tel, string date, string date_inlab,string date_ing, string dpi, string gen,string mail) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = date;
		fecha_inicio_labores = date_inlab;
		fecha_ingreso = date_ing;
		DPI = dpi;
		genero = gen; 
		correo = mail;

	}
};

