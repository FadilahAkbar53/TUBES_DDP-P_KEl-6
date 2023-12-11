#ifndef header_H
#define header_H
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nama[20];
    int skor;
} pemain;

pemain player1 = {"", 0};
pemain player2 = {"", 0};
pemain computer = {"Computer", 0};

// Kamus Data
int input_home_menu;
int input_mode_game;
int input_mode_level;
int input_highscore;
int size;
char winner;
char response = ' ';
clock_t startTime;

// User Interfaces
void tampilan_menu_awal();
/*Modul ini digunakan untuk menampilkan Menu Home
I.S : Menu tidak tampil
F.S : Menu tampil di layar
*/

void tampilan_peraturan_bermain();
/*
Modul ini digunakan untuk menampilkan Rules Of Game
I.S : Tampilan Menu Home
F.S : Peraturan tampil di layar

*/

void tampilan_exit();
/*Modul ini untuk menampilkan tampilan keluar
I.S : Tampilan Menu Home
F.S : Tampilan keluar game tampil di layar
*/

void tampilan_pilihan_mode();
/*
Modul ini digunakan untuk memilih mode permainan
I.S : Mode permainan belum terpilih
F.S : Mode permainan telah terpilih
*/

void tampilan_pemenang_player1();
/*Modul ini untuk menampilkan pemenang player1
I.S : Player1 Win tidak tampil
F.S : Player1 Win tampil di layar
*/

void tampilan_pilihan_papan();
/*Modul ini digunakan untuk memilih papan permainan
I.S : Papan permainan belum terpilih
F.S : Papan permainan telah terpilih
*/

void tampilan_pilihan_level();
/*
Modul ini digunakan untuk memilih level permainan
I.S : Level belum terpilih
F.S :  Level telah terpilih
*/

void tampilan_pemenang_player2();
/*Modul ini untuk menampilkan pemenang Player2
I.S : Player2 Win tidak tampil
F.S : Player2Win tampil di layar
*/

void tampilan_pemenang_komputer();
/*Modul ini untuk menampilkan pemenang computer
I.S : Computer Win tidak tampil
F.S : Computer Win tampil di laya
*/

void tampilan_pemenang_draw();
/*Modul ini untuk menampilkan apabila tidak ada pemenang
I.S : Draw Game tidak tampil
F.S : Draw Game tampil di layar
*/

void tampilan_masukan_nama();
/*
Modul ini digunakan untuk menginputkan nama pemain
I.S : Nama kosong
F.S : Nama sudah terinput
*/

// Mode permainan
void modePlyvsCmp(); // done
/*
modul yang berisikan kumpulan alur dalam mode permainan player vs komputer
I.S : skor player masih skor awal dan bermain dengan komputer
F.S : menentukan permainan dimenanangkan oleh player 1 atau komputer
*/
void modePlyvsPly(); // done
/*
modul yang berisikan kumpulan alur dalam mode permainan player vs player
I.S : skor player masih skor awal dan bermain dengan player 1 dengan player 2
F.S : menentukan permainan dimenanangkan oleh player 1 atau player 2
*/

void cetak_papan(int size, int modePlyvsCmp);
/*Modul ini untuk menampilkan papan permainan
I.S : Papan permainan tidak tampil
F.S : Papan permainan tampil di layar
*/

void reset_Papan(int size);
/*Modul ini untuk mengembalikan  papan permainan
I.S : Papan permainan belum terubah
F.S : Papan permainan sudah terubah
*/

int cek_papan_kosong(int size);
/*Modul ini untuk memeriksa isi papan kosong
I.S : Papan kosong belum terisi oleh pemain
F.S : Papan terisi penuh oleh pemain
*/

void pergerakan_pemain1(int size);
/*Modul ini untuk pergerakan pemain1 bermain
I.S : Kotak papan kosong belum terisi pemain
F.S : Kotak papan terisi salah satu oleh pemain1
*/

void pergerakan_pemain2(int size);
/*Modul ini untuk pergerakan pemain1 bermain
I.S : Kotak papan kosong belum terisi pemain
F.S : Kotak papan terisi salah satu oleh pemain1
*/

void pergerakan_komputer(int size, int difficulty);
/*Modul ini untuk pergerakan komputer bermain
I.S : Kotak papan kosong belum terisi pemain
F.S : Kotak papan terisi salah satu oleh komputer
*/

char cek_pemenang(int size);
/*Modul ini mengecek pemenang permainan
I.S : Pemenang tidak di ketahui
F.S : Pemenang diketahui
*/

void cetak_pemenang(char winner, int modePlyvsCmp);
/*
modul untuk menampilkan dan menambahkan score apabila pemain menang
I.S : setelah cek pemenang sesuai dengan ketentuan
F.S : menampilkan siapa yang menang yaitu player 1, player 2 atau komputer dan bertambah scorenya
*/
void simpan_highscore(pemain player1, pemain player2, const char *filename);
/*
modul untuk menyimpan hasil permainan
I.S : sudah diketahui siapa pemain yang menang
F.S : menyimpan data hasil permainan yaitu nama pemain dan score kedalam file eksternal bernama "highscore.txt"
*/
void tampil_highscore(const char *filename);
/*
modul untuk menampilkan isi dari file eksternal "highscore.txt"
I.S : file sudah ada dalam file eksternal
F.S : dapat menampilkan isi dari data permainan
*/

int minimax(char currentPlayer, int depth, int size);
/*
modul untuk mengembangkan kecerdasan komputer
I.S : memeriksa apakah masih ada sel kosong atau tidak.
F.s : dapat memperkiran langkah paling tepat untuk melawan player
*/
int evaluateBoard(int size);
/*
modul untuk memberi nilai seberapa besar dalam permainan
I.S : susuai dengan ukuran papan
F.S :  kondisi di mana permainan telah selesai dan skor sesuai dengan hasil permainan (menang, kalah, atau seri).*/

#endif