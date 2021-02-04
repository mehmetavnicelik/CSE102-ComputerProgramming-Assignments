#include <stdio.h>
#include <math.h>

int isprime (int a);

int main(){
	
	int i;
	int number,check;

	printf("Please enter an integer: ");
	scanf("%d",&number);
	if(number==0||number==1||number==2){
		printf("There is no prime number less than 2!\n");
	}
	else;
	for(i=2;i<number;i++){						//this loop will check every number until the chosen number if it is prime or not.
		check=isprime(i);
		if(check==1){
			printf("%d is a prime number\n\n",i);
		}
		else if(check!=1){
			printf("%d is not a prime number, it is dividible by %d.\n\n",i,check);
		}
		else{
			printf("ERROR!\n");
			break;
		}
	}
return 0;
}
///////////////////////////////////////////////////////////////////
int isprime (int a){

	int flag,i;
	float rootA;

	if(a==2||a==3){				//the easiest way to find 2 and 3 is prime or not,is not include them
		flag=1;					//in any algorithm. just to declare that if the number is 2 or 3,then it is prime.
		return flag;
	}
	else;
	rootA=sqrt(a);
	for(i=2;i<=rootA;i++){
		if(a%i!=0){					//the loops control that if the chosen number is dividible 
			flag=1;					//between values in the formula below:
		}							//1 < X ≤ √A. if it is dividible it wont be prime number.
		else{						//if it is not dividible flag=1 will be returned and it means 
			flag=i;					//the number is not prime.
			break;
		}
	}				//if the number is dividible to something flag value will be the divider value.and return to main

return flag;
}
///////////////////////////////////////////////////////////////////