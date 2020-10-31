#include<bits/stdc++.h>
using namespace std;

#define ll long long
struct bit{
    // My Fenwick tree is 0-index.
    vector<ll> a;
    int n;

    void init(int s){
        n = s;
        a = vector<ll>(n+1, 0);
    }

    int get_next(int idx){
        return idx + (idx & -idx);
    }

    void add(int idx, ll val){
        if(idx < 0) return;
        idx++;
        while(idx <= n){
            a[idx] += val;
            idx = get_next(idx);
        }
    }

    int get_parent(int idx){
        return idx - (idx & -idx);
    }

    ll query(int idx){
        idx += 1;
        ll sum = 0;

        while(idx > 0){
            sum += a[idx];
            idx = get_parent(idx);
        }
        return sum;
    }
};
 