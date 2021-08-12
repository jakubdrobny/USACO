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

const int mxn = 3005;
vvi pasture(mxn, vi(mxn));

int neigh_count(int x, int y) {
    if (!pasture[x][y]) return 0;
    int res = 0;
    FOR(i,0,4) res += pasture[x + dx[i]][y + dy[i]];
    return res;
}

int main() {
    setIO();

    int N, cnt = 0; cin >> N;
    
    FOR(i,0,N) {
        int x, y; cin >> x >> y;
        x += 1000, y += 1000;

        FOR(ind,0,4) {
            int nc = neigh_count(x + dx[ind], y + dy[ind]);
            if (nc == 3) cnt--;
            else if (nc == 2) cnt++;
        }

        cnt += neigh_count(x, y) == 3;
        pasture[x][y] = 1;

        cout << cnt << "\n";
    }

    return 0;
}