#include <iostream>

using namespace std;

void floydwarshall(int n, double probabilidade[100][100]) {
    for(int k = 0; k <= n; k++) {
        for(int i = 0; i <= n; i++) {
            if(i == k)
                continue;
            for(int j = 0; j <= n; j++) {
                if(j == k || j == i)
                    continue;
                if(probabilidade[i][k] * probabilidade[k][j] > probabilidade[i][j] && probabilidade[i][k] && probabilidade[k][j])
                    probabilidade[i][j] = probabilidade[i][k] * probabilidade[k][j];
            }
        }
    }
}

int main(int argc, char **argv){
    int i, j, k, n, m;
    int origem, destino, peso;

    while (cin >> n, n)
    {
        cin >> m;
        double probabilidade[100][100] = {{ 0 }};
        for(i=0; i<m; i++){
            cin >> origem >> destino >> peso;
            probabilidade[origem][destino] = probabilidade[destino][origem] = peso *0.01;
        }

        floydwarshall(n,probabilidade);

        printf("%.6F percent\n", probabilidade[1][n] * 100);
    }
}
