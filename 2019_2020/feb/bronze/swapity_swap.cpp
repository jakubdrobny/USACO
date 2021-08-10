#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template<typename T> void ckmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void ckmax(T &a, T b) { if (a < b) a = b; }
 
#define pb push_back
#define mp make_pair
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define manytests int TT;cin >> TT; while (TT--)
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORd(i,a,b) for (int i = (a); i >= (b); --i)
 
int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1}, dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int INF = 1e9;
long long INFI = 2e18;
double PI = atan(1) * 4;
 
#define ll long long
#define ld long double
#define fi first
#define se second
#define rev reverse
 
#define vi vector<int>
#define vl vector<ll>
#define vc vector<char>
#define vd vector<double>
#define vs vector<string>
#define vld vector<ld>
#define vb vector<bool>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pl pair<ll, ll>
#define pld pair<ld, ld>
#define vpi vector<pii>
#define vpl vector<pl>
#define vpld vector<pld>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);

    int N, K; cin >> N >> K;
    
    vi a(N);
    iota(all(a), 1);

    int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;

    auto reverse_ind = [&](int i, int j) {
        --i, --j;
        int l = i, r = j;
        while (l < r) swap(a[l++], a[r--]);
        return;
    };

    vi b = a;
    int period = 0;
    do {
        reverse_ind(a1, a2);
        reverse_ind(b1, b2);
        period++;
    } while (b != a);

    K %= period;

    while (K--) {
        reverse_ind(a1, a2);
        reverse_ind(b1, b2);
    }
    FOR(i,0,N) cout << a[i] << "\n";

    return 0;
}
