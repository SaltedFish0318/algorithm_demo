#include <iostream>

using namespace std;

const int MAX = 1010;

int f[MAX],v[MAX],w[MAX];

int main(){
    
    int N,V;
    cin >> N >> V;
    
    for(int i = 1; i <= N; i++) cin >> v[i] >> w[i];
    
    for(int i = 1; i <= N; i++)
        for(int j = v[i]; j <= V; j++)
            f[j] = max(f[j],f[j-v[i]] + w[i]);

            /*
                f[i][j]      = max(f[i-1][j], 【f[i-1][j-v[i]] + w[i], f[i-1][j-2*v[i]] + 2*w[i],...】)
                f[i][j-v[i]] = max(           【f[i-1][j-v[i]]       , f[i-1][j-2*v[i]] +   w[i],...】)

                f[i][j] = max(f[i-1][j], f[i][j-v[i]] + w[i])
            */
            
    
    cout << f[V];
}