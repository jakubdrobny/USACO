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
   
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int N, B; cin >> N >> B;
    vpi a(N); FOR(i,0,N) cin >> a[i].fi >> a[i].se;

    sort(all(a));

    int ans = N;

    FOR(i,0,N) {
        vpi below, above;

        FOR(j,0,N) {
            if (a[j].se <= a[i].se) below.pb(a[j]);
            else above.pb(a[j]);
        }
        int belowInd = 0, aboveInd = 0;

        while (belowInd < sz(below) || aboveInd < sz(above)) {
            int xBorder = INF;

            if (belowInd < sz(below)) ckmin(xBorder, below[belowInd].fi);
            if (aboveInd < sz(above)) ckmin(xBorder, above[aboveInd].fi);

            while (belowInd < sz(below) && below[belowInd].fi == xBorder) belowInd++;
            while (aboveInd < sz(above) && above[aboveInd].fi == xBorder) aboveInd++;

            ckmin(ans, max(max(belowInd, sz(below) - belowInd), max(aboveInd, sz(above) - aboveInd)));
        }
    }

    cout << ans << "\n";

    return 0;
}