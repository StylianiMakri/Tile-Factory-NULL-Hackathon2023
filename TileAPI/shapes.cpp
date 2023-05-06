#include "shapes.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "../stabilityAPI/stability.h"

void generateShapes(char *F,char *I,char *L,char *N,char *P,char *T,char*U,char*V,char*W,char*X,char*Y,char*Z){
    initF(F);
    initI(I);
    initL(L);
    initN(N);
    initP(P);
    initT(T);
    initU(U);
    initV(V);
    initW(W);
    initX(X);
    initY(Y);
    initZ(Z);

}
//Initializes Shape F
void initF(char* F){
    F = new char[25];
    checkForMemoryError(F);
    F[0] = ' ';
    F[1] = ' ';
    F[2] = ' ';
    F[3] = ' ';
    F[4] = ' ';
    F[5] = ' ';
    F[6] = ' ';
    F[7] = 'F';
    F[8] = 'F';
    F[9] = ' ';
    F[10] = ' ';
    F[11] = 'F';
    F[12] = 'F';
    F[13] = ' ';
    F[14] = ' ';
    F[15] = ' ';
    F[16] = ' ';
    F[17] = 'F';
    F[18] = ' ';
    F[19] = ' ';
    F[20] = ' ';
    F[21] = ' ';
    F[22] = ' ';
    F[23] = ' ';
    F[24] = ' ';


}

//Initializes Shape I
void initI(char* I) {
    I = new char[25];
    checkForMemoryError(I);
    I[0] = ' ';
    I[1] = 'I';
    I[2] = ' ';
    I[3] = ' ';
    I[4] = ' ';
    I[5] = ' ';
    I[6] = ' ';
    I[7] = 'I';
    I[8] = ' ';
    I[9] = ' ';
    I[10] = ' ';
    I[11] = ' ';
    I[12] = 'I';
    I[13] = ' ';
    I[14] = ' ';
    I[15] = ' ';
    I[16] = ' ';
    I[17] = 'I';
    I[18] = ' ';
    I[19] = ' ';
    I[20] = ' ';
    I[21] = ' ';
    I[22] = 'I';
    I[23] = ' ';
    I[24] = ' ';


}
//Initializes Shape L
void initL(char* L){
     L = new char[25];
    checkForMemoryError(L);
    L[0] = ' ';
    L[1] = ' ';
    L[2] = 'L';
    L[3] = ' ';
    L[4] = ' ';
    L[5] = ' ';
    L[6] = ' ';
    L[7] = 'L';
    L[8] = ' ';
    L[9] = ' ';
    L[10] = ' ';
    L[11] = ' ';
    L[12] = 'L';
    L[13] = ' ';
    L[14] = ' ';
    L[15] = ' ';
    L[16] = ' ';
    L[17] = 'L';
    L[18] = 'L';
    L[19] = ' ';
    L[20] = ' ';
    L[21] = ' ';
    L[22] = ' ';
    L[23] = 'L';
    L[24] = ' ';


}
//Initializes Shape N
void initN(char* N) {
    N = new char[25];
    checkForMemoryError(N);
    N[0] = ' ';
    N[1] = ' ';
    N[2] = 'N';
    N[3] = ' ';
    N[4] = ' ';
    N[5] = ' ';
    N[6] = ' ';
    N[7] = 'N';
    N[8] = ' ';
    N[9] = ' ';
    N[10] = ' ';
    N[11] = ' ';
    N[12] = 'N';
    N[13] = ' ';
    N[14] = ' ';
    N[15] = ' ';
    N[16] = 'N';
    N[17] = 'N';
    N[18] = ' ';
    N[19] = ' ';
    N[20] = ' ';
    N[21] = ' ';
    N[22] = ' ';
    N[23] = ' ';
    N[24] = ' ';


}

//Initializes Shape P
void initP(char* P) {
    P = new char[25];
    checkForMemoryError(P);
    P[0] = ' ';
    P[1] = ' ';
    P[2] = ' ';
    P[3] = ' ';
    P[4] = ' ';
    P[5] = ' ';
    P[6] = ' ';
    P[7] = ' ';
    P[8] = ' ';
    P[9] = ' ';
    P[10] = ' ';
    P[11] = 'P';
    P[12] = 'P';
    P[13] = ' ';
    P[14] = ' ';
    P[15] = ' ';
    P[16] = 'P';
    P[17] = 'P';
    P[18] = ' ';
    P[19] = ' ';
    P[20] = ' ';
    P[21] = 'P';
    P[22] = ' ';
    P[23] = ' ';
    P[24] = ' ';


}
//Initializes Shape T
void initT(char* T) {
    T = new char[25];
    checkForMemoryError(T);
    T[0] = ' ';
    T[1] = ' ';
    T[2] = ' ';
    T[3] = ' ';
    T[4] = ' ';
    T[5] = ' ';
    T[6] = ' ';
    T[7] = ' ';
    T[8] = ' ';
    T[9] = ' ';
    T[10] = ' ';
    T[11] = 'T';
    T[12] = 'T';
    T[13] = 'T';
    T[14] = ' ';
    T[15] = ' ';
    T[16] = ' ';
    T[17] = 'T';
    T[18] = ' ';
    T[19] = ' ';
    T[20] = ' ';
    T[21] = ' ';
    T[22] = 'T';
    T[23] = ' ';
    T[24] = ' ';

}
//Initializes Shape U
void initU(char* U) {
    U = new char[25];
    checkForMemoryError(U);
    U[0] = ' ';
    U[1] = ' ';
    U[2] = ' ';
    U[3] = ' ';
    U[4] = ' ';
    U[5] = ' ';
    U[6] = ' ';
    U[7] = ' ';
    U[8] = ' ';
    U[9] = ' ';
    U[10] = ' ';
    U[11] = ' ';
    U[12] = ' ';
    U[13] = ' ';
    U[14] = ' ';
    U[15] = ' ';
    U[16] = 'U';
    U[17] = ' ';
    U[18] = 'U';
    U[19] = ' ';
    U[20] = ' ';
    U[21] = 'U';
    U[22] = 'U';
    U[23] = 'U';
    U[24] = ' ';

}

//Initializes Shape V
void initV(char* V) {
    V = new char[25];
    checkForMemoryError(V);
    V[0] = ' ';
    V[1] = ' ';
    V[2] = ' ';
    V[3] = ' ';
    V[4] = ' ';
    V[5] = ' ';
    V[6] = ' ';
    V[7] = ' ';
    V[8] = ' ';
    V[9] = ' ';
    V[10] = ' ';
    V[11] = ' ';
    V[12] = ' ';
    V[13] = 'V';
    V[14] = ' ';
    V[15] = ' ';
    V[16] = ' ';
    V[17] = ' ';
    V[18] = 'V';
    V[19] = ' ';
    V[20] = ' ';
    V[21] = 'V';
    V[22] = 'V';
    V[23] = 'V';
    V[24] = ' ';

}

//Initializes Shape W
void initW(char* W) {
    W = new char[25];
    checkForMemoryError(W);
    W[0] = ' ';
    W[1] = ' ';
    W[2] = ' ';
    W[3] = ' ';
    W[4] = ' ';
    W[5] = ' ';
    W[6] = ' ';
    W[7] = ' ';
    W[8] = ' ';
    W[9] = ' ';
    W[10] = ' ';
    W[11] = 'W';
    W[12] = ' ';
    W[13] = ' ';
    W[14] = ' ';
    W[15] = ' ';
    W[16] = 'W';
    W[17] = 'W';
    W[18] = ' ';
    W[19] = ' ';
    W[20] = ' ';
    W[21] = ' ';
    W[22] = 'W';
    W[23] = 'W';
    W[24] = ' ';


}
//Initializes Shape X
void initX(char* X) {
    X = new char[25];
    checkForMemoryError(X);
    X[0] = ' ';
    X[1] = ' ';
    X[2] = ' ';
    X[3] = ' ';
    X[4] = ' ';
    X[5] = ' ';
    X[6] = ' ';
    X[7] = ' ';
    X[8] = ' ';
    X[9] = ' ';
    X[10] = ' ';
    X[11] = ' ';
    X[12] = 'X';
    X[13] = ' ';
    X[14] = ' ';
    X[15] = ' ';
    X[16] = 'X';
    X[17] = 'X';
    X[18] = 'X';
    X[19] = ' ';
    X[20] = ' ';
    X[21] = ' ';
    X[22] = 'X';
    X[23] = ' ';
    X[24] = ' ';


}
//Initializes Shape Y
void initY(char* Y) {
    Y = new char[25];
    checkForMemoryError(Y);
    Y[0] = ' ';
    Y[1] = ' ';
    Y[2] = ' ';
    Y[3] = ' ';
    Y[4] = ' ';
    Y[5] = ' ';
    Y[6] = ' ';
    Y[7] = 'Y';
    Y[8] = ' ';
    Y[9] = ' ';
    Y[10] = ' ';
    Y[11] = 'Y';
    Y[12] = 'Y';
    Y[13] = ' ';
    Y[14] = ' ';
    Y[15] = ' ';
    Y[16] = ' ';
    Y[17] = ' ';
    Y[18] = 'Y';
    Y[19] = ' ';
    Y[20] = ' ';
    Y[21] = ' ';
    Y[22] = 'Y';
    Y[23] = ' ';
    Y[24] = ' ';

}
//Initializes Shape Z
void initZ(char*Z) {
    Z = new char[25];
    checkForMemoryError(Z);
    Z[0] = ' ';
    Z[1] = ' ';
    Z[2] = ' ';
    Z[3] = ' ';
    Z[4] = ' ';
    Z[5] = ' ';
    Z[6] = ' ';
    Z[7] = ' ';
    Z[8] = ' ';
    Z[9] = ' ';
    Z[10] = ' ';
    Z[11] = 'Z';
    Z[12] = 'Z';
    Z[13] = ' ';
    Z[14] = ' ';
    Z[15] = ' ';
    Z[16] = ' ';
    Z[17] = 'Z';
    Z[18] = ' ';
    Z[19] = ' ';
    Z[20] = ' ';
    Z[21] = ' ';
    Z[22] = 'Z';
    Z[23] = 'Z';
    Z[24] = ' ';

}

int* rotateShape(int* shape,int degrees, int* rotatedShape){
    switch (degrees) {
        case 0:
            for (int i = 0; i < 5 * 5; i++) {
                rotatedShape[i] = shape[i];
            }
            break;
        case 90:
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    rotatedShape[j * 5 + (4 - i)] = shape[i * 5 + j];
                }
            }
            break;
            case 180:
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        rotatedShape[(5 - 1 - i) * 5 + (5 - 1 - j)] = shape[i * 5 + j];
                    }
                }
                break;case 270:
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            rotatedShape[(4 - j) * 5 + i] = shape[i * 5 + j];
                        }
                    }
                break;
            }
    return rotatedShape;
    }



int* flipShape(int* shape,int axis, int* flippedShape) {
    if (axis == 'x') {
        // flip along the x-axis (mirror horizontally)
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                flippedShape[(5 - 1 - i) * 5 + j] = shape[i * 5 + j];
            }
        }
    } else if (axis == 'y') {
        // flip along the y-axis (mirror vertically)
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                flippedShape[i * 5 + (5 - 1 - j)] = shape[i * 5 + j];
            }
        }
    }
    return flippedShape;
}

void displayShape(int* rotatedShape){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d",rotatedShape[i*5+j]);
        }
    }
}



