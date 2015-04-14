#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;


typedef struct {
   int id;
   int edad;
   int nota;
   int sexo;
   string nombre;
    } Alumno;

void LlenarArreglo(long A[], int largo){
    int digitos,numero;
    for(int i=0; i<largo; i++){
            numero = 1;
            digitos = 0;
            while(digitos<6){
                numero = numero*10 + rand()%10;
                digitos++;
            }
            numero = numero*10 + rand()%2;

        A[i] = numero;
        //cout<<" Casilla "<< i <<" es: "<< A[i] << endl;
    }

}

 void LlenarAlumno(Alumno A[], long Numero[], int largo){


      for(int i=0;i<largo;i++){
      // Llenado de de Estructura Alumno
      // Se saca el primer digito y se acorta el numero en una cifra.
      A[i].sexo = Numero[i]%10;
      Numero[i]= Numero[i]/10;
       // Se saca los otros dos digitos y se acorta el resto del numero en dos cifras.
      A[i].nota = Numero[i]%100;
      Numero[i]= Numero[i]/100;
      // Se saca los otros dos digitos y se acorta el resto del numero en dos cifras.
      A[i].edad = Numero[i]%100;
      Numero[i]= Numero[i]/100;
      // Se saca los otros dos digitos y se acorta el resto del numero en dos cifras.
      A[i].id = Numero[i]%100;
      Numero[i]= Numero[i]/100;

      cout<<"ingrese nombre "<< i <<endl;
      cin>>A[i].nombre;
      fflush(stdin);
    }

 }
 void MostrarEstudiantes(Alumno A[], int largo){
   for(int i=0;i<largo;i++){
     cout<<"* -----  Alumno "<<i+1<<" ----- * "<<endl;
     cout<<"Id : "<<A[i].id<<endl;
     cout<<"Edad : "<<A[i].edad<<endl;
     cout<<"Nota : "<<A[i].nota<<endl;
      if(A[i].sexo==0)
        cout<<"El alumno es Hombre "<<endl;
      else
         cout<<"El alumno es Mujer "<<endl;

    cout<<" * --------------------- *"<<endl;
    cout<<endl;


   }
 }

void Promedio(Alumno A[], int largo){
    int s=0;
    int p;
    for(int i=0; i<largo; i++){
        s = s + A[i].nota;
    }
    p = s / largo;
    cout << "El promedio es: " << p << endl;

}

void Hombre(Alumno A[], int largo){
    int i;
    int cta1=0, cta2=0;
    for (i=0; i<largo; i++)
    {
        if(A[i].sexo == 0)
            cta1++;
        else
            cta2++;
    }
    cout <<"La cantidad de hombres es:" << cta1 << endl;
}

int contar(Alumno tortuga[], int largo){
    int i;
    int cont=0;
    for (i=0; i<largo; i++){
        if (tortuga[i].edad<18)
            cont++;

    }
    return cont;


}

void compararnombre(Alumno A[], int largo)
{
    for (int i=0; i<largo; i++)
    {
        string palabra = A[i].nombre;
        string compara = "Diego";

        if(palabra.compare(compara)==0)
        {
            cout<< "Existe Diego";
        }
    }
}



int main(){
    Alumno Estudiantes[100];
    long Arreglo[100];
    LlenarArreglo(Arreglo, 5);
    LlenarAlumno(Estudiantes,Arreglo, 5);
    MostrarEstudiantes(Estudiantes, 5);
    Promedio(Estudiantes, 5);
    Hombre(Estudiantes, 5);
    compararnombre(Estudiantes,5);
    cout << "La cantidad de estudiantes menores de 18 años es " << contar(Estudiantes, 5)<< endl;
    return 0;
}
