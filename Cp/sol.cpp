#include <bits/stdc++.h>
using namespace std;
#define int long long

string smallestWithSum(int k, int len) {
    string res(len, '0');
    for (int i = 0; i < len; i++) {
        for (int d = (i == 0); d <= 9; d++) {
            int rem = k - d;
            int maxRem = 9 * (len - i - 1);
            if (rem >= 0 && rem <= maxRem) {
                res[i] = '0' + d;
                k -= d;
                break;
            }
        }
    }
    return (k == 0 ? res : "-1");
}

string largestWithSum(int k, int len) {
    string res(len, '0');
    for (int i = 0; i < len; i++) {
        for (int d = 9; d >= (i == 0); d--) {
            int rem = k - d;
            int maxRem = 9 * (len - i - 1);
            if (rem >= 0 && rem <= maxRem) {
                res[i] = '0' + d;
                k -= d;
                break;
            }
        }
    }
    return (k == 0 ? res : "-1");
}

signed main() {
    int l, r, k;
    cin >> l >> r >> k;

    int lenL = to_string(l).size();
    int lenR = to_string(r).size();

    string smallest = "-1", largest = "-1";
    for (int len = lenL; len <= lenR; len++) {
        string s = smallestWithSum(k, len);
        if (s != "-1") {
            int val = stoll(s);
            if (val >= l && val <= r) {
                smallest = s;
                break;
            }
        }
    }

    for (int len = lenR; len >= lenL; len--) {
        string s = largestWithSum(k, len);
        if (s != "-1") {
            int val = stoll(s);
            if (val >= l && val <= r) {
                largest = s;
                break;
            }
        }
    }

    cout << smallest << " " << largest << "\n";
    return 0;
}
