#include <stdio.h>
#include <stdbool.h>

void printGuide();
int printMenu(); 

int main(){
  bool gameOn = false;
  int action = printMenu(); 

  if(action == 1){

  }else if(action == 2){
    printGuide();
  }else {
    printf("*** GOODBYE ***");
  }

  return 0;

}

int printMenu(){
  int action = 0;
  scanf("1. Start\n2. Guide\n3.Exit\nPlease select an action: %d\n", &action);
  return action; 
}

void printGuide(){

}

