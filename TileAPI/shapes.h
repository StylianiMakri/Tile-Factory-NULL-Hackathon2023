#ifndef TILEFACTORY_SHAPES_H
#define TILEFACTORY_SHAPES_H

void generateShapes(char *F,char *I,char *L,char *N,char *P,char *T,char*U,char*V,char*W,char*X,char*Y,char*Z);
void initF(char* F);
void initI(char* I);
void initL(char* L);
void initN(char* N);
void initP(char* P);
void initT(char* T);
void initU(char* U);
void initV(char* V);
void initW(char* W);
void initX(char* X);
void initY(char* Y);
void initZ(char* Z);

int* rotateShape(int* shape,int degrees, int* rotatedShape);
int* flipShape(int* shape,int axis, int* flippedShape);
void displayShape(int* rotatedshape);
void flipPentomino(Pentomino& p, char rotation);

#endif //TILEFACTORY_SHAPES_H
