#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mendefinisikan struct untuk Artefak
typedef struct {
    char nama[100];
    char kategori[100];
    int tahun;
    int nilai;
} Artefak;

// Fungsi komparator untuk mengurutkan data dengan qsort
int compare_artefak(const void *a, const void *b) {
    Artefak *artefakA = (Artefak *)a;
    Artefak *artefakB = (Artefak *)b;

    // 1. Kategori alfabetis naik
    int cmp_kategori = strcmp(artefakA->kategori, artefakB->kategori);
    if (cmp_kategori != 0) {
        return cmp_kategori;
    }

    // 2. Jika kategori sama, tahun naik
    if (artefakA->tahun != artefakB->tahun) {
        return artefakA->tahun - artefakB->tahun;
    }

    // 3. Jika tahun sama, nilai turun (perhatikan urutannya dibalik: B - A)
    if (artefakA->nilai != artefakB->nilai) {
        return artefakB->nilai - artefakA->nilai;
    }

    // 4. Jika nilai sama, nama alfabetis naik
    return strcmp(artefakA->nama, artefakB->nama);
}

int main() {
    int N;
    
    // Membaca jumlah artefak
    if (scanf("%d", &N) != 1) {
        return 0;
    }

    // Alokasi memori dinamis (Dynamic Array) untuk N artefak
    Artefak *daftar = (Artefak *)malloc(N * sizeof(Artefak));

    // Membaca input data artefak
    for (int i = 0; i < N; i++) {
        scanf("%s %s %d %d", daftar[i].nama, daftar[i].kategori, &daftar[i].tahun, &daftar[i].nilai);
    }

    // Mengurutkan array menggunakan fungsi bawaan qsort
    qsort(daftar, N, sizeof(Artefak), compare_artefak);

    // Mencetak output sesuai format yang diminta
    for (int i = 0; i < N; i++) {
        printf("%s %s %d %d\n", daftar[i].nama, daftar[i].kategori, daftar[i].tahun, daftar[i].nilai);
    }

    // Membebaskan memori
    free(daftar);

    return 0;
}
