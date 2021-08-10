#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

#define sz(x) (int)x.size()
#define fi first
#define se second

#define ll long long
#define ld long double

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vi a(n);
    for (int &x : a) cin >> x;
    ll ans = n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ld sm = 0;
            unordered_set<ld> st;
            for (int k = i; k <= j; k++) st.insert((ld)a[k]), sm += a[k];
            sm /= j-i+1;
            if (st.find(sm)!=st.end()) ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}