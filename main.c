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

                switch (input_mode_game)
                {
                case 1: // Mode Player vs Computer
                    do
                    {
                        modePlyvsCmp();

                        printf("\nWould you like to play again? (Y/N): ");
                        scanf(" %c", &response);
                        response = toupper(response);
                    } while (response == 'Y');
                    break;

                case 2: // mode player vs player(MultiPlayer)
                    do
                    {
                        modePlyvsPly();

                        printf("\nWould you like to play again? (Y/N): ");
                        scanf(" %c", &response);
                        response = toupper(response);
                    } while (response == 'Y');
                    break;
                case 0:
                    // keluar dari mode permainan dan kembali ke menu awal
                    break;

                default:
                    break;
                }
            } while (input_mode_game != 0);

            main();

        case 2: // pelaturan game
            system("cls");
            tampilan_peraturan_bermain();
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
