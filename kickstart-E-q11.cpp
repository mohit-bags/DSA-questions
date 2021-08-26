#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

string  gen_random(int len) {
        string s;
        static const char alphanum[] =
            "abcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < len; ++i) {
            s+= alphanum[rand() % (sizeof(alphanum) - 1)];
             }

     return s;
    
}

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

string backtr(string s){
    possible.clear();
     int n=s.length();
     vector<int> vec(26,0);
     for(int i=0;i<n;i++){
         vec[s[i]-'a']++;
     }
     solve(vec,s,"");
     string ans;
     if(possible.size()==0)
        ans="IMPOSSIBLE";
    else 
        ans=possible[0];
    return ans;
}

string pqway(string s){
   int n=s.length();
     vector<int> vec(26,0);
     for(int i=n-1;i>=0;i--){
         vec[s[i]-'a']++;
     }
    bool g1=false;
     string ans="";
    for(int i=0;i<26;i++){
        if(vec[i]>(n/2))
        {
            ans="IMPOSSIBLE";
        
        }
        if(vec[i]>1)
            g1=true;
    }
    if(!g1){
        if(n==1)return "IMPOSSIBLE";
        string ans="";
        for(int i=1;i<n;i++)
            ans+=s[i];
        ans+=s[0];
        return ans;
    }
    if(ans=="IMPOSSIBLE"){
        return ans;
    }
    priority_queue<pair<int,int>> pq;
    stack <pair<int,int>> st;
    for(int i=0;i<26;i++){
        pq.push(make_pair(vec[i],i));
    }
    
     for(int i=0;i<n-2;i++){
         while(!pq.empty()){
            pair<int,int> tmp=pq.top();
            pq.pop();
            if(tmp.second!=s[i]-'a' && tmp.first>0){
                ans+=tmp.second+'a';
                char chh = tmp.second+'a';
                tmp.first--;
                pq.push(tmp);
                break;
            }
            st.push(tmp);
         }
         while(!st.empty())
            {
            pq.push(st.top());
            st.pop();
             }
     }
    //  cout << "----"<<ans<<endl;
     if(ans.size()!=n-2)
        return "IMPOSSIBLE";
     char l,r;
     l=pq.top().second+'a';
     if(pq.top().first==2)
        r=l;
    else{
     pq.pop();
     r=pq.top().second+'a';
    }
     if(l==s[n-1])
     {
         ans+=l;
         ans+=r;
     }
     else 
        ans+=r,ans+=l;
    if(n==1)ans="IMPOSSIBLE";
     return ans;
}
signed main(){
    boost;
    int t; cin >> t;
    for(int _=1;_<=t;_++){
            string s; cin >> s;
            cout << "Case #"<<_<<": "<< pqway(s)<<endl;
            // cout << "PQWAY:" << pqway(s) << endl;
        }
}