#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

struct datosEmpleado{
    string nombre;
    char tipo;
    double s_Basico;
    double d_Seguro;
    double d_AFP;
    double bonificacion;
    double s_Neto;
};

void calcularDeducciones_Bonificaciones(datosEmpleado &empleado) {
    empleado.d_AFP = empleado.s_Basico * 0.08;
    empleado.d_Seguro = empleado.s_Basico * 0.05;

    if (empleado.tipo == 'C' || empleado.tipo == 'c') {
        empleado.bonificacion = empleado.s_Basico * 0.08;
    } else if (empleado.tipo == 'N' || empleado.tipo == 'n') {
        empleado.bonificacion = empleado.s_Basico * 0.12;
    }

    empleado.s_Neto=empleado.s_Basico-empleado.d_AFP-empleado.d_Seguro+empleado.bonificacion;
}

int main() {
    vector<datosEmpleado> empleados;
    int cantNombrados=0;
    int cantContratados=0;
    double t_sueldosNombrados=0.0;
    double t_sueldosContratados=0.0;

    char continuar;

    do {
        datosEmpleado empleado;
        cout << "Ingrese el nombre del empleado: ";
        cin >> empleado.nombre;
        cout << "Ingrese el sueldo basico del empleado: ";
        cin >> empleado.s_Basico;
        cout << "Ingrese el tipo de empleado (N:nombrado C:contratado): ";
        cin >> empleado.tipo;
        empleado.tipo = tolower(empleado.tipo);

        calcularDeducciones_Bonificaciones(empleado);
        empleados.push_back(empleado);

        if (empleado.tipo=='c') {
            cantContratados++;
            t_sueldosContratados += empleado.s_Neto;
        } else if (empleado.tipo=='n') {
            cantNombrados++;
            t_sueldosNombrados+=empleado.s_Neto;
        }
        
		system("cls");
		
        cout<<"Desea ingresar otro empleado? (S/N): ";
        cin>>continuar;
        continuar=tolower(continuar);
        
    } while (continuar=='s');
  	  system("cls");
    cout <<"\nDetalles de los empleados:"<<endl;
    for (const auto &empleado : empleados) {
        cout <<"Nombre: "<< empleado.nombre<<endl;
        cout <<"Tipo de empleado: "<< (empleado.tipo=='C' || empleado.tipo=='c' ? "Contratado" : "Nombrado") << endl;
        cout <<"Sueldo Basico: "<<empleado.s_Basico<<endl;
        cout <<"Deduccion Seguro: "<<empleado.d_Seguro<<endl;
        cout <<"Deduccion AFP: "<<empleado.d_AFP<<endl;
        cout <<"Bonificacion: "<<empleado.bonificacion<<endl;
        cout <<"Sueldo Neto: "<<empleado.s_Neto<<endl;
        cout <<"--------------------------------------------"<<endl;
    }

cout<<"\nResumen consolidado:"<<endl;
cout<<"Cantidad de empleados nombrados: " << cantNombrados << endl;
cout<<"Cantidad de empleados contratados: "<<cantContratados<<endl;
cout<<"Total acumulado de sueldos netos de empleados nombrados: " << t_sueldosNombrados<<endl;
cout<<"Total acumulado de sueldos netos de empleados contratados: "<<t_sueldosContratados<<endl;

    return 0;
}
