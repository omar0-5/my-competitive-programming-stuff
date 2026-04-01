//cf link: https://codeforces.com/contest/1692/problem/F
//brute force for three pointers 

//to solve time complexity shorten the array (observation)

void solve(){


   int n; cin>>n;
   vector <long long> v(n);
   for(int i=0;i<n;i++) cin>>v[i];

   for(int i=0;i<n;i++){
    while(v[i]>=10){
        v[i]%=10;
    }
   }

   //for(int i=0;i<n;i++) cout<<v[i]<<" ";

   vector<long long>shortv;
   map<long long,int>mp;
   for(int i=0;i<n;i++){
    mp[v[i]]++;
   }

   for(auto& me : mp){
    int temp=me.second;
    if(temp>3) temp=3;
    while(temp--)shortv.push_back(me.first);

   }

   int shortv_size=shortv.size();



   int a=0,b=1;
   while(a<shortv_size){
    b=a+1;
        while(b<shortv_size){
                int it=b+1;
                while(it<shortv_size){
                    long long val= shortv[a]+shortv[b]+shortv[it];
                    while(val>=10){val%=10;}

                    if(val==3){
                        cout<<"yes"<<endl;
                        return;
                    }
                    //cout<<val<<endl;
                  // cout<<v[a]<<" "<<v[b]<<" "<<v[it]<<endl;

                    it++;
                }
               
                b++;
        }
        a++;
}

cout<<"no"<<endl;


}
