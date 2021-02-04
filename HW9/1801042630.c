#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
	
	int cntA=0; //global variable for part1
	int cntS=0; //global variable for part1
	int counter;//global variable for part2
	
	//for part 2 there was 2 algorithms i could find. one of them is searching all locations, and the other one is calling
	//function again by increasing 1 the address of location array. For 2 combined i searched all locations 1-by-1;
	//for 3 and 4 combined locations i did the other way. but the thing is it doesnt look for all of the locations.
	//it looks for (as index) first 0-1-2 then 1-2-3, then 2-3-4 until it finds. Also the given output in the pdf can be obtained by this way.
	//thank you.

	struct Hospital{
		char *name;
		char citiesServed[3];
	};
	struct card{
		 const char *face;
		 const char *suit;
	}; 
int menu();
int fact(int A);
void part3(struct card deck[]);
int numPathsHome(int street, int avenue);
int canOfferCovidCoverage(char _cities[], char _locations[][3], int _numHospitals, struct Hospital results[]);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	printf("deneme\n");
	int i,j;
	char _cities[6]=			{'A','B','C','D','E','F'};
	char _locations[4][3]=	 {{'A', 'B', 'C'},{'A', 'C', 'D'},{'B', 'F'},{'C', 'E', 'F'}};
	int _numHospitals;
	struct Hospital results[4];
	struct card deck[53];
	int street,avenue;

	srand(time(NULL));
	while(1){
		printf("\n");
		int choice=menu();
		//---------------------------------------------------------------------------------------
		if(choice==1){
			cntS=0;
			cntA=0;
			do{
				printf("please enter a street and avenue(should be larger than 0)\n");
				scanf("%d%d",&street,&avenue);
				if (street<1 || avenue<1){
					printf("INVALID CHOICE.TRY AGAIN!\n");
				}
			}while(street<1 || avenue<1);
			printf("Total number of ways:%d \n",numPathsHome(street,avenue));
		}
		//---------------------------------------------------------------------------------------
		else if(choice==2){
			do{
				printf("Enter the maximum number of hospitals that can be constructed: ");
				scanf("%d",&_numHospitals);
				if(_numHospitals<1 || _numHospitals>4){
					printf("INVALID CHOICE.TRY AGAIN!\n");
				}
			}while(_numHospitals<1 || _numHospitals>4);
			counter=0;
			
			if(canOfferCovidCoverage( _cities, _locations, _numHospitals,results)==0){		//function return 0 if all cities can not be contained
				printf("No,some cities are not covered.\n");
			}
			else if(canOfferCovidCoverage( _cities, _locations, _numHospitals,results)==1){	//function return 1 if all cities can be contained
				for(i=0;i<_numHospitals;i++){
					printf("%s\n",results[i].name);					//prints the name of hospital
					printf("Hospital locations: ");
					for(j=0; j<3; j++){								//prints the cities served.
						printf("%c",results[i].citiesServed[j]);
					}
					printf("\n");

				}
			}
			
		}
		//---------------------------------------------------------------------------------------
		else if(choice==3){
			printf("YOU ARE IN PART3\n");
			part3(deck);
		}
		//---------------------------------------------------------------------------------------
		else if(choice==4){
			printf("You Are Leaving...\n");
			break;
		}
		//---------------------------------------------------------------------------------------
		else{
			printf("INVALID CHOICE. TRY AGAIN.\n");
		}
	}
return 0; 
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu(){
	int choice;
	do{
		printf("PLEASE SELECT WHICH PART YOU WANT TO EXECUTE\n");
		printf("1) PART 1\n");
		printf("2) PART 2\n");
		printf("3) PART 3\n");
		printf("4) EXIT\n");
		scanf("%d",&choice);
	}while(choice>4 || choice<1);
return choice;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int fact(int number){
  int i,fact= 1;
  for (i=1;i<=number;i++){				//this function calculates factorial of sent number.
  	 fact=fact*i;
  }
 return fact;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void part3(struct card deck[]){
	int  random,i,j,c=0;
	char choose;
	char suit[4][20]={"Hearts","Diamonds","Clubs","Spades"};
	char face[13][20]={"Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
	struct card temp;
	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
			deck[c].suit=suit[i];
			c++;									//this code segment assigns suits value in this order: 
		}											//13-hearts
	}												//13-diamonds
	c=0;											//13-clubs	
	for(i=0;i<4;i++){								//13-spades
		for(j=0;j<13;j++){							//then all the face values assign each suit
			deck[c].face=face[j];
			c++;
		}
	}
	printf("p) PRESS 'p' TO SEE THE ORIJINAL ALIGNMENT OF THE DECK.\n");	// menu of part 3
	printf("s) PRESS 's' TO SEE THE SHUFFLED ALIGNMENT OF THE DECK \n");	//p->previous s->shuffle q->quit
	printf("q) PRESS 'q' TO GO BACK TO THE MAIN MENU \n");
	scanf(" %c",&choose);
	while(choose!='q'||choose!='Q'){
		if(choose=='p'||choose=='P'){
			for(i=0;i<51;i=i+2){
				printf("%7s of %s \t %5s of %-7s\n",deck[i].face,deck[i].suit,deck[i+1].face,deck[i+1].suit);
			}
		}
		else if(choose=='s'||choose=='S'){
			for(i=0;i<52;i++){
				random=rand()%52;
				temp=deck[i];					//by using "structure card temp" we can shuffle the cards randomly  
				deck[i]=deck[random];
				deck[random]=temp;
			}
			for(i=0;i<51;i=i+2){
				printf("%7s of %s \t %5s of %-7s\n",deck[i].face,deck[i].suit,deck[i+1].face,deck[i+1].suit);
			}	
		}
		else if(choose=='q'||choose=='Q'){
			break;
		}
		else{
			printf("INVALID VALUE! TRY AGAIN.\n");
		}
		printf("p) PRESS 'p' TO SEE THE PREVIOUS ALIGNMENT OF THE DECK.\n");
		printf("s) PRESS 's' TO SEE THE SHUFFLED ALIGNMENT OF THE DECK \n");
		printf("q) PRESS 'q' TO GO BACK TO THE MAIN MENU \n");
		scanf(" %c",&choose); 
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int numPathsHome(int street, int avenue){
    if(avenue==1 && street==1){
    	return fact(cntS+cntA)/(fact(cntS)*fact(cntA));		//The combimnation formula's result will be returned.
    }
    else if(street!=1){		
    	cntS++;									//Global Variable for counter				
    	numPathsHome(street-1, avenue);			//This statement counts the streets until it is 1(Cİn Ali's Home)
    }
    else if(avenue!=1){
    	cntA++;									//Global Variable for counter
    	numPathsHome(street, avenue-1);			//This statement counts the avenues until it is 1(Cİn Ali's Home)
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int canOfferCovidCoverage(char _cities[], char _locations[][3], int _numHospitals, struct Hospital results[]){
	int i,j,k,m=0;
	int flag=0;
	char temp[6];
	char temp2[9];
	char temp3[12];
	//----------------------------------------------------------------------------------//
	if(_numHospitals==1){
		return 0;				// 1 index of locations includes maximum 3 cities. So there is no need to search cities.
	}
	//----------------------------------------------------------------------------------//
	else if(_numHospitals==2){	//this statement searh all 2-combined locations 1-by-1,to find all cities. 
		if(counter==0){
			for(i=0;i<6;i++){										//in this code segment; first, cities compared with the cities in locations
				for(j=0;j<2;j++){									//then if they match, matched values are assigned to temp array.
					for(k=0;k<3;k++){								//After then all city names are searched in temp array. if even 1 of them doesnt 
						if(_cities[i]==_locations[j][k]){			//match with temp arrays cities, then flag becomes 0 and by increasing counter it calls the
							temp[m]=_cities[i];						//function again. if counter is increased next statement will be searched.	
							m++;
						}
					}												//FOR ALL 2 COMBINED LOCATIONS THE ALGORITHM WORKS EXACTLY SAME, SO PLEASE CONSIDER THAT
				}													//THE COMMENTS WILL BE THE SAME WITH THE ABOVE EXPLANATION.
			}															
			for(i=0;i<6;i++){											
				flag=0;
				for(j=0;j<6;j++){
					if(_cities[i]==temp[j]){
						flag=1;
						break;											
					}													
				}
				if(flag==0){
					counter++;
					return canOfferCovidCoverage( _cities, _locations, _numHospitals,results);
				}
			}
		}
		m=0;
		//----------------------------------------------------------------------------
		if(counter==1){
			for(i=0;i<6;i++){
				for(j=0;j<3;j=j+2){
					for(k=0;k<3;k++){
						if(_cities[i]==_locations[j][k]){
							if(_cities[i]==_locations[j][k]){			//if(counter==0) this part of the statement will be executed.
								temp[m]=_cities[i];						//this part search LOCATION 0-2
								m++;
							}			
						}
					}
				}
			}
			for(i=0;i<6;i++){
				flag=0;
				for(j=0;j<6;j++){
					if(_cities[i]==temp[j]){
						flag=1;
						break;
					}	
				}
				if(flag==0){
					counter++;
					return canOfferCovidCoverage( _cities, _locations, _numHospitals,results);
				}
			}
		}
		m=0;
		//----------------------------------------------------------------------------
		if(counter==2){
			for(i=0;i<6;i++){
				for(j=0;j<4;j=j+3){
					for(k=0;k<3;k++){
						if(_cities[i]==_locations[j][k]){			//if(counter==0) this part of the statement will be executed.
							temp[m]=_cities[i];						//this part search LOCATION 0-3
							m++;
						}	
					}
				}
			}
			for(i=0;i<6;i++){
				flag=0;
				for(j=0;j<6;j++){
					if(_cities[i]==temp[j]){
						flag=1;
						break;
					}	
				}
				if(flag==0){
					counter++;
					return canOfferCovidCoverage( _cities, _locations, _numHospitals,results);
				}
			}
		}
		m=0;
		//----------------------------------------------------------------------------
		if(counter==3){	
			for(i=0;i<6;i++){
				for(j=1;j<3;j++){
					for(k=0;k<3;k++){		
						if(_cities[i]==_locations[j][k]){			//if(counter==0) this part of the statement will be executed.
							temp[m]=_cities[i];						//this part search LOCATION 1-2
							m++;
						}	
					}
				}
			}
			for(i=0;i<6;i++){
				flag=0;
				for(j=0;j<6;j++){
					if(_cities[i]==temp[j]){
						flag=1;
						break;
					}	
				}
				if(flag==0){
					counter++;
					return canOfferCovidCoverage( _cities, _locations, _numHospitals,results);
				}
			}
		}
		m=0;
		//----------------------------------------------------------------------------
		if(counter==4){
			for(i=0;i<6;i++){
				for(j=1;j<4;j=j+2){
					for(k=0;k<3;k++){
						if(_cities[i]==_locations[j][k]){				//if(counter==0) this part of the statement will be executed.
							temp[m]=_cities[i];							//this part search LOCATION 1-3
							m++;
						}	
					}
				}
			}
			for(i=0;i<6;i++){
				flag=0;
				for(j=0;j<6;j++){
					if(_cities[i]==temp[j]){
						flag=1;
						break;
					}	
				}
				if(flag==0){
					counter++;
					return canOfferCovidCoverage( _cities, _locations, _numHospitals,results);
				}
			}
		}
		m=0;
		//----------------------------------------------------------------------------
		if(counter==5){
			for(i=0;i<6;i++){
				for(j=2;j<4;j++){
					for(k=0;k<3;k++){									//if(counter==0) this part of the statement will be executed.
						if(_cities[i]==_locations[j][k]){				//this part search LOCATION 2-3
							temp[m]=_cities[i];		
							m++;													
						}
					}
				}
			}
			for(i=0;i<6;i++){
				flag=0;
				for(j=0;j<6;j++){
					if(_cities[i]==temp[j]){
						flag=1;
						break;
					}	
				}
				if(flag==0){
					counter++;
					return canOfferCovidCoverage( _cities, _locations, _numHospitals,results);
				}
			}
		}
		m=0;
		if(flag==0){					//if all the possibilities are searched then function returns 0
			return 0;
		}
	}	
	//----------------------------------------------------------------------------------//
	else if(_numHospitals==3){	//this statement searh all 3-combined locations 1-by-1,to find all cities.
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		m=0;
		if(counter==0){
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					temp2[m]=_locations[i][j];				//in this code segment all location values are assigned to temp array.
					m++;									//then all cities are searched in temp array if even 1 of them doesnt match 
				}											//function searches other location,eventually return 0.
			}
			for(i=0;i<6;i++){
				flag=0;													//0-1-2 index locations
				for(j=0;j<9;j++){		
					if(_cities[i]==temp2[j]){								
						flag=1;
						break;
					}	
				}
				if(flag==0){
					counter++;
					return canOfferCovidCoverage( _cities, _locations, _numHospitals,results);
				}
			}
			if(flag==1){
				results[0].name="Şehir Hastanesi - 1";		
				strncpy(results[0].citiesServed,temp2,3);
				results[1].name="Şehir Hastanesi - 2";
				strncpy(results[1].citiesServed,temp2+3,3);
				results[2].name="Şehir Hastanesi - 3";
				strncpy(results[2].citiesServed,temp2+6,3);
				return 1;
			}
		}
			//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
		else if(counter==1){
			m=0;
			for(i=0;i<3;i++){
				if(i==2){
					i=3;
				}
				for(j=0;j<3;j++){
					temp2[m]=_locations[i][j];
					m++;											//index 0-1-3 locations
				}		
			}
			for(i=0;i<6;i++){
				flag=0;
				for(j=0;j<9;j++){
					if(_cities[i]==temp2[j]){
						flag=1;
						break;
					}	
				}
				if(flag==0){
					counter++;
					return canOfferCovidCoverage( _cities, _locations, _numHospitals,results);
				}
			}
			if(flag==1){
				results[0].name="Şehir Hastanesi - 1";		
				strncpy(results[0].citiesServed,temp2,3);
				results[1].name="Şehir Hastanesi - 2";
				strncpy(results[1].citiesServed,temp2+3,3);
				results[2].name="Şehir Hastanesi - 3";
				strncpy(results[2].citiesServed,temp2+6,3);
				return 1;
			}
		}
			//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		else if(counter==2){
			m=0;
			for(i=0;i<4;i++){
				if(i==1){
					i=2;
				}
				for(j=0;j<3;j++){
					temp2[m]=_locations[i][j];						//index 0-2-3 locations	
					m++;	
				}		
			}
			for(i=0;i<6;i++){
				flag=0;
				for(j=0;j<9;j++){
					if(_cities[i]==temp2[j]){
						flag=1;
						break;
					}	
				}
				if(flag==0){
					counter++;
					return canOfferCovidCoverage( _cities, _locations, _numHospitals,results);
				}
			}
			if(flag==1){
				results[0].name="Şehir Hastanesi - 1";		
				strncpy(results[0].citiesServed,temp2,3);
				results[1].name="Şehir Hastanesi - 2";
				strncpy(results[1].citiesServed,temp2+3,3);
				results[2].name="Şehir Hastanesi - 3";
				strncpy(results[2].citiesServed,temp2+6,3);
				return 1;
			}
		}
			//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
		else if(counter==3){
			m=0;
			for(i=1;i<4;i++){
				for(j=0;j<3;j++){
					temp2[m]=_locations[i][j];
					m++;	
				}		
			}
			for(i=0;i<6;i++){								//index 1-2-3 locations
				flag=0;
				for(j=0;j<9;j++){
					if(_cities[i]==temp2[j]){
						flag=1;
						break;
					}	
				}
				if(flag==0){
					counter++;
					return canOfferCovidCoverage( _cities, _locations, _numHospitals,results);
				}
			}
			if(flag==1){
				results[0].name="Şehir Hastanesi - 1";		
				strncpy(results[0].citiesServed,temp2,3);
				results[1].name="Şehir Hastanesi - 2";
				strncpy(results[1].citiesServed,temp2+3,3);
				results[2].name="Şehir Hastanesi - 3";
				strncpy(results[2].citiesServed,temp2+6,3);
				return 1;
			}
		}
		if(flag==0){
			return 0;
		}
	}
	//----------------------------------------------------------------------------------//
	else if(_numHospitals==4){
		m=0;
		if(counter==0){
			for(i=0;i<4;i++){
				for(j=0;j<3;j++){
					temp3[m]=_locations[i][j];			//same algorithm wih 3 combined locations
					m++;	
				}		
			}
			for(i=0;i<6;i++){							//1-2-3-4
				flag=0;													
				for(j=0;j<12;j++){		
					if(_cities[i]==temp3[j]){								
						flag=1;
						break;
					}	
				}
				if(flag==0){
					counter++;
					return canOfferCovidCoverage( _cities, _locations, _numHospitals,results);
				}
			}
			if(flag==1){
				results[0].name="Şehir Hastanesi - 1";
				strncpy(results[0].citiesServed,temp3,3);
				results[1].name="Şehir Hastanesi - 2";
				strncpy(results[1].citiesServed,temp3+3,3);
				results[2].name="Şehir Hastanesi - 3";
				strncpy(results[2].citiesServed,temp3+6,3);
				results[3].name="Şehir Hastanesi - 4";
				strncpy(results[3].citiesServed,temp3+9,3);
				return 1;
			}
		}
		else if(counter!=0){
			return 0;
		}
	}
	//----------------------------------------------------------------------------------//
return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
