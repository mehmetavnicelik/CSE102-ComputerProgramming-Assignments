#include <stdio.h>
#include <math.h>

int number_length(int number);
int find_digit(int number, int index);

int main(){
	int number,length,index,digit;

	printf("Enter a number (maximum 6 digits):\n");
	scanf("%d",&number);
	if(number>0){										//if the entered number is larger than zero, program will work.
		length=number_length(number);
		if(length>6){
			printf("The length of the number can not be larger than 6.\nINVALID CHOICE");
			return 0;
		}
		printf("Your number has %d digits.\n\n",length);
		printf("When your number is written 100 times next to each other,which digit of this number would you like to see? :\n");
		scanf("%d",&index);

		digit=find_digit(number,index);
		if(digit==-1){									//if the returned value of find_digit function is -1,means that the length of index is 
														//larger than the length of sequence.and it will not work.
			printf("INVALIDE CHOICE!\nThe length of index is larger than the length of sequence.\n");
		}
		else{
			printf("\n\n%d.th digit of the big number sequence: %d\n",index,digit);
		}
	}
	else{
		printf("INVALID CHOICE!\n");					//if the entered number is smaller than or equal to zero, then program will not work.
	}
return 0;	
}
///////////////////////////////////////////////////////
int number_length(int number){

	int result;
	result=(log10(number)+1);							//Taking the natural logarithm of the number to find how many digits does it have. but we have to 
														//add 1 to the result of logarithm. because it will give us a x 10^n. Means that we would found the number 			
return result;											//of zeroes without adding 1.	
}
///////////////////////////////////////////////////////
int find_digit(int number, int index){
	
	int totalDigit,remainder;
	int mod1,newNumber,divider,result2;

	totalDigit = number_length(number);
	remainder=(index%totalDigit);						//we take the index mod total digit of the number to find the remainder. Remainder of this operation
														//will give us the wanted number's place in the original number.	

	if(index>totalDigit*100){							//if the wanted digit's place is larger than sequance, then it will not work.
		return -1;
	}
	else{												//if not, it will work.
		if (remainder==0){
			result2 = (number%10);						//if remainder is zero,means that the wanted number will be the last digit of entered,original, number.
		}
		else{											//if the remainder is different than zero, we try to eliminate the digits before the wanted digits. so we take power 10 to 
			mod1=pow(10,(totalDigit-remainder+1));		//power totaldigit-remainder+1.than take the mod of orijinal number with this result.
			newNumber=(number%mod1);					//i.e by this way if the number is 123456 and 4th digit is wanted, after this operation new number will be 456.

			divider=pow(10,(totalDigit-remainder));		//and now by taking the 10 to the power totaldigit-remainder it will give us the number we should divide, to find
			result2= (newNumber/divider);				//the division.the divisions integer part will give us the wanted number.
			}											//i.e by this way 456/(10^2)=456/100=4.
		}

return result2;
}
///////////////////////////////////////////////////////