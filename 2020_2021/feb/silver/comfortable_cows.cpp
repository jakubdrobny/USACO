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

int main() {
    setIO();

    int N, ans = 0; cin >> N;
    vvi adj(3000, vi(3000)), vis(3000, vi(3000));

    function<void(int, int)> add = [&](int x, int y) {
        if (!vis[x][y]) {
            vis[x][y] = 1;
            ans++;
            if (vis[x][y] && adj[x][y] == 3) FOR(ind,0,4) add(x + dx[ind], y + dy[ind]);
            FOR(ind,0,4) {
                int xx = x + dx[ind], yy = y + dy[ind];
                adj[xx][yy]++;
                if (vis[xx][yy] && adj[xx][yy] == 3) {
                    FOR(ind2,0,4) add(xx + dx[ind2], yy + dy[ind2]);
                }
            }
        }
    };

    FOR(i,0,N) {
        int x, y; cin >> x >> y;
        x += 1000, y += 1000;
        ans--;
        add(x, y);
        cout << ans << "\n";
    }

    return 0;
}