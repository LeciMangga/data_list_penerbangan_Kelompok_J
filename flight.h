#ifndef SLL_H
#define SLL_H

#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
using namespace std;

struct detailPesawat {
    string jenisPesawat;
    int kapasitasPenumpang;
    int kapasitasTangki;
};

typedef detailPesawat infotype;
typedef struct elmList *adr;

struct elmList {
    infotype info;
    adr next;
};

struct List {
    adr first;
};

void Create_List(List &L);
adr New_Elemen(infotype data);
void Insert_First(List &L, adr p);
void Insert_Last(List &L, adr p);
void Insert_After(List &L, adr prec, adr p);
void Delete_First(List &L, adr &p);
void Delete_Last(List &L, adr &p);
void Delete_After(List &L, adr prec, adr &p);
void Show(List L);
void SortByKapasitasPesawat(List &L);
adr SearchByJenisPesawat(List L, detailPesawat data);

#endif
