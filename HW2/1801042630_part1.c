#include <stdio.h>
#include <math.h>

int draw_triangle(int side1,int side2, int side3);
void type_triangle(int side1,int side2, int side3);
int perimeter_triangle(int side1,int side2, int side3);
double area_triangle(int side1,int side2, int side3,int perimeter);


int main(){
	
	int 	side1,side2,side3;		
	int 	be_drawn,perimeter;		
	float 	area;					
	
	printf("~~~~~Please enter the triangle's sides~~~~~\n");
	printf("The length of first side: \n");
	scanf("%d",&side1);
	printf("The length of second side: \n");
	scanf("%d",&side2);
	printf("The length of third side: \n");
	scanf("%d",&side3);

	be_drawn = draw_triangle(side1,side2,side3);
	if(be_drawn==0){
		printf("According to the triangle inequality theorem, this triangle cannot be drawn.\n");
	}
	else{
		printf("According to the triangle inequality theorem, this triangle can be drawn.\n");		
		type_triangle(side1,side2,side3);
		perimeter = perimeter_triangle(side1,side2,side3);			//ASSIGNING THE RETURNED PERIMETER VALUE TO 'PERIMETER'
		area = area_triangle(side1,side2,side3,perimeter);			//ASSIGNING THE RETURNED AREA VALUE TO 'AREA'
		printf("The perimeter of the triangle: %d\n",perimeter);
		printf("The area of the triangle: %.3f\n\n",area);
	}
return 0;
}
/////////////////////////////////////////////////////////////
int draw_triangle(int side1,int side2, int side3){
	
	int result;
	if(side1+side2 > side3	&&	side1+side3 > side2	&&	side2+side3>side1){		//WE ARE CHECKING THAT IF A TRIANGLE CAN OR CANNOT BE DRAWN, BY USING TRIANGLE INEQUALITY THEOREM
		result = 1;	//IF IT ENSURE, 1 WILL BE RETURNED
	}
	else{			//IF NOT,0 WILL BE RETURNED.
		result = 0;
	}
	
return result;
}
/////////////////////////////////////////////////////////////
void type_triangle(int side1,int side2, int side3){
	
	if(side1==side2 && side1==side3){
		printf("It is an equilateral triangle.\n");
	}
		else if(side1==side2 && side1!=side3 || side1==side3 && side1!=side2 || side2==side3 && side2!=side1){	//WE ARE CHECKING THAT IF IT VERIFY FOR ALL CONDITIONS
			printf("It is an isosceles triangle.\n");
		}
		else if(side1!=side2 && side1!=side3 && side2!=side3){
			printf("It is a scalene triangle.\n");
		}
	else{
		printf("ERROR.\n");
	}
}
/////////////////////////////////////////////////////////////
int perimeter_triangle(int side1,int side2, int side3){
	
	int perimeter;
	perimeter=side1+side2+side3;									//CALCULATING THE PERIMETER OF THE TRIANGLE

return perimeter;
}
/////////////////////////////////////////////////////////////
double area_triangle(int side1,int side2, int side3,int perimeter){
	
	double area,formula,x;

	x =(double)perimeter/2;										//PERIMETER IS AN INTEGER VALUE SO WE ALLOW THE 'PERIMETER' TO KEEP DOUBLE VALUE
																//CALCULATING THE AREA OF THE TRIANGLE
	formula = (double)x*(x-side1)*(x-side2)*(x-side3);
	area=sqrt(formula);											//SQUARE ROOT FUNCTION

return  area;
}
/////////////////////////////////////////////////////////////