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
char input_name_player1[20];
char input_name_player2[20];

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

                system("cls");
                tampilan_masukan_nama();
                printf("\n\t                                                   INPUT NAME PLAYER-1 : ");
                scanf("%s", &input_name_player1[20]);

                system("cls");
                tampilan_pilihan_papan();
                printf("\n\t                                        Pilih Papan Yang Akan digunakan : ");
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
                    pergerakan_pemain1(size);
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
            do
            {
                system("cls");
                tampilan_masukan_nama();
                printf("\n\t                                                   INPUT NAME PLAYER-1 : ");
                scanf("%s", &input_name_player1[20]);

                printf("\n\t                                                   INPUT NAME PLAYER-2 : ");
                scanf("%c", &input_name_player2);
                winner = ' ';
                response = ' ';

                tampilan_pilihan_papan();
                printf("\n\t                                        Pilih Papan Yang Akan digunakan : ");
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

                    // Giliran pemain 1 & Periksa kemenangan pemain
                    pergerakan_pemain1(size);
                    winner = cek_pemenang(size);
                    if (winner != ' ')
                    {
                        cetak_pemenang(winner);
                        break;
                    }

                    // Giliran pemain 1 & Periksa kemenangan pemain
                    pergerakan_pemain2(size);
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
