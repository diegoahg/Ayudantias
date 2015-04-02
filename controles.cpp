#include <iostream>
#include <stdlib.h>

/*
Autor: Diego Hernández García
Asignatura: Estructura de datos
Semestre: Primero
Año: 2015
Universidad: UTEM
*/

using namespace std;

//Funcion cuenta impares de un numero
int ContarImpares(int numero){
    int contador = 0, digito;
    while(numero>0){
        digito = numero%10;
        if(digito%2 != 0){
            contador++;
        }
        numero =  numero/10;
    }
    return contador;
}

//Cuenta los numero que empiezen con 5
int Cuenta5s(int A[], int cantidad){
    int i, contador=0, primero;

    for(i=0; i<cantidad; i++){
        while(A[i] > 0){
            primero = A[i]%10;
            A[i] = A[i]/10;
        }
        if(primero == 5){
                contador++;

        }
    }
    return contador;
}

//Control 1 de Estructura de Datos
void Control1(int opcion){
    switch(opcion){
        case 1:
            cout << "Escriba un programa en C++, que permita leer dos números enteros  permita:"<<endl;
            cout << "-Indicar cual de los numeros tiene mas digitos impares"<<endl;
            cout << "-Intercambiar los ultimos digitos de cada numero; ejemplo N1=334 y N=2, debe retornar N1=331 y N2=4564"<<endl;
            cout << "Presione ENTER para continuar..."<<endl;
        break;
        case 2:
            int numero1 , numero2 , contador1 , contador2, aux1, aux2;
            cout << "******************NUMERO CON MAS IMPARES****************** "<<endl;
            cout << "Ingrese primer numero"<<endl;
            cin >> numero1;
            cout << "Ingrese ndoseg numero"<<endl;
            cin >> numero2;
            contador1 = ContarImpares(numero1);
            contador2 = ContarImpares(numero2);

            if(contador1 > contador2){
                cout << "El numero con mas digitos es "<< contador1 << endl;
            }
            if(contador1 < contador2){
                cout << "El numero con mas digitos es "<< contador2 << endl;
            }
            if(contador1 == contador2){
                cout << "Los numeros son iguales"<< endl;
            }
            cin.ignore().get(); //system("pause") para windows
            system("clear"); //system("cls") para windows
            cout << "******************INTERCAMBIAR NUMEROS****************** "<<endl;
            cout << "Ingrese primer numero"<<endl;
            cin >> numero1;
            cout << "Ingrese segundo numero"<<endl;
            cin >> numero2;
            cout << "NUMERO ANTIGUOS:" << numero1 << " y " << numero2 << endl;
            aux1 = numero1%10;
            aux2 = numero2%10;
            numero1 = numero1/10;
            numero2 = numero2/10;
            numero1 = (numero1*10) + aux2;
            numero2 = (numero2*10) + aux1;
            cout << "NUMERO INTERCAMBIADOS:" << numero1 << " y " << numero2 << endl;
        break;
    }
}

//Control 3 de EDD
void Control2(int opcion){
     switch(opcion){
        case 3:
            cout << "Se pide escribir una funcion llamada Cuenta5s que recibe un arreglo de enteros y su cantidad de elementos, permita retornar la cantidad de elementos que comienzan con el digito 5"<<endl;
            cout << "Presione ENTER para continuar..."<<endl;
        break;
        case 4:
            int Arreglo[100],i, azar, largo, resultado;
            cout << "***********Cuenta5s***********"<<endl;
            cout << "Indique cantidad de casillas"<<endl;
            cin >> largo;
            cout << "El Arreglo esta conformado por " << largo << " casillas que contienen:" <<endl;
            for(i=0; i<largo; i++){
                Arreglo[i] = rand() % 1000;
                cout << "Casilla " << i+1 << " es: " << Arreglo[i] <<endl;
            }
            resultado = Cuenta5s(Arreglo,largo);
            cout<< "La cantidad de elementos que comienzan con 5 son: " << resultado << endl;
        break;
        }
}
int main(){
    int opcion;
    do{
        cout << "Ingrese una opcion"<<endl;
        cout << "\t1)Ver enunciado de Control 1"<<endl;
        cout << "\t2)Ejecutar Control 1"<<endl;
        cout << "\t3)Ver enunciado de Control 2"<<endl;
        cout << "\t4)Ejecutar Control 2"<<endl;
        cout << "\t5)Salir"<<endl;
        cin >> opcion;
        switch(opcion){
            case 1:
                Control1(1);
                cin.ignore().get();  //system("pause") para windows
                system("clear"); //system("cls") para windows
            break;
            case 2:
                Control1(2);
                cin.ignore().get();  //system("pause") para windows
                system("clear"); //system("cls") para windows
            break;
            case 3:
                Control2(3);
                cin.ignore().get();  //system("pause") para windows
                system("clear"); //system("cls") para windows
            break;
            case 4:
                Control2(4);
                cin.ignore().get();  //system("pause") para windows
                system("clear"); //system("cls") para windows
            break;
            case 5:
                cout << "Hasta Luego...Adios" << endl;
            break;
            default:
                cout << "Opcion no es valida." <<endl;
                cin.ignore().get();  //system("pause") para windows
                system("clear"); //system("cls") para windows
        }
    }
    while(opcion!=5);
}
