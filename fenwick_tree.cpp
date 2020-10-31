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
 

int get_next(int index){
    return index + (index & -index);
}


int get_parent(int index){
    return index - (index & -index);
}


void update_fenwick_tree(int tree[], int val, int index, int n){
    index += 1;
    while(index <= n){
        tree[index] += val;
        index = get_next(index);
    }
}


int * create_fenwick_tree(int arr[], int n){
    int *tree = new int[n+1];
    memset(tree, 0, sizeof(tree));

    for(int i = 0; i < n; i++){
        update_fenwick_tree(tree, arr[i], i, n);
    }

    return tree;
}


int get_sum(int tree[], int index){
    index += 1;
    int sum = 0;

    while(index > 0){
        sum += tree[index];
        index = get_parent(index);
    }

    return sum;
}


int main() 
{
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int *tree = create_fenwick_tree(arr, n);
    int q;
    cout << "Enter number of update queries (index new_value):";
    cin >> q;

    for(int i=0; i<q; i++){
        int idx, val;
        cin >> idx >> val;
        update_fenwick_tree(tree, idx, arr[i] - val, n);
    }

    cout << "Enter number of prefix sum queries: (index)";
    cin >> q;

    for(int i=0; i<q; i++){
        int idx;
        cin >> idx;
        cout << get_sum(tree, idx) << endl;
    }

    return 0;
   
}