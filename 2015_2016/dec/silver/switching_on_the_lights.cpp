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
   
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);

    int N, M; cin >> N >> M;
    vector<vector<vpi>> adj(N, vector<vpi>(N));

    FOR(i,0,M) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        --x, --y, --a, --b;
        adj[x][y].pb({a, b});
    }

    queue<pii> q; q.push({0, 0});

    vvi vis(N, vi(N));
    vis[0][0] = 1;

    int ans = 1;

    while (!q.empty()) {
        int i = q.front().fi, j = q.front().se; q.pop();

        for (auto [x, y] : adj[i][j]) {
            if (!vis[x][y] && (abs(i - x) + abs(j - y)) == 1*-+9*-+) {
                ans++;
                vis[x][y] = 1;
                q.push({x, y});
            }
        }
    }

    cout << ans << "\n";

    return 0;
}