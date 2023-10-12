#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define I_love_you_Liny ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define int long long int
#define all(x)     (x).begin(), (x).end()
#define rall(x)    (x).rbegin(),(x).rend()

template <typename T> using orset =  tree<T, null_type, less<T>,  rb_tree_tag,   tree_order_statistics_node_update>;
template <typename T, typename V> using ormap = tree<T, V, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> istream& operator>>(istream& is,  vector<T> &a){for (auto &x : a) is >> x;         return is;}
template <typename T> ostream& operator<<(ostream& os,  vector<T>  a){for (auto &x : a) os << x << ' ';  return os;}
template <typename T> ostream& operator<<(ostream& os,  set<T>  s){for (auto &x : s) os << x << ' ';     return os;}
template <typename T> ostream& operator<<(ostream& os,  multiset<T>  s){for (auto &x : s) os << x << ' ';return os;}
template <typename T, typename V> void operator+=(vector<T>& a, const V value) { for(auto &x : a)x += value; }
template <typename T, typename V> void operator-=(vector<T>& a, const V value) { for(auto &x : a)x -= value; }
template <typename T, typename V> void operator*=(vector<T>& a, const V value) { for(auto &x : a)x *= value; }
template <typename T, typename V> void operator/=(vector<T>& a, const V value) { for(auto &x : a)x /= value; }
template <typename T> void operator++(vector<T>& a) { a += 1; }
template <typename T> void operator--(vector<T>& a) { a -= 1; }


const long long inf = 0x3f3f3f3f3f3f3f3f;
const int N = 301000;
const int mod = 1000000007;

int n;
int p[N],c[N];

void csort(){
    //vector<int>cnt(n);
    int cnt[n];
    for(int i=0;i<n;i++) cnt[c[i]]++;
    int p_new[n];
    int pos[n];

    pos[0] = 0;
    for(int i=1;i<n;i++){
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for(int i=0;i<n;i++){
        p_new[pos[c[p[i]]]] = p[i];
        pos[c[p[i]]]++;
    }

    for(int i=0;i<n;i++) p[i] = p_new[i];

}

void make_suff_array(string s){
    //n++;
    vector<pair<char,int>>a(n);
    for(int i=0;i<n;i++) a[i] = {s[i],i};
    sort(all(a));

    for(int i=0;i<n;i++) p[i] = a[i].second;
    c[p[0]] = 0;
    for(int i=1;i<n;i++){
        if(a[i].first ==a[i-1].first){
            c[p[i]] = c[p[i-1]];
        }
        else c[p[i]] = c[p[i-1]] + 1;
    }

    int k = 0;
    while((1 << k) < n){

        for(int i=0;i<n;i++){
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        csort();
        int c_new[n];
        c_new[p[0]] = 0;
        for(int i=1;i<n;i++){
            pair<int,int> prev = {c[p[i-1]],c[(p[i-1] + (1 << k) + n) % n]};
            pair<int,int> now = {c[p[i]],c[(p[i] + (1 << k) + n) % n]};
            if(prev==now) c_new[p[i]] = c_new[p[i-1]];
            else c_new[p[i]] = c_new[p[i-1]] + 1;
        }
        for(int i=0;i<n;i++) c[i] = c_new[i];
        //c = c_new;
        k++;
    }

//    for(int i=0;i<n;i++){
//        cout << p[i] << ' ' << s.substr(p[i],n - p[i]) << '\n';
//    }

}


void solution(){
    string s;
    cin >> s;
    s+="$";
    n = s.size();
    make_suff_array(s);
    for(int i=0;i<n;i++) cout << p[i] << ' ';

}

bool multi_test = 0;

int32_t main(){

    I_love_you_Liny;

    int T = 1;
    if(multi_test) cin >> T;
    while(T--) solution();

    return 0;

}

