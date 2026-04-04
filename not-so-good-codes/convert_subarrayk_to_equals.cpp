//cses: https://cses.fi/problemset/task/1077


void solve(){

       int n,k;
  cin>>n>>k;
     vector <long long> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    if(k==1){
         for(int i=0;i<n;i++) cout<<0<<" ";
         return;
    }

multiset<long long> left,right;
long long sum_right=0,sum_left=0,ans=0;

vector<long long> temp;
for(int i=0;i<k;i++){
    temp.push_back(v[i]);
    
}

sort(temp.begin(),temp.end());

for(int i=0;i<k/2;i++){
    left.insert(temp[i]);
    sum_left+=temp[i];

}

for(int i=k/2;i<temp.size();i++){
    right.insert(temp[i]);
   // if(i!=(k/2)){
        sum_right+=temp[i];
   // }

}

    long long median = *right.begin();
    long long cost = (sum_right - median) - (long long)(right.size() - 1) * median
                   + (long long)left.size() * median - sum_left;
                   cout<<cost<<" ";

for(int i=k;i<n;i++){


    auto inR = right.find(v[i-k]);
    if(inR!=right.end()){
        //v[i-k] in right
          auto last_left=prev(left.end());

        right.erase(inR);
        sum_right-=v[i-k];

        if(v[i]>=(*last_left)){
            right.insert(v[i]);
            sum_right+=(v[i]);
        }
        else{
            left.insert(v[i]); sum_left+=v[i];
            auto it=prev(left.end());
            right.insert((*it)); sum_right+=((*it));
            sum_left-=((*it)); left.erase(it); 
        }
    }
    else{
        //v[i-k]in left
        auto inL = left.find(v[i-k]);
        left.erase(inL);
        sum_left-=v[i-k];

        if(v[i]<=(*right.begin())){
            left.insert(v[i]);
            sum_left+=v[i];
        }
        else{
            right.insert(v[i]);  sum_right+=v[i];
            auto it = right.begin();
            left.insert(*it); sum_left+=((*it));
            sum_right-=((*it)); right.erase(it);
        }


    }



    long long median = *right.begin();
    long long cost = (sum_right - median) - (long long)(right.size() - 1) * median
                   + (long long)left.size() * median - sum_left;
                   cout<<cost<<" ";

}



}