#ifndef TILEFACTORY_SHAPES_H
#define TILEFACTORY_SHAPES_H
#include <vector>
using namespace std;

struct Pentomino {
    char letter;
    vector<pair<int, int>> coords; // List of (row, col) coordinates
};

vector<Pentomino> generatePentominos();
void displayPentomino(const Pentomino& p);

void rotatePentomino(Pentomino& p);
int* flipShape(int* shape,int axis, int* flippedShape);
void displayShape(int* rotatedshape);
void flipPentomino(Pentomino& p, char rotation);

#endif //TILEFACTORY_SHAPES_H
