#include <iostream>

using namespace std;

const int N = 100010;
int a[N], q[N];

int main(){
    
    int n;
    cin >> n;
    
    for(int i = 0;i < n; i++) cin >> a[i];
    
    int len = 0;
    q[0] = -2e9;
    for(int i = 0; i< n; i++){
        
        int l = 0, r = len;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        
        len = max(len, r + 1);
        q[r + 1] = a[i];
				
		/*
			q[i]: 长度为 i 的上升子序列，末尾的最小值
			用二分法，找到 r 使得 q[r] 为 0 到 len 中最后一个小于 a[i] 的位置
			因为 q[r] < a[i] , q[r + 1] > a[i]
			所以 a[i] 直接填入 q[r] 后面一个位置 q[r + 1] 作为长度为 r + 1 的上升子序列中，末尾值的最小数值
		*/
        
    }
    
    cout << len;
    
}