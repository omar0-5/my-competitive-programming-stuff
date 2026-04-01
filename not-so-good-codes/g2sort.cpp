//codeforces problem : https://codeforces.com/contest/1692/problem/G
void solve(){
   int n,k;
   cin>>n>>k;

     vector <long long> v(n);
 for(int i=0;i<n;i++) cin>>v[i];


 vector<long long>check(n,0);

 for(int i=0;i<n-1;i++){
    if(v[i]< v[i+1]*2){
        check[i]=1;
    }
 }
  //check[n-1]=1;


 //v[n-1] =0
 //if(v[n-2] < v[n-1]*2)check[n-]


int ans=0;

 //for(int i=0;i<n;i++)cout<<check[i]<<" "; cout<<endl;

 vector<long long> pref(n+1,0);
 for(int i=1;i<=n;i++){
    pref[i]=pref[i-1]+check[i-1];
 }

 //for(int i=0;i<=n;i++)cout<<pref[i]<<" "; cout<<Endl;
//pref[n]=pref[n-1];


 for(int i=0;i<n-k;i++){
    long long val = pref[i+k+1]-pref[i];
    if(pref[i+k+1]>pref[i+k])val--;
    if(val ==k)ans++;
   // cout<<pref[i+k+1]<<" "<< pref[i];
   // cout<<endl;
 }



 cout<<ans<<endl;

   
}
 
 
 