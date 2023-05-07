#include "shapes.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>


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

void rotatePentomino(Pentomino& p) {
    for (auto& coord : p.coords) {
        int i = coord.first;
        int j = coord.second;
        int n =5; // number of rows/columns
        int k = j;
        int l = n - i - 1;
        coord = make_pair(k, l);
    }
}
void flipPentomino(Pentomino& p, char rotation) {
    if (rotation == 'X') {
        for (auto &coord: p.coords) {
            coord = make_pair(coord.first, -(coord.second));
        }
    }
    else if (rotation == 'Y') {
        for (auto &coord: p.coords) {
            int i = coord.first;
            int j = coord.second;
            int n = 4; // number of rows/columns
            int k = n - i - 1;
            int l = j;
            coord = make_pair(k, l);
        }
    }
    else {
        cout << "invalid input" ;
    }

}


std::vector<std::vector<std::pair<int, int>>> getAllPositions(const Pentomino& shape, int rows, int cols) {
    std::vector<std::vector<std::pair<int, int>>> positions;



    for (int i = 0; i <= rows - 5; i++) {
        for (int j = 0; j <= cols - 5; j++) {
            std::vector<std::pair<int, int>> current_position;
            bool valid_position = true;
            for (const auto& coord : shape.coords) {
                int row = i + coord.first;
                int col = j + coord.second;
                if (row >= rows || col >= cols) {
                    valid_position = false;
                    break;
                }
                current_position.emplace_back(row, col);
            }
            if (valid_position) {
                positions.push_back(current_position);
            }
        }
    }

    return positions;
}











