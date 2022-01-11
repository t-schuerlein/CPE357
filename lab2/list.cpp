#include <stdio.h>
#include <stdlib.h>


//TODO thoroughly test
//TODO comment out 

void pushString();
void printList();
void deleteItem();

//Use this structure: 
struct listelement 
{ 
listelement *next,*prev = NULL; 
char text[1000]; 
}; 
//and this global list head: 

listelement *head = NULL; 


int main(){

int size = 0;
int input = 0;

while(input != 4){
    printf("1 push string\n2 print list\n3 delete item\n4 end program\n");
    scanf("%d", &input);

    if(input == 1){
        pushString();
    }

    if(input == 2){
        printList();
    }
    if(input == 3){
        deleteItem();
    }
    
}
}



void pushString(){
    listelement* li = (listelement *) malloc(sizeof(listelement));
    
    // get new text and store it in struct
    printf("insert text:\n");
    scanf("%s", li->text);

    if(head == NULL){
        head = li;
    }
    else{
        // go through list until we reach end and then attach node
        listelement *oldLast = head;
        while(oldLast->next != NULL){
            oldLast = oldLast -> next;
        }
        listelement *newLast = li;
        oldLast->next = newLast;
        newLast ->prev = oldLast;    
    }

    
    

    

}

void printList(){
    listelement *iter = head;
    while(iter != NULL){
        printf("%s\n", iter->text);
        iter = iter->next;
    }
    return;
}

void deleteItem(){
    int position = 0;
    printf("starting from 1, where is the spot of the element we want to remove???\n");
    scanf("%d", &position);
    if(position < 1 ){
        printf("spot cannot be less than 1\n");
        return;
    }
    int spot = position;
    listelement* iter = head;

    while(--position > 0){
        if(iter -> next != NULL){
            iter = iter->next;
        } else {
            printf("You chose too big of a number!!!\n");
            return;
        }
        

    }
    printf("the text: %s is in the %d position\n", iter->text, spot);
    
    listelement* kill = iter;
    listelement* before = kill->prev;
    listelement* after = kill->next;
    if(before == NULL){
        head = after;
        after-> prev = NULL;
    } else if(after == NULL){
        before -> next = NULL;
    } else{
        before -> next = after;
        after -> prev = before;
    }

    free(kill);

    return;
}

int size(){

}