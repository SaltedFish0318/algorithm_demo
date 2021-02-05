#include <iostream>

using namespace std;

const int N = 1010;

int dp[N][N];

int main(){
    
    int n,m;
    char a[N],b[N];
    
    scanf("%d%s", &n, a+1);
    scanf("%d%s", &m, b+1);
    
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int i = 0; i <= m; i++) dp[0][i] = i;
	
	/*
		初始化 当字符串 a 长度为 0 时，要变成 b 需要增加 b 的长度个字符
		初始化 当字符串 b 长度为 0 时，a 要变成 b 需要删除 a 的长度个字符
	*/
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            
            dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
            if(a[i] == b[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
            
        }
	
	/*
		当遍历到 i, j 时，有一下几种方法使得 a 到达 b
		1 当 a[i] == b[j] 时，和遍历到 i-1, j-1 时，方法一样
		2 当 a[i] != b[j] 时，为 a[i-1] -> b[j-1] 的方法数量 +1 次 字符修改操作
		3 可以从 a[i-1] -> b[j] 的方法 +1 次 删除字符的操作
		4 可以从 a[i] -> b[j-1] 的方法 +1 次 添加字符的操作 
	*/

    cout << dp[n][m];
}