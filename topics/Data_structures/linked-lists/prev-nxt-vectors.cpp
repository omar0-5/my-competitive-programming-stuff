//cf link : https://codeforces.com/contest/2166/problem/C
//use: 
//vector<int> nxt(n), prev(n);
// to track index of the next and prev of a certain element
//to remove element k:
   // prev[nxt[k]]=prev[k];
   // nxt[prev[k]]=nxt[k];
  
//

void solve(){

   int n; cin>>n;
   vector <long long> v(n);
   for(int i=0;i<n;i++) cin>>v[i];

   set<pair<long long,int>> me;

for(int i=0;i<n;i++){
    me.insert({v[i],i});
}


vector<int> nxt(n), prev(n);
for(int i = 0; i < n; i++){
    prev[i] = (i - 1 + n) % n;
    nxt[i] = (i + 1) % n;
}

// for(int i=0;i<n;i++) cout<<prev[i]<<" "; cout<<endl;
// for(int i=0;i<n;i++) cout<<nxt[i]<<" "; cout<<endl;





long long ans=0;

for(int i=0;i<n-1;i++){
    auto it=me.begin();
    long long smalles_inedex=it->second;

    int r=nxt[smalles_inedex],l=prev[smalles_inedex];

    // while(v[r]==0){
    //     r=(r+1)%n;
    // }
    //     while(v[l]==0){
    //     l=(l-1+n)%n;
    // }

    
    ans+=min(v[r],v[l]);

    prev[nxt[smalles_inedex]]=prev[smalles_inedex];
    nxt[prev[smalles_inedex]]=nxt[smalles_inedex];
  

    me.erase(it);
}

cout<<ans<<endl;





}