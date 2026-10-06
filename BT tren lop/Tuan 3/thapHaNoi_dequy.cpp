#include <iostream>
using namespace std;

void thapHaNoi(int n, char goc, char dich, char trung_gian) {
    if (n <= 0) return;
    thapHaNoi(n - 1, goc, trung_gian, dich);
    cout << "Chuyen dia " << n << " tu "<< goc << " sang " << dich << endl;
    thapHaNoi(n - 1, trung_gian, dich, goc);
}

int main() {
    int n;
    cin >> n;
    thapHaNoi(n, 'A', 'B', 'C');
    cout << "Da hoan thanh thu thach Thap Ha Noi" << endl;
    return 0;
}