#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define all(x)     (x).begin(), (x).end()
#define rall(x)    (x).rbegin(),(x).rend()
#define dbg(...) __func(#__VA_ARGS__, __VA_ARGS__)

template <typename T> void __func(const char* name, T&& x) { cerr << name << " : " << x << '\n'; }
template <typename T, typename... V> void __func(const char* names, T&& x, V&&... y){
    cerr.write (names, strchr(names+1, ',')-names) << " : " << x << " | "; __func (strchr(names+1, ',')+1, y...);
}
template <typename T> using orset =  tree<T, null_type, less<T>,  rb_tree_tag,   tree_order_statistics_node_update>;
template <typename T, typename V> using ormap = tree<T, V, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> istream& operator>>(istream& is,  vector<T> &a){for (auto &x : a) is >> x;         return is;}
template <typename T> ostream& operator<<(ostream& os,  vector<T>  a){for (auto &x : a) os << x << ' ';  return os;}

const long long inf = 1e18;
const int N = 300020;
const int mod = 1e9+7;

void solution(){






}

bool TEST_CASE = 1;
bool CASE_PRINT = 0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    if(TEST_CASE) cin >> T;
    for(int i=1;i<=T;i++){
        if(CASE_PRINT) cout << "Case " << i << ": ";
        solution();
    }
    return 0;
}
