#include <iostream>
using namespace std;

struct Pegawai {
    int id;
    char nama[50];
    double gaji;
};

Pegawai daftarPegawai[100];
int jumlahPegawai = 0;

int main() {
    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Pegawai\n";
        cout << "2. Lihat Daftar Pegawai\n";
        cout << "3. Cari Pegawai\n";
        cout << "4. Perbarui Gaji Pegawai\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;
        
        if (pilihan == 1) {
            if (jumlahPegawai >= 100) {
                cout << "Data pegawai penuh!" << endl;
                continue;
            }
            Pegawai p;
            cout << "Masukkan ID: ";
            cin >> p.id;
            cout << "Masukkan Nama: ";
            cin.ignore();
            cin.getline(p.nama, 50);
            cout << "Masukkan Gaji: ";
            cin >> p.gaji;
            daftarPegawai[jumlahPegawai++] = p;
        } 
        else if (pilihan == 2) {
            if (jumlahPegawai == 0) {
                cout << "Tidak ada data pegawai." << endl;
                continue;
            }
            for (int i = 0; i < jumlahPegawai; i++) {
                cout << "ID: " << daftarPegawai[i].id << ", Nama: " << daftarPegawai[i].nama << ", Gaji: " << daftarPegawai[i].gaji << endl;
            }
        } 
        else if (pilihan == 3) {
            int id;
            cout << "Masukkan ID Pegawai yang dicari: ";
            cin >> id;
            bool ditemukan = false;
            for (int i = 0; i < jumlahPegawai; i++) {
                if (daftarPegawai[i].id == id) {
                    cout << "ID: " << daftarPegawai[i].id << ", Nama: " << daftarPegawai[i].nama << ", Gaji: " << daftarPegawai[i].gaji << endl;
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan) {
                cout << "Pegawai dengan ID " << id << " tidak ditemukan." << endl;
            }
        } 
        else if (pilihan == 4) {
            int id;
            cout << "Masukkan ID Pegawai yang ingin diperbarui gajinya: ";
            cin >> id;
            bool ditemukan = false;
            for (int i = 0; i < jumlahPegawai; i++) {
                if (daftarPegawai[i].id == id) {
                    cout << "Masukkan gaji baru: ";
                    cin >> daftarPegawai[i].gaji;
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan) {
                cout << "Pegawai dengan ID " << id << " tidak ditemukan." << endl;
            } else {
                cout << "Gaji berhasil diperbarui." << endl;
            }
        } 
        else if (pilihan == 5) {
            cout << "Keluar dari program..." << endl;
        } 
        else {
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);
    
    return 0;
}
