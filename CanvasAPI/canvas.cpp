#include "canvas.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../stabilityAPI/stability.h"



char* generateCanvas(char* canvas){
    //createCanvas(canvas,5,12);
  //  initCanvas(canvas,5,12,2);

    return canvas;

}


char** createCanvas(int rows, int cols) {
    char** canvas = new char*[rows];
    for (int i = 0; i < rows; i++) {
        canvas[i] = new char[cols];
        for (int j = 0; j < cols; j++) {
            canvas[i][j] = ' ';
        }
    }
    return canvas;
}



//display canvas to console
void displayCanvas(char** canvas, int rows, int cols){

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("+---");
        }
        printf("+\n");
        for (int j = 0; j < cols; j++) {
            printf("| %c ", canvas[i][j] );
        }
        printf("|\n");
    }
    for (int j = 0; j < cols; j++) {
        printf("+---");
    }
    printf("+\n");
}
//Initialize values of a canvas
void initCanvas(char** canvas, int rows, int cols, int num_holes) {
    srand(time(NULL));
    for (int k = 1; k <= num_holes; k++) {
        int row = rand() % rows;
        int col = rand() % cols;
        canvas[row][col] = 'B';
    }
}

bool locateShape(int* canvas, int* shape){

    int n = sizeof(canvas);
    int m = sizeof(shape);
    if (m > n) {
        return false;
    }

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (canvas[i + j] != shape[j]) break;
        }
        if (j == m) return true;
    }

    return false;
}

void countCells(char* canvas, int rows, int cols, int& numEmpty, int& numFilled){
    numEmpty = 0;
    numFilled = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (canvas[i * cols + j] == 0) {
                numEmpty++;
            } else if (canvas[i * cols + j] != 0) {
                numFilled++;
            }
        }
    }

}



std::string shapesPositions(char* canvas, int rows, int cols) {
    std::string result = "";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char c = canvas[i * cols + j];
            if (c == -1) {
                result += "B";
            } else if (c >= 'A' && c <= 'Z') {
                result += c;
            } else {
                result += " ";
            }
        }
        if (i != rows - 1) {
            result += " ";
        }
    }
    return result;
}
char** insertShape(char** canvas, char* shape) {
    
}

