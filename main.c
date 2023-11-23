#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "header.h"
#include "body.c"

// kamus data
int input_home_menu;
int input_mode_game;
int size;
char winner;
char response = ' ';

int main()
{
    tampilan_menu_awal();
    scanf("%d", &input_home_menu);

    switch (input_home_menu)
    {
    case 1: // memulai game

        system("cls");
        tampilan_pilihan_mode();
        scanf("%d", &input_mode_game);

        switch (input_mode_game)
        {
        case 1: // Mode Player vs Computer
            do
            {
                winner = ' ';
                response = ' ';

                printf("\t\t| 3 | 3x3 \n");
                printf("\t\t| 5 | 5x5 \n");
                printf("\t\t| 7 | 7x7 \n");
                printf("Pilih Papan Yang Akan digunakan : ");
                scanf("%d", &size);

                // Validasi ukuran papan
                if (size != 3 && size != 5 && size != 7)
                {
                    printf("Ukuran Papan yang anda pilih salah.\n");
                    return 1;
                }

                // Inisialisasi papan
                reset_Papan(size);

                // Main game loop
                while (1)
                {
                    // Tampilkan papan
                    cetak_papan(size);

                    // Giliran pemain & Periksa kemenangan pemain
                    pergerakan_pemain(size);
                    winner = cek_pemenang(size);
                    if (winner != ' ')
                    {
                        cetak_pemenang(winner);
                        break;
                    }

                    // Giliran komputer & Periksa kemenangan komputer
                    pergerakan_komputer(size);
                    winner = cek_pemenang(size);
                    if (winner != ' ')
                    {
                        cetak_pemenang(winner);
                        break;
                    }
                }

                printf("\nWould you like to play again? (Y/N): ");
                scanf(" %c", &response);
                response = toupper(response);
            } while (response == 'Y');

            printf("terima kasih sudah memainkan");
            break;

        case 2: // mode player vs player(MultiPlayer)

            system("cls");
            tampilan_masukan_nama();
            printf("\n\t               #                                   INPUT PLAYER-1 :                                    #              ");
            printf("\n\t               #                                   INPUT PLAYER-2 :                                    #              ");

            break;
        case 0: // EXIT KEMBALI KE HOME MENU
            system("cls");
            tampilan_menu_awal(); // Kembali ke menu utama
            break;
        default:
            break;
        }
        break;

    case 2: // pelaturan game
        system("cls");
        tampilan_pelaturan_bermain();
        getchar();            // Menunggu hingga pengguna menekan Enter
        tampilan_menu_awal(); // Kembali ke menu utama
        break;
    case 0: // exit
        system("cls");
        printf("THANKS FOR PLAYING TIC TAC TOE");
        break;
    default:
        break;
    }

    return 0;
}
