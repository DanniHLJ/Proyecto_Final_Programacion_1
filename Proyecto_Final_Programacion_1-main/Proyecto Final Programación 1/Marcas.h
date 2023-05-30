
#pragma once
#include <iostream>
	using namespace std;

	class Marcas
	{

		//atributos
	protected:  string idMarca, marca;
			 //constructor
	protected:
		Marcas() {

		};
		Marcas(string idMrc, string mrc) {
			idMarca = idMrc;
			marca = mrc;
		}
	};

