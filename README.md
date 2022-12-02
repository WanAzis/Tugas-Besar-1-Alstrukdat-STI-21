# Tugas-Besar-Alstrukdat-STI-21
Pengerjaan tugas besar mata kuliah Analisis dan Struktur Data program studi STI tahun ajaran 2022/2023 
Kelompok 1 K3, Anggota : 
1. Wan Aufa Azis	 		    18221001
2. Athira Dhyanissa Tafkir		18221022
3. Dhafin Ghalib Luqman Hakim	18221023
4. Syasya Umaira 			    18221026
5. Muhammad Mumtaz 			    18221029

# Deskripsi Singkat Program
BNMO (dibaca: Binomo) adalah sebuah robot video game console yang dimiliki oleh Indra dan Doni. Dua bulan yang lalu, ia mengalami kerusakan dan telah berhasil diperbaiki. Sayangnya, setelah diperbaiki ia justru mendapatkan lebih banyak bug dalam sistemnya. Oleh karena itu, kami akan memprogram ulang robot video game console kesayangannya.

# Cara Kompilasi dan Menjalankan Program 
Clone repositori ini dan masuk ke direktori repositori lokal yang telah dibuat, kemudian masuk ke folder bin
```
    git clone https://github.com/WanAzis/Tugas-Besar-Alstrukdat-STI-21.git
    cd Tugas-Besar-Alstrukdat-STI-21\bin
```

## Kompilasi dan Run Program dengan System Operasi Windows
Kompilasi manual dengan menuliskan teks di bawah ini pada terminal
```
    gcc -o BNMO ../src/main.c ../src/ADT/Array/array.c ../src/ADT/Array/arraymap.c ../src/ADT/list/listdp.c ../src/ADT/map/map.c ../src/ADT/matriks/matriks.c ../src/ADT/point/point.c ../src/ADT/Queue/queue.c ../src/ADT/QueueDD/queueDD.c ../src/ADT/MesinKata/mesin_karakter.c ../src/ADT/MesinKata/mesin_kata.c ../src/ADT/set/set.c ../src/ADT/stack/stack.c ../src/ADT/stack/stacktoh.c ../src/procedure/fungsi_kecil.c ../src/game/dinerdash/dinerdash.c ../src/game/hangman/hangman.c ../src/game/jaribocil/jaribocil.c ../src/game/RNG/RNG.c ../src/game/snakeonmeteor/som.c ../src/game/towerofhanoi/toh.c ../src/console.c
```
Lalu run file executable `BNMO.exe` kemudian setelah masuk ke dalam program pastikan bahwa setiap command yang diinput dalam program merupakan Uppercase dan tanpa whitespace.

## Kompilasi dan Run Program dengan System Operasi Linux
Kompilasi manual dengan menuliskan teks di bawah ini pada terminal
```
    gcc -c "../src/ADT/Array/array.c" -o array.o
    gcc -c "../src/ADT/Array/arraymap.c" -o arraymap.o
    gcc -c "../src/ADT/list/listdp.c" -o listdp.o
    gcc -c "../src/ADT/map/map.c" -o map.o
    gcc -c "../src/ADT/matriks/matriks.c" -o matriks.o
    gcc -c "../src/ADT/point/point.c" -o point.o
    gcc -c "../src/ADT/Queue/queue.c" -o queue.o
    gcc -c "../src/ADT/QueueDD/queueDD.c" -o queueDD.o
    gcc -c "../src/ADT/MesinKata/mesin_karakter.c" -o mesinkarakter.o
    gcc -c "../src/ADT/MesinKata/mesin_kata.c" -o mesinkata.o
    gcc -c "../src/ADT/set/set.c" -o set.o
    gcc -c "../src/ADT/stack/stack.c" -o stack.o
    gcc -c "../src/ADT/stack/stacktoh.c" -o stacktoh.o
    gcc -c "../src/procedure/fungsi_kecil.c" -o fungsikecil.o
    gcc -c "../src/game/dinerdash/dinerdash.c" -o dinerdash.o
    gcc -c "../src/game/hangman/hangman.c" -o hangman.o
    gcc -c "../src/game/jaribocil/jaribocil.c" -o jaribocil.o
    gcc -c "../src/game/RNG/RNG.c" -o RNG.o
    gcc -c "../src/game/snakeonmeteor/som.c" -o som.o
    gcc -c "../src/game/towerofhanoi/toh.c" -o toh.o
    gcc -c "../src/console.c" -o console.o
    gcc ../src/main.c array.o arraymap.o listdp.o map.o matriks.o point.o queue.o queueDD.o mesinkarakter.o mesinkata.o set.o stack.o stacktoh.o fungsikecil.o dinerdash.o hangman.o jaribocil.o RNG.o som.o toh.o console.o 
```
Cara menjalankan program adalah dengan menuliskan `./a.out` pada terminal atau jalankan file `a.exe` kemudian setelah masuk ke dalam program pastikan bahwa setiap command yang diinput dalam program merupakan Uppercase dan tanpa whitespace.