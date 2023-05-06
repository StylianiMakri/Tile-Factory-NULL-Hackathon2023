#ifndef TILEFACTORY_CANVAS_H
#define TILEFACTORY_CANVAS_H
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

vector<std::vector<bool>> generateCanvas(int rows, int cols, vector<pair<int, int>> holes);
char* generateCanvas(char* canvas);
char** createCanvas(int rows,int cols);
void displayCanvas(char** canvas, int rows, int cols);
void initCanvas(char** canvas, int rows, int cols, int num_holes);
bool locateShape(char* canvas, int* shape);
void countCells(char* canvas, int rows, int cols, int& numEmpty, int& numFilled);
char** insertShape(char** canvas, char* shape);
#endif //TILEFACTORY_CANVAS_H
