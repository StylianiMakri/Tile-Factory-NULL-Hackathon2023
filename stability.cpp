#include <cstddef>
#include <cstdlib>
#include <iostream>
#include "../TileAPI/shapes.h"
#include "../CanvasAPI/canvas.h"

void checkForMemoryError(char * arr){

    if (arr == NULL)
    {
        std::cout<<"Memory Error...";
        exit(1);
    }

}

/*void freeMemory(){
    delete [] canvas;
    delete [] F;
    delete [] I;
    delete [] L;
    delete [] N;
    delete [] P;
    delete [] T;
    delete [] U;
    delete [] V;
    delete [] W;
    delete [] X;
    delete [] Y;
    delete [] Z;
}
 */