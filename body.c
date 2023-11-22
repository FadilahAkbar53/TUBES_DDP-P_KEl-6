#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void tampilan_menu_awal()
{
    int inputAwal;
    printf("\n\t        xx   xx                                                                                            xx   xx     ");
    printf("\n\t         xx xx                                                                                              xx xx      ");
    printf("\n\t          xxx    #======================================================================================#    xxx       ");
    printf("\n\t         xx xx   #                                                                                      #   xx xx      ");
    printf("\n\t        xx   xx  #        ww   ww   ww  eeeeee  ll       cccccc    ooooo    mm        mm  eeeeee        #  xx   xx     ");
    printf("\n\t     oooo        #        ww  wwww  ww  ee      ll      cc        oo   oo   mmm      mmm  ee            #        oooo  ");
    printf("\n\t    oo  oo       #        ww ww  ww ww  eeeeee  ll      cc       oo     oo  mm mm  mm mm  eeeeee        #       oo  oo ");
    printf("\n\t    oo  oo       #        www      www  ee      ll      cc        oo   oo   mm   mm   mm  ee            #       oo  oo ");
    printf("\n\t     oooo        #        ww        ww  eeeeee  llllll   cccccc    ooooo    mm        mm  eeeeee        #        oooo  ");
    printf("\n\t                 #                                                                                      #");
    printf("\n\t                 #                                 tttttttt   ooooo                                     #");
    printf("\n\t                 #                                    tt     oo   oo                                    #");
    printf("\n\t                 #                                    tt    oo     oo                                   #");
    printf("\n\t                 #                                    tt     oo   oo                                    #");
    printf("\n\t                 #                                    tt      ooooo                                     #");
    printf("\n\t                 #                                                                                      #");
    printf("\n\t                 #   xxxxxxxx  oo  xx  xx    xxxxxxxx    ooo      xx  xx    xxxxxxxx  ooooo    xxxxxx   #");
    printf("\n\t                 #      xx     oo  xx xx        xx      oo oo     xx xx        xx    oo   oo   xx       #");
    printf("\n\t    xx   xx      #      xx     oo  xxx          xx     ooooooo    xxx          xx   oo     oo  xxxxxx   #      xx   xx ");
    printf("\n\t     xx xx       #      xx     oo  xx xx        xx    oo     oo   xx xx        xx    oo   oo   xx       #       xx xx  ");
    printf("\n\t      xxx        #      xx     oo  xx   xx      xx   oo       oo  xx   xx      xx     ooooo    xxxxxx   #        xxx   ");
    printf("\n\t     xx xx       #                                                                                      #       xx xx  ");
    printf("\n\t    xx   xx      # ==================================================================================== #      xx   xx ");
    printf("\n\t          oooo   #                     oxoxoxoxoxoxoxox MENU HOME xoxoxoxoxoxoxoxo                      #   oooo       ");
    printf("\n\t         oo  oo  # ==================================================================================== #  oo  oo      ");
    printf("\n\t         oo  oo  #                                     |1| START                                        #  oo  oo      ");
    printf("\n\t          oooo   #                                     |2| RULE OF GAME                                 #   oooo       ");
    printf("\n\t                 #                                     |0| QUIT                                         #");
    printf("\n\t                 # ==================================================================================== #");
    printf("\n\t                                                     Masukan Angka : ");
}

void tampilan_pelaturan_bermain()
{
    system("cls");
    printf("\n\t      xx   xx                                                                                            xx   xx     ");
    printf("\n\t       xx xx                                                                                              xx xx      ");
    printf("\n\t        xxx    ########################################################################################    xxx       ");
    printf("\n\t       xx xx   #                                                                                      #   xx xx      ");
    printf("\n\t      xx   xx  #                       rrrrr   uu   uu  ll      eeeeee   sssss                        #  xx   xx     ");
    printf("\n\t   oooo        #                       rr   r  uu   uu  ll      ee      s                             #        oooo  ");
    printf("\n\t  oo  oo       #                       rrrrr   uu   uu  ll      eeeeee  s                             #       oo  oo ");
    printf("\n\t  oo  oo       #                       rrr     uu   uu  ll      eeeeee   sssss                        #       oo  oo ");
    printf("\n\t   oooo        #                       rr rr   uu   uu  ll      ee            s                       #        oooo  ");
    printf("\n\t               #                       rr  rr   uuuuu   llllll  eeeeee   sssss                        #");
    printf("\n\t               #                                                                                      #");
    printf("\n\t               #        ooooo    ffffff          ggggg         aaa       mm            mm  eeeeee     #");
    printf("\n\t               #       oo   oo   ff             gg            aa aa      mmm          mmm  ee         #");
    printf("\n\t               #      oo     oo  ffffff         gg           aa   aa     mm mm      mm mm  eeeeee     #");
    printf("\n\t               #      oo     oo  ff             gg  gggg    aaaaaaaaa    mm   mm  mm   mm  eeeeee     #");
    printf("\n\t               #       oo   oo   ff             gg    gg   aa       aa   mm     mm     mm  ee         #");
    printf("\n\t               #        ooooo    ff              gggggg   aa         aa  mm            mm  eeeeee     #");
    printf("\n\t               #                                                                                      #");
    printf("\n\t               # ==================================================================================== #");
    printf("\n\t               #                xoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxoxox                 #");
    printf("\n\t               # ==================================================================================== #");
    printf("\n\t               #                                                                                      #");
    printf("\n\t               # 1.Besar papan permainan berukuran 3x3 dengan deret kemenangan 3 bidak, berukuran 5x5 #");
    printf("\n\t               #   deret kemenangan 4 bidak, atau berukuran 7x7 dengan deret kemenangan 5 bidak.      #");
    printf("\n\t               # 2.Pemain dalam permainan ini dibatasi untuk satu lawan satu, dilakukan bergiliran    #");
    printf("\n\t               #   antara manusia dan manusia.                                                        #");
    printf("\n\t               # 3.Untuk memberikan langkah, setiap pemain harus mengisi bidak dengan simbol pemain   #");
    printf("\n\t               #   masing-masing, biasanya X atau O.                                                  #");
    printf("\n\t               # 4.Setiap pemain hanya mempunyai satu kali kesempatan pada setiap giliran.            #");
    printf("\n\t               # 5.Setiap pemain diberi waktu kesempatan untuk memilih tempat yang di isikan selama   #");
    printf("\n\t               #   10 detik.                                                                          #");
    printf("\n\t               # 6.Bidak yang sudah terisi tidak bisa ditimpa oleh bidak lain pada langkah berikutnya.#");
    printf("\n\t  xx   xx      # 7.Langkah yang sudah diambil tidak dapat dibatalkan atau diganti dengan langkah yang #      xx   xx ");
    printf("\n\t   xx xx       #   lain.                                                                              #       xx xx  ");
    printf("\n\t    xxx        # 8.Tujuan dari permainan ini adalah untuk mendapatkan deret dengan tiga(3), empat(4)  #        xxx   ");
    printf("\n\t   xx xx       #   atau lima (5) bidak yang sama secara horizontal, vertikal atau diagonal.           #       xx xx  ");
    printf("\n\t  xx   xx      # 9.Pemenangnya adalah yang berhasil terlebih dahulu membuat 3 deretan xxx atau ooo    #      xx   xx ");
    printf("\n\t        oooo   #   untuk 3x3 membuat 4 deret xxxx atau oooo untuk 5x5, dan membuat 5 deret xxxxx atau #   oooo       ");
    printf("\n\t       oo  oo  #   ooooo untuk 7x7.                                                                   #  oo  oo      ");
    printf("\n\t       oo  oo  # 10.Permainan akan dihentikan jika sudah ada pemenang atau papan permainan penuh.     #  oo  oo      ");
    printf("\n\t        oooo   #                                                                                      #   oooo       ");
    printf("\n\t               ########################################################################################");
    printf("\n\t               #                                                                                      #");
    printf("\n\t               #                              Press Enter to continue...                              #");
    getchar(); // Membaca karakter newline setelah Enter
}

void tampilan_pilihan_mode()
{
    system("cls");
    printf("\n\t      xx   xx                                                                                           xx   xx     ");
    printf("\n\t       xx xx                                                                                             xx xx      ");
    printf("\n\t        xxx    #######################################################################################    xxx       ");
    printf("\n\t       xx xx   #                                                                                     #   xx xx      ");
    printf("\n\t      xx   xx  #      cccccc  hh    hh    ooooo      ooooo      sssss   eeeeee                       #  xx   xx     ");
    printf("\n\t   oooo        #     cc       hh    hh   oo   oo    oo   oo    s        ee                           #        oooo  ");
    printf("\n\t  oo  oo       #     cc       hhhhhhhh  oo     oo  oo     oo   s        eeeeee                       #       oo  oo ");
    printf("\n\t  oo  oo       #     cc       hhhhhhhh  oo     oo  oo     oo    sssss   eeeeee                       #       oo  oo ");
    printf("\n\t   oooo        #     cc       hh    hh   oo   oo    oo   oo          s  ee                           #        oooo  ");
    printf("\n\t               #      cccccc  hh    hh    ooooo      ooooo     ssssss   eeeeee                       #");
    printf("\n\t               #                                                                                     #");
    printf("\n\t               #                                ggggg         aaa       mm            mm  eeeeee     #");
    printf("\n\t               #                               gg            aa aa      mmm          mmm  ee         #");
    printf("\n\t               #                               gg           aa   aa     mm mm      mm mm  eeeeee     #");
    printf("\n\t               #                               gg  gggg    aaaaaaaaa    mm   mm  mm   mm  eeeeee     #");
    printf("\n\t               #                               gg    gg   aa       aa   mm     mm     mm  ee         #");
    printf("\n\t               #                                gggggg   aa         aa  mm            mm  eeeeee     #");
    printf("\n\t               #                                                                                     #");
    printf("\n\t               #     mm           mm    ooooo     dddddd   eeeeee                                    #");
    printf("\n\t               #     mmm         mmm   oo   oo    dd    d  ee                                        #");
    printf("\n\t               #     mm mm     mm mm  oo     oo   dd    d  eeeeee                                    #");
    printf("\n\t               #     mm   mm  mm  mm  oo     oo   dd    d  eeeeee                                    #");
    printf("\n\t               #     mm     mm    mm   oo   oo    dd    d  ee                                        #");
    printf("\n\t  xx   xx      #     mm           mm    ooooo     dddddd   eeeeee                                    #      xx   xx ");
    printf("\n\t   xx xx       #                                                                                     #       xx xx  ");
    printf("\n\t    xxx        # =================================================================================== #        xxx   ");
    printf("\n\t   xx xx       #                     oxoxoxoxoxoxoxoxox MENU  xoxoxoxoxoxoxoxoxo                     #       xx xx  ");
    printf("\n\t  xx   xx      # =================================================================================== #      xx   xx ");
    printf("\n\t        oooo   #                                |1| Player VS Computer                               #   oooo       ");
    printf("\n\t       oo  oo  #                                |2| Player VS Player                                 #  oo  oo      ");
    printf("\n\t       oo  oo  #                                |0| Back                                             #  oo  oo      ");
    printf("\n\t        oooo   # =================================================================================== #   oooo       ");
    printf("\n\t                                                   Masukan Angka : ");
}

void tampilan_masukan_nama()
{
    system("cls");
    printf("\n\t      xx   xx                                                                                            xx   xx     ");
    printf("\n\t       xx xx                                                                                              xx xx      ");
    printf("\n\t        xxx    ########################################################################################    xxx       ");
    printf("\n\t       xx xx   #                                                                                      #   xx xx      ");
    printf("\n\t      xx   xx  #         ii  n    nn  ppppp   uu   uu  tttttttt                                       #  xx   xx     ");
    printf("\n\t   oooo        #         ii  nn   nn  pp   p  uu   uu     tt                                          #        oooo  ");
    printf("\n\t  oo  oo       #         ii  nnn  nn  pppppp  uu   uu     tt                                          #       oo  oo ");
    printf("\n\t  oo  oo       #         ii  nn  nnn  pp      uu   uu     tt                                          #       oo  oo ");
    printf("\n\t   oooo        #         ii  nn   nn  pp      uu   uu     tt                                          #        oooo  ");
    printf("\n\t               #         ii  nn    n  pp       uuuuu      tt                                          #");
    printf("\n\t               #                                                                                      #");
    printf("\n\t  xx   xx      #                                                                                      #      xx   xx ");
    printf("\n\t   xx xx       #                              n    nn       aaa       mm            mm  eeeeee        #       xx xx  ");
    printf("\n\t    xxx        #                              nn   nn      aa aa      mmm          mmm  ee            #        xxx   ");
    printf("\n\t   xx xx       #                              nnn  nn     aa   aa     mm mm      mm mm  eeeeee        #       xx xx  ");
    printf("\n\t  xx   xx      #                              nn  nnn    aaaaaaaaa    mm   mm  mm   mm  eeeeee        #      xx   xx ");
    printf("\n\t        oooo   #                              nn   nn   aa       aa   mm     mm     mm  ee            #   oooo       ");
    printf("\n\t       oo  oo  #                              nn    n  aa         aa  mm            mm  eeeeee        #  oo  oo      ");
    printf("\n\t       oo  oo  #                                                                                      #  oo  oo      ");
    printf("\n\t        oooo   ########################################################################################   oooo       ");
}

void tampilan_pemenang_player1()
{
    printf("\n\t      xx   xx                                                                                            xx   xx     ");
    printf("\n\t       xx xx                                                                                              xx xx      ");
    printf("\n\t        xxx    ########################################################################################    xxx       ");
    printf("\n\t       xx xx   #                                                                                      #   xx xx      ");
    printf("\n\t      xx   xx  #          ppppp   ll           aaa     yy    yy  eeeeee  rrrrr        11              #  xx   xx     ");
    printf("\n\t   oooo        #          pp   p  ll          aa aa     yy  yy   ee      rr   r     1111              #        oooo  ");
    printf("\n\t  oo  oo       #          pp   p  ll         aa   aa     yyyy    eeeeee  rrrrr        11              #       oo  oo ");
    printf("\n\t  oo  oo       #          ppppp   ll        aaaaaaaaa     yy     eeeeee  rrr          11              #       oo  oo ");
    printf("\n\t   oooo        #          pp      ll       aa       aa    yy     ee      rr rr        11              #        oooo  ");
    printf("\n\t               #          pp      llllll  aa         aa   yy     eeeeee  rr  rr     11111             #");
    printf("\n\t               #                                                                                      #");
    printf("\n\t               #                            ww        ww  ii  n    nn                                 #");
    printf("\n\t  xx   xx      #                            ww   ww   ww  ii  nn   nn                                 #      xx   xx  ");
    printf("\n\t   xx xx       #                            ww  wwww  ww  ii  nnn  nn                                 #       xx xx   ");
    printf("\n\t    xxx        #                            ww ww  ww ww  ii  nn  nnn                                 #         xx    ");
    printf("\n\t   xx xx       #                            www      www  ii  nn   nn                                 #       xx xx   ");
    printf("\n\t  xx   xx      #                            ww        ww  ii  nn    n                                 #      xx   xx  ");
    printf("\n\t        oooo   #                                                                                      #   oooo        ");
    printf("\n\t       oo  oo  ########################################################################################  oo  oo       ");
    printf("\n\t       oo  oo                                                                                            oo  oo       ");
    printf("\n\t        oooo                                                                                              oooo        ");
}
void tampilan_pemenang_player2()
{
    printf("\n\t      xx   xx                                                                                            xx   xx     ");
    printf("\n\t       xx xx                                                                                              xx xx      ");
    printf("\n\t        xxx    ########################################################################################    xxx       ");
    printf("\n\t       xx xx   #                                                                                      #   xx xx      ");
    printf("\n\t      xx   xx  #          ppppp   ll           aaa     yy    yy  eeeeee  rrrrr       22222            #  xx   xx     ");
    printf("\n\t   oooo        #          pp   p  ll          aa aa     yy  yy   ee      rr   r     22  22            #        oooo  ");
    printf("\n\t  oo  oo       #          pp   p  ll         aa   aa     yyyy    eeeeee  rrrrr         22             #       oo  oo ");
    printf("\n\t  oo  oo       #          ppppp   ll        aaaaaaaaa     yy     eeeeee  rrr          22              #       oo  oo ");
    printf("\n\t   oooo        #          pp      ll       aa       aa    yy     ee      rr rr       22               #        oooo  ");
    printf("\n\t               #          pp      llllll  aa         aa   yy     eeeeee  rr  rr     222222            #");
    printf("\n\t               #                                                                                      #");
    printf("\n\t               #                            ww        ww  ii  n    nn                                 #");
    printf("\n\t  xx   xx      #                            ww   ww   ww  ii  nn   nn                                 #      xx   xx  ");
    printf("\n\t   xx xx       #                            ww  wwww  ww  ii  nnn  nn                                 #       xx xx   ");
    printf("\n\t    xxx        #                            ww ww  ww ww  ii  nn  nnn                                 #         xx    ");
    printf("\n\t   xx xx       #                            www      www  ii  nn   nn                                 #       xx xx   ");
    printf("\n\t  xx   xx      #                            ww        ww  ii  nn    n                                 #      xx   xx  ");
    printf("\n\t        oooo   #                                                                                      #   oooo        ");
    printf("\n\t       oo  oo  ########################################################################################  oo  oo       ");
    printf("\n\t       oo  oo                                                                                            oo  oo       ");
    printf("\n\t        oooo                                                                                              oooo        ");
}
