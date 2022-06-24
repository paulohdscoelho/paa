#include <stdio.h>

double maximo(double a, double b){
    if(a > b)
        return a;
    return b;
}

int main(int argc, char **argv){
    int i, j, k, n, m;
    int origem, destino, peso;

    while (scanf("%d", &n), n)
    {
        scanf("%d",&m);
        double probabilidade[100][100] = {{ 0 }};
        for(i=0; i<m; i++){
            scanf("%d %d %d", &origem, &destino, &peso);
            probabilidade[origem][destino] = probabilidade[destino][origem] = peso *0.01;
        }
        for (i = 1; i <= n; i++)
            for (j = 1; j < n; j++)
                for (k = 1; k <= n; k++)
                    probabilidade[j][k] = maximo(probabilidade[j][k], probabilidade[j][i] * probabilidade[i][k]);

        printf("%.6F percent\n", probabilidade[1][n] * 100);
    }
}
