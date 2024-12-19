#include <iostream>
#ifndef TUBES_STD_KEL1_H_INCLUDED
#define TUBES_STD_KEL1_H_INCLUDED
#define first(L) L.first
#define next_c(x) x->next_c
#define info_c(x) x->info_c
#define next_p(x) x->next_p
#define info_p(x) x->info_p
#define child(x) x->child

using namespace std;

struct proyek{
   string projectName;
   int banyakTask;
   string manajerName;
};

struct tugas{
   string taskName;
   string status;
   int jamDL;
   int menitDL;
   int hariDL;
   int bulanDL;
   int tahunDL;
};

typedef struct elmParent *adr_parent;

struct elmParent{
    proyek info_p;
    adr_parent next_p;
    struct elmChild *child;
};

typedef struct elmChild *adr_child;

struct elmChild{
    tugas info_c;
    adr_child next_c;
};

struct LParent{
  adr_parent first;
};

void createListParent(LParent &L);
adr_parent allocateParent(proyek data);
adr_child allocateChild(tugas data);
void insertLastParent(LParent &L, adr_parent p);
void insertLastChild(adr_parent p, adr_child c);
void showParent(LParent L);
void showParentWithChild(LParent L,int jamSekarang, int menitSekarang, int hariSekarang, int bulanSekarang, int tahunSekarang);
void deleteParent(LParent &L, string projectName);
void deleteChild(adr_parent p, string taskName);
adr_parent searchParent(LParent L, string projectName);
adr_child searchChild(adr_parent p, string taskName);
int lamaDurasi(int jamSekarang, int menitSekarang, int hariSekarang, int bulanSekarang, int tahunSekarang,int jamDL, int menitDL, int hariDL, int bulanDL, int tahunDL) ;
void updateParent(adr_parent p,string newProjectName, string newManajerName);
void updateChild(adr_child child, string newTaskName, string newStatus, int newJamDL, int newMenitDL, int newhariDL, int newbulanDL, int newtahunDL);





#endif // TUBES_STD_KEL1_H_INCLUDED
