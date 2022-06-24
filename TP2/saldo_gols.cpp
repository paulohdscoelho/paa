#include <iostream>
#include <tuple>

using namespace std;

tuple<int,int,int> max_subarray(int v[], int n)
{
    int max_atual, x_temp, i, max_total, x, y;

    max_atual = 0;
    max_total = -1;
    x_temp = 0;

    for(i=0; i<n; i++)
    {
        max_atual = max_atual + v[i];
        if(max_atual < 0)
        {
            max_atual = 0;
            x_temp = i + 1;
        }
        if(max_atual >= max_total)
        {
            max_total = max_atual;
            x = x_temp;
            y = i;
        }
    }
    return {max_total, x, y};
}

int main(){
    int i,p,v[10000], nro_teste, max, a, b, x, y;
    nro_teste = 1;
    while(cin >> p ,p!=0){

        for(i=0; i<p; i++) {
            cin >> x >> y;
            v[i] = x - y;
        }

        auto[max,a,b] = max_subarray(v, p);
        cout << "Teste " << nro_teste << endl;

        if(max > 0){
            cout << a+1 << " " << b+1 << endl;
        }
        else{
            cout << "nenhum" << endl;
        }

        cout << endl;
        nro_teste++;
    }

    return 0;
}