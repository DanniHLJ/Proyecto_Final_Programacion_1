#include <iostream>
#include <mysql.h>

using namespace std;

int main() {

	
	MYSQL* conectar; 
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar,"localhost","root","HLJDanni","act11db",3306,NULL,0);
	if (conectar) {

		cout << "Conexion Exitosa..." << endl;
	}
	else {
		cout << "Error en la Conexión..." << endl; 
	}

	system("pause");
	return 0;

}






