#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<string> possible;
void solve(vector<int> vec,string s, string ans){
    int n=s.length();
    if((int)ans.length()==n)
    {
        possible.push_back(ans);
        return;
    }
    if(possible.size()>=1)
        return;
    int j=ans.length();
    for(int i=0;i<26;i++)
        if(vec[i] && i!=(s[j]-'a'))
        {
            char ch=i+'a';
            vec[i]--;
              if(possible.size()>=1)
              return;
            solve(vec,s,ans+ch);
            vec[i]++;
            if(possible.size()>=1)
                return;
        }
    return;
}
signed main(){
    boost;
    int t; cin >> t;
    for(int _=1;_<=t;_++){
     possible.clear();
     string s; cin >> s;
     int n=s.length();
     vector<int> vec(26,0);
     for(int i=0;i<n;i++){
         vec[s[i]-'a']++;
     }
      string ans;
     for(int i=0;i<26;i++){
        if(vec[i]>(n/2))
        {
            ans="IMPOSSIBLE";
            break;
        }
    }
      if(ans=="IMPOSSIBLE"){
        cout << "Case #"<<_<<": "<<ans<<endl;
        continue;
    }
     solve(vec,s,"");
    
     if(possible.size()==0)
        ans="IMPOSSIBLE";
    else 
        ans=possible[0];
     cout << "Case #"<<_<<": "<<ans<<endl;
    }
}