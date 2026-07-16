#include <bits/stdc++.h>
using namespace std;
#define Endl endl
const int MAXN = 400000;
const int LIM = 6000000;

 vector<bool> isPrime(LIM, true);

void solve(){
   int n,q; cin>>n>>q;

   vector< vector<int> > v (n+1,vector<int>(n+1,0));

   for(int i =1 ;i<=n;i++){
    string s; cin>>s;
    for(int j =1;j<=n;j++){
        if(s[j-1]=='*')  v[i][j]=1;
        else v[i][j]=0;
          }
   }

  vector<vector<int>> pref(n + 1, vector<int>(n + 1, 0));

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        pref[i][j]= v[i][j] + pref[i-1][j]+ pref[i][j-1] - pref[i-1][j-1];
    }
  }



   while( q--){
    int y1,x1,y2,x2; cin>>y1>>x1>>y2>>x2;

    long long ans = pref[y2][x2]- (pref[y1-1][x2] + pref[y2][x1-1]) + pref[y1-1][x1-1];
cout<<ans<<endl;
   }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

     solve();

}
