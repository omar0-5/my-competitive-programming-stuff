

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

   //int n; cin>>n;
   // vector <long long> v(n);
   // for(int i=0;i<n;i++) cin>>v[i];


const int N = 200005;
int parent[N];
int sz[N];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // path compression
}


void unite(int a, int b) {
    a = find_set(a); b = find_set(b);
    if (a != b) parent[a] = b;
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    for(int i=0;i+k-1<n;i++){
    for(int j = 0; j < k / 2; j++){        
        unite(i + j, i + k - 1 - j);
      //   for(int i=0;i<n;i++)cout<<parent[i]<<" "; cout<<Endl;

    }
    }
   long long comp=0; 
    for(int i=0;i<n;i++){
        if(find_set(i)==i){comp++;
           //         cout<<"this is i : "<<i<<endl;

        }

    }

    long long ans=power(m,comp);
   // cout<<comp<<endl;

  //  for(int i=0;i<n;i++)cout<<parent[i]<<" "; cout<<Endl;
   cout<<ans<<endl;
}


