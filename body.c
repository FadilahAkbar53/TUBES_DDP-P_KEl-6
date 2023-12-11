#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include "header.h"

#define MAX_SIZE 7
#define TURN_TIME_LIMIT 5

char board[MAX_SIZE][MAX_SIZE];
const char PLAYER1 = 'X';
const char PLAYER2 = '0';
const char COMPUTER = 'O';

void reset_Papan(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = ' ';
        }
    }
}

int cek_papan_kosong(int size)
{
    int kotakKosong = size * size;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] != ' ')
            {
                kotakKosong--;
            }
        }
    }
    return kotakKosong;
}

void pergerakan_pemain1(int size)
{
    int x, y;
    startTime = time(NULL);

    do
    {
        printf("PLAYER 1 - X %s\n", &player1.nama);
        printf("Enter row #(1-%d): ", size);
        scanf(" %d", &x);
        x--;
        printf("Enter column #(1-%d): ", size);
        scanf(" %d", &y);
        y--;

        if (x < 0 || x >= size || y < 0 || y >= size)
        {
            printf("Invalid move! Out of bounds.\n");
        }
        else if (board[x][y] != ' ')
        {
            printf("Invalid move! Cell already occupied.\n");
        }
        else
        {
            board[x][y] = PLAYER1;
            cetak_papan(size, 1);
            break;
        }
    } while (board[x][y] != ' ' && difftime(time(NULL), startTime) <= TURN_TIME_LIMIT);
}

void pergerakan_pemain2(int size)
{
    int x, y;
    startTime = time(NULL);

    do
    {
        printf("PLAYER 2 - O %s\n", &player2.nama);
        printf("Enter row #(1-%d): ", size);
        scanf(" %d", &x);
        x--;
        printf("Enter column #(1-%d): ", size);
        scanf(" %d", &y);
        y--;

        if (x < 0 || x >= size || y < 0 || y >= size)
        {
            printf("Invalid move! Out of bounds.\n");
        }
        else if (board[x][y] != ' ')
        {
            printf("Invalid move! Cell already occupied.\n");
        }
        else
        {
            board[x][y] = PLAYER2;
            cetak_papan(size, 2);
            break;
        }
    } while (board[x][y] != ' ' && difftime(time(NULL), startTime) <= TURN_TIME_LIMIT);
}

void pergerakan_komputer(int size, int difficulty)
{
    int bestMove;
    if (cek_papan_kosong(size) > 0)
    {
        switch (difficulty)
        {
        case 1: // Easy
            do
            {
                bestMove = rand() % (size * size);
            } while (board[bestMove / size][bestMove % size] != ' ');
            break;

        case 2: // Medium
            bestMove = minimax(COMPUTER, 5, size);
            break;

        case 3: // Hard
            bestMove = minimax(COMPUTER, 10, size);
            break;

        default:
            break;
        }

        board[bestMove / size][bestMove % size] = COMPUTER;
    }
    else
    {
        cetak_papan(size, 1);
        cetak_pemenang(' ', 1);
    }
}

int minimax(char currentPlayer, int depth, int size)
{
    int score;
    int bestScore;

    if (currentPlayer == COMPUTER)
        bestScore = INT_MIN;
    else
        bestScore = INT_MAX;

    if (depth == 0 || cek_papan_kosong(size) == 0 || cek_pemenang(size) != ' ')
        return evaluateBoard(size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = currentPlayer;

                if (currentPlayer == COMPUTER)
                {
                    score = minimax(PLAYER1, depth - 1, size);
                    bestScore = (score > bestScore) ? score : bestScore;
                }
                else
                {
                    score = minimax(COMPUTER, depth - 1, size);
                    bestScore = (score < bestScore) ? score : bestScore;
                }

                board[i][j] = ' ';
            }
        }
    }

    return bestScore;
}

int evaluateBoard(int size)
{
    char winner = cek_pemenang(size);

    if (winner == COMPUTER)
        return 10000; // Skor tinggi jika komputer menang
    else if (winner == PLAYER1)
        return -10000; // Skor rendah jika pemain 1 menang
    else
        return 0; // Skor seimbang jika belum ada pemenang
}

char cek_pemenang(int size)
{
    int winCondition = (size == 3) ? 3 : ((size == 5) ? 4 : 5);

    for (int i = 0; i < size; i++)
    {
        // Check rows
        for (int j = 0; j <= size - winCondition; j++)
        {
            char firstCell = board[i][j];
            int count = 0;
            for (int k = 0; k < winCondition; k++)
            {
                if (board[i][j + k] == firstCell && firstCell != ' ')
                {
                    count++;
                }
            }
            if (count == winCondition)
            {
                return firstCell;
            }
        }

        // Check columns
        for (int j = 0; j <= size - winCondition; j++)
        {
            char firstCell = board[j][i];
            int count = 0;
            for (int k = 0; k < winCondition; k++)
            {
                if (board[j + k][i] == firstCell && firstCell != ' ')
                {
                    count++;
                }
            }
            if (count == winCondition)
            {
                return firstCell;
            }
        }
    }

    // Check diagonals
    for (int i = 0; i <= size - winCondition; i++)
    {
        for (int j = 0; j <= size - winCondition; j++)
        {
            char firstCell = board[i][j];
            int count = 0;
            for (int k = 0; k < winCondition; k++)
            {
                if (board[i + k][j + k] == firstCell && firstCell != ' ')
                {
                    count++;
                }
            }
            if (count == winCondition)
            {
                return firstCell;
            }
        }
    }

    for (int i = 0; i <= size - winCondition; i++)
    {
        for (int j = winCondition - 1; j < size; j++)
        {
            char firstCell = board[i][j];
            int count = 0;
            for (int k = 0; k < winCondition; k++)
            {
                if (board[i + k][j - k] == firstCell && firstCell != ' ')
                {
                    count++;
                }
            }
            if (count == winCondition)
            {
                return firstCell;
            }
        }
    }

    return ' ';
}

void cetak_pemenang(char winner, int modePlyvsCmp)
{
    if (winner == PLAYER1)
    {
        tampilan_pemenang_player1();
        player1.skor++;
    }
    else if (winner == PLAYER2)
    {
        tampilan_pemenang_player2();
        player2.skor++;
    }
    else if (winner == COMPUTER)
    {
        tampilan_pemenang_komputer();
        computer.skor++;
    }
    else
    {
        tampilan_pemenang_draw();
    }
}

void modePlyvsCmp() // Player vs Computer
{
    winner = ' ';

    // Validasi ukuran papan
    if (size != 3 && size != 5 && size != 7)
    {
        printf("Ukuran Papan yang anda pilih salah.\n");
        return;
    }

    // Inisialisasi papan
    reset_Papan(size);

    // Main game loop
    while (1)
    {
        // Tampilkan papan
        cetak_papan(size, 1);

        // Giliran pemain & Periksa kemenangan pemain
        pergerakan_pemain1(size);
        winner = cek_pemenang(size);
        if (winner != ' ' || cek_papan_kosong(size) == 0)
        {
            cetak_pemenang(winner, 1);
            simpan_highscore(player1, computer, "highscore1.txt");
            break;
        }

        // Giliran komputer & Periksa kemenangan komputer
        pergerakan_komputer(size, 1);
        winner = cek_pemenang(size);
        if (winner != ' ' || cek_papan_kosong(size) == 0)
        {
            cetak_pemenang(winner, 1);
            simpan_highscore(player1, computer, "highscore1.txt");
            break;
        }
    }
}

void modePlyvsPly() // Player1 vs player2
{
    winner = ' ';

    // Validasi ukuran papan
    if (size != 3 && size != 5 && size != 7)
    {
        printf("Ukuran Papan yang anda pilih salah.\n");
        return;
    }

    // Inisialisasi papan
    reset_Papan(size);

    // Main game loop
    while (1)
    {

        // Tampilkan papan
        cetak_papan(size, 2);

        // Giliran pemain 1 & Periksa kemenangan pemain
        pergerakan_pemain1(size);
        winner = cek_pemenang(size);
        if (winner != ' ' || cek_papan_kosong(size) == 0)
        {
            cetak_pemenang(winner, 1);
            simpan_highscore(player1, player2, "highscore2.txt");
            break;
        }

        // Giliran pemain 1 & Periksa kemenangan pemain
        pergerakan_pemain2(size);
        winner = cek_pemenang(size);
        if (winner != ' ' || cek_papan_kosong(size) == 0)
        {
            cetak_pemenang(winner, 1);
            simpan_highscore(player1, player2, "highscore2.txt");
            break;
        }
    }
}

void cetak_papan(int size, int modePlyvsCmp)
{
    if (size == 3)
    {
        system("cls");

        if (modePlyvsCmp == 1)
        {
            printf("\n\t\t=============================          Name Player 1 : %s ", player1.nama);
            printf("\n\t\t|                           |          Score Winner  : %d ", player1.skor);
            printf("\n\t\t|   ==== Board 3x3 ====     |");
            printf("\n\t\t|                           |          ");
            printf("\n\t\t=============================          ");
        }
        else
        {
            printf("\n\t\t=============================          Name Player 1 : %s ", player1.nama);
            printf("\n\t\t|                           |          Score Winner  : %d ", player1.skor);
            printf("\n\t\t|   ==== Board 3x3 ====     |");
            printf("\n\t\t|                           |          Name Player 2 : %s ", player2.nama);
            printf("\n\t\t=============================          Score Winner  : %d ", player2.skor);
        }

        printf("\n\t\t|        |        |        |");
        printf("\n\t\t|    %C   |    %C   |    %C   |", board[0][0], board[0][1], board[0][2]);
        printf("\n\t\t|        |        |        |");
        printf("\n\t\t|--------+--------+--------| ");
        printf("\n\t\t|        |        |        |");
        printf("\n\t\t|    %C   |    %C   |    %C   |", board[1][0], board[1][1], board[1][2]);
        printf("\n\t\t|        |        |        |");
        printf("\n\t\t|--------+--------+--------| ");
        printf("\n\t\t|        |        |        |");
        printf("\n\t\t|    %C   |    %C   |    %C   |", board[2][0], board[2][1], board[2][2]);
        printf("\n\t\t|        |        |        |");
        printf("\n\t\t|--------------------------| ");
        printf("\n");
    }
    if (size == 5)
    {
        system("cls");
        if (modePlyvsCmp == 1)
        {
            printf("\n\t\t================================================          Name Player 1 : %s ", player1.nama);
            printf("\n\t\t|                                              |          Score Winner  : %d ", player1.skor);
            printf("\n\t\t|        ========= Board 5x5 =========         |");
            printf("\n\t\t|                                              |");
            printf("\n\t\t===============================================");
        }
        else
        {
            printf("\n\t\t================================================          Name Player 1 : %s ", player1.nama);
            printf("\n\t\t|                                              |          Score Winner  : %d ", player1.skor);
            printf("\n\t\t|        ========= Board 5x5 =========         |");
            printf("\n\t\t|                                              |          Name Player 2 : %s ", player2.nama);
            printf("\n\t\t===============================================           Score Winner  : %d ", player2.skor);
        }
        printf("\n\t\t|        |        |        |         |         |");
        printf("\n\t\t|    %c   |    %c   |    %c   |     %c   |      %c  |", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4]);
        printf("\n\t\t|        |        |        |         |         |");
        printf("\n\t\t|--------+--------+--------+---------+---------|");
        printf("\n\t\t|        |        |        |         |         |");
        printf("\n\t\t|    %c   |    %c   |    %c   |     %c   |      %c  |", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4]);
        printf("\n\t\t|        |        |        |         |         |");
        printf("\n\t\t|--------+--------+--------+---------+---------|");
        printf("\n\t\t|        |        |        |         |         |");
        printf("\n\t\t|    %c   |    %c   |    %c   |     %c   |      %c  |", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4]);
        printf("\n\t\t|        |        |        |         |         |");
        printf("\n\t\t|--------+--------+--------+---------+---------|");
        printf("\n\t\t|        |        |        |         |         |");
        printf("\n\t\t|    %c   |    %c   |    %c   |     %c   |      %c  |", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4]);
        printf("\n\t\t|        |        |        |         |         |");
        printf("\n\t\t|--------+--------+--------+---------+---------|");
        printf("\n\t\t|        |        |        |         |         |");
        printf("\n\t\t|    %c   |    %c   |    %c   |     %c   |      %c  |", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4]);
        printf("\n\t\t|        |        |        |         |         |");
        printf("\n\t\t|----------------------------------------------|");
        printf("\n");
    }
    if (size == 7)
    {
        system("cls");
        if (modePlyvsCmp == 1)
        {
            printf("\n\t\t====================================================================          Name Player 1 : %s ", player1.nama);
            printf("\n\t\t|                                                                  |          Score Winner  : %d ", player1.skor);
            printf("\n\t\t|                     ========= Board 7x7 =========                |");
            printf("\n\t\t|                                                                  |");
            printf("\n\t\t====================================================================");
        }
        else
        {
            printf("\n\t\t====================================================================          Name Player 1 : %s ", player1.nama);
            printf("\n\t\t|                                                                  |          Score Winner  : %d ", player1.skor);
            printf("\n\t\t|                     ========= Board 7x7 =========                |");
            printf("\n\t\t|                                                                  |          Name Player 2 : %s ", player2.nama);
            printf("\n\t\t====================================================================          Score Winner  : %d ", player2.skor);
        }
        printf("\n\t\t|        |        |        |         |         |         |         |");
        printf("\n\t\t|    %c   |    %c   |    %c   |     %c   |     %c   |     %c   |    %c    |", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6]);
        printf("\n\t\t|        |        |        |         |         |         |         |");
        printf("\n\t\t|--------+--------+--------+---------+---------+---------+---------|");
        printf("\n\t\t|        |        |        |         |         |         |         |");
        printf("\n\t\t|    %c   |    %c   |    %c   |     %c   |     %c   |     %c   |    %c    |", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6]);
        printf("\n\t\t|        |        |        |         |         |         |         |");
        printf("\n\t\t|--------+--------+--------+---------+---------+---------+---------|");
        printf("\n\t\t|        |        |        |         |         |         |         |");
        printf("\n\t\t|    %c   |    %c   |    %c   |     %c   |     %c   |     %c   |    %c    |", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6]);
        printf("\n\t\t|        |        |        |         |         |         |         |");
        printf("\n\t\t|--------+--------+--------+---------+---------+---------+---------|");
        printf("\n\t\t|        |        |        |         |         |         |         |");
        printf("\n\t\t|    %c   |    %c   |    %c   |     %c   |     %c   |     %c   |    %c    |", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6]);
        printf("\n\t\t|        |        |        |         |         |         |         |");
        printf("\n\t\t|--------+--------+--------+---------+---------+---------+---------|");
        printf("\n\t\t|        |        |        |         |         |         |         |");
        printf("\n\t\t|    %c   |    %c   |    %c   |     %c   |     %c   |     %c   |    %c    |", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6]);
        printf("\n\t\t|        |        |        |         |         |         |         |");
        printf("\n\t\t|--------+--------+--------+---------+---------+---------+---------|");
        printf("\n\t\t|        |        |        |         |         |         |         |");
        printf("\n\t\t|    %c   |    %c   |    %c   |     %c   |     %c   |     %c   |    %c    |", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6]);
        printf("\n\t\t|        |        |        |         |         |         |         |");
        printf("\n\t\t|--------+--------+--------+---------+---------+---------+---------|");
        printf("\n\t\t|        |        |        |         |         |         |         |");
        printf("\n\t\t|    %c   |    %c   |    %c   |     %c   |     %c   |     %c   |    %c    |", board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6]);
        printf("\n\t\t|        |        |        |         |         |         |         |");
        printf("\n\t\t|------------------------------------------------------------------|");
        printf("\n\n");
    }
}

void simpan_highscore(pemain player1, pemain player2, const char *filename)
{
    // Mode Player vs Player
    FILE *file = fopen("highscore2.txt", "a");
    if (file == NULL)
    {
        printf("Gagal membuka file highscore.txt\n");
        return;
    }

    if (player2.nama[0] == '\0') // Mode player vs computer
    {
        file = fopen("highscore1.txt", "a+");
        if (file == NULL)
        {
            printf("Gagal membuka file highscore1.txt\n");
            return;
        }

        // Mencari nama pemain di file dan menambahkan skor jika ditemukan
        int found = 0;
        pemain current_player;
        while (fscanf(file, "%s %d", current_player.nama, &current_player.skor) != EOF)
        {
            if (strcmp(current_player.nama, player1.nama) == 0)
            {
                current_player.skor += player1.skor;
                found = 1;
                break;
            }
        }

        // Menulis data jika nama pemain tidak ditemukan
        if (!found)
        {
            fprintf(file, "%s %d\n", player1.nama, player1.skor);
        }

        fclose(file);
    }

    else // Mode Player vs Player
    {
        file = fopen("highscore2.txt", "a");
        if (file == NULL)
        {
            printf("Gagal membuka file highscore2.txt\n");
            return;
        }

        // Mencari nama pemain di file dan menambahkan skor jika ditemukan
        int found = 0;
        pemain current_player1, current_player2;
        while (fscanf(file, "%s %d %s %d", current_player1.nama, &current_player1.skor, current_player2.nama, &current_player2.skor) != EOF)
        {
            if (strcmp(current_player1.nama, player1.nama) == 0)
            {
                current_player1.skor += player1.skor;
                found = 1;
                break;
            }
        }

        // Menulis data jika nama pemain tidak ditemukan
        if (!found)
        {
            fprintf(file, "%s %d %s %d\n", player1.nama, player1.skor, player2.nama, player2.skor);
        }

        fclose(file);
    }
}

void tampil_highscore(const char *filename)
{
    system("cls");
    pemain current_player1, current_player2;
    FILE *file = fopen("highscore2.txt", "r"); // mode player vs player
    if (file == NULL)
    {
        printf("Gagal membuka file highscore.txt\n");
        return;
    }

    printf("\n=========================== Highscore =======================");
    printf("\n| Name Player 1       Score     |  Name player 2      Score |");
    printf("\n=============================================================\n");

    while (1)
    {
        if (fscanf(file, "%s %d", current_player1.nama, &current_player1.skor) == EOF)
            break;

        printf("|  %-20s\t%d   ", current_player1.nama, current_player1.skor);

        // Jika mode Player vs Player, baca data pemain kedua
        if (fscanf(file, "%s %d", current_player2.nama, &current_player2.skor) == EOF)
            break;

        printf("\t|  %-20s\t%d   |\n", current_player2.nama, current_player2.skor);
        printf("|-------------------------------|---------------------------|\n");
    }

    printf("=============================================================\n");
    getchar(); // Membaca karakter newline setelah Enter

    fclose(file);
}

void tampilan_menu_awal()
{
    int inputAwal;
    system("cls");
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
    printf("\n\t                 #   xxxxxxxx  oo   cccccc   xxxxxxxx    ooo       cccccc   xxxxxxxx  ooooo    xxxxxx   #");
    printf("\n\t                 #      xx     oo  cc           xx      oo oo     cc           xx    oo   oo   xx       #");
    printf("\n\t    xx   xx      #      xx     oo  cc           xx     ooooooo    cc           xx   oo     oo  xxxxxx   #      xx   xx ");
    printf("\n\t     xx xx       #      xx     oo  cc           xx    oo     oo   cc           xx    oo   oo   xx       #       xx xx  ");
    printf("\n\t      xxx        #      xx     oo   cccccc      xx   oo       oo   cccccc      xx     ooooo    xxxxxx   #        xxx   ");
    printf("\n\t     xx xx       #                                                                                      #       xx xx  ");
    printf("\n\t    xx   xx      # ==================================================================================== #      xx   xx ");
    printf("\n\t          oooo   #                     oxoxoxoxoxoxoxox MENU HOME xoxoxoxoxoxoxoxo                      #   oooo       ");
    printf("\n\t         oo  oo  # ==================================================================================== #  oo  oo      ");
    printf("\n\t         oo  oo  #                                     |1| START                                        #  oo  oo      ");
    printf("\n\t          oooo   #                                     |2| RULE OF GAME                                 #   oooo       ");
    printf("\n\t                 #                                     |3| HIGHSCORE                                    #              ");
    printf("\n\t                 #                                     |0| QUIT                                         #");
    printf("\n\t                 # ==================================================================================== #");
    printf("\n\t                                                     Masukan Angka : ");
    scanf("%d", &input_home_menu);
}

void tampilan_peraturan_bermain()
{
    system("cls");
    printf("\n\t      xx   xx                                                                                            xx   xx     ");
    printf("\n\t       xx xx                                                                                              xx xx      ");
    printf("\n\t        xxx    ########################################################################################    xxx       ");
    printf("\n\t       xx xx   #                                                                                      #   xx xx      ");
    printf("\n\t      xx   xx  #                       rrrrr   uu   uu  ll      eeeeee   sssss                        #  xx   xx     ");
    printf("\n\t   oooo        #                       rr   r  uu   uu  ll      ee      ss                            #        oooo  ");
    printf("\n\t  oo  oo       #                       rrrrr   uu   uu  ll      eeeeee  ss                            #       oo  oo ");
    printf("\n\t  oo  oo       #                       rrr     uu   uu  ll      eeeeee   sssss                        #       oo  oo ");
    printf("\n\t   oooo        #                       rr rr   uu   uu  ll      ee           ss                       #        oooo  ");
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
    printf("\n\t   oooo        #     cc       hh    hh   oo   oo    oo   oo    ss       ee                           #        oooo  ");
    printf("\n\t  oo  oo       #     cc       hhhhhhhh  oo     oo  oo     oo   ss       eeeeee                       #       oo  oo ");
    printf("\n\t  oo  oo       #     cc       hhhhhhhh  oo     oo  oo     oo    sssss   eeeeee                       #       oo  oo ");
    printf("\n\t   oooo        #     cc       hh    hh   oo   oo    oo   oo         ss  ee                           #        oooo  ");
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
    scanf("%d", &input_mode_game);
}
void tampilan_pilihan_level()
{
    system("cls");
    printf("\n\t      xx   xx                                                                                           xx   xx     ");
    printf("\n\t       xx xx                                                                                             xx xx      ");
    printf("\n\t        xxx    #######################################################################################    xxx       ");
    printf("\n\t       xx xx   #                                                                                     #   xx xx      ");
    printf("\n\t      xx   xx  #      cccccc  hh    hh    ooooo      ooooo      sssss   eeeeee                       #  xx   xx     ");
    printf("\n\t   oooo        #     cc       hh    hh   oo   oo    oo   oo    ss       ee                           #        oooo  ");
    printf("\n\t  oo  oo       #     cc       hhhhhhhh  oo     oo  oo     oo   ss       eeeeee                       #       oo  oo ");
    printf("\n\t  oo  oo       #     cc       hhhhhhhh  oo     oo  oo     oo    sssss   eeeeee                       #       oo  oo ");
    printf("\n\t   oooo        #     cc       hh    hh   oo   oo    oo   oo         ss  ee                           #        oooo  ");
    printf("\n\t               #      cccccc  hh    hh    ooooo      ooooo     ssssss   eeeeee                       #");
    printf("\n\t               #                                                                                     #");
    printf("\n\t               #                                ggggg         aaa       mm            mm  eeeeee     #");
    printf("\n\t               #                               gg            aa aa      mmm          mmm  ee         #");
    printf("\n\t               #                               gg           aa   aa     mm mm      mm mm  eeeeee     #");
    printf("\n\t               #                               gg  gggg    aaaaaaaaa    mm   mm  mm   mm  eeeeee     #");
    printf("\n\t               #                               gg    gg   aa       aa   mm     mm     mm  ee         #");
    printf("\n\t               #                                gggggg   aa         aa  mm            mm  eeeeee     #");
    printf("\n\t               #                                                                                     #");
    printf("\n\t               #     ll        eeeeee  vv        vv  eeeeee  ll                                      #");
    printf("\n\t               #     ll        ee       vv      vv   ee      ll                                      #");
    printf("\n\t               #     ll        eeeeee    vv    vv    eeeeee  ll                                      #");
    printf("\n\t               #     ll        eeeeee     vv  vv     eeeeee  ll                                      #");
    printf("\n\t               #     ll        ee          vvvv      ee      ll                                      #");
    printf("\n\t  xx   xx      #     llllllll  eeeeee       vv       eeeeee  lllllllll                               #      xx   xx ");
    printf("\n\t   xx xx       #                                                                                     #       xx xx  ");
    printf("\n\t    xxx        # =================================================================================== #        xxx   ");
    printf("\n\t   xx xx       #                     oxoxoxoxoxoxoxoxox LEVEL  xoxoxoxoxoxoxoxox                     #       xx xx  ");
    printf("\n\t  xx   xx      # =================================================================================== #      xx   xx ");
    printf("\n\t        oooo   #                                        |1| EASY                                     #   oooo       ");
    printf("\n\t       oo  oo  #                                        |2| MEDIUM                                   #  oo  oo      ");
    printf("\n\t       oo  oo  #                                        |3| HARD                                     #  oo  oo      ");
    printf("\n\t        oooo   # =================================================================================== #   oooo       ");
    printf("\n");
}

void tampilan_pilihan_papan()
{
    system("cls");
    printf("\n\t      xx   xx                                                                                            xx   xx     ");
    printf("\n\t       xx xx                                                                                              xx xx      ");
    printf("\n\t        xxx    ########################################################################################    xxx       ");
    printf("\n\t       xx xx   #                                                                                      #   xx xx      ");
    printf("\n\t      xx   xx  #                 bbbbb       ooooo         aaa       rrrrr   dddddd                   #        oooo           ");
    printf("\n\t   oooo        #                 bb   b     oo   oo       aa aa      rr   r  dd   dd                  #       oo  oo          ");
    printf("\n\t  oo  oo       #                 bbbbbb    oo     oo     aa   aa     rrrrr   dd   dd                  #       oo  oo          ");
    printf("\n\t  oo  oo       #                 bb    b   oo     oo    aaaaaaaaa    rrr     dd   dd                  #        oooo           ");
    printf("\n\t   oooo        #                 bb    b    oo   oo    aa       aa   rr rr   dd   dd                  #");
    printf("\n\t               #                 bbbbbb      ooooo    aa         aa  rr  rr  dddddd                   #");
    printf("\n\t               #                                                                                      #");
    printf("\n\t               #                              sssss   ii  zzzzzzz  eeeeee                             #");
    printf("\n\t               #                             s        ii      zz   ee                                 #");
    printf("\n\t               #                             s        ii     zz    eeeeee                             #");
    printf("\n\t               #                              sssss   ii    zz     eeeeee                             #");
    printf("\n\t               #                                   s  ii   zz      ee                                 #");
    printf("\n\t               #                              sssss   ii  zzzzzzz  eeeeee                             #");
    printf("\n\t               # ==================================================================================== #");
    printf("\n\t               #                                                                                      #");
    printf("\n\t               #       |    |            |    |    |    |            |    |    |    |    |    |       #");
    printf("\n\t               #   ____|____|____    ____|____|____|____|____    ____|____|____|____|____|____|____   #");
    printf("\n\t               #       |    |            |    |    |    |            |    |    |    |    |    |       #");
    printf("\n\t               #   ____|____|____    ____|____|____|____|____    ____|____|____|____|____|____|____   #");
    printf("\n\t               #       |    |            |    |    |    |            |    |    |    |    |    |       #");
    printf("\n\t               #       |    |        ____|____|____|____|____    ____|____|____|____|____|____|____   #");
    printf("\n\t               #                         |    |    |    |            |    |    |    |    |    |       #");
    printf("\n\t               #    |3| 3 x 3        ____|____|____|____|____    ____|____|____|____|____|____|____   #");
    printf("\n\t               #                         |    |    |    |            |    |    |    |    |    |       #");
    printf("\n\t               #                         |    |    |    |        ____|____|____|____|____|____|____   #");
    printf("\n\t               #                                                     |    |    |    |    |    |       #");
    printf("\n\t               #                           |5| 5 x 5             ____|____|____|____|____|____|____   #");
    printf("\n\t  xx   xx      #                                                     |    |    |    |    |    |       #      xx   xx  ");
    printf("\n\t   xx xx       #                                                 ____|____|____|____|____|____|____   #       xx xx   ");
    printf("\n\t    xxx        #                                                     |    |    |    |    |    |       #        xxx    ");
    printf("\n\t   xx xx       #                                                     |    |    |    |    |    |       #       xx xx   ");
    printf("\n\t  xx   xx      #                                                                                      #      xx   xx  ");
    printf("\n\t        oooo   #                                                          |7|   7 x 7                 #   oooo        ");
    printf("\n\t       oo  oo  #                                                                                      #  00  00       ");
    printf("\n\t       oo  oo  # ==================================================================================== #  00  00       ");
    printf("\n\t        oooo   #                                                                                      #   oooo        ");
}

void tampilan_masukan_nama()
{
    // system("cls");
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
    printf("\n\t        oooo   ########################################################################################   oooo       \n");
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

void tampilan_pemenang_komputer()
{
    printf("\n\t      xx   xx                                                                                            xx   xx     ");
    printf("\n\t       xx xx                                                                                              xx xx      ");
    printf("\n\t        xxx    ########################################################################################    xxx       ");
    printf("\n\t       xx xx   #                                                                                      #   xx xx      ");
    printf("\n\t      xx   xx  #    ccccc    ooooo    mm            mm  ppppp   uu   uu  tttttttt  eeeeee  rrrrr      #  xx   xx     ");
    printf("\n\t   oooo        #   cc       oo   oo   mmm          mmm  pp   p  uu   uu     tt     ee      rr   r     #        oooo  ");
    printf("\n\t  oo  oo       #   cc      oo     oo  mm mm      mm mm  pp   p  uu   uu     tt     eeeeee  rrrrr      #       oo  oo ");
    printf("\n\t  oo  oo       #   cc      oo     oo  mm   mm  mm   mm  ppppp   uu   uu     tt     eeeeee  rrr        #       oo  oo ");
    printf("\n\t   oooo        #   cc       oo   oo   mm     mm     mm  pp      uu   uu     tt     ee      rr rr      #        oooo  ");
    printf("\n\t               #    ccccc    ooooo    mm            mm  pp       uuuuu      tt     eeeeee  rr   rr    #");
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

void tampilan_pemenang_draw()
{
    printf("\n\t      xx   xx                                                                                            xx   xx     ");
    printf("\n\t       xx xx                                                                                              xx xx      ");
    printf("\n\t        xxx    ########################################################################################    xxx       ");
    printf("\n\t       xx xx   #                                                                                      #   xx xx      ");
    printf("\n\t      xx   xx  #          ddddd    rrrrr        aaa       ww          ww                              #  xx   xx     ");
    printf("\n\t   oooo        #          dd   dd  rr   r      aa aa      ww     ww   ww                              #        oooo  ");
    printf("\n\t  oo  oo       #          dd   dd  rrrrr      aa   aa     ww    wwww  ww                              #       oo  oo ");
    printf("\n\t  oo  oo       #          dd   dd  rrrr      aaaaaaaaa    ww  ww   ww ww                              #       oo  oo ");
    printf("\n\t   oooo        #          dd   dd  rr rr    aa       aa   www        www                              #        oooo  ");
    printf("\n\t               #          ddddd    rr  rr  aa         aa  ww          ww                              #");
    printf("\n\t               #                                                                                      #");
    printf("\n\t               #                            gggggg        aaa       mm         mm  eeeeee             #");
    printf("\n\t  xx   xx      #                           gg            aa aa      mmm       mmm  ee                 #      xx   xx  ");
    printf("\n\t   xx xx       #                           gg           aa   aa     mm mm   mm mm  eeeeee             #       xx xx   ");
    printf("\n\t    xxx        #                           gg  gggg    aaaaaaaaa    mm   mmm   mm  eeeeee             #         xx    ");
    printf("\n\t   xx xx       #                           gg    gg   aa       aa   mm    mm   mm  ee                 #       xx xx   ");
    printf("\n\t  xx   xx      #                            gggggg   aa         aa  mm         mm  eeeeee             #      xx   xx  ");
    printf("\n\t        oooo   #                                                                                      #   oooo        ");
    printf("\n\t       oo  oo  ########################################################################################  oo  oo       ");
    printf("\n\t       oo  oo                                                                                            oo  oo       ");
    printf("\n\t        oooo                                                                                              oooo        ");
}

void tampilan_exit()
{
    printf("\n\t      xx   xx                                                                                            xx   xx     ");
    printf("\n\t       xx xx                                                                                              xx xx      ");
    printf("\n\t        xxx    ########################################################################################    xxx       ");
    printf("\n\t       xx xx   #                                                                                      #   xx xx      ");
    printf("\n\t      xx   xx  #       tttttttt  hh    hh       aaaa       n    nn  kk   kk   n    nn   ssssss        #  xx   xx     ");
    printf("\n\t   oooo        #          tt     hh    hh      aa  aa      nn   nn  kk  kk    nn   nn  ss             #        oooo  ");
    printf("\n\t  oo  oo       #          tt     hhhhhhhh     aa    aa     nnn  nn  kkkk      nnn  nn  ss             #       oo  oo ");
    printf("\n\t  oo  oo       #          tt     hhhhhhhh    aaaaaaaaaa    nn  nnn  kkkk      nn  nnn   ssssss        #       oo  oo ");
    printf("\n\t   oooo        #          tt     hh    hh   aa        aa   nn   nn  kk  kk    nn   nn        ss       #        oooo  ");
    printf("\n\t               #          tt     hh    hh  aa          aa  nn    n  kk    kk  nn    n   ssssss        #");
    printf("\n\t               #                                                                                      #");
    printf("\n\t               #                              fffffffff   ooooo    rrrrrrr                            #");
    printf("\n\t               #                            ff          oo    oo  rr      r                           #");
    printf("\n\t               #                            ff          oo    oo  rr      r                           #");
    printf("\n\t               #                            ffffffff    oo    oo  rrrrrrrr                            #");
    printf("\n\t               #                            ff          oo    oo  rr    rr                            #");
    printf("\n\t               #                            ff          00    00  rr     rr                           #");
    printf("\n\t               #                            ff           ooooo    rr      rr                          #");
    printf("\n\t               #                                                                                      #");
    printf("\n\t               #         ppppppp   ll             aaaa       yy     yy  ii  n    nn   gggggggg        #");
    printf("\n\t  xx   xx      #         pp     p  ll            aa  aa       yy   yy   ii  nn   nn  gg               #      xx   xx  ");
    printf("\n\t   xx xx       #         ppppppp   ll           aa    aa       yy yy    ii  nnn  nn  gg               #       xx xx   ");
    printf("\n\t    xxx        #         pp        ll          aaaaaaaaaa       yyy     ii  nn  nnn  gg   gggg        #         xx    ");
    printf("\n\t   xx xx       #         pp        ll         aa        aa      y y     ii  nn   nn  gg     gg        #       xx xx   ");
    printf("\n\t  xx   xx      #         pp        llllllll  aa          aa     y y     ii  nn    n   gggggggg        #      xx   xx  ");
    printf("\n\t        oooo   #                                                                                      #   oooo        ");
    printf("\n\t       oo  oo  ########################################################################################  oo  oo       ");
    printf("\n\t       oo  oo                                                                                            oo  oo       ");
    printf("\n\t        oooo                                                                                              oooo        ");
}