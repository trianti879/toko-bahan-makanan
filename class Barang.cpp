#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

using namespace std;

class Barang {
public:
    string nama;
    int harga;

    Barang(string nama, int harga) {
        this->nama = nama;
        this->harga = harga;
    }
};

class Transaksi {
public:
    vector<Barang> daftarBarang;

    void tambahBarang(Barang barang) {
        if (barang.harga < 0) {
            throw runtime_error("Harga tidak boleh negatif");
        }
        daftarBarang.push_back(barang);
    }

    int hitungTotal() {
        int total = 0;
        for (int i = 0; i < daftarBarang.size(); i++) {
            total += daftarBarang[i].harga;
        }
        return total;
    }

    void tampilkanStruk() {
        cout << "=== STRUK BELANJA ===" << endl;
        for (int i = 0; i < daftarBarang.size(); i++) {
            cout << daftarBarang[i].nama << " : Rp"
                 << daftarBarang[i].harga << endl;
        }
        cout << "----------------------" << endl;
        cout << "TOTAL : Rp" << hitungTotal() << endl;
    }
};
void testHitungTotal() {
    Transaksi t;
    t.tambahBarang(Barang("Beras", 10000));
    t.tambahBarang(Barang("Gula", 5000));

    int hasil = t.hitungTotal();

    if (hasil == 15000)
        cout << "Unit Test Total Belanja: PASS" << endl;
    else
        cout << "Unit Test Total Belanja: FAIL" << endl;
}
void testInputBarang() {
    try {
        Transaksi t;
        t.tambahBarang(Barang("Minyak", 20000));
        cout << "Unit Test Input Barang: PASS" << endl;
    } catch (...) {
        cout << "Unit Test Input Barang: FAIL" << endl;
    }
}
void integrationTest() {
    try {
        Transaksi t;

        t.tambahBarang(Barang("Telur", 12000));
        t.tambahBarang(Barang("Susu", 15000));

        int total = t.hitungTotal();

        t.tampilkanStruk();

        if (total == 27000)
            cout << "Integration Test Toko: PASS" << endl;
        else
            cout << "Integration Test Toko: FAIL" << endl;

    } catch (...) {
        cout << "Integration Test Toko: FAIL" << endl;
    }
}
int main() {
    testHitungTotal();
    testInputBarang();
    integrationTest();
    return 0;
}
