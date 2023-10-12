const int SIEVE = 1000005;

int lp[SIEVE+1];
vector<int> primes;

void sieve(int m){  /*call*/ // For any number , call upto sqrt(number) is enough
    for (int i=2; i<=m; ++i){
        if (lp[i] == 0){ lp[i] = i; primes.push_back(i); }
        for(int j=0;j<primes.size() && primes[j]<=lp[i] && i*primes[j] <= m;j++) lp[i*primes[j]] = primes[j];
    }
}

vector<pair<int,int>>factorize(int n){
    int tmp = n;
    vector<pair<int,int>>res;
    for(auto x : primes){
        if(x*x>tmp) break;
        if(tmp%x) continue;
        int p = 0;
        while(tmp%x==0){ tmp/=x, p++;}
        res.push_back({x,p});
    }
    if(tmp>1) res.push_back({tmp,1});
    return res;
}
