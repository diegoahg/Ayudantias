#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

/*Funcion EXPLODE delimita por un caracter y guarda el resultado en un array*/
vector<string> explode(const string& str, const char& ch) {
	string next;
	vector<string> result;


	for (string::const_iterator it = str.begin(); it != str.end(); it++) {

		if (*it == ch)
		{
			if (!next.empty()) {

				result.push_back(next);
				next.clear();
			}
		} else {

			next += *it;
		}
	}
	if (!next.empty())
		result.push_back(next);
	return result;
}

int main(){
	cout<<"Programa para Poder leer un fichero"<<endl;
	const string nfichero = "archivo.txt"; //Nombre del Fichero
	string str;
	ifstream fichero ; //Inicializa una variable de tipo Stream
	fichero.open(nfichero.c_str()); //Abre el fichero
	if (!fichero.fail()) // Comprueba que el fichero no venga vacio.
	{
		getline(fichero, str); //Obtiene una linea
		vector <string> result = explode(str, ';'); //delimitador
		cout<< "NOMBRE: " << result[0]<<endl;
		cout<< "EDAD: " << result[1]<<endl;
		cout<< "Sexo: " << result[2]<<endl<<endl;
		while (!fichero.eof())
		{
			getline(fichero, str);
			vector <string> result = explode(str, ';'); //delimitador
			cout<< "NOMBRE: " << result[0]<<endl;
			cout<< "EDAD: " << result[1]<<endl;
			cout<< "Sexo: " << result[2]<<endl<<endl;
		}
	}
	else{
		cout<<"No se pudo abrir este archivo"<<endl;
	}
	fichero.close(); //Siempre cerrar fichero

}