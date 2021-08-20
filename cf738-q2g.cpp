#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

signed main(){
    int t;cin >> t;
    while(t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        int c=0;
        string copy=s;
        int c1=0;
        if(s[0]=='?')
        {
            s[0]='B';
            for(int i=1;i<n;i++)
            if(s[i]=='?')
            {
                if(s[i-1]=='B')
                    s[i]='R';
                else 
                    s[i]='B';
            }
            for(int i=1;i<n;i++)
                if(s[i]==s[i-1])c++;

            copy[0]='R';
            for(int i=1;i<n;i++)
            if(copy[i]=='?')
            {
                if(copy[i-1]=='B')
                    copy[i]='R';
                else 
                    copy[i]='B';
            }
            for(int i=1;i<n;i++)
                if(copy[i]==copy[i-1])c1++;
            if(c1<c)s=copy;
        }
        else{
            for(int i=1;i<n;i++)
            if(s[i]=='?')
            {
                if(s[i-1]=='B')
                    s[i]='R';
                else 
                    s[i]='B';
            }
        }
         for(int i=0;i<n;i++)
                cout << s[i];
            cout << endl;
    }
}