#include <bits/stdc++.h>
using namespace std;

void func(int p1, int p2, int n) {
    if (n == 1) {
        cout << p1 << " " << p2 << "\n";
        return;
    }
    func(p1, 6 - p1 - p2, n - 1);
    cout << p1 << " " << p2 << "\n";
    func(6 - p1 - p2, p2, n - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    func(1, 3, n);
}