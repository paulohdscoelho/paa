#include <cstdio>
#include <iostream>

using namespace std;

#define MAXR 101
#define MAXK 10010
int grau[MAXR],dp[MAXR][MAXK],possivel,r,k;

int pontes(int regiao,int restam){
    if(possivel)
        return 1;
    if(restam < 0 || regiao > r)
        return 0;
    if(restam == 0){
        possivel = 1;
        return dp[regiao][restam] = 1;
    }
    if(dp[regiao][restam] != -1)
        return dp[regiao][restam];

    return dp[regiao][restam] = pontes(regiao+1,restam) || pontes(regiao+1,restam - grau[regiao]);
}
int main(){
    while( cin >> r >> k  && r != EOF && k != EOF){
        possivel = 0;
        for(int i=1;i<=r;i++){
            grau[i] = 0;
            for(int j=0;j<=k;j++){
                dp[i][j] = -1;
            }
        }
        for(int i=1;i<=k;i++){
            int u,v;
            cin >> u >> v;

            grau[u]++;
            grau[v]++;
        }
        if (pontes(1,k)){
            cout << 'S' << endl;
        }else{
            cout << 'N' << endl;
        }
    }
    return 0;
}
