int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
// gcd(a, b) = gcd(b, a % b)
// a % b = a - c * b
// a % x == 0, b % x == 0  ===>   (a - c * b) % x == 0
// gcd(a,0) == a