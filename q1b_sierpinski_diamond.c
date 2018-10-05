#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void printSpace(int num){ // a helper method to print the space
	int count = 0;
	while (count <= num) {
		printf("%c", ' ');
		count++;
	}
}


void drawRow(int row, int height, int level){
	if (level==1) {
		for (int i=0; i<height; i++) {
			int diff = abs(row - height/2);//how many lines are this line from the middle
			if (i >= diff && i <= height-1-diff){
				printf("%c", '*');
			} else {
				printf("%c", ' ');
			} 
		}
    } else { //level is not 1, so we should divide it
    	//drawing the top half
    	if (row<(height+1)/4) { 
			printSpace(height/4);
			drawRow(row, height/2, level-1);
			printSpace(height/4);
		
		} else if (row>=height-(height+1)/4) { // the top half counting from the bottom
			printSpace(height/4);
			drawRow(height-row-1, height/2, level-1);
			printSpace(height/4);

		} else { // draw the two "bottom half"
			drawRow(abs(row-(height+1)/4), height/2, level-1);
			printf("%c", ' ');
			drawRow(abs(row-(height+1)/4), height/2, level-1);
		}
	}
}

int main(int argc, char const *argv[])
{
	if (argc != 3){
		printf("%s\n", "ERROR: Wrong number of arguments. Two required.");
		return 0;
	}

	int height = atoi(argv[1]);
	int level = atoi(argv[2]);

	if (height<1 || height%2 == 0){
		printf("%s\n", "ERROR: Bad argument. Height must be positive odd integer.");
		return 0;
	}

	if (height<(int)(pow(2, level)-1)){
		printf("%s\n", "ERROR: Height does not allow evenly dividing requested number of levels.");
		return 0;
	} 

	for (int row=0; row<height; row++) {
		drawRow(row, height, level);
		printf("%s", "\n");
	}	
	return 0;
}