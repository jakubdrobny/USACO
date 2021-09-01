#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fill(x, y) memset(x, y, sizeof(x))
#define manytests int TT;cin >> TT; while (TT--)

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORd(i,a,b) for (int i = (a); i >= (b); --i)

#define ll long long
#define ld long double
#define str string
#define fi first
#define se second
#define rev reverse

int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1}, dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int INF = 1e9;
ll INFI = 1e18;
double PI = atan(1) * 4;

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

template<class T> bool ckmin(T &a, const T &b) { return (b < a ? a = b, 1 : 0); }
template<class T> bool ckmax(T &a, const T &b) { return (a < b ? a = b, 1 : 0); }

template<class T, class U> istream& operator>>(istream& in, pair<T, U> &x) { in >> x.fi >> x.se; return in; }
template<class T> istream& operator>>(istream& in, vector<T> &v) { for (auto &x : v) in >> x; return in; }

template<class T, class U> ostream& operator<<(ostream& out, const pair<T, U> &x) { out << "(" << x.fi << ", " << x.se << ")"; return out; }
template<class T> ostream& operator<<(ostream& out, const vector<T> &v) { out << "["; FOR(i,0,sz(v)) out << v[i] << (i < sz(v) - 1 ? ", " : "]"); return out; }

inline namespace FileIO {
    void setIn(str s) { freopen(s.c_str(), "r", stdin); }
	void setOut(str s) { freopen(s.c_str(), "w", stdout); }
	void setIO(str s = "") {
		cin.tie(0)->sync_with_stdio(0);
		if (sz(s)) setIn(s+".in"), setOut(s+".out");
	}
}

int main() {
    setIO("milkorder");

    int N, M, K; cin >> N >> M >> K;
    vi m(M), c(K), p(K), res(N+1); cin >> m;
    unordered_map<int, int> placed;
    FOR(i,0,K) {
        cin >> c[i] >> p[i];
        res[p[i]] = c[i];
        placed[c[i]] = p[i];
    }

    int ind = -1;
    FOR(i,1,N+1) if (res[i] == 1) ind = i;
    if (ind != -1) return cout << ind << "\n", 0;

    if (set<int>(all(m)).count(1)) {
        int i = 1, j = 0;
        while (j < M) {
            if (placed.count(m[j])) i = placed[m[j++]] + 1;
            else {
                if (res[i] == 0) res[i++] = m[j++];
                else i++;
            }
        }
        FOR(k,1,N+1) if (res[k] == 1) return cout << k << "\n", 0;
    } else {
        int i = N, j = M - 1;
        while (j >= 0) {
            if (placed.count(m[j])) i = placed[m[j--]] - 1;
            else {
                if (res[i] == 0) res[i--] = m[j--];
                else i--;
            }
        }
        FOR(k,1,N+1) if (!res[k]) return cout << k << "\n", 0;
    }
	
    return 0;
}