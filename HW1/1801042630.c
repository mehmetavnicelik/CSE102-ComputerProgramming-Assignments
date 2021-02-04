#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void find_root();
void find_newtonian_root();
int find_multiple_closest(int a, int b);

// I didnt build a menu because when we ask you about it, you sad there is no need to menu.

int main(){
	int dividend,divider;
	printf("-----PART 1-----\n");	
	find_root(); 
	printf("-----PART 2-----\n");
	find_newtonian_root(); 
		
	printf("-----PART 3-----\n");
	printf("Enter the first integer: \n");
	scanf("%d",&dividend);
	printf("Enter the second integer: \n");
	scanf("%d",&divider);

	if(dividend<divider){
		printf("The divider is greater than the dividend. Try again.\n");
	}
		else if(dividend%divider==0){	// means that the remainder is 0 and a is multiple of b
			printf("Closest number to %d that is multiple of %d is itself.",dividend,find_multiple_closest(dividend,divider));	//returned value will be shown.
		}
		
		else if(dividend%divider!=0){	// means that the remainder is different than 0.
			if(dividend%divider>=divider/2){	// If the remainder is greater than half of divider,then it is closer to previous one.  
				printf(" Closest number to %d that is multiple of %d is %d",dividend,divider,find_multiple_closest(dividend,divider));	//returned value will be shown.
			}
				else if(dividend%divider<divider/2){	//If the remainder is lower than half of divider,then it is closer to next one. 
					printf(" Closest number to %d that is multiple of %d is %d",dividend,divider,find_multiple_closest(dividend,divider));	//returned value will be shown.
				}
		}
return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void find_root(){
	
	double a,b,c;	//ax^2+bx+c=0;
	double root1,root2,delta;
	
	printf("Enter the first coefficient: \n");
	scanf("%lf",&a);
	printf("Enter the second coefficient: \n");
	scanf("%lf",&b);
	printf("Enter the third coefficient: \n");
	scanf("%lf",&c);
	
	delta=(b*b)-(4*a*c);
	
	if(delta>0){	
		root1=(-b+(sqrt(delta)))/(2*a);	//mathematical expression for finding roots.
		root2=(-b-(sqrt(delta)))/(2*a);	//mathematical expression for finding roots.
		printf("Your equation (%.0f)x^2 + (%.0f)x + (%.0f) have real roots {%.1f, %.1f}.\n",a,b,c,root1,root2);
	}
		else if(delta==0){
			root1=(-b+sqrt(delta))/2*a; //mathematical expression for finding roots.
			printf("Your equation (%.0f)x^2 + (%.0f)x + (%.0f) have 1 real root {%.1f}.\n",a,b,c,root1);
		}
		else if(delta<0){	//it will have complex number of roots.
			printf("Your equation (%.0f)x^2 + (%.0f)x + (%.0f) does not have any real roots.\n",a,b,c);
		}
	else{
		printf("ERROR");
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void find_newtonian_root(){
	
	double a,b,c; //	ax^2+bx+c=0;
	double initial;
	double delta,closer;
	double root1,root2;
	
	printf("Please enter the first coefficient: \n");
	scanf("%lf",&a);
	
	printf("Please enter the second coefficient: \n");
	scanf("%lf",&b);
	
	printf("Please enter the third coefficient: \n");
	scanf("%lf",&c);

	delta=(b*b)-(4*a*c);
	root1=(-b+(sqrt(delta)))/(2*a);
	root2=(-b-(sqrt(delta)))/(2*a);
	
	
	printf("Please enter the initial: \n");
	scanf("%lf",&initial);
	printf("Your equation is (%.0f)x^2 + (%.0f)x + (%.0f) and iterations are \n",a,b,c);
	printf("Step\tx\tf(x)\tDifference \n");
	
	//in every step, new initial will be the next root.
	
	initial= initial - ((a*initial*initial)+(b*initial)+c) / ((2*a*initial)+(b));	//Newtonian root method's mathematical expression step1
	
	if(abs(root1-initial)>abs(root2-initial)){closer=root2;}					//Finding the closer root of equation's, to initial root.
	else if(abs(root1-initial)<=abs(root2-initial)){closer=root1;}
	else{printf("ERROR");}
	
	printf("x1\t");
	printf("%.4lf\t",initial);
	printf("%.4lf\t",((a*initial*initial)+(b*initial)+c));
	printf("%.4lf\n",initial-closer);	//initial - closer will be the difference in every step of newtons method.
	
	initial= initial - ((a*initial*initial)+(b*initial)+c) / ((2*a*initial)+(b)); //Newtonian root method's mathematical expression step2
	printf("x2\t");
	printf("%.4lf\t",initial);
	printf("%.4lf\t",((a*initial*initial)+(b*initial)+c));
	printf("%.4lf\n",initial-closer);
	
	
	initial= initial - ((a*initial*initial)+(b*initial)+c) / ((2*a*initial)+(b)); //Newtonian root method's mathematical expression step3
	printf("x3\t");
	printf("%.4lf\t",initial);
	printf("%.4lf\t",((a*initial*initial)+(b*initial)+c));
	printf("%.4lf\n",initial-closer);
	
	
	initial= initial - ((a*initial*initial)+(b*initial)+c) / ((2*a*initial)+(b)); //Newtonian root method's mathematical expression step4
	printf("x4\t");
	printf("%.4lf\t",initial);
	printf("%.4lf\t",((a*initial*initial)+(b*initial)+c));
	printf("%.4lf\n",initial-closer);
	
	
	initial= initial - ((a*initial*initial)+(b*initial)+c) / ((2*a*initial)+(b)); //Newtonian root method's mathematical expression step5
	printf("x5\t");
	printf("%.4lf\t",initial);
	printf("%.4lf\t",((a*initial*initial)+(b*initial)+c));
	printf("%.4lf\n",initial-closer);
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int find_multiple_closest(int a,int b){
	int remainder,division;
	
		if(a%b==0){	// means that the remainder is 0 and a is multiple of b
			return b;
		}
			else if(a%b!=0){	// means that the remainder is different than 0.
				division=a/b;	// finding the division by ignoring fractions.
				remainder=a%b;	// finding the remainder.
				// finding that if remainder is closer to next dividend or previous dividend.
				if(a%b>=b/2){	// If the remainder is greater than half of divider,then it is closer to previous one.  
					return b*(division+1); 
				}
					else if(a%b<b/2){	//If the remainder is lower than half of divider,then it is closer to next one. 
						return (a-remainder);
					}
			}
	else{
		printf("ERROR");
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////