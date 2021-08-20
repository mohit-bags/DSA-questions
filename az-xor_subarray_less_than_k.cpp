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
int getkxor(int x,trienode* cur,int k){
    int ans=0;
   
    for(int i=31;i>=0;i--){
         if(cur == NULL) {
            break;
        }
        int bit = x&(1<<i);
        int kth = k&(1<<i);
       
        if(bit!=kth){
            if(kth)
                if(cur->left)
                    ans+=cur->left->freq;
            cur=cur->right;
        }
        else{
            if(kth)
                if(cur->right)
                ans+=cur->right->freq;
            
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
        int n; cin >> n; int k; cin >> k;
        int tmp=0; 
        vector<int> vec(n);
         vector<int> Xor(n);
                 int mx=0;

        for(int i=0;i<n;i++)
        {
            int num;cin>>num;
            vec[i]=num;
            tmp^=num;
            Xor[i]=tmp;
            mx+=getkxor(Xor[i],head,k);
             insert(tmp,head);
        }
        
        cout << mx<<endl;
    }
    return 0;
}