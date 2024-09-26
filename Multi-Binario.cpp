#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, v[10000], vect[10000], b;
    cout << "Ingrese longitud para los vectores: ";
    cin >> a;
    //cuando el tamaño del bit es 1
    if (a == 1) {
        cout << "Inserte multiplicando: ";
        cin >> v[0];
        cout << "-----------------------------\n";
        cout << "Inserte multiplicador: ";
        cin >> vect[0];
        
        int resultado = v[0] * vect[0];
        cout << "El resultado de la multiplicación de números binarios digitados es: " << resultado << endl;
        return 0;
    }

    //Cuando el usuario digite 0
    else if(a == 0){
        cout << "El bit tamaño 0 no existe" << endl;
        return 0;
    }

    //Bucle para digitar el numero a multiplicar en binario (multiplicando)
    int i = 0;
    for (; i < a; i++){
        cout << "Inserte multiplicando: ";
        cin >> v[i];
    }
  
    cout << "------------------------\n";

    //Bucle para digitar el numero a multiplicar en binario tambien (multiplicador)
    int h =0;
    for (; h < a; h++) {
        cout << "Inserte multiplicador: ";
        cin >> vect[h];
    }

    //
    int suma = 0, potencia = 0;
    for (int j = a - 1; j >= 0; j--){
        int aux = 0;
        aux = v[j] * (pow(2, potencia));
        potencia += 1;
        suma += aux;
    }

    int suma1 = 0, potencia1 = 0;
    for (int j1 = a - 1; j1 >= 0; j1--){
        int aux1 = 0;
        aux1 = vect[j1] * (pow(2, potencia1));
        potencia1 += 1;
        suma1 += aux1;
    }

    int mul, k1, co[1000], au;
    mul = (suma * suma1);
    au = mul;

    k1 = 0;
    while (au > 0){
        co[k1] = au % 2;
        au = au / 2; 
        k1++;
    }

    cout << "El resultado de la multiplicacion de numeros binarios digitado es: ";
    
    for (int x = k1 - 1; x >= 0; x--){
        
        cout << co[x];
    }
  
    cout << endl;
  
    return 0;
}