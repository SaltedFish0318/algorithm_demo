#include <iostream>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    
    int n,x;
    cin >> n;
    
    unordered_map<int,int> primes;
    
    while(n--){
        cin >> x;
        
        for(int i = 2; i <= x / i; i++){
            
            while(x % i == 0){
                primes[i]++;
                x /= i;
            }
            
        }
        if(x > 1) primes[x]++;
    }
    
    long long res = 1;
    for (auto p : primes)
    {
        long long a = p.first, b = p.second;
        long long t = 1;
        while(b--) t = (t * a + 1) % MOD;
        res = (res * t) % MOD;
    }
    
    cout << res;
    
}