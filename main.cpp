#include "flight.h"

int main() {
    List NRA;
    detailPesawat data1, data2, data3, data4, data5, data6;
    adr newList, List4, adrData1, adrData2, adrData6;
    string input;

    // 01. meng create list
    Create_List(NRA);

    // meminta user data pertama yang akan dimasukkan ke list
    cout << "Masukkan Jenis Pesawat: "; cin >> data1.jenisPesawat;
    cout << "Masukkan Kapasitas Penumpang: "; cin >> data1.kapasitasPenumpang;
    cout << "Masukkan Kapasitas Tangki: "; cin >> data1.kapasitasTangki;

    // 02. melakukan create new elemen berdasarkan data yang diinputkan user
    newList = New_Elemen(data1);

    // 03. memanggil salah satu jenis insert (jangan insert after)
    Insert_First(NRA, newList);

    // meminta user data kedua yang akan dimasukkan ke list
    cout << "Masukkan Jenis Pesawat: "; cin >> data2.jenisPesawat;
    cout << "Masukkan Kapasitas Penumpang: "; cin >> data2.kapasitasPenumpang;
    cout << "Masukkan Kapasitas Tangki: "; cin >> data2.kapasitasTangki;

    // 04. melakukan create new elemen berdasarkan data yang diinputkan user
    newList = New_Elemen(data2);

    // 05. memanggil salah satu jenis insert (berbeda dengan insert yang data pertama, jangan Insert after)
    Insert_Last(NRA, newList);

    // meminta user data ketiga yang akan dimasukkan ke list
    cout << "Masukkan Jenis Pesawat: "; cin >> data3.jenisPesawat;
    cout << "Masukkan Kapasitas Penumpang: "; cin >> data3.kapasitasPenumpang;
    cout << "Masukkan Kapasitas Tangki: "; cin >> data3.kapasitasTangki;

    // 06. melakukan create new elemen berdasarkan data yang diinputkan user
    newList = New_Elemen(data3);

    // memanggil salah satu jenis insert (insert First)
    Insert_First(NRA, newList);

    // meminta user data keempat yang akan dimasukkan ke list
    cout << "Masukkan Jenis Pesawat: "; cin >> data4.jenisPesawat;
    cout << "Masukkan Kapasitas Penumpang: "; cin >> data4.kapasitasPenumpang;
    cout << "Masukkan Kapasitas Tangki: "; cin >> data4.kapasitasTangki;

    // 07. melakukan create new elemen berdasarkan data yang diinputkan user
    List4 = New_Elemen(data4);

    // 08. memanggil salah satu jenis insert (insert Last)
    Insert_Last(NRA, List4);

    // meminta user data kelima yang akan dimasukkan ke list
    cout << "Masukkan Jenis Pesawat: "; cin >> data5.jenisPesawat;
    cout << "Masukkan Kapasitas Penumpang: "; cin >> data5.kapasitasPenumpang;
    cout << "Masukkan Kapasitas Tangki: "; cin >> data5.kapasitasTangki;

    // 09. melakukan create new elemen berdasarkan data yang diinputkan user
    newList = New_Elemen(data5);

    // 10. memanggil salah satu jenis insert (insert after) pada data ke-4
    Insert_After(NRA, List4, newList);

    // meminta user data keenam yang akan dimasukkan ke list
    cout << "Masukkan Jenis Pesawat: "; cin >> data6.jenisPesawat;
    cout << "Masukkan Kapasitas Penumpang: "; cin >> data6.kapasitasPenumpang;
    cout << "Masukkan Kapasitas Tangki: "; cin >> data6.kapasitasTangki;

    // 11. melakukan create new elemen berdasarkan data yang diinputkan user
    newList = New_Elemen(data6);

    // 12. memanggil salah satu jenis insert (insert after) pada data ke 4
    Insert_After(NRA, List4, newList);

    cout << endl << endl;
    // memanggil show (01)
    Show(NRA);

    // 13. melakukan pencarian dan penghapusan data kedua dengan memanfaatkan salah satu jenis delete (delete after)
    cout << "Apakah anda ingin menghapus data ke-2 dari list? : ";
    cin >> input;
    if (input == "Ya"){
        adrData2 = SearchByJenisPesawat(NRA, data2);
        adr adrDataSebelum2;
        if (adrData2 == first(NRA)){
            Delete_First(NRA, adrData2);
        } else {
            adrDataSebelum2 = first(NRA);
            while (next(adrDataSebelum2) != adrData2){
                adrDataSebelum2 = next(adrDataSebelum2);
            }
            Delete_After(NRA, adrDataSebelum2, adrData2);
        }
        cout << "List setelah menghapus data ke-2" << endl;
        Show(NRA);
    } else {
        cout << "Maaf, inputan anda salah" << endl;
    }

    //14. melakukan pencarian dan penghapusan data keenam dengan memanfaatkan salah satu jenis delete (gunakan pengkondisian)
    cout << endl << "Apakah anda ingin menghapus data ke-6 dari list? : ";  // Ganti prompt yang sesuai
    cin >> input;
    adrData6 = SearchByJenisPesawat(NRA, data6);
    adr adrDataSebelum6;
    if (adrDataSebelum6 == first(NRA)){
        Delete_First(NRA, adrData6);
    } else {
        adrDataSebelum6 = first(NRA);
        while (next(adrDataSebelum6) != adrData6){
            adrDataSebelum6 = next(adrDataSebelum6);
        }
        Delete_After(NRA, adrDataSebelum6, adrData6);
    }
    Show(NRA);

    //15. melakukan pengurutan elemen pada list berdasarkan sub data yang didefinisikan
    cout << "Apakah anda ingin mengurutkan data di list berdasarkan Kapasitas Pesawat   ? : ";
    cin >> input;
    if (input == "Ya"){
        SortByKapasitasPesawat(NRA);
        cout << "List setelah mengurutkan data di list" << endl
        ;
    }
    //memanggil show (02)
    Show(NRA);

    return 0;
}
