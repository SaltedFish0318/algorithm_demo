#include <iostream>

using namespace std;

const int N = 510, INF = 1e9;

int f[N][N];

int main(){
    
    int n, c, m = 0;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++){
            cin >> f[i][j];
        }
            

    for(int i = n - 1; i >= 0; i--){
        
        for(int j = 1; j <= i; j++){
            
            f[i][j] = max(f[i][j] + f[i+1][j], f[i][j] + f[i+1][j+1]);
            //cout << f[i][j] << " ";
        }
        //puts("");
    }
    
    cout << f[1][1];
}