// Adrian Melendez
// A silly program I made while taking Intro to C

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define XGRID 25
#define YGRID 15

void InitializeArray(int *WallArr, int value, int xGrid);
int SumArray(int *WallArr, int xGrid);
void DrawLine(int xGrid);
void DrawGrid(int xGrid, int yGrid, int xPos, int yPos, int xBull, int yBull, char Player, char Wall, char Bullet, int *WallArr);
void ShootingGrid(int xGrid, int yGrid, int xPos, int yPos, int xBull, int yBull, char Player, char Wall, char Bullet, int *WallArr);

int main() {

    int xPos = (XGRID - 1)/2;
    int yPos = YGRID - 2;

    int xBull = 0;
    int yBull = 0;

    int WallArr[XGRID];
    InitializeArray(WallArr, 1, XGRID);

    int BulletCounter = XGRID * 2;

    char Player = 'X';
    char Wall = '#';
    char Bullet = '^';
    char PInput;

    printf("Controls:\n\nW: Shoot\nA: Left\nD: Right\nEnter: Execute Move(s)\n");
    printf("\nPress Enter to start.\n\n");
    getchar();

    system("cls");

    while (1) {
        DrawGrid(XGRID, YGRID, xPos, yPos, xBull, yBull, Player, Wall, Bullet, WallArr);
        printf("\n");

        if (SumArray(WallArr, XGRID) < 3) {
            printf("You Win!\n\n");
            break;
        } else if (BulletCounter < 1) {
            printf("You Lose!\n\n");
            break;
        }

        scanf("%c",&PInput);
        PInput = toupper(PInput);

        switch (PInput) {
        case 'W':
            xBull = xPos;
            ShootingGrid(XGRID, YGRID, xPos, yPos, xBull, yBull, Player, Wall, Bullet, WallArr);
            WallArr[xPos] = 0;
            BulletCounter--;
            break;
        case 'A':
            if (xPos > 1)
                xPos--;

            break;
        case 'D':
            if (xPos < XGRID - 2)
                xPos++;

            break;
        }

        system("cls");
    }

    return 0;
}

void ShootingGrid(int xGrid, int yGrid, int xPos, int yPos, int xBull, int yBull, char Player, char Wall, char Bullet, int *WallArr) {
    int y;
    for (y = yGrid - 3; y > 0; y--) {
        system("cls");
        DrawGrid(XGRID, YGRID, xPos, yPos, xBull, y, Player, Wall, Bullet, WallArr);
    }

}

void DrawGrid(int xGrid, int yGrid, int xPos, int yPos, int xBull, int yBull, char Player, char Wall, char Bullet, int *WallArr) {
    int x, y;
    for (y = 0; y < yGrid; y++) {
        if (y == 0 || y == yGrid - 1) {
            DrawLine(xGrid);
            continue;
        }
        for (x = 0; x < xGrid; x++) {
            if (x == xPos && y == yPos) {
                printf("%c", Player);
            } else if (x == 0 || x == xGrid - 1) {
                printf("|");
            } else if (x == xBull && y == yBull) {
                printf("%c", Bullet);
            } else if (y == 1 && WallArr[x] == 1) {
                printf("%c", Wall);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    Sleep(10);
}

void DrawLine(int xGrid) {
    int x;
    for (x = 0; x < xGrid; x++) {
        if (x == 0 || x == xGrid - 1) {
            printf("+");
        } else {
            printf("-");
        }
    }
    printf("\n");
}

void InitializeArray(int *WallArr, int value, int xGrid) {
    int x;
    for (x = 0; x < xGrid; x++) {
        WallArr[x] = value;
    }
}

int SumArray(int *WallArr, int xGrid) {
    int x;
    int sum = 0;
    for (x = 0; x < xGrid; x++) {
        sum += WallArr[x];
    }
    return sum;
}
