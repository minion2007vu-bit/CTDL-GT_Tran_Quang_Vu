#include <iostream>
#include <vector>
using namespace std;

struct sapxepthapHN {
    int n;
    char a, b, c;
    int chuyen;
};

int main() {
    int n = 3;
    vector<sapxepthapHN> HN;
    HN.push_back({n, 'A', 'B', 'C', 0});
    while (HN.size() > 0) {
        sapxepthapHN t = HN[0];
        HN.erase(HN.begin());

        if (t.n <= 0) {
            continue;
        }

        if (t.n == 1 || t.chuyen == 1) {
            cout << "Chuyen dia " << t.n << " tu " << t.a << " sang " << t.b << endl;
        } else {
            HN.insert(HN.begin(), {t.n - 1, t.c, t.b, t.a, 0});
            HN.insert(HN.begin(), {t.n, t.a, t.b, t.c, 1});
            HN.insert(HN.begin(), {t.n - 1, t.a, t.c, t.b, 0});
        }
    }

    cout << "Da hoan thanh" << endl;
    return 0;
}