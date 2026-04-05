//cf : https://codeforces.com/contest/2171/problem/D

void solve(){
    int n; cin>>n;
   vector <long long> v(n);
   for(int i=0;i<n;i++) {
    cin>>v[i];  
}
    
    vector<long long>pref(n),suf(n);
    pref[0]=v[0];
    suf[n-1]=v[n-1];
    for(int i=1;i<n;i++){
        pref[i]=min(pref[i-1],v[i]);
    }
    for(int i=n-2;i>=0;i--){
        suf[i]=max(suf[i+1],v[i]);
    }


    for(int i=0;i<n-1;i++){
        if(pref[i]>suf[i+1]){
            cout<<"no"<<endl;
            return;
        }
    }
    cout<<"yes"<<endl;

}
