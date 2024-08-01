/*
TRABALHO 1 - PROGRAMAÇÃO DE SISTEMAS / 14138
*/

#include <stdio.h>

int SetBitn(int num, int n) {
    // seta o n-ésimo bit de num com o valor “1”
    // 0 =< n <= 31
    // shiftar 1 para esquerda n vezes e realizar um bitwise OR com o próprio num
                // 1 | 0 = 1
                // 1 | 1 = 1
    return ((1 << n) | num);
}

int ResetBitn(int num, int n) {
    // seta o n-ésimo bit de num com o valor “0”
    // 0 =< n <= 31
    // shiftar 1 para esquerda n vezes e negar todos os bits desse resultado
    // e realizar um bitwise & com o próprio num // num &= ~(1 << n); return num;
    return (num & (~(1 << n)));
}

int GetBitn(int num, int n) {
    // recupera o valor (1 ou 0) do n-ésimo bit de num.
    // 0 =< n <= 31
    return ((num & (1 << n)) >> n);
}

int InvBitn(int num, int n) {
    // Inverte o valor (1 ou 0) do n-ésimo bit de num.
    // 0 =< n <= 31
    return (num ^ (1 << n));
}

int ChangeBitn(int num, int n, int b) {
    // Modifica o valor do n-ésimo bit de num pelo valor b (0 ou 1).
    // 0 =< n <= 31
    int mask = 1 << n;
    return ((num & ~mask) | (b << p));
}
