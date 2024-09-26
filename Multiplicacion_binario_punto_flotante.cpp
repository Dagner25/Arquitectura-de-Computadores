#include <iostream>
#include <bitset>
#include <climits>
#include <cmath>

using namespace std;


void multiplicacion(float x, float y) {
    int bias = (1 << 7) - 1;

    union {
        float input;
        int bits;
    } data1, data2, result;

    data1.input = x;
    data2.input = y;


    int sign1 = (data1.bits >> 31) & 1;
    int sign2 = (data2.bits >> 31) & 1;

    int exponent1 = ((data1.bits >> 23) & ((1 << 8) - 1)) - bias;
    int exponent2 = ((data2.bits >> 23) & ((1 << 8) - 1)) - bias;

    int significand1 = (data1.bits & ((1 << 23) - 1)) | (1 << 23); 
    int significand2 = (data2.bits & ((1 << 23) - 1)) | (1 << 23); 

    
    long long product = static_cast<long long>(significand1) * significand2;

   
    int exponent_result = exponent1 + exponent2 + bias;


    if (product & (1LL << 47)) {
        product >>= 1;
        exponent_result++;
    }

    if (exponent_result > (1 << 8) - 1) {
        result.bits = (sign1 ^ sign2) << 31 | ((1 << 8) - 1) << 23;
    } 
    
    else if (exponent_result < 0) {
        result.bits = (sign1 ^ sign2) << 31;
    } 
    
    else {
        result.bits = (sign1 ^ sign2) << 31 | (exponent_result + bias) << 23 | ((product >> 24) & ((1 << 23) - 1));
    }
    int resultado_binario = result.bits;

    cout << "Resultado en binario:" << bitset<23>(resultado_binario) << endl;
}

int main() {
    float x, y;
    cout << "Digite el primer número flotante: ";
    cin >> x;
    cout << "Digite el segundo número flotante: ";
    cin >> y;

    multiplicacion(x, y);

    return 0;
}

