// Implementacao do Algoritmo de Dinic para fluxo maximo em redes
//
// Para usar, basta declarar com o numero de vertices
// vertices sao indexados com 0, 1, ... n-1
//
// Exemplo:
//
// dinic D(10); // teremos 10 vertices indexados de 0 a 9
// D.add(0, 1, 5); // adiciona aresta de 0 a 1 com capacidade 5
// int flow = D.max_flow(0, 1); // computa o fluxo maximo de 0 a 1

#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <set>

using namespace std;

struct dinic {
    struct edge {
        int to, cap, rev, flow;
        bool res;
        edge(int to_, int cap_, int rev_, bool res_)
                : to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
    };

    vector<vector<edge>> g;
    vector<int> lev, beg;
    long long F;
    dinic(int n) : g(n), F(0) {}

    void add(int a, int b, int c) {
        g[a].emplace_back(b, c, g[b].size(), false);
        g[b].emplace_back(a, 0, g[a].size()-1, true);
    }
    bool bfs(int s, int t) {
        lev = vector<int>(g.size(), -1); lev[s] = 0;
        beg = vector<int>(g.size(), 0);
        queue<int> q; q.push(s);
        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto& i : g[u]) {
                if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
                lev[i.to] = lev[u] + 1;
                q.push(i.to);
            }
        }
        return lev[t] != -1;
    }
    int dfs(int v, int s, int f = 0x3f3f3f3f) {
        if (!f or v == s) return f;
        for (int& i = beg[v]; i < g[v].size(); i++) {
            auto& e = g[v][i];
            if (lev[e.to] != lev[v] + 1) continue;
            int foi = dfs(e.to, s, min(f, e.cap - e.flow));
            if (!foi) continue;
            e.flow += foi, g[e.to][e.rev].flow -= foi;
            return foi;
        }
        return 0;
    }
    long long max_flow(int s, int t) {
        while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
        return F;
    }
};

int main(int argc, char **argv){
    int N, M, G, a, b, i, j, k, S, T, V, jogos_flux, cap_jogos, max_flow, pontos_restantes;
    int pontos[40], jogos[40][40];
    char op;
    bool flag;

    while(cin >> N >> M >> G && N > 0 && M > 0 && G > 0){
        for(i = 0; i < N; i++){
            pontos[i] = 0;
            for (j = 0; j < N; j++)
                jogos[i][j] = M;
        }
        for(i = 0; i < G; i++){
            cin >> a >> op >> b;
            jogos[a][b]--;
            jogos[b][a]--;
            if(op == '=')
            {
                pontos[a]++;
                pontos[b]++;
            }
            else
            {
                pontos[b] += 2;
            }
        }

        for(i = 1; i < N; i++)
            pontos[0] += 2 * jogos[0][i];

        flag = true;
        for(i = 1; i < N; i++){
            if(pontos[i] >= pontos[0]){
                flag = false;
            }
        }

        if(!flag)
        {
            cout << "N" << endl;
            continue;
        }

        V = N*N+N+2;
        dinic D(V);

        S = V-1;
        T = V-2;
        k = N;
        pontos_restantes=0;
        for(i = 1; i < N; i++) {
            for(j=1; j < N; j++){
                if(i > j){
                    pontos_restantes += jogos[i][j]*2;
                    D.add(S, k, jogos[i][j]*2);

                    D.add(k, i, jogos[i][j]*2);
                    D.add(k, j, jogos[i][j]*2);
                    D.add(i,T, pontos[0]-pontos[i]-1);
                    k++;
                }
            }
        }

        max_flow = D.max_flow(S,T);
        if(pontos_restantes == max_flow)
            cout << "Y" << endl;
        else
            cout << "N" << endl;

    }

    return 0;
}
