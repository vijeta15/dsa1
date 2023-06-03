#include <stdio.h>

int main() {
    // Create a 2D array for the chessboard
    char chessboard[8][8];

    // Initialize the chessboard with empty spaces
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            chessboard[row][col] = '-';
        }
    }

    // Place black coins on the chessboard
    chessboard[0][0] = 'r';  // Black rook
    chessboard[0][1] = 'n';  // Black knight
    chessboard[0][2] = 'b';  // Black bishop
    chessboard[0][3] = 'q';  // Black queen
    chessboard[0][4] = 'k';  // Black king
    chessboard[0][5] = 'b';  // Black bishop
    chessboard[0][6] = 'n';  // Black knight
    chessboard[0][7] = 'r';  // Black rook

    for (int col = 0; col < 8; col++) {
        chessboard[1][col] = 'p';  // Black pawn
    }

    // Place white coins on the chessboard
    chessboard[7][0] = 'R';  // White rook
    chessboard[7][1] = 'N';  // White knight
    chessboard[7][2] = 'B';  // White bishop
    chessboard[7][3] = 'Q';  // White queen
    chessboard[7][4] = 'K';  // White king
    chessboard[7][5] = 'B';  // White bishop
    chessboard[7][6] = 'N';  // White knight
    chessboard[7][7] = 'R';  // White rook

    for (int col = 0; col < 8; col++) {
        chessboard[6][col] = 'P';  // White pawn
    }

    // Display the chessboard with the positions of coins
    printf("Chessboard:\n");
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            printf("%c ", chessboard[row][col]);
        }
        printf("\n");
    }

    return 0;
}
