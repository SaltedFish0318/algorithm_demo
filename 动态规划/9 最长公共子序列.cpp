#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1010;

int dp[MAX][MAX];
char A[MAX],B[MAX];

int main(){
    
    int N, M;
    cin >> N >> M;
    
    scanf("%s%s", A+1, B+1);
    
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++){
            
            if(A[i] == B[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			
			/*
				dp[i][j] 表示 字符串A[1...i] 与 字符串B[1...j] 的最长公共子序列长度 
				
				当 A[i] == B[j] 时，最长公共子序列的长度为 A[1...i-1] 与 B[1...j-1] 的最长公共子序列长度 +1
				当 A[i] != B[j] 时
						最长公共子序列的长度可能为 A[1...i-1] 与 B[1...j] 的最长公共子序列长度
					或  最长公共子序列的长度可能为 A[1...i] 与 B[1...j-1] 的最长公共子序列长度
					即  最长公共子序列的长度为 max(dp[i][j-1], dp[i-1][j])
			*/
            
        }
        
    cout << dp[N][M];
    
}