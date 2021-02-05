#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1010;

int f[MAX];
int v[MAX], w[MAX];

int main(){
    
    int N,V;
    cin >> N >> V;
    for(int i = 1; i <= N; i++){
        cin >> v[i] >> w[i];        
    }
    
    for(int i = 1; i <= N; i++)
        for(int j = V; j >= v[i]; j--)
            f[j] = max(f[j], f[j-v[i]] + w[i]);
            
    
    cout << f[V];
}