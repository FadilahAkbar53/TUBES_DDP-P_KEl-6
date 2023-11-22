#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "body.c"

// kamus data
// int input_home_menu;
// int input_mode_game;

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
        case 1: // mode player vs computer(Single)
            system("cls");
            printf("mode vs computer");
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
