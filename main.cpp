#include <iostream>
#include "TuBes_STD_Kel1.h"

using namespace std;

int main()
{
    string Clue;
    int jamSekarang, menitSekarang;
    int hariSekarang, bulanSekarang, tahunSekarang;
    cout << "==============================================" << endl;
    cout << "Masukkan password Untuk Login kedalam Aplikasi " << endl;
    cout << "==============================================" << endl;
    cout << "a. Aku bingung, bisa beri aku clue ga?" << endl;
    cout << "b. Ga ah, mager aku"<< endl;
    cout << "==============================================" << endl;
    cout << "Pilih opsi : " ;
    cin >>Clue;
    if (Clue == "a" || Clue == "A"){
            cout << "Sebelum itu, masukkan Tanggal Hari ini ya (Dalam bentuk Angka)" << endl;
            cout << "Tanggal : ";
            cin >> hariSekarang;
            cout << "Bulan : ";
            cin >> bulanSekarang;
            cout << "Tahun : ";
            cin >> tahunSekarang;
            if (bulanSekarang < 1 || bulanSekarang > 12 || hariSekarang < 1 || hariSekarang > 30) {
    cout << "Tanggal tidak valid!" << endl;
    return 0;
}
        cout << "Cluenya adalah jam sekarang (range 0 - 23 jam)" << endl;
        cin >> jamSekarang ;
        cout << "Oh iya, sama menit sekarang berapa? (range 0 - 59)" << endl ;
        cin >> menitSekarang;
        if (jamSekarang < 0 || jamSekarang > 23 || menitSekarang < 0 || menitSekarang > 59) {
    cout << "Jam atau menit tidak valid!" << endl;
    return 0;
}
        cout << "Baiklah, Anda bisa masuk ke aplikasi kami" << endl;

    LParent list;
    createListParent(list);

    int pilihan;
    do {
            cout << endl;
        cout << "===========================================" << endl;
        cout << "Pilihlah menu yang ingin Anda pilih" << endl;
        cout << "===========================================" << endl;
        cout << "1. Tambah Proyek" << endl;
        cout << "2. Tambah Tugas ke Proyek" << endl;
        cout << "3. Tampilkan Semua Proyek" << endl;
        cout << "4. Tampilkan Semua Proyek dan Tugas" << endl;
        cout << "5. Cari Tugas dalam Proyek" << endl;
        cout << "6. Hapus Tugas" << endl;
        cout << "7. Hapus Proyek" << endl;
        cout << "8. Update Proyek" << endl;
        cout << "9. Update Tugas" << endl;
        cout << "Jika ingin keluar dari aplikasi, silahkan ketik '0'." << endl;
        cout << "===========================================" << endl;
        cout << "Pilihan opsi: ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
        case 1: {
            //Tambah proyek
            proyek p;
            cout << "Masukkan Nama Proyek: ";
            cin >> p.projectName;
            cout << "Masukkan Nama Manager: ";
            cin >> p.manajerName;
            p.banyakTask = 0;
            insertLastParent(list, allocateParent(p));

            break;
        }
        case 2: {
              //Tambah Tugas ke proyek
            string projectName;
            cout << "Masukkan Nama Proyek: ";
            cin >> projectName;
            adr_parent parent = searchParent(list, projectName);

            if (parent != nullptr) {
                tugas t;
                cout << "Masukkan Nama Tugas: ";
                cin >> t.taskName;
                cout << "Masukkan Status: ";
                cin >> t.status;
                cout << "Masukkan Tanggal Deadline: ";
                cin >> t.hariDL;
                 cout << "Masukkan Bulan Deadline: ";
                cin >> t.bulanDL;
                 cout << "Masukkan Tahun Deadline: ";
                cin >> t.tahunDL;
                cout << "Masukkan Jam Deadline: ";
                cin >> t.jamDL;
                cout << "Masukkan Menit Deadline: ";
                cin >> t.menitDL;
                  if (t.jamDL < 0 || t.jamDL > 23 || t.menitDL < 0 || t.menitDL >  59 || t.bulanDL < 1 || t.bulanDL > 12 || t.hariDL < 1 || t.hariDL > 30 ) {
    cout << "Waktu deadline tidak valid!" << endl;
    break;
     }
                insertLastChild(parent, allocateChild(t));
                cout << "Tugas pada proyek " << projectName << " sudah ditambahkan" << endl;
            } else {
                cout << "Proyek tidak ditemukan";
            }

            break;
        }
        case 3:
            //Tampilkan Semua Proyek
            showParent(list);
            break;
        case 4:
            //Tampilkan Semua Proyek dan Tugas
            showParentWithChild(list,jamSekarang,menitSekarang,hariSekarang,bulanSekarang,tahunSekarang);
            cout << endl;
            break;
        case 5: {
            if(first(list) == NULL){
                cout << "Masukkan terlebih dahulu proyek baru dengan memilih opsi 1, lalu masukkan juga tugasnya dengan memilih opsi 2" << endl;
                break;
            }
           // Cari Tugas dalam Proyek
            string projectName, taskName;
            cout << "Masukkan Nama Proyek: ";
            cin >> projectName;


            adr_parent parent = searchParent(list, projectName);
            if (parent != nullptr) {
                    cout << "Masukkan Nama Tugas: ";
                    cin >> taskName;
                adr_child task = searchChild(parent, taskName);
                if (task != nullptr) {
                    cout << "Proyek dan Tugas ditemukan " << endl;
                    cout << "Proyek : " << info_p(parent).projectName << " | Task: " << info_c(task).taskName << " | Tanggal: " << info_c(task).hariDL <<"-" << info_c(task).bulanDL << "-" << info_c(task).tahunDL <<  " | Pukul: " << info_c(task).jamDL << ":" << info_c(task).menitDL << endl;
                } else {
                    cout << "Tugas tidak ditemukan";
                }
            } else {
                cout << "Proyek tidak ditemukan";
            }
            break;
        }
        case 6: {
            // Hapus Tugas
             if(first(list) == NULL){
                cout << "Masukkan terlebih dahulu proyek baru dengan memilih opsi 1, lalu masukkan juga tugasnya dengan memilih opsi 2" << endl;
                break;
            }
            string projectName, taskName;
            cout << "Masukkan Nama Proyek: ";
            cin >> projectName;


            adr_parent parent = searchParent(list, projectName);
            if (parent != nullptr) {
            cout << "Masukkan Nama Tugas: ";

            cin >> taskName;
            adr_child task = searchChild(parent, taskName);
            if(task != NULL){
                deleteChild(parent, taskName);
            }else{
               cout << "Tugas tidak ditemukan" << endl;
            }
            } else {
                cout << "Proyek tidak ditemukan";
            }
            break;
        }
        case 7: {
           // Hapus Proyek
            if(first(list) == NULL){
                cout << "Masukkan terlebih dahulu proyek baru dengan memilih opsi 1" << endl;
                break;
            }
            string projectName;
            cout << "Masukkan Nama Proyek: ";
            cin >> projectName;
             adr_parent parent = searchParent(list, projectName);
            if (parent != nullptr){
            deleteParent(list, projectName);
            }else{
              cout << "Proyek tidak ditemukan" << endl;
            }
            break;
        }
        case 8: {
            // Update Proyek
             if(first(list) == NULL){
                cout << "Masukkan terlebih dahulu proyek baru dengan memilih opsi 1" << endl;
                break;
            }
            string projectName;
            cout << "Masukkan Nama Proyek yang Ingin Diupdate: ";
            cin >> projectName;

            adr_parent parent = searchParent(list, projectName);
            if (parent != nullptr) {
                string newProjectName, newManagerName;
                cout << "Masukkan Nama Proyek Baru: ";
                cin >> newProjectName;
                cout << "Masukkan Nama Manager Baru: ";
                cin >> newManagerName;
                updateParent(parent, newProjectName, newManagerName);
            } else {
                cout << "Proyek tidak ditemukan";
            }
            break;
        }
        case 9: {
           // Update Tugas
           if(first(list) == NULL){
                cout << "Masukkan terlebih dahulu proyek baru dengan memilih opsi 1, lalu masukkan juga tugasnya dengan memilih opsi 2" << endl;
                break;
            }
            string projectName, taskName;
            cout << "Masukkan Nama Proyek: ";
            cin >> projectName;


            adr_parent parent = searchParent(list, projectName);
            if (parent != nullptr) {
            cout << "Masukkan Nama Tugas: ";
            cin >> taskName;
                adr_child task = searchChild(parent, taskName);
                if (task != nullptr) {
                    string newTaskName, newStatus;
                    int newJamDL, newMenitDL, newhariDL,newbulanDL,newtahunDL;
                    cout << "Masukkan Nama Tugas Baru: ";
                    cin >> newTaskName;
                    cout << "Masukkan Status Baru: ";
                    cin >> newStatus;
                     cout << "Masukkan Tanggal Deadline Baru: ";
                    cin >> newhariDL;
                     cout << "Masukkan Bulan Deadline Baru: ";
                    cin >> newbulanDL;
                     cout << "Masukkan Tahun Deadline Baru: ";
                    cin >> newtahunDL;
                    cout << "Masukkan Jam Deadline Baru: ";
                    cin >> newJamDL;
                    cout << "Masukkan Menit Deadline Baru: ";
                    cin >> newMenitDL;
                     if (newJamDL < 0 || newJamDL > 23 || newMenitDL < 0 || newMenitDL >  59 || newbulanDL < 1 || newbulanDL > 12 || newhariDL < 1 || newhariDL > 30 ) {
    cout << "Waktu deadline tidak valid!" << endl;
    break;
     }
                    updateChild(task, newTaskName, newStatus, newJamDL, newMenitDL,newhariDL,newbulanDL,newtahunDL);
                } else {
                    cout << "Tugas tidak ditemukan";
                }
            } else {
                cout << "Proyek tidak ditemukan";
            }
            break;
        }

        case 0:
            cout << "Terimakasih sudah memakai aplikasi kami";
            break;
        default:
            cout << "Pilihan tidak valid. Coba lagi";
            break;
        }
    } while (pilihan != 0);
    }else if(Clue == "b" || Clue == "B"){
         cout << "Yahhh, ga seru ah, keluar aja kamu deh" << endl;
    }
    return 0;
}
