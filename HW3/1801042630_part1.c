#include<stdio.h>

int sum(int n,int flag);
int mult(int n,int flag);

int main(){
	int number,operation,flag;
	int addition,multiplication;

	printf("Enter an integer: ");
	scanf("%d",&number);
	printf("Please enter '0' for sum, '1' for multiplication:\n");
	scanf("%d",&operation);
	printf("Please enter '0' to work on even numbers, '1' to work on odd numbers:\n");
	scanf("%d",&flag);
	switch(operation){
		case 0:											//case 0 is about addition
	 		addition=sum(number,flag);
	 		if(addition!=0){
	 			printf("%d\n",addition);				//until the chosen number sequence will be written in sum function.
	 		}											//the result will return and will be written in here,main.
	 		else; 
	 		break;
		case 1:											//case 1 is about multiplication
			multiplication=mult(number,flag);
			if(multiplication!=0){						//until the chosen number sequence will be written in mult function.
				printf("%d\n",multiplication);			//the result will return and will be written in here,main.
			}
			else;
			break;
		default:
			printf("Unsupported operation!\n");
			break;
	}

return 0;
}
////////////////////////////////////////////////////////////////////////
int sum(int n,int flag){
	int i,sum=0;
	if(flag==0){					//flag=0 is about even numbers
		for(i=2;i<n;i+=2){
			if(i+2<n){						//******EXPLANATION THE OPERATIONS BELOW******//
				printf("%d + ",i);			//if i+2<(the chosen number) in main, it will print the 
			}								//sequence 1-by-1.Until the last element of sequence.
			else{							//In the last element i+2 will be larger than the chosen nunmber.
				printf("%d = ",i);			//so code will not enter the if statement.the else statement will work.
			}								//in here,the else statement,because it is the last element of sequence,
			sum+=i;							//the last number and = sign will be written.
		}
	}
		else if(flag==1){			//flag=1 is about odd numbers
			for(i=1;i<n;i+=2){
				if(i+2<n){
					printf("%d + ",i);		//same opeartions. explained above. 
				}
				else{
					printf("%d = ",i);
				}
				sum+=i;
			}
		}
	else{
		printf("Invalid value for odd/even selection.\n");
		return 0;
	}
	return sum;
}
////////////////////////////////////////////////////////////////////////
int mult(int n,int flag){
	int j,product=1;
	if(flag==0){					//flag=0 is about even numbers
		for(j=2;j<n;j+=2){
			if(j+2<n){
				printf("%d * ",j);			//same operations. explained above.
			}
			else{
				printf("%d = ",j);
			}
			product*=j;
		}
	}
		else if(flag==1){			//flag=1 is about odd numbers
			for(j=1;j<n;j+=2){
				if(j+2<n){					//same operations. explained above.
					printf("%d * ",j);
				}
				else{
					printf("%d = ",j);
				}
				product*=j;
			}
		}
	else{
		printf("Invalid value for odd/even selection.\n");
		return 0;
	}
	return product;
}
////////////////////////////////////////////////////////////////////////
