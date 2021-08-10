#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

#define sz(x) (int)x.size()
#define fi first
#define se second

#define ll long long
#define ld long double

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define vl vector<ll>
#define pii pair<int, int>
#define vpi vector<pii>

int Infinity = 1000000001;

struct Cow {
    int time_stopped;
    int x, y;
    char dir;
};

int N;
Cow C[50];

int when_hits(int i, int j, int current_time) {
    Cow I = C[i], J = C[j];
    if (I.dir == J.dir) return Infinity;
    if (I.dir == 'E') swap(I.x, I.y), swap(J.x, J.y);
    if (J.y <= I.y) return Infinity;
    if (J.time_stopped == Infinity) {
        if (I.x < J.x - current_time || I.x >= J.x + J.y - I.y) return Infinity;
    } else {
        if (I.x > J.x || I.x < J.x - J.time_stopped) return Infinity;
    }
    return current_time + J.y - I.y;
}

int advance_to_next_event(int current_time) {
    int T[50], minT = Infinity;

    for (int i = 0; i < N; i++) {
        T[i] = Infinity;
        if (C[i].time_stopped == Infinity) {
            for (int j = 0; j < N; j++) {
                int t = when_hits(i, j, current_time);
                if (t < T[i]) T[i] = t;
            }
            if (T[i] < minT) minT = T[i];
        }
    }

    if (minT == Infinity) return Infinity;

    for (int i = 0; i < N; i++) {
        if (C[i].time_stopped == Infinity) {
            if (C[i].dir == 'N') C[i].y += minT - current_time;
            else C[i].x += minT - current_time;
        }
        if (T[i] == minT) C[i].time_stopped = minT;
    }

    return minT;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> C[i].dir >> C[i].x >> C[i].y;
        C[i].time_stopped = Infinity;
    }

    int current_time = 0;
    do { current_time = advance_to_next_event(current_time); }
    while (current_time != Infinity);

    for (int i = 0; i < N; i++) {
        if (C[i].time_stopped == Infinity) cout << "Infinity\n";
        else cout << C[i].time_stopped << "\n";
    }

    return 0;
}