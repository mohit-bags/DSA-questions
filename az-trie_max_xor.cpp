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
    int q;cin >> q;
    trienode* head=new trienode();
    insert(0,head);
    while(q--){
        char ch; cin >> ch;
        int num; cin>>num;
        if(ch=='+'){
            insert(num,head);
        }
        if(ch=='-')
        {
            remove(num,head);
        }
        if(ch=='?'){
           cout <<  getmaxxor(num,head) << endl;
        }
    }
    return 0;
}