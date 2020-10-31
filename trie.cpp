#include<bits/stdc++.h>
using namespace std;
 
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define sd(val) scanf("%d",&val)
#define ss(val) scanf("%s",&val)
#define sl(val) scanf("%lld",&val)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl; 
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 

 const int alphabet_size = 26;
 struct TrieNode{
     struct TrieNode *children[alphabet_size];
     bool endOfWord;
 };
 
struct TrieNode *getNewNode(){
    struct TrieNode *newNode = new TrieNode;
    newNode->endOfWord = false;
    for(int i=0; i<alphabet_size; i++)
        newNode->children[i] = NULL;
    
    return newNode;
}

struct TrieNode *insertKey(struct TrieNode *root, string key){
    struct TrieNode *pCrawl = root;

    for(int i=0; i<key.length(); i++){
        int idx = key[i] - 'a';
        
        if(!pCrawl->children[idx])
            pCrawl->children[idx] = getNewNode();

        pCrawl = pCrawl->children[idx];        
    }
    pCrawl->endOfWord = true;
}

bool search(struct TrieNode *root, string key){
    struct TrieNode *pCrawl = root;

    for(int i=0; i<key.length(); i++){
        int idx = key[i] - 'a';
        if(!pCrawl->children[idx])
            return false;
        
        pCrawl = pCrawl->children[idx];
    }

    if(pCrawl!=NULL && pCrawl->endOfWord)
        return true;
    else
        return false;
}

int main() 
{
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n = 6;
    string keys[6] = {"hello", "parthesh", "car", "horrible", "jigsaw", "shubham"};
    
    struct TrieNode *root = getNewNode();
    
    for(int i=0; i<n; i++)
        insertKey(root, keys[i]);

    int q;
    cout << "Number of searches: " << endl;
    cin >> q;
    for(int i=0; i<q; i++){
        string key;
        cin >> key;
        cout << search(root, key) << endl;
    } 
    return 0;
   
}