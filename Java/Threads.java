import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Threads {

    // Faktorial Threads
    static class Faktorial implements Runnable {

        @Override
        public void run() {
            int n = 5;
            long hasil = 1;

            for (int i = 1; i <= n; i++) {
                hasil *= i;
            }

            System.out.println("[Thread Faktorial] " + n + "! = " + hasil);
        }
    }

    // Fibonacci Threads
    static class Fibonacci implements Runnable {

        @Override
        public void run() {
            int n = 10;
            int a = 0;
            int b = 1;

            System.out.print("[Thread Fibonacci] " + n + " deret: ");

            for (int i = 0; i < n; i++) {
                System.out.print(a + " ");

                int c = a + b;
                a = b;
                b = c;
            }

            System.out.println();
        }
    }

    //Thread Membaca File
    static class BacaFile implements Runnable {

        @Override
        public void run() {
            try {
                java.io.BufferedReader reader =
                new java.io.BufferedReader(
                new java.io.FileReader("../data.txt"));

                String teks;

                System.out.println("[Thread Baca File] Isi file:");

                while ((teks = reader.readLine()) != null) {
                    System.out.println(teks);
                }

                reader.close();

            } 
                catch (java.io.IOException e) {
                    System.out.println("[Thread Baca File] File tidak ditemukan!");
                }
        }
    }


    public static void main(String[] args) {

        System.out.println("====================================");
        System.out.println("       PROGRAM PTHREADS JAVA");
        System.out.println("====================================");

        Thread thread1 = new Thread(new Faktorial());
        Thread thread2 = new Thread(new Fibonacci());
        Thread thread3 = new Thread(new BacaFile());

        try {
            thread1.start();
            thread2.start();
            thread3.start();

            thread1.join();
            thread2.join();
            thread3.join();
        } 
        catch (InterruptedException e) {
            System.out.println("Thread terganggu.");
        }

        System.out.println("====================================");
        System.out.println("Semua thread telah selesai.");
        System.out.println("====================================");
    }

}
