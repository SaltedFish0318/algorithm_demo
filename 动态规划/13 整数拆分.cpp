/*--------------------------
	方法一：
---------------------------*/
#include <iostream>

using namespace std;

const int N = 1010, MOD = 1e9 + 7;

int f[N];
/*
	可以将 n 拆成 1 2 3 4 5 6 ... n
	运用完全背包问题解决此问题，即从 [1,n] 中，选择数字且每个数字可以使用无数次，相加拼成 n
	f[i][j]：i 表示使用前 i 个数时，合成 j 的情况。
	
	f[i][j]     = f[i - 1][j] + f[i - 1][j - i] + f[i - 1][j - 2 * i] + ... + f[i - 1][j - s * i]
	f[i][j - i] =               f[i - 1][j - i] + f[i - 1][j - 2 * i] + ... + f[i - 1][j - s * i]
	
	==> f[i][j] = f[i - 1][j] + f[i][j - i]
*/

int main(){
    
    int n;
    cin >> n;
    
    f[0] = 1;
    
    for(int i = 1; i <= n; i++){
        
        for(int j = i; j <= n; j++ ){
            f[j] = (f[j] + f[j - i]) % MOD;
        }
    }
    
    cout << f[n];
    
}


/*--------------------------
	方法二：
---------------------------*/
#include <iostream>

using namespace std;

const int N = 1010, MOD = 1e9 + 7;

int f[N][N];
/*
    f[i][j]: i 是 j 个值相加的和
    
    j 个数中，最小的值等于 1 ==> f[i - 1][j - 1]
    j 个数中，最小的值不为 1 ==> f[i - j][j]
    
    ==> f[i][j] = f[i - 1][j - 1] + f[i - j][j]
    
*/

int main(){
    
    int n;
    cin >> n;
    
    f[0][0] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++ ){
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % MOD;
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++) res = (res + f[n][i]) % MOD;
    
    cout << res;
    
}