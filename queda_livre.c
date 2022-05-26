#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int origem;
    int destino;
    double peso;
}ARESTA ;

typedef struct {
    int x, y;
}ponto;

ARESTA arestas[300000];
ponto pontos[300000];
int p[300000];

int compare(ARESTA *a, ARESTA *b)
{
    double tmp = a->peso - b->peso;

    if (tmp > 0.0)
        return 1;
    else if (tmp < 0.0)
        return -1;
    else
        return 0;

}

int parent(int i)
{
    if(i == p[i]){
        return i;
    }
    return parent(p[i]);
}

double distancia(ponto a, ponto b)
{
    return hypot(b.x - a.x, b.y - a.y);
}

double kruskal(int n_aresta)
{
    int i, u, v;
    double teia=0;

    for (i = 0; i < n_aresta; ++i)
    {
        u = parent(arestas[i].origem);
        v = parent(arestas[i].destino);

        if (v != u) {
            p[u] = p[v];
            teia += arestas[i].peso;
        }
    }
    return teia;
}

int main(int argc, char **argv)
{
    int i, j, n, c, k;
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d", &n);

        for (i = 0, k = 0; i < n; i++)
        {
            scanf("%d %d", &pontos[i].x, &pontos[i].y);
            for (j = 0; j < i; j++)
            {
                arestas[k].origem = j;
                arestas[k].destino = i;
                arestas[k].peso = distancia(pontos[j], pontos[i]) / 100.0;
                k++;
            }
        }

        qsort(arestas, k, sizeof(ARESTA),compare);

        for (i = 0; i < n; ++i)
            p[i] = i;

        printf("%.2lf\n", kruskal(k));

    }
    return 0;
}
