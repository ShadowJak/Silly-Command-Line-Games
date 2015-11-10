// Adrian Melendez
// A silly program I made while taking Intro to C

#include <stdio.h>
#include <stdlib.h>

#define XRATIO 5
#define YRATIO 3

void DrawLine(int xGrid);
void DrawGrid(int xGrid, int yGrid, int xPos, int yPos, int xGoal, int yGoal, char Player, char Goal);

int main() {
    int GridMult = 5;
    int xGrid = GridMult * XRATIO;
    int yGrid = GridMult * YRATIO;

    int xPos = 1;
    int yPos = 1;

    int xGoal = xGrid - 2;
    int yGoal = yGrid - 2;

    int TurnCounter = 0;
    int TurnLimit = (xGrid + yGrid) * 2;

    char Player = 'X';
    char Goal = 'O';
    char PInput;

    printf("Controls:\n\nW: Up\nS: Down\nA: Left\nD: Right\nEnter: Execute Move(s)\n");
    printf("\nPress Enter to start.\n\n");
    getchar();

    system("cls");

    int x, y;
    while (1) {
        DrawGrid(xGrid, yGrid, xPos, yPos, xGoal, yGoal, Player, Goal);
        printf("\n");

        if (xPos == xGoal && yPos == yGoal){
            printf("You Win!\n\n");
            break;
        }
        if (TurnCounter > TurnLimit) {
            printf("You Lose!\n\n");
            break;
        }

        scanf("%c",&PInput);
        PInput = toupper(PInput);

        switch (PInput) {
        case 'W':
            if (yPos > 1)
                yPos--;
                TurnCounter++;
            break;
        case 'S':
            if (yPos < yGrid - 2)
                yPos++;
                TurnCounter++;
            break;
        case 'A':
            if (xPos > 1)
                xPos--;
                TurnCounter++;
            break;
        case 'D':
            if (xPos < xGrid - 2)
                xPos++;
                TurnCounter++;
            break;
        }

        system("cls");
    }

    return 0;
}

void DrawGrid(int xGrid, int yGrid, int xPos, int yPos, int xGoal, int yGoal, char Player, char Goal){
    int x, y;
    for (y = 0; y < yGrid; y++) {
        if (y == 0 || y == yGrid - 1) {
            DrawLine(xGrid);
            continue;
        }
        for (x = 0; x < xGrid; x++) {
            if (x ==  xPos && y == yPos) {
                printf("%c", Player);
            } else if (x == xGoal && y == yGoal) {
                printf("%c", Goal);
            } else if (x == 0 || x == xGrid - 1) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void DrawLine(int xGrid) {
    int x;
    for (x = 0; x < xGrid; x++) {
        if (x == 0 || x == xGrid - 1){
            printf("+");
        } else {
            printf("-");
        }
    }
    printf("\n");
}
