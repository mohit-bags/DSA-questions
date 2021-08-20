#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

struct trienode{
    int freq;
    trienode* left;
    trienode* right;
    trienode(){
        freq=0;
        left=NULL;
        right=NULL;
    }
};
void remove(int n,trienode* cur){
    for(int i=31;i>=0;i--){
        int bit=n&(1<<i);
        if(bit){
            cur->right->freq--;
            cur=cur->right;
        }
        else{
            cur->left->freq--;
            cur=cur->left;
        }
    }
}
void insert(int n,trienode* head){
    trienode* cur=head;
    for(int i=31;i>=0;i--){
        int bit=n&(1<<i);
        if(bit){
            if(cur->right==NULL){
                cur->right = new trienode();
            }
            cur=cur->right;
            cur->freq++;
        }
        else{
            if(!cur->left)
                cur->left=new trienode();
            cur=cur->left;
            cur->freq++;
        }
    }
}
int getmaxxor(int x,trienode* cur){
    int ans=0;
    for(int i=31;i>=0;i--){
        int bit=x&(1<<i);
        if(bit){
            if(cur->left && cur->left->freq>0){
                cur=cur->left;
                ans+=(1<<i);
            }
            else
                cur=cur->right;
        }
        else{
            if(cur->right && cur->right->freq>0){
                cur=cur->right;
                ans+=(1<<i);
            }
            else
                cur=cur->left;
        }
    }
    return ans;
}
signed main(){
    int t;cin >> t;
    while(t--){
        trienode* head=new trienode();
        insert(0,head);
        int n; cin >> n;
        int tmp=0; 
        vector<int> vec(n);
        vector<int> Xor(n);
        for(int i=0;i<n;i++)
        {
            int num;cin>>num;
            vec[i]=num;
            tmp^=num;
            insert(tmp,head);
            Xor[i]=tmp;
        }
        int mx=0;
         for(int i=0;i<n;i++)
        {
           mx=max(mx,getmaxxor(Xor[i],head));
        }
        cout << mx<<endl;
    }
    return 0;
}