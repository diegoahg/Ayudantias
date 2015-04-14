#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct {
   int id;
   int edad;
   int nota;
   int sexo;
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
        cout<<" Casilla "<< i <<" es: "<< A[i] << endl;
    }

}

 void LlenarAlumno(Alumno A[], long Numero[] ){


      for(int i=0;i<100;i++){
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



        }

 }
 void MostrarEstudiantes(Alumno A[]){
   for(int i=0;i<100;i++){
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
int main(){
    Alumno Estudiantes[100];
    long Arreglo[100];
    LlenarArreglo(Arreglo, 100);
    LlenarAlumno(Estudiantes,Arreglo);
    MostrarEstudiantes(Estudiantes);

    return 0;
}
