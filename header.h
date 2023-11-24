#ifndef header_H
#define header_H

typedef struct
{
    char input_name_player1[20];
    char input_name_player2[20];
    int score_permainan;
} pemain;

// Kamus Data
int input_home_menu;
int input_mode_game;

// User Interfaces
void tampilan_menu_awal();         // done
void tampilan_pemenang_player1();  // done
void tampilan_pemenang_player2();  // done
void tampilan_pemenang_komputer(); // done
void tampilan_pemenang_draw();
void tampilan_pilihan_papan();     // done
void tampilan_pilihan_level();     // done
void tampilan_pilihan_mode();      // done
void tampilan_masukan_nama();      // done
void tampilan_pelaturan_bermain(); // done

// opsi pilihan & pelaturan
void pilihan_level();
void input_nama();
void kesempatan_waktu();

void cetak_papan(int size);        // done
void reset_Papan(int size);        // done
int cek_papan_kosong(int size);    // done
void pergerakan_pemain1(int size); // done
void pergerakan_pemain2(int size);
void pergerakan_komputer(int size); // done
char cek_pemenang(int size);        // done
void cetak_pemenang(char winner);   // done

#endif