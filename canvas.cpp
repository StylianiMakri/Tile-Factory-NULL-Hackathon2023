#include "canvas.h"
#include <iostream>

using namespace std;

vector<vector<bool>> generateCanvas(int rows, int cols, vector<pair<int, int>> holes) {
    // Initialize canvas with all white cells
    vector<vector<bool>> canvas(rows, vector<bool>(cols, false));

    // Mark black cells
    for (auto hole : holes) {
        int row = hole.first;
        int col = hole.second;
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            canvas[row][col] = true;
        }
    }

    return canvas;
}


//display canvas to console
void displayCanvas(vector<std::vector<bool>> canvas, int rows, int cols){

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (canvas[i][j]) {
                std::cout << "B "; // Hole cell
            } else {
                std::cout << ". "; // Empty cell
            }
        }
        std::cout << std::endl;
    }
}

bool isPositionAvailable(vector<std::vector<bool> >canvas, int row, int col) {
    // check if the given position is available (i.e., contains a 0)
    return canvas[row][col] == 0;
}

bool canShapeFit(vector<std::vector<bool>> canvas, Pentomino shape, int row, int col) {
    // check if the shape can fit starting at the given position
    for (auto& coord : shape.coords) {
        int r = coord.first + row;
        int c = coord.second + col;
        if (r < 0 || r >= canvas.size() || c < 0 || c >= canvas[0].size() || !isPositionAvailable(canvas, r, c)) {
            return false;
        }
    }
    return true;
}

void addShapeToCanvas(vector<std::vector<bool>> &canvas, Pentomino shape) {
    // try to fit the shape at each position in the canvas
    for (int row = 0; row < canvas.size(); row++) {
        for (int col = 0; col < canvas[0].size(); col++) {
            if (canShapeFit(canvas, shape, row, col)) {
                // shape can fit at this position, so add it to the canvas
                for (auto &coord: shape.coords) {
                    int r = coord.first + row;
                    int c = coord.second + col;
                    canvas[r][c] = shape.letter;
                }
                return;
            }
        }
    }
}



