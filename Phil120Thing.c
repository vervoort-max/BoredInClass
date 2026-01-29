#include <stdio.h>
#include <stdbool.h>

void printGuide();
int printMenu();

int main(){
  bool gameOn = false;
  int action = printMenu(); 
  

  /*if(action == 1){

  }else if(action == 2){
    printGuide();

  }else {
    printf("*** GOODBYE ***");
  }*/

  return 0;

}

void printGuide(){

}

int printMenu(){
  int action = 0;
  printf("*** Welcome ***\nTo The Truth Game\n--------------------\n");
  printf("1. Start\n2. Guide\n3. Exit\nPlease select an action: ");
  scanf("%d", &action);
  return action;
}
