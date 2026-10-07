#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// ===============================
// THREAD 1: Menghitung Faktorial
// ===============================
void* faktorial(void* arg) {
    int n = *(int*)arg;
    long long hasil = 1;

    for (int i = 1; i <= n; i++) {
        hasil *= i;
    }

    printf("[Thread Faktorial] %d! = %lld\n", n, hasil);

    return NULL;
}

// ===============================
// THREAD 2: Menampilkan Fibonacci
// ===============================
void* fibonacci(void* arg) {
    int n = *(int*)arg;
    int a = 0, b = 1, c;

    printf("[Thread Fibonacci] %d deret: ", n);

    for (int i = 0; i < n; i++) {
        printf("%d ", a);

        c = a + b;
        a = b;
        b = c;
    }

    printf("\n");

    return NULL;
}

// ===============================
// THREAD 3: Membaca File
// ===============================
void* bacaFile(void* arg) {
    FILE *file;
    char teks[100];

    file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("[Thread Baca File] File tidak ditemukan!\n");
        return NULL;
    }

    printf("[Thread Baca File] Isi file:\n");

    while (fgets(teks, sizeof(teks), file) != NULL) {
        printf("%s", teks);
    }

    printf("\n");

    fclose(file);

    return NULL;
}

// ===============================
// PROGRAM UTAMA
// ===============================
int main() {

    pthread_t thread1, thread2, thread3;

    int angkaFaktorial = 5;
    int jumlahFibonacci = 10;

    printf("====================================\n");
    printf("       PROGRAM PTHREADS C\n");
    printf("====================================\n");

    // Membuat dan menunggu thread 1 (Faktorial)
    pthread_create(&thread1, NULL, faktorial, &angkaFaktorial);
    pthread_join(thread1, NULL);

    // Membuat dan menunggu thread 2 (Fibonacci)
    pthread_create(&thread2, NULL, fibonacci, &jumlahFibonacci);
    pthread_join(thread2, NULL);

    // Membuat dan menunggu thread 3 (Baca File)
    pthread_create(&thread3, NULL, bacaFile, NULL);
    pthread_join(thread3, NULL);

    printf("====================================\n");
    printf("Semua thread telah selesai.\n");
    printf("====================================\n");

    return 0;
}