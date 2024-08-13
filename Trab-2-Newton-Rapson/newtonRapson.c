/*
TRABALHO 2 - Newton-Rapson
PROGRAMAÇÃO DE SISTEMAS / 14138
*/

#include <stdio.h>
#include <math.h>

#define VAL_MIN 50
#define VAL_MAX 70
#define INCREMENTO 1
#define TOLERANCIA 0.00001
#define VIES 127

typedef union {
    float x;
    struct {
        unsigned int mantissa : 23; // para a fração
        unsigned int expoente : 8; // para o expoente com viés
        unsigned int sinal : 1; // para o sinal
    } bits;
} FloatIEEE;

float estimativaInicial(float A) {
    FloatIEEE value;
    value.x = A;
    // ajusta o expoente subtraindo 
    int expoente = value.bits.expoente - VIES;
    if (expoente > 0) { 
        // aproximação inicial
        // se o expoente for positivo
        // calcula a metada do expoente e adiciona o vies novamente
        value.bits.expoente = (expoente >> 1) + VIES;
    } 
    else {
        // se o expoente for negativo
        // define o expoente como 127
        value.bits.expoente = VIES;
    }
    // divide a mantissa por 2
    value.bits.mantissa >>= 1;

    if (expoente & 1) { // se o expoente for ímpar
        // divide o valor por 1/sqrt(2)
        value.x *= 1.4142135623730950488016887f;
    }

    return value.x;
}

float newtonRaphson(float A) {
    float x0 = estimativaInicial(A);
    // aplicação da fórmula de Newton-Rapson
    float x1 = (x0 + A / x0) * 0.5f;

    while (1) {
        // aplicação da fórmula de Newton-Rapson
        x1 = (x0 + A / x0) * 0.5f;
        
        if (x0 == x1 || (x1 - x0) < TOLERANCIA) {
            // finaliza o loop quando a estimativa está precisa
            return x1;
        }
        else {
            x0 = x1;
        }
    }
}

int main() {
    // imprimindo a tabela
    printf("Valor de A\tRaiz por Newton-Raphson\t\t\n");

    for (float A = VAL_MIN; A <= VAL_MAX; A += INCREMENTO) {
        float sqrt_newton = newtonRaphson(A);
        printf("%.1f ---------- %.10f\t\t\n", A, sqrt_newton);
    }
    
    return 0;
}
