#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 110;
int f[MAX];
int v[MAX],w[MAX];

int main(){
    
    int N,V;
    cin >> N >> V;
    
    for(int i = 1; i <= N; i++){
        
        int S;
        cin >> S;
        for(int j = 0; j < S; j++) cin >> v[j] >> w[j];
        for(int j = V; j > 0; j--)
            for(int k = 0; k < S; k++)
                if(v[k] <= j) f[j] = max(f[j], f[j - v[k]] + w[k]);
        
    }
    
    cout << f[V];
    
}