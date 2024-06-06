#include <iostream>

using namespace std;

unsigned long seed = 1;

int rand_simple() {
    seed = (seed * 1103515245 + 12345) % 2147483648;
    return seed;
}

int main() {
    cout << "Ingrese una semilla para el generador de numeros aleatorios: ";
    cin >> seed;

    int matriz_2x3[2][3];
    int matriz_3x2[3][2];

    cout << "Matriz 2x3 original:" << endl;
    for (int i=0;i<2;++i) {
        for (int j=0;j<3;++j) {
            matriz_2x3[i][j]=rand_simple() % 10 + 1;
            cout << matriz_2x3[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"\nMatriz 3x2 original:"<<endl;
    for (int i=0;i<3;++i){
        for (int j=0;j<2;++j) {
            matriz_3x2[i][j] = rand_simple() % 10 + 1;
            cout<<matriz_3x2[i][j]<< " ";
        }
        cout<<endl;
    }

    for (int i=0;i<2;++i) {
        for (int j=0;j<3;++j) {
            if (matriz_2x3[i][j]>5) {
                matriz_2x3[i][j]=1;
            }
        }
    }

    for (int i=0;i<3;++i) {
        for (int j=0;j<2;++j) {
            if (matriz_3x2[i][j]<6) {
                matriz_3x2[i][j]=0;
            }
        }
    }
    
    cout << "\nMatriz 2x3 modificada:" << endl;
    for (int i=0;i<2;++i) {
        for (int j=0;j<3;++j) {
            cout<<matriz_2x3[i][j]<< " ";
        }
        cout<<endl;
    }

    cout<<"\nMatriz 3x2 modificada:"<<endl;
    for (int i=0;i<3;++i) {
        for (int j=0;j<2;++j) {
            cout<<matriz_3x2[i][j]<< " ";
        }
        cout<<endl;
    }

    return 0;
}
