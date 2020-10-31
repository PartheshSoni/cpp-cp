#define MOD 998244353


int mul(int n, int m){
    return (( n * 1ll * m) % MOD);
}


int bp(int n, int m){ 
    //binary_power
    int res = 1;
    for(; m > 0; m /= 2){
        if(m & 1)
            res = mul(res, n);
        n = mul(n, n);
    }

    return res;
}

int inv(int a){
    // If MOD is prime, use
    // fermat's little theorm
    return bp(a, MOD - 2);
}