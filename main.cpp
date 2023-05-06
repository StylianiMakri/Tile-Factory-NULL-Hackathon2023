#include <iostream>
#include "CanvasAPI/canvas.h"
#include "TileAPI/shapes.h"
#include "stabilityAPI/stability.h"


char* canvas;
char *F, *I, *L, *N, *P,*T,*U,*V,*W,*X,*Y,*Z;
int main() {
    int rows, cols,num_holes;
    std:: cout << std::endl;
    std::cout << "Enter rows: " ;
    std:: cin >> rows;
    std:: cout << std::endl;
    std:: cout << "Enter cols: ";
    std:: cin >> cols;
    std:: cout << std::endl;
    std:: cout << "Enter numholes: ";
    std:: cin >> num_holes ;
    std:: cout << std::endl;

    char** canvas = createCanvas(rows, cols);
    initCanvas(canvas, rows, cols, num_holes);
    displayCanvas(canvas, rows, cols);

    return 0;
}

