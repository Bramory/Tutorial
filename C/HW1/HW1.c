#include <stdio.h>
#include <conio.h>
#include "dk_tool.h"

int main(){
    int x, y;
    printf("Enter matrix size, please {[x],[y]} > 0 \n");
    do{
		x = num_scan();
		y = num_scan();
		if (x > 0 && y > 0) break; 
			printf("Invalid size! {[x],[y]} > 0\n");
	}
	while(1);
	
	int matr[x][y];

    printf("Fill the matrix with %i numbers: ", x*y);
	read_matr(x, y, matr);
	
	printf("\n\nOriginal matrix:\n\n");
	print_matr(x, y, matr);
	
	int transp_matr[y][x];
	transp(x, y, transp_matr, matr);
	printf("\n\nTransp_matrix:\n\n");
	print_matr(y, x, transp_matr);

    getch();
    return 0;
}


