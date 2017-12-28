#ifndef RULES_H_INCLUDED
#define RULES_H_INCLUDED

#include <GL/glut.h>

#include "checker.h"
#include "const.h"
#include "draw.h"


int teamCount(int team);
void Winner (int team);
void initCheck(void);
int checkMandatoryTaking(int);


#endif // RULES_H_INCLUDED
