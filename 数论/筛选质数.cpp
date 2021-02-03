int primes[N], cnt;
bool st[N];

//∞£ œ…∏—°∑® 
void get_primes(int n){
	for (int i = 2; i <= n; i ++ ){
		if (!st[i]){
			primes[cnt ++ ] = i;
			for (int j = i + i; j <= n; j += i) st[j]= true;
		}
	}
}

