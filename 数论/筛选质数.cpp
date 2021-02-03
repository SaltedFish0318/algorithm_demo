int primes[N], cnt;
bool st[N];

//埃氏筛选法 
void get_primes(int n){
    
    for(int i = 2; i <= n; i++){
        if(!st[i]) {
            primes[cnt++] = i;
            for(int j = i + i; j <= n; j += i) st[j] = true;
        }
    }
    
}

//线性筛选法 
void get_primes(int n){
    
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] <= n / i; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
			// 当 i % primes[j] == 0 时，因为primes是递增的，所以primes[j]是 i 的最小质因子，也是 i * primes[j] 的最小质因子
			// 当 i % primes[j] != 0 时，因为primes是递增的，所以primes[j]小于 i 的最小质因子，也是 i * primes[j] 的最小质因子
			// => primes[j] 是 i * primes[j] 的最小质因子
        }
    }
}

int main(){
	get_primes(1000);
}

