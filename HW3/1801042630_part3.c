#include<stdio.h>
int digit_comparator(int number1,int number2);
int binary_check(int number1,int number2);
int andop (int a, int b);

int main(){
	int number1,number2;
	int digit,isbinary;
	int and_result;

	printf("First Integer:	");
	scanf("%d",&number1);
	printf("Second Integer:	");
	scanf("%d",&number2);
	
	if(number1==0 || number2==0){
		printf("%d AND %d = 0\n",number1,number2);	// if both number is 0 then the result will be 0.
		return 0;
	}
	else;
	
		while(1){	//the loop is going to work until the both condition satisfies. 
			digit=	digit_comparator(number1,number2);//this function finds out that the digit numbers of two entered number is equal or not.
			isbinary=	binary_check(number1,number2);//this function finds out that the entered numbers are binary or not.
			if(digit==0){//if digits are not equal,then it asks you to enter 2 new integers.
				printf("Integers should have the same length,please enter 2 new integers.\n");
				printf("First Integer:	");
				scanf("%d",&number1);
				printf("Second Integer:	");
				scanf("%d",&number2);
			}
			else;//if it is equal,it contunios.
				
			if(isbinary==0 && digit!=0){ //if 1 of the condition does not satisfy,then it will ask new numbers
				printf("Integers should be binary,please enter 2 new integers.\n");
				printf("First Integer:	");
				scanf("%d",&number1);
				printf("Second Integer:	");
				scanf("%d",&number2);
			}
			else;
			
			if(digit!=0 && isbinary==1){//if both condition satisfies,it will break and leave the loop
				break;
			}
			else;
		}
		and_result= andop(number1,number2);//then it will send the numbers and operaitons function
		printf("%d AND %d = %d\n",number1,number2,and_result);//print the result.

	return 0;
}

///////////////////////////////////////////////////////
int digit_comparator(int number1,int number2){

	int counter1=1,counter2=1;
	int result;

		while(number1>=10){				//the loop will be ececuted until the number1 less than 10
			number1=(number1/10);		//in every step of loop the number will be divided to 10 and 
			counter1++;					//by this way,total digit number will be found.
										//counter1 keeps the digit number of number1
		}
		while(number2>=10){				//the loop will be ececuted until the number2 less than 10
			number2=(number2/10);		//in every step of loop the number will be divided to 10 and 
										//by this way,total digit number will be found.						
			counter2++;					//counter1 keeps the digit number of number2
		}
		if(counter1==counter2) result=counter1;	//if the digits are equal,digits number will be returned.
		else result=0;							//if not,0 will be returned.

return result;
}
////////////////////////////////////////////////////
int binary_check(int number1,int number2){
	int mod1,mod2;
	int flag=0;
	while(flag==0){		
		while(number1>0){	//the loop will be executed until the number==0
			mod1=number1%10;		//we take mod of the entered number to find last digit.
			number1=number1/10;		//then divide the number to 10.to eliminate the digit we found.
			
			if(mod1==0||mod1==1){
				flag=1;			//if mod is 0 or 1,means that it is binary 	
			}
			else{
				flag=0;			//else, not binary.
				break;
			}
		}
		
		if(flag==0){			//if first number is not binary,it doesnt check the second number,
			break;				//it just assigns to flag '0' value than leave the loop.
		}
		else;
		
		while(number2>0){	//the loop will be executed until the number==0
			mod2=number2%10;		//we take mod of the entered number to find last digit.
			number2=number2/10;		//then divide the number to 10.to eliminate the digit we found.
			
			if(mod2==0||mod2==1){
				flag=1;			//if mod is 0 or 1,means that it is binary 	
			}
			else{
				flag=0;			//else, not binary.
				break;
			}	
		}
	}	
	//flag==1 -> BINARY
	//flag==0 -> NOT BINARY 
return flag;
}
//////////////////////////////////////////////////////////
int andop (int a, int b){
	int digitNumber,result=0;
	int mod1=0,mod2=0;
	int i=1,j=1;

	digitNumber= digit_comparator(a,b);		//by using digit_comparator function,the digit number of
	while(i<=digitNumber){					//entered number will be found. Until the digit number the loop will work.
		
		mod1=a%10;				//same way with comparing a digit is binary or not,now,
		a=a/10;					//the digits will be found and compared between each other.
		mod2=b%10;
		b=b/10;

		if(mod1==1 & mod2==1){	//if both digits are 1 then result of and op will 1.
			result+=1*j;		//in every step of loop the cofficient increase 10 times.
		}						
		
		else{					//if both digits are not 1 logical result will be 0.
			result+= 0*j;		//if both digits are not 1, to make the results digit 0,j multiplies by 0.
		}						//when we add the results we will obtain and operation result.				
		j*=10;
		i++;
	}
return result;					//and operations result
}