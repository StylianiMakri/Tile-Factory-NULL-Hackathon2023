#include <iostream>
#include <vector>
#include <cmath>
#include "CanvasAPI/canvas.h"
#include "TileAPI/shapes.h"
#include <chrono>

using namespace std;
using namespace std::chrono;


int main() {
    int rows;
    int cols;

    cout << "Give rows: ";
    cin >> rows;
    cout << endl;
    cout << "Give cols: ";
    cin >> cols;

    //initialize canva and pentomino shapes
    vector<pair<int, int>> holes = {{2, 3},
                                    {2, 8}}; // (row, col) pairs of black cells

    auto start = high_resolution_clock::now();
    auto canvas = generateCanvas(rows, cols, holes);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Initialize canvas: " << duration.count() << "ms";

    start = high_resolution_clock::now();
    auto pentominos = generatePentominos();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Initialize shapes: " << duration.count() << "ms";


    // Print canvas
    cout << "Canvas: " << endl;
    displayCanvas(canvas, rows, cols);

    //print pentonimo shapes
    cout << "Letters: ";
    for (auto p: pentominos) {
        cout << p.letter << ':' << endl;
        displayPentomino(p);
        cout << endl;
    }

    //print all possible position for all shapes (no rotate)
    for (int i = 0; i < 12; i++) {
        Pentomino shape = pentominos[i];
        std::vector<std::vector<std::pair<int, int>>> positions = getAllPositions(shape, rows, cols);
        std::cout << "All possible positions for shape " << shape.letter << " inside a " << rows << "x" << cols
                  << " canvas:\n";
        for (const auto &pos: positions) {
            std::cout << "[";
            for (const auto &coord: pos) {
                std::cout << "(" << coord.first << "," << coord.second << ")";
            }
            std::cout << "]\n";
        }
    }

    //rotation
    for (int i = 0; i < 12; i++) {
        Pentomino p = pentominos[i];
        char rotation;
        cout << "Enter rotation for " << p.letter << " (0,90,180 or 270 degrees) or mirrored in X or Y axis: " << endl;
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
            case 180: {
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
                flipPentomino(p, rotation);
                displayPentomino(p);
                cout << endl;
            }
                break;
            case 'Y': {
                flipPentomino(p, rotation);
                displayPentomino(p);
                cout << endl;
            }
                break;
            default: {
                cout << "Invalid input" << endl;
            }
                break;
        };
    }


    return 0;
    }