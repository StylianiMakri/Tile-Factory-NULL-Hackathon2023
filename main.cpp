#include <iostream>
#include <vector>
#include <cmath>
#include "CanvasAPI/canvas.h"
#include "TileAPI/shapes.h"

using namespace std;


// Generate  orthogonal canvas with "holes"

void printCavas(auto canvas, int rows, int cols){

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (canvas[i][j]) {
                cout << "B "; // Hole cell
            } else {
                cout << ". "; // Empty cell
            }
        }
        cout << endl;
    }
}



// Define a struct to represent a Pentomino shape
struct Pentomino {
    char letter;
    vector<pair<int, int>> coords; // List of (row, col) coordinates
};

vector<Pentomino> generatePentominos() {
    vector<Pentomino> pentominos;

    // Add each Pentomino shape with its corresponding letter and coordinates
    pentominos.push_back({'F', {{0, 1}, {0, 2}, {1, 0}, {1, 1}, {2, 1}}});
    pentominos.push_back({'I', {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}}});
    pentominos.push_back({'L', {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {3, 1}}});
    pentominos.push_back({'N', {{0, 1}, {1, 1}, {2, 0}, {2, 1}, {3, 0}}});
    pentominos.push_back({'P', {{0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 0}}});
    pentominos.push_back({'T', {{0, 0}, {0, 1}, {0, 2}, {1, 1}, {2, 1}}});
    pentominos.push_back({'U', {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {0, 2}}});
    pentominos.push_back({'V', {{0, 2}, {1, 2}, {2, 0}, {2, 1}, {2, 2}}});
    pentominos.push_back({'W', {{0, 0}, {1, 0}, {1, 1}, {2, 1}, {2, 2}}});
    pentominos.push_back({'X', {{0, 1}, {1, 0}, {1, 1}, {1, 2}, {2, 1}}});
    pentominos.push_back({'Y', {{0, 1}, {1, 0}, {1, 1}, {2, 1}, {3, 1}}});
    pentominos.push_back({'Z', {{0, 0}, {0, 1}, {1, 1}, {2, 1}, {2, 2}}});

    return pentominos;
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



bool canShapeFit(auto canvas, Pentomino shape, int row, int col) {
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

void addShapeToCanvas(auto &canvas, Pentomino shape) {
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

int main(){
    int rows = 5;
    int cols = 12;

    //initialize canva and pentomino shapes
    vector<pair<int, int>> holes = {{2, 3}, {2, 8}}; // (row, col) pairs of black cells
    auto canvas = generateCanvas(rows, cols, holes);
    auto pentominos = generatePentominos();

    // Print canvas
    cout << "Canvas: ";
    printCavas(canvas,rows,cols);

    //print pentonimo shapes
    cout << "Letters: ";
    for (auto p : pentominos) {
        cout << p.letter << ':' << endl;
        displayPentomino(p);
        cout << endl;
    }

    //print all possible position for all shapes (no rotate)
    for(int i=0; i<12; i++){
        Pentomino shape = pentominos[i];
        std::vector<std::vector<std::pair<int, int>>> positions = getAllPositions(shape, rows, cols);
        std::cout << "All possible positions for shape " << shape.letter << " inside a " << rows << "x" << cols << " canvas:\n";
        for (const auto& pos : positions) {
            std::cout << "[";
            for (const auto& coord : pos) {
                std::cout << "(" << coord.first << "," << coord.second << ")";
            }
            std::cout << "]\n";
        }
    }

    //rotation
    for(int i =0; i<12; i++){
        Pentomino p = pentominos[i];
        char rotation;
        cout << "Enter rotation for " << p.letter << " (0,90,180 or 270 degrees) or mirrored in X or Y axis: " <<endl;
        cin >> rotation;
    switch (rotation) {
        case 0: {
            displayPentomino(p);
            cout << endl;
        }
        break;
        case 90: {
            rotatePentomino(p);
            displayPentomino(p);
            cout << endl;
        }
        break;
        case 180:{
            rotatePentomino(p);
            rotatePentomino(p);
            displayPentomino(p);
            cout << endl;
        }
        break;
        case 270: {
            rotatePentomino(p);
            rotatePentomino(p);
            rotatePentomino(p);
            displayPentomino(p);
            cout << endl;
        }
        break;
        case 'X': {
            flipPentomino(p,rotation);
            displayPentomino(p);
            cout << endl;
        }
            break;
        case 'Y': {
            flipPentomino(p,rotation);
            displayPentomino(p);
            cout << endl;
        }
            break;
        default:
        {
            cout << "Invalid input" <<endl;
        }
        break;
    };
    }



    addShapeToCanvas(canvas, pentominos[0]);
    printCavas(canvas,rows,cols);
    return 0;
    }




