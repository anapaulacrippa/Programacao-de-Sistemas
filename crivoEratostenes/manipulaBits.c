/*
TRABALHO 1 - PROGRAMAÇÃO DE SISTEMAS / 14138 - TURMA 01
RA 137304 - Ana Paula Loureiro Crippa

Usando o Crivo de Eratóstenes construa uma tabela de consulta (lockup
table) que permita dizer se um número inteiro positivo pertencente ao intervalo [2, 6400] é
primo ou não.
(1)Deve-se fazer uma função que seja capaz de montar essa tabela com um esforço
computacional e uso de memória mínimos e;
(2)Deve-se fazer uma função que realize consultas nessa tabela para informar se um
determinado valor é primo ou não com custo mínimo de processamento.
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

int InvBitn(int num, int n)
{
    // Inverte o valor (1 ou 0) do n-ésimo bit de num.
    // 0 =< n <= 31
    return (num ^ (1 << n));
}

int ChangeBitn(int num, int n, int b)
{
    // Modifica o valor do n-ésimo bit de num pelo valor b (0 ou 1).
    // 0 =< n <= 31
    int mask = 1 << n;
    return ((num & ~mask) | (b << p));
}