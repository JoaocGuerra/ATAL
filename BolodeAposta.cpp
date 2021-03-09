#include <stdio.h>

int subArraySomaM(int *apostas, int inicio, int meio, int fim ) {
    int soma, somaE = -1001, somaD = -1001;

    soma = 0;
    for (int i = meio; i >= inicio; i--) {
        soma += apostas[i];
        if (somaE > soma) somaE= somaE;
        else somaE = soma;

    }

    soma = 0;
    for (int i = meio + 1; i <= fim; i++ ) {
        soma += apostas[i];
        if (somaD > soma) somaD = somaD;
        else somaD = soma;

    }

    int maiorE_D;
    if (somaE > somaD) maiorE_D = somaE;
    else maiorE_D = somaD;

    int somaE_D = somaE + somaD;

    if (somaE_D > maiorE_D) return somaE_D;
    return maiorE_D;

}

int subArraySoma(int *apostas, int inicio, int fim) {
    if (inicio == fim) return apostas[fim];
    int meio = (inicio + fim) / 2;

    int somaE = subArraySoma(apostas, inicio, meio);
    int somaD = subArraySoma(apostas, meio + 1, fim);
    int somaM = subArraySomaM(apostas, inicio, meio, fim);

    int maxSubArrays;
    if (somaE > somaD ) maxSubArrays = somaE;
    else maxSubArrays = somaD;

    if (maxSubArrays > somaM) return maxSubArrays;
    return somaM;

}

int main () {
    int n, apostas[100001] = {};

    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++ )
            scanf("%d", &apostas[i]);
        int streak = subArraySoma(apostas, 0, n - 1);
        if (streak > 0) printf("The maximum winning streak is %d.\n",  streak);
        else printf("Losing streak.\n");
    }
}