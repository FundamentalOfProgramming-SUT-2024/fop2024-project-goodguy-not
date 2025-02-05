#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <ncurses.h>
#include <locale.h>
#include <wchar.h>
int wepean_pish = 1;
int load_game = 0;
int hidden_count = 0;
int asar_telesm_speed = 0;
int asar_telesm_damage = 0;
int asar_telesm_health = 0;
char karbar[100];
FILE *folder;
int map_gold[6][55][55];
char map[6][55][55];
int map_seen[6][55][55];
int gold = 0;
int hp = 100;
int shadabi = 100;
char inv_food[7][100];
char inv_telesm[12][20];
char inv_weapen[7][20];
int enemy_count = 0;
int dagger = 0;
int magik_wand = 0;
int normal_arrow = 0;
int sword = 0;
int mance = 1;
int foods_count = 0;
int steps = 0;
int telesm_count = 0;
void creat_map(int tabaghe);
int reg_pass(char b[100]);
int reg_email(char c[200]);
void harekat(int row, int col, int tabaghe, char ghabli);
int nahye_shenas(int row, int col);
void sign_up();
void sign_in();
void inter_as_guest();
void start_menu();
int find_line(char a[50], FILE *fptr);
struct enemy
{
    int row;
    int col;
    int tabaghe;
    char type;
    int health;
    int ability_to_walk;
    char ghabli;
    int chase_count;
};
struct enemy doshman[60];
void menu_start()
{
    clear();
    refresh();
    printw("1.new game\n2.load game\n");
    char chert = getch();
    while (chert != '1' && chert != '2')
    {
        chert = getch();
    }
    if (chert == '1')
    {
        creat_map(1);
        creat_map(2);
        creat_map(3);
        creat_map(0);
    }
    if (chert == '2')
    {
        char save[100];
        FILE *fptr4;
        strcpy(save, karbar);
        strncat(save, "save.txt", sizeof(save) - 11 - 1);
        fptr4 = fopen(save, "r");
        if (fgetc(fptr4) == '1')
        {
            wepean_pish = 0;
            hidden_count = 0;
            asar_telesm_speed = 0;
            asar_telesm_damage = 0;
            asar_telesm_health = 0;
            gold = 0;
            hp = 0;
            shadabi = 0;
            enemy_count = 0;
            dagger = 0;
            magik_wand = 0;
            normal_arrow = 0;
            sword = 0;
            foods_count = 0;
            steps = 0;
            telesm_count = 0;
            for (int k = 0; k < 4; k++)
            {
                for (int i = 0; i < 49; i++)
                {
                    for (int j = 0; j < 49; j++)
                    {
                        map_seen[k][i][j] = 0;
                        map_gold[k][i][j] = 0;
                    }
                }
            }
            for (int i = 0; i < 49; i++)
            {
                for (int j = 0; j < 49; j++)
                {
                    map_seen[4][i][j] = 2;
                }
            }
            strcpy(save, karbar);
            strncat(save, "map.txt", sizeof(save) - 7 - 1);
            fptr4 = fopen(save, "r");
            for (int k = 0; k < 6; k++)
            {
                for (int i = 0; i < 49; i++)
                {
                    for (int j = 0; j < 49; j++)
                    {
                        map[k][i][j] = fgetc(fptr4);
                    }
                }
            }
            gold = 0;
            strcpy(save, karbar);
            strncat(save, "g.txt", sizeof(save) - 5 - 1);
            fptr4 = fopen(save, "r");
            char ch;
            int x = 0;
            int gold1[10];
            while ((ch = fgetc(fptr4)) != EOF)
            {
                if (ch == '0')
                {
                    gold1[x] = 0;
                }
                if (ch == '1')
                {
                    gold1[x] = 1;
                }
                if (ch == '2')
                {
                    gold1[x] = 2;
                }
                if (ch == '3')
                {
                    gold1[x] = 3;
                }
                if (ch == '4')
                {
                    gold1[x] = 4;
                }
                if (ch == '5')
                {
                    gold1[x] = 5;
                }
                if (ch == '6')
                {
                    gold1[x] = 6;
                }
                if (ch == '7')
                {
                    gold1[x] = 7;
                }
                if (ch == '8')
                {
                    gold1[x] = 8;
                }
                if (ch == '9')
                {
                    gold1[x] = 9;
                }
                x += 1;
            }
            for (int i = x - 1; i > -1; i--)
            {
                gold *= 10;
                gold += gold1[i];
            }
            strcpy(save, karbar);
            strncat(save, "mapseen.txt", sizeof(save) - 11 - 1);
            fptr4 = fopen(save, "r");
            for (int k = 0; k < 6; k++)
            {
                for (int i = 0; i < 49; i++)
                {
                    for (int j = 0; j < 49; j++)
                    {
                        char ch = fgetc(fptr4);
                        if (ch == '0')
                        {
                            map_seen[k][i][j] = 0;
                        }
                        if (ch == '1')
                        {
                            map_seen[k][i][j] = 1;
                        }
                        if (ch == '2')
                        {
                            map_seen[k][i][j] = 2;
                        }
                        if (ch == '3')
                        {
                            map_seen[k][i][j] = 3;
                        }
                    }
                }
            }
            strcpy(save, karbar);
            strncat(save, "arrow.txt", sizeof(save) - 9 - 1);
            fptr4 = fopen(save, "r");
            x = 0;
            while ((ch = fgetc(fptr4)) != EOF)
            {
                if (ch == '0')
                {
                    gold1[x] = 0;
                }
                if (ch == '1')
                {
                    gold1[x] = 1;
                }
                if (ch == '2')
                {
                    gold1[x] = 2;
                }
                if (ch == '3')
                {
                    gold1[x] = 3;
                }
                if (ch == '4')
                {
                    gold1[x] = 4;
                }
                if (ch == '5')
                {
                    gold1[x] = 5;
                }
                if (ch == '6')
                {
                    gold1[x] = 6;
                }
                if (ch == '7')
                {
                    gold1[x] = 7;
                }
                if (ch == '8')
                {
                    gold1[x] = 8;
                }
                if (ch == '9')
                {
                    gold1[x] = 9;
                }
                x += 1;
            }
            for (int i = x - 1; i > -1; i--)
            {
                normal_arrow *= 10;
                normal_arrow += gold1[i];
            }
            strcpy(save, karbar);
            strncat(save, "dagger.txt", sizeof(save) - 10 - 1);
            fptr4 = fopen(save, "r");
            x = 0;
            while ((ch = fgetc(fptr4)) != EOF)
            {
                if (ch == '0')
                {
                    gold1[x] = 0;
                }
                if (ch == '1')
                {
                    gold1[x] = 1;
                }
                if (ch == '2')
                {
                    gold1[x] = 2;
                }
                if (ch == '3')
                {
                    gold1[x] = 3;
                }
                if (ch == '4')
                {
                    gold1[x] = 4;
                }
                if (ch == '5')
                {
                    gold1[x] = 5;
                }
                if (ch == '6')
                {
                    gold1[x] = 6;
                }
                if (ch == '7')
                {
                    gold1[x] = 7;
                }
                if (ch == '8')
                {
                    gold1[x] = 8;
                }
                if (ch == '9')
                {
                    gold1[x] = 9;
                }
                x += 1;
            }
            for (int i = x - 1; i > -1; i--)
            {
                dagger *= 10;
                dagger += gold1[i];
            }
            strcpy(save, karbar);
            strncat(save, "sword.txt", sizeof(save) - 9 - 1);
            fptr4 = fopen(save, "r");
            x = 0;
            while ((ch = fgetc(fptr4)) != EOF)
            {
                if (ch == '0')
                {
                    gold1[x] = 0;
                }
                if (ch == '1')
                {
                    gold1[x] = 1;
                }
                if (ch == '2')
                {
                    gold1[x] = 2;
                }
                if (ch == '3')
                {
                    gold1[x] = 3;
                }
                if (ch == '4')
                {
                    gold1[x] = 4;
                }
                if (ch == '5')
                {
                    gold1[x] = 5;
                }
                if (ch == '6')
                {
                    gold1[x] = 6;
                }
                if (ch == '7')
                {
                    gold1[x] = 7;
                }
                if (ch == '8')
                {
                    gold1[x] = 8;
                }
                if (ch == '9')
                {
                    gold1[x] = 9;
                }
                x += 1;
            }
            for (int i = x - 1; i > -1; i--)
            {
                sword *= 10;
                sword += gold1[i];
            }
            strcpy(save, karbar);
            strncat(save, "wand.txt", sizeof(save) - 8 - 1);
            fptr4 = fopen(save, "r");
            x = 0;
            while ((ch = fgetc(fptr4)) != EOF)
            {
                if (ch == '0')
                {
                    gold1[x] = 0;
                }
                if (ch == '1')
                {
                    gold1[x] = 1;
                }
                if (ch == '2')
                {
                    gold1[x] = 2;
                }
                if (ch == '3')
                {
                    gold1[x] = 3;
                }
                if (ch == '4')
                {
                    gold1[x] = 4;
                }
                if (ch == '5')
                {
                    gold1[x] = 5;
                }
                if (ch == '6')
                {
                    gold1[x] = 6;
                }
                if (ch == '7')
                {
                    gold1[x] = 7;
                }
                if (ch == '8')
                {
                    gold1[x] = 8;
                }
                if (ch == '9')
                {
                    gold1[x] = 9;
                }
                x += 1;
            }
            for (int i = x - 1; i > -1; i--)
            {
                magik_wand *= 10;
                magik_wand += gold1[i];
            }
            strcpy(save, karbar);
            strncat(save, "telesmcount.txt", sizeof(save) - 15 - 1);
            fptr4 = fopen(save, "r");
            x = 0;
            while ((ch = fgetc(fptr4)) != EOF)
            {
                if (ch == '0')
                {
                    gold1[x] = 0;
                }
                if (ch == '1')
                {
                    gold1[x] = 1;
                }
                if (ch == '2')
                {
                    gold1[x] = 2;
                }
                if (ch == '3')
                {
                    gold1[x] = 3;
                }
                if (ch == '4')
                {
                    gold1[x] = 4;
                }
                if (ch == '5')
                {
                    gold1[x] = 5;
                }
                if (ch == '6')
                {
                    gold1[x] = 6;
                }
                if (ch == '7')
                {
                    gold1[x] = 7;
                }
                if (ch == '8')
                {
                    gold1[x] = 8;
                }
                if (ch == '9')
                {
                    gold1[x] = 9;
                }
                x += 1;
            }
            for (int i = x - 1; i > -1; i--)
            {
                telesm_count *= 10;
                telesm_count += gold1[i];
            }
            strcpy(save, karbar);
            strncat(save, "shadabi.txt", sizeof(save) - 11 - 1);
            fptr4 = fopen(save, "r");
            x = 0;
            while ((ch = fgetc(fptr4)) != EOF)
            {
                if (ch == '0')
                {
                    gold1[x] = 0;
                }
                if (ch == '1')
                {
                    gold1[x] = 1;
                }
                if (ch == '2')
                {
                    gold1[x] = 2;
                }
                if (ch == '3')
                {
                    gold1[x] = 3;
                }
                if (ch == '4')
                {
                    gold1[x] = 4;
                }
                if (ch == '5')
                {
                    gold1[x] = 5;
                }
                if (ch == '6')
                {
                    gold1[x] = 6;
                }
                if (ch == '7')
                {
                    gold1[x] = 7;
                }
                if (ch == '8')
                {
                    gold1[x] = 8;
                }
                if (ch == '9')
                {
                    gold1[x] = 9;
                }
                x += 1;
            }
            for (int i = x - 1; i > -1; i--)
            {
                shadabi *= 10;
                shadabi += gold1[i];
            }
            strcpy(save, karbar);
            strncat(save, "hp.txt", sizeof(save) - 6 - 1);
            fptr4 = fopen(save, "r");
            x = 0;
            while ((ch = fgetc(fptr4)) != EOF)
            {
                if (ch == '0')
                {
                    gold1[x] = 0;
                }
                if (ch == '1')
                {
                    gold1[x] = 1;
                }
                if (ch == '2')
                {
                    gold1[x] = 2;
                }
                if (ch == '3')
                {
                    gold1[x] = 3;
                }
                if (ch == '4')
                {
                    gold1[x] = 4;
                }
                if (ch == '5')
                {
                    gold1[x] = 5;
                }
                if (ch == '6')
                {
                    gold1[x] = 6;
                }
                if (ch == '7')
                {
                    gold1[x] = 7;
                }
                if (ch == '8')
                {
                    gold1[x] = 8;
                }
                if (ch == '9')
                {
                    gold1[x] = 9;
                }
                x += 1;
            }
            for (int i = x - 1; i > -1; i--)
            {
                hp *= 10;
                hp += gold1[i];
            }
            strcpy(save, karbar);
            strncat(save, "hidden.txt", sizeof(save) - 10 - 1);
            fptr4 = fopen(save, "r");
            x = 0;
            while ((ch = fgetc(fptr4)) != EOF)
            {
                if (ch == '0')
                {
                    gold1[x] = 0;
                }
                if (ch == '1')
                {
                    gold1[x] = 1;
                }
                if (ch == '2')
                {
                    gold1[x] = 2;
                }
                if (ch == '3')
                {
                    gold1[x] = 3;
                }
                if (ch == '4')
                {
                    gold1[x] = 4;
                }
                if (ch == '5')
                {
                    gold1[x] = 5;
                }
                if (ch == '6')
                {
                    gold1[x] = 6;
                }
                if (ch == '7')
                {
                    gold1[x] = 7;
                }
                if (ch == '8')
                {
                    gold1[x] = 8;
                }
                if (ch == '9')
                {
                    gold1[x] = 9;
                }
                x += 1;
            }
            for (int i = x - 1; i > -1; i--)
            {
                hidden_count *= 10;
                hidden_count += gold1[i];
            }
            strcpy(save, karbar);
            strncat(save, "Foodcount.txt", sizeof(save) - 13 - 1);
            fptr4 = fopen(save, "r");
            x = 0;
            while ((ch = fgetc(fptr4)) != EOF)
            {
                if (ch == '0')
                {
                    gold1[x] = 0;
                }
                if (ch == '1')
                {
                    gold1[x] = 1;
                }
                if (ch == '2')
                {
                    gold1[x] = 2;
                }
                if (ch == '3')
                {
                    gold1[x] = 3;
                }
                if (ch == '4')
                {
                    gold1[x] = 4;
                }
                if (ch == '5')
                {
                    gold1[x] = 5;
                }
                if (ch == '6')
                {
                    gold1[x] = 6;
                }
                if (ch == '7')
                {
                    gold1[x] = 7;
                }
                if (ch == '8')
                {
                    gold1[x] = 8;
                }
                if (ch == '9')
                {
                    gold1[x] = 9;
                }
                x += 1;
            }
            for (int i = x - 1; i > -1; i--)
            {
                foods_count *= 10;
                foods_count += gold1[i];
            }
            for (int k = 0; k < 6; k++)
            {
                for (int i = 0; i < 49; i++)
                {
                    for (int j = 0; j < 49; j++)
                    {
                        if (map[k][i][j] == 'd' || map[k][i][j] == 'u' || map[k][i][j] == 'S' || map[k][i][j] == 'I' || map[k][i][j] == 'f')
                        {
                            doshman[enemy_count].tabaghe = k;
                            doshman[enemy_count].row = i;
                            doshman[enemy_count].col = j;
                            doshman[enemy_count].type = map[k][i][j];
                            doshman[enemy_count].ability_to_walk = 1;
                            doshman[enemy_count].ghabli = '.';
                            if (map[k][i][j] == 'd')
                            {
                                doshman[enemy_count].health = 5;
                            }
                            if (map[k][i][j] == 'u')
                            {
                                doshman[enemy_count].health = 60;
                            }
                            if (map[k][i][j] == 'S')
                            {
                                doshman[enemy_count].health = 20;
                            }
                            if (map[k][i][j] == 'f')
                            {
                                doshman[enemy_count].health = 10;
                            }
                            if (map[k][i][j] == 'I')
                            {
                                doshman[enemy_count].health = 15;
                            }
                            enemy_count += 1;
                        }
                        if (map[k][i][j] == 'G')
                        {
                            map_gold[k][i][j] = (rand() % 50) + 1;
                        }
                        if (map[k][i][j] == 'g')
                        {
                            map_gold[k][i][j] = (rand() % 100) + 150;
                        }
                    }
                }
            }
            for (int i = 0; i < foods_count; i++)
            {
                int no_ghaza = rand() % 4;
                if (no_ghaza == 0)
                {
                    strcpy(inv_food[i], "kobide makhsos ba noon va pyaz va dogh mahsham");
                }
                if (no_ghaza == 1)
                {
                    strcpy(inv_food[i], "bomb mehran");
                }
                if (no_ghaza == 2)
                {
                    strcpy(inv_food[i], "gheime nazry");
                }
                if (no_ghaza == 3)
                {
                    strcpy(inv_food[i], "nimro");
                }
            }
            strcpy(save, karbar);
            strncat(save, "telesm.txt", sizeof(save) - 10 - 1);
            fptr4 = fopen(save, "r");
            for (int i = 0; i < telesm_count; i++)
            {
                fgets(inv_telesm[i], 20, fptr4);
                inv_telesm[i][strcspn(inv_telesm[i], "\n")] = '\0';
            }
            for (int k = 0; k < 6; k++)
            {
                for (int i = 0; i < 49; i++)
                {
                    for (int j = 0; j < 49; j++)
                    {
                        if (map[k][i][j] == 'N')
                        {
                            load_game = 1;
                            harekat(i, j, k, '.');
                        }
                    }
                }
            }
        }
        else
        {
            printw("you dont have any save!.(press space)\n");
            char chert = getch();
            while (chert != ' ')
            {
                chert = getch();
            }
            menu_start();
        }
        /*char save[100];
            strcpy(save, a);
            strncat(save, "g.txt", sizeof(save) - 5 - 1);
            FILE *fptr4 = fopen(save, "w");
            strcpy(save, a);
            strncat(save, "map.txt", sizeof(save) - 7 - 1);
            fptr4 = fopen(save, "w");
            strcpy(save, a);
            strncat(save, "telesm.txt", sizeof(save) - 9 - 1);
            fptr4 = fopen(save, "w");
            strcpy(save, a);
            strncat(save, "dagger.txt", sizeof(save) - 10 - 1);
            fptr4 = fopen(save, "w");
            strcpy(save, a);
            strncat(save, "sword.txt", sizeof(save) - 9 - 1);
            fptr4 = fopen(save, "w");
            strcpy(save, a);
            strncat(save, "arrow.txt", sizeof(save) - 9 - 1);
            fptr4 = fopen(save, "w");
            strcpy(save, a);
            strncat(save, "wand.txt", sizeof(save) - 8 - 1);
            fptr4 = fopen(save, "w");
            strcpy(save, a);
            strncat(save, "hidden.txt", sizeof(save) - 10 - 1);
            fptr4 = fopen(save, "w");
            strcpy(save, a);
            strncat(save, "mapgold.txt", sizeof(save) - 11 - 1);
            fptr4 = fopen(save, "w");
            strcpy(save, a);
            strncat(save, "mapseen.txt", sizeof(save) - 11 - 1);
            fptr4 = fopen(save, "w");
            strcpy(save, a);
            strncat(save, "hp.txt", sizeof(save) - 6 - 1);
            fptr4 = fopen(save, "w");
            strcpy(save, a);
            strncat(save, "shadabi.txt", sizeof(save) - 11 - 1);
            fptr4 = fopen(save, "w");
            strcpy(save, a);
            strncat(save, "Foodcount.txt", sizeof(save) - 13 - 1);
            fptr4 = fopen(save, "w");
            strcpy(save, a);
            strncat(save, "telesmcount.txt", sizeof(save) - 15 - 1);
            fptr4 = fopen(save, "w");
            strcpy(save, a);
            strncat(save, "save.txt", sizeof(save) - 11 - 1);
            fptr4 = fopen(save, "w");*/
    }
}
void creat_floor_six()
{
    for (int i = 4; i < 41; i++)
    {
        map[5][i][4] = '|';
        map[5][i][40] = '|';
        map[5][4][i] = '_';
        map[5][40][i] = '_';
    }
    map[5][4][4] = '$';
    map[5][40][4] = '$';
    map[5][40][40] = '$';
    map[5][4][40] = '$';
    for (int i = 5; i < 40; i++)
    {
        for (int j = 5; j < 40; j++)
        {
            map[5][i][j] = '.';
        }
    }
    for (int i = 0; i < 8; i++)
    {
        int colmn = (rand() % (39 - 5 - 3)) + 5 + 2;
        int row = (rand() % (39 - 5 - 3)) + 5 + 2;
        while (map[5][row][colmn] != '.')
        {
            colmn = (rand() % (39 - 5 - 3)) + 5 + 2;
            row = (rand() % (39 - 5 - 3)) + 5 + 2;
        }
        map[5][row][colmn] = 'T';
    }
    int colmn = (rand() % (39 - 5 - 3)) + 5 + 2;
    int row = (rand() % (39 - 5 - 3)) + 5 + 2;
    while (map[5][row][colmn] != '.')
    {
        colmn = (rand() % (39 - 5 - 3)) + 5 + 2;
        row = (rand() % (39 - 5 - 3)) + 5 + 2;
    }
    for (int i = 0; i < 49; i++)
    {
        for (int j = 0; j < 49; j++)
        {
            map_seen[5][i][j] = 2;
        }
    }
    map[5][row][colmn] = 'D';
}
void creat_hidden_door()
{
    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < 49; i++)
        {
            for (int j = 0; j < 49; j++)
            {
                if (map[k][i][j] == '+' && map[k][i + 1][j] != '#' && map[k][i - 1][j] != '#' && map[k][i][j + 1] != '#' && map[k][i][j - 1] != '#')
                {
                    map[k][i][j] = '!';
                    hidden_count += 1;
                }
            }
        }
    }
    for (int k = 1; k < 4; k++)
    {
        for (int i = 1; i < 40; i++)
        {
            for (int j = 1; j < 40; j++)
            {
                if (map[k][i][j] == '_')
                {
                    map[k][i][j] = '!';
                    hidden_count += 1;
                    i = 50;
                    j = 50;
                }
            }
        }
    }
}
void save_end()
{
    if (load_game == 1)
    {
        char save[100];
        strcpy(save, karbar);
        strncat(save, "save.txt", sizeof(save) - 8 - 1);
        FILE *fptr4 = fopen(save, "w");
    }
    if (load_game == 2)
    {
        start_menu();
    }
    menu_start();
}
int check_victory()
{
    for (int i = 0; i < 49; i++)
    {
        for (int j = 0; j < 49; j++)
        {
            if (map[4][i][j] == 'd' || map[4][i][j] == 'u' || map[4][i][j] == 'S' || map[4][i][j] == 'I' || map[4][i][j] == 'f')
            {
                return 0;
            }
        }
    }
    return 1;
}
void otagh_boss_saz()
{
    for (int i = 0; i < 49; i++)
    {
        for (int j = 0; j < 49; j++)
        {
            map[4][i][j] = ' ';
        }
    }
    int x1 = (rand() % 4) + 4;
    int x2 = 43 - (rand() % 5);
    int y2 = 43 - (rand() % 5);
    int y1 = (rand() % 4) + 4;
    map[4][x1][y1] = '$';
    map[4][x1][y2] = '$';
    map[4][x2][y1] = '$';
    map[4][x2][y2] = '$';
    for (int j = (x1 + 1); j < x2; j++)
    {
        map[4][j][y1] = '|';
        map[4][j][y2] = '|';
    }
    for (int j = (y1 + 1); j < y2; j++)
    {
        map[4][x1][j] = '_';
        map[4][x2][j] = '_';
    }
    for (int j = (x1 + 1); j < x2; j++)
    {
        for (int k = (y1 + 1); k < y2; k++)
        {
            map[4][j][k] = '.';
        }
    }
    for (int i = 0; i < 10; i++)
    {
        int colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
        int row = (rand() % (x2 - x1 - 3)) + x1 + 2;
        while (map[4][row][colmn] != '.')
        {
            colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
            row = (rand() % (x2 - x1 - 3)) + x1 + 2;
        }
        int shans_Trap = (rand() % 3);
        if (shans_Trap == 0)
        {
            map[4][row][colmn] = 'R';
        }
        else
        {
            map[4][row][colmn] = 'r';
        }
    }
    for (int i = 0; i < 5; i++)
    {
        int colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
        int row = (rand() % (x2 - x1 - 3)) + x1 + 2;
        while (map[4][row][colmn] != '.')
        {
            colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
            row = (rand() % (x2 - x1 - 3)) + x1 + 2;
        }
        map[4][row][colmn] = 'F';
    }
    for (int i = 0; i < 3; i++)
    {
        int colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
        int row = (rand() % (x2 - x1 - 3)) + x1 + 2;
        while (map[4][row][colmn] != '.')
        {
            colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
            row = (rand() % (x2 - x1 - 3)) + x1 + 2;
        }
        map[4][row][colmn] = 'T';
    }
    for (int i = 0; i < 10; i++)
    {
        int colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
        int row = (rand() % (x2 - x1 - 3)) + x1 + 2;
        while (map[4][row][colmn] != '.')
        {
            colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
            row = (rand() % (x2 - x1 - 3)) + x1 + 2;
        }
        int no_enemy = (rand() % 10);
        if (no_enemy == 0)
        {
            map[4][row][colmn] = 'S';
            doshman[enemy_count].row = row;
            doshman[enemy_count].col = colmn;
            doshman[enemy_count].tabaghe = 4;
            doshman[enemy_count].type = 'S';
            doshman[enemy_count].health = 20;
            doshman[enemy_count].ability_to_walk = 1;
            doshman[enemy_count].ghabli = '.';
            doshman[enemy_count].chase_count = 0;
        }
        if (no_enemy == 1 || no_enemy == 2)
        {
            map[4][row][colmn] = 'I';
            doshman[enemy_count].row = row;
            doshman[enemy_count].col = colmn;
            doshman[enemy_count].tabaghe = 4;
            doshman[enemy_count].type = 'I';
            doshman[enemy_count].health = 15;
            doshman[enemy_count].ability_to_walk = 1;
            doshman[enemy_count].ghabli = '.';
            doshman[enemy_count].chase_count = 0;
        }
        if (no_enemy == 3 || no_enemy == 4 || no_enemy == 5)
        {
            map[4][row][colmn] = 'f';
            doshman[enemy_count].row = row;
            doshman[enemy_count].col = colmn;
            doshman[enemy_count].tabaghe = 4;
            doshman[enemy_count].type = 'f';
            doshman[enemy_count].health = 10;
            doshman[enemy_count].ability_to_walk = 1;
            doshman[enemy_count].ghabli = '.';
            doshman[enemy_count].chase_count = 0;
        }
        if (no_enemy == 6 || no_enemy == 7 || no_enemy == 8 || no_enemy == 9)
        {
            map[4][row][colmn] = 'd';
            doshman[enemy_count].row = row;
            doshman[enemy_count].col = colmn;
            doshman[enemy_count].tabaghe = 4;
            doshman[enemy_count].type = 'd';
            doshman[enemy_count].health = 5;
            doshman[enemy_count].ability_to_walk = 1;
            doshman[enemy_count].ghabli = '.';
            doshman[enemy_count].chase_count = 0;
        }
        enemy_count += 1;
    }
    for (int i = 0; i < 2; i++)
    {
        int colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
        int row = (rand() % (x2 - x1 - 3)) + x1 + 2;
        while (map[4][row][colmn] != '.')
        {
            colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
            row = (rand() % (x2 - x1 - 3)) + x1 + 2;
        }
        map[4][row][colmn] = 'u';
        doshman[enemy_count].row = row;
        doshman[enemy_count].col = colmn;
        doshman[enemy_count].tabaghe = 4;
        doshman[enemy_count].type = 'u';
        doshman[enemy_count].health = 60;
        doshman[enemy_count].ability_to_walk = 1;
        doshman[enemy_count].ghabli = '.';
        doshman[enemy_count].chase_count = 0;
        enemy_count += 1;
    }
}
void start_boss()
{
    for (int i = 0; i < 49; i++)
    {
        for (int j = 0; j < 49; j++)
        {
            if (map[4][i][j] == '.')
            {
                map[4][i][j] = 'N';
                harekat(i, j, 4, '.');
            }
        }
    }
}
int dakhel_otagh(int row, int col, int tabaghe)
{
    int sum = 0;
    if (map[tabaghe][row][col + 1] != '#' && map[tabaghe][row][col + 1] != ' ' && map[tabaghe][row][col + 1] != '@' && map[tabaghe][row][col + 1] != '$' && map[tabaghe][row][col + 1] != '|' && map[tabaghe][row][col + 1] != '_' && map[tabaghe][row][col + 1] != '#' && map[tabaghe][row][col + 1] != '~')
    {
        sum += 1;
    }
    if (map[tabaghe][row][col - 1] != '#' && map[tabaghe][row][col - 1] != ' ' && map[tabaghe][row][col - 1] != '@' && map[tabaghe][row][col - 1] != '$' && map[tabaghe][row][col - 1] != '|' && map[tabaghe][row][col - 1] != '_' && map[tabaghe][row][col - 1] != '#' && map[tabaghe][row][col - 1] != '~')
    {
        sum += 1;
    }
    if (map[tabaghe][row - 1][col] != '#' && map[tabaghe][row - 1][col] != ' ' && map[tabaghe][row - 1][col] != '@' && map[tabaghe][row - 1][col] != '$' && map[tabaghe][row - 1][col] != '|' && map[tabaghe][row - 1][col] != '_' && map[tabaghe][row - 1][col + 1] != '#' && map[tabaghe][row - 1][col] != '~')
    {
        sum += 1;
    }
    if (map[tabaghe][row + 1][col] != '#' && map[tabaghe][row + 1][col] != ' ' && map[tabaghe][row + 1][col] != '@' && map[tabaghe][row + 1][col] != '$' && map[tabaghe][row + 1][col] != '|' && map[tabaghe][row + 1][col] != '_' && map[tabaghe][row + 1][col] != '#' && map[tabaghe][row + 1][col] != '~')
    {
        sum += 1;
    }
    if (sum > 1)
    {
        return 1;
    }
    if (tabaghe == 4)
    {
        return 1;
    }
    return 0;
}
void check_monster_health()
{
    for (int i = 0; i < enemy_count; i++)
    {
        if (doshman[i].health < 1)
        {
            doshman[i].ability_to_walk = 0;
            map[doshman[i].tabaghe][doshman[i].row][doshman[i].col] = '.';
            doshman[i].row = 1;
            doshman[i].col = 1;
        }
    }
}
void check_harekat(int row, int col, int tabaghe, int row1, int col1, int i, char no_enemy)
{
    if (doshman[i].health < 1)
    {
        return;
    }
    if (no_enemy == 'I' || no_enemy == 'f')
    {
        if (doshman[i].chase_count < 5)
        {
            if (row == row1)
            {
                if (col1 > col)
                {
                    if (map[tabaghe][row1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                        map[tabaghe][row1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                        map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                        map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                        map[tabaghe][row1 + 1][col1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                        map[tabaghe][row1 - 1][col1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                }
                else if (col1 < col)
                {
                    if (map[tabaghe][row1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                        map[tabaghe][row1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                        map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                        map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                        map[tabaghe][row1 + 1][col1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                        map[tabaghe][row1 - 1][col1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                }
            }
            else if (row > row1)
            {
                if (col1 > col)
                {
                    if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                        map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                        map[tabaghe][row1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                        map[tabaghe][row1 + 1][col1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                        map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                        map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                }
                else if (col1 < col)
                {
                    if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                        map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                        map[tabaghe][row1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                        map[tabaghe][row1 + 1][col1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                        map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                        map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                }
                else if (col1 == col)
                {
                    if (map[tabaghe][row1 + 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                        map[tabaghe][row1 + 1][col1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                        map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                        map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                        map[tabaghe][row1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                        map[tabaghe][row1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                }
            }
            else if (row1 > row)
            {
                if (col1 > col)
                {
                    if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                        map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                        map[tabaghe][row1 - 1][col1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                        map[tabaghe][row1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                        map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                        map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                }
                else if (col1 < col)
                {
                    if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                        map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                        map[tabaghe][row1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                        map[tabaghe][row1 - 1][col1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                        map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                        map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                }
                else if (col1 == col)
                {
                    if (map[tabaghe][row1 - 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                        map[tabaghe][row1 - 1][col1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                        map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                        map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                        map[tabaghe][row1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                        map[tabaghe][row1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                }
            }
        }
        else if (doshman[i].chase_count == 5)
        {
            doshman[i].chase_count = 6;
        }
        else if ((row - row1 == 1 && (col - col1 == 0 || (col - col1) == 1 || (col1 - col) == 1)) || (row - row1 == -1 && (col - col1 == 0 || (col - col1) == 1 || (col1 - col) == 1)) || (row1 - row == 0 && ((col - col1) == 1 || (col1 - col) == 1)))
        {
            doshman[i].chase_count = 0;
        }
    }
    else if (no_enemy == 'S' || no_enemy == 'u')
    {
        if (row == row1)
        {
            if (col1 > col)
            {
                if (map[tabaghe][row1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                    map[tabaghe][row1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                    map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                    map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 + 1][col1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                    map[tabaghe][row1 + 1][col1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 - 1][col1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                    map[tabaghe][row1 - 1][col1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1;
                    doshman[i].chase_count += 1;
                }
            }
            else if (col1 < col)
            {
                if (map[tabaghe][row1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                    map[tabaghe][row1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                    map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                    map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 + 1][col1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                    map[tabaghe][row1 + 1][col1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 - 1][col1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                    map[tabaghe][row1 - 1][col1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1;
                    doshman[i].chase_count += 1;
                }
            }
        }
        else if (row > row1)
        {
            if (col1 > col)
            {
                if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                    map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                    map[tabaghe][row1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 + 1][col1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                    map[tabaghe][row1 + 1][col1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                    map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                    map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
            }
            else if (col1 < col)
            {
                if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                    map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                    map[tabaghe][row1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 + 1][col1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                    map[tabaghe][row1 + 1][col1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                    map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                    map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
            }
            else if (col1 == col)
            {
                if (map[tabaghe][row1 + 1][col1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                    map[tabaghe][row1 + 1][col1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                    map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                    map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                    map[tabaghe][row1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                    map[tabaghe][row1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
            }
        }
        else if (row1 > row)
        {
            if (col1 > col)
            {
                if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                    map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 - 1][col1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                    map[tabaghe][row1 - 1][col1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                    map[tabaghe][row1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                    map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                    map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
            }
            else if (col1 < col)
            {
                if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                    map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                    map[tabaghe][row1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 - 1][col1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                    map[tabaghe][row1 - 1][col1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                    map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                    map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
            }
            else if (col1 == col)
            {
                if (map[tabaghe][row1 - 1][col1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                    map[tabaghe][row1 - 1][col1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                    map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                    map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                    map[tabaghe][row1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else if (map[tabaghe][row1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                    map[tabaghe][row1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
            }
        }
    }
    else if (no_enemy == 'd')
    {
        if (doshman[i].chase_count < 5)
        {
            if (row == row1)
            {
                if (col1 > col)
                {
                    if (map[tabaghe][row1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                        map[tabaghe][row1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                        map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                        map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                        map[tabaghe][row1 + 1][col1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                        map[tabaghe][row1 - 1][col1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                }
                else if (col1 < col)
                {
                    if (map[tabaghe][row1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                        map[tabaghe][row1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                        map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                        map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                        map[tabaghe][row1 + 1][col1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                        map[tabaghe][row1 - 1][col1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                }
            }
            else if (row > row1)
            {
                if (col1 > col)
                {
                    if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                        map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                        map[tabaghe][row1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                        map[tabaghe][row1 + 1][col1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                        map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                        map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                }
                else if (col1 < col)
                {
                    if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                        map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                        map[tabaghe][row1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                        map[tabaghe][row1 + 1][col1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                        map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                        map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                }
                else if (col1 == col)
                {
                    if (map[tabaghe][row1 + 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                        map[tabaghe][row1 + 1][col1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                        map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                        map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                        map[tabaghe][row1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                        map[tabaghe][row1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                }
            }
            else if (row1 > row)
            {
                if (col1 > col)
                {
                    if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                        map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                        map[tabaghe][row1 - 1][col1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                        map[tabaghe][row1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                        map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                        map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                }
                else if (col1 < col)
                {
                    if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                        map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                        map[tabaghe][row1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                        map[tabaghe][row1 - 1][col1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                        map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                        map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                }
                else if (col1 == col)
                {
                    if (map[tabaghe][row1 - 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                        map[tabaghe][row1 - 1][col1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                        map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                        map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                        map[tabaghe][row1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else if (map[tabaghe][row1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                        map[tabaghe][row1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                }
            }
        }
        else
        {
            int ans = 1;
            int x = rand() % 9;
            if (x == 0)
            {
                if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                    map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
                else
                {
                    ans = 0;
                }
            }
            if (x == 1)
            {
                if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                    map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else
                {
                    ans = 0;
                }
            }
            if (x == 2)
            {
                if (map[tabaghe][row1 - 1][col1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                    map[tabaghe][row1 - 1][col1] = doshman[i].type;
                    doshman[i].row = row1 - 1;
                    doshman[i].col = col1;
                    doshman[i].chase_count += 1;
                }
                else
                {
                    ans = 0;
                }
            }
            if (x == 3)
            {
                if (map[tabaghe][row1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                    map[tabaghe][row1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else
                {
                    ans = 0;
                }
            }
            if (x == 4)
            {
                if (map[tabaghe][row1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                    map[tabaghe][row1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
                else
                {
                    ans = 0;
                }
            }
            if (x == 5)
            {
                if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                    map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1 - 1;
                    doshman[i].chase_count += 1;
                }
                else
                {
                    ans = 0;
                }
            }
            if (x == 6)
            {
                if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                    map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1 + 1;
                    doshman[i].chase_count += 1;
                }
                else
                {
                    ans = 0;
                }
            }
            if (x == 7)
            {
                if (map[tabaghe][row1 + 1][col1] == '.')
                {
                    map[tabaghe][row1][col1] = doshman[i].ghabli;
                    doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                    map[tabaghe][row1 + 1][col1] = doshman[i].type;
                    doshman[i].row = row1 + 1;
                    doshman[i].col = col1;
                    doshman[i].chase_count += 1;
                }
                else
                {
                    ans = 0;
                }
            }
            while (ans == 0)
            {
                ans = 1;
                x = rand() % 9;
                if (x == 0)
                {
                    if (map[tabaghe][row1 - 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 - 1];
                        map[tabaghe][row1 - 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else
                    {
                        ans = 0;
                    }
                }
                if (x == 1)
                {
                    if (map[tabaghe][row1 - 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1 + 1];
                        map[tabaghe][row1 - 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else
                    {
                        ans = 0;
                    }
                }
                if (x == 2)
                {
                    if (map[tabaghe][row1 - 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 - 1][col1];
                        map[tabaghe][row1 - 1][col1] = doshman[i].type;
                        doshman[i].row = row1 - 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else
                    {
                        ans = 0;
                    }
                }
                if (x == 3)
                {
                    if (map[tabaghe][row1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 + 1];
                        map[tabaghe][row1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else
                    {
                        ans = 0;
                    }
                }
                if (x == 4)
                {
                    if (map[tabaghe][row1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1][col1 - 1];
                        map[tabaghe][row1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else
                    {
                        ans = 0;
                    }
                }
                if (x == 5)
                {
                    if (map[tabaghe][row1 + 1][col1 - 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 - 1];
                        map[tabaghe][row1 + 1][col1 - 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 - 1;
                        doshman[i].chase_count += 1;
                    }
                    else
                    {
                        ans = 0;
                    }
                }
                if (x == 6)
                {
                    if (map[tabaghe][row1 + 1][col1 + 1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1 + 1];
                        map[tabaghe][row1 + 1][col1 + 1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1 + 1;
                        doshman[i].chase_count += 1;
                    }
                    else
                    {
                        ans = 0;
                    }
                }
                if (x == 7)
                {
                    if (map[tabaghe][row1 + 1][col1] == '.')
                    {
                        map[tabaghe][row1][col1] = doshman[i].ghabli;
                        doshman[i].ghabli = map[tabaghe][row1 + 1][col1];
                        map[tabaghe][row1 + 1][col1] = doshman[i].type;
                        doshman[i].row = row1 + 1;
                        doshman[i].col = col1;
                        doshman[i].chase_count += 1;
                    }
                    else
                    {
                        ans = 0;
                    }
                }
            }
        }
    }
}
void harekat_monster(int row, int col, int tabaghe)
{
    for (int i = 0; i < enemy_count; i++)
    {
        if (doshman[i].tabaghe == tabaghe)
        {
            if (dakhel_otagh(row, col, tabaghe) == 1)
            {
                if ((nahye_shenas(row, col) == nahye_shenas(doshman[i].row, doshman[i].col)) || tabaghe == 4)
                {
                    if (doshman[i].ability_to_walk == 1 && doshman[i].health > 0)
                    {
                        if (doshman[i].type == 'S')
                        {
                            check_harekat(row, col, tabaghe, doshman[i].row, doshman[i].col, i, 'S');
                        }
                        if (doshman[i].type == 'I')
                        {
                            check_harekat(row, col, tabaghe, doshman[i].row, doshman[i].col, i, 'I');
                        }
                        if (doshman[i].type == 'f')
                        {
                            check_harekat(row, col, tabaghe, doshman[i].row, doshman[i].col, i, 'f');
                        }
                        if (doshman[i].type == 'd')
                        {
                            check_harekat(row, col, tabaghe, doshman[i].row, doshman[i].col, i, 'd');
                        }
                        if (doshman[i].type == 'u')
                        {
                            check_harekat(row, col, tabaghe, doshman[i].row, doshman[i].col, i, 'u');
                        }
                    }
                }
            }
        }
    }
}
void damage_monster(int row, int col, int tabaghe)
{
    for (int i = 0; i < enemy_count; i++)
    {
        if (doshman[i].tabaghe == tabaghe)
        {
            if (doshman[i].row - row < 2 && doshman[i].row - row > -2)
            {
                if (doshman[i].col - col < 2 && doshman[i].col - col > -2)
                {
                    if (doshman[i].health > 0)
                    {
                        if (doshman[i].type == 'S')
                        {
                            if ((rand() % 2) == 0)
                            {
                                hp -= 8;
                                mvprintw(1, 0, "The snake has inflicted a venomous bite on you\n");
                                char ans = getch();
                                while (ans != ' ')
                                {
                                    ans = getch();
                                }
                            }
                            else
                            {
                                mvprintw(1, 0, "Alhamdolelah. The snake couldn't bite\n");
                                char ans = getch();
                                while (ans != ' ')
                                {
                                    ans = getch();
                                }
                            }
                        }
                        if (doshman[i].type == 'I')
                        {
                            if ((rand() % 2) == 0)
                            {
                                hp -= 5;
                                mvprintw(1, 0, "The Giant smashed you.\n");
                                char ans = getch();
                                while (ans != ' ')
                                {
                                    ans = getch();
                                }
                            }
                            else
                            {
                                mvprintw(1, 0, "Alhamdolelah.The giant missed\n");
                                char ans = getch();
                                while (ans != ' ')
                                {
                                    ans = getch();
                                }
                            }
                        }
                        if (doshman[i].type == 'f')
                        {
                            if ((rand() % 2) == 0)
                            {
                                hp -= 8;
                                mvprintw(1, 0, "The Fire Breathing Monster has caused you to suffer burns.\n");
                                char ans = getch();
                                while (ans != ' ')
                                {
                                    ans = getch();
                                }
                            }
                            else
                            {
                                mvprintw(1, 0, "Alhamdolelah.The Fire Breathing Monster couldn't supply fuel for its fire\n");
                                char ans = getch();
                                while (ans != ' ')
                                {
                                    ans = getch();
                                }
                            }
                        }
                        if (doshman[i].type == 'd')
                        {
                            if ((rand() % 2) == 0)
                            {
                                hp -= 5;
                                mvprintw(1, 0, "The deamon stabbed you in the back.\n");
                                char ans = getch();
                                while (ans != ' ')
                                {
                                    ans = getch();
                                }
                            }
                            else
                            {
                                mvprintw(1, 0, "Alhamdolelah.The deamon missed\n");
                                char ans = getch();
                                while (ans != ' ')
                                {
                                    ans = getch();
                                }
                            }
                        }
                        if (doshman[i].type == 'u')
                        {
                            if ((rand() % 2) == 0)
                            {
                                hp -= 10;
                                mvprintw(1, 0, "The Undead hit you with dark forth\n");
                                char ans = getch();
                                while (ans != ' ')
                                {
                                    ans = getch();
                                }
                            }
                            else
                            {
                                mvprintw(1, 0, "Alhamdolelah.light force helped us to defend the Undeads hit\n");
                                char ans = getch();
                                while (ans != ' ')
                                {
                                    ans = getch();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void start_menu()
{
    clear();
    refresh();
    printw("1.sign_up\n2.sign_in\n3.inter_as_geust\n");
    char ans = getch();
    while (ans != '1' && ans != '2' && ans != '3')
    {
        ans = getch();
    }
    if (ans == '1')
    {
        sign_up();
    }
    if (ans == '2')
    {
        sign_in();
    }
    if (ans == '3')
    {
        inter_as_guest();
    }
}
int nahye_shenas(int row, int col)
{
    int r = ((row / 16) * 10) + (col / 16);
    return r;
}
int to_otagh(int row, int col, int tabaghe)
{
    if (map[tabaghe][row - 1][col] == '.')
    {
        return 1;
    }
    if (map[tabaghe][row + 1][col] == '.')
    {
        return 1;
    }
    if (map[tabaghe][row][col + 1] == '.')
    {
        return 1;
    }
    if (map[tabaghe][row][col - 1] == '.')
    {
        return 1;
    }
    return 0;
}
void trap(char f)
{
    if (f == 'R')
    {
        mvprintw(1, 0, "ohhhhhhhhhhh! you stepped on a big trappp.\n");
        char chert = getch();
        while (chert != ' ')
        {
            chert = getch();
        }

        hp -= ((rand() % 5) + 1);
    }
    if (f == 'r')
    {
        mvprintw(1, 0, "oh. i think you stepped on a bee.\n");
        char chert = getch();

        while (chert != ' ')
        {
            chert = getch();
        }
        hp -= ((rand() % 5) + 10);
    }
}
int goshe_shenas(int row, int col, int f)
{
    int x1, x2, y1, y2;
    while (map[f][row][col] != '_' && map[f][row][col] != '+' && map[f][row][col] != '?' && map[f][row][col] != '!')
    {
        row -= 1;
    }
    x1 = row;
    row += 1;
    while (map[f][row][col] != '_' && map[f][row][col] != '+' && map[f][row][col] != '?' && map[f][row][col] != '!')
    {
        row += 1;
    }
    x2 = row;
    row -= 1;
    while (map[f][row][col] != '|' && map[f][row][col] != '+' && map[f][row][col] != '?' && map[f][row][col] != '!')
    {
        col += 1;
    }
    y2 = col;
    col -= 1;
    while (map[f][row][col] != '|' && map[f][row][col] != '+' && map[f][row][col] != '?' && map[f][row][col] != '!')
    {
        col -= 1;
    }
    y1 = col;
    return (x1 + (100 * x2) + (10000 * y1) + (1000000 * y2));
}
int check_stair(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i < (x2 + 1); i++)
    {
        for (int j = y1; j < (y2 + 1); j++)
        {
            if (map[3][i][j] == 'D' || map[3][i][j] == 'U')
            {
                return 1;
            }
        }
    }
    return 0;
}
void add_otagh_ganj()
{
    int row = rand() % 49;
    int col = rand() % 49;
    int chargosh = goshe_shenas(row, col, 3);
    int x1, x2, y1, y2;
    x1 = (chargosh % 100);
    chargosh /= 100;
    x2 = (chargosh % 100);
    chargosh /= 100;
    y1 = (chargosh % 100);
    chargosh /= 100;
    y2 = (chargosh % 100);
    while (map[3][row][col] != '.' || check_stair(x1, y1, x2, y2) != 0)
    {
        row = rand() % 49;
        col = rand() % 49;
        chargosh = goshe_shenas(row, col, 3);
        x1 = (chargosh % 100);
        chargosh /= 100;
        x2 = (chargosh % 100);
        chargosh /= 100;
        y1 = (chargosh % 100);
        chargosh /= 100;
        y2 = (chargosh % 100);
    }
    for (int i = x1; i < (x2 + 1); i++)
    {
        for (int j = y1; j < (y2 + 1); j++)
        {
            if (map[3][i][j] == '.')
            {
                int x = rand() % 100;
                if (x < 8)
                {
                    if (x < 4)
                    {
                        map[3][i][j] = 'r';
                    }
                    else
                    {
                        map[3][i][j] = 'R';
                    }
                }
                if (x > 57 && x < 61)
                {
                    map[3][i][j] = 'g';
                    map_gold[3][i][j] = (rand() % 100) + 150;
                }
                if (x > 10 && x < 21)
                {
                    map[3][i][j] = 'G';
                    map_gold[3][i][j] = (rand() % 50) + 1;
                }
                if (x > 80 && x < 86)
                {
                    map[3][i][j] = 'F';
                }
            }
        }
    }
    row = (rand() % (x2 - x1 - 1)) + x1 + 1;
    col = (rand() % (y2 - y1 - 1)) + y1 + 1;
    while (map[3][row][col] != '.')
    {
        row = (rand() % (x2 - x1 - 1)) + x1 + 1;
        col = (rand() % (y2 - y1 - 1)) + y1 + 1;
    }
    map[3][row][col] = 'E';
}
void initial_map_seen(int row, int col)
{
    int x1, x2, y1, y2;
    int chargosh = goshe_shenas(row, col, 0);
    x1 = (chargosh % 100);
    chargosh /= 100;
    x2 = (chargosh % 100);
    chargosh /= 100;
    y1 = (chargosh % 100);
    chargosh /= 100;
    y2 = (chargosh % 100);
    for (int i = x1; i < (x2 + 1); i++)
    {
        for (int j = y1; j < (y2 + 1); j++)
        {
            map_seen[0][i][j] = 2;
        }
    }
}
void check_seen(int row, int col, int tabaghe, char s)
{
    if (s == 'U')
    {
        tabaghe += 1;
        tabaghe = (tabaghe % 4);
        for (int i = 0; i < 49; i++)
        {
            for (int j = 0; j < 49; j++)
            {
                if (map[tabaghe][i][j] == 'D')
                {
                    row = i;
                    col = j;
                }
            }
        }
        int x1, x2, y1, y2;
        int chargosh = goshe_shenas(row, col, tabaghe);
        x1 = (chargosh % 100);
        chargosh /= 100;
        x2 = (chargosh % 100);
        chargosh /= 100;
        y1 = (chargosh % 100);
        chargosh /= 100;
        y2 = (chargosh % 100);
        for (int i = x1; i < (x2 + 1); i++)
        {
            for (int j = y1; j < (y2 + 1); j++)
            {
                map_seen[tabaghe][i][j] = 2;
            }
        }
    }
    else if (s == 'D')
    {
        tabaghe -= 1;
        tabaghe += 4;
        tabaghe = (tabaghe % 4);
        for (int i = 0; i < 49; i++)
        {
            for (int j = 0; j < 49; j++)
            {
                if (map[tabaghe][i][j] == 'U')
                {
                    row = i;
                    col = j;
                }
            }
        }
        int x1, x2, y1, y2;
        int chargosh = goshe_shenas(row, col, tabaghe);
        x1 = (chargosh % 100);
        chargosh /= 100;
        x2 = (chargosh % 100);
        chargosh /= 100;
        y1 = (chargosh % 100);
        chargosh /= 100;
        y2 = (chargosh % 100);
        for (int i = x1; i < (x2 + 1); i++)
        {
            for (int j = y1; j < (y2 + 1); j++)
            {
                map_seen[tabaghe][i][j] = 2;
            }
        }
    }
    else if (s == '+')
    {
        int x1, x2, y1, y2;
        int chargosh = goshe_shenas(row, col, tabaghe);
        x1 = (chargosh % 100);
        chargosh /= 100;
        x2 = (chargosh % 100);
        chargosh /= 100;
        y1 = (chargosh % 100);
        chargosh /= 100;
        y2 = (chargosh % 100);
        for (int i = x1; i < (x2 + 1); i++)
        {
            for (int j = y1; j < (y2 + 1); j++)
            {
                map_seen[tabaghe][i][j] = 2;
            }
        }
    }
    else if (s == '.')
    {
        int x1, x2, y1, y2;
        int chargosh = goshe_shenas(row, col, tabaghe);
        x1 = (chargosh % 100);
        chargosh /= 100;
        x2 = (chargosh % 100);
        chargosh /= 100;
        y1 = (chargosh % 100);
        chargosh /= 100;
        y2 = (chargosh % 100);
        for (int i = x1; i < (x2 + 1); i++)
        {
            for (int j = y1; j < (y2 + 1); j++)
            {
                map_seen[tabaghe][i][j] = 2;
            }
        }
    }
}
int faseleha(int row1, int col1, int row2, int col2)
{
    int r = 0;
    if (row1 > row2)
    {
        r += (row1 - row2);
    }
    else
    {
        r += (row2 - row1);
    }
    if (col1 > col2)
    {
        r += (col1 - col2);
    }
    else
    {
        r += (col2 - col1);
    }
    return r;
}
void print_board(int tabaghe, int row, int col)
{
    clear();
    // char *message = "\u2692\n"; // UTF-8 string
    // mvprintw(0, 0, "%s", message);
    printw("-------------------------------------------\n");
    printw("$money$ = %d    ", gold);
    printw("health: ");
    for (int i = 0; i < (hp / 5) + 1; i++)
    {
        if (hp / 5 > 12)
        {
            attron(COLOR_PAIR(1));
            printw("=");
            attroff(COLOR_PAIR(1));
        }
        if (hp / 5 < 13 && hp / 5 > 6)
        {
            attron(COLOR_PAIR(2));
            printw("=");
            attroff(COLOR_PAIR(2));
        }
        if (hp / 5 < 7)
        {
            attron(COLOR_PAIR(3));
            printw("=");
            attroff(COLOR_PAIR(3));
        }
    }
    printw("    energy: ");
    for (int i = 0; i < (shadabi / 5) + 1; i++)
    {
        if (shadabi / 5 > 12)
        {
            attron(COLOR_PAIR(1));
            printw("=");
            attroff(COLOR_PAIR(1));
        }
        if (shadabi / 5 < 13 && shadabi / 5 > 6)
        {
            attron(COLOR_PAIR(2));
            printw("=");
            attroff(COLOR_PAIR(2));
        }
        if (shadabi / 5 < 7)
        {
            attron(COLOR_PAIR(3));
            printw("=");
            attroff(COLOR_PAIR(3));
        }
    }
    printw("\n");
    for (int i = 0; i < 49; i++)
    {
        for (int j = 0; j < 49; j++)
        {
            if (i == 1 && j == 1 && map[tabaghe][i][j] == '.')
            {
                printw("  ");
                continue;
            }
            if (map_seen[tabaghe][i][j] == 2 || map[tabaghe][i][j] == 'N' || ((map_seen[tabaghe][i][j] == 1) && (faseleha(row, col, i, j) < 6) && to_otagh(row, col, tabaghe) == 0) || tabaghe == 4 || tabaghe == 5)
            {
                if (map[tabaghe][i][j] != '#')
                {
                    int x1, x2, y1, y2;
                    int z1 = nahye_shenas(row, col);
                    int z2 = nahye_shenas(i, j);
                    x1 = (z1 / 10);
                    y1 = (z1 % 10);
                    x2 = (z2 / 10);
                    y2 = (z2 % 10);
                    int r = 0;
                    if (x1 > x2)
                    {
                        r += (x1 - x2);
                    }
                    else
                    {
                        r += (x2 - x1);
                    }
                    if (y1 > y2)
                    {
                        r += (y1 - y2);
                    }
                    else
                    {
                        r += (y2 - y1);
                    }
                    if (r < 2 || tabaghe == 4 || tabaghe == 5)
                    {
                        if (map[tabaghe][i][j] == 'R' || map[tabaghe][i][j] == 'r')
                        {
                            printw(". ");
                        }
                        // else if (map[tabaghe][i][j] == '4')
                        // {
                        //     char *message = "\u2692"; // UTF-8 string
                        //     mvprintw(0, 0, "%s", message);
                        // }

                        else
                        {

                            if (map[tabaghe][i][j] == '4' || map[tabaghe][i][j] == '9')
                            {
                                char *message = "\u27b3"; // UTF-8 string
                                printw("%s ", message);
                            }
                            else if (map[tabaghe][i][j] == '5')
                            {
                                char *message = "\u2694"; // UTF-8 string
                                printw("%s ", message);
                            }
                            else if (map[tabaghe][i][j] == '3' || map[tabaghe][i][j] == '8')
                            {
                                attron(A_DIM);
                                char *magic_wand = "\U0001F300";
                                printw("%s", magic_wand);
                                attroff(A_DIM);
                            }
                            else if (map[tabaghe][i][j] == '2' || map[tabaghe][i][j] == '7')
                            {

                                char *message = "\U0001F5E1"; // UTF-8 string
                                printw("%s ", message);
                            }
                            else if (map[tabaghe][i][j] == '#')
                            {
                                char *message = "\u2507";
                                printw("%s%s", message, message);
                            }
                            else if (map[tabaghe][i][j] == 'N')
                            {
                                char *message = "\U0001F5FF";
                                printw("%s", message);
                            }
                            else if (map[tabaghe][i][j] == '|')
                            {
                                char *message = "\u2551";
                                printw("%s ", message);
                            }
                            else if (map[tabaghe][i][j] == '_' || map[tabaghe][i][j] == '!')
                            {
                                char *message = "\u2550";
                                printw("%s%s", message, message);
                            }
                            else if (map[tabaghe][i][j] == '$')
                            {
                                if (map[tabaghe][i][j + 1] != ' ' && map[tabaghe][i][j + 1] != '#')
                                {
                                    char *message = "\u25B4";
                                    char *message1 = "\u2550";
                                    printw("%s%s", message, message1);
                                }
                                else
                                {
                                    char *message = "\u25B4";
                                    printw("%s ", message);
                                }
                            }
                            else if (map[tabaghe][i][j] == 'G')
                            {
                                char *message = "\U0001F4B0";
                                printw("%s", message);
                            }
                            else if (map[tabaghe][i][j] == 'g')
                            {
                                char *message = "\U0001F48E";
                                printw("%s", message);
                            }
                            else if (map[tabaghe][i][j] == 'S')
                            {
                                char *message = "\U0001F40D";
                                printw("%s", message);
                            }
                            else if (map[tabaghe][i][j] == 'd')
                            {
                                char *message = "\U0001F47F";
                                printw("%s", message);
                            }
                            else if (map[tabaghe][i][j] == 'F')
                            {
                                char *message = "\U0001F958";
                                printw("%s", message);
                            }
                            else if (map[tabaghe][i][j] == 'f')
                            {
                                char *message = "\U0001F409";
                                printw("%s", message);
                            }
                            else if (map[tabaghe][i][j] == 'T')
                            {
                                char *message = "\U0001F3FA";
                                printw("%s", message);
                            }
                            else if (map[tabaghe][i][j] == 'I')
                            {
                                char *message = "\U0001F47E";
                                printw("%s", message);
                            }
                            else if (map[tabaghe][i][j] == 'E')
                            {
                                char *message = "\U0001F6D6";
                                printw("%s", message);
                            }
                            else if (map[tabaghe][i][j] == 'U')
                            {
                                char *message = "\u23EB";
                                printw("%s", message);
                            }
                            else if (map[tabaghe][i][j] == 'D')
                            {
                                char *message = "\u23EC";
                                printw("%s", message);
                            }
                            else if (map[tabaghe][i][j] == 'u')
                            {
                                char *message = "\U0001F480";
                                printw("%s", message);
                            }
                            else if (map[tabaghe][i][j] == '?')
                            {
                                printw("%c%c", map[tabaghe][i][j], map[tabaghe][i][j]);
                            }
                            else if (map[tabaghe][i][j] == '+')
                            {
                                printw("%c%c", map[tabaghe][i][j], map[tabaghe][i][j]);
                            }
                            else
                            {
                                printw("%c ", map[tabaghe][i][j]);
                            }
                        }
                    }
                    else
                    {
                        printw("  ");
                    }
                }
                else
                {
                    if (map[tabaghe][i][j] == 'R' || map[tabaghe][i][j] == 'r')
                    {
                        printw(". ");
                    }
                    else
                    {

                        if (map[tabaghe][i][j] == '4' || map[tabaghe][i][j] == '9')
                        {
                            char *message = "\u27b3"; // UTF-8 string
                            printw("%s ", message);
                        }
                        else if (map[tabaghe][i][j] == '5')
                        {
                            char *message = "\u2694"; // UTF-8 string
                            printw("%s ", message);
                        }
                        else if (map[tabaghe][i][j] == '3' || map[tabaghe][i][j] == '8')
                        {
                            char *message = "\U0001F300"; // UTF-8 string
                            printw("%s", message);
                        }
                        else if (map[tabaghe][i][j] == '2' || map[tabaghe][i][j] == '7')
                        {
                            char *message = "\U0001F5E1"; // UTF-8 string
                            printw("%s ", message);
                        }
                        else if (map[tabaghe][i][j] == '#')
                        {
                            char *message = "\u2507";
                            printw("%s%s", message, message);
                        }
                        else if (map[tabaghe][i][j] == 'N')
                        {
                            char *message = "\U0001F5FF";
                            printw("%s", message);
                        }
                        else if (map[tabaghe][i][j] == '|')
                        {
                            char *message = "\u2551";
                            printw("%s ", message);
                        }
                        else if (map[tabaghe][i][j] == '_' || map[tabaghe][i][j] == '!')
                        {
                            char *message = "\u2550";
                            printw("%s ", message);
                        }
                        else if (map[tabaghe][i][j] == '$')
                        {
                            if (map[tabaghe][i][j + 1] != ' ' && map[tabaghe][i][j + 1] != '#')
                            {
                                char *message = "\u25B4";
                                char *message1 = "\u2550";
                                printw("%s%s", message, message1);
                            }
                            else
                            {
                                char *message = "\u25B4";
                                printw("%s ", message);
                            }
                        }
                        else if (map[tabaghe][i][j] == '+')
                        {
                            printw("%c%c", map[tabaghe][i][j], map[tabaghe][i][j]);
                        }
                        else if (map[tabaghe][i][j] == '+')
                        {
                            printw("%c%c", map[tabaghe][i][j], map[tabaghe][i][j]);
                        }
                        else if (map[tabaghe][i][j] == 'G')
                        {
                            char *message = "\U0001F4B0";
                            printw("%s", message);
                        }
                        else if (map[tabaghe][i][j] == 'g')
                        {
                            char *message = "\U0001F48E";
                            printw("%s", message);
                        }
                        else if (map[tabaghe][i][j] == 'S')
                        {
                            char *message = "\U0001F40D";
                            printw("%s", message);
                        }
                        else if (map[tabaghe][i][j] == 'd')
                        {
                            char *message = "\U0001F47F";
                            printw("%s", message);
                        }
                        else if (map[tabaghe][i][j] == 'F')
                        {
                            char *message = "\U0001F958";
                            printw("%s", message);
                        }
                        else if (map[tabaghe][i][j] == 'f')
                        {
                            char *message = "\U0001F409";
                            printw("%s", message);
                        }
                        else if (map[tabaghe][i][j] == 'I')
                        {
                            char *message = "\U0001F47E";
                            printw("%s", message);
                        }
                        else if (map[tabaghe][i][j] == 'T')
                        {
                            char *message = "\U0001F3FA";
                            printw("%s", message);
                        }
                        else if (map[tabaghe][i][j] == 'E')
                        {
                            char *message = "\U0001F6D6";
                            printw("%s", message);
                        }
                        else if (map[tabaghe][i][j] == 'U')
                        {
                            char *message = "\u23EB";
                            printw("%s", message);
                        }
                        else if (map[tabaghe][i][j] == 'D')
                        {
                            char *message = "\u23EC";
                            printw("%s", message);
                        }
                        else if (map[tabaghe][i][j] == 'u')
                        {
                            char *message = "\U0001F480";
                            printw("%s", message);
                        }
                        else
                        {
                            printw("%c ", map[tabaghe][i][j]);
                        }
                    }
                }
            }
            else
            {
                printw("  ");
            }
            if (faseleha(row, col, i, j) == 0)
            {
                map_seen[tabaghe][i][j] = 2;
            }
        }
        printw("\n");
    }
    printw("\n");
    // printw("-------------------------------------------");
    printw("\n");

    refresh();
}
int account_exist(char a[50], FILE *fptr)
{
    char line[100];
    while (fgets(line, sizeof(line), fptr))
    {
        line[strcspn(line, "\n")] = 0; // Remove newline
        if (strcmp(line, a) == 0)
        {
            return 0;
        }
    }
    return 1;
}
int find_line(char a[50], FILE *fptr)
{
    char line[100];
    int khat = 0;
    while (fgets(line, sizeof(line), fptr))
    {
        line[strcspn(line, "\n")] = 0; // Remove newline
        if (strcmp(line, a) == 0)
        {
            return khat;
        }
        khat++;
    }
    return -1;
}
int reg_pass(char b[100])
{
    if (strlen(b) < 7)
    {
        return 0;
    }
    int charc = 0, chars = 0, number = 0;
    for (int i = 0; i < strlen(b); i++)
    {
        if ((int)b[i] > 47 && (int)b[i] < 58)
        {
            number += 1;
        }
        if ((int)b[i] > 64 && (int)b[i] < 91)
        {
            charc += 1;
        }
        if ((int)b[i] > 96 && (int)b[i] < 123)
        {
            chars += 1;
        }
    }
    if (charc == 0 || chars == 0 || number == 0)
    {
        return 0;
    }
    return 1;
}
int reg_email(char c[200])
{
    int adsigh = 0;
    int dot = 0;
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] == '@')
        {
            if (adsigh == 0)
            {
                if (i == 0)
                {
                    return 0;
                }
                else
                {
                    adsigh = i;
                }
            }
            else
            {
                return 0;
            }
        }
    }
    if (adsigh == 0)
    {
        return 0;
    }
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] == '.')
        {
            if (dot > adsigh)
            {
                return 0;
            }
            else
            {
                dot = i;
            }
        }
    }
    if (dot - adsigh > 1 && dot > 0 && adsigh > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void sign_up()
{
    clear();
    refresh();
    printw("Username (max 50 char):\n");
    char a[100];
    scanw("%s", a);
    a[strcspn(a, "\n")] = 0; // Remove newline
    FILE *fptr = fopen("karbar.txt", "r");
    printw("Password (max 50 char):\n");
    char b[100];
    scanw("%s", b);
    b[strcspn(b, "\n")] = 0; // Remove newline
    printw("E-mail:\n");
    char c[200];
    scanw("%s", c);
    c[strcspn(c, "\n")] = 0; // Remove newline
    int pass = reg_pass(b);
    int email = reg_email(c);
    if (find_line(a, fptr) > -1)
    {
        printw("This username is already in use.(press space)\n");
        char chert = getch();
        while (chert != ' ')
        {
            chert = getch();
        }
        start_menu();
        return;
    }
    else
    {
        if (pass == 0)
        {
            printw("Password should contain uppercase chars and lowercase chars and numbers and at least 7 digits(press space)\n");
            char chert = getch();
            while (chert != ' ')
            {
                chert = getch();
            }
            sign_up();
            return;
        }
        else
        {
            if (email == 0)
            {
                printw("pleas inter your E-mail corrctly(press space)\n");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                sign_up();
                return;
            }
        }
    }
    // Save data
    FILE *fptr1 = fopen("karbar.txt", "a");
    FILE *fptr2 = fopen("ramz.txt", "a");
    FILE *fptr3 = fopen("email.txt", "a");
    FILE *fptr5 = fopen("emtyaz.txt", "a");
    fprintf(fptr1, "%s\n", a);
    fprintf(fptr2, "%s\n", b);
    fprintf(fptr3, "%s\n", c);
    fprintf(fptr5, "0\n");
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    fclose(fptr5);
    char save[100];
    strcpy(save, a);
    strncat(save, "g.txt", sizeof(save) - 5 - 1);
    FILE *fptr4 = fopen(save, "w");
    fclose(fptr4);
    strcpy(save, a);
    strncat(save, "map.txt", sizeof(save) - 7 - 1);
    fptr4 = fopen(save, "w");
    fclose(fptr4);
    strcpy(save, a);
    strncat(save, "telesm.txt", sizeof(save) - 9 - 1);
    fptr4 = fopen(save, "w");
    fclose(fptr4);
    strcpy(save, a);
    strncat(save, "dagger.txt", sizeof(save) - 10 - 1);
    fptr4 = fopen(save, "w");
    fclose(fptr4);
    strcpy(save, a);
    strncat(save, "sword.txt", sizeof(save) - 9 - 1);
    fptr4 = fopen(save, "w");
    fclose(fptr4);
    strcpy(save, a);
    strncat(save, "arrow.txt", sizeof(save) - 9 - 1);
    fptr4 = fopen(save, "w");
    fclose(fptr4);
    strcpy(save, a);
    strncat(save, "wand.txt", sizeof(save) - 8 - 1);
    fptr4 = fopen(save, "w");
    fclose(fptr4);
    strcpy(save, a);
    strncat(save, "hidden.txt", sizeof(save) - 10 - 1);
    fptr4 = fopen(save, "w");
    fclose(fptr4);
    strcpy(save, a);
    strncat(save, "mapgold.txt", sizeof(save) - 11 - 1);
    fptr4 = fopen(save, "w");
    fclose(fptr4);
    strcpy(save, a);
    strncat(save, "mapseen.txt", sizeof(save) - 11 - 1);
    fptr4 = fopen(save, "w");
    fclose(fptr4);
    strcpy(save, a);
    strncat(save, "hp.txt", sizeof(save) - 6 - 1);
    fptr4 = fopen(save, "w");
    fclose(fptr4);
    strcpy(save, a);
    strncat(save, "shadabi.txt", sizeof(save) - 11 - 1);
    fptr4 = fopen(save, "w");
    fclose(fptr4);
    strcpy(save, a);
    strncat(save, "Foodcount.txt", sizeof(save) - 13 - 1);
    fptr4 = fopen(save, "w");
    fclose(fptr4);
    strcpy(save, a);
    strncat(save, "telesmcount.txt", sizeof(save) - 15 - 1);
    fptr4 = fopen(save, "w");
    fclose(fptr4);
    strcpy(save, a);
    strncat(save, "save.txt", sizeof(save) - 11 - 1);
    fptr4 = fopen(save, "w");
    fclose(fptr4);
    // Create user directory
    start_menu();
}
void sign_in()
{
    clear();
    refresh();
    char a[60];
    printw("Username:\n");
    scanw("%s", a);
    a[strcspn(a, "\n")] = 0; // Remove newline
    printw("Password:\n");
    char b[50];
    scanw("%s", b);
    b[strcspn(b, "\n")] = 0; // Remove newline
    FILE *fptr = fopen("karbar.txt", "r");
    FILE *fptr1 = fopen("ramz.txt", "r");
    int khat = find_line(a, fptr);
    if (khat == -1)
    {
        printw("This account name doesn't exist. If you don't have an account, create one.(press space)\n");
        char chert = getch();
        while (chert != ' ')
        {
            chert = getch();
        }
        start_menu();
    }
    else
    {
        char line[200];
        int r = 0;
        while (fgets(line, sizeof(line), fptr1))
        {
            line[strcspn(line, "\n")] = '\0'; // Remove newline
            if (khat == r)
            {
                if (strcmp(b, line) == 0)
                {
                    strcpy(karbar, a); // Store username globally
                    printw("Welcome, %s!(press space)\n", a);
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                }
                else
                {
                    printw("Your password is incorrect(press space)\n");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
            }
            r++;
        }
    }
    fclose(fptr);
    fclose(fptr1);
    menu_start();
}
void inter_as_guest()
{
    load_game = 2;
    creat_map(1);
    creat_map(2);
    creat_map(3);
    creat_map(0);
}
void goshe_kesh(char naghshe[49][49])
{
    for (int i = 0; i < 3; i++)
    {
        naghshe[(16 * i) + 1][15] = '@';
        naghshe[(16 * i) + 15][15] = '@';
        naghshe[(16 * i) + 1][17] = '@';
        naghshe[(16 * i) + 15][17] = '@';
        naghshe[(16 * i) + 1][31] = '@';
        naghshe[(16 * i) + 15][31] = '@';
        naghshe[(16 * i) + 1][33] = '@';
        naghshe[(16 * i) + 15][33] = '@';
    }
    for (int i = 0; i < 3; i++)
    {
        naghshe[15][(16 * i) + 1] = '@';
        naghshe[15][(16 * i) + 15] = '@';
        naghshe[17][(16 * i) + 1] = '@';
        naghshe[31][(16 * i) + 1] = '@';
        naghshe[31][(16 * i) + 15] = '@';
        naghshe[17][(16 * i) + 15] = '@';
        naghshe[33][(16 * i) + 1] = '@';
        naghshe[33][(16 * i) + 15] = '@';
    }
}
int otaban_kesh(int is, int js, char naghshe[49][49], int s, int m)
{
    int currentj = js;
    int currenti = is;
    if (naghshe[is][js - 1] == '.')
    {
        currentj += 1;
        naghshe[currenti][currentj] = '#';
        while (1)
        {
            if (currentj == 15 || currentj == 31 || currentj == 47)
            {
                break;
            }
            naghshe[currenti][currentj] = '#';
            currentj += 1;
        }
        naghshe[currenti][currentj] = '#';
        if ((s / 3) > (m / 3))
        {
            while (1)
            {
                if (currenti == 1 || currenti == 17 || currenti == 33)
                {
                    break;
                }
                naghshe[currenti][currentj] = '#';
                currenti -= 1;
            }
        }
        else
        {
            while (1)
            {
                if (currenti == 15 || currenti == 31 || currenti == 47)
                {
                    break;
                }
                naghshe[currenti][currentj] = '#';
                currenti += 1;
            }
        }
    }
    else if (naghshe[is][js + 1] == '.')
    {
        currentj -= 1;
        naghshe[currenti][currentj] = '#';
        while (1)
        {
            if (currentj == 1 || currentj == 17 || currentj == 33)
            {
                break;
            }
            naghshe[currenti][currentj] = '#';
            currentj -= 1;
        }
        naghshe[currenti][currentj] = '#';
        if ((s / 3) > (m / 3))
        {
            while (1)
            {
                if (currenti == 1 || currenti == 17 || currenti == 33)
                {
                    break;
                }
                naghshe[currenti][currentj] = '#';
                currenti -= 1;
            }
        }
        else
        {
            while (1)
            {
                if (currenti == 15 || currenti == 31 || currenti == 47)
                {
                    break;
                }
                naghshe[currenti][currentj] = '#';
                currenti += 1;
            }
        }
    }
    else if (naghshe[is + 1][js] == '.')
    {
        currenti -= 1;
        naghshe[currenti][currentj] = '#';
        while (1)
        {
            if (currenti == 1 || currenti == 17 || currenti == 33)
            {
                break;
            }
            naghshe[currenti][currentj] = '#';
            currenti -= 1;
        }
        naghshe[currenti][currentj] = '#';
        if ((s % 3) > (m % 3))
        {
            while (1)
            {
                if (currentj == 1 || currentj == 17 || currentj == 33)
                {
                    break;
                }
                naghshe[currenti][currentj] = '#';
                currentj -= 1;
            }
        }
        else
        {
            while (1)
            {
                if (currentj == 15 || currentj == 31 || currentj == 47)
                {
                    break;
                }
                naghshe[currenti][currentj] = '#';
                currentj += 1;
            }
        }
    }
    else if (naghshe[is - 1][js] == '.')
    {
        currenti += 1;
        naghshe[currenti][currentj] = '#';
        while (1)
        {
            if (currenti == 15 || currenti == 31 || currenti == 47)
            {
                break;
            }
            naghshe[currenti][currentj] = '#';
            currenti += 1;
        }
        naghshe[currenti][currentj] = '#';
        if ((s % 3) < (m % 3))
        {
            while (1)
            {
                if (currentj == 15 || currentj == 31 || currentj == 47)
                {
                    break;
                }
                naghshe[currenti][currentj] = '#';
                currentj += 1;
            }
        }
        else
        {
            while (1)
            {
                if (currentj == 1 || currentj == 17 || currentj == 33)
                {
                    break;
                }
                naghshe[currenti][currentj] = '#';
                currentj -= 1;
            }
        }
    }
    goshe_kesh(naghshe);
    return ((currenti * 100) + currentj);
}
void rahro_kesh(int is, int js, int im, int jm, char naghshe[49][49], int s, int m)
{
    int noghte1 = otaban_kesh(is, js, naghshe, s, m);
    int noghte2 = otaban_kesh(im, jm, naghshe, m, s);
    int is1 = noghte1 / 100;
    int js1 = noghte1 % 100;
    int im1 = noghte2 / 100;
    int jm1 = noghte2 % 100;
    if (im1 == is1)
    {
        if (jm1 > js1)
        {
            for (int i = js1; i < (jm1 + 1); i++)
            {
                naghshe[im1][i] = '#';
            }
        }
        else
        {
            for (int i = jm1; i < (js1 + 1); i++)
            {
                naghshe[im1][i] = '#';
            }
        }
    }
    else if (js1 == jm1)
    {
        if (im1 > is1)
        {
            for (int i = is1; i < (im1 + 1); i++)
            {
                naghshe[i][jm1] = '#';
            }
        }
        else
        {
            for (int i = im1; i < (is1 + 1); i++)
            {
                naghshe[i][jm1] = '#';
            }
        }
    }
    else if ((im1 > is1) && (jm1 > js1))
    {
        for (int i = is1; i < im1 + 1; i++)
        {
            naghshe[i][js1] = '#';
        }
        for (int i = js1; i < jm1 + 1; i++)
        {
            naghshe[im1][i] = '#';
        }
    }
    else if (im1 > is1 && jm1 < js1)
    {
        for (int i = is1; i < im1 + 1; i++)
        {
            naghshe[i][js1] = '#';
        }
        for (int i = jm1; i < js1 + 1; i++)
        {
            naghshe[im1][i] = '#';
        }
    }
    else if (jm1 > js1 && im1 < is1)
    {
        for (int i = js1; i < jm1 + 1; i++)
        {
            naghshe[is1][i] = '#';
        }
        for (int i = im1; i < is1 + 1; i++)
        {
            naghshe[i][jm1] = '#';
        }
    }
    else if (jm1 < js1 && im1 < is1)
    {
        for (int i = jm1; i < js1 + 1; i++)
        {
            naghshe[im1][i] = '#';
        }
        for (int i = im1; i < is1 + 1; i++)
        {
            naghshe[i][js1] = '#';
        }
    }
    naghshe[im1][js1] = '@';
    naghshe[im1][jm1] = '@';
    naghshe[is1][js1] = '@';
    naghshe[is1][jm1] = '@';
}
void osta_bana(int ghesmat[9], char naghshe[49][49], int tedad)
{
    int blook[tedad];
    int r = 0;
    for (int i = 0; i < 9; i++)
    {
        if (ghesmat[i] == 1)
        {
            blook[r] = i;
            r += 1;
        }
    }
    r = 0;
    int blook_random[tedad];
    while (r < tedad)
    {
        int x = (rand() % tedad);
        if (blook[x] != -1)
        {
            blook_random[r] = blook[x];
            blook[x] = -1;
            r += 1;
        }
    }
    for (int i = 0; i < tedad; i++)
    {
        if (i < (tedad - 1))
        {
            int maxx = (((blook_random[i] / 3) * 16) + 14);
            int minx = ((blook_random[i] / 3) * 16) + 2;
            int maxy = (((blook_random[i] % 3) * 16) + 14);
            int miny = ((blook_random[i] % 3) * 16) + 2;
            int is;
            int js;
            int im;
            int jm;
            for (int j = minx; j < (maxx + 1); j++)
            {
                for (int k = miny; k < (maxy + 1); k++)
                {
                    if (naghshe[j][k] == '+')
                    {
                        is = j;
                        js = k;
                    }
                }
            }
            maxx = (((blook_random[i + 1] / 3) * 16) + 14);
            minx = ((blook_random[i + 1] / 3) * 16) + 2;
            maxy = (((blook_random[i + 1] % 3) * 16) + 14);
            miny = ((blook_random[i + 1] % 3) * 16) + 2;
            for (int j = minx; j < (maxx + 1); j++)
            {
                for (int k = miny; k < (maxy + 1); k++)
                {
                    if (naghshe[j][k] == '+')
                    {
                        im = j;
                        jm = k;
                    }
                }
            }
            // printf("%d %d %d %d %d %d",is,js,im,jm,blook_random[i],blook_random[i+1]);
            rahro_kesh(is, js, im, jm, naghshe, blook_random[i], blook_random[i + 1]);
        }
    }
    goshe_kesh(naghshe);
}
int baghal_shomar(char naghshe[49][49], int i, int j)
{
    int shomar = 0;
    if (naghshe[i + 1][j] == '#')
    {
        shomar += 1;
    }
    if (naghshe[i - 1][j] == '#')
    {
        shomar += 1;
    }
    if (naghshe[i][j + 1] == '#')
    {
        shomar += 1;
    }
    if (naghshe[i][j - 1] == '#')
    {
        shomar += 1;
    }
    return shomar;
}
void rahro_hazf(char naghshe[49][49], int i, int j)
{
    if (baghal_shomar(naghshe, i, j) > 1 && naghshe[i][j] == '@')
    {
        return;
    }
    if (naghshe[i + 1][j] == '#')
    {
        if (baghal_shomar(naghshe, i + 1, j) < 2)
        {
            naghshe[i + 1][j] = ' ';
            rahro_hazf(naghshe, i + 1, j);
        }
    }
    if (naghshe[i - 1][j] == '#')
    {
        if (baghal_shomar(naghshe, i - 1, j) < 2)
        {
            naghshe[i - 1][j] = ' ';
            rahro_hazf(naghshe, i - 1, j);
        }
    }
    if (naghshe[i][j + 1] == '#')
    {
        if (baghal_shomar(naghshe, i, j + 1) < 2)
        {
            naghshe[i][j + 1] = ' ';
            rahro_hazf(naghshe, i, j + 1);
        }
    }
    if (naghshe[i][j - 1] == '#')
    {
        if (baghal_shomar(naghshe, i, j - 1) < 2)
        {
            naghshe[i][j - 1] = ' ';
            rahro_hazf(naghshe, i, j - 1);
        }
    }
}
int object_picker(char item, int row, int col, int tabaghe)
{
    if (item == 'G' || item == 'g')
    {
        gold += map_gold[tabaghe][row][col];
        return 1;
    }
    if (item == 'F')
    {
        if (foods_count == 5)
        {
            return 0;
        }
        int no_ghaza = rand() % 4;
        if (no_ghaza == 0)
        {
            strcpy(inv_food[foods_count], "kobide makhsos ba noon va pyaz va dogh mahsham");
        }
        if (no_ghaza == 1)
        {
            strcpy(inv_food[foods_count], "bomb mehran");
        }
        if (no_ghaza == 2)
        {
            strcpy(inv_food[foods_count], "gheime nazry");
        }
        if (no_ghaza == 3)
        {
            strcpy(inv_food[foods_count], "nimro");
        }
        foods_count += 1;
        return 1;
    }
    if (item == 'T')
    {
        if (telesm_count == 9)
        {
            return 0;
        }
        int no_telesm = rand() % 3;
        if (no_telesm == 0)
        {
            strcpy(inv_telesm[telesm_count], "Health talisman");
        }
        if (no_telesm == 1)
        {
            strcpy(inv_telesm[telesm_count], "Speed talisman");
        }
        if (no_telesm == 2)
        {
            strcpy(inv_telesm[telesm_count], "Damage talisman");
        }
        telesm_count += 1;
        return 1;
    }
    if (item == '2')
    {
        dagger += 10;
        return 1;
    }
    if (item == '3')
    {
        magik_wand += 8;
        return 1;
    }
    if (item == '4')
    {
        normal_arrow += 20;
        return 1;
    }
    if (item == '5')
    {
        if (sword == 1)
        {
            return 0;
        }
        else
        {
            sword += 1;
            return 1;
        }
    }
    if (item == '9')
    {
        normal_arrow += 1;
        return 1;
    }
    if (item == '8')
    {
        magik_wand += 1;
        return 1;
    }
    if (item == '7')
    {
        dagger += 1;
        return 1;
    }
    return 0;
}
int chech_shadabi(int tabaghe)
{
    if ((steps % 15) == 4 && tabaghe == 5)
    {
        hp -= 2;
        shadabi -= 2;
        return 1;
    }
    if ((steps % 10) == 0 && shadabi > 70 && tabaghe < 4)
    {
        if (hp < 100)
        {
            hp += 3;
        }
        if (hp > 100)
        {
            hp = 100;
        }
    }
    if (shadabi < 1)
    {
        return 2;
    }
    if ((steps % 30) == 11)
    {

        shadabi -= 3;
        if ((shadabi < 60) && (shadabi > 40))
        {
            mvprintw(1, 0, "i'm feeling some headache. i think we should eat something.\n");
            refresh();
            char chert = getch();
            while (chert != ' ')
            {
                chert = getch();
            }
            hp -= 2;
        }
        else if (shadabi <= 40 && shadabi > 20)
        {
            mvprintw(1, 0, "i don't feel so good. pleas let's rest and eat.\n");
            refresh();
            char chert = getch();
            while (chert != ' ')
            {
                chert = getch();
            }
            hp -= 2;
            if ((rand() % 3) == 1)
            {
                return 1;
            }
        }
        else if (shadabi <= 20 && shadabi > 0)
        {
            mvprintw(1, 0, "I feel like I can't walk anymore. I think we've reached the end of the line.\n");
            refresh();
            char chert = getch();
            while (chert != ' ')
            {
                chert = getch();
            }
            hp -= 3;
            if ((rand() % 2) == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}
void entekhab_aslahe()
{
    printw("You dont have any wepeans in your hand. pick one(use first letter to pick)\n");
    char ans = getch();
    int tedad = 0;
    if (ans == 'd')
    {
        tedad = dagger;
    }
    if (ans == 'm')
    {
        tedad = mance;
    }
    if (ans == 'a')
    {
        tedad = normal_arrow;
    }
    if (ans == 's')
    {
        tedad = sword;
    }
    if (ans == 'w')
    {
        tedad = magik_wand;
    }
    while ((ans != 'd' && ans != 'm' && ans != 'a' && ans != 's' && ans != 'w') || (tedad == 0))
    {
        printw("choose corectly\n");
        ans = getch();
        if (ans == 'd')
        {
            tedad = dagger;
        }
        if (ans == 'm')
        {
            tedad = mance;
        }
        if (ans == 'a')
        {
            tedad = normal_arrow;
        }
        if (ans == 's')
        {
            tedad = sword;
        }
        if (ans == 'w')
        {
            tedad = magik_wand;
        }
    }
    if (ans == 'd')
    {
        wepean_pish = 2;
    }
    if (ans == 'm')
    {
        wepean_pish = 1;
    }
    if (ans == 'a')
    {
        wepean_pish = 4;
        ;
    }
    if (ans == 's')
    {
        wepean_pish = 5;
    }
    if (ans == 'w')
    {
        wepean_pish = 3;
    }
}
void harekat(int row, int col, int tabaghe, char ghabli)
{
    noecho();
    check_monster_health();
    if (check_victory() == 1 && tabaghe == 4)
    {
        clear();
        mvprintw(27, 100, "you won!!!!");
        char chert = getch();
        while (chert != ' ')
        {
            chert = getch();
        }
        save_end();
        return;
    }
    print_board(tabaghe, row, col);
    char jahat = getch();
    while (jahat != ' ' && jahat != 'i' && jahat != '8' && jahat != '2' && jahat != '4' && jahat != '6' && jahat != 'e' && jahat != '>' && jahat != '<' && jahat != 'm' && jahat != '7' && jahat != '9' && jahat != '1' && jahat != '3' && jahat != 't' && jahat != 's' && jahat != 'S')
    {
        jahat = getch();
    }
    if (jahat == ' ')
    {
        if (wepean_pish == 0)
        {
            mvprintw(1, 0, "You don't have any weapon in your hands. pick one with 'i'\n");
            char chert = getch();
            while (chert != ' ')
            {
                chert = getch();
            }
        }
        else
        {
            int ans = 0;
            for (int i = 0; i < enemy_count; i++)
            {
                if (row - doshman[i].row < 2 && row - doshman[i].row > -2 && doshman[i].col - col > -2 && doshman[i].col - col < 2)
                {
                    ans = 1;
                    break;
                }
            }
            if (wepean_pish == 2 || wepean_pish == 3 || wepean_pish == 4)
            {
                ans = 1;
            }
            if (ans == 0)
            {
                mvprintw(1, 0, "Who are you killing? Have you gone crazy?\n");
                char ans = getch();
                while (ans != ' ')
                {
                    ans = getch();
                }
                harekat_monster(row, col, tabaghe);
            }
            else
            {
                if (wepean_pish == 1)
                {
                    int x = rand() % 12;
                    if (x == 7)
                    {
                        mvprintw(1, 0, "wow!!!!!!!your hit killed the enemy in just one hit.\n");
                        char ans = getch();
                        while (ans != ' ')
                        {
                            ans = getch();
                        }
                        for (int i = 0; i < enemy_count; i++)
                        {
                            int row1 = doshman[i].row;
                            int col1 = doshman[i].col;
                            if ((row - row1 == 1 && (col - col1 == 0 || (col - col1) == 1 || (col1 - col) == 1)) || (row - row1 == -1 && (col - col1 == 0 || (col - col1) == 1 || (col1 - col) == 1)) || (row1 - row == 0 && ((col - col1) == 1 || (col1 - col) == 1)))
                            {
                                doshman[i].health = -1;
                            }
                        }
                    }
                    if (x > -1 && x < 7)
                    {
                        mvprintw(1, 0, "you dealt a good blow to the enemy\n");
                        char ans = getch();
                        while (ans != ' ')
                        {
                            ans = getch();
                        }
                        for (int i = 0; i < enemy_count; i++)
                        {
                            int row1 = doshman[i].row;
                            int col1 = doshman[i].col;
                            if ((row - row1 == 1 && (col - col1 == 0 || (col - col1) == 1 || (col1 - col) == 1)) || (row - row1 == -1 && (col - col1 == 0 || (col - col1) == 1 || (col1 - col) == 1)) || (row1 - row == 0 && ((col - col1) == 1 || (col1 - col) == 1)))
                            {
                                if (asar_telesm_damage > 0)
                                {
                                    asar_telesm_damage -= 1;
                                    doshman[i].health -= 10;
                                }
                                else
                                {
                                    doshman[i].health -= 5;
                                }
                            }
                        }
                    }
                    else
                    {
                        int x = rand() % 3;
                        if (x == 0)
                        {
                            mvprintw(1, 0, "Shame on you. Ehsan made this game for you to play like this? you missed again.\n");
                        }
                        if (x == 1)
                        {
                            mvprintw(1, 0, "That blow was very simple. how could you miss that????\n");
                        }
                        if (x == 2)
                        {
                            mvprintw(1, 0, "Do you want to kill them or what?\n");
                        }
                        char ans = getch();
                        while (ans != ' ')
                        {
                            ans = getch();
                        }
                    }
                    check_monster_health();
                    damage_monster(row, col, tabaghe);
                    harekat_monster(row, col, tabaghe);
                }
                if (wepean_pish == 5)
                {
                    int x = rand() % 12;
                    if (x == 7)
                    {
                        mvprintw(1, 0, "wow!!!!!!!your hit killed the enemy in just one hit.\n");
                        char ans = getch();
                        while (ans != ' ')
                        {
                            ans = getch();
                        }
                        for (int i = 0; i < enemy_count; i++)
                        {
                            int row1 = doshman[i].row;
                            int col1 = doshman[i].col;
                            if ((row - row1 == 1 && (col - col1 == 0 || (col - col1) == 1 || (col1 - col) == 1)) || (row - row1 == -1 && (col - col1 == 0 || (col - col1) == 1 || (col1 - col) == 1)) || (row1 - row == 0 && ((col - col1) == 1 || (col1 - col) == 1)))
                            {
                                doshman[i].health = -1;
                            }
                        }
                    }
                    if (x > -1 && x < 7)
                    {
                        mvprintw(1, 0, "you dealt a good blow to the enemy\n");
                        char ans = getch();
                        while (ans != ' ')
                        {
                            ans = getch();
                        }
                        for (int i = 0; i < enemy_count; i++)
                        {
                            int row1 = doshman[i].row;
                            int col1 = doshman[i].col;
                            if ((row - row1 == 1 && (col - col1 == 0 || (col - col1) == 1 || (col1 - col) == 1)) || (row - row1 == -1 && (col - col1 == 0 || (col - col1) == 1 || (col1 - col) == 1)) || (row1 - row == 0 && ((col - col1) == 1 || (col1 - col) == 1)))
                            {
                                if (asar_telesm_damage > 0)
                                {
                                    asar_telesm_damage -= 1;
                                    doshman[i].health -= 20;
                                }
                                else
                                {
                                    doshman[i].health -= 10;
                                }
                            }
                        }
                    }
                    else
                    {
                        int x = rand() % 3;
                        if (x == 0)
                        {
                            mvprintw(1, 0, "Shame on you. Ehsan made this game for you to play like this? you missed again.\n");
                        }
                        if (x == 1)
                        {
                            mvprintw(1, 0, "That blow was very simple. how could you miss that????\n");
                        }
                        if (x == 2)
                        {
                            mvprintw(1, 0, "Do you want to kill them or what?\n");
                        }
                        char ans = getch();
                        while (ans != ' ')
                        {
                            ans = getch();
                        }
                    }
                    check_monster_health();
                    damage_monster(row, col, tabaghe);
                    harekat_monster(row, col, tabaghe);
                }
                if (wepean_pish == 2)
                {
                    char hadaf = getch();
                    while (hadaf != '1' && hadaf != '2' && hadaf != '3' && hadaf != '4' && hadaf != '6' && hadaf != '7' && hadaf != '8' && hadaf != '9')
                    {
                        hadaf = getch();
                    }
                    int hit = 0;
                    if (hadaf == '6')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if ((map[tabaghe][row][col + i] == 'I' || map[tabaghe][row][col + i] == 'f' || map[tabaghe][row][col + i] == 'd' || map[tabaghe][row][col + i] == 'S' || map[tabaghe][row][col + i] == 'u') && hit != 1)
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row)
                                            {
                                                if (doshman[j].col == (col + i))
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 24;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 12;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    dagger -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row][col + i] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row][col + i] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row][col + i - 1] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '2')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row + i][col] == 'I' || map[tabaghe][row + i][col] == 'f' || map[tabaghe][row + i][col] == 'd' || map[tabaghe][row + i][col] == 'S' || map[tabaghe][row + i][col] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row + i)
                                            {
                                                if (doshman[j].col == col)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 24;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 12;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    dagger -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row + i][col] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row + i][col] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row + i - 1][col] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '8')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row - i][col] == 'I' || map[tabaghe][row - i][col] == 'f' || map[tabaghe][row - i][col] == 'd' || map[tabaghe][row - i][col] == 'S' || map[tabaghe][row - i][col] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row - i)
                                            {
                                                if (doshman[j].col == col)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 24;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 12;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    dagger -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row - i][col] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row - i][col] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row - i + 1][col] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '4')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row][col - i] == 'I' || map[tabaghe][row][col - i] == 'f' || map[tabaghe][row][col - i] == 'd' || map[tabaghe][row][col - i] == 'S' || map[tabaghe][row][col - i] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row)
                                            {
                                                if (doshman[j].col == col - i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 24;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 12;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    dagger -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row][col - i] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row][col - i] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row][col - i + 1] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '7')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row][col - i] == 'I' || map[tabaghe][row][col - i] == 'f' || map[tabaghe][row][col - i] == 'd' || map[tabaghe][row][col - i] == 'S' || map[tabaghe][row][col - i] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row - i)
                                            {
                                                if (doshman[j].col == col - i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 24;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 12;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    dagger -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row - i][col - i] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row - i][col - i] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row - i + 1][col - i + 1] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '9')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row - i][col + i] == 'I' || map[tabaghe][row - i][col + i] == 'f' || map[tabaghe][row - i][col + i] == 'd' || map[tabaghe][row - i][col + i] == 'S' || map[tabaghe][row - i][col + i] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row - i)
                                            {
                                                if (doshman[j].col == col + i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 24;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 12;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    dagger -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row - i][col + i] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row - i][col + i] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row - i + 1][col + i - 1] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '1')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if ((map[tabaghe][row + i][col - i] == 'I' || map[tabaghe][row + i][col - i] == 'f' || map[tabaghe][row + i][col - i] == 'd' || map[tabaghe][row + i][col - i] == 'S' || map[tabaghe][row + i][col - i] == 'u') && hit != 1)
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row + i)
                                            {
                                                if (doshman[j].col == col - i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 24;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 12;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    dagger -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row + i][col - i] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row + i][col - i] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row + i - 1][col - i + 1] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '3')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row + i][col + i] == 'I' || map[tabaghe][row + i][col + i] == 'f' || map[tabaghe][row + i][col + i] == 'd' || map[tabaghe][row + i][col + i] == 'S' || map[tabaghe][row + i][col + i] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row + i)
                                            {
                                                if (doshman[j].col == col + i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 24;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 12;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    dagger -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row + i][col + i] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row + i][col + i] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row + i - 1][col + i - 1] = '7';
                                    dagger -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (dagger == 0)
                    {
                        wepean_pish = 0;
                    }
                    check_monster_health();
                    damage_monster(row, col, tabaghe);
                    harekat_monster(row, col, tabaghe);
                }
                if (wepean_pish == 3)
                {
                    char hadaf = getch();
                    while (hadaf != '1' && hadaf != '2' && hadaf != '3' && hadaf != '4' && hadaf != '6' && hadaf != '7' && hadaf != '8' && hadaf != '9')
                    {
                        hadaf = getch();
                    }
                    int hit = 0;
                    if (hadaf == '6')
                    {
                        for (int i = 1; i < 11; i++)
                        {
                            if ((map[tabaghe][row][col + i] == 'I' || map[tabaghe][row][col + i] == 'f' || map[tabaghe][row][col + i] == 'd' || map[tabaghe][row][col + i] == 'S' || map[tabaghe][row][col + i] == 'u') && hit != 1)
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row)
                                            {
                                                if (doshman[j].col == col + i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 30;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 15;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    doshman[j].ability_to_walk = 0;
                                                    magik_wand -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row][col + i] == '.' && hit != 1)
                            {
                                if (i == 10)
                                {
                                    map[tabaghe][row][col + i] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row][col + i - 1] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '2')
                    {
                        for (int i = 1; i < 11; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row + i][col] == 'I' || map[tabaghe][row + i][col] == 'f' || map[tabaghe][row + i][col] == 'd' || map[tabaghe][row + i][col] == 'S' || map[tabaghe][row + i][col] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row + i)
                                            {
                                                if (doshman[j].col == col)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 30;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 15;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    doshman[j].ability_to_walk = 0;
                                                    magik_wand -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row + i][col] == '.' && hit != 1)
                            {
                                if (i == 10)
                                {
                                    map[tabaghe][row + i][col] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row + i - 1][col] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '8')
                    {
                        for (int i = 1; i < 11; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row - i][col] == 'I' || map[tabaghe][row - i][col] == 'f' || map[tabaghe][row - i][col] == 'd' || map[tabaghe][row - i][col] == 'S' || map[tabaghe][row - i][col] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row - i)
                                            {
                                                if (doshman[j].col == col)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 30;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 15;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    doshman[j].ability_to_walk = 0;
                                                    magik_wand -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row - i][col] == '.' && hit != 1)
                            {
                                if (i == 10)
                                {
                                    map[tabaghe][row - i][col] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row - i + 1][col] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '4')
                    {
                        for (int i = 1; i < 11; i++)
                        {
                            if ((map[tabaghe][row][col - i] == 'I' || map[tabaghe][row][col - i] == 'f' || map[tabaghe][row][col - i] == 'd' || map[tabaghe][row][col - i] == 'S' || map[tabaghe][row][col - i] == 'u') && hit != 1)
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row)
                                            {
                                                if (doshman[j].col == col - i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 30;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 15;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    doshman[j].ability_to_walk = 0;
                                                    magik_wand -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row][col - i] == '.' && hit != 1)
                            {
                                if (i == 10)
                                {
                                    map[tabaghe][row][col - i] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row][col - i + 1] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '7')
                    {
                        for (int i = 1; i < 11; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row][col - i] == 'I' || map[tabaghe][row][col - i] == 'f' || map[tabaghe][row][col - i] == 'd' || map[tabaghe][row][col - i] == 'S' || map[tabaghe][row][col - i] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row - i)
                                            {
                                                if (doshman[j].col == col - i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 30;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 15;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    doshman[j].ability_to_walk = 0;
                                                    magik_wand -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row - i][col - i] == '.' && hit != 1)
                            {
                                if (i == 10)
                                {
                                    map[tabaghe][row - i][col - i] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row - i + 1][col - i + 1] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '9')
                    {
                        for (int i = 1; i < 11; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row - i][col + i] == 'I' || map[tabaghe][row - i][col + i] == 'f' || map[tabaghe][row - i][col + i] == 'd' || map[tabaghe][row - i][col + i] == 'S' || map[tabaghe][row - i][col + i] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row - i)
                                            {
                                                if (doshman[j].col == col + i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 30;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 15;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    doshman[j].ability_to_walk = 0;
                                                    magik_wand -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row - i][col + i] == '.' && hit != 1)
                            {
                                if (i == 10)
                                {
                                    map[tabaghe][row - i][col + i] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row - i + 1][col + i - 1] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '1')
                    {
                        for (int i = 1; i < 11; i++)
                        {
                            if ((map[tabaghe][row + i][col - i] == 'I' || map[tabaghe][row + i][col - i] == 'f' || map[tabaghe][row + i][col - i] == 'd' || map[tabaghe][row + i][col - i] == 'S' || map[tabaghe][row + i][col - i] == 'u') && hit != 1)
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row + i)
                                            {
                                                if (doshman[j].col == col - i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 30;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 15;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    doshman[j].ability_to_walk = 0;
                                                    magik_wand -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row + i][col - i] == '.' && hit != 1)
                            {
                                if (i == 10)
                                {
                                    map[tabaghe][row + i][col - i] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row + i - 1][col - i + 1] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '3')
                    {
                        for (int i = 1; i < 11; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row + i][col + i] == 'I' || map[tabaghe][row + i][col + i] == 'f' || map[tabaghe][row + i][col + i] == 'd' || map[tabaghe][row + i][col + i] == 'S' || map[tabaghe][row + i][col + i] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row + i)
                                            {
                                                if (doshman[j].col == col + i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 30;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 15;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    doshman[j].ability_to_walk = 0;
                                                    magik_wand -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row + i][col + i] == '.' && hit != 1)
                            {
                                if (i == 10)
                                {
                                    map[tabaghe][row + i][col + i] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row + i - 1][col + i - 1] = '8';
                                    magik_wand -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (magik_wand == 0)
                    {
                        wepean_pish = 0;
                    }
                    check_monster_health();
                    damage_monster(row, col, tabaghe);
                    harekat_monster(row, col, tabaghe);
                }
                if (wepean_pish == 4)
                {
                    char hadaf = getch();
                    while (hadaf != '1' && hadaf != '2' && hadaf != '3' && hadaf != '4' && hadaf != '6' && hadaf != '7' && hadaf != '8' && hadaf != '9')
                    {
                        hadaf = getch();
                    }
                    int hit = 0;
                    if (hadaf == '6')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if ((map[tabaghe][row][col + i] == 'I' || map[tabaghe][row][col + i] == 'f' || map[tabaghe][row][col + i] == 'd' || map[tabaghe][row][col + i] == 'S' || map[tabaghe][row][col + i] == 'u') && hit != 1)
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row)
                                            {
                                                if (doshman[j].col == (col + i))
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 10;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 5;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    normal_arrow -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row][col + i] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row][col + i] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row][col + i - 1] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '2')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row + i][col] == 'I' || map[tabaghe][row + i][col] == 'f' || map[tabaghe][row + i][col] == 'd' || map[tabaghe][row + i][col] == 'S' || map[tabaghe][row + i][col] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row + i)
                                            {
                                                if (doshman[j].col == col)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 10;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 5;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    normal_arrow -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row + i][col] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row + i][col] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row + i - 1][col] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '8')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if ((map[tabaghe][row - i][col] == 'I' || map[tabaghe][row - i][col] == 'f' || map[tabaghe][row - i][col] == 'd' || map[tabaghe][row - i][col] == 'S' || map[tabaghe][row - i][col] == 'u') && hit != 1)
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row - i)
                                            {
                                                if (doshman[j].col == col)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 10;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 5;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    normal_arrow -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row - i][col] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row - i][col] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row - i + 1][col] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '4')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row][col - i] == 'I' || map[tabaghe][row][col - i] == 'f' || map[tabaghe][row][col - i] == 'd' || map[tabaghe][row][col - i] == 'S' || map[tabaghe][row][col - i] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row)
                                            {
                                                if (doshman[j].col == col - i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 10;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 5;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    normal_arrow -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row][col - i] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row][col - i] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row][col - i + 1] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '7')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row][col - i] == 'I' || map[tabaghe][row][col - i] == 'f' || map[tabaghe][row][col - i] == 'd' || map[tabaghe][row][col - i] == 'S' || map[tabaghe][row][col - i] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row - i)
                                            {
                                                if (doshman[j].col == col - i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 10;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 5;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    normal_arrow -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row - i][col - i] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row - i][col - i] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row - i + 1][col - i + 1] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '9')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if ((map[tabaghe][row - i][col + i] == 'I' || map[tabaghe][row - i][col + i] == 'f' || map[tabaghe][row - i][col + i] == 'd' || map[tabaghe][row - i][col + i] == 'S' || map[tabaghe][row - i][col + i] == 'u') && hit != 1)
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row - i)
                                            {
                                                if (doshman[j].col == col + i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 10;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 5;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    normal_arrow -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row - i][col + i] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row - i][col + i] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row - i + 1][col + i - 1] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '1')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if (hit != 1 && (map[tabaghe][row + i][col - i] == 'I' || map[tabaghe][row + i][col - i] == 'f' || map[tabaghe][row + i][col - i] == 'd' || map[tabaghe][row + i][col - i] == 'S' || map[tabaghe][row + i][col - i] == 'u'))
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row + i)
                                            {
                                                if (doshman[j].col == col - i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 10;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 5;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    normal_arrow -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row + i][col - i] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row + i][col - i] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row + i - 1][col - i + 1] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (hadaf == '3')
                    {
                        for (int i = 1; i < 6; i++)
                        {
                            if ((map[tabaghe][row + i][col + i] == 'I' || map[tabaghe][row + i][col + i] == 'f' || map[tabaghe][row + i][col + i] == 'd' || map[tabaghe][row + i][col + i] == 'S' || map[tabaghe][row + i][col + i] == 'u') && hit != 1)
                            {
                                for (int j = 0; j < enemy_count; j++)
                                {
                                    if (doshman[j].health > 0)
                                    {
                                        if (doshman[j].tabaghe == tabaghe)
                                        {
                                            if (doshman[j].row == row + i)
                                            {
                                                if (doshman[j].col == col + i)
                                                {
                                                    if (asar_telesm_damage > 0)
                                                    {
                                                        doshman[j].health -= 10;
                                                        asar_telesm_damage -= 1;
                                                    }
                                                    else
                                                    {
                                                        doshman[j].health -= 5;
                                                    }
                                                    doshman[j].chase_count = 0;
                                                    normal_arrow -= 1;
                                                    mvprintw(1, 0, "you did a good throw to the enemy\n");
                                                    char chert = getch();
                                                    while (chert != ' ')
                                                    {
                                                        chert = getch();
                                                    }
                                                    hit = 1;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else if (map[tabaghe][row + i][col + i] == '.' && hit != 1)
                            {
                                if (i == 5)
                                {
                                    map[tabaghe][row + i][col + i] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                            else if (hit != 1)
                            {
                                if (i == 1)
                                {
                                    break;
                                }
                                else
                                {
                                    map[tabaghe][row + i - 1][col + i - 1] = '9';
                                    normal_arrow -= 1;
                                    break;
                                }
                            }
                        }
                    }
                    if (normal_arrow == 0)
                    {
                        wepean_pish = 0;
                    }
                    check_monster_health();
                    damage_monster(row, col, tabaghe);
                    harekat_monster(row, col, tabaghe);
                }
            }
        }
    }
    if (jahat == 'i')
    {
        clear();
        mvprintw(1, 0, "Long-range:\n");
        mvprintw(2, 0, "name                amount             range               damage\n");
        mvprintw(3, 0, "Dagger              %4d                5                   12\n", dagger);
        mvprintw(4, 0, "Magic Wand          %4d                10                  15\n", magik_wand);
        mvprintw(5, 0, "Normal Arrow        %4d                5                   5\n", normal_arrow);
        mvprintw(6, 0, "Close-range:\n");
        mvprintw(7, 0, "name                amount             damage\n");
        mvprintw(8, 0, "Sword               %d                 10\n", sword);
        mvprintw(9, 0, "Mace                1                 5\n");
        if (wepean_pish == 0)
        {
            entekhab_aslahe();
        }
        else
        {
            if (wepean_pish == 1)
            {
                printw("your default weapon is mace. if you want to change it press 'm' and then chose what you want\n");
                char ans = getch();
                if (ans == 'm')
                {
                    entekhab_aslahe();
                }
            }
            if (wepean_pish == 2)
            {
                printw("your default weapon is Dagger. if you want to change it press 'd' and then chose what you want\n");
                char ans = getch();
                if (ans == 'd')
                {
                    entekhab_aslahe();
                }
            }
            if (wepean_pish == 3)
            {
                printw("your default weapon is Magic Wand. if you want to change it press 'w' and then chose what you want\n");
                char ans = getch();
                if (ans == 'w')
                {
                    entekhab_aslahe();
                }
            }
            if (wepean_pish == 4)
            {
                printw("your default weapon is Normall Arrow. if you want to change it press 'a' and then chose what you want\n");
                char ans = getch();
                if (ans == 'a')
                {
                    entekhab_aslahe();
                }
            }
            if (wepean_pish == 5)
            {
                printw("your default weapon is sword. if you want to change it press 's' and then chose what you want\n");
                char ans = getch();
                if (ans == 's')
                {
                    entekhab_aslahe();
                }
            }
        }
    }
    if (jahat == '7')
    {
        if (asar_telesm_health > 0)
        {
            asar_telesm_health -= 1;
            hp += 4;
            if (hp > 100)
            {
                hp = 100;
            }
        }
        if (asar_telesm_damage > 0)
        {
            asar_telesm_damage -= 1;
        }
        char badi;
        if (asar_telesm_speed > 0)
        {
            badi = map[tabaghe][row - 2][col - 2];
            if (badi == '?')
            {
                map[tabaghe][row][col] = '.';
                harekat(15, 15, 5, '.');
                return;
            }
            if (badi == '+' && ghabli == '#')
            {
                if (map[tabaghe][row - 2][col - 3] == '.')
                {
                    check_seen(row - 2, col - 3, tabaghe, '+');
                }
                if (map[tabaghe][row - 3][col - 2] == '.')
                {
                    check_seen(row - 3, col - 2, tabaghe, '+');
                }
            }
            if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
            {
                damage_monster(row, col, tabaghe);
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                steps += 1;
                if (object_picker(badi, row - 2, col - 2, tabaghe) == 1)
                {
                    map[tabaghe][row - 2][col - 2] = '.';
                    badi = '.';
                }
                int mizan_shadabi = chech_shadabi(tabaghe);
                if (mizan_shadabi == 1)
                {
                    if (hp < 1 || shadabi < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                }
                if (mizan_shadabi == 2)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                if (badi == 'E')
                {
                    map[tabaghe][row][col] = ghabli;
                    start_boss();
                    return;
                }
                if (badi == 'r' || badi == 'R')
                {
                    trap(badi);
                    if (hp < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                    map[tabaghe][row - 2][col - 2] = '^';
                    badi = '^';
                }
                map[tabaghe][row - 2][col - 2] = 'N';
                map[tabaghe][row][col] = ghabli;
                asar_telesm_speed -= 1;
                harekat_monster(row - 2, col - 2, tabaghe);
                harekat(row - 2, (col - 2), tabaghe, badi);
                return;
            }
        }
        badi = map[tabaghe][row - 1][col - 1];
        if (badi == '?')
        {
            map[tabaghe][row][col] = '.';
            harekat(15, 15, 5, '.');
            return;
        }
        if (badi == '+' && ghabli == '#')
        {
            if (map[tabaghe][row - 1][col - 2] == '.')
            {
                check_seen(row - 1, col - 2, tabaghe, '+');
            }
            if (map[tabaghe][row - 2][col - 1] == '.')
            {
                check_seen(row - 2, col - 1, tabaghe, '+');
            }
        }
        if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
        {
            damage_monster(row, col, tabaghe);
            if (hp < 1 || shadabi < 1)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();
                return;
            }

            steps += 1;
            if (object_picker(badi, row - 1, col - 1, tabaghe) == 1)
            {
                map[tabaghe][row - 1][col - 1] = '.';
                badi = '.';
            }
            int mizan_shadabi = chech_shadabi(tabaghe);
            if (mizan_shadabi == 1)
            {
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }

                    start_menu();
                    return;
                }
            }
            if (mizan_shadabi == 2)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();
                return;
            }
            if (badi == 'E')
            {
                map[tabaghe][row][col] = ghabli;
                start_boss();
                return;
            }
            if (badi == 'r' || badi == 'R')
            {
                trap(badi);
                if (hp < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                map[tabaghe][row - 1][col - 1] = '^';
                badi = '^';
            }
            map[tabaghe][row - 1][col - 1] = 'N';
            map[tabaghe][row][col] = ghabli;
            harekat_monster(row - 1, col - 1, tabaghe);
            harekat(row - 1, (col - 1), tabaghe, badi);
            return;
        }
        else
        {
            harekat(row, col, tabaghe, ghabli);
            return;
        }
    }
    if (jahat == '1')
    {
        if (asar_telesm_health > 0)
        {
            asar_telesm_health -= 1;
            hp += 4;
            if (hp > 100)
            {
                hp = 100;
            }
        }
        if (asar_telesm_damage > 0)
        {
            asar_telesm_damage -= 1;
        }
        char badi;
        if (asar_telesm_speed > 0)
        {
            badi = map[tabaghe][row + 2][col - 2];
            if (badi == '?')
            {
                map[tabaghe][row][col] = '.';
                harekat(15, 15, 5, '.');
                return;
            }
            if (badi == '+' && ghabli == '#')
            {
                if (map[tabaghe][row + 2][col - 3] == '.')
                {
                    check_seen(row + 2, col - 3, tabaghe, '+');
                }
                if (map[tabaghe][row + 3][col - 2] == '.')
                {
                    check_seen(row + 3, col - 2, tabaghe, '+');
                }
            }
            if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
            {
                damage_monster(row, col, tabaghe);
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                steps += 1;
                if (object_picker(badi, row + 2, col - 2, tabaghe) == 1)
                {
                    map[tabaghe][row + 2][col - 2] = '.';
                    badi = '.';
                }
                int mizan_shadabi = chech_shadabi(tabaghe);
                if (mizan_shadabi == 1)
                {
                    if (hp < 1 || shadabi < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                }
                if (mizan_shadabi == 2)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                if (badi == 'E')
                {
                    map[tabaghe][row][col] = ghabli;
                    start_boss();
                    return;
                }
                if (badi == 'r' || badi == 'R')
                {
                    trap(badi);
                    if (hp < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                    map[tabaghe][row + 2][col - 2] = '^';
                    badi = '^';
                }
                map[tabaghe][row + 2][col - 2] = 'N';
                map[tabaghe][row][col] = ghabli;
                harekat_monster(row + 2, col - 2, tabaghe);
                asar_telesm_speed -= 1;
                harekat(row + 2, (col - 2), tabaghe, badi);
                return;
            }
        }

        badi = map[tabaghe][row + 1][col - 1];
        if (badi == '?')
        {
            map[tabaghe][row][col] = '.';
            harekat(15, 15, 5, '.');
            return;
        }
        if (badi == '+' && ghabli == '#')
        {
            if (map[tabaghe][row + 1][col - 2] == '.')
            {
                check_seen(row + 1, col - 2, tabaghe, '+');
            }
            if (map[tabaghe][row + 2][col - 1] == '.')
            {
                check_seen(row + 2, col - 1, tabaghe, '+');
            }
        }
        if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
        {
            damage_monster(row, col, tabaghe);
            if (hp < 1 || shadabi < 1)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();
                return;
            }
            steps += 1;
            if (object_picker(badi, row + 1, col - 1, tabaghe) == 1)
            {
                map[tabaghe][row + 1][col - 1] = '.';
                badi = '.';
            }
            int mizan_shadabi = chech_shadabi(tabaghe);
            if (mizan_shadabi == 1)
            {
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
            }
            if (mizan_shadabi == 2)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();
                return;
            }
            if (badi == 'E')
            {
                map[tabaghe][row][col] = ghabli;
                start_boss();
                return;
            }
            if (badi == 'r' || badi == 'R')
            {
                trap(badi);
                if (hp < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                map[tabaghe][row + 1][col - 1] = '^';
                badi = '^';
            }
            map[tabaghe][row + 1][col - 1] = 'N';
            map[tabaghe][row][col] = ghabli;
            harekat_monster(row + 1, col - 1, tabaghe);
            harekat(row + 1, (col - 1), tabaghe, badi);
            return;
        }
        else
        {
            harekat(row, col, tabaghe, ghabli);
            return;
        }
    }
    if (jahat == '3')
    {
        if (asar_telesm_health > 0)
        {
            asar_telesm_health -= 1;
            hp += 4;
            if (hp > 100)
            {
                hp = 100;
            }
        }
        if (asar_telesm_damage > 0)
        {
            asar_telesm_damage -= 1;
        }
        char badi;
        if (asar_telesm_speed > 0)
        {
            badi = map[tabaghe][row + 2][col + 2];
            if (badi == '?')
            {
                map[tabaghe][row][col] = '.';
                harekat(15, 15, 5, '.');
                return;
            }
            if (badi == '+' && ghabli == '#')
            {
                if (map[tabaghe][row + 2][col + 3] == '.')
                {
                    check_seen(row + 2, col + 3, tabaghe, '+');
                }
                if (map[tabaghe][row + 3][col + 2] == '.')
                {
                    check_seen(row + 3, col + 2, tabaghe, '+');
                }
            }
            if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
            {
                damage_monster(row, col, tabaghe);
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();

                    return;
                }
                steps += 1;
                if (object_picker(badi, row + 2, col + 2, tabaghe) == 1)
                {
                    map[tabaghe][row + 2][col + 2] = '.';
                    badi = '.';
                }
                int mizan_shadabi = chech_shadabi(tabaghe);
                if (mizan_shadabi == 1)
                {
                    if (hp < 1 || shadabi < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                }
                if (mizan_shadabi == 2)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                if (badi == 'E')
                {
                    map[tabaghe][row][col] = ghabli;
                    start_boss();
                    return;
                }
                if (badi == 'r' || badi == 'R')
                {
                    trap(badi);
                    if (hp < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                    map[tabaghe][row + 2][col + 2] = '^';
                    badi = '^';
                }
                map[tabaghe][row + 2][col + 2] = 'N';
                map[tabaghe][row][col] = ghabli;
                asar_telesm_speed -= 1;
                harekat_monster(row + 2, col + 2, tabaghe);
                harekat(row + 2, (col + 2), tabaghe, badi);
                return;
            }
        }

        badi = map[tabaghe][row + 1][col + 1];
        if (badi == '?')
        {
            map[tabaghe][row][col] = '.';
            harekat(15, 15, 5, '.');
            return;
        }
        if (badi == '+' && ghabli == '#')
        {
            if (map[tabaghe][row + 1][col + 2] == '.')
            {
                check_seen(row + 1, col + 2, tabaghe, '+');
            }
            if (map[tabaghe][row + 2][col + 1] == '.')
            {
                check_seen(row + 2, col + 1, tabaghe, '+');
            }
        }
        if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
        {
            damage_monster(row, col, tabaghe);
            if (hp < 1 || shadabi < 1)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();

                return;
            }
            steps += 1;
            if (object_picker(badi, row + 1, col + 1, tabaghe) == 1)
            {
                map[tabaghe][row + 1][col + 1] = '.';
                badi = '.';
            }
            int mizan_shadabi = chech_shadabi(tabaghe);
            if (mizan_shadabi == 1)
            {
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
            }
            if (mizan_shadabi == 2)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();
                return;
            }
            if (badi == 'E')
            {
                map[tabaghe][row][col] = ghabli;
                start_boss();
                return;
            }
            if (badi == 'r' || badi == 'R')
            {
                trap(badi);
                if (hp < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                map[tabaghe][row + 1][col + 1] = '^';
                badi = '^';
            }
            map[tabaghe][row + 1][col + 1] = 'N';
            map[tabaghe][row][col] = ghabli;
            harekat_monster(row + 1, col + 1, tabaghe);
            harekat(row + 1, (col + 1), tabaghe, badi);
            return;
        }
        else
        {
            harekat(row, col, tabaghe, ghabli);
            return;
        }
    }
    if (jahat == '9')
    {
        if (asar_telesm_health > 0)
        {
            asar_telesm_health -= 1;
            hp += 4;
            if (hp > 100)
            {
                hp = 100;
            }
        }
        if (asar_telesm_damage > 0)
        {
            asar_telesm_damage -= 1;
        }
        char badi;
        if (asar_telesm_speed > 0)
        {
            badi = map[tabaghe][row - 2][col + 2];
            if (badi == '?')
            {
                map[tabaghe][row][col] = '.';
                harekat(15, 15, 5, '.');
                return;
            }
            if (badi == '+' && ghabli == '#')
            {
                if (map[tabaghe][row - 2][col + 3] == '.')
                {
                    check_seen(row - 2, col + 3, tabaghe, '+');
                }
                if (map[tabaghe][row - 3][col + 2] == '.')
                {
                    check_seen(row - 3, col + 2, tabaghe, '+');
                }
            }
            if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
            {
                damage_monster(row, col, tabaghe);
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();

                    return;
                }
                steps += 1;
                if (object_picker(badi, row - 2, col + 2, tabaghe) == 1)
                {
                    map[tabaghe][row - 2][col + 2] = '.';
                    badi = '.';
                }
                int mizan_shadabi = chech_shadabi(tabaghe);
                if (mizan_shadabi == 1)
                {
                    if (hp < 1 || shadabi < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                }
                if (mizan_shadabi == 2)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                if (badi == 'E')
                {
                    map[tabaghe][row][col] = ghabli;
                    start_boss();
                    return;
                }
                if (badi == 'r' || badi == 'R')
                {
                    trap(badi);
                    if (hp < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                    map[tabaghe][row - 2][col + 2] = '^';
                    badi = '^';
                }
                map[tabaghe][row - 2][col + 2] = 'N';
                map[tabaghe][row][col] = ghabli;
                harekat_monster(row - 2, col + 2, tabaghe);
                harekat(row - 2, (col + 2), tabaghe, badi);
                return;
            }
        }

        badi = map[tabaghe][row - 1][col + 1];
        if (badi == '?')
        {
            map[tabaghe][row][col] = '.';
            harekat(15, 15, 5, '.');
            return;
        }
        if (badi == '+' && ghabli == '#')
        {
            if (map[tabaghe][row - 1][col + 2] == '.')
            {
                check_seen(row - 1, col + 2, tabaghe, '+');
            }
            if (map[tabaghe][row - 2][col + 1] == '.')
            {
                check_seen(row - 2, col + 1, tabaghe, '+');
            }
        }
        if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
        {
            damage_monster(row, col, tabaghe);
            if (hp < 1 || shadabi < 1)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();

                return;
            }
            steps += 1;
            if (object_picker(badi, row - 1, col + 1, tabaghe) == 1)
            {
                map[tabaghe][row - 1][col + 1] = '.';
                badi = '.';
            }
            int mizan_shadabi = chech_shadabi(tabaghe);
            if (mizan_shadabi == 1)
            {
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
            }
            if (mizan_shadabi == 2)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();
                return;
            }
            if (badi == 'E')
            {
                map[tabaghe][row][col] = ghabli;
                start_boss();
                return;
            }
            if (badi == 'r' || badi == 'R')
            {
                trap(badi);
                if (hp < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                map[tabaghe][row - 1][col + 1] = '^';
                badi = '^';
            }
            map[tabaghe][row - 1][col + 1] = 'N';
            map[tabaghe][row][col] = ghabli;
            harekat_monster(row - 1, col + 1, tabaghe);
            harekat(row - 1, (col + 1), tabaghe, badi);
            return;
        }
        else
        {
            harekat(row, col, tabaghe, ghabli);
            return;
        }
    }
    if (jahat == '6')
    {
        if (asar_telesm_health > 0)
        {
            asar_telesm_health -= 1;
            hp += 4;
            if (hp > 100)
            {
                hp = 100;
            }
        }
        if (asar_telesm_damage > 0)
        {
            asar_telesm_damage -= 1;
        }
        char badi;
        if (asar_telesm_speed > 0)
        {
            badi = map[tabaghe][row][col + 2];
            if (badi == '?')
            {
                map[tabaghe][row][col] = '.';
                harekat(15, 15, 5, '.');
                return;
            }
            if (badi == '+' && map[tabaghe][row][col + 3] != '#')
            {
                check_seen(row, col + 3, tabaghe, '+');
            }
            if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
            {
                damage_monster(row, col, tabaghe);
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();

                    return;
                }
                steps += 1;
                if (object_picker(badi, row, col + 2, tabaghe) == 1)
                {
                    map[tabaghe][row][col + 2] = '.';
                    badi = '.';
                }
                int mizan_shadabi = chech_shadabi(tabaghe);
                if (mizan_shadabi == 1)
                {
                    if (hp < 1 || shadabi < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                }
                if (mizan_shadabi == 2)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                if (badi == 'E')
                {
                    map[tabaghe][row][col] = ghabli;
                    start_boss();
                    return;
                }
                if (badi == 'r' || badi == 'R')
                {
                    trap(badi);
                    if (hp < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                    map[tabaghe][row][col + 2] = '^';
                    badi = '^';
                }
                map[tabaghe][row][col + 2] = 'N';
                map[tabaghe][row][col] = ghabli;
                asar_telesm_speed -= 1;
                harekat_monster(row, col + 2, tabaghe);
                harekat(row, (col + 2), tabaghe, badi);
                return;
            }
            refresh();
        }

        badi = map[tabaghe][row][col + 1];
        if (badi == '?')
        {
            map[tabaghe][row][col] = '.';
            harekat(15, 15, 5, '.');
            return;
        }
        if (badi == '+' && map[tabaghe][row][col + 2] != '#')
        {
            check_seen(row, col + 2, tabaghe, '+');
        }
        if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
        {
            damage_monster(row, col, tabaghe);
            if (hp < 1 || shadabi < 1)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();

                return;
            }
            steps += 1;
            if (object_picker(badi, row, col + 1, tabaghe) == 1)
            {
                map[tabaghe][row][col + 1] = '.';
                badi = '.';
            }
            int mizan_shadabi = chech_shadabi(tabaghe);
            if (mizan_shadabi == 1)
            {
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
            }
            if (mizan_shadabi == 2)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();
                return;
            }
            if (badi == 'E')
            {
                map[tabaghe][row][col] = ghabli;
                start_boss();
                return;
            }
            if (badi == 'r' || badi == 'R')
            {
                trap(badi);
                if (hp < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                map[tabaghe][row][col + 1] = '^';
                badi = '^';
            }
            map[tabaghe][row][col + 1] = 'N';
            map[tabaghe][row][col] = ghabli;
            harekat_monster(row, col + 1, tabaghe);
            harekat(row, (col + 1), tabaghe, badi);
            return;
        }
        else
        {
            harekat(row, col, tabaghe, ghabli);
            return;
        }
        refresh();
    }
    if (jahat == '4')
    {
        if (asar_telesm_health > 0)
        {
            asar_telesm_health -= 1;
            hp += 4;
            if (hp > 100)
            {
                hp = 100;
            }
        }
        if (asar_telesm_damage > 0)
        {
            asar_telesm_damage -= 1;
        }
        char badi;
        if (asar_telesm_speed > 0)
        {
            badi = map[tabaghe][row][col - 2];
            if (badi == '?')
            {
                map[tabaghe][row][col] = '.';
                harekat(15, 15, 5, '.');
                return;
            }
            if (badi == '+' && map[tabaghe][row][col - 3] != '#')
            {
                check_seen(row, col - 3, tabaghe, '+');
            }
            if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
            {
                damage_monster(row, col, tabaghe);
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();

                    return;
                }
                steps += 1;
                int mizan_shadabi = chech_shadabi(tabaghe);
                if (mizan_shadabi == 1)
                {
                    if (hp < 1 || shadabi < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                }
                if (mizan_shadabi == 2)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                if (object_picker(badi, row, col - 2, tabaghe) == 1)
                {
                    map[tabaghe][row][col - 2] = '.';
                    badi = '.';
                }
                if (badi == 'E')
                {
                    map[tabaghe][row][col] = ghabli;
                    start_boss();
                    return;
                }
                if (badi == 'r' || badi == 'R')
                {
                    trap(badi);
                    if (hp < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                    map[tabaghe][row][col - 2] = '^';
                    badi = '^';
                }
                map[tabaghe][row][col - 2] = 'N';
                map[tabaghe][row][col] = ghabli;
                asar_telesm_speed -= 1;
                harekat_monster(row, col - 2, tabaghe);
                harekat(row, (col - 2), tabaghe, badi);
                return;
            }
            refresh();
        }

        badi = map[tabaghe][row][col - 1];
        if (badi == '?')
        {
            map[tabaghe][row][col] = '.';
            harekat(15, 15, 5, '.');
            return;
        }
        if (badi == '+' && map[tabaghe][row][col - 2] != '#')
        {
            check_seen(row, col - 2, tabaghe, '+');
        }
        if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
        {
            damage_monster(row, col, tabaghe);
            if (hp < 1 || shadabi < 1)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();

                return;
            }
            steps += 1;
            int mizan_shadabi = chech_shadabi(tabaghe);
            if (mizan_shadabi == 1)
            {
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
            }
            if (mizan_shadabi == 2)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();
                return;
            }
            if (object_picker(badi, row, col - 1, tabaghe) == 1)
            {
                map[tabaghe][row][col - 1] = '.';
                badi = '.';
            }
            if (badi == 'E')
            {
                map[tabaghe][row][col] = ghabli;
                start_boss();
                return;
            }
            if (badi == 'r' || badi == 'R')
            {
                trap(badi);
                if (hp < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                map[tabaghe][row][col - 1] = '^';
                badi = '^';
            }
            map[tabaghe][row][col - 1] = 'N';
            map[tabaghe][row][col] = ghabli;
            harekat_monster(row, col - 1, tabaghe);
            harekat(row, (col - 1), tabaghe, badi);
            return;
        }
        else
        {
            harekat(row, col, tabaghe, ghabli);
            return;
        }
        refresh();
    }
    if (jahat == '2')
    {
        if (asar_telesm_health > 0)
        {
            asar_telesm_health -= 1;
            hp += 4;
            if (hp > 100)
            {
                hp = 100;
            }
        }
        if (asar_telesm_damage > 0)
        {
            asar_telesm_damage -= 1;
        }
        char badi;
        if (asar_telesm_speed > 0)
        {
            asar_telesm_speed -= 1;
            badi = map[tabaghe][row + 2][col];
            if (badi == '?')
            {
                map[tabaghe][row][col] = '.';
                harekat(15, 15, 5, '.');
                return;
            }
            if (badi == '+' && map[tabaghe][row + 3][col] != '#')
            {
                check_seen(row + 3, col, tabaghe, '+');
            }
            if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
            {
                damage_monster(row, col, tabaghe);
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();

                    return;
                }
                steps += 1;
                if (object_picker(badi, row + 2, col, tabaghe) == 1)
                {
                    map[tabaghe][row + 2][col] = '.';
                    badi = '.';
                }
                int mizan_shadabi = chech_shadabi(tabaghe);
                if (mizan_shadabi == 1)
                {
                    if (hp < 1 || shadabi < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                }
                if (mizan_shadabi == 2)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                if (badi == 'E')
                {
                    map[tabaghe][row][col] = ghabli;
                    start_boss();
                    return;
                }
                if (badi == 'r' || badi == 'R')
                {

                    trap(badi);
                    if (hp < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                    map[tabaghe][row + 2][col] = '^';
                    badi = '^';
                }
                map[tabaghe][row + 2][col] = 'N';
                map[tabaghe][row][col] = ghabli;
                harekat_monster(row + 2, col, tabaghe);
                harekat(row + 2, col, tabaghe, badi);
                return;
            }
            refresh();
        }

        badi = map[tabaghe][row + 1][col];
        if (badi == '?')
        {
            map[tabaghe][row][col] = '.';
            harekat(15, 15, 5, '.');
            return;
        }
        if (badi == '+' && map[tabaghe][row + 2][col] != '#')
        {
            check_seen(row + 2, col, tabaghe, '+');
        }
        if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
        {
            damage_monster(row, col, tabaghe);
            if (hp < 1 || shadabi < 1)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();

                return;
            }
            steps += 1;
            if (object_picker(badi, row + 1, col, tabaghe) == 1)
            {
                map[tabaghe][row + 1][col] = '.';
                badi = '.';
            }
            int mizan_shadabi = chech_shadabi(tabaghe);
            if (mizan_shadabi == 1)
            {
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
            }
            if (mizan_shadabi == 2)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();
                return;
            }
            if (badi == 'E')
            {
                map[tabaghe][row][col] = ghabli;
                start_boss();
                return;
            }
            if (badi == 'r' || badi == 'R')
            {
                trap(badi);
                if (hp < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                map[tabaghe][row + 1][col] = '^';
                badi = '^';
            }
            map[tabaghe][row + 1][col] = 'N';
            map[tabaghe][row][col] = ghabli;
            harekat_monster(row + 1, col, tabaghe);
            harekat(row + 1, col, tabaghe, badi);
            return;
        }
        else
        {
            harekat(row, col, tabaghe, ghabli);
            return;
        }
        refresh();
    }
    if (jahat == '8')
    {
        if (asar_telesm_health > 0)
        {
            asar_telesm_health -= 1;
            hp += 4;
            if (hp > 100)
            {
                hp = 100;
            }
        }
        if (asar_telesm_damage > 0)
        {
            asar_telesm_damage -= 1;
        }
        char badi;
        if (asar_telesm_speed > 0)
        {
            asar_telesm_speed -= 1;
            badi = map[tabaghe][row - 2][col];
            if (badi == '?')
            {

                map[tabaghe][row][col] = '.';
                harekat(15, 15, 5, '.');
                return;
            }
            if (badi == '+' && map[tabaghe][row - 3][col] != '#')
            {
                check_seen(row - 3, col, tabaghe, '+');
            }
            if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
            {
                damage_monster(row, col, tabaghe);
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();

                    return;
                }
                steps += 1;
                if (object_picker(badi, row - 2, col, tabaghe) == 1)
                {
                    map[tabaghe][row - 2][col] = '.';
                    badi = '.';
                }
                int mizan_shadabi = chech_shadabi(tabaghe);
                if (mizan_shadabi == 1)
                {
                    if (hp < 1 || shadabi < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                }
                if (mizan_shadabi == 2)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                if (badi == 'E')
                {
                    map[tabaghe][row][col] = ghabli;
                    start_boss();
                    return;
                }
                if (badi == 'r' || badi == 'R')
                {
                    trap(badi);
                    if (hp < 1)
                    {
                        if (load_game == 1)
                        {
                            char save[100];
                            strcpy(save, karbar);
                            strncat(save, "save.txt", sizeof(save) - 8 - 1);
                            FILE *fptr4 = fopen(save, "w");
                        }
                        clear();
                        mvprintw(1, 0, "Damn!! you died");
                        char chert = getch();
                        while (chert != ' ')
                        {
                            chert = getch();
                        }
                        start_menu();
                        return;
                    }
                    map[tabaghe][row - 2][col] = '^';
                    badi = '^';
                }
                map[tabaghe][row - 2][col] = 'N';
                map[tabaghe][row][col] = ghabli;
                harekat_monster(row - 2, col, tabaghe);
                harekat(row - 2, col, tabaghe, badi);
                return;
            }
            refresh();
        }
        badi = map[tabaghe][row - 1][col];
        if (badi == '?')
        {
            map[tabaghe][row][col] = '.';
            harekat(15, 15, 5, '.');
            return;
        }
        if (badi == '+' && map[tabaghe][row - 2][col] != '#')
        {
            check_seen(row - 2, col, tabaghe, '+');
        }
        if (badi != '!' && badi != '|' && badi != '_' && badi != '$' && badi != ' ' && badi != '|' && badi != 'O' && badi != 'S' && badi != 'I' && badi != 'd' && badi != 'f' && badi != 'u' && badi != '@')
        {
            damage_monster(row, col, tabaghe);
            if (hp < 1 || shadabi < 1)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();

                return;
            }
            steps += 1;
            if (object_picker(badi, row - 1, col, tabaghe) == 1)
            {
                map[tabaghe][row - 1][col] = '.';
                badi = '.';
            }
            int mizan_shadabi = chech_shadabi(tabaghe);
            if (mizan_shadabi == 1)
            {
                if (hp < 1 || shadabi < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
            }
            if (mizan_shadabi == 2)
            {
                if (load_game == 1)
                {
                    char save[100];
                    strcpy(save, karbar);
                    strncat(save, "save.txt", sizeof(save) - 8 - 1);
                    FILE *fptr4 = fopen(save, "w");
                }
                clear();
                mvprintw(1, 0, "Damn!! you died");
                char chert = getch();
                while (chert != ' ')
                {
                    chert = getch();
                }
                start_menu();
                return;
            }
            if (badi == 'E')
            {
                map[tabaghe][row][col] = ghabli;
                start_boss();
                return;
            }
            if (badi == 'r' || badi == 'R')
            {
                trap(badi);
                if (hp < 1)
                {
                    if (load_game == 1)
                    {
                        char save[100];
                        strcpy(save, karbar);
                        strncat(save, "save.txt", sizeof(save) - 8 - 1);
                        FILE *fptr4 = fopen(save, "w");
                    }
                    clear();
                    mvprintw(1, 0, "Damn!! you died");
                    char chert = getch();
                    while (chert != ' ')
                    {
                        chert = getch();
                    }
                    start_menu();
                    return;
                }
                map[tabaghe][row - 1][col] = '^';
                badi = '^';
            }
            map[tabaghe][row - 1][col] = 'N';
            map[tabaghe][row][col] = ghabli;
            harekat_monster(row - 1, col, tabaghe);
            harekat(row - 1, col, tabaghe, badi);
            return;
        }
        else
        {
            harekat(row, col, tabaghe, ghabli);
            return;
        }
        refresh();
    }
    if (jahat == 'S')
    {
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                if (map[tabaghe][row + i][col + j] == 'r' || map[tabaghe][row + i][col + j] == 'R')
                {
                    map[tabaghe][row + i][col + j] = '^';
                }
                if (map[tabaghe][row + i][col + j] == '!')
                {
                    map[tabaghe][row + i][col + j] = '?';
                }
            }
        }
    }
    if (jahat == '>' && ghabli == 'U')
    {
        check_seen(row, col, tabaghe, 'U');
        map[tabaghe][row][col] = 'U';
        if (tabaghe == 3)
        {
            tabaghe = 0;
        }
        else
        {
            tabaghe += 1;
        }
        for (int i = 0; i < 49; i++)
        {
            for (int j = 0; j < 49; j++)
            {
                if (map[tabaghe][i][j] == 'D')
                {
                    row = i;
                    col = j;
                }
            }
        }
        map[tabaghe][row][col] = 'N';
        harekat(row, col, tabaghe, 'D');
        return;
    }
    if (jahat == '<' && ghabli == 'D')
    {
        if (tabaghe == 5)
        {
            map[tabaghe][row][col] = 'D';
            int x = 0;
            int y = rand() % hidden_count;
            for (int k = 0; k < 4; k++)
            {
                for (int i = 0; i < 49; i++)
                {
                    for (int j = 0; j < 49; j++)
                    {
                        if (map[k][i][j] == '?' || map[k][i][j] == '!')
                        {
                            if (x == y)
                            {
                                if (map[k][i][j + 1] == '.')
                                {
                                    check_seen(i, j + 1, k, '.');
                                    harekat(i, j + 1, k, '.');
                                }
                                if (map[k][i][j - 1] == '.')
                                {
                                    check_seen(i, j - 1, k, '.');
                                    harekat(i, j - 1, k, '.');
                                }
                                if (map[k][i + 1][j] == '.')
                                {
                                    check_seen(i + 1, j, k, '.');
                                    harekat(i + 1, j, k, '.');
                                }
                                if (map[k][i - 1][j] == '.')
                                {
                                    check_seen(i - 1, j, k, '.');
                                    harekat(i - 1, j, k, '.');
                                }
                            }
                            else
                            {
                                x += 1;
                            }
                        }
                    }
                }
            }
        }
        check_seen(row, col, tabaghe, 'D');
        map[tabaghe][row][col] = 'D';
        if (tabaghe == 0)
        {
            tabaghe = 3;
        }
        else
        {
            tabaghe -= 1;
        }
        for (int i = 0; i < 49; i++)
        {
            for (int j = 0; j < 49; j++)
            {
                if (map[tabaghe][i][j] == 'U')
                {
                    row = i;
                    col = j;
                }
            }
        }
        map[tabaghe][row][col] = 'N';
        harekat(row, col, tabaghe, 'U');
        return;
    }
    if (jahat == 's' && ghabli == '.' && load_game != 2)
    {
        clear();
        refresh();
        printw("Do you want save game?(Y/N)");
        char chert = getch();
        while (chert != 'y' && chert != 'Y' && chert != 'n' && chert != 'N')
        {
            chert = getch();
        }
        if (chert == 'Y' || chert == 'y')
        {
            char save[100];
            strcpy(save, karbar);
            strncat(save, "g.txt", sizeof(save) - 5 - 1);
            FILE *savekon = fopen(save, "w");
            while (gold > 0)
            {
                if (gold % 10 == 0)
                {
                    fputc('0', savekon);
                }
                if (gold % 10 == 1)
                {
                    fputc('1', savekon);
                }
                if (gold % 10 == 2)
                {
                    fputc('2', savekon);
                }
                if (gold % 10 == 3)
                {
                    fputc('3', savekon);
                }
                if (gold % 10 == 4)
                {
                    fputc('4', savekon);
                }
                if (gold % 10 == 5)
                {
                    fputc('5', savekon);
                }
                if (gold % 10 == 6)
                {
                    fputc('6', savekon);
                }
                if (gold % 10 == 7)
                {
                    fputc('7', savekon);
                }
                if (gold % 10 == 8)
                {
                    fputc('8', savekon);
                }
                if (gold % 10 == 9)
                {
                    fputc('9', savekon);
                }
                gold /= 10;
            }
            fclose(savekon);
            strcpy(save, karbar);
            strncat(save, "map.txt", sizeof(save) - 7 - 1);
            savekon = fopen(save, "w");
            for (int k = 0; k < 6; k++)
            {
                for (int j = 0; j < 49; j++)
                {
                    for (int i = 0; i < 49; i++)
                    {
                        fputc(map[k][j][i], savekon);
                    }
                }
            }
            fclose(savekon);
            strcpy(save, karbar);
            strncat(save, "telesm.txt", sizeof(save) - 9 - 1);
            savekon = fopen(save, "w");
            for (int i = 0; i < telesm_count; i++)
            {
                fprintf(savekon, "%s\n", inv_telesm[i]);
            }
            fclose(savekon);
            strcpy(save, karbar);
            strncat(save, "dagger.txt", sizeof(save) - 10 - 1);
            savekon = fopen(save, "w");
            while (dagger > 0)
            {
                if (dagger % 10 == 0)
                {
                    fputc('0', savekon);
                }
                if (dagger % 10 == 1)
                {
                    fputc('1', savekon);
                }
                if (dagger % 10 == 2)
                {
                    fputc('2', savekon);
                }
                if (dagger % 10 == 3)
                {
                    fputc('3', savekon);
                }
                if (dagger % 10 == 4)
                {
                    fputc('4', savekon);
                }
                if (dagger % 10 == 5)
                {
                    fputc('5', savekon);
                }
                if (dagger % 10 == 6)
                {
                    fputc('6', savekon);
                }
                if (dagger % 10 == 7)
                {
                    fputc('7', savekon);
                }
                if (dagger % 10 == 8)
                {
                    fputc('8', savekon);
                }
                if (dagger % 10 == 9)
                {
                    fputc('9', savekon);
                }
                dagger /= 10;
            }
            fclose(savekon);
            strcpy(save, karbar);
            strncat(save, "sword.txt", sizeof(save) - 9 - 1);
            savekon = fopen(save, "w");
            while (sword > 0)
            {
                if (sword % 10 == 0)
                {
                    fputc('0', savekon);
                }
                if (sword % 10 == 1)
                {
                    fputc('1', savekon);
                }
                if (sword % 10 == 2)
                {
                    fputc('2', savekon);
                }
                if (sword % 10 == 3)
                {
                    fputc('3', savekon);
                }
                if (sword % 10 == 4)
                {
                    fputc('4', savekon);
                }
                if (sword % 10 == 5)
                {
                    fputc('5', savekon);
                }
                if (sword % 10 == 6)
                {
                    fputc('6', savekon);
                }
                if (sword % 10 == 7)
                {
                    fputc('7', savekon);
                }
                if (sword % 10 == 8)
                {
                    fputc('8', savekon);
                }
                if (sword % 10 == 9)
                {
                    fputc('9', savekon);
                }
                sword /= 10;
            }
            fclose(savekon);
            strcpy(save, karbar);
            strncat(save, "arrow.txt", sizeof(save) - 9 - 1);
            savekon = fopen(save, "w");
            while (normal_arrow > 0)
            {
                if (normal_arrow % 10 == 0)
                {
                    fputc('0', savekon);
                }
                if (normal_arrow % 10 == 1)
                {
                    fputc('1', savekon);
                }
                if (normal_arrow % 10 == 2)
                {
                    fputc('2', savekon);
                }
                if (normal_arrow % 10 == 3)
                {
                    fputc('3', savekon);
                }
                if (normal_arrow % 10 == 4)
                {
                    fputc('4', savekon);
                }
                if (normal_arrow % 10 == 5)
                {
                    fputc('5', savekon);
                }
                if (normal_arrow % 10 == 6)
                {
                    fputc('6', savekon);
                }
                if (normal_arrow % 10 == 7)
                {
                    fputc('7', savekon);
                }
                if (normal_arrow % 10 == 8)
                {
                    fputc('8', savekon);
                }
                if (normal_arrow % 10 == 9)
                {
                    fputc('9', savekon);
                }
                normal_arrow /= 10;
            }
            fclose(savekon);
            strcpy(save, karbar);
            strncat(save, "wand.txt", sizeof(save) - 8 - 1);
            savekon = fopen(save, "w");
            while (magik_wand > 0)
            {
                if (magik_wand % 10 == 0)
                {
                    fputc('0', savekon);
                }
                if (magik_wand % 10 == 1)
                {
                    fputc('1', savekon);
                }
                if (magik_wand % 10 == 2)
                {
                    fputc('2', savekon);
                }
                if (magik_wand % 10 == 3)
                {
                    fputc('3', savekon);
                }
                if (magik_wand % 10 == 4)
                {
                    fputc('4', savekon);
                }
                if (magik_wand % 10 == 5)
                {
                    fputc('5', savekon);
                }
                if (magik_wand % 10 == 6)
                {
                    fputc('6', savekon);
                }
                if (magik_wand % 10 == 7)
                {
                    fputc('7', savekon);
                }
                if (magik_wand % 10 == 8)
                {
                    fputc('8', savekon);
                }
                if (magik_wand % 10 == 9)
                {
                    fputc('9', savekon);
                }
                magik_wand /= 10;
            }
            fclose(savekon);
            strcpy(save, karbar);
            strncat(save, "hidden.txt", sizeof(save) - 10 - 1);
            savekon = fopen(save, "w");
            while (hidden_count > 0)
            {
                if (hidden_count % 10 == 0)
                {
                    fputc('0', savekon);
                }
                if (hidden_count % 10 == 1)
                {
                    fputc('1', savekon);
                }
                if (hidden_count % 10 == 2)
                {
                    fputc('2', savekon);
                }
                if (hidden_count % 10 == 3)
                {
                    fputc('3', savekon);
                }
                if (hidden_count % 10 == 4)
                {
                    fputc('4', savekon);
                }
                if (hidden_count % 10 == 5)
                {
                    fputc('5', savekon);
                }
                if (hidden_count % 10 == 6)
                {
                    fputc('6', savekon);
                }
                if (hidden_count % 10 == 7)
                {
                    fputc('7', savekon);
                }
                if (hidden_count % 10 == 8)
                {
                    fputc('8', savekon);
                }
                if (hidden_count % 10 == 9)
                {
                    fputc('9', savekon);
                }
                hidden_count /= 10;
            }
            fclose(savekon);
            strcpy(save, karbar);
            strncat(save, "mapseen.txt", sizeof(save) - 11 - 1);
            savekon = fopen(save, "w");
            for (int k = 0; k < 6; k++)
            {
                for (int i = 0; i < 49; i++)
                {
                    for (int j = 0; j < 49; j++)
                    {
                        if (map_seen[k][i][j] == 0)
                        {
                            fputc('0', savekon);
                        }
                        if (map_seen[k][i][j] == 1)
                        {
                            fputc('1', savekon);
                        }
                        if (map_seen[k][i][j] == 2)
                        {
                            fputc('2', savekon);
                        }
                        if (map_seen[k][i][j] == 3)
                        {
                            fputc('3', savekon);
                        }
                    }
                }
            }
            fclose(savekon);
            strcpy(save, karbar);
            strncat(save, "hp.txt", sizeof(save) - 6 - 1);
            savekon = fopen(save, "w");
            while (hp > 0)
            {
                if (hp % 10 == 0)
                {
                    fputc('0', savekon);
                }
                if (hp % 10 == 1)
                {
                    fputc('1', savekon);
                }
                if (hp % 10 == 2)
                {
                    fputc('2', savekon);
                }
                if (hp % 10 == 3)
                {
                    fputc('3', savekon);
                }
                if (hp % 10 == 4)
                {
                    fputc('4', savekon);
                }
                if (hp % 10 == 5)
                {
                    fputc('5', savekon);
                }
                if (hp % 10 == 6)
                {
                    fputc('6', savekon);
                }
                if (hp % 10 == 7)
                {
                    fputc('7', savekon);
                }
                if (hp % 10 == 8)
                {
                    fputc('8', savekon);
                }
                if (hp % 10 == 9)
                {
                    fputc('9', savekon);
                }
                hp /= 10;
            }
            fclose(savekon);
            strcpy(save, karbar);
            strncat(save, "shadabi.txt", sizeof(save) - 11 - 1);
            savekon = fopen(save, "w");
            while (shadabi > 0)
            {
                if (shadabi % 10 == 0)
                {
                    fputc('0', savekon);
                }
                if (shadabi % 10 == 1)
                {
                    fputc('1', savekon);
                }
                if (shadabi % 10 == 2)
                {
                    fputc('2', savekon);
                }
                if (shadabi % 10 == 3)
                {
                    fputc('3', savekon);
                }
                if (shadabi % 10 == 4)
                {
                    fputc('4', savekon);
                }
                if (shadabi % 10 == 5)
                {
                    fputc('5', savekon);
                }
                if (shadabi % 10 == 6)
                {
                    fputc('6', savekon);
                }
                if (shadabi % 10 == 7)
                {
                    fputc('7', savekon);
                }
                if (shadabi % 10 == 8)
                {
                    fputc('8', savekon);
                }
                if (shadabi % 10 == 9)
                {
                    fputc('9', savekon);
                }
                shadabi /= 10;
            }
            fclose(savekon);
            strcpy(save, karbar);
            strncat(save, "Foodcount.txt", sizeof(save) - 13 - 1);
            savekon = fopen(save, "w");
            while (foods_count > 0)
            {
                if (foods_count % 10 == 0)
                {
                    fputc('0', savekon);
                }
                if (foods_count % 10 == 1)
                {
                    fputc('1', savekon);
                }
                if (foods_count % 10 == 2)
                {
                    fputc('2', savekon);
                }
                if (foods_count % 10 == 3)
                {
                    fputc('3', savekon);
                }
                if (foods_count % 10 == 4)
                {
                    fputc('4', savekon);
                }
                if (foods_count % 10 == 5)
                {
                    fputc('5', savekon);
                }
                if (foods_count % 10 == 6)
                {
                    fputc('6', savekon);
                }
                if (foods_count % 10 == 7)
                {
                    fputc('7', savekon);
                }
                if (foods_count % 10 == 8)
                {
                    fputc('8', savekon);
                }
                if (foods_count % 10 == 9)
                {
                    fputc('9', savekon);
                }
                foods_count /= 10;
            }
            fclose(savekon);
            strcpy(save, karbar);
            strncat(save, "telesmcount.txt", sizeof(save) - 15 - 1);
            savekon = fopen(save, "w");
            while (telesm_count > 0)
            {
                if (telesm_count % 10 == 0)
                {
                    fputc('0', savekon);
                }
                if (telesm_count % 10 == 1)
                {
                    fputc('1', savekon);
                }
                if (telesm_count % 10 == 2)
                {
                    fputc('2', savekon);
                }
                if (telesm_count % 10 == 3)
                {
                    fputc('3', savekon);
                }
                if (telesm_count % 10 == 4)
                {
                    fputc('4', savekon);
                }
                if (telesm_count % 10 == 5)
                {
                    fputc('5', savekon);
                }
                if (telesm_count % 10 == 6)
                {
                    fputc('6', savekon);
                }
                if (telesm_count % 10 == 7)
                {
                    fputc('7', savekon);
                }
                if (telesm_count % 10 == 8)
                {
                    fputc('8', savekon);
                }
                if (telesm_count % 10 == 9)
                {
                    fputc('9', savekon);
                }
                telesm_count /= 10;
            }
            fclose(savekon);
            strcpy(save, karbar);
            strncat(save, "save.txt", sizeof(save) - 11 - 1);
            savekon = fopen(save, "w");
            fputc('1', savekon);
            fclose(savekon);
        }
        menu_start();
    }
    if (jahat == 'e')
    {

        if (foods_count == 0)
        {
            mvprintw(1, 0, "If I had listened to my mom, we would have some foods now.(always listen to your moms)\n");
            char chert = getch();
        }
        else
        {
            clear();
            for (int i = 0; i < foods_count; i++)
            {
                mvprintw(i + 1, 0, "%d.%s\n", i + 1, inv_food[i]);
            }
            mvprintw(foods_count + 1, 0, "Shall we break the diet and eat?(1 means yes and 0 means no!)\n");
            char ans = getch();
            while (ans != '1' && ans != '0')
            {
                printw("i said 1 or 0\n");
                ans = getch();
            }
            if (ans == '0')
            {
            }
            if (ans == '1')
            {
                printw("witch one?(select based on list numbers)\n");
                char javab = getch();

                while ((javab != '1' && javab != '2' && javab != '3' && javab != '4' && javab != '5') || (((int)javab - 48) > foods_count))
                {
                    printw("pleas select a number that is on the list\n");
                    javab = getch();
                }
                shadabi += 25;
                if (shadabi > 100)
                {
                    shadabi = 100;
                }
                hp += (rand() % 14) + 12;
                if (hp > 100)
                {
                    hp = 100;
                }
                for (int i = ((int)javab - 49); i < foods_count - 1; i++)
                {
                    strcpy(inv_food[i], inv_food[i + 1]);
                }
                foods_count -= 1;
            }
        }
        refresh();
    }
    if (jahat == 'm')
    {
        clear();
        for (int i = 0; i < 49; i++)
        {
            for (int j = 0; j < 49; j++)
            {
                if (i == 1 && j == 1 && map[tabaghe][i][j] == '.')
                {
                    printw("  ");
                    continue;
                }
                if (map[tabaghe][i][j] == '@')
                {
                    printw(" ");
                }
                else if (map[tabaghe][i][j] == 'T' || map[tabaghe][i][j] == '4' || map[tabaghe][i][j] == '3' || map[tabaghe][i][j] == '2' || map[tabaghe][i][j] == '5' || map[tabaghe][i][j] == 'O' || map[tabaghe][i][j] == 'F' || map[tabaghe][i][j] == 'G' || map[tabaghe][i][j] == 'g' || map[tabaghe][i][j] == 'E' || map[tabaghe][i][j] == 'R' || map[tabaghe][i][j] == 'r' || map[tabaghe][i][j] == 'U' || map[tabaghe][i][j] == 'D' || map[tabaghe][i][j] == 'd' || map[tabaghe][i][j] == 'u' || map[tabaghe][i][j] == 'S' || map[tabaghe][i][j] == 'I' || map[tabaghe][i][j] == 'f' || map[tabaghe][i][j] == '^' || map[tabaghe][i][j] == '?')
                {
                    printw(".");
                }
                else if (map[tabaghe][i][j] == '!')
                {
                    char *message = "\u2550";
                    printw("%s", message);
                }
                ///////////////////
                else if (map[tabaghe][i][j] == '#')
                {
                    char *message = "\u2507";
                    printw("%s", message);
                }
                else if (map[tabaghe][i][j] == '|')
                {
                    char *message = "\u2551";
                    printw("%s", message);
                }
                else if (map[tabaghe][i][j] == '_')
                {
                    char *message = "\u2550";
                    printw("%s", message);
                }
                else if (map[tabaghe][i][j] == '$')
                {
                    char *message = "\u25B4";
                    printw("%s", message);
                }
                else
                {
                    printw("%c", map[tabaghe][i][j]);
                }
            }
            printw("\n");
        }
        mvprintw(0, 0, "prees m to continue");
        char javab = getch();

        while (javab != 'm')
        {
            javab = getch();
        }
    }
    if (jahat == 't')
    {
        if (telesm_count == 0)
        {
            mvprintw(1, 0, "You don't have a spell. You can buy it from reputable stores across the country.\n");
            char chert = getch();
        }
        else
        {
            clear();
            for (int i = 0; i < telesm_count; i++)
            {
                printw("%d.%s\n", i + 1, inv_telesm[i]);
            }
            printw("play like a coward?(1 means yes and 0 means no)\n");
            char ans = getch();
            while (ans != '1' && ans != '0')
            {
                printw("i said 1 or 0\n");
                ans = getch();
            }
            if (ans == '0')
            {
            }
            if (ans == '1')
            {
                printw("witch one?(select based on list numbers)\n");
                char javab = getch();
                while ((javab != '1' && javab != '2' && javab != '3' && javab != '4' && javab != '5' && javab != '6' && javab != '7' && javab != '8' && javab != '9') || ((int)javab - 48) > telesm_count)
                {
                    printw("pleas select a number that is on the list\n");
                    javab = getch();
                }
                if (inv_telesm[((int)javab - 49)][0] == 'S')
                {
                    asar_telesm_speed += 15;
                }
                else if (inv_telesm[((int)javab - 49)][0] == 'D')
                {
                    asar_telesm_damage += 15;
                }
                else if (inv_telesm[((int)javab - 49)][0] == 'H')
                {
                    asar_telesm_health += 5;
                }
                for (int i = ((int)javab - 49); i < telesm_count - 1; i++)
                {
                    strcpy(inv_telesm[i], inv_telesm[i + 1]);
                }
                telesm_count -= 1;
            }
        }
    }
    refresh();
    harekat(row, col, tabaghe, ghabli);
}
void tabaghe_saz()
{
    int colmn = (rand() % 49);
    int row = (rand() % 49);
    while (map[0][row][colmn] != '.')
    {
        colmn = (rand() % 49);
        row = (rand() % 49);
    }
    map[0][row][colmn] = 'N';
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int colmn = (rand() % 49);
            int row = (rand() % 49);
            while (map[i][row][colmn] != '.')
            {
                colmn = (rand() % 49);
                row = (rand() % 49);
            }
            if (j == 0)
            {
                if (i < 3)
                {
                    map[i][row][colmn] = 'U';
                }
            }
            else
            {
                if (i > 0)
                {
                    map[i][row][colmn] = 'D';
                }
            }
        }
    }
    initial_map_seen(row, colmn);
    add_otagh_ganj();
    creat_hidden_door();
    otagh_boss_saz();
    creat_floor_six();
    harekat(row, colmn, 0, '.');
}
void creat_map(int tabaghe)
{

    if (tabaghe == 1)
    {
        wepean_pish = 1;
        dagger = 0;
        normal_arrow = 0;
        magik_wand = 0;
        sword = 0;
        telesm_count = 0;
        int gold = 0;
        hp = 100;
        shadabi = 100;
        foods_count = 0;
        steps = 0;
        wepean_pish = 1;
        hidden_count = 0;
        asar_telesm_speed = 0;
        asar_telesm_damage = 0;
        asar_telesm_health = 0;
        enemy_count = 0;
        telesm_count = 0;
        for (int k = 0; k < 4; k++)
        {
            for (int i = 0; i < 49; i++)
            {
                for (int j = 0; j < 49; j++)
                {
                    map_seen[k][i][j] = 0;
                    map_gold[k][i][j] = 0;
                }
            }
        }
    }
    int tedad = (rand() % 4) + 6;
    int ghesmat[9];
    for (int i = 0; i < 9; i++)
    {
        ghesmat[i] = -1;
    }
    for (int i = 0; i < tedad; i++)
    {
        int x = rand() % 9;
        while (ghesmat[x] != -1)
        {
            x = rand() % 9;
        }
        ghesmat[x] = 1;
    }
    int adamak = rand() % 9;
    int makan_adamakx, makan_adamaky;
    while (ghesmat[adamak] == 0)
    {
        adamak = rand() % 9;
    }
    char naghshe[49][49];
    for (int i = 0; i < 49; i++)
    {
        for (int j = 0; j < 49; j++)
        {
            naghshe[i][j] = ' ';
        }
    }
    goshe_kesh(naghshe);
    for (int i = 0; i < 9; i++)
    {
        if (ghesmat[i] == 1)
        {
            int maxx = (((i / 3) * 16) + 14);
            int minx = ((i / 3) * 16) + 2;
            int maxy = (((i % 3) * 16) + 14);
            int miny = ((i % 3) * 16) + 2;
            int x1 = (rand() % 4) + minx;
            int x2 = maxx - (rand() % 5);
            int y2 = maxy - (rand() % 5);
            int y1 = (rand() % 4) + miny;
            naghshe[x1][y1] = '$';
            naghshe[x1][y2] = '$';
            naghshe[x2][y1] = '$';
            naghshe[x2][y2] = '$';
            for (int j = (x1 + 1); j < x2; j++)
            {
                naghshe[j][y1] = '|';
                naghshe[j][y2] = '|';
            }
            for (int j = (y1 + 1); j < y2; j++)
            {
                naghshe[x1][j] = '_';
                naghshe[x2][j] = '_';
            }
            for (int j = (x1 + 1); j < x2; j++)
            {
                for (int k = (y1 + 1); k < y2; k++)
                {
                    naghshe[j][k] = '.';
                }
            }
            int up = rand() % 4;
            if (up == 0)
            {
                int door = (rand() % (y2 - y1 - 2)) + y1 + 1;
                naghshe[x1][door] = '+';
            }
            else if (up == 1)
            {
                int door = (rand() % (x2 - x1 - 2)) + x1 + 1;
                naghshe[door][y1] = '+';
            }
            else if (up == 2)
            {
                int door = (rand() % (y2 - y1 - 2)) + y1 + 1;
                naghshe[x2][door] = '+';
            }
            else if (up == 3)
            {
                int door = (rand() % (x2 - x1 - 2)) + x1 + 1;
                naghshe[door][y2] = '+';
            }
            int soton = (rand() % 3);
            for (int j = 0; j < soton; j++)
            {
                int colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
                int row = (rand() % (x2 - x1 - 3)) + x1 + 2;
                if (naghshe[row][colmn] == '.' && naghshe[row + 1][colmn] != '+' && naghshe[row][colmn + 1] != '+' && naghshe[row - 1][colmn] != '+' && naghshe[row][colmn - 1] != '+')
                {
                    naghshe[row][colmn] = 'O';
                }
                else
                {
                    while (naghshe[row][colmn] != '.' && naghshe[row + 1][colmn] == '+' && naghshe[row][colmn + 1] == '+' && naghshe[row - 1][colmn] == '+' && naghshe[row][colmn - 1] == '+')
                    {
                        colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
                        row = (rand() % (x2 - x1 - 3)) + x1 + 2;
                    }
                    naghshe[row][colmn] = 'O';
                }
            }
            int shans_gold = (rand() % 7);
            if (shans_gold < 3)
            {
                int colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
                int row = (rand() % (x2 - x1 - 3)) + x1 + 2;
                while (naghshe[row][colmn] != '.')
                {
                    colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
                    row = (rand() % (x2 - x1 - 3)) + x1 + 2;
                }
                int shans_no_tala = rand() % 10;
                if (shans_no_tala == 1)
                {
                    naghshe[row][colmn] = 'g';
                }
                else
                {
                    naghshe[row][colmn] = 'G';
                }
            }
            int shans_Trap = (rand() % 3);
            if (shans_Trap == 0)
            {
                int colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
                int row = (rand() % (x2 - x1 - 3)) + x1 + 2;
                while (naghshe[row][colmn] != '.')
                {
                    colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
                    row = (rand() % (x2 - x1 - 3)) + x1 + 2;
                }
                shans_Trap = (rand() % 3);
                if (shans_Trap == 0)
                {
                    naghshe[row][colmn] = 'R';
                }
                else
                {
                    naghshe[row][colmn] = 'r';
                }
            }
            int shans_ghaza = (rand() % 3);
            if (shans_ghaza == 0)
            {
                int colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
                int row = (rand() % (x2 - x1 - 3)) + x1 + 2;
                while (naghshe[row][colmn] != '.')
                {
                    colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
                    row = (rand() % (x2 - x1 - 3)) + x1 + 2;
                }
                naghshe[row][colmn] = 'F';
            }
            int shans_telesm = (rand() % 5);
            if (shans_telesm == 1)
            {
                int colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
                int row = (rand() % (x2 - x1 - 3)) + x1 + 2;
                while (naghshe[row][colmn] != '.')
                {
                    colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
                    row = (rand() % (x2 - x1 - 3)) + x1 + 2;
                }
                naghshe[row][colmn] = 'T';
            }
            int shans_wepean = (rand() % 4);
            if (shans_wepean == 0)
            {
                int colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
                int row = (rand() % (x2 - x1 - 3)) + x1 + 2;
                while (naghshe[row][colmn] != '.')
                {
                    colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
                    row = (rand() % (x2 - x1 - 3)) + x1 + 2;
                }
                int no_wepean = rand() % 10;
                if (no_wepean == 0 || no_wepean == 1)
                {
                    naghshe[row][colmn] = '3';
                }
                if (no_wepean == 2 || no_wepean == 3 || no_wepean == 4 || no_wepean == 9)
                {
                    naghshe[row][colmn] = '4';
                }
                if (no_wepean == 5 || no_wepean == 6 || no_wepean == 7)
                {
                    naghshe[row][colmn] = '2';
                }
                if (no_wepean == 8)
                {
                    naghshe[row][colmn] = '5';
                }
            }
            int shans_enemy = (rand() % 2);
            if (shans_enemy == 1)
            {
                int colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
                int row = (rand() % (x2 - x1 - 3)) + x1 + 2;
                while (naghshe[row][colmn] != '.')
                {
                    colmn = (rand() % (y2 - y1 - 3)) + y1 + 2;
                    row = (rand() % (x2 - x1 - 3)) + x1 + 2;
                }
                int no_enemy = (rand() % 10);
                if (no_enemy == 0)
                {
                    naghshe[row][colmn] = 'S';
                    doshman[enemy_count].row = row;
                    doshman[enemy_count].col = colmn;
                    doshman[enemy_count].tabaghe = tabaghe;
                    doshman[enemy_count].type = 'S';
                    doshman[enemy_count].health = 20;
                    doshman[enemy_count].ability_to_walk = 1;
                    doshman[enemy_count].ghabli = '.';
                    doshman[enemy_count].chase_count = 0;
                }
                if (no_enemy == 1 || no_enemy == 2)
                {
                    naghshe[row][colmn] = 'I';
                    doshman[enemy_count].row = row;
                    doshman[enemy_count].col = colmn;
                    doshman[enemy_count].tabaghe = tabaghe;
                    doshman[enemy_count].type = 'I';
                    doshman[enemy_count].health = 15;
                    doshman[enemy_count].ability_to_walk = 1;
                    doshman[enemy_count].ghabli = '.';
                    doshman[enemy_count].chase_count = 0;
                }
                if (no_enemy == 3 || no_enemy == 4 || no_enemy == 5)
                {
                    naghshe[row][colmn] = 'f';
                    doshman[enemy_count].row = row;
                    doshman[enemy_count].col = colmn;
                    doshman[enemy_count].tabaghe = tabaghe;
                    doshman[enemy_count].type = 'f';
                    doshman[enemy_count].health = 10;
                    doshman[enemy_count].ability_to_walk = 1;
                    doshman[enemy_count].ghabli = '.';
                    doshman[enemy_count].chase_count = 0;
                }
                if (no_enemy == 6 || no_enemy == 7 || no_enemy == 8 || no_enemy == 9)
                {
                    naghshe[row][colmn] = 'd';
                    doshman[enemy_count].row = row;
                    doshman[enemy_count].col = colmn;
                    doshman[enemy_count].tabaghe = tabaghe;
                    doshman[enemy_count].type = 'd';
                    doshman[enemy_count].health = 5;
                    doshman[enemy_count].ability_to_walk = 1;
                    doshman[enemy_count].ghabli = '.';
                    doshman[enemy_count].chase_count = 0;
                }
                enemy_count += 1;
            }
        }
    }
    osta_bana(ghesmat, naghshe, tedad);
    for (int i = 0; i < 49; i++)
    {
        for (int j = 0; j < 49; j++)
        {
            if (naghshe[i][j] == '@')
            {
                rahro_hazf(naghshe, i, j);
            }
        }
    }
    for (int i = 0; i < 49; i++)
    {
        for (int j = 0; j < 49; j++)
        {
            if (naghshe[i][j] == '@' && baghal_shomar(naghshe, i, j) > 1)
            {
                naghshe[i][j] = '#';
            }
        }
    }
    for (int i = 0; i < 49; i++)
    {
        for (int j = 0; j < 49; j++)
        {
            map[tabaghe][i][j] = naghshe[i][j];
            if (naghshe[i][j] == 'G')
            {
                map_gold[tabaghe][i][j] = (rand() % 50) + 1;
            }
            if (naghshe[i][j] == 'g')
            {
                map_gold[tabaghe][i][j] = (rand() % 100) + 150;
            }
            if (naghshe[i][j] == '#' || naghshe[i][j] == '+')
            {
                map_seen[tabaghe][i][j] = 1;
            }
        }
    }
    if (tabaghe == 0)
    {
        tabaghe_saz();
    }
}
int main()
{
    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < 49; i++)
        {
            for (int j = 0; j < 49; j++)
            {
                map_seen[k][i][j] = 0;
                map_gold[k][i][j] = 0;
            }
        }
    }
    for (int i = 0; i < 49; i++)
    {
        for (int j = 0; j < 49; j++)
        {
            map_seen[4][i][j] = 2;
        }
    }
    strcpy(inv_weapen[0], "mance");
    strcpy(inv_weapen[1], "Dagger");
    strcpy(inv_weapen[2], "Magic wand");
    strcpy(inv_weapen[3], "Normal Arrow");
    strcpy(inv_weapen[4], "sword");
    setlocale(LC_ALL, "");
    initscr();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    keypad(stdscr, TRUE);

    srand(time(0));
    FILE *karbar_file = NULL;
    FILE *ramz_file = NULL;
    FILE *email_file = NULL;
    FILE *file;
    FILE *emtyaz = NULL;
    karbar_file = fopen("karbar.txt", "r");
    email_file = fopen("email.txt", "r");
    ramz_file = fopen("ramz.txt", "r");
    emtyaz = fopen("emtyaz.txt", "r");
    if (emtyaz)
    {
    }
    else
    {
        file = fopen("emtyaz.txt", "w");
    }
    if (karbar_file)
    {
    }
    else
    {
        file = fopen("karbar.txt", "w");
    }
    if (ramz_file)
    {
    }
    else
    {
        file = fopen("ramz.txt", "w");
    }
    if (email_file)
    {
    }
    else
    {
        file = fopen("email.txt", "w");
    }
    refresh();
    endwin();
    start_menu();
    return 0;
}