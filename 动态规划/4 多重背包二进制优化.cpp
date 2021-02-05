#include <iostream>

using namespace std;

int f[2010],v[11010],w[11010];

int main(){
    
    int N, V, a, b, c, k,cnt = 0;
    cin >> N >> V;
    
    for(int i = 1; i <= N; i++){
        
        cin >> a >> b >> c;
        
        k = 1;
        
        while(k <= c){
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            c -= k;
            k *= 2;
        }
        if(c > 0){
            cnt++;
            v[cnt] = a * c;
            w[cnt] = b * c;
        }
        
    }
    
    for(int i = 1; i <= cnt; i++)
        for(int j = V; j >= v[i]; j--)
            f[j] = max(f[j], f[j-v[i]] + w[i]);
            
    cout << f[V];
    
}