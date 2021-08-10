#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a;
    for (int i = 0; i < 7; i++) { int x; cin >> x; a.push_back(x); }
    sort(a.begin(), a.end());
    int A = a[0], B = a[1], C;
    if (a[2] == A+B) C = a[3];
    else C = a[2];
    cout << A << " " << B << " " << C << "\n";

    return 0;
}