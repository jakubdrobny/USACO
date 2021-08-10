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
   
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int N, ans = INF, timer = 0; cin >> N;
    pii cur = {0, 0};

    map<pii, int> last;
    last[cur] = timer;

    function<void()> update = [&]() {
        timer++;
        if (last.count(cur)) ckmin(ans, timer - last[cur]);
        last[cur] = timer;
    };

    FOR(i,0,N) {
        char d; int s; cin >> d >> s;
        if (d == 'N') {
            while (s--) {
                cur.se++;
                update();
            }
        } else if (d == 'S') {
            while (s--) {
                cur.se--;
                update();
            }
        } else if (d == 'W') {
            while (s--) {
                cur.fi--;
                update();
            }
        } else {
            while (s--) {
                cur.fi++;
                update();
            }
        }
    }

    cout << (ans == INF ? -1 : ans) << "\n";

    return 0;
}