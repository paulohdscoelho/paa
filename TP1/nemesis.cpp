#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int x, y;
}Ponto;

int toInt(char c) {
    if(isdigit(c)){
        return c-48;
    }
    return 0;
}

int row[] = { -1, 0, 1, 0 }, col[] = { 0, 1, 0 , -1 };

int dijkstra(char labirinto[600][600], Ponto hercules, Ponto euterpe, int N, int M){
    int min_dist[600][600];
    int peso_t =0;
    queue<Ponto> aVisitar;
    Ponto acao, vizinho;

    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            min_dist[i][j] = INT_MAX;
        }
    }

    min_dist[hercules.x][hercules.y] = 0;

    aVisitar.push(hercules);

    while(!aVisitar.empty()) {
        acao = aVisitar.front();
        aVisitar.pop();

        for(int i = 0; i < 4; i++) {
            vizinho = {acao.x+row[i], acao.y+col[i]};
            peso_t = min_dist[acao.x][acao.y] + toInt(labirinto[vizinho.x][vizinho.y]);

            if(labirinto[vizinho.x][vizinho.y] != '#' && min_dist[vizinho.x][vizinho.y] > peso_t) {
                min_dist[vizinho.x][vizinho.y] = peso_t;
                aVisitar.push({vizinho.x, vizinho.y});
            }
        }
    }

    return min_dist[euterpe.x][euterpe.y];
}

int main(int argc, char **argv){
    int N, M;
    Ponto hercules, euterpe;
    char labirinto[600][600], entrada;

    cin >> N >> M;

    for(int i = 0; i <= N + 1; i++) {
        for(int j = 0; j <= M + 1; j++)
            labirinto[i][j] = '#';
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> entrada;
            labirinto[i][j] = entrada;
            if(entrada == 'H'){
                hercules.x = i;
                hercules.y = j;
            }else if(entrada == 'E'){
                euterpe.x = i;
                euterpe.y = j;
            }
        }
    }

    int distancia = dijkstra(labirinto, hercules, euterpe, N, M);

    if(distancia == INT_MAX)
        cout << "ARTSKJID" << endl;
    else
        cout << distancia << endl;

    return 0;
}
