#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_ELEMENT 100
#define PI 3.14

typedef struct point{
	double x;
	double y;					//structure for points
	char name[10];
}_point;

typedef struct line{
	_point a;
	_point b;					//nested structure for lines
	char name[10];
}_line;

typedef struct polygon{
	_point dot[20];				//nested structure for polygons
	_line link[20];
	char name[10];
}_polygon;

void fill_array(char str[], FILE *fp,_point *points,_line *lines,_polygon *polygons);
void distance_point2point(char str[],char command[],FILE *fp,_point *points);
void distance_point2line(char str[],char command[],FILE *fp,_point *points,_line *lines);
void length_of_line(char str[],char command[],FILE *fp,_point *points,_line *lines);
void angle(char str[],char command[],FILE *fp,_point *points,_line *lines);

int main(){	
	_point 		points[MAX_ELEMENT];				//a _point type of array to keep points
	_line 		lines[MAX_ELEMENT];					//a _line type of array to keep lines
	_polygon	polygons[MAX_ELEMENT];				//a _polgon tyepe of array to keep polygons

	int i,flag=0;
	int rowNumber;
	char str[100];
	char command[100],cmd[100];
	char inp1[10],inp2[10];
	FILE *infile,*outfile;
	infile=fopen("commands.txt","r");


	fgets(str,100,infile);
	if(str[0]=='d'&&str[1]=='a'&&str[2]=='t'&&str[3]=='a'){
		fill_array(str,infile,points,lines,polygons);				//arrays will be filled according to files commands.
	}
	else{
		printf("DATA CAN NOT BE FOUND.\n");
		exit(0);
	}
	do{
		fgets(str,100,infile);										//after filling is done it will go until action part.
	}while(str[0]!='a'&&str[0]!='c'&&str[0]!='t'&&str[0]!='i'&&str[0]!='o'&&str[0]!='n');	
	
	fgets(str,100,infile);
	outfile=fopen(str,"w");
	fgets(str,100,infile);
	sscanf(str,"%d",&rowNumber);
	for(i=0;i<rowNumber;i++){
		fgets(str,100,infile);
		strcpy(cmd,str);
		sscanf(str,"%s %s %s",cmd,inp1,inp2);
		strcpy(command,str);											//According to commands and inputs the process will be executed.
		sscanf(command,"%s",command);					
		if(strcmp(cmd,"Distance")==0 && inp1[0]=='P' && inp2[0]=='P'){		
			distance_point2point(str,command,outfile,points);
		}
		else if(strcmp(cmd,"Distance")==0 && (inp1[0]=='P' && inp2[0]=='L' || inp1[0]=='L' && inp2[0]=='P')){
			distance_point2line(str,command,outfile,points,lines);
		}
		else if(strcmp(cmd,"Angle")==0){
			angle(str,command,outfile,points,lines);
		}
		else if(strcmp(cmd,"Length")==0 && (inp1[0]=='L')){
			length_of_line(str,command,outfile,points,lines);
		}
		else{
			if(flag==0){
				fprintf(outfile,"\nUnfortunately I failed to handle Polygons.\n");
				fprintf(outfile,"--NOT_IMPLEMENTED--");
				flag++;
			}
		}
	}
	fclose(infile);
	fclose(outfile);
return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void fill_array(char str[], FILE *fp,_point *points,_line *lines,_polygon *polygons){
	int rowNumber;
	int i,j;
	char a[5];
	char b[5];
	_point *tempP;
	_line *tempL;
	
	tempP=points;
	tempL=lines;

	fgets(str,100,fp);
	sscanf(str,"%d",&rowNumber);
	for(i=0;i<rowNumber;i++){
		fgets(str,100,fp);
		if(str[0]==' '||str[0]=='0'||str[0]=='1'||str[0]=='2'||str[0]=='3'||str[0]=='4'||str[0]=='5'||str[0]=='6'||str[0]=='7'||str[0]=='8'||str[0]=='9'){
			sscanf(str,"%lf %lf %s",&points->x,&points->y,points->name);
			points++;
		}
		else if(str[0]=='P'&& str[6]=='L'){
			points=tempP;
			sscanf(str,"%s %s %s",a,b,lines->name);
			for(j=0;j<100;j++,points++){
				if(strcmp(a,points->name)==0){
					lines->a.x=points->x;
					lines->a.y=points->y;
					break;
				}
			}
			points=tempP;
			for(j=0;j<100;j++,points++){
				if(strcmp(b,points->name)==0){
					lines->b.x=points->x;
					lines->b.y=points->y;
				}
			}
			lines++;
		}

		/*else{
			points=tempP;
			lines=tempL;
			printf("polygon olacak\n");
		}*/
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////
void distance_point2point(char str[],char command[], FILE *fp,_point *points){
	char point1[5];
	char point2[5];
	double distance;
	double x1,y1,x2,y2;
	_point temp[100];
	
	*temp=*points;								//temp array is used for keeping the original address of the point array.
	sscanf(str+8," %s %s",point1,point2);
	for(;;points++){							//point names are in the point arrays.
		if(strcmp(points->name,point1)==0){		//those are comparing to find their name in the point array by increasing the adress.
			x1=points->x;						//when found assigning is done.
			y1=points->y;
			break;
		}
	}
	*points=*temp;
	for(;;points++){
		if(strcmp(points->name,point2)==0){		//same process
			x2=points->x;
			y2=points->y;
			break;
		}
	}
	distance=sqrt(pow((x1-x2),2)+pow((y1-y2),2));				//calculation of the formula to find distance between 2 points.
	fprintf(fp,"%s(%s,%s) = %.1f\n",command,point1,point2,distance);		//print it on the file.
}
////////////////////////////////////////////////////////////////////////////////////////////////
void distance_point2line(char str[],char command[],FILE *fp,_point *points,_line *lines){
	char point[5];
	char street[5];
	float slope,distance;
	float x1,y1,initial_point_x,initial_point_y,end_point_x,end_point_y;
	float A,B,C;
	_point tempP[100];
	_line tempL[100];
	
	*tempP=*points;								//temp array is used for keeping the original address of the point array.
	*tempL=*lines;								//temp array is used for keeping the original address of the line array.
	sscanf(str+8," %s %s",point,street);
	for(;;points++){
		if(strcmp(points->name,point)==0){				//point names are in the point arrays.
			x1=points->x;								//those are comparing to find their name in the point array by increasing the adress.
			y1=points->y;								//when found assigning is done.
			break;	
		}
	}
	*points=*tempP;
	for(;;lines++){
		if(strcmp(lines->name,street)==0){				//line names are in the line array.
			initial_point_x=lines->a.x;					//those are comparing to find their name in the line array by increasing the adress.
			initial_point_y=lines->a.y;					//when found assigining to lines points x and y values is done.

			end_point_x=lines->b.x;						//second point of line 
			end_point_y=lines->b.y;
			break;
		}
	}
	slope=(float)(end_point_y-initial_point_y)/(float)(end_point_x-initial_point_x);	//mathematical expression of slope
	if((end_point_x-initial_point_x)==0){
		fprintf(fp,"%s(%s,%s) = %.1f\n",command,point,street,initial_point_x-x1);		//this is for undefined slope.
	}
	else{
		A=-slope;
		B=1;
		C=slope*end_point_x-end_point_y;
		distance= fabsf(A*x1+B*y1+C)/sqrt(pow(A,2)+pow(B,2));				//mathematical expression of distance.
		fprintf(fp,"%s(%s,%s) = %.1f\n",command,point,street,distance);	
	}	
}
////////////////////////////////////////////////////////////////////////////////////////////////
void length_of_line(char str[],char command[],FILE *fp,_point *points,_line *lines){
	char street[5];
	float length;
	float x1,y1,x2,y2;
	_line tempL[100];
	
	*tempL=*lines;
	sscanf(str+7,"%s",street);
	for(;;lines++){							//line names are in the line array.
		if(strcmp(lines->name,street)==0){	//those are comparing to find their name in the line array by increasing the adress.
			x1=lines->a.x;					
			y1=lines->a.y;					//when found assigining to lines points x and y values is done.

			x2=lines->b.x;					//second point of line 
			y2=lines->b.y;
			break;
		}
	}
	*lines=*tempL;
	length=sqrt(pow((x1-x2),2)+pow((y1-y2),2));			//mathematical expression of length
	fprintf(fp,"%s(%s) = %.1f\n",command,street,length);
}
////////////////////////////////////////////////////////////////////////////////////////////////
void angle(char str[],char command[],FILE *fp,_point *points,_line *lines){
	char street1[5];
	char street2[5];
	float slope1,slope2;
	float x1,y1,x2,y2,x3,y3,x4,y4;
	float A,B,C;
	float angle;
	_point tempP[100];
	_line tempL[100];
	
	*tempP=*points;
	*tempL=*lines;
	sscanf(str+5," %s %s",street1,street2);		
	for(;;lines++){								
		if(strcmp(lines->name,street1)==0){		//those are comparing to find their name in the line array by increasing the adress.
			x1=lines->a.x;
			y1=lines->a.y;						//when found assigining to lines points x and y values is done.

			x2=lines->b.x;						//second point of line 
			y2=lines->b.y;
			break;
		}
	}
	*lines=*tempL;
	for(;;lines++){
		if(strcmp(lines->name,street2)==0){
			x3=lines->a.x;
			y3=lines->a.y;					//this is for the second line. 
											// the comment are same with the explanation above.
			x4=lines->b.x;
			y4=lines->b.y;
			break;
		}
	}
	slope1=(y2-y1)/(x2-x1);
	slope2=(y4-y3)/(x4-x3);
	if(slope1*slope2==-1||x2==x1||x4==x3){		//if 2 lines slopes multiplication is equal to -1 that means the lines are perpendicular to each other.
		angle=90;
	}
	else{
		angle=180*atan((slope1-slope2)/(1+(slope1*slope2)))/PI;		//or we can calculate the inner angle with this formula.
	}
	if(angle<0) angle=angle*-1;
	fprintf(fp,"%s(%s,%s) = %.1f\n",command,street1,street2,angle);
}
////////////////////////////////////////////////////////////////////////////////////////////////