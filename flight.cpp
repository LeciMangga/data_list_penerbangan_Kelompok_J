#include <iostream>
#include "flight.h"

void Create_List(List &L) {
    first(L) = NULL;
}

adr New_Elemen(infotype data) {
    adr p = new elmList;
    info(p) = data;
    next(p) = NULL;
    return p;
}

void Insert_First(List &L, adr p) {
    next(p) = first(L);
    first(L) = p;
}

void Insert_Last(List &L, adr p) {
    if (first(L) != NULL) {
        adr Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = p;
    } else {
        first(L) = p;
    }
}

void Insert_After(List &L, adr prec, adr p) {
    if (prec != NULL) {
        next(p) = next(prec);
        next(prec) = p;
    }
}

void Delete_First(List &L, adr &p) {
    if (first(L) != NULL) {
        p = first(L);
        first(L) = next(p);
        next(p) = NULL;
    }
}

void Delete_Last(List &L, adr &p) {
    if (first(L) == NULL) {
        p = NULL;
    } else if (next(first(L)) == NULL) {
        p = first(L);
        first(L) = NULL;
    } else {
        adr prev = first(L);
        adr last = next(first(L));
        while (next(last) != NULL) {
            prev = last;
            last = next(last);
        }
        p = last;
        next(prev) = NULL;
    }
}

void Delete_After(List &L, adr prec, adr &p) {
    if (next(prec) != NULL) {
        p = next(prec);
        next(prec) = next(p);
        next(p) = NULL;
    } else {
        p = NULL;
    }
}

void Show(List L) {
    if (first(L) == NULL) {
        cout << "List kosong" << endl;
    } else {
        adr P = first(L);
        while (P != NULL) {
            cout << "Jenis Pesawat: " << info(P).jenisPesawat << endl;
            cout << "Kapasitas Penumpang: " << info(P).kapasitasPenumpang << endl;
            cout << "Kapasitas Tangki: " << info(P).kapasitasTangki << endl;
            P = next(P);
        }
    }
}

void SortByKapasitasPesawat(List &L) {
    if (first(L) != NULL) {
        adr P, Q, Sorted = NULL;
        while (first(L) != NULL) {
            P = first(L);
            first(L) = next(first(L));
            if (Sorted == NULL || info(Sorted).kapasitasPenumpang > info(P).kapasitasPenumpang) {
                next(P) = Sorted;
                Sorted = P;
            } else {
                Q = Sorted;
                while (next(Q) != NULL && info(next(Q)).kapasitasPenumpang < info(P).kapasitasPenumpang) {
                    Q = next(Q);
                }
                next(P) = next(Q);
                next(Q) = P;
            }
        }
        first(L) = Sorted;
    } else {
        cout << "List kosong";
    }
}

adr SearchByJenisPesawat(List L, detailPesawat data) {
    if (first(L) != NULL) {
        adr Q = first(L);
        while (next(Q) != NULL && info(Q).jenisPesawat != data.jenisPesawat) {
            Q = next(Q);
        }
        if (info(Q).jenisPesawat == data.jenisPesawat) {
            return Q;
        } else {
            return NULL;
        }
    } else {
        cout << "list kosong" << endl;
        return NULL;
    }

}
