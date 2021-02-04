#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

void menu();
void decrypt_and_print(char *file_path);
char decrypt_numbers(int number);
void track_machine();
void refresh_position (int *X, int *Y, double *D, double *R);
void deep_decrypt_and_print (char *file_path);
int line_counter(char *file_path);
void encrypt_messages(char *file_path); 
int decrypt_signs(char ch);

int main(){

	srand(time(NULL));
	
	menu();
return 0;
}
/////////////////////////////////////////////////////////////////////////////
void menu(){

	int choice;

	while(1){														//Menu will work until the choice input is 5.
		printf("1) Decrypt and print encrypted_p1.img\n");
		printf("2) Decrypt and print encrypted_p2.img\n");
		printf("3) Switch on the tracking machine\n");
		printf("4) Encrypt the message\n");
		printf("5) Switch off\n");
		printf("Please make your choice:\n");
		scanf("%d",&choice);
																	//The related functions are called according to input.
		if(choice==1){
			decrypt_and_print("encrypted_p1.img");
		}
			else if(choice==2){
				deep_decrypt_and_print("encrypted_p2.img");
			}
			else if(choice==3){
				track_machine();
			}
			else if(choice==4){
				encrypt_messages("decrypted_p4.img");
			}
			else if(choice==5){
				printf("EXIT\n");
				break;
			}
		else{
			printf("INVALIDE CHOICE.TRY AGAIN!\n");
			
		}
	}
}
/////////////////////////////////////////////////////////////////////////////
void decrypt_and_print(char *file_path){
	
	char ch;
	int number;
	char symbol;
	FILE *fp;
	fp=fopen(file_path,"r");
	ch=getc(fp);
	while(!feof(fp)){									//Reading the file until the EOF.
		number=ch-48;									//We are taking the numbers as chars because if we would take as an integer we cant read the numbers 1-by-1.
		symbol=decrypt_numbers(number);					//After taking them as a char, we convert them to integers by using ASCII table (ch-48)=ascii values.
		printf("%c",symbol);							//and we send the numbers to decrypt_numbers function to assign the numbers a sign.
		ch=getc(fp);									//when ch==EOF,it leaves the loop.
	}
	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////
char decrypt_numbers(int number){
	
	switch(number){
										//Thise funciton represent the numbers as an integer. according to cases,
										//funtion returns the related part of the function.
		case 0:
			return ' ';
		case 1:
			return '-';
		case 2:
			return '_';
		case 3:
			return '|';
		case 4:
			return '/';
		case 5:
			return '\\';
		case 6:
			return 'O';
		case -38:
			return '\n';
	}
}
/////////////////////////////////////////////////////////////////////////////
void track_machine(){
	int x,y;
	int counter=0;
	int o_x=6,o_y=6;
	int e_x,e_y;
	double R,D;
	char command='R';													//at first command is 'E' to make it enter the loop. Then it will change by taking it from the player.

	while(command!='E'){												//it will be in the loop until command is R
		if(command=='R'){
			if(counter==0){												//when the opening of the game enemy will be in the 1x1 and the distance to us will be 7,0710.
				e_x=1;
				e_y=1;
				D=7.0710;
				counter++;												//after the first move counter will be more than 1 and this statement will be skipped.
			}
			else{
				refresh_position(&e_x,&e_y,&D,&R);						//if command is 'E' and if its not the first move the addres of enemis positions(x and y) will be sent
				if(e_x==o_x && e_y==o_y){								//to refresh_position function to change the position randomly.
					printf("YOU ARE BUSTED BY THE ENEMIES!!\n\n");		//if enemy and us would be in the same position game over.
					break;
				}
				else;
			}
			for(x=1;x<12;x++){											//this loop prints the battle field.
				for(y=1;y<12;y++){
					if(o_x==y && o_y==x){								//if the x and y value of us is equal to each other 'O' will be printed.
						printf("O\t");
					}
					else if(e_x==y && e_y==x){							//if the x and y value of enemy is equal to each other 'E' will be printed.
						printf("E\t");
					}
					else{
						printf(".\t");									//if not dots(.) will be printed as the field.
					}
				}
				printf("\n");
			}
			printf("Enemies X position %d, Y position: %d, Displacement: %.2f, Distance to our camp %.2f\n",e_y,e_x,R,D);
			printf("Command waiting...:\n");
			scanf(" %c",&command);
		}
		else{
			printf("INVALID CHOICE!!!\n\n");	// if the command is different then 'E' and if its not R its invalid choice you should try again.
			printf("Command waiting...:\n");
			scanf(" %c",&command);
		}
	}
}
/////////////////////////////////////////////////////////////////////////////
void refresh_position (int *X, int *Y, double *D, double *R){

	int temp_x=*X;	// we assign the original values to temp values to 
	int temp_y=*Y;	// calculate the difference between former position and new position of enemy.
					
	do{
		*X=rand()%12;	//new x and y values will be less than 12 means that 1-11.
		*Y=rand()%12;	
	}while(*X==0 || *Y==0);	// if x or y is equal to 0 it will try again because our field starts from 1.

	*R=sqrt(pow((*X-temp_x),2)+pow((*Y-temp_y),2));	//its the mathematical expression of displacement.
	*D=sqrt(pow((*X-6),2)+pow((*Y-6),2));			//its the mathematical expression of the distance to our camp
}
/////////////////////////////////////////////////////////////////////////////
void deep_decrypt_and_print (char *file_path){
	
	char ch;
	int number,line_number;
	int sum=0,mod;
	int i;
	int counter=-1;
	char symbol;
												//In this function the file is decrypted LINE-BY-LINE.
	FILE *fp;
	fp=fopen(file_path,"r");
	
	line_number=line_counter(file_path);		//line_counter function finds the number of line in a file.
	int j;
	for(j=0;j<line_number;j++){				//this for loop reads the file until the last line.
		ch=getc(fp);
		while(ch!='\n'){						//this while loop reads the chars until the end of line.
			for(i=0;i<3;i++){					//adding 3 numbers.
				number=ch-48;					//convert the chars to int.
				sum+=number;
				if(i!=2){
					ch=getc(fp);
				}
				if(ch=='\n'){
					ch='0';
				}
			}
			mod=sum%7;						//its the formula given us.
			symbol=decrypt_numbers(mod);	//sending the mod number to decrypt_numbers function to assign them a sign.
			sum=0;
			printf("%c",symbol);
			counter++;
			fseek(fp,counter,SEEK_SET);		//and managing the file pointers location according to counters place. ıncreasing it 1by1.
			ch=getc(fp);
		}
	printf("\n");
	}
	fclose(fp);
}
/////////////////////////////////////////////////////////////////////////////
int line_counter(char *file_path){

	char ch;
	int counter=0;
										//this function calculates number of line in any file.
	FILE *fp;
	fp=fopen(file_path,"r");
	
	ch=getc(fp);
	while(!feof(fp)){					//it will read until the EOF
		if(ch=='\n'){					//counter will be increased if ch=end of line
			counter++;
		}
		ch=getc(fp);
	}
	fclose(fp);							//in the end counter will be equal to line number and it will return the line number.
return counter;						
}
/////////////////////////////////////////////////////////////////////////////
void encrypt_messages(char *file_path){

	char ch;
	int number1,number2,number3;
	int counter=1;
	int mod;
	int zero=0;
	
	FILE *fp;
	fp=fopen(file_path,"r");

	FILE *fp2;
	fp2=fopen("encrypted_p4.img","w");


	fscanf(fp,"%c",&ch);
	while(!feof(fp)){
		while(ch!='\n'){
			number1=decrypt_signs(ch);

			counter++;
			if(counter==1){
				mod=number1%7;
			}
			else if(counter==2){
				number2=number1;
				fscanf(fp,"%c",&ch);						//we take mod of the numbers according to counter.if its 1 just number1
															//if its 1 (number1+number2)%7 etc.
				number1=decrypt_signs(ch);					//we decrypt the signs to numbers 
				mod=(number1+number2)%7;					//we take mode 7 of the numbers.
			}
			else{
				number3=number2;
				number2=number1;
				fscanf(fp,"%c",&ch);
				number1=decrypt_signs(ch);					//by sending decrypt_signs function we convert the signs to integers.
				mod=(number1+number2+number3)%7;
			}
			fprintf(fp2,"%d",mod);
		}		
		fprintf(fp2,"\n");
		number1=0;							//each time we assign them 0 to get new numbers.
		number2=0;
		number3=0;
		counter=1;
		fscanf(fp,"%c",&ch);
	}
	fclose(fp);
	fclose(fp2);
} 
/////////////////////////////////////////////////////////////////////////////
int decrypt_signs(char ch){	
	switch(ch){							
		case ' ':
			return 0;
		case '-':
			return 1;
		case '_':
			return 2;
		case '|':
			return 3;
		case '/':
			return 4;
		case '\\':
			return 5;
		case 'O':
			return 6;
	}
}
