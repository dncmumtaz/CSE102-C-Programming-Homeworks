		/*Mumtaz Danaci*/
		/*161044002    */
		/*Homework V   */
#include <stdio.h>/*standart io library*/

#define size1 250 /*lenght of text*/

int read(FILE * first, char character[size1]);/*assign to character array from input text*/
int osman(FILE *last,char character[size1], int numberOfText, int index, int parenthesis,  int control2);/*recursive function*/
int main()/*main function*/
{
	FILE *first, *last;/*File pointer*/
	int parenthesis=0,  control2=0, index=0, numberOfText;/*parenthesis is number of parenthesis*/
	char character[size1];/*character array*/

	first = fopen("input.txt","r");
	last = fopen("output.txt","w");
	numberOfText = read(first, character);
	
	osman(last,character,numberOfText,index, parenthesis, control2);/*recursive function*/
	fclose(first);
	fclose(last);
	return 0;

}

int read(FILE * first, char character[size1]){
	int i =0, control = 0;	
	while(fscanf(first,"%c",&(character[i])) != EOF){	/*assign to array from input text*/
		if(character[i] != ' ')
			control++;
		if(control != 0){
			i++;
		}
	}

	return i;/*i is lenght of array*/
}

int osman(FILE *last, char character[size1], int numberOfText, int index, int parenthesis,  int control2){
	int temp, i;
	if(index == 0 && character[index] == ' ')/*space of beginning*/
		index++;
	if(index != numberOfText){
		
		if(character[index] == '('){/*if there is ( , increase parenthesis */
			parenthesis++;
			index++;
		}

		else if(character[index] == ')'){ /*if there is ) , decrease parenthesis */
			parenthesis--;
			index++;
		}
		else if(character[index] == ',')index++;/*if the character is comma, pass next*/
		else {	
			
				
		
			while(index < numberOfText && character[index] != ',' && character[index] != '(' && character[index] != ')' ){
				temp =index;
				while(index < numberOfText && character[temp] == ' '){	temp++;
					if(character[temp] != ' '){
						if(character[temp] == ',' || character[temp] == '(' || character[temp] == ')'){

							control2=-1;
						}

						else 
							control2 = 1;
					
						break;
					}
				

				}		

				if(control2 == -1){
					index = temp;

				}
				for(i = 0; i< parenthesis && character[index] != ' ' && control2 != -1; i++){
					fprintf(last,"-");		
				}
				
				while(index < numberOfText && character[index] != ',' && character[index] != '(' && character[index] != ')'){
					fprintf(last,"%c",character[index]);
					
					index++;
				}
			
				
				
			
				if( character[index] != ' ' && control2 != -1 ){
					fprintf(last,"\n");
				}

				control2 = 0;
				if(index == numberOfText)
					break;
			}

		}
		
		
		if(index == numberOfText) return 1 ;/*for end of array */
		else
			return osman(last,character,numberOfText,index, parenthesis,  control2);
		
	}
	return 0;


}