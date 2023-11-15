#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void menu_awal()
{
    int inputAwal;
    printf("\t====================================================================\n");
    printf("\n\t       O)))))      O))      O))      O)))))      O))      O))     ");
    printf("\n\t    O))     O)))    O))   O))     O))     O)))    O))   O))");
    printf("\n\t   O))        O)))   O)) O))     O))        O)))   O)) O))");
    printf("\n\t   O))        O)))     O))       O))        O)))     O))");
    printf("\n\t   O))        O))    O)) O))     O))        O))    O)) O))");
    printf("\n\t    O))     O)))    O))   O))     O))     O)))    O))   O))");
    printf("\n\t       O)))))      O))      O))      O)))))      O))      O))\n");
    printf("\n\t                           TIC TAC TOE  \n");
    printf("\n\t====================================================================");
    printf("\n\t         ooooooooooooooooo  HOME MENU  oooooooooooooooooo");
    printf("\n\t====================================================================");
    printf("\n\n\t                           |1| START  ");
    printf("\n\n\t                           |2| RULES IN GAMES  ");
    printf("\n\n\t                           |0| EXIT  ");
    printf("\n\n\t====================================================================");
    printf("\n\n\t                           MASUKAN ANGKA : ");
}

void pelaturan_bermain()
{
    system("cls");
    printf("========================================================================================================");
    printf("\n    //   ) )                                             //  ) )   //   ) )                              ");
    printf("\n   //___/ /            //  ___      ___         ___   __//__      //         ___      _   __      ___     ");
    printf("\n  // ___ (   //   / / // //___))  ((   ))     //   ) ) //        //  ____  //   ) ) // ) )  ) )  //___))  ");
    printf("\n //    | |  //   / / // //         \\\\        //   / / //        //    / / //    / / // / /  / / //        ");
    printf("\n//     | | ((___( ( // ((____   //   ) )    ((___/ / //        ((____/ / ((___( ( // / /  / /  ((____");
    printf("\n========================================================================================================");
    printf("\n\n|1|. Besar papan permainan berukuran 3x3 dengan deret kemenangan 3 bidak, berukuran 5x5 dengan \n     deret kemenangan 4 bidak, atau berukuran 7x7 dengan deret kemenangan 5 bidak.");
    printf("\n\n|2|. Pemain dalam permainan ini dibatasi untuk satu lawan satu, dilakukan bergiliran antara \n      manusia dan manusia.");
    printf("\n\n|3|. Untuk memberikan langkah, setiap pemain harus mengisi bidak dengan simbol pemain \n      masing-masing, biasanya X atau O.");
    printf("\n\n|4|. Setiap pemain hanya mempunyai satu kali kesempatan pada setiap giliran. ");
    printf("\n\n|5|. Setiap pemain diberi waktu kesempatan untuk memilih tempat yang di isikan selama 10 detik.");
    printf("\n\n|6|. Bidak yang sudah terisi tidak bisa ditimpa oleh bidak lain pada langkah berikutnya. ");
    printf("\n\n|7|. Langkah yang sudah diambil tidak dapat dibatalkan atau diganti dengan langkah yang lain.");
    printf("\n\n|8|. Tujuan dari permainan ini adalah untuk mendapatkan deret dengan tiga (3), empat (4), \n    atau lima (5) bidak yang sama secara horizontal, vertikal atau diagonal. ");
    printf("\n\n|9|. Pemenangnya adalah yang berhasil terlebih dahulu membuat 3 deretan xxx atau ooo untuk 3x3,\n     membuat 4 deret xxxx atau oooo untuk 5x5, dan membuat 5 deret xxxxx atau ooooo untuk 7x7.");
    printf("\n\n|10|. Permainan akan dihentikan jika sudah ada pemenang atau papan permainan penuh. ");
    printf("\n\n========================================================================================================");
}

void pilihan_mode();
