#ifndef TILEFACTORY_CANVAS_H
#define TILEFACTORY_CANVAS_H
#include "../TileAPI/shapes.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>


using namespace std;

vector<std::vector<bool>> generateCanvas(int rows, int cols, vector<pair<int, int>> holes);
void displayCanvas(vector<std::vector<bool>> canvas, int rows, int cols);
bool isPositionAvailable(vector<std::vector<bool>> canvas, int row, int col);
bool canShapeFit(vector<std::vector<bool>> canvas, Pentomino shape, int row, int col);
void addShapeToCanvas(vector<std::vector<bool>> &canvas, Pentomino shape);
std::vector<std::vector<std::pair<int, int>>> getAllPositions(const Pentomino& shape, int rows, int cols);
#endif //TILEFACTORY_CANVAS_H
