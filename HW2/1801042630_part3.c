#include <stdio.h>

#define EURO 	6.69
#define DOLLAR 	6.14
#define LIRA 	1

int main(){

	int 	own_currency,converted_currency;	
	float 	own_money,converted_money;			
	int 	check;
	printf("*****Welcome to ACDC Exchange Office****\n\n");
	printf("Enter your amount:\n");
	scanf("%f",&own_money);
	printf("\nPlease select your currency:\n");
	printf("1. Turkish Lira\n2. Euro\n3. Dollar\n\n");
	scanf("%d",&own_currency);
	
		switch(own_currency){
			case 1: 
				printf("You have %f Turkish Liras\n",own_money);
				break;
			case 2: 
				printf("You have %f Euro.\n",own_money);
				break;
			case 3: 
				printf("You have %f Dollar\n",own_money);
				break;
			default:
				printf("Invalid Selection\n");
				return 0;
		}

	printf("Choose which currency you want to convert.\n");
	scanf("%d",&converted_currency);
	switch(converted_currency){
		case 1: 												//from others to lira conversion
			switch(own_currency){
				case 1: 
					converted_money=own_money;					//lira to lira conversion
					break;
				case 2: 
					converted_money=(EURO/LIRA)*own_money;		//euro to lira conversion
					break;
				case 3: 
					converted_money=(DOLLAR/LIRA)*own_money;	//dollar to lira conversion
					break;
					default:
					printf("Invalid Selection\n");
					return 0;
			}
			printf("\nYou have %f Turkish Liras.\n",converted_money);
			break;
		
		case 2: 											//from others to euro conversion
			switch(own_currency){
				case 1: 
					converted_money=(LIRA/EURO)*own_money;	//lira to euro conversion
					break;
				case 2: 
					converted_money=own_money;				//euro to euro conversion
					break;
				case 3: 
					converted_money=(DOLLAR/EURO)*own_money;	//dollar to euro conversion
					break;
				default:
				printf("Invalid Selection\n");
				return 0;
			}
			printf("\nYou have %f Euros.\n",converted_money);
			break;
	
		case 3: 												// from others to dollar converison
			switch(own_currency){
				case 1: 
					converted_money=(LIRA/DOLLAR)*own_money;	//lira to dollar conversion
					break;
				case 2: 
					converted_money=(EURO/DOLLAR)*own_money;	//euro to dollar conversion
					break;
				case 3: 
					converted_money=own_money;					//dollar to dollar converison
					break;
				default:
				printf("Invalid Selection\n");
				return 0;
			}
			printf("\nYou have %f Dollars.\n",converted_money);
			break;

			default:
			printf("Invalid Selection\n");
			return 0;
	}

return 0;
}
