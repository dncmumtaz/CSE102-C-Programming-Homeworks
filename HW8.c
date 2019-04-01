/*HOMEWORK VIII*/
/*161044002*/
/*MUMTAZ DANACI*/
#include <stdio.h>/*libraries*/
#include <stdlib.h>
#include <sys/resource.h>

#define sizeOfMatrisX 512
#define sizeOfMatrisY 512
#define sizeOfMaximumWaterLevel 120
/*findToisland and findToisland is recursion funtion */
/*findToisland, for write to number of island*/
/*findToislandd , for write to coordinate of island*/
int findToisland( char matris[sizeOfMatrisX][sizeOfMatrisY], int numberOfisland, int indexX, int indexY, int levelOfWater, int control) ;
int readInput(char matris[sizeOfMatrisX][sizeOfMatrisY]);/*for read from input.txt*/
int findToislandd(char matris[sizeOfMatrisX][sizeOfMatrisY], int numberOfisland, int indexX, int indexY, int levelOfWater, int control) ;

FILE *INPUT,*output;
int main(){



    const rlim_t kStackSize = 16 * 1024 * 1024; // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0){
        if (rl.rlim_cur < kStackSize){
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
        if (result != 0){
        fprintf(stderr, "setrlimit returned result = %d\n", result);
        }
        }
    }    
   
    int numberOfisland =0;
    int levelOfWater = 0, indexX = 0, indexY = 0, control=0;
    char matris[sizeOfMatrisX][sizeOfMatrisY];
  
  
    INPUT = fopen("input.txt","r");
    output = fopen("output.txt","a");


    levelOfWater = readInput( matris);

    findToisland( matris, numberOfisland, indexX, indexY, levelOfWater, control);
    findToislandd(matris, numberOfisland, indexX, indexY, levelOfWater, control);
  

 
    fclose(INPUT);
   
 fclose(output);
}


int findToisland( char matris[sizeOfMatrisX][sizeOfMatrisY], int numberOfisland, int indexX, int indexY, int levelOfWater, int control){/* */
   
	if(indexX == sizeOfMatrisX-1  && indexY == sizeOfMatrisY -1 && control == 0 ){/*only this correct*/
       fprintf(output,"%d\n", numberOfisland);   
        control ++;
        return numberOfisland;
    }

  
    if( matris[indexX][indexY] == 'T' ){


        if(matris[indexX][indexY+1] == 'F' && 
           matris[indexX+1][indexY] == 'F' ){
         
              
            (numberOfisland)++;
        //    printf("%d,%d\n",indexX, indexY );

        
        }

         if(indexY == sizeOfMatrisY){
            indexY = 0;
            indexX++;
        }

        if(indexX < sizeOfMatrisX && indexY < sizeOfMatrisY){
       
             indexY +=1;
            findToisland(matris, numberOfisland, indexX, indexY, levelOfWater, control);
        }       
        
    }
    else{   
      
        if(indexY == sizeOfMatrisY){
            indexY = 0;
            indexX++;
        }
       
        if(indexX < sizeOfMatrisX  )
            return findToisland( matris, numberOfisland, indexX, indexY +=1, levelOfWater, control);
    }

   

}  


int readInput(char matris[sizeOfMatrisX][sizeOfMatrisY]){/*to  read from  input.txt*/

    int i,j, levelOfWater;


    fscanf(INPUT,"%d", &levelOfWater);
    int temp;

    for(i = 0; i< sizeOfMatrisX; ++i){
        for (j = 0; j < sizeOfMatrisY ; ++j){
            fscanf(INPUT, "%d", &temp);
           
       
            if(temp > levelOfWater){/*if it is bigger than water of level, assign "T" to character array . Else assign "F" to array*/
                matris[i][j] = 'T'  ; 
            }

            else
                matris[i][j] = 'F';   
                
        }

    }



    return levelOfWater;/*first line in input.txt*/

}
int findToislandd(char matris[sizeOfMatrisX][sizeOfMatrisY], int numberOfisland, int indexX, int indexY, int levelOfWater, int control){

       if(indexX == sizeOfMatrisX-1  && indexY == sizeOfMatrisY -1 && control == 0 ){/*only this correct*/
        
        control ++;
        return numberOfisland;
    }

  
    if( matris[indexX][indexY] == 'T' ){


        if(matris[indexX][indexY+1] == 'F' && 
            matris[indexX+1][indexY] == 'F' ){
            fprintf(output, "%d %d\n",indexX, indexY );  
              
            (numberOfisland)++;
    

        
        }

         if(indexY == sizeOfMatrisY){
            indexY = 0;
            indexX++;
        }

        if(indexX < sizeOfMatrisX && indexY < sizeOfMatrisY){

             indexY +=1;
            findToislandd( matris, numberOfisland, indexX, indexY, levelOfWater, control);
        }       
        
    }
    else{   
      
        if(indexY == sizeOfMatrisY){
            indexY = 0;
            indexX++;
        }
       
        if(indexX < sizeOfMatrisX  )
            return findToislandd(matris, numberOfisland, indexX, indexY +=1, levelOfWater, control);
    }


}