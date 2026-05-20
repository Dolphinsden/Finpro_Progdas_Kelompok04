#include <stdio.h>
#include <stdlib.h>

typedef enum {
    baik = 1,
    sedang,
    buruk
} Kategori;

typedef struct {
    float luasTanah;
    int banyakCacing;
    float luasTanahWeeds;
    float phTanah;
    int jumlahSpesies;
    Kategori kategoriCacing;
    Kategori kategoriWeeds;
    Kategori kategoripH;
} hutan;

hutan inputData (int count) {
    hutan h;
    float temp;

    printf("Masukkan luas tanah hutan (meter) pada tahun ini : ");
    scanf("%f", &h.luasTanah);
    while (h.luasTanah < 0) { //fail safe
        printf("Input tidak valid!\nLuas harus lebih dari 0!\n\n");
        printf("Masukkan luas tanah hutan (meter) pada tahun ini : ");
        scanf("%f", &h.luasTanah);
    }

    printf("Masukkan jumlah cacing tanah dalam satu kubik tanah : ");
    scanf("%i", &h.banyakCacing);
    while (h.banyakCacing < 0) { //fail safe
        printf("Input tidak valid!\nJumlah cacing harus sama atau lebih dari 0!\n\n");
        printf("Masukkan jumlah cacing tanah dalam satu kubik tanah : ");
        scanf("%f", &h.banyakCacing);
    }

    printf("Masukkan luas tanah hutan yang tertutup oleh weeds (meter) seperti dandelions, crab grass, dll : ");
    scanf("%f", &h.luasTanahWeeds);
    while (h.luasTanahWeeds < 0 || h.luasTanahWeeds > h.luasTanah) { //fail safe
        if (h.luasTanahWeeds < 0) {
            printf("Input tidak valid!\nLuas harus lebih dari 0!\n\n");
        } else {
            printf("Input tidak valid!\nLuas tanah yang tertutup oleh weeds harus lebih kecil dibanding dengan luas tanah hutan!\n\n");
        }

        printf("Masukkan luas tanah hutan yang tertutup oleh weeds (meter) seperti dandelions, crab grass, dll : ");
        scanf("%f", &h.luasTanahWeeds);
    }

    printf("Masukkan pH tanah hutan pada saati ini : ");
    scanf("%f", &h.phTanah);
    while (h.phTanah < 0) { //fail safe
        printf("Input tidak valid!\npH tanah harus diantara 0 sampai 9!\n\n");
        printf("Masukkan pH tanah hutan pada saat ini : ");
        scanf("%f", &h.phTanah);
    }

    printf("Masukkan jumlah spesies yang tinggal dalam hutan ini : ");
    scanf("%i", &h.jumlahSpesies);
    while (h.jumlahSpesies < 0) { //fail safe
        printf("Input tidak valid!\nJumlah spesies yang tinggal dalam hutan ini harus sama atau lebih dari 0!\n\n");
        printf("Masukkan jumlah spesies yang tinggal dalam hutan ini : ");
        scanf("%f", &h.jumlahSpesies);
    }

    if (h.banyakCacing > 150) {
        h.kategoriCacing = 1;
    } else if (h.banyakCacing > 50) {
        h.kategoriCacing = 2;
    } else {
        h.kategoriCacing = 3;
    }

    temp = h.luasTanahWeeds / h.luasTanah;
    if (temp >= 0.25) {
        h.kategoriWeeds = 3;
    } else if (temp >= 0.1) {
        h.kategoriWeeds = 2;
    } else {
        h.kategoriWeeds = 1;
    }

    if (h.phTanah > 5.0 && h.phTanah < 6.5) {
        h.kategoripH = 1;
    } else if (h.phTanah > 4.0 && h.phTanah < 5.0 || h.phTanah > 6.5 && h.phTanah < 7.5) {
        h.kategoripH = 2;
    } else {
        h.kategoripH = 3;
    }

    return h;
}

void riwayat (int tahunAwal, hutan tahunSekarang, hutan tahunSebelum) {}

void analisisPerubahan (/*masukin variabel yg dibutuhin*/) {}

int menu () {
    int n;
    
    printf("\n ===== Pilihan Menu =====\n");
    printf("1. Input data\n");
    printf("2. Tampilkan riwatat per tahun\n");
    printf("3. Tampilkan analisis tahun sekarang dengan tahun sebelumnya\n");
    printf("0. Selesaikan program\n");

    printf("Pilihan : ");
    scanf("%i", &n);

    return n;
}

int main() {
    //variabel semua bikin di awal
    int pilihan, count = 0, max = 5, tahunAwal;

    //bikin array malloc pake tipe data struct yg hutan
    hutan *tahun = (hutan *)malloc(max * sizeof(hutan));

    if (tahun == NULL) {
        printf("Memory Reallocation Failed");

        return 1;
    }

    printf(" ===== Data Kesehatan Hutan =====\n");
    printf("Tahun berapa sekarang? : ");
    scanf("%i", &tahunAwal);
    while (tahunAwal < 0) { //fail safe
        printf("Input tidak valid!\nTahun harus lebih dari 0 (hanya menggunakan tahun setelah masehi)!\n");
        printf("Tahun berapa sekarang? : ");
        scanf("%i", &tahunAwal);
    }

    do { //main loop
        pilihan = menu();

        while (pilihan < 0 && pilihan > 3) { //fail safe
            printf("Input tidak valid!\nInput angka sesuai dengan pilihan!\n\n");
            pilihan = menu();
        }

        if (pilihan == 1) {
            //minta data trs masukin ke array
            printf(" ===== Data Untuk Tahun %i =====\n", tahunAwal + count);
            tahun[count] = inputData(count);

            count++;

            if (max == count) {
                max += 5;
                tahun = (hutan *)realloc(tahun, max * sizeof(hutan));
            }
        } else if (pilihan == 2) {
            riwayat(tahunAwal, tahun[0], tahun[0]);

            for (int i = 0; i < count; i++) {
                riwayat(tahunAwal, tahun[i], tahun[i - 1]);
            }
        } else if (pilihan == 3) {
            //tampilin analisis
        } else if (pilihan == 0) {
            printf("Terima kasih sudah menggunakan program ini!\n");
        } else {
            printf("Input angka sesuai dengan pilihan!\n");
        }
    } while (pilihan != 0);

    //tampilin riwayat + hasil analisis akhir (kalo sempet pake histogram)

    return 0;
}