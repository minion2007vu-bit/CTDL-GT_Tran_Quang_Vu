#include <iostream>

using namespace std;

void thapHaNoi(int soDia, char cotNguon, char cotDich, char cotPhu) {
    if (soDia == 0) return;

    thapHaNoi(soDia - 1, cotNguon, cotPhu, cotDich);
    cout << "Dia " << soDia << ": " << cotNguon << " -> " << cotDich << '\n';
    thapHaNoi(soDia - 1, cotPhu, cotDich, cotNguon);
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
