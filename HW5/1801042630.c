#include <stdio.h>
//////////////////////////////////////////////////////////////////////////
void menu();
double f_func(int x);
int is_readed(char n);
double g_func(double f(int x),int a);								//prototypes
void append_file(char *file_path, char c);
void read_file_write_terminal(char *file_path);
void read_magic_numbers(char buffer_magic[10], char buffer_news[500]);
void read_news(char buffer[500], char file_path[11], int is_Only_Title); 
//////////////////////////////////////////////////////////////////////////
int main(){

	menu();

return 0;
}
//////////////////////////////////////////////////////////////////////////
void menu(){

	int choice2;
	char choice,choice3;
	int loop=0,is_Only_Title;
	char buffer[500],file_path[11];
	int is_yes;
	char c;
	char buffer_magic[10];
	char buffer_news[500];
	
	while(loop==0){
		is_Only_Title=1;																//below functions will read just titles because of is_Only_Title==1
		printf("Title of 1. news:  ");
		read_news(buffer,"news/1.txt",is_Only_Title);									//initial menu
		printf("Title of 2. news:  ");
		read_news(buffer,"news/2.txt",is_Only_Title);
		printf("Title of 3. news:  ");
		read_news(buffer,"news/3.txt",is_Only_Title);
		printf("Title of 4. news:  ");
		read_news(buffer,"news/4.txt",is_Only_Title);
		printf("What do you want to do?\n");
		printf("a. Read a news\n");
		printf("b. List the readed news.\n");
		printf("c. Get decrypted information from the news.\n");
		scanf(" %c",&choice);
		switch(choice){
			case 'a':	
						is_Only_Title=0;												//when the user choose reading news is_Only_Title will be equal to 0.So all the news will be readed
						printf("Which news text you want to read?\n");
						scanf("%d",&choice2);
						printf("\n~~~~~~~~~~\n");
						if(choice2==1){
							c='1';
							if(is_readed(c)==1){										//is readed function check that if the chosen news is readed before.if it is readed it will ask to read it again?
								printf("This news is readed. Do you want to read again? Yes(1)/ No(0)\n");
								scanf("%d",&is_yes);
								if(is_yes==1){
									read_news(buffer,"news/1.txt",is_Only_Title);
								}
								else printf("INVALID CHOICE!!\n");
							}
							else{
								read_news(buffer,"news/1.txt",is_Only_Title);			//if is_readed function return 0 then it wont ask to read it again?
								append_file("readed_news_id.txt", c);					//it will add the readed numbers id to the readed_news_id file by using append_file function.
							}
						}

						// ABOVE COMMENTS ARE VALID FOR ALL case 'a' CONDITIONS.

							else if(choice2==2){
								c='2';
								if(is_readed(c)==1){
									printf("This news is readed. Do you want to read again? Yes(1)/ No(0)\n");
									scanf("%d",&is_yes);
									if(is_yes==1){
										read_news(buffer,"news/2.txt",is_Only_Title);
									}
									else printf("INVALID CHOICE!!\n");
								}
								else {
									read_news(buffer,"news/2.txt",is_Only_Title);
									append_file("readed_news_id.txt", c);
								}
							}
							else if(choice2==3){
								c='3';
								if(is_readed(c)==1){
									printf("This news is readed. Do you want to read again? Yes(1)/ No(0)\n");
									scanf("%d",&is_yes);
									if(is_yes==1){
										read_news(buffer,"news/3.txt",is_Only_Title);
									}
									else printf("INVALID CHOICE!!\n");
								}
								else {
									read_news(buffer,"news/3.txt",is_Only_Title);
									append_file("readed_news_id.txt", c);
								}	
							}
							else if(choice2==4){
								c='4';
								if(is_readed(c)==1){
									printf("This news is readed. Do you want to read again? Yes(1)/ No(0)\n");
									scanf("%d",&is_yes);
									if(is_yes==1){
										read_news(buffer,"news/4.txt",is_Only_Title);
									}
									else printf("INVALID CHOICE!!\n");
								}
								else {
									read_news(buffer,"news/4.txt",is_Only_Title);
									append_file("readed_news_id.txt", c);
								}
							}
						else{
							printf("INVALID CHOICE!\n");

						}
						printf("\nDo you want to continue? Yes(y)/No(n)\n");
						scanf(" %c",&choice3);
						printf("\n");
						if (choice3=='n'){
							printf("Good Bye!\n");
							loop=1;
						}				
			break;
			case 'b':	
						printf("\n");
						read_file_write_terminal("readed_news_id.txt");		//if user choose case b,readed news will be printed to screen from the file.
						printf("\n");
			break;
					
			case 'c':	
						read_magic_numbers(buffer_magic,buffer_news);					//if the user choose case c, read_magic_numbers funtion will calculate the magic number and print it.
						break;

			default:	
						printf("INVALID CHOICE. TRY AGAIN!\n\n");
						break;
		}
	}
}
//////////////////////////////////////////////////////////////////////////
void read_magic_numbers(char buffer_magic[10], char buffer_news[500]){

	int i,j,k;
	int quantity=0;							//quantity is the number of magic numbers.
	double magicNumber=0;
	char decryptNews;

	FILE *fp;
	
	printf("which news would you like to decrypt?:\n");
	scanf(" %c",&decryptNews);
	
	while(1)
	if(decryptNews=='1'){									//if the user choose decrypting the first news, 
		fp=fopen("news/1.txt","r");
		read_file_write_terminal("news/1.txt");				//read_file_write_terminal funtiopn will read and print the news.
		printf("\nThe number of tests performed: ");		
		break;
	}
	// ABOVE COMMENTS ARE VALID FOR ALL case 'c'/ (else if) CONDITIONS.

		else if(decryptNews=='2'){
			fp=fopen("news/2.txt","r");
			read_file_write_terminal("news/2.txt");
			printf("\nThe number of sick people: ");
			break;
		}
		else if(decryptNews=='3'){
			fp=fopen("news/3.txt","r");
			read_file_write_terminal("news/3.txt");
			printf("\nThe number of deaths: ");
			break;
		}
		else if(decryptNews=='4'){
			fp=fopen("news/4.txt","r");
			read_file_write_terminal("news/4.txt");
			printf("\nThe expected number of sick people: ");
			break;
		}
	else{
		 printf("INVALID CHOICE!!TRY AGAIN\n");
		 scanf(" %c",&decryptNews);
	}

	i=0;
	j=0;
	buffer_news[i]=fgetc(fp);							//first i get char from the file and 
	while(!feof(fp)){									//go through until the EOF
		if(buffer_news[i]=='#'){						//if the selected char is # the next char will be one of our magic number so 
			buffer_magic[j]=(getc(fp)-48);				//we assign it to buffer_magic array.
			fseek(fp,-1, SEEK_CUR);						//and make the cursor step backwards 
			quantity++;									//increasing the number of magic numbers.
			j++;										//and increasing the iterator of buffer_magic array
		}	
		i++;
		buffer_news[i]=getc(fp);						//and take a char again to go until EOF
	}
	buffer_news[i]='\0';								//assign '\0' to last element of buffer_news array to prevent to make cursor go further.
	
	for(k=0;k<quantity;k++){							//calculating the magic number by adding them all.
		magicNumber+=g_func(f_func,buffer_magic[k]);
	}
	printf("%.2f\n\n",magicNumber);
	fclose(fp);
}
//////////////////////////////////////////////////////////////////////////
double f_func(int x){
	
	double result_f;
	result_f= (x*x*x)-(x*x)+2;			//mathematical expression of function f_func
return result_f;
}
//////////////////////////////////////////////////////////////////////////
double g_func(double f(int x),int a){

	double result_g;
	result_g= f(a)*f(a);					//mathematical expression of function g_func
return result_g;
}
//////////////////////////////////////////////////////////////////////////
void read_news(char buffer[500], char file_path[11], int is_Only_Title){

	int i;
	FILE *fp;
	fp=fopen(file_path,"r");

	if(is_Only_Title==1){					// if the is_Only_Title==1 just the title will be readed.
			i=0;
			buffer[i]=fgetc(fp);			//first we get char from the file
			while(buffer[i]!='\n'){			//and continue to move forward until the first line is end.
				i++;
				buffer[i]=fgetc(fp);		//and assign all the chars into buffer.
			}
			buffer[i]='\0';					//assign '\0' to last element of buffer_news array to prevent to make cursor go further.
			for(i=0;i<500;i++){				//and chars will be written until the cursor sees '\0'
				printf("%c",buffer[i]);
				if(buffer[i+1]=='\0') break;
			}
			fclose(fp);
			printf("\n");
	}
	else{
		i=0;								//if the is_Only_Title==0 all the news will be readed.

		// ABOVE COMMENTS ARE VALID FOR THE FOLLOWING LOOP. 
		//ONLY DIFFERENT IS IT WILL CONTINUE UNTIL EOF NOT UNTIL THE END OF FIRST LINE
		buffer[i]=fgetc(fp);
		while(!feof(fp)){
			i++;
			buffer[i]=getc(fp);
		}
		buffer[i]='\0';
		for(i=0;i<500;i++){
			printf("%c",buffer[i]);
			if (buffer[i+1]=='\0') break;
		}
		fclose(fp);
	}
	//printf("\n~~~~~~~~~~\n");
}
//////////////////////////////////////////////////////////////////////////
void append_file(char *file_path, char c){

	FILE *fp;
	fp=fopen(file_path,"a");
	fprintf(fp,"%c. news is readed\n",c);		//appanding file that whic news is readed.
	fclose(fp);
}
//////////////////////////////////////////////////////////////////////////
void read_file_write_terminal(char *file_path){

	char ch;

	FILE *fp;
	
	fp=fopen(file_path,"r");
	while ((ch = fgetc(fp)) != EOF){			//this functions read any file and print it to the terminal screen.
	  printf("%c", ch);
	}
	fclose(fp);
}
//////////////////////////////////////////////////////////////////////////
int is_readed(char n){

	int is_readed;
	char ch;								//this function checks that if the chosen news is readed or not.
	
	FILE *fp;
	fp=fopen("readed_news_id.txt","r");
	while((ch=getc(fp))!=EOF){				//takes a char until EOF and checks that the chosen news id is in there or not.  
		if(ch==n){							//if it is already there stimulate the user that the chosen news is readed before.	
			is_readed=1;
			break;
		}
		else{
			is_readed=0;					// if not is_readed will be 0 and means that the chosen news has not been readed before
		}
	}
	fclose(fp);
return is_readed;
}
//////////////////////////////////////////////////////////////////////////

