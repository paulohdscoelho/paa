#include <iostream>
using namespace std;

int main(){

    long long resultado, unidade;
    int n, i, custo;

    while(cin >> n, n!=0){
        unidade = 0;
        resultado = 0;
        for(i=0; i<n; i++){
            cin >> custo;
            unidade += custo;
            resultado+=abs(unidade);
        }
        cout << resultado << endl;
    }

    return 0;
}