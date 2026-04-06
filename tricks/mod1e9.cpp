
long long mod=1e9+7;

long long power(long long x, long long y){
    long long res = 1;
    x=x%mod;
    while(y){
        if(y & 1) res =res * x %mod;
        x = x*x%mod;
        y >>= 1;
    }
    return res;
}

/*
x=2,  res=1
y=10 (1010 in binary)

step 1: y&1=0, x = 2*2=4,      y=5
step 2: y&1=1, res = 1*4=4,    x = 4*4=16,    y=2
step 3: y&1=0, x = 16*16=256,  y=1
step 4: y&1=1, res = 4*256=1024, x = 256*256, y=0

return 1024 = 2^10 ✓
*/