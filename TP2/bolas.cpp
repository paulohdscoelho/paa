#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n,M[1000][1000];
int soma[1000][1000 + 1];
long long memo[1000][1000];
bool done[1000][1000];

long long empilha(int r, int c){
    if(r == n) return 0;
    long long &ret = memo[r][c];

    if(!done[r][c]){
        done[r][c] = true;
        ret = 0;

        if(c > 0) ret = max(ret,empilha(r,c - 1));
        ret = max(ret,empilha(r + 1,min(n - 2 - r,c)) + soma[r][c + 1]);
    }

    return ret;
}

int main(){
    while(true){
        cin >> n;
        if(n == 0)
            break;
        for(int i = 0;i < n;++i)
            for(int j = 0;j <= i;++j)
                cin >> M[j][i-j];

        for(int i = 0;i < n;++i)
            for(int j = 0;j < n - i;++j)
                soma[i][j + 1] = M[i][j] + soma[i][j];

        memset(done,false,sizeof done);
        cout << empilha(0, n-1) << endl;
    }

    return 0;
}