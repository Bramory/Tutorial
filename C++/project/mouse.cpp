#include <GL/glut.h>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include <iostream>

#include "king.h"
#include "const.h"
#include "rules.h"

//return index of Checker [1..24] when we click on it
//otherwise 0
int searchChecker(int x, int y){
    for (int i = 0; i < check[0]->getCount(); i++){ //search checker
        if (check[i]->getIndex() > 0){ //on the board (alive)
            float dist = sqrt(  pow(x - (check[i]->get_x() * CELL_WIDTH  + CELL_WIDTH/2) , 2) +
                                pow(y - (check[i]->get_y() * CELL_HEIGHT + CELL_HEIGHT/2), 2));
//            std::cout << "dist" << dist << std::endl;
//            std::cout << "checkRadius" << checkRadius << std::endl;
            //click on it
            if( dist <= checkRadius ){
                if (activeCheck != check[i]->getIndex()){
                    //our choice from the mandatory list or list is empty
                    if( 1 == checkMandatoryTaking(check[i]->getIndex()) )
                        activeCheck = check[i]->getIndex(); //Change ActiveChecker
                }
                else
                    activeCheck = -1; //OFF Active
//                std::cout << "ACTIVE == " << activeCheck << std::endl;

                //we found unique checker
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
                system("cls");
                foundIn = searchChecker(x, y);
                std::cout <<"Priority = " << (priority == 1 ? "RED_TEAM" : "BLUE_TEAM") << std::endl; /////????
                std::cout <<"foundIn = " << foundIn << std::endl; /////????
                std::cout << "ACTIVE == " << activeCheck << std::endl;
                if ((activeCheck >  12 && activeCheck <= 24  && priority == BLUE_TEAM) || // -1
                    (activeCheck <= 12 && activeCheck >= 1   && priority == RED_TEAM)   ) //  1
                    //make step in empty place with activeChecker
                    if ( !foundIn && activeCheck > 0 )
                    {
                        float dx, dy;
                        // get position of the center for our activeChecker
                        float x_pt = check[activeCheck-1]->get_x() * CELL_WIDTH  + CELL_WIDTH/2;
                        float y_pt = check[activeCheck-1]->get_y() * CELL_HEIGHT + CELL_HEIGHT/2;

                        // how far we want go (in cells)
                        dx = (float)(x - x_pt)/CELL_WIDTH;
                        dy = (float)(y - y_pt)/CELL_HEIGHT;

                        int moveDetector = check[activeCheck-1]->move( round(dx), round(dy));
                                        // Hit
                        if ( moveDetector == 2 )
                        {
                            std::cout <<"STEP IS DONE " << std::endl;
                            //check if we can continue to hit another checkers
                            if ( check[activeCheck-1]->possibleMoves() == 1 ){
                                // fix index for activeCheck
                                // continue ...
                                std::cout <<"we have moves to hit -> continue " << std::endl;
                            }
                            else{
                                activeCheck = -1; //reset activeMode
                                priority *= -1;   // change player
                                std::cout <<"Priority CHANGE = " << priority << std::endl; /////????
                            }
                        }
                                    // illegal move
                        else if(  moveDetector == 0 ){
                            std::cout <<"illegal move " << std::endl;
                            activeCheck = -1; //reset activeMode
                        }
                                    //  "Move"
                        else if (moveDetector == 1){
                            std::cout <<"Make \"Move\" " << std::endl;
                            activeCheck = -1; //reset activeMode
                            priority *= -1;   // change player
                            std::cout <<"Priority CHANGE = " << priority << std::endl; /////????
                        }
                    }
                    break;
        case GLUT_RIGHT_BUTTON:
            foundIn = searchChecker(x, y);
            if(foundIn > 0 )
                (*check[activeCheck-1])--;
            else if (y < height/2)
                    for (int i = 0; i < 12; i++){ //for all checkers
                      (*check[i])--;
                    }
                else
                    for (int i = 12; i < 24; i++){ //for all checkers
                      (*check[i])--;
                    }

            break;

        case GLUT_MIDDLE_BUTTON:
            foundIn = searchChecker(x, y);
            if(foundIn > 0 )
                check[activeCheck-1] = (*check[activeCheck-1])++;
            break;
        }
}


void MouseMove(int ax, int ay){
    x = ax;
    y = ay;
    std::cout << ax << " " << ay << std::endl;
    //glutSetWindowTitle("MouseMove");
//    printf("X = %d\n", x);
//    printf("Y = %d\n", y);
}


void MousePressedMove(int ax, int ay){
    x = ax;
    y = ay;
    //glutSetWindowTitle("MousePressedMove");
}
