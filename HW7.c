/*HOMEWORK VII*/
/*161044002*/
/*MUMTAZ DANACI*/


#include <stdio.h>/*the libraries*/
#include <stdlib.h>
#include <string.h>

#define sizeofprocessname 30
#define nameOfinput1 30
#define nameOfinput2 30
#define nameOfresult 30
#define sizeofinputarr 30/*the pre-def */
#define sizeofcircuitarray 230
#define sizeofoutput 230

typedef struct node{/*the content of structure*/

    char nameOfprocess[sizeofprocessname];
    char input1[nameOfinput1], input2[nameOfinput2], result[nameOfresult];
    struct node *parent, * right, *left;

}node;


void perform(FILE *circuit, node *tree ,char arrayOfcircuit[sizeofcircuitarray]);
int and(int input1, int input2);
int or(int input1, int input2);
int not(int input);
int flipflop(int input);
int readInput(FILE * INPUT,char inputArray[sizeofinputarr], char outputArray[sizeofoutput]);
void writeOutput(FILE * OUTPUT, char outputArray[sizeofoutput], int a);

struct node *newNode(char tempOperation[sizeofprocessname], char tempResult[sizeofprocessname], char tempInput1[nameOfinput1], char tempInput2[nameOfinput2])
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    strcpy(temp -> nameOfprocess ,tempOperation);
    strcpy(temp -> result , tempResult);
    strcpy(temp -> input1 , tempInput1);
    strcpy(temp -> input2 , tempInput2);

    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, char tempOperation[sizeofprocessname], char tempResult[sizeofprocessname], char tempInput1[nameOfinput1], char tempInput2[nameOfinput2])/*insert function*/
{
    /* If the tree is empty, return a new node */
    if (node == NULL) {
        printf("node null\n");
        return newNode(tempOperation,
                       tempResult,
                       tempInput1,
                       tempInput2);
    }


    /* Otherwise, recur down the tree */
    if (strcmp(node->result, tempInput1) == 0) {
        printf("input1 ->  %s\n", tempResult);
        (node)->left  = insert((node)->left, tempOperation,
                                tempResult,
                                tempInput1,
                                tempInput2);
    }
    else if (strcmp(tempResult, tempInput2) == 0){
        printf("input2 ->  %s\n", tempResult);
        (node)->right  = insert((node)->right, tempOperation,
                                 tempResult,
                                 tempInput1,
                                 tempInput2);
    }

    /* return the (unchanged) node pointer */
    return node;
}




void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        inorder(root->right);
    }
}

int main (){
    FILE * circuit;
	FILE * INPUT;
	FILE * OUTPUT;

	char inputArray[sizeofinputarr], arrayOfcircuit[sizeofcircuitarray], outputArray[sizeofoutput];
    struct node *tree = (struct node *)malloc(sizeof(struct node));
   	
    circuit = fopen("circuit.txt","r");
   	INPUT = fopen("input.txt","r");
   	OUTPUT = fopen("output.txt","w");
    perform(circuit, tree, arrayOfcircuit);
    inorder(tree);
	int a;	
	a= readInput(INPUT, inputArray, outputArray);
	writeOutput(OUTPUT, outputArray, a);
	
	fclose(OUTPUT);
    fclose(circuit);
	fclose(INPUT);

	

	return 0;

}





void writeOutput(FILE * OUTPUT, char outputArray[sizeofoutput], int a){
	int i;
	for(i= 0 ; i < a; i++){
		if(i ==0)
			fprintf(OUTPUT,"%c\n",outputArray[2]);
		else
			fprintf(OUTPUT,"%c\n",outputArray[i]);
				
	}	
}


void perform(FILE *circuit, node * tree ,  char arrayOfcircuit[sizeofcircuitarray]){
    char tempOperation[sizeofprocessname];
    char tempResult[nameOfresult], tempInput1[nameOfinput1], tempInput2[nameOfinput2];
    fgets(arrayOfcircuit,sizeofcircuitarray,circuit);
    arrayOfcircuit[strcspn(arrayOfcircuit, "\n")] = 0;
    
    while(fgets(arrayOfcircuit,sizeofcircuitarray,circuit) != NULL ){

       	int i =0, control =0;
       	while(arrayOfcircuit[i] != '\n'){
       		i++;
       		if(arrayOfcircuit[i] == ' ')
       			control++;
       		
       	}
       	if(control == 3){
        	sscanf(arrayOfcircuit,"%s %s %s %s", tempOperation, tempResult, tempInput1, tempInput2);
      		insert(tree, tempOperation, tempResult, tempInput1, tempInput2);
      	} 
       	if(control == 2){
       		sscanf(arrayOfcircuit,"%s %s %s", tempOperation, tempResult, tempInput1);
        	strcpy(tempInput2,"*");
        	insert(tree, tempOperation, tempResult, tempInput1, tempInput2);
		}
    }

}

int and(int input1, int input2){
    return input1 && input2;
}
int or(int input1, int input2){
    return input1 || input2;
}
int not(int input){
    if(input == 0)
        return 1;
    else
        return 0;
}
int flipflop(int input){
	

}

int readInput(FILE * INPUT,char inputArray[sizeofinputarr],char outputArray[sizeofoutput]){
	int control=0;
	while(fgets(inputArray,sizeofinputarr,INPUT) != NULL ){
		control++;
		inputArray[strcspn(inputArray, "\n")] = 0;
		strcpy( outputArray, inputArray);		
	}
	
	inputArray[control+1] = 0;
	return control;

}



















	
