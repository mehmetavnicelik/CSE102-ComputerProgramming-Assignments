#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

typedef struct n{
	int data;
	struct n *next;
}node;

typedef struct diff{
	int n1;
	int n2;
	struct diff *next;
}_diff;

node* read_linkedlist(char *filename,node *root,int *byte);
int* read_array(char *filename,int *arr,int *byte);
float* stats_array(int *arr);
float* stats_linkedlist(node *root);
_diff* part2();

int main(){

	clock_t start,end;
	float time=0,*values,*values2;
	int i,*arr,byte_used,byte_used2;
	char *filename="list.txt";
	node *root,*iter;
	_diff *source,*iter2;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PART 1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("_________________________________________________\n");
	printf("~~~~~Elapsed Times~~~~~\n");
	//---------------------------------------------------------
	for(i=0;i<4;i++){
		start=clock();
			arr=read_array(filename,arr,&byte_used);
		end=clock();												//read array function
		time+= ((double) (end-start))/CLOCKS_PER_SEC;
	}
	time=time/4;
	printf("-> in (*read_array):\t\t%f s\n",time );
	//---------------------------------------------------------
	time=0;
	for(i=0;i<4;i++){
		start=clock();
			values=stats_array(arr);								//stats array function
		end=clock();
		time+= ((double) (end-start))/CLOCKS_PER_SEC;
	}
	time=time/4;
	printf("-> in (*stats_array):\t\t%f s\n",time );
	//---------------------------------------------------------
	time=0;
	root= (node*)malloc(sizeof(node));
	iter=root;
	for(i=0;i<4;i++){
		start=clock();	
			root=read_linkedlist(filename,root,&byte_used2);		//read linked list function
		end=clock();
		time+= ((double) (end-start))/CLOCKS_PER_SEC;	
	}
	time=time/4;
	printf("-> in (*read_linkedlist):\t%f s\n",time );
	//---------------------------------------------------------
	time=0;
	for(i=0;i<4;i++){
		start=clock();
			values2=stats_linkedlist(root);							//stats linked list function
		end=clock();
		time+= ((double) (end-start))/CLOCKS_PER_SEC;
	}
	time=time/4;
	printf("-> in (*stats_linkedlist):\t%f s\n",time );
	printf("_________________________________________________\n\n");
	//---------------------------------------------------------

	printf("_________________________________________________\n");
	printf("~~~~~(*read_array) Function~~~~~\n");					//statistic of the array
	printf("-> Byte used:\t%d\n",byte_used);							
	printf("-> Mean Value:\t%.2f\n-> STD Value:\t%.2f\n-> Max Value:\t%.2f\n-> Min Value:\t%.2f\n",*values,*(values+1),*(values+2),*(values+3));
	printf("_________________________________________________\n\n");
	
	printf("_________________________________________________\n");
	printf("~~~~~(*read_linkedlist) Function~~~~~\n");				//statistic of the linked list
	printf("-> Byte used:\t%d\n",byte_used2);
	printf("-> Mean Value:\t%.2f\n-> STD Value:\t%.2f\n-> Max Value:\t%.2f\n-> Min Value:\t%.2f\n",*values2,*(values2+1),*(values2+2),*(values2+3));
	printf("_________________________________________________\n\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PART 2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("The Linked List of Differenet Entries.\n");
	source=part2();				//assigns the address of part2 function to source pointer.
	iter2=source;
	while(iter2->next!=NULL){
		printf("n1: %d\tn2:%d\n",iter2->n1,iter2->n2);
		printf("-----------\n");
		iter2=iter2->next;		//we keep the source and make the operations with iter2.
	}
	iter2=source;		//both iter2 and source points the first element of array.

return 0;
}
/////////////////////////////////////////////////////////////////////////
node* read_linkedlist(char *filename,node *root,int *byte){
	node *iter;
	char ch;
	int inp;

	FILE *fp;
	fp=fopen(filename,"r");

	*byte=8;
	iter=root;		//we keep the roots address and make the operaiton by using iter.
					//we can manipulate iter however we want.
	while(!feof(fp)){
		fscanf(fp,"%d%c",&inp,&ch);
		iter->data=inp;
		//printf("data= %d\n",iter->data );
		iter->next=(node*)malloc(sizeof(node));		//create a memory cell in every time 
		iter=iter->next;						
	}
	iter->data=-1;
	iter=root;
	while(iter->next->next->next!=NULL){
		iter=iter->next;
		*byte+=8;	// used byte calculation
	}
	iter->next->data=-1;
	fclose(fp);
return root;	//returns the address of root pointer.
}
/////////////////////////////////////////////////////////////////////////
int* read_array(char *filename,int *arr,int *byte){
	
	char ch;
	int inp;
	int a=2,i=0;

	*byte=0;
	FILE *fp;
	fp=fopen(filename,"r");

	arr=(int*)malloc(sizeof(int));
	while(!feof(fp)){
		fscanf(fp,"%d%c",&inp,&ch);
		arr[i]=inp;								
		arr=(int*)realloc(arr,sizeof(int)*a);	//increasing the capacity of arr.	
		a++;									
		i++;
		*byte+=4;	// used byte calculation 		
	}
	arr[i-1]=-1;	//last element is -1 to know where should stop.
	*byte-=4;
	fclose(fp);
return arr;		//returns the address of arr pointer.
}
/////////////////////////////////////////////////////////////////////////
float* stats_array(int *arr){
	int sum,counter,i=0;
	float *values;
	values=(float*)calloc(4,sizeof(float));
	values[0]=0;
	values[1]=0;
	values[2]=0;
	values[3]=0;

	while(arr[i]!=-1){
		values[0]+=arr[i];
		i++;
	}
	counter=i;
	values[0]=values[0]/i;				//values[0]= mean value;
	for(i=0;i<counter;i++){
		 values[1] += ((arr[i]-values[0])*(arr[i]-values[0]));
	}
	values[1]=sqrt(values[1]/counter);	//values[1]= standard deviation	
	
	values[2]=arr[0];					//values[2]= max value
	for (i = 0; i < counter; i++)		 
        if (arr[i] > values[2]) 
            values[2] = arr[i];

    values[3]=arr[0];					//values[3]= min value
	for (i = 0; i < counter; i++)
        if (arr[i] < values[3]) 
            values[3] = arr[i];
return values;	//returns the address of values array
}
/////////////////////////////////////////////////////////////////////////
float* stats_linkedlist(node *root){
	node *iter;
	iter=root;
	int i;
	float sum=0,counter=0;
	float *values;
	values=(float*)calloc(4,sizeof(float));//this is a memory allocation for 4 statistic.
	*(values)=0;
	*(values+1)=0;
	*(values+2)=0;
	*(values+3)=0;
	while(iter->data!=-1){
		sum+=iter->data;
		iter=iter->next;
		counter++;
	}
	*(values)=sum/counter;					//values[0]= mean value;

	iter=root;
	for(i=0;i<counter;i++){
		 *(values+1) += ((iter->data-*(values))*(iter->data-*(values)));
		 iter=iter->next;
	}
	*(values+1)=sqrt(*(values+1)/counter);		//values[1]= standard deviation

	iter=root;
	*(values+2)=iter->data;					//values[2]= max value
	for (i = 0; i < counter; i++){
		if (iter->data > *(values+2)){
            *(values+2) = iter->data;
		}
		iter=iter->next; 
	}		 

	iter=root;
	*(values+3)=iter->data;
	for (i = 0; i < counter; i++){			//values[3]= min value
		if (iter->data < *(values+3)){
            *(values+3) = iter->data;
		}
		iter=iter->next; 
	}		 
return values;	//returns the address of values array
}
/////////////////////////////////////////////////////////////////////////
_diff* part2(){
	int i=0,j,a=2,number,number2,*temp;
	_diff *head,*iter2;
	node *root,*iter;
	root= (node*)malloc(sizeof(node));
	iter=root;
	int *arr;

	printf("Please enter numbers for dynamic array. Press (-1) to break.\n");
	arr=(int*)malloc(sizeof(int));
	while(number!=-1){
		scanf("%d",&number);
		arr[i]=number;								
		arr=(int*)realloc(arr,sizeof(int)*a);	//increasing the capacity of arr.	
		a++;
		i++;									
	}
	arr[i-1]=-1;

	printf("Please enter numbers for linked list. It will break automatically.\n");
	j=0;
	while(j!=i-1){
		scanf("%d",&number2);
		iter->data=number2;
		iter->next=(node*)malloc(sizeof(node));
		iter=iter->next;	
		j++;					
	}
	iter->data=-1;
	iter=root;

	head= (_diff*)malloc(sizeof(_diff));
	iter2=head;
	for(j=0;j<i-1;j++){
		if(arr[j]!=iter->data){
			iter2->n1=arr[j];
			iter2->n2=iter->data;
			iter2->next=(_diff*)malloc(sizeof(_diff));
			iter2=iter2->next;		
		}
		iter=iter->next;
	}
	iter2->next=NULL;
	iter2=head;
	printf("-----------\n");
return head;	//returns the address of head pointer.
}