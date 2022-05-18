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