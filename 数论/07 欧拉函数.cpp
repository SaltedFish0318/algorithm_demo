#include <iostream>

using namespace std;

int ol(int n){
    double res = n;
    
    int i = 2;
    for(int i = 2; i <= n / i; i++){
        if(n % i == 0){
            res *= ((double)(i-1)/i);
            while(n % i == 0) n /= i;
        }
    }
    
    if(n > 1)  res *= ((double)(n - 1) / n);
    
    return res;
}

int main(){
    
    int n;
    cin >> n;
    
    while(n--){
        int c;
        cin >> c;
        cout << ol(c) << endl;
    }
    
}