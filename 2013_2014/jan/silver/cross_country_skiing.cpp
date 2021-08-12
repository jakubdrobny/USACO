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

const int mxn = 505;
int N, M;
int elevations[mxn][mxn], waypoints[mxn][mxn], vis[mxn][mxn];

bool check(int dif) {
    memset(vis, 0, sizeof(vis));

    queue<pii> q;
    
    FOR(i,0,N) {
        bool found = false;
        FOR(j,0,M) {
            if (waypoints[i][j]) {
                q.push({i, j});
                vis[i][j] = 1;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    while (!q.empty()) {
        int cx = q.front().fi, cy = q.front().se; q.pop();

        FOR(ind,0,4) {
            int x = cx + dx[ind], y = cy + dy[ind];
            if (x >= 0 && y >= 0 && x < N && y < M && !vis[x][y] && abs(elevations[x][y] - elevations[cx][cy]) <= dif) {
                vis[x][y] = 1;
                q.push({x, y});
            }
        }
    }

    bool ok = true;

    FOR(i,0,N) FOR(j,0,M) if (waypoints[i][j]) ok &= vis[i][j];

    return ok;
}

int main() {
    setIO("ccski");

    cin >> N >> M;
    FOR(i,0,N) FOR(j,0,M) cin >> elevations[i][j];
    FOR(i,0,N) FOR(j,0,M) cin >> waypoints[i][j];

    int l = 0, r = 1e9;
    while (l < r) {
        int m = (l + r) / 2;
        
        if (check(m)) r = m;
        else l = m + 1;
    }

    cout << l << "\n";

    return 0;
}