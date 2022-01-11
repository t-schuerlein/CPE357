#include <stdio.h>
#include <stdlib.h>

void drawLeafs(int levels);
void drawTrunk(int trunkLoc);
void fileTree(FILE *dest, int length);
void fileTrunk(FILE *dest, int length);

int main(int argc, char *argv[]){

    // stores the number of leafs on tree
    int numLeafs = 0;
    // 1 indicates file argument was passed 
    int gotFile = 0;
    //TODO should we overwrite file or add to it?
    FILE *file;

    int gotNum = 0;
    
    
    // go through each argument, see if it's a file name or tree height
    int index;
    for(index = 1; index < argc; index ++){
        
        if(gotNum == 0){
        // check if argument is a number
        numLeafs = atoi(argv[index]);
        // printf("numLeafs after atoi is now %d\n", numLeafs);
        if(numLeafs != 0){
 gotNum = 1;
        }
       
        }
        // print statement that helps with debugging
        // printf("argument given %d\n", numLeafs);

        // if the argument is number ensure it fits constraints (between 1-10)
        if(argv[index] == "0" || (gotNum == 1  && atoi(argv[index]) != 0) ){
            // if bad number given, prompt for better input
            // while (numLeafs < 1 || numLeafs > 10){
            // // prompt user for number between 1 - 10
            // printf("Error, the number given needs to be between 1 and 10\n");
            // // scan in number from terminal input
            // scanf("%d", &numLeafs);
            // }
            // printf("we were given a number\n");
            
        }
        // else the argument is a file name, open the file
        else{
            // open up given file name
            file = fopen(argv[index], "w+");
            //acknowledge we received a file
            gotFile = 1;
        }
    }

    // debugging tool
    // printf("after checking the arguments %d\n", numLeafs);


    // if number was never given in arguments, prompt for one
    while (numLeafs == 0){
            // prompt user for number between 1 - 10
            printf("how many leaves does the tree have? choose number between 1 and 10\n");
            // read in number value from terminal input
            scanf("%d", &numLeafs);
    }

    //setting the max leafs to be 10 lines
    if(numLeafs > 10){
        numLeafs = 10;
    }

    // if we didn't receive file, print out tree in terminal
    if(gotFile == 0){

        // debugging tool
        // printf("not given a file %d \n", numLeafs);

        // since we don't have file to write to, print out tree in terminal
        drawLeafs(numLeafs);
        // the trunk location is x2 the number of leafs (arbitrary loc defined in drawLeafs)
        int trunkLoc = numLeafs * 2;
        // printing out trunk in terminal
        drawTrunk(trunkLoc);
    }
    // else we have a file name to write to
    else{
        //debugging tool
        // printf("given a file\n");

        // writing tree on given file
        fileTree(file, numLeafs);
        // the trunk location is x2 the number of leafs (arbitrary loc defined in drawLeafs)
        int trunkLoc = numLeafs * 2;
        // writing tree on given file
        fileTrunk(file, trunkLoc);
        fclose(file);

    }

    // debugging helper
    // printf("we are done\n");

}

// method will draw the leaves and return the location of where to put the trunk
void drawLeafs(int layers){
   
    // the first layer will have 1 star, then +2 for each layer
    int numStars = 1;
    // need to know where to place '*' to get tree shape
    int leafLoc = (layers) * 2;
    // write for loop to iterate through each layer
    int i;
    for(i = 0; i < layers; i++){
        // use variable to place spaces until we reach first leaf spot
        int temp = leafLoc;
        while(temp > 0){
            putchar(' ');
            temp --;    
        }
        // next round leaf needs to start one spot sooner to accomodate the extra leaf
        leafLoc --;
        // place down desired number of stars
        temp = numStars;
        while(temp > 0){
            putchar('*');
            temp --;
        }
        // next round will have +2 stars
        numStars += 2;
        // reset location on next line
        putchar('\n');

    }

}

void drawTrunk(int trunkLoc){
    
    int trunkLen = 3;
    while(trunkLen > 0){
        int temp = trunkLoc;
        while (temp > 0){
            putchar(' ');
            temp --;
        }
        printf("*\n");
        trunkLen --;
    }


}

void fileTree(FILE *dest, int layers){
    // fprintf(dest, "something");
  
    // the first layer will have 1 star, then +2 for each layer
    int numStars = 1;
    // need to know where to place '*' to get tree shape
    int leafLoc = (layers) * 2;
    // write for loop to iterate through each layer
    int i;
    for(i = 0; i < layers; i++){
        // use variable to place spaces until we reach first leaf spot
        int temp = leafLoc;
        while(temp > 0){
            fprintf(dest, " ");
            temp --;    
        }
        // next round leaf needs to start one spot sooner to accomodate the extra leaf
        leafLoc --;
        // place down desired number of stars
        temp = numStars;
        while(temp > 0){
            fprintf(dest, "*");
            temp --;
        }
        // next round will have +2 stars
        numStars += 2;

        fprintf(dest, "\n");

    }

}

void fileTrunk(FILE *dest, int layers){
        int trunkLen = 3;
    while(trunkLen > 0){
        int temp = layers;
        while (temp > 0){
            fprintf(dest, " ");
            temp --;
        }
        fprintf(dest, "*\n");
        trunkLen --;
    }


}