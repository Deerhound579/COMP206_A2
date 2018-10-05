#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	if (argc != 2){
		printf("%s\n", "ERROR: Wrong number of arguments. One required.");
		return 0;
	}

	int height = atoi(argv[1]);

	if (height<1 || height%2 == 0){
	printf("%s\n", "ERROR: Bad argument. Height must be positive odd integer.");
	return 0;
	} 

	int midline = height/2;
	//a for loop that goes over each line
	for (int line=0; line<height; line++){
		//another for loop that goes through each position in one line
		for (int pos=0; pos<height; pos++){
			int diff = abs(midline-line);//find how many lines are between current line and the middle line
			if (pos >= diff && pos <= height-1-diff){
				printf("%c", '*');
			} else {
				printf("%c", ' ');
			}
		}
		printf("%s", "\n"); // print a new line 
	} 
}