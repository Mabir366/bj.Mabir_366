#include <iostream>
#include "TuBes_STD_Kel1.h"

using namespace std;

void createListParent(LParent &L){
    // Membuat dan menginisialisasi list parent dengan nilai awal NULL.
     first(L) = NULL;
}
adr_parent allocateParent(proyek data){
    // Membuat node baru untuk parent (proyek) dengan informasi proyek yang diberikan.
    // Menginisialisasi next pointer dan child pointer dengan NULL.
   adr_parent newProyek = new elmParent;
   info_p(newProyek) = data;
   next_p(newProyek) = NULL;
   child(newProyek) = NULL;
   return newProyek;
}
adr_child allocateChild(tugas data){
    // Membuat node baru untuk child (tugas) dengan informasi tugas yang diberikan.
    // Menginisialisasi next pointer dengan NULL.
   adr_child newTask = new elmChild;
   info_c(newTask) = data;
   next_c(newTask) = NULL;
   return newTask;
}
void insertLastParent(LParent &L, adr_parent p){
     // Menambahkan node parent (proyek) baru ke akhir list parent.
    // Jika list kosong, proyek menjadi elemen pertama.
    if(first(L) == NULL){
        first(L) = p;
    }else{
       adr_parent temp = first(L);
       while(next_p(temp) != NULL){
           temp = next_p(temp);
       }
       next_p(temp) = p;
    }
    cout << "Proyek sudah ditambahkan" << endl;
}
void insertLastChild(adr_parent p, adr_child c){
    // Menambahkan node child (tugas) baru ke akhir list child dari parent tertentu.
    // Jika parent tidak memiliki child sebelumnya, tugas menjadi elemen pertama.
    // Menambahkan jumlah tugas pada parent.
   if(p == NULL){
    cout << "Proyek beserta tugasnya tidak ditemukan." << endl;
   }else{
      if(child(p) == NULL){
         child(p) = c;
      }else{
         adr_child temp = child(p);
         while(next_c(temp) != NULL){
            temp = next_c(temp);
         }
         next_c(temp) = c;
      }
      info_p(p).banyakTask++;
   }
}
void showParent(LParent L){
    // Menampilkan semua data parent (proyek) di dalam list tanpa menampilkan child.
    // Jika tidak ada parent, menampilkan pesan bahwa list kosong.
   if(first(L) == NULL){
    cout << "Tidak ada proyek yang tersedia" << endl;
   }else{
      adr_parent temp = first(L);
      while(temp != NULL){
        cout << "Project Name : " << info_p(temp).projectName << " | ";
        cout << "Manager Name : " << info_p(temp).manajerName << " | ";
        cout << "Task's Store : " << info_p(temp).banyakTask << endl;
        temp = next_p(temp);
      }
   }
}
void showParentWithChild(LParent L, int jamSekarang, int menitSekarang, int hariSekarang, int bulanSekarang, int tahunSekarang){
    // Menampilkan semua data parent (proyek) beserta semua data child (tugas) yang terkait.
    // Menghitung lama durasi dari waktu saat ini hingga deadline untuk setiap tugas.
    // Menampilkan informasi jika tugas telah overdue atau durasi tersisa.
     if(first(L) == NULL){
    cout << "Tidak ada proyek dan tugas yang tersedia" << endl;
   }else{
       adr_parent temp = first(L);
       while(temp != NULL){
         cout << "Project Name : " << info_p(temp).projectName << " | ";
        cout << "Manager Name : " << info_p(temp).manajerName << " | ";
        cout << "Task's Store : " << info_p(temp).banyakTask << endl;
         if(info_p(temp).banyakTask != 0){
        adr_child C = child(temp);
        while(C != NULL){
                cout << "===========================================" << endl;
            cout << "Task     : " << info_c(C).taskName << endl;
             int durasi = lamaDurasi(jamSekarang,menitSekarang,hariSekarang,bulanSekarang,tahunSekarang, info_c(C).jamDL, info_c(C).menitDL, info_c(C).hariDL,info_c(C).bulanDL,info_c(C).tahunDL);
              if(durasi == -1){
                cout << "Status : Overdue" << endl;
            }else if (durasi == 0){
                cout << "Status : Time's up!!" << endl;
            }else{
                 cout << "Status : " << info_c(C).status << endl;
            }
            cout << "Deadline   " <<endl;
            cout << "Tanggal  : " << info_c(C).hariDL << "-" <<info_c(C).bulanDL << "-"<<info_c(C).tahunDL<< endl;
            if(info_c(C).jamDL >= 0 && info_c(C).jamDL <=10){
                cout << "Pukul    : " <<"0" << info_c(C).jamDL << ":" ;
            }else{
            cout << "Pukul    : " << info_c(C).jamDL << ":" ;
            }
            if(info_c(C).menitDL >= 0 && info_c(C).menitDL <=10){
                cout << "0" << info_c(C).menitDL << endl;
            }else{
             cout << info_c(C).menitDL << endl;
            }

            if(durasi == -1){
                cout << "Lama Durasi : - " << endl;
            }else{
               if(durasi >= 1440){
                cout << "Lama Durasi : " << durasi/1440 << " hari" << endl;
               }else if(durasi >= 60 && durasi < 1440){
               cout << "Lama Durasi : " <<durasi/60 << " jam" << endl;
               }else if(durasi >= 0 && durasi < 60) {
                   cout << "Lama Durasi : " << durasi <<" menit"<< endl;
               }

            }
            C = next_c(C);
        }

       }else{
          cout << "Tidak ada tugas yang dikerjakan" << endl;
       }
       temp = next_p(temp);
    }
  }
}
void deleteParent(LParent &L, string projectName){
    // Menghapus parent (proyek) berdasarkan nama proyek.
    // Menghapus semua child (tugas) yang terkait dengan proyek tersebut.
    // Jika proyek tidak ditemukan, menampilkan pesan kesalahan.
   adr_parent temp = first(L);
   adr_parent prev = NULL;

   while(temp != NULL && info_p(temp).projectName != projectName){
       prev = temp;
       temp = next_p(temp);
   }

   if(temp == NULL){
    cout << "Proyek tidak ditemukan" << endl;
   }else{

   adr_child C = child(temp);
   while(C != NULL){
    C = next_c(C);
   }

   if(prev == NULL){
    first(L) = next_p(temp);
   }else{
      next_p(prev) = next_p(temp);
   }
   cout << "Proyek sudah dihapus" << endl;

}
}
void deleteChild(adr_parent p, string taskName){
    // Menghapus child (tugas) dari list child pada parent tertentu berdasarkan nama tugas.
    // Mengurangi jumlah tugas pada parent.
    // Jika tugas atau proyek tidak ditemukan, menampilkan pesan kesalahan.
   if(p == NULL){
    cout << "Proyek tidak ditemukan" << endl;
   }else{
      adr_child prev = NULL;
      adr_child temp = child(p);

      while(temp != NULL && info_c(temp).taskName != taskName){
        prev = temp;
        temp = next_c(temp);
      }

      if(temp == NULL){
        cout << "Tugas tidak ditemukan" << endl;
      }else{
         if(prev == NULL){
            child(p) = next_c(temp);
         }else{
             next_c(prev) = next_c(temp);
         }
      }
      if(info_p(p).banyakTask != 0){
             info_p(p).banyakTask--;
      }
      cout << "Tugas sudah dihapus" << endl;
   }
}
adr_parent searchParent(LParent L, string projectName){
    // Mencari parent (proyek) berdasarkan nama proyek dalam list.
    // Jika ditemukan, mengembalikan alamat node proyek; jika tidak, menampilkan pesan kesalahan.
     adr_parent temp = first(L);
     while(temp != NULL){
        if(info_p(temp).projectName == projectName){
            return temp;
        }
        temp = next_p(temp);
     }
     return NULL;
}
adr_child searchChild(adr_parent p, string taskName){
    // Mencari child (tugas) berdasarkan nama tugas dalam list child pada parent tertentu.
    // Jika ditemukan, mengembalikan alamat node tugas; jika tidak, menampilkan pesan kesalahan.
   if(p == NULL){
    return NULL;
   }else{
       adr_child temp = child(p);
     while(temp != NULL){
        if(info_c(temp).taskName == taskName){
            return temp;
        }
        temp = next_c(temp);
     }
     return NULL;
   }
}

int lamaDurasi(int jamSekarang, int menitSekarang, int hariSekarang, int bulanSekarang, int tahunSekarang,int jamDL, int menitDL, int hariDL, int bulanDL, int tahunDL) {
    // Konversi waktu sekarang ke total menit sejak awal waktu
    int totalMenitSekarang = menitSekarang + jamSekarang * 60;
    totalMenitSekarang += (hariSekarang - 1) * 1440; // Konversi hari ke menit
    totalMenitSekarang += (bulanSekarang - 1) * 30 * 1440; // Konversi bulan ke menit
    totalMenitSekarang += (tahunSekarang - 1) * 12 * 30 * 1440; // Konversi tahun ke menit

    // Konversi deadline ke total menit sejak awal waktu
    int totalMenitDL = menitDL + jamDL * 60;
    totalMenitDL += (hariDL - 1) * 1440; // Konversi hari ke menit
    totalMenitDL += (bulanDL - 1) * 30 * 1440; // Konversi bulan ke menit
    totalMenitDL += (tahunDL - 1) * 12 * 30 * 1440; // Konversi tahun ke menit

    // Hitung durasi dalam menit
    int durasiMenit = totalMenitDL - totalMenitSekarang;

    // Jika durasi negatif, artinya sudah melewati deadline
    if (durasiMenit < 0) {
        return -1;
    }
    return durasiMenit;
}


void updateParent(adr_parent p,string newProjectName, string newManajerName){
    // Memperbarui informasi nama proyek dan nama manajer untuk parent tertentu.
    // Jika proyek tidak ditemukan, menampilkan pesan kesalahan.
   if(p == NULL){
    cout << "Proyek tidak ditemukan" << endl;
   }

   info_p(p).projectName = newProjectName;
   info_p(p).manajerName = newManajerName;
   cout << "Proyek sudah diperbarui" << endl;
}
void updateChild(adr_child child, string newTaskName, string newStatus, int newJamDL, int newMenitDL, int newhariDL, int newbulanDL, int newtahunDL){
    // Memperbarui informasi tugas seperti nama tugas, status, dan deadline.
    // Jika tugas tidak ditemukan, menampilkan pesan kesalahan.
     // Jika proyek tidak ditemukan, menampilkan pesan kesalahan.
    if(child == NULL){
        cout << "Tugas tidak ditemukan" << endl;
    }else{
       info_c(child).taskName = newTaskName;
        info_c(child).status = newStatus;
        info_c(child).hariDL = newhariDL;
        info_c(child).bulanDL = newbulanDL;
        info_c(child).tahunDL = newtahunDL;
         info_c(child).jamDL = newJamDL;
          info_c(child).menitDL = newMenitDL;
           cout << "Tugas sudah diperbarui" << endl;
    }
}
