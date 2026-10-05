#include <iostream>
#include <stack>

using namespace std;

struct CongViec {
    int soDia;
    char cotNguon, cotDich, cotPhu;
    bool chiChuyen;
};

void thapHaNoi(int soDia, char cotNguon, char cotDich, char cotPhu) {
    stack<CongViec> viecCanLam;
    viecCanLam.push({soDia, cotNguon, cotDich, cotPhu, false});

    while (!viecCanLam.empty()) {
        CongViec viec = viecCanLam.top();
        viecCanLam.pop();
        if (viec.soDia == 0) continue;

        if (viec.chiChuyen || viec.soDia == 1) {
            cout << "Dia " << viec.soDia << ": " << viec.cotNguon
                 << " -> " << viec.cotDich << '\n';
            continue;
        }

        // Stack lay viec vao sau truoc, nen day ba buoc theo thu tu nguoc.
        viecCanLam.push({viec.soDia - 1, viec.cotPhu, viec.cotDich, viec.cotNguon, false});
        viecCanLam.push({viec.soDia, viec.cotNguon, viec.cotDich, viec.cotPhu, true});
        viecCanLam.push({viec.soDia - 1, viec.cotNguon, viec.cotPhu, viec.cotDich, false});
    }
}

int main() {
    int soDia;
    if (!(cin >> soDia)) {
        cout << "So dia phai la so nguyen tu 0 den 20.\n";
        return 1;
    }
    cin >> ws;
    if (!cin.eof() || soDia < 0 || soDia > 20) {
        cout << "So dia phai la so nguyen tu 0 den 20.\n";
        return 1;
    }

    // ponytail: in toi da 2^20 - 1 buoc; tang gioi han khi can xuat bai lon hon.
    thapHaNoi(soDia, 'A', 'C', 'B');
    cout << "Tong so buoc: " << (1LL << soDia) - 1 << '\n';
    return 0;
}
