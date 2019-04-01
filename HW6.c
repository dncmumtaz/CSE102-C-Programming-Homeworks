/*t161044002*/
/*MUMTAZ DANACI*/
/*homework VI*/ 

#include <stdio.h>/*the libraries*/
#include <stdlib.h>
#include <string.h>



void start(char str[100]);/*for begining*/
double recurFunc(char arr[100], char *previous, char str[100], double number, int begining);/*recursive function*/


int main()/*main function*/
{
	char arr[100], str[100], *previous;
	double result,  number;
	int begining =0;

	start(str);	
	result = recurFunc(arr, previous, str, number, begining);
	printf("%lf\n",result );
	return 0;
}
void start(char str[100]){
	
	printf("Name the object:\n");
	
	scanf("%s",str);
	printf("Define %s?\n", str);

	

}
double recurFunc(char arr[100], char *previous, char str[100], double number,int begining){/*recursive function*/
	
	int i=0, j, countarray, index=0, control =0, control2=0;
	
	char  nameOfobject[100];
	double price=1, sum=0;	
	arr = malloc(100);

	getchar();	
	scanf("%[^\n]s",arr);
	countarray = strlen(arr);
	arr[countarray] = ' ';	
	
	while(arr[i] == ' ')i++;/*for skip to extra space */

	while(arr[i] != '\0' ){			
			
		if(arr[i] == ' '){/*for find the space*/
			control++;
			while(arr[i+1] == ' ')i++;/*for skip to extra space */
			if(control %2 == 0 ){				
		
				sscanf(&arr[index], "%lf %s",&number, nameOfobject);
		
				if(begining == 0){
					printf("Define %s in %s\n",nameOfobject,str );
					begining++;
				}
				
				else		
					printf("Define %s in %s\n",nameOfobject,previous );
				index =i;
				previous = nameOfobject;
				sum += recurFunc(arr, previous, str, number,begining);
				
			}	
		}	
	i++;
	}
	
	for(j=0;j<strlen(arr);j++){/*if user enter a price*/
			
		if(arr[j] < 48 && arr[j] != 32 || arr[j] > 57 && arr[j] != 32) 
			control2++;
	}

	if(control2 == 0){

		sscanf(&arr[index], "%lf",&price);
		sum = number*price;
	}		
	
	return sum;

}
