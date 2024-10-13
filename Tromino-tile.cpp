#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int board[1000][1000];
int no = 0;

void trominoTile(int xBoard, int yBoard, int y_hole, int x_hole, int boardSize) {
    int halfSize = boardSize / 2;
    int xCenter = xBoard + halfSize - 1;
    int yCenter = yBoard + halfSize - 1;

    if (boardSize == 2) {
        if (board[yBoard][xBoard + 1] == 0 &&
            board[yBoard + 1][xBoard] == 0 &&
            board[yBoard + 1][xBoard + 1] == 0) {
            no++;
            board[yBoard][xBoard + 1] = no;
            board[yBoard + 1][xBoard] = no;
            board[yBoard + 1][xBoard + 1] = no;
        }
        if (board[yBoard][xBoard] == 0 &&
            board[yBoard + 1][xBoard] == 0 &&
            board[yBoard + 1][xBoard + 1] == 0) {
            no++;
            board[yBoard][xBoard] = no;
            board[yBoard + 1][xBoard] = no;
            board[yBoard + 1][xBoard + 1] = no;
        }
        if (board[yBoard][xBoard + 1] == 0 &&
            board[yBoard][xBoard] == 0 &&
            board[yBoard + 1][xBoard + 1] == 0) {
            no++;
            board[yBoard + 1][xBoard + 1] = no;
            board[yBoard][xBoard + 1] = no;
            board[yBoard][xBoard] = no;
        }
        if (board[yBoard][xBoard + 1] == 0 &&
            board[yBoard + 1][xBoard] == 0 &&
            board[yBoard][xBoard] == 0) {
            no++;
            board[yBoard][xBoard] = no;
            board[yBoard][xBoard + 1] = no;
            board[yBoard + 1][xBoard] = no;
        }
        return;
    }

    if (y_hole <= yCenter) {
        if (x_hole <= xCenter) {
            if (board[yCenter][xCenter + 1] == 0 &&
                board[yCenter + 1][xCenter] == 0 &&
                board[yCenter + 1][xCenter + 1] == 0) {
                no++;
                board[yCenter][xCenter + 1] = no;
                board[yCenter + 1][xCenter] = no;
                board[yCenter + 1][xCenter + 1] = no;
            }
        } else {
            if (board[yCenter][xCenter] == 0 &&
                board[yCenter + 1][xCenter] == 0 &&
                board[yCenter + 1][xCenter + 1] == 0) {
                no++;
                board[yCenter][xCenter] = no;
                board[yCenter + 1][xCenter + 1] = no;
                board[yCenter + 1][xCenter] = no;
            }
        }
    } else {
        if (x_hole <= xCenter) {
            if (board[yCenter][xCenter + 1] == 0 &&
                board[yCenter][xCenter] == 0 &&
                board[yCenter + 1][xCenter + 1] == 0) {
                no++;
                board[yCenter][xCenter] = no;
                board[yCenter][xCenter + 1] = no;
                board[yCenter + 1][xCenter + 1] = no;
            }
        } else {
            if (board[yCenter + 1][xCenter] == 0 &&
                board[yCenter][xCenter] == 0 &&
                board[yCenter][xCenter + 1] == 0) {
                no++;
                board[yCenter][xCenter] = no;
                board[yCenter][xCenter + 1] = no;
                board[yCenter + 1][xCenter] = no;
            }
        }
    }

    if (y_hole <= yCenter) {
        if (x_hole <= xCenter) {
            trominoTile(xBoard, yBoard, y_hole, x_hole, halfSize);
            trominoTile(xBoard, yCenter + 1, yCenter + 1, xCenter + 1, halfSize);
            trominoTile(xCenter + 1, yBoard, yCenter, xCenter, halfSize);
            trominoTile(xCenter + 1, yCenter + 1, yCenter + 1, xCenter + 1, halfSize);
        } else {
            trominoTile(xBoard, yBoard, yCenter, xCenter, halfSize);
            trominoTile(xBoard, yCenter + 1, y_hole, x_hole, halfSize);
            trominoTile(xCenter + 1, yBoard, yCenter, xCenter, halfSize);
            trominoTile(xCenter + 1, yCenter + 1, yCenter + 1, xCenter + 1, halfSize);
        }
    } else {
        if (x_hole <= xCenter) {
            trominoTile(xBoard, yBoard, yCenter, xCenter, halfSize);
            trominoTile(xBoard, yCenter + 1, yCenter + 1, xCenter + 1, halfSize);
            trominoTile(xCenter + 1, yBoard, y_hole, x_hole, halfSize);
            trominoTile(xCenter + 1, yCenter + 1, yCenter + 1, xCenter + 1, halfSize);
        } else {
            trominoTile(xBoard, yBoard, yCenter, xCenter, halfSize);
            trominoTile(xBoard, yCenter + 1, yCenter + 1, xCenter + 1, halfSize);
            trominoTile(xCenter + 1, yBoard, x_hole, y_hole, halfSize);
            trominoTile(xCenter + 1, yCenter + 1, y_hole, x_hole, halfSize);
        }
    }
}

int main() {
    int boardSize, x_hole, y_hole;
    scanf("%d", &boardSize);
    scanf("%d%d", &x_hole, &y_hole);

    int n = pow(2, boardSize);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            board[i][j] = 0;
        }
    }
    board[y_hole][x_hole] = -1;
    trominoTile(1, 1, y_hole, x_hole, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == y_hole && j == x_hole) {
                printf("%4s", "-1");
            } else {
                printf("%4d", board[i][j]);
            }
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
