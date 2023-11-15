#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "body.c"

// kamus data
int input_home_menu;
int input_mode_game;

int main()
{

    menu_awal();
    scanf("%d", &input_home_menu);

    switch (input_home_menu)
    {
    case 1: // memulai game
        system("cls");

        printf("masukan angka mode yg dipilih : ");
        scanf("%d", &input_mode_game);

        switch (input_mode_game)
        {
        case 1: // mode player vs computer(Single)
            printf("mode vs computer");
            break;
        case 2: // mode player vs player(MultiPlayer)
            printf("mode vs player");
            break;
        case 0: // EXIT KEMBALI KE HOME MENU
            printf("EXIT");
            break;
        default:
            break;
        }
        break;

    case 2: // pelaturan game
        system("cls");
        pelaturan_bermain();
        break;
    case 0: // exit
        system("cls");
        printf("keluar");
        break;
    default:
        break;
    }

    return 0;
}
