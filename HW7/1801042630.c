#include <stdio.h>
#include <string.h>
#include <stdlib.h>
///////////////////////////////////////////////////////////////////////////////////////////////////
int menu();
void average_of_scores(float fl_scores[]);
void through_years(int int_years[], char names[][100]);
void convert_years(char ch_years[][20], int int_years[]);
void genre_frequence(int indexG[],char genres[][20]);
void platform_frequence(int indexP[],char platforms[][20]);
void fn_scores(char ch_scores[][20], float fl_scores[]);
void fn_na_sales(char ch_na_sales[][20], float fl_na_sales[]);
void fn_eu_sales(char ch_eu_sales[][20], float fl_eu_sales[]);
void fn_global_sales(char ch_global_sales[][20], float fl_global_sales[]);
void geo_info(char names[][100], float fl_eu_sales[], float fl_na_sales[]);
void unique_genres(char allGenres[][20], char genres[][20],int indexG[]);
void unique_platforms(char allPlatforms[][20], char platforms[][20],int indexP[]);
void all_info(float info[][7],int indexG[],int indexP[],int int_years[],float fl_na_sales[],float fl_eu_sales[],float fl_global_sales[],float fl_scores[]);	
///////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	int i,j,m;												//j=line    i=char
	int flag=1,flagg,operation;
	int indexG[2001],indexP[2001];
	int int_years[2001];
	char inputGame[100];
	char line[1][200];
	char names[2001][100],ch_years[2001][20],allGenres[2001][20],genres[12][20],platforms[10][20],allPlatforms[2001][20];
	char ch_na_sales[2001][20],ch_eu_sales[2001][20],ch_global_sales[2001][20],ch_scores[2001][20];
	float fl_na_sales[2001];
	float fl_eu_sales[2001],fl_global_sales[2001],fl_scores[2001];
	float info[2001][7];
	FILE *fp;
	fp=fopen("Video_Games.txt","r");
	fgets(*line,200,fp);									//first we get a line to eliminate first line of the txt file.
	j=0;													//with this while loop, we get another line and scan it until end of line...
	while(!feof(fp)){										//and assign the values to the arrays according to commas.
		fgets(*line,200,fp);				
		//***************************************||--->	for storing all names.
		for(i=0;line[0][i]!=',';i++){
			names[j][i]=line[0][i];
		}
		names[j][i]='\0';
		//***************************************||--->	for storing all genres.
		i=i+1;
		for(m=0;line[0][i]!=',';i++){
			allGenres[j][m]=line[0][i];
			m++;
		}
		allGenres[j][m]='\0';
		//***************************************||--->	for storing all platforms.
		i=i+1;
		for(m=0;line[0][i]!=',';i++){
			allPlatforms[j][m]=line[0][i];
			m++;
		}
		allPlatforms[j][m]='\0';
		//***************************************||--->	for storing all years.
		i=i+1;
		for(m=0;line[0][i]!=',';i++){
			ch_years[j][m]=line[0][i];
			m++;
		}
		ch_years[j][m]='\0';
		//***************************************||--->	for storing NA_Sales.
		i=i+1;
		for(m=0;line[0][i]!=',';i++){
			ch_na_sales[j][m]=line[0][i];
			m++;
		}
		ch_na_sales[j][m]='\0';
		//***************************************||--->	for storing EU_Sales.
		i=i+1;
		for(m=0;line[0][i]!=',';i++){
			ch_eu_sales[j][m]=line[0][i];
			m++;
		}
		ch_eu_sales[j][m]='\0';
		//***************************************||--->	for storing global_Sales.
		i=i+1;
		for(m=0;line[0][i]!=',';i++){
			ch_global_sales[j][m]=line[0][i];
			m++;
		}
		ch_global_sales[j][m]='\0';
		//***************************************||--->	for storing user_scores.
		i=i+1;
		for(m=0;line[0][i]!='\n';i++){
			ch_scores[j][m]=line[0][i];
			m++;
		}
		ch_scores[j][m]='\0';
		j++;																	// j is the line increaser
	}
	convert_years(ch_years,int_years);						//convert_years function,converts the string type year to int value and store them. 
	fn_na_sales(ch_na_sales,fl_na_sales);					//this function convert the string type of na sales to int value,and store all of it.
	fn_eu_sales(ch_eu_sales,fl_eu_sales);					//this function convert the string type of eu sales to int value,and store all of it.							
	fn_global_sales(ch_global_sales,fl_global_sales);		//this function convert the string type of global sales to int value,and store all of it.
	fn_scores(ch_scores,fl_scores);							//this function convert the string type of scores to int value,and store all of it.
	unique_platforms(allPlatforms,platforms,indexP);		//this function finds the unique platforms and assign all platforms indexes according to them.
	unique_genres(allGenres,genres,indexG);					//this function finds the unique genres and assign all platforms indexes according to them.
	all_info(info,indexG,indexP,int_years,fl_na_sales,fl_eu_sales,fl_global_sales,fl_scores);//keeps all of the informations about all games, in 1 float array.
	while(1){
		operation= menu();
		if(operation==0){									//prints unique genres.
			for(i=0;i<12;i++){
				printf("%s\n",genres[i]);
			}
		}
			else if (operation==1){							//prints unique platforms.
				for(i=0;i<10;i++){
					printf("%s\n",platforms[i]);
				}
			}
			else if (operation==2){
				through_years(int_years,names);				//takes a year and until/since value,and shows all game before/after entered year.
			}
			else if (operation==3){							//takes a game name as an input
				while(1){
					flagg=0;
					printf("Please enter the name of the game:\n");	// if the entered game is not exist in the list,it asks a name again...
					scanf(" %s",inputGame);							//if not,it keeps the index and it continues.
					for(i=0;i<2000;i++){
						if(strcmp(inputGame,names[i])==0){		//checks if there is a game named as inputGame value.
							flagg=1; 
							break;
						}
					}
					if(flagg==1) break;
					else printf("NO GAME WITH THAT NAME,TRY AGAIN.\n");	
				}			
				int a=info[i][0];		//info[i][0] keeps the index of genres so we assign it to another variable
				int b=info[i][1];		//info[i][1] keeps the index of platforms so we assign it to another variable
				printf("Name:\t\t %s \n",names[i]);	//prints the names of entered game.
				printf("Genre:\t\t %s \n",genres[a]);//prints the genre of entered game
				printf("Platform:\t %s \n",platforms[b]);//prints the platform of entered game
				printf("Year:\t\t %.0f \n",info[i][2]);//prints the release year of entered game.
				printf("Sales in NA:\t %f \n",info[i][3]);//prints the NA sales of entered game.
				printf("Sales in EU:\t %f \n",info[i][4]);//prints the EU sales of entered game.
				if(info[i][5]==-1)	printf("Total Sales:\t Not Available \n");//prints the global sales of entered game...
				else 				printf("Total Sales:\t %f \n",info[i][5]);//if it is "not available" in the file, instead of that it is assigned before as -1. 
				printf("User Score:\t %f \n",info[i][6]);//prints the user score of entered game.
	
			}
			else if (operation==4){
				average_of_scores(fl_scores);		//prints the all scores average.
			}
			else if (operation==5){
				geo_info(names,fl_eu_sales,fl_na_sales);	//prints the geographical info of entered game
			}
			else if (operation==6){
				genre_frequence(indexG,genres);				//prints all genre Frequences.
			}
			else if (operation==7){
				platform_frequence(indexP,platforms);		//prints all platforms Frequences.
			}		
			else if(operation==8){
				printf("You are leaving...\n");
				exit(1);
			}
		else{
			printf("\n\nINVALID CHOICE. TRY AGAIN.\n");
		}	
	}
	fclose(fp);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int menu(){	
	int op;
	printf("\n\nWELCOME\n_______________________\n");
	printf("0: List of The Genres\n");
	printf("1: List of The Platforms\n");
	printf("2: List of The Game Through The Years\n");
	printf("3: All Information of a Single Game\n");
	printf("4: Avarage of The User Score\n");
	printf("5: Georgraphical Information of a Single Game\n");
	printf("6: Frequence of The Genres\n");
	printf("7: Frequence of The Platforms\n");
	printf("8: Exit\n");
	printf("\nPlease Select an operation: ");
	scanf("%d",&op);
	printf("\n\n");
	return op;		
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void average_of_scores(float fl_scores[]){
	int i;
	float average=0;
	for(i=0;i<2000;i++){
		average+=fl_scores[i];				//calculates all the scores average.
	}
	average=average/2000;
	printf("%f\n",average);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void through_years(int int_years[],char names[][100]){
	int i;
	int year,period;

	while(1){
		printf("Enter a year: ");
		scanf("%d",&year);
		printf("\nUntil (0) or Since (1) %d ? ",year);
		scanf("%d",&period);
		printf("\n");
		if((period==0 && year<1986) || (period==1 && year>2004)){
			printf("INVALID CHOICE. TRY AGAIN.\n\n");
		}
		else break;
	}												//asks for year and until/since value to print the games before/until entered year.
	if(period==0){
		for(i=0;i<2000;i++){
			if(year>int_years[i]){
				printf("%s\n",names[i]);
			}
		}
	}
	if(period==1){
		for(i=0;i<2000;i++){
			if(year<int_years[i]){
				printf("%s\n",names[i]);
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void convert_years(char ch_years[][20], int int_years[]){
	int i,j;
	char ch;
	int digit_value,number;
	int year,period;

	for(i=0;i<2000;i++){
		number=0;
		digit_value=1000;							//converts string type of years to integer values.
		for(j=0;j<4;j++){
			ch=ch_years[i][j];
			number+=(ch-48)*digit_value;
			digit_value=digit_value/10;
		}
		int_years[i]=number;	
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void genre_frequence(int indexG[],char genres[][20]){
	int i,j;
	int counters[12];				//counter arrays keep all the counter values. for example counter[0] is the counter of genre[0]
	for(i=0;i<12;i++){
		counters[i]=0;				//first 0 is aasigned to all counters.
	}
	for(i=0;i<2000;i++){				
		for(j=0;j<12;j++){
			if(indexG[i]==j){		//then we search indexes and if index of a game is equal to any number between 0 and 11 it increases the... 
				counters[j]++;		//that number of counter 
				break;
			}	
		}
	}
	for(i=0;i<12;i++){
		printf("%-30s %d\n",genres[i],counters[i]);		//then print them all.
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void platform_frequence(int indexP[],char platforms[][20]){
	int i,j;
	int counters[10];
	for(i=0;i<10;i++){
		counters[i]=0;
	}
	for(i=0;i<2000;i++){					//same explanation with genre_frequence function.
		for(j=0;j<10;j++){
			if(indexP[i]==j){
				counters[j]++;
				break;
			}	
		}
	}
	for(i=0;i<10;i++){
		printf("%-15s %d\n",platforms[i],counters[i]);
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void fn_scores(char ch_scores[][20], float fl_scores[]){
	char ch;
	int i,j,limit;
	float digit_value,number;
	for(i=0;i<2001;i++){
		limit=strlen(ch_scores[i]);
		number=0;
		digit_value=1;						//same explanation with fn_na_sales.
		for(j=0;j<limit;j++){
			ch=ch_scores[i][j];
			if(ch!='.'){
				number+=(ch-48)*digit_value;
				digit_value=digit_value/10;	
			}
		}
		fl_scores[i]=number;	
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void fn_na_sales(char ch_na_sales[][20], float fl_na_sales[]){
	char ch;
	int i,j,limit;
	float digit_value,number;
	for(i=0;i<2001;i++){					//scanc all na sales
		limit=strlen(ch_na_sales[i]);		//takes their size for second loops limit	
		number=0;
		digit_value=1;
		for(j=0;j<limit;j++){
			ch=ch_na_sales[i][j];
			if(ch!='.'){					//if ch is not . its going to make the mathematical convertions
				number+=(ch-48)*digit_value;
				digit_value=digit_value/10;	//in every step of loop digit value will be divided to 10.So we will obtain the fractions.
			}
		}
		fl_na_sales[i]=number;			//and assign all the values to float na sales array 
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void fn_eu_sales(char ch_eu_sales[][20], float fl_eu_sales[]){
	char ch;
	int i,j,limit;
	float digit_value,number;
	for(i=0;i<2001;i++){
		limit=strlen(ch_eu_sales[i]);
		number=0;
		digit_value=1;						//same explanation with fn_na_sales. 
		for(j=0;j<limit;j++){
			ch=ch_eu_sales[i][j];		
			if(ch!='.'){
				number+=(ch-48)*digit_value;
				digit_value=digit_value/10;	
			}
		}
		fl_eu_sales[i]=number;	
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void fn_global_sales(char ch_global_sales[][20], float fl_global_sales[]){
	char ch;
	int i,j,limit;
	float digit_value,number;
	for(i=0;i<2001;i++){
		limit=strlen(ch_global_sales[i]);
		number=0;
		digit_value=1;							//same explanation with fn_na_sales.
		for(j=0;j<limit;j++){
			ch=ch_global_sales[i][j];
			if(ch_global_sales[i][j]=='n'){
				number=-1;
				break;
			}
			if(ch!='.'){
				number+=(ch-48)*digit_value;
				digit_value=digit_value/10;	
			}
		}
		fl_global_sales[i]=number;	
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void geo_info(char names[][100], float fl_eu_sales[], float fl_na_sales[]){
	int flag,i;
	char inputGame[100];
	while(1){
		flag=0;
		printf("\nPlease enter the name of the game:\n");
		scanf(" %s",inputGame);										//take a game name as an input and find its sales amounts to compare...
		for(i=0;i<2000;i++){										//na sales and eu sales.
			if(strcmp(inputGame,names[i])==0){
				flag=1; 
				break;
			}
		}
		if(flag==1) break;
		else printf("NO GAME WITH THAT NAME,TRY AGAIN.\n");	
	}
	if(fl_eu_sales[i]>fl_na_sales[i])			printf("This game is more popular in Europe.\n");
	else if(fl_eu_sales[i]==fl_na_sales[i])		printf("This game has same popularity in both area.\n");
	else 										printf("This game is more popular in North America.\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
void unique_genres(char allGenres[][20], char genres[][20], int indexG[]){
	int i,j,k;
	int flag=1;
	k=0;
	for(i=0;i<2000;i++){
		for(j=0;j<12;j++){
			flag=strcmp(allGenres[i],genres[j]);	//we compare the allGenres array with empty genres array...
			if(flag==0)	break;						//if one of the element of allGenres array is in also genre array,notthing changes...
		}
		if(flag!=0){								//but if there is no same element, it copies the unique one from all genres to genres 
			strcpy(genres[k],allGenres[i]);
			k++;
		}	
	}
	
	printf("\n");
	for(i=0;i<2000;i++){							//we scan allGenres array and store their indexes as integer in indexG array to use it in...
		for(j=0;j<12;j++){							//later for float all info array. 
			if(strcmp(allGenres[i],genres[j])==0){	
				indexG[i]=j;
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void unique_platforms(char allPlatforms[][20], char platforms[][20],int indexP[]){
	int i,j,k;
	int flag=1;
	k=0;
	for(i=0;i<2000;i++){
		for(j=0;j<10;j++){
			flag=strcmp(allPlatforms[i],platforms[j]);
			if(flag==0)	break;
		}													//same explanation with unique_genres function.
		if(flag!=0){
			strcpy(platforms[k],allPlatforms[i]);
			k++;
		}	
	}
	printf("\n");
	for(i=0;i<2000;i++){
		for(j=0;j<10;j++){
			if(strcmp(allPlatforms[i],platforms[j])==0){
				indexP[i]=j;
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void all_info(float info[][7],int indexG[],int indexP[],int int_years[],float fl_na_sales[],float fl_eu_sales[],float fl_global_sales[],float fl_scores[]){
	int i;
	for(i=0;i<2000;i++){
		info[i][0]=indexG[i];
		info[i][1]=indexP[i];
		info[i][2]=int_years[i];				//keeps the all info of all games.
		info[i][3]=fl_na_sales[i];
		info[i][4]=fl_eu_sales[i];
		info[i][5]=fl_global_sales[i];
		info[i][6]=fl_scores[i];	
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
