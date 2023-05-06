#include "shapes.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "../stabilityAPI/stability.h"

void generateShapes(char *F,char *I,char *L,char *N,char *P,char *T,char*U,char*V,char*W,char*X,char*Y,char*Z){
    initF(F);
    initI(I);
    initL(L);
    initN(N);
    initP(P);
    initT(T);
    initU(U);
    initV(V);
    initW(W);
    initX(X);
    initY(Y);
    initZ(Z);

}

void displayPentomino(const Pentomino& p) {
    // Find the dimensions of the shape
    int min_row = p.coords.front().first;
    int max_row = p.coords.front().first;
    int min_col = p.coords.front().second;
    int max_col = p.coords.front().second;
    for (auto coord : p.coords) {
        min_row = min(min_row, coord.first);
        max_row = max(max_row, coord.first);
        min_col = min(min_col, coord.second);
        max_col = max(max_col, coord.second);
    }
    int rows = max_row - min_row + 1;
    int cols = max_col - min_col + 1;

    // Initialize the grid to empty cells
    vector<vector<char>> grid(rows, vector<char>(cols, '.'));

    // Fill in the occupied cells
    for (auto coord : p.coords) {
        int row = coord.first - min_row;
        int col = coord.second - min_col;
        grid[row][col] = p.letter;
    }

    // Print the grid
    for (auto row : grid) {
        for (auto cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

int* rotateShape(int* shape,int degrees, int* rotatedShape){
    switch (degrees) {
        case 0:
            for (int i = 0; i < 5 * 5; i++) {
                rotatedShape[i] = shape[i];
            }
            break;
        case 90:
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    rotatedShape[j * 5 + (4 - i)] = shape[i * 5 + j];
                }
            }
            break;
            case 180:
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        rotatedShape[(5 - 1 - i) * 5 + (5 - 1 - j)] = shape[i * 5 + j];
                    }
                }
                break;case 270:
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            rotatedShape[(4 - j) * 5 + i] = shape[i * 5 + j];
                        }
                    }
                break;
            }
    return rotatedShape;
    }



int* flipShape(int* shape,int axis, int* flippedShape) {
    if (axis == 'x') {
        // flip along the x-axis (mirror horizontally)
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                flippedShape[(5 - 1 - i) * 5 + j] = shape[i * 5 + j];
            }
        }
    } else if (axis == 'y') {
        // flip along the y-axis (mirror vertically)
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                flippedShape[i * 5 + (5 - 1 - j)] = shape[i * 5 + j];
            }
        }
    }
    return flippedShape;
}

void displayShape(int* rotatedShape){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d",rotatedShape[i*5+j]);
        }
    }
}



