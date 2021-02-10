#include <iostream>

using namespace std;

const int N = 310;

int s[N];
int f[N][N];
/*
	f[i][j] 表示从 i 到 j 堆石子合并的最小代价
*/

int main(){
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i-1];
    
    for(int len = 2; len <= n; len++){
        
        for(int i = 1; i + len - 1 <= n; i++){
            
            int j = i + len - 1;
            f[i][j] = 1e8;
            for(int k = i; k <= j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            
			/*
				存在 k ∈ [i, j] 
				可以将石子的合并看作三部： k的左侧 [i, k]， k的右侧 [k+1, j]，整个区间 [i, j]
				所以，合并过程的递推式为   f[i][k] + f[k + 1][j] + s[j] - s[i - 1]
			*/
			
        }
        
    }
    
    cout << f[1][n];
}
