/*
Moisey Moshe bakshiev
group number : #61108
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*functions defenitions and declerations*/
void FreeArr(void** Arr, int skelsize)// releasing memory of arr
{
	int i;
	for (i = 0; i < skelsize; i++)
		free(Arr[i]);
	free(Arr);
	printf("MEMORY HAVE RELEASED...\n\n");
}
///////////////////////////////////// /*Ex1 Functions*/ //////////////////////////////////////////////
void CoppyWords(char* str, char letter, int SkelSize, char** NewArrSkel)// copying the words from the sentence to each arrey in it place and printing them
{
	int i = 0, j = 0, k = 0, z = 0;
	for (i = 0; i < strlen(str); i++)
	{
		if (i == 0 && toupper(str[i]) == toupper(letter))//working the same as the Arrs_Size working just instead of counting its copying
		{
			k = 0;
			j = i;
			while ((str[j] != ' ') && (str[j] != '\0'))
			{
				(NewArrSkel[z][k]) = (str[j]);
				if ((str[j + 1] == ' ') || (str[j + 1] == '\0'))
				{
					NewArrSkel[z][k + 1] = '\0';
					z++;
				}
				k++;
				j++;
			}
		}
		if (str[i - 1] == ' ' && toupper(str[i]) == toupper(letter))
		{
			k = 0;
			j = i;
			while ((str[j] != ' ') && (str[j] != '\0'))
			{
				(NewArrSkel[z][k]) = (str[j]);
				if ((str[j + 1] == ' ') || (str[j + 1] == '\0'))
				{
					NewArrSkel[z][k + 1] = '\0';
					z++;
				}
				k++;
				j++;
			}
		}
	}
}

void Arrs_Size(char* str, char letter, int SkelSize, char** NewArrSkel)// defining the size of each arrey
{
	int i = 0, j = 0, k = 0;
	int *counter;
	counter = (int*)calloc(SkelSize, sizeof(int*));
	for (i = 0; i < strlen(str); i++)
	{
		if (i == 0 && toupper(str[i]) == toupper(letter))//incase the first word started with the letter
		{
			j = i;
			while ((str[j] != ' ') && (str[j] != '\0')) //stop condition is space or end of raw
			{
				counter[k]++;
				if ((str[j + 1] == ' ') || (str[j + 1] == '\0'))
				{
					counter[k]++;
					k++;
				}
				j++;
			}
		}
		if (str[i - 1] == ' ' && toupper(str[i]) == toupper(letter))// identifie the words started with the chosen letter
		{
			j = i;
			while ((str[j] != ' ') && (str[j] != '\0'))//stop condition is space or end of raw
			{
				counter[k]++;
				if ((str[j + 1] == ' ') || (str[j + 1] == '\0'))
				{
					counter[k]++;
					k++;
				}
				j++;
			}
		}
	}
	for (i = 0; i < SkelSize; i++)// defining each arrey in the size of the word will coppied in the next function
	{
		printf("The %d Word is in size of :%d\n", i + 1, counter[i] - 1);
		NewArrSkel[i] = (char*)malloc((counter[i]), sizeof(char));
	}
	printf("\n");
}

int SkeletonSize(char* str, char letter)// checking if there is words that starting with the letter the user entered
{
	int i;
	int counter = 0;
	for (i = 0; i < (strlen(str)); i++)
	{
		if (i == 0 && toupper(str[i]) == toupper(letter))
			counter++;
		if (toupper(str[i]) == toupper(letter) && str[i - 1] == ' ')
			counter++;
	}
	if (counter>0)
	{
		return counter;
	}
	else if (counter <= 0)// in case there is no words
	{
		printf("No words found\n\n");
		return counter = 0;
	}
}
char **DynStrArr(char *str, char letter, int *skelsize)
{
	int j = 0, i = 0, counter = 0;
	char** ArrofStr = { NULL };
	*skelsize = (SkeletonSize(str, letter));
	if (*skelsize>0)// if skelsize>0 function have found words that fit the question
	{
		ArrofStr = (char**)calloc(*skelsize, sizeof(void*));//creating the skeleton
		Arrs_Size(str, letter, *skelsize, ArrofStr);// defining the size of each arrey in the skeleton
		CoppyWords(str, letter, *skelsize, ArrofStr);// copying the words from the sentence to each arrey in it place
	}
	return ArrofStr;
}
//////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////*Ex2 Functions*///////////////////////////////////
int SkelSize(char *string)
{
	int i = 0;
	int counter = 0;
	while (string[i] != '\0')
	{
		if (!isdigit(string[i]) && string[i] != ' ')
			counter++;
		i++;
	}
	printf("The size of the new String is : %d\n", counter);
	return counter;
}
int *CrtNOnum(char *string, int *skelsize)
{
	char *NewStr;
	int i = 0, k = 0;
	NewStr = (char*)calloc(skelsize + 1, sizeof(char));
	while (string[i] != '\0')
	{
		if (!isdigit(string[i]) && string[i] != ' ')
		{
			NewStr[k] = string[i];
			k++;
		}
		if (string[i + 1] == '\0')
			NewStr[k] = '\0';
		i++;
	}
	return NewStr;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////* Ex3 Functions *///////////////////////////////////////
char commonestLetter(char* filename)
{
	char chr = NULL;
	int *AlphaCounter;
	int i;
	int Max = 0;
	int MaxIndex;
	FILE *fileptr;
	char string[80];
	int choise = 1;
	AlphaCounter = (int*)calloc(26, sizeof(int));
	/*    //////     */
	printf("Creating File...\n");
	fileptr = fopen(filename, "a+");//openin or creating the file for writing
	printf("File Created! \n");
	if (fileptr != NULL)
		while (choise != 0)
		{
			printf("Write content: ");
			rewind(stdin);//clearing keyboard buffer
			gets(string);
			fputs(string, fileptr);
			printf("\n     [KEEP WRITING PRESS] 'Any number'\n     [END FILE PRESS] '0'    :");
			scanf("%d", &choise);
		}
	fclose(fileptr);//closing file for writing to open it later for reading
	free(fileptr);
	fileptr = fopen(filename, "r+");
	while (!feof(fileptr))
	{
		chr = fgetc(fileptr);
		if (isalpha(chr))
			AlphaCounter[toupper(chr) - 'A']++;
		else
			AlphaCounter[toupper(chr) - 'a']++;
	}
	for (i = 26; i >= 0; i--)
	{
		if (AlphaCounter[i] > Max)
		{
			Max = AlphaCounter[i];
			MaxIndex = i;
		}
	}
	fclose(fileptr);
	free(fileptr);
	fileptr = fopen(filename, "r");
	chr = fgetc(fileptr);
	while (chr != EOF)
	{
		printf("%c", chr);
		chr = fgetc(fileptr);
	}
	printf("\n");
	i = remove(filename);//removing file
	if (i == 0)
		printf("File deleted successfully\n");
	else printf("Didn't successed to delete the File\n");
	fclose(fileptr);//closing the conection between the file and the pointer
	return 'A' + MaxIndex;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////* Ex4 Functions *///////////////////////////////////////
void codedSTR(char string[])
{
	int i = 0;
	int k = 1;
	printf("PreDecoded string: \n");
	printf("%s\n", string);
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
			k = 1;
		else if (string[i] != ' ')
		{
			string[i] -= k;
			k++;
		}
		i++;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////* Ex5 Functions *///////////////////////////////////////
void calcDeclartion(char filename[], char str[])
{
	int sizeOfType = 0, isPointer = 0, i = 0, arrSize = 1, endDec = 0, j;
	char *configStr, chr, *temp = NULL;
	FILE *fileptr;

	configStr = strtok(str, ",");
	//checking the start of the declaration to get what type we are using
	switch (str[0])
	{
	case 'i':
		sizeOfType = 4;
		break;
	case 'c':
		sizeOfType = 1;
		break;
	case 's':
		sizeOfType = 2;
		break;
	case 'f':
		sizeOfType = 4;
		break;
	case 'd':
		sizeOfType = 8;
		break;
	}
	if (sizeOfType == 0)//if it didnt match the only choises left is long or long long
	{
		if (strstr(str, "long long") != NULL)
			sizeOfType = 8;
		else if (strstr(str, "long") != NULL)
			sizeOfType = 4;
	}




	i = strlen(configStr) - 1;//end of the first pack of string
	while (configStr[i] != ' ')//get to the whole first var
		i--;
	configStr = configStr + i + 1;//point 1 char after the space.
	fileptr = fopen(filename, "a+");
	while (configStr != NULL)
	{
		i = strlen(configStr) - 1;
		if (configStr[i] == ';')
			endDec = 1;// the last var
					   //configStr-=1;//getting rid of the '';'
		if (strstr(configStr, "*") != NULL)
		{
			configStr += 1;
			isPointer = 1;
		}
		else if (configStr[i] == ']')
		{
			arrSize = getDigitFromStr(configStr);
			i = strlen(configStr) - 2;//start from the right digit of the array		
		}
		if (endDec)
		{
			for (j = 0; j < i - 1; j++)
				fputc(configStr[j], fileptr);
		}
		else
			for (j = 0; j <= i && configStr[j] != '['; j++)
				fputc(configStr[j], fileptr);
		fputs(" requires ", fileptr);
		if (isPointer)
		{
			fputs("8", fileptr);
		}
		else
		{
			fprintf(fileptr, "%d", (sizeOfType*arrSize));
		}
		fputs(" Bytes\n", fileptr);
		arrSize = 1;
		isPointer = 0;
		configStr = strtok(NULL, ",");
	}

	fclose(fileptr);
	fileptr = fopen(filename, "r");
	chr = fgetc(fileptr);
	while (chr != EOF)
	{
		printf("%c", chr);
		chr = fgetc(fileptr);
	}
	fclose(fileptr);

}

int getDigitFromStr(char str[])
{
	int i = 0, sum = 0;
	while (str[i] < '0' || str[i]>'9')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = sum * 10 + (str[i] - '0');
		i++;
	}
	return sum;
}
/////////////////////////////////////////////////////////////////////////////////////////////////

void Ex1()//main block of question 1
{
	char str[100];// static string as allowed in the classwork guide
	char letter;
	char** ArrPtr;
	int skelsize = 0, i, j = 0;
	puts("Please enter a Sentence: ");
	gets(str);
	puts("Please enter a Letter: ");
	scanf("%c", &letter);
	printf("\n\n\n\n\n\n\n");
	printf("The Sentence is : ''%s''\n", str);
	printf("The chosen letter is : %c \n\n", letter);

	ArrPtr = DynStrArr(str, letter, &skelsize);
	printf("There is %d Words (The size of the Array)\n", skelsize);
	printf("\nThe words are:\n");
	for (i = 0; i < skelsize; i++)// printing the Arrey
	{
		printf("[ %s ]", ArrPtr[i]);
		printf("\n");
	}
	printf("\n");
	FreeArr(ArrPtr, skelsize);// releasing memory
}

void Ex2()//main block of question 2
{
	char String[100];
	char* NoNumStr;
	int skelsize;
	printf("Please enter a string : ");
	gets(String);
	skelsize = SkelSize(String);
	NoNumStr = CrtNOnum(String, skelsize);
	puts("The new String is :\n");
	puts(NoNumStr);
	printf("\n\n");
	free(NoNumStr);
}

void Ex3() // main block of question 3
{
	char MostLetter;
	char filename[100];// = "input.txt";
	puts("Please name the file that will be created and add ' .txt' in the end of it:\n");
	gets(filename);
	MostLetter = commonestLetter(filename);
	printf("%c\n", MostLetter);
}

void Ex4() // main block question 4
{
	char string[] = "Btwlzx Dqqes Eq|pj2 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt";
	char str[100];
	int i, choise = 0;
	printf("Enter 0 for the examples string,\nBtwlzx Dqqes Eq|pj2 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt\nor any other number to insert string\n");
	scanf("%d", &choise);
	if (choise != 0)
	{
		printf("Enter the new string :\n");
		rewind(stdin);//clearing keyboard buffer 
		gets(str);
		codedSTR(str);
	}
	else
	{
		codedSTR(string);
	}
	printf("THE SYSTEM DECODING THE STRING.....\n");
	for (i = 0; i < 10; i++)
		printf(".\n");
	printf("\n");
	printf("Decoded string: \n");
	if (choise != 0)
		puts(str);
	else
		puts(string);
	printf("\n");
}

void Ex5() // main block question 5
{
	char dec[100];
	char filename[100];// = "input.txt";
	puts("Please name the file that will be created and add ' .txt' in the end of it:\n");
	gets(filename);
	puts("\n\nPlease enter the declration for the text file, \n\nI REMIND YOU TO INPUT ONLY BUT ONLY VALID INPUT, \nthere is no enough checks for un valid declaration \n");
	gets(dec);
	calcDeclartion(filename, dec);
}

// main block //

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 5; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do
			{
				select = 0;
				printf("please select 0-5 : ");
				scanf("%d", &select);
				printf("\n");
				rewind(stdin);//clearing keyboard buffer 
			} while ((select<0) || (select>5));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}
