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
#define str string
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

inline namespace FileIO {
    void setIn(str s) { freopen(s.c_str(), "r", stdin); }
	void setOut(str s) { freopen(s.c_str(), "w", stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0);
		if (sz(s)) setIn(s+".in"), setOut(s+".out");
	}
}

const int mxn = 105;
int N, M, ans = 1, vis[mxn][mxn], lit[mxn][mxn];
vector<vector<vpi>> g;

void dfs(int x, int y) {
    if (x <= 0 || y <= 0 || x > N || y > N || !lit[x][y] || vis[x][y]) return;

    vis[x][y] = 1;

    if (sz(g[x][y])) {
        for (auto [nx, ny]: g[x][y]) {
            if (!lit[nx][ny]) {
                lit[nx][ny] = 1;
                ans++;
                FOR(ind,0,4) {
                    if (nx + dx[ind] > N || nx + dx[ind] <= 0) continue;
                    if (ny + dy[ind] > N || ny + dy[ind] <= 0) continue;
                    if (vis[nx + dx[ind]][ny + dy[ind]]) dfs(nx, ny);
                }
            }
        }
    }

    FOR(ind,0,4) dfs(x + dx[ind], y + dy[ind]);
}

int main() {
    setIO("lightson");

    cin >> N >> M;
    g.assign(N+1, vector<vpi>(N+1));

    FOR(i,0,M) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        g[x][y].pb({a, b});
    }

    lit[1][1] = 1;
    dfs(1, 1);

    cout << ans << "\n";

    return 0;
}