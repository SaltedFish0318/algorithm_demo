#include <iostream>

using namespace std;

const int MAX = 110;

int f[MAX];

int main(){
    
    int N,V,v,w,s;
    cin >> N >> V;
    
    for(int i = 1; i <= N; i++){
        
        cin >> v >> w >> s;
        
        for(int j = V; j > 0; j--)
            for(int k = 1; k <= s && k * v <= j; k++)
                f[j] = max(f[j], f[j-k*v] + k*w);
        
    }
    
    cout << f[V];
}