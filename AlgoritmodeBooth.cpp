#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
using namespace std;
void imprimir(int numero, int n) {
    string binario = bitset<32>(numero).to_string().substr(32 - n, n);
    cout << binario << endl; 
}

int decimal_a_binario(int decimal, int n){
    return decimal & ((1 << n)-1); //1 << n significa que toma el valor de 1 y desplaza sus bits n pocisiones hacia la izquierda
}

int complemento_2(int numero, int n){
    return (1 << n)- numero;
}

int adicion_binaria(int numero1,int numero2, int n){
    int resultado = numero1 + numero2;
    return resultado & ((1 << n)-1);
}   

int subtraccion_binaria(int minuendo, int subtraendo, int n){
    subtraendo = complemento_2(subtraendo, n); //aqui usamos el complemento 2, ya que si el resultado es negativo, estara en formato complemento 2
    return adicion_binaria(minuendo, subtraendo, n); //es la misma logica que la adicion (ahorrar linea de codigo)
}

int corrimiento_aritmetico(int numero, int n){
    int signo = (numero >> (n-1)) & 1; // Para saber el bit de signo
    int resultado = (numero >> 1) & ((1 << (n - 1)) - 1); // Corrimiento hacia la derecha sin el bit de signo
    resultado |= (signo << (n - 1)); // Restaura el bit de signo
    return resultado;
}

int multiplicacion(int multiplicando, int multiplicador, int n){
    int M = multiplicando;
    int A = 0;
    int Q = multiplicador;
    int Q_1negativo = (Q < 0) ? decimal_a_binario(-Q, n) : decimal_a_binario(Q, n);

    int S = (Q < 0) ? decimal_a_binario(-M, n) : decimal_a_binario(M, n);

    int Qn_1 = 0;
    int Qn_2 = 0;

    for(int i = 0; i < n; i++) {
        int Qn = (Q >> (n - 1 - i)) & 1;// Obtener el bit más significativo de Q

        if (Qn == 1 && Qn_1 == 0) {
            A = subtraccion_binaria(A, S, n);
            A = corrimiento_aritmetico(A, n);
            Q = corrimiento_aritmetico(Q, n);
        } else if (Qn == 0 && Qn_1 == 1) {
            A = adicion_binaria(A, S, n);
            A = corrimiento_aritmetico(A, n);
            Q = corrimiento_aritmetico(Q, n);
        }
        else if ((Qn == 0 && Qn_1 ==0)||(Qn==1&&Qn_1==1)){
            A = corrimiento_aritmetico(A, n);
            Q = corrimiento_aritmetico(Q, n);
        }
        // Realiza un corrimiento aritmético a la derecha en Q y A
        Qn_1 = Qn; // Actualiza Qn_1 para la siguiente iteración
    }

    if (Q_1negativo & (1 << (n - 1))) {
        return complemento_2(A, n);
    }

    return A;
}

int main(){
    int n;
    int multiplicando;
    int multiplicador;

    cout << "Ingrese la cantida de bits: ";
    cin >> n;

    cout << "Ingrese el multiplicando: ";
    cin >> multiplicando;

    cout << "Ingrese el multiplicador: ";
    cin >> multiplicador;

    int resultado;
    resultado = multiplicacion(multiplicando, multiplicador, n);

    cout << "El resultado decimal es: " << resultado << endl;
    cout << "El resultado en binario es: ";
    imprimir(resultado, n);   
    return 0;
}
