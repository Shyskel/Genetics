#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int convertToBase4(int input, int* storeArray, int index);
void convertToBase10(char* genString);
void convertToBase4Helper(int* convertedArray, int length);



int main (){

	char input[15];
	int cases, i = 0, loopsRequired, sequenceCount = 1;

	scanf("%d", &cases);

	while (cases > 0){

		scanf("%s", input);

		int* storeArray = malloc(sizeof(int) * 15);

		printf("Sequence #%d: ", sequenceCount);

		if (atoi(input)){
			loopsRequired = convertToBase4(atoi(input), storeArray, 0);

			convertToBase4Helper(storeArray, loopsRequired);
		}
		
		else
			convertToBase10(input);
		

		
		sequenceCount++;
		cases--;

		free(storeArray);
	}

	return 0;
}

// Recusive function that puts modular results
// into an int array.
int convertToBase4(int input, int* storeArray, int index){
	
	if (input == 0)
		return index;

	storeArray[index] = input % 4;

	convertToBase4(input / 4, storeArray, index + 1);
	
}



// Reverses the order of the int array. {
void convertToBase4Helper(int* convertedArray, int length){

	int i;
	int* tempArray = malloc(sizeof(int)*length);


	// Reverse the convertedArray using a temp array.
	for (i = 0; i < length; i++){
		tempArray[i] = convertedArray[length - 1 - i];
	}


	// Put A = 0, C = 1, G = 2, T = 3
	// into a corisponding int array.
	for (i = 0; i < length; i++){

		switch (tempArray[i]){

			case 0:
				printf("A");
				break;

			case 1:

				printf("C");
				break;
			case 2:

				printf("G");
				break;

			case 3:

				printf("T");
				break;

		}

	}

	printf("\n");

	free(tempArray);
}


void convertToBase10(char* genString){

	int length = strlen(genString);
	int i, value = 0;

	int* tempArray = malloc(sizeof(int)*length);

	for (i = 0; i < length; i++){

		switch (genString[i]){

		case 'A' :
			tempArray[i] = 0;
			break;

		case 'C' :

			tempArray[i] = 1;
			break;

		case 'G' :

			tempArray[i] = 2;
			break;

		case 'T' :

			tempArray[i] = 3;
			break;

		}

	}

	int* newTempArray = malloc(sizeof(int)*length);


	// Reverse the array using a temp array.
	for (i = 0; i < length; i++)
		newTempArray[i] = tempArray[length - 1 - i];


	free(tempArray);


	for (i = 0; i < length; i++)
		value = value + (newTempArray[i] * pow(4, i));

	free(newTempArray);
	
	printf("%d\n", value);
}