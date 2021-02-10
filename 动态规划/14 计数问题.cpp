#include <iostream>
#include <vector>

using namespace std;

int get(vector<int> num, int l, int r){
    
    int res = 0;
    
    for(int i = l; i >= r; i--)
        res = res * 10 + num[i];
    
    return res;
}

int power10(int x){
    int res = 1;
    while(x--) res *= 10;
    return res;
}

int count(int n, int x){
    
    if(!n) return 0;
    
    vector<int> num;
    while(n){
        num.push_back(n % 10);
        n /= 10;
    }
    
    n = num.size();
    
    int res = 0;
    for(int i = n - 1; i >= 0; i--){
        if(i == n - 1 && !x) continue;
        
        if(i < n - 1){
            res += get(num, n - 1, i + 1) * power10(i);
            if(!x) res -= power10(i);
        }
        
        if(num[i] == x) res += get(num, i - 1, 0) + 1;
        else if(num[i] > x) res += power10(i); 
    }
    
    /*
        1 ~ abcdefg 位 一共有多少个 x
        统计每一位 x 的个数
        
        例如 d 这一位
        
        当 abc 位在 000 ~ abc - 1 时 d = x，efg 可以是 000 ~ 999 有 abc * 1000种情况
        当 abc 位恰好等于 abc 时:
            当 d < x, 那 d = x 的情况不存在
            当 d = x, 那 d = x 的情况有 000 ~ efg 共有 efg + 1 种情况
            当 d > x, 那 d = x 的情况有 000 ~ 999 共有 1000 种情况
            
        特殊情况：
            当统计 0 时：
            当统计 a 位为 0 的情况，当首位为 0 的时候，作为前导 0 ，不计入统计
            当统计 d 位为 0 的情况，abc 如果等于 000 那么 d 位的 0 属于前导 0 不计入统计，应减去 000 所对应的一次 1000
    */
    
    return res;
}

int main(){
    
    int a,b;
    while(cin >> a >> b, a || b){
        
        if(a > b) swap(a, b);
        
        for(int i = 0; i < 10; i++)
            cout << count(b, i) - count(a - 1, i) << " ";
        
        puts("");
    }
    return 0;
}