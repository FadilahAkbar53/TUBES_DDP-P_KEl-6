#ifndef header_H
#define header_H

// Kamus Data
int input_home_menu;
int input_mode_game;

// User Interfaces
void tampilan_menu_awal();        // done
void tampilan_pemenang_player1(); // done
void tampilan_pemenang_player2(); // done
void tampilan_pemenang_komputer();
void tampilan_pemenang_draw();
void tampilan_pilihan_level();
void tampilan_pilihan_mode();      // done
void tampilan_masukan_nama();      // done
void tampilan_pelaturan_bermain(); // done

// opsi pilihan & pelaturan
void pilihan_level();
void pilihan_papan();
void masukan_nama();

//
void cetak_papan();
void pergerakan_pemain();
void pergerakan_komputer();
void kesempatan_waktu();
void cek_papan_kosong();
void cek_pemenang();

#endif