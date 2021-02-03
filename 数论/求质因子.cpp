void divide(int n){
    
    for(int i = 2; i <= n / i; i++){
        if(n % i == 0){
            int s = 0;
            while(n % i == 0){
                s++;
                n /= i;
            }
            printf("%d %d\n",i,s);
        }
    }
    if(n > 1) printf("%d %d\n",n,1);
}