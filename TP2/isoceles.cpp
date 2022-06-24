#include <iostream>
using namespace std;

int main(){
    int v[50001], i, n, maior=0;

    cin >> n;
    v[0]=0;
    v[n+1]=0;

    for(i=1; i<=n; i++){
        cin >> v[i];

        if(v[i] > v[i-1])
            v[i] = v[i-1] +1;
    }

    for(i=n; i>=1; i--){
        if(v[i] > v[i+1])
            v[i] = v[i+1] +1;
    }

    for(i = 0; i <= n; i++)
    {
        if (v[i] > maior)
            maior = v[i];
    }
    cout << maior << endl;

    return 0;
}