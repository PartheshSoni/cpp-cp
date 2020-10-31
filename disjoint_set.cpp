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
 
class DJS{
    public:
        int n;
        int * rank;
        int * parent;

        unordered_map<int, int> mapp;

        DJS(int n, int data[]){
            this->n = n;
            rank = new int[n];
            parent = new int[n];

            make_set(data);
        }

        void make_set(int data[]){
            for(int i=0; i<n; i++){
                rank[i] = 0;
                parent[i] = i;
                mapp[data[i]] = i;
            }
        }

        void union_set(int data1, int data2){
            int id1 = mapp[data1];
            int id2 = mapp[data2];

            int par1 = find_parent(id1);
            int par2 = find_parent(id2);

            if(par1 == par2){
                return;
            }

            if(rank[par1] >= rank[par2]){
                rank[par1] = rank[par1] == rank[par2]? rank[par1] + 1: rank[par1];
                parent[par2] = par1;
            }
            else{
                parent[par1] = par2;
            }
        }

        int find_parent(int x){
            if(parent[x] != x){
                parent[x] = find_parent(parent[x]);
            }
            return parent[x];
        }
    };



int main() 
{
    cout << "Enter n: " << endl;
    int nn;
    cin >> nn;

    int data[nn];
    cout << "Enter numbers: ";
    for(int i=0; i<nn; i++)
        cin >> data[i];

   
    DJS obj(nn, data);
    while (true)
    {
        /* code */
        int op_type;
        cout << "1: Union, 2: Find Parent -> " << endl;
        cin >> op_type;
        if(op_type == 1){
            cout << "Enter sets data to be unioned: ";
            int o, t;
            cin >> o >> t;
            obj.union_set(o, t);
        }
        else{
            int dat;
            cout << "Enter data to find parent of: ";
            cin >> dat;
            cout << "Parent ID: " << endl;
            cout << obj.find_parent(dat) << endl;
        }
    }
    
    
    return 0;
   
}