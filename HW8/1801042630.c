#include<stdio.h>
#include<stdlib.h>

void menu();
void generate_hofstadters_sequence (int *arr, int n);
int find_max (int arr[], int index, int max_value);
int sum_array (int arr[]);
char* remove_duplicates(char *str);

int main(){
	menu();
return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void menu(){
	int arr[500]={0};
	int i,n,choice,subMenu;
	int index,max_value=0;

	while(1){
		printf("\nWelcome to Homework 8, please choose one of the parts to continue.\n");
		printf("--------------------\n");
		printf("1) Execute Part 1\n");
		printf("2) Execute Part 2\n");
		printf("3) Execute Part 3\n");
		printf("4) Exit\n");
		scanf("%d",&choice);
		printf("\n");
		if(choice==1){
			while(1){
				printf("\nPlease make your choice:\n----------------\n");
				printf("1) Fill Array\n");
				printf("2) Find the Biggest Number\n");
				printf("3) Calculate Sum\n");
				printf("4) Calculate Standard Deviation\n");
				printf("5) Exit\n");
				scanf("%d",&subMenu);
				if(subMenu==1){
					for(i=0;i<500;i++){										//in every time the user choose filling array, before it fills the array first, it assigns 0 to every index.
						arr[i]=0;
					}
					while(1){
						printf("\nPLEASE ENTER A POSITIVE NUMBER: ");
						scanf("%d",&n);
						if(n>=1) break;	
						else printf("INVALID CHOICE. TRY AGAIN.\n");
					}
					generate_hofstadters_sequence(arr,n-1);					//This function produces hofstadters_sequence
					for(i=0;i<n;i++){
						printf("%d  ",arr[i]);
					}
					printf("\n");
				}
					else if(subMenu==2){
						max_value=0;										// in every time the user choose finding max_value,first 0 is assign to it to clear the previous one. 
						index=500;											//index is max element number
						max_value=find_max(arr,index,max_value);			//This function find the largest element of an array.
						printf("\n\nTHE LARGEST ELEMENT OF THE ARRAY IS: %d \n\n",max_value);	
					}
					else if(subMenu==3){
						int sum=sum_array(arr);								//adds the elements of array
						printf("\n\nSUM OF THE ELEMENTS IN THE ARRAY: %d \n\n",sum);
					}
					else if(subMenu==4){
						printf("UNFORTUNATELY I COULDN'T ACHIEVE THIS PART\n");
					}
					else if(subMenu==5){
						break;
					}
				else{
					printf("INVALID CHOICE. TRY AGAIN.\n");
				}
			}
		}
		else if(choice==2){
			printf("UNFORTUNATELY I COULDN'T ACHIEVE THIS PART\n");
		}
		else if(choice==3){
			char string[150];
			printf("Enter a sentences that you want to remove dupilcated characters.\n");
			fgetc(stdin);
			fgets(string,150,stdin);					//Takes string from the user (max 150 char-you can increase or decrease it)
			printf("%s",remove_duplicates(string));		//in here, function pointer is used to return string value.
		}
		else if(choice==4){
			printf("YOU ARE LEAVING...\n");
			exit(0);
		}
		else{
			printf("INVALID CHOICE. TRY AGAIN.\n");
		}
	}
}	
//////////////////////////////////////////////////////////////////////////////////////////////////
int sum_array(int arr[]){
	if(*arr==0)	return 0;							//if the last element of array is 0 returns 0;
	else 		return arr[0]+sum_array(arr+1);		// if not it adds first element of array with next value of the function.
}
//////////////////////////////////////////////////////////////////////////////////////////////////
int find_max(int arr[], int index, int max_value){
	if(index==0){
		return max_value;					//if the sent is 0 existing max_value will be returned.
	}
	else{
		if(arr[index]>max_value){			//checks the present index of arr that is it larger than assigned max_value
			max_value=arr[index];			//if it is larger than, it assigns it to max_value.
		}
		return find_max(arr,index-1,max_value);		//then calls the function again with index-1 to finally reach the first element of it. 
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void generate_hofstadters_sequence (int *arr, int n){
	int temp1,temp2;
	if(n==0||n==1){
		arr[0]=1;					//if 1 or 2 is entered by the user arr[0] and arr[1] will be 1 accdording to definition.
		arr[1]=1;
	}
	else{
		generate_hofstadters_sequence(arr,n-1);	//function finds the previous element of array.
		generate_hofstadters_sequence(arr,n-2);	//function finds the 2 previous element of array.
		temp1=arr[n-1];	//assign the found value to variable
		temp2=arr[n-2];	//assign the found value to another variable.
		arr[n]=arr[n-temp1]+arr[n-temp2];// adds them to create next value of the hofstadters sequence.
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
char* remove_duplicates(char *str){
	int i;
	if((*str)==*(str+1)){				//compares that present and next char is equal or not
		for(i=0;i<150;i++){
			str[i]=str[i+1];			//if they are equal,swift the string to the left for all next chartacters.
		}
		remove_duplicates(str);			//then calls the function to compara it again. by this way, if it is repeated more than twice, it will be found anyway.
	}
	if(*str!='\0'){						//function calls itself until it reaches to the '\0' element 
		remove_duplicates(str+1);
	}
	return str;							// finally str value will be returned as string.
}
//////////////////////////////////////////////////////////////////////////////////////////////////