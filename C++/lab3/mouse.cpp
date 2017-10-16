#include <GL/glut.h>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include "const.h"

//return index of Checker
//otherwise 0
int searchChecker(int x, int y){
    for (int i = 0; i < check[0]->getCount(); i++){ //search checker
        if (check[i]->getIndex() > 0){ //alive
            float dist = sqrt(  pow(x - (check[i]->get_x() * CELL_WIDTH  + CELL_WIDTH/2) , 2) +
                                pow(y - (check[i]->get_y() * CELL_HEIGHT + CELL_HEIGHT/2), 2));
//            std::cout << "dist" << dist << std::endl;
//            std::cout << "checkRadius" << checkRadius << std::endl;
            if( dist <= checkRadius ){
                if (activeCheck != check[i]->getIndex())
                    activeCheck = check[i]->getIndex();
                else
                    activeCheck = -1;
                std::cout << "ACTIVE == " << activeCheck << std::endl;
                return activeCheck;
            }
        }
    }
    return 0;
}

void MousePressed(int button, int state, int x, int y){
    bool down = false;
    int foundIn;
    if (state == down )
        switch(button){
            case GLUT_LEFT_BUTTON:
                foundIn = searchChecker(x, y);
//                std::cout <<"Priority = " << priority << std::endl; /////????
//                if ((foundIn > check[0]->getCount()/2  && priority == -1) ||
//                    (foundIn <= check[0]->getCount()/2 && priority == 1)   )
                    //make step if not found new checker and have some active checker
                    if ( !foundIn && activeCheck > -1 ){
                        float dx, dy;
                        float x_pt = check[activeCheck-1]->get_x() * CELL_WIDTH  + CELL_WIDTH/2;
                        float y_pt = check[activeCheck-1]->get_y() * CELL_HEIGHT + CELL_HEIGHT/2;
                        dx = (float)(x - x_pt)/CELL_WIDTH;
                        dy = (float)(y - y_pt)/CELL_HEIGHT;
                        check[activeCheck-1]->move( round(dx), round(dy));
                        activeCheck = -1; //reset activeMode
                        //priority *= -1;
                        //not in that place!!!!!!!!!!!!
                    }
        }
}


void MouseMove(int ax, int ay){
    x = ax;
    y = ay;
    //glutSetWindowTitle("MouseMove");
//    printf("X = %d\n", x);
//    printf("Y = %d\n", y);
}


void MousePressedMove(int ax, int ay){
    x = ax;
    y = ay;
    //glutSetWindowTitle("MousePressedMove");
}
