#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
///////////////////////////////////////////////////////////////////////////////////////////////
const int ROWS	=20; 
const int COLS	=20; 
#define is_all_letters 1	//if you want to see the puzzle just with the chosen words (without random chars, change is_all_letters value to 0)
///////////////////////////////////////////////////////////////////////////////////////////////
char random_char_generator();
int size_of_line(char *line);
void get_random_lines(char puzzle[][20]);
void word_compare(char puzzle[][20],int *is_finish);
void random_chars2grid(char puzzle[][COLS],int ROWS);
void print_original_grid(char puzzle[][20]);
void left2right(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor);
void right2left(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor);
void top2bottom(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor);
void bottom2top(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor);
void left_horitontal2right(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor);
void right_horitontal2left(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor);
void left_horitontal2right_from_bottom(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor);
void right_horitontal2left_from_bottom(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor);
///////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	
	int i,j;
	int is_finish=0;
	char puzzle[ROWS][COLS];
	srand(time(0));

	for(i=0;i<20;i++){
		for(j=0;j<20;j++){										//At the beginning of the program, to make the array empty we assign ' ' to every indexs.
			puzzle[i][j]=' ';
		}
	}
	printf("\n");
	get_random_lines(puzzle);									//get_random_lines function gets random lines from the given file 
	if(is_all_letters==1) random_chars2grid(puzzle,ROWS);								//random_chars2grid function assigns random chars to empty places of puzzle array
	print_original_grid(puzzle);								//print_original_grid functions renew the array in order to users inputs.
	printf("\n\n");
	while(1){	
		word_compare(puzzle,&is_finish);						//gets input from the user and compare it to the given coordinates
		printf("\n");
		print_original_grid(puzzle);
		printf("\n");
		if(is_finish==10){										//when 10 words are found,the program ends.
			printf("CONGRATS! You found all the words in puzzle.\n");
			break;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void word_compare(char puzzle[][20],int *is_finish){
	
	char ch='a';
	int i,is_found=0;
	int safeRowNumber,safeColumnNumber,column,rowNumber,limit;
	char row;
	char word[20];
	
	printf("You can see the words in the puzzle at the upmost.\nPlease enter the coordinate and the word (enter 'Exit' or 'exit' to leave the game):\n ");
	scanf(" %c",&row);
	scanf(" %d",&column);
	scanf("%s",word);
	if((row=='E'||row=='e') && (word[0]=='x') && (word[1]=='i') && (word[2]=='t')){
		printf("You left the game!\n");
		exit(1);
	}

	rowNumber=row-65;															//according to row char, this line convert the letter to number.
	limit=size_of_line(word);													//size_of_line function finds the size of entered word.
	safeRowNumber=		rowNumber;												//to save the original rowNumbers value from the incoming process we assign it to safeRowNumber
	safeColumnNumber=	column;													//to save the original column number value from the incoming process we assign it to safeColNumber
	//**************************************************************************************************
	column=safeColumnNumber;
	rowNumber=safeRowNumber;														//				-->
	for(i=0;i<limit;i++){												
		if(puzzle[rowNumber][i+column]!=word[i]){									//this statement checks from left to right that the entered word is in the puzzle or not 
			is_found=0;																//if it is in the puzzle is_found=1, if not is_found=0
			break;
		}
		else{
			is_found=1;
		}
	}
	if(is_found==1){																//if i found==1,this statement make uppercase the entered word in puzzle
		(*is_finish)++;
		column=safeColumnNumber;
		rowNumber=safeRowNumber;
		for(i=0;i<limit;i++){
			puzzle[rowNumber][i+column]=puzzle[rowNumber][i+column]-32;				//Please consider that the comments of the statements below will be the same with this part.
		}
	}
	//**************************************************************************************************
	column=safeColumnNumber;
	rowNumber=safeRowNumber;												//					<--
	for(i=0;i<limit;i++){													
		if(puzzle[rowNumber][column--]!=word[i]){							//this statement checks from right to left that the entered word is in the puzzle or not 
			is_found=0;
			break;
		}
		else{
			is_found=1;
		}
	}
	if(is_found==1){
		(*is_finish)++;
		column=safeColumnNumber;
		rowNumber=safeRowNumber;
		for(i=0;i<limit;i++){
			puzzle[rowNumber][column]=puzzle[rowNumber][column]-32;
			column=column-1;
		}
	}
	//**************************************************************************************************
	column=safeColumnNumber;
	rowNumber=safeRowNumber;												//					↓
	for(i=0;i<limit;i++){												
		if(puzzle[rowNumber++][column]!=word[i]){							//this statement checks from top to bottom that the entered word is in the puzzle or not 
			is_found=0;
			break;
		}
		else{
			is_found=1;
		}
	}
	if(is_found==1){
		(*is_finish)++;
		column=safeColumnNumber;
		rowNumber=safeRowNumber;
		for(i=0;i<limit;i++){
			puzzle[rowNumber][column]=puzzle[rowNumber][column]-32;
			rowNumber=rowNumber+1;
		}
	}
	//**************************************************************************************************
	column=safeColumnNumber;
	rowNumber=safeRowNumber;													//				↑
	for(i=0;i<limit;i++){											
		if(puzzle[rowNumber--][column]!=word[i]){								//this statement checks from bottom to top that the entered word is in the puzzle or not 
			is_found=0;
			break;
		}
		else{
			is_found=1;
		}
	}
	if(is_found==1){
		(*is_finish)++;
		column=safeColumnNumber;
		rowNumber=safeRowNumber;
		for(i=0;i<limit;i++){
			puzzle[rowNumber][column]=puzzle[rowNumber][column]-32;
			rowNumber=rowNumber-1;
		}
	}
	//**************************************************************************************************	
	column=safeColumnNumber;										
	rowNumber=safeRowNumber;										//				↘
	for(i=0;i<limit;i++){
		if(puzzle[rowNumber++][column++]!=word[i]){					//this statement checks left to right-top to bottom horitontal that the entered word is in the puzzle or not 
			is_found=0;
			break;
		}
		else{
			is_found=1;
		}
	}
	 if(is_found==1){
		(*is_finish)++;
		column=safeColumnNumber;
		rowNumber=safeRowNumber;
		for(i=0;i<limit;i++){
			puzzle[rowNumber][column]=puzzle[rowNumber][column]-32;
			rowNumber=rowNumber+1;
			column=column+1;
		}
	}
	//**************************************************************************************************
	column=safeColumnNumber;
	rowNumber=safeRowNumber;									//					↖
	for(i=0;i<limit;i++){											
		if(puzzle[rowNumber--][column--]!=word[i]){				//this statement checks from right to left-bottom horizontal to top that the entered word is in the puzzle or not 
			is_found=0;
			break;
		}
		else{
			is_found=1;
		}
	}
	if(is_found==1){
		(*is_finish)++;
		column=safeColumnNumber;
		rowNumber=safeRowNumber;
		for(i=0;i<limit;i++){
			puzzle[rowNumber][column]=puzzle[rowNumber][column]-32;
			rowNumber=rowNumber-1;
			column=column-1;
		}
	}
	//**************************************************************************************************
	column=safeColumnNumber;
	rowNumber=safeRowNumber;										//				↗
	for(i=0;i<limit;i++){											
		if(puzzle[rowNumber--][column++]!=word[i]){					//this statement checks from left to right-bottom horizontal to top that the entered word is in the puzzle or not 
			is_found=0;
			break;
		}
		else{
			is_found=1;
		}
	}
	if(is_found==1){
		(*is_finish)++;
		column=safeColumnNumber;
		rowNumber=safeRowNumber;
		for(i=0;i<limit;i++){
			puzzle[rowNumber][column]=puzzle[rowNumber][column]-32;
			column=column+1;
			rowNumber=rowNumber-1;
		}
	}

	//**************************************************************************************************
	column=safeColumnNumber;
	rowNumber=safeRowNumber;														//							↙
	for(i=0;i<limit;i++){														
		if(puzzle[rowNumber++][column--]!=word[i]){									//this statement checks from right to left-top to bottom horizontal that the entered word is in the puzzle or not 
			is_found=0;
			break;
		}
		else{
			is_found=1;
		}
	}
	if(is_found==1){
		(*is_finish)++;
		column=safeColumnNumber;
		rowNumber=safeRowNumber;
		for(i=0;i<limit;i++){
			puzzle[rowNumber][column]=puzzle[rowNumber][column]-32;
			rowNumber=rowNumber+1;
			column=column-1;
		}
	}
	//**************************************************************************************************
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void random_chars2grid(char puzzle[][COLS],int ROWS){
	
	int i,j;
	char rowChar='A';

	for(i=0;i<ROWS;i++){
		for(j=0;j<COLS;j++){
			if(puzzle[i][j]==' '){
				puzzle[i][j]=random_char_generator();				// if the current location of idnexes is empty, this function assigns random chars.
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_original_grid(char puzzle[][COLS]){
	int i,j;
	char rowChar='A';

	printf("   ");
	for(i=0;i<9;i++){
		printf("%d  ",i);		//This function prints the first-orijinal situation of the puzzle just with the words from the file (without random chars)
	}
	for(i=9;i<20;i++){
		printf("%d ",i);
	}
	printf("\n");
	for(i=0;i<21;i++){
		printf("_  ");
	}
	for(i=0;i<ROWS;i++){
		printf("\n%c| ",rowChar);
		rowChar++;
		for(j=0;j<COLS;j++){
			printf("%c  ",puzzle[i][j]);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void get_random_lines(char puzzle[][20]){
	
	int i,j,randomLine,choice,cursor=0;					
	int lengths[10];
	char buffer[100];
	char tempBuffer[10][20];

   	FILE *fp=fopen("words.txt","r");

   	for(i=0;i<10;i++){
   		randomLine=(rand()%100)+1;
   		fseek(fp,0,SEEK_SET);				//this statement gets line from the file and assign the words to 1D buffer.
   		for(j=0;j<randomLine;j++){
   			fgets(buffer,100,fp);
        }
        strcpy(tempBuffer[i], buffer);		//to send the words to 2D buffer we use strcpy function
	}
    fclose(fp);
    for(i=0;i<10;i++){
    	lengths[i]=size_of_line(tempBuffer[i])-1;		// to keep the lenghts of words tempBuffer array is sent to size_of_line function 	
    }													// and the results are stored in the lengths array
    printf("THE WORDS IN THE PUZZLE\n_______________________\n");

    for(i=0;i<10;i++){
    	printf("%s",tempBuffer[i]);						// prints the chosen words from the file
    }
    printf("_______________________\n\n");
    	i=0;
    	while(i<10){
	    	choice=rand()%8;							//taking random line to place the words randomly. According the random choice the words will be sent the functions randomly.
	    	if(choice==0)		left_horitontal2right(tempBuffer,puzzle,lengths,&cursor);
	    	else if(choice==1)	right_horitontal2left(tempBuffer,puzzle,lengths,&cursor);
	    	else if(choice==2)	left_horitontal2right_from_bottom(tempBuffer,puzzle,lengths,&cursor);		//cursor keeps the words location in the tempBuffer array, so; the same word...
	   		else if(choice==3)	right_horitontal2left_from_bottom(tempBuffer,puzzle,lengths,&cursor);		// cannot be written to the puzzle because cursors value increases every time.
	    	else if(choice==4)	left2right(tempBuffer,puzzle,lengths,&cursor);	
	    	else if(choice==5)	right2left(tempBuffer,puzzle,lengths,&cursor);
	    	else if(choice==6)	top2bottom(tempBuffer,puzzle,lengths,&cursor);
	    	else if(choice==7)	bottom2top(tempBuffer,puzzle,lengths,&cursor);
	    	i++;
	    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
char random_char_generator(){
	char ch;
	ch='a'+(rand()%26);				//this function creates random chars.
    return ch;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int size_of_line(char *string){
	char *arrow=string; // to keep the beginning of the line
	
	int counter = 0;
	while(*arrow!='\n' && *arrow!='\0'){	//it goes and counts until it sees a new line or NULL
		arrow++;
		counter++; 
	}
	return counter;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void left2right(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor){
	
	int bufferCol,puzzleRow,puzzleCol;
	int is_empty,a,c,x,y;
	
	puzzleRow=(rand()%20);
	puzzleCol=(rand()%20);
	
	x=puzzleCol;
	y=puzzleRow;
	a=x;
	while(1){
		for(c=0;c<lengths[*cursor];c++){
			if(puzzle[y][x]!=' '){				//it checks from 0 until the length of the chosen word that if the chosen location empty or not
				is_empty=0;
				break;
			}
			else{
				is_empty=1;
			}
			x++;								//if it is empty it checks all the x values.
		}
		if(x>19){
			is_empty=0;							//if the last x value is larger than 19 it means that there is overflowing. So it makes is_empty=0
		}
		if(is_empty==1){
			break;
		}	
		if(is_empty==0){						//when is_empty==0 it takes new random values until is_empty==1
			y=(rand()%20);
			x=(rand()%20);
			a=x;								//to keep the new orijinal value of x, we assign it to a variable 
		}														
	}
    for(bufferCol=0;bufferCol<lengths[*cursor];bufferCol++){
    	puzzle[y][a]=tempBuffer[*cursor][bufferCol];					//if there is no collision or overflowing, the words are going to be assigned to the puzzle array.
    	a++;
   	}
   	(*cursor)++;								// increase the cursor value, so next words in the array will be sent to the next incoming function.
   												//PLEASE CONSIDER THAT, AFTER THIS FUNCTION, THE FOLLOWING FUNCTIONS' EXPLANATIONS WILL BE SAME.
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void right2left(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor){
	
	int bufferCol,puzzleRow,puzzleCol;
	int is_empty,a,c,x,y;
	
	puzzleRow=(rand()%20);
	puzzleCol=(rand()%20);
	x=puzzleCol;
	y=puzzleRow;
	a=x;
	while(1){
		for(c=0;c<lengths[*cursor];c++){
			if(puzzle[y][x]!=' '){
				is_empty=0;
				break;
			}
			else{
				is_empty=1;
			}
			x--;									// The logic behind this code segment, is explained in right2left function...
		}											//	The only differences is the directions that will be checked.
		if(x<0){
			is_empty=0;
		}
		if(is_empty==1){
			break;
		}	
		if(is_empty==0){
			y=(rand()%20);
			x=(rand()%20);
			a=x;						
		}	
	}
    for(bufferCol=0;bufferCol<lengths[*cursor];bufferCol++){
    	puzzle[y][a]=tempBuffer[*cursor][bufferCol];
    	a--;
   	}
   	(*cursor)++;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void top2bottom(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor){
	int bufferCol,puzzleRow,puzzleCol;
	int is_empty,a,c,x,y;

	puzzleRow=(rand()%20);
	puzzleCol=(rand()%20);
	
	x=puzzleCol;
	y=puzzleRow;
	a=y;
	while(1){
		for(c=0;c<lengths[*cursor];c++){
			if(puzzle[y][x]!=' '){
				is_empty=0;
				break;
			}
			else{
				is_empty=1;
			}
			y++;
		}											// The logic behind this code segment, is explained in right2left function...
		if(y>20){									//	The only differences is the directions that will be checked.
			is_empty=0;
		}
		if(is_empty==1){
			break;
		}	
		if(is_empty==0){
			y=(rand()%20);
			a=y;
			x=(rand()%20);	
		}	
	}
    for(bufferCol=0;bufferCol<lengths[*cursor];bufferCol++){
    	puzzle[a][x]=tempBuffer[*cursor][bufferCol];
    	a++;
   	}
   	(*cursor)++;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void bottom2top(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor){
	int bufferCol,puzzleRow,puzzleCol;
	int is_empty,a,c,x,y;
	
	puzzleCol=(rand()%20);
	puzzleRow=(rand()%20);
	
	x=puzzleCol;
	y=puzzleRow;
	a=y;
	while(1){
		for(c=0;c<lengths[*cursor];c++){
			if(puzzle[y][x]!=' '){
				is_empty=0;
				break;
			}
			else{
				is_empty=1;
			}
			y--;											// The logic behind this code segment, is explained in right2left function...
		}													//	The only differences is the directions that will be checked.
		if(y<0){
			is_empty=0;
		}
		if(is_empty==1){
			break;
		}	
		if(is_empty==0){
			y=(rand()%20);
			a=y;
			x=(rand()%20);		
		}	
	}
    for(bufferCol=0;bufferCol<lengths[*cursor];bufferCol++){
    	puzzle[a][x]=tempBuffer[*cursor][bufferCol];
    	a--;
   	}
   	(*cursor)++;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void left_horitontal2right(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor){
	int bufferCol,puzzleRow,puzzleCol;
	int is_empty,a,b,c,x,y;	
	

	puzzleRow=(rand()%20);
	puzzleCol=(rand()%20);
	
	x=puzzleCol;
	y=puzzleRow;
	a=x;
	b=y;
	while(1){
		for(c=0;c<lengths[*cursor];c++){
			if(puzzle[y][x]!=' '){
				is_empty=0;
				break;
			}
			else{
				is_empty=1;
			}
			x++;
			y++;										// The logic behind this code segment, is explained in right2left function...
		}												//	The only differences is the directions that will be checked.
		if(x>19 || y>19){
			is_empty=0;
		}
		if(is_empty==1){
			break;
		}	

	
	if(is_empty==0){
		y=(rand()%20);
		b=y;
		x=(rand()%20);
		a=x;
	
		}	
	}
    for(bufferCol=0;bufferCol<lengths[*cursor];bufferCol++){
    	puzzle[b][a]=tempBuffer[*cursor][bufferCol];
    	b++;
    	a++;
  	 } 
  	 (*cursor)++;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void right_horitontal2left(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor){
	int bufferCol,puzzleRow,puzzleCol;
	int is_empty,a,b,c,x,y;
	
	puzzleRow=(rand()%20);
	puzzleCol=(rand()%20);
	
	x=puzzleCol;
	y=puzzleRow;
	a=x;
	b=y;
	while(1){
		for(c=0;c<lengths[*cursor];c++){
			if(puzzle[y][x]!=' '){
				is_empty=0;
				break;
			}
			else{
				is_empty=1;
			}
			x--;
			y++;
		}												// The logic behind this code segment, is explained in right2left function...
		if(x<0 || y>19){								//	The only differences is the directions that will be checked.
			is_empty=0;
		}
		if(is_empty==1){
			break;
		}	

	
		if(is_empty==0){	
			y=(rand()%20);	
			b=y;								
			x=(rand()%20);
			a=x;						
		}	
	}
    for(bufferCol=0;bufferCol<lengths[*cursor];bufferCol++){
    	puzzle[b][a]=tempBuffer[*cursor][bufferCol];
    	b++;
    	a--;
  	} 
  	(*cursor)++;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void left_horitontal2right_from_bottom(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor){
	int bufferCol,puzzleRow,puzzleCol;
	int is_empty,a,b,c,x,y;	
	
	puzzleRow=(rand()%20);
	puzzleCol=(rand()%20);	

	x=puzzleCol;
	y=puzzleRow;
	a=x;
	b=y;
	while(1){
		for(c=0;c<lengths[*cursor];c++){
			if(puzzle[y][x]!=' '){
				is_empty=0;
				break;
			}
			else{
				is_empty=1;
			}
			x++;										// The logic behind this code segment, is explained in right2left function...i
			y--;										//	The only differences is the directions that will be checked.
		}
		if(x>19 || y<0){
			is_empty=0;
		}
		if(is_empty==1){
			break;
		}	

	
		if(is_empty==0){	
			y=(rand()%20);
			b=y;		
			x=(rand()%20);
			a=x;			
		}	
	}
    for(bufferCol=0;bufferCol<lengths[*cursor];bufferCol++){
    	puzzle[b][a]=tempBuffer[*cursor][bufferCol];
    	b--;
    	a++;
  	}
  	(*cursor)++;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void right_horitontal2left_from_bottom(char tempBuffer[][20], char puzzle[][20], int lengths[], int *cursor){
	int bufferCol,puzzleRow,puzzleCol;
	int is_empty,a,b,c,x,y;	
	
	puzzleRow=(rand()%20);
	puzzleCol=(rand()%20);
	
	x=puzzleCol;
	y=puzzleRow;
	a=x;
	b=y;
	while(1){
		for(c=0;c<lengths[*cursor];c++){
			if(puzzle[y][x]!=' '){
				is_empty=0;
				break;
			}
			else{
				is_empty=1;
			}
			x--;
			y--;									// The logic behind this code segment, is explained in right2left function...
		}											//	The only differences is the directions that will be checked.
		if(x<0 || y<0){
			is_empty=0;
		}												
		if(is_empty==1){
			break;
		}	

	
		if(is_empty==0){	
			y=(rand()%20);
			b=y;
			x=(rand()%20);
			a=x;			
		}	
	}
    for(bufferCol=0;bufferCol<lengths[*cursor];bufferCol++){
    	puzzle[b][a]=tempBuffer[*cursor][bufferCol];
    	b--;
    	a--;
  	 }
  	(*cursor)++;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////