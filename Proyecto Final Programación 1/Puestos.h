#pragma once
#include <iostream>
using namespace std; 

class Puestos
{

		//atributos
protected:  string idPuesto,puesto;
		 //constructor
protected:
	Puestos() {

	};
	Puestos(string idPst, string pst) {
		idPuesto = idPst;
		puesto = pst; 
	}
};

