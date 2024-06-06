#include <iostream>
#include <string>

using namespace std;

struct datosEstudiante{
	string nombre;
    string codigo;
    float nota1,nota2,nota3,prom=0;
};

int main() {

    datosEstudiante estudiante[50];
    int cant,desaprobados=0;

    cout<<"Cantidad de estudiantes: ";cin>>cant;

    for(int i=0 ; i<cant; ++i) {
        cout<<"Datos del estudiante "<<i+1<<": "<<endl;
        cout<<"Ingrese nombre del estudiante: ";cin>>estudiante[i].nombre;
		cout<<"Ingrese codigo de estudiante: ";cin>>estudiante[i].codigo;
		cout<<"Ingrese nota 1: "; cin>>estudiante[i].nota1;
		cout<<"Ingrese nota 2: "; cin>>estudiante[i].nota2;
		cout<<"Ingrese nota 3: "; cin>>estudiante[i].nota3;
		
        estudiante[i].prom=(estudiante[i].nota1+estudiante[i].nota2+estudiante[i].nota3)/3.0;
        if (estudiante[i].prom<10.0) {
			desaprobados++;
		}
    }

    for (int i=0;i<cant-1;++i) {
        for (int j=0;j<cant-i-1;++j) {
            if (estudiante[j].prom<estudiante[j+1].prom) {
                datosEstudiante lol=estudiante[j];
                estudiante[j]=estudiante[j+1];
                estudiante[j+1]=lol;
            }
        }
    }

    cout<<"\nReporte de los estudiantes:\n";
    for (int i=0;i<cant;++i) {
        cout<<"Estudiante "<<i+1<<": "<<estudiante[i].nombre;
		cout<<"\n 	 Promedio: "<<estudiante[i].prom<<endl;
    }
    cout<<"Desaprobados: "<<desaprobados<<endl;

    return 0;
}
