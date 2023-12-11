/*
    NAMA KELOMPOK       : TERUS MAJU
    KELAS               : 1B SEMESTER 1
    ANGGOTA KELOMPOK    : Fadilah Akbar             (231524041) (Ketua)
                          Devi Febrianti		    (231524039)
                          Muhammad Hasbi Asshidiqi	(231524055)
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "header.h"
#include "body.c"

int main()
{
    do
    {
        tampilan_menu_awal();

        switch (input_home_menu)
        {
        case 1: // memulai game
            do
            {
                system("cls");
                tampilan_pilihan_mode();
                do
                {
                    switch (input_mode_game)
                    {

                    case 1: // Mode Player vs Computer (Single)
                        player1.skor = 0;
                        computer.skor = 0;
                        system("cls");
                        tampilan_masukan_nama();
                        printf("\n\t                                                   INPUT NAME PLAYER-1 : ");
                        scanf("%s%[^\n]", player1.nama);

                        system("cls");
                        tampilan_pilihan_level();
                        printf("\n\t                                                   Pilih Level  : ");
                        scanf("%d", &input_mode_level);

                        system("cls");
                        tampilan_pilihan_papan();
                        printf("\n\t                                        Pilih Papan Yang Akan digunakan : ");
                        scanf("%d", &size);

                        do
                        {
                            modePlyvsCmp();
                            printf("\nWould you like to play again? (Y/N): ");
                            scanf(" %c", &response);
                        } while (response == 'y');

                        break;

                    case 2: // mode player vs player (MultiPlayer)
                        player1.skor = 0;
                        player2.skor = 0;
                        system("cls");
                        tampilan_masukan_nama();
                        printf("\n\t                                                   INPUT NAME PLAYER - 1 : ");
                        scanf("%s%[^\n]", &player1.nama);

                        printf("\n\t                                                   INPUT NAME PLAYER - 2 : ");
                        scanf("%s%[^\n]", &player2.nama);

                        tampilan_pilihan_papan();
                        printf("\n\t                                        Pilih Papan Yang Akan digunakan : ");
                        scanf("%d", &size);
                        do
                        {
                            modePlyvsPly();
                            printf("\nWould you like to play again? (Y/N): ");
                            scanf(" %c", &response);
                        } while (response == 'y');
                        break;

                    default:
                        break;
                    }
                } while (response == 'Y');

            } while (input_mode_game != 0); // fitur back halaman sebelumnya

        case 2: // pelaturan game
            system("cls");
            tampilan_peraturan_bermain();
            if (getchar())
            {
                main();
            }
            break;

        case 3:
            system("cls");
            tampil_highscore("highscore2.txt");
            if (getchar())
            {
                main();
            }

            break;

        case 0:
            // keluar dari program
            break;
        default:
            break;
        }

    } while (input_home_menu != 0);

    system("cls");
    tampilan_exit();

    return 0;
}