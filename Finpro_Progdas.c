#include <stdio.h>

typedef struct {
    float luasTanah;
    int banyakCacing;
    float luasTanahWeeds;
    float phTanah;
    int jumlahSpesies;
} hutan;

void riwayat (/*masukin variabel yg dibutuhin*/) {}

void analisisPerubahan (/*masukin variabel yg dibutuhin*/) {}

int menu () {
    int n;
    //list pilihan menu
    return n;
}

int main() {
    //variabel semua bikin di awal
    int pilihan, count = 0, max = 5;

    //bikin array malloc pake tipe data struct yg hutan
    int *tahun = (hutan *)malloc(max * sizeof(hutan));
    if (tahun == NULL) {
        printf("Memory Reallocation Failed");
        return 1;
    }

    do { //main loop
        pilihan = menu();

        if (pilihan == 1) {
            //perbesar array kalo gk cukup

            //minta data trs masukin ke array

        } else if (pilihan == 2) {
            //tampilin riwayat
        } else if (pilihan == 3) {
            //tampilin analisis
        } else if (pilihan == 0) {
            //tampilin riwayat + hasil analisis akhir
        } else {
            printf("Input angka sesuai dengan pilihan!\n\n");
        }
    } while (pilihan != 0);

    return 0;
}