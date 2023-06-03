//Sidhardh Burre, ssb3vk@virginia.edu, 4/15/2021, linkedlist.c
//Stupidest lab I have ever done. 

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define PUSH_FRONT 	0
#define PUSH_BACK 	1
#define POP_FRONT 	2
#define POP_BACK 	3
#define PRINT_LIST 	4
#define HELP 		5
#define QUIT 		6
#define INVALID 	7

#define BUFFER_SIZE 20

void printOptions();
int readInput(int* val);
int isNumber(const char* token);
int isEmpty(const char* input);

typedef struct list_item {// list node
  struct list_item* prev;
  struct list_item* next;
  int value;

}list_item_t; 

typedef struct list {// the list itself
  list_item_t* head;
  list_item_t* tail;
  unsigned int length;
  int (*compare)(const void* key, const void* with);
  void (*datum_delete)(void*);

}list; 


int main(){

  // TODO: INSTANTIATE YOUR LINKED LIST HERE.
  list list;
  list.head = (struct list_item*)malloc(sizeof(struct list_item)); // casting to struct list_item* (from void*)
  list.tail = (struct list_item*)malloc(sizeof(struct list_item));
  list.head->next = list.tail;
  list.head->prev = NULL;
  
  list.tail->prev = list.head;
  list.tail->next = NULL; 

  //----END----
	
  int option, val;
  printOptions();

  do {
    option = readInput(&val);
    struct list_item* node;

    switch(option){
    case PUSH_FRONT:				// push onto front of list
      // TODO: Insert code to push val onto front of linked list here.
      node = list.head->next;

      list.head->next = (struct list_item*)malloc(sizeof(struct list_item));
      list.head->next->value = val;

      list.head->next->prev = list.head;

      list.head->next->next = node;
      node->prev = list.head->next;
      list.length++; 
			  

      //----END----
      break;
			  
    case PUSH_BACK: 				// push onto back of list
      // TODO: Insert code to push val onto back of linked list here.
      node = list.tail->prev;

      list.tail->prev = (struct list_item*)malloc(sizeof(struct list_item));
      list.tail->prev->value = val;

      list.tail->prev->next = list.tail;

      list.tail->prev->prev = node;
      node->next = list.tail->prev;
      list.length++; 

      //----END----
      break;
    case POP_FRONT: 				// remove from front of list
      // TODO: Insert code to remove from front of linked list here.
      // If list is empty, do nothing.
      if ( list.length == 0 ) {
	break;
			    
      } else {
	node = list.head->next;

	node->prev->next = node->next;
	node->next->prev = node->prev;

	free(node);  
	list.length--;
	break;

      }
      //----END----
      break;
    case POP_BACK:					// remove from back of list
      // TODO: Insert code to remove from back of linked list here.
      // If list is empty, do nothing.
      if ( list.length == 0 ) {

	break;
			    
      } else {
	node = list.tail->prev;

	node->prev->next = node->next;
	node->next->prev = node->prev;

	free(node);  
	list.length--;
	break;

      }

      //----END----
      break;
    case PRINT_LIST:				// print list
      // TODO: Insert code to print list forwards here.
      // Simply print each element separated by a space as shown below:
      // Elements: 1 2 3 4 5 
      printf("Elements: ");

      if ( list.length == 0 ) {
	printf("%d ", 0);

	break;
				  
      } else {
	node = list.head->next;

	while (node != list.tail) {
	  int x = node->value;
	  printf("%d ", x);
	  node = node->next; 

	}
	printf("\n"); 

	break;

      }

      //----END----
      break;
    case HELP: 						// print menu
      printOptions();
      break;
    case QUIT: 						// quit
      break;
    case INVALID: 					// bad input
      fprintf(stderr,"Invalid command or operand, please input a valid command or help to see the list again.\n");
      break;
    }

  } while(option != QUIT);

  // TODO: free any memory used by your linked list here

  struct list_item* listItrObject = list.head->next;

  while(listItrObject != list.tail) {
    listItrObject = listItrObject->next;
    free(listItrObject->prev);
  }
	
  free(list.head);
  free(list.tail); 

  //----END----

  return 0;
}



//---------------------------------------
//NOTE: EVERYTHING BELOW THIS LINE SHOULD NOT BE TOUCHED. IT HANDLES INPUT AND SUCH FOR YOU
//---------------------------------------

int readInput(int* val){
  char input[BUFFER_SIZE]="";
  while(isEmpty(input)){
    printf("Enter command: ");
    fgets(input, BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;
  }

  char* token = strtok(input, " ");
	
  if ((strcmp(token, "af")) == 0){
    token = strtok(NULL, " ");
    if (isNumber(token)){
      *val = atoi(token);
      return PUSH_FRONT;
    } else return INVALID;
  } else if ((strcmp(token, "ab")) == 0){
    token = strtok(NULL, " ");
    if (isNumber(token)){
      *val = atoi(token);
      return PUSH_BACK;
    } else return INVALID;
  } else if ((strcmp(token, "rf")) == 0){
    return POP_FRONT;
  } else if ((strcmp(token, "rb")) == 0){
    return POP_BACK;
  } else if ((strcmp(token, "p")) == 0){
    return PRINT_LIST;
  } else if((strcmp(token, "help")) == 0){
    return HELP;
  } else if((strcmp(token, "-1")) == 0){
    return QUIT;
  } else {
    return INVALID;
  }
}

void printOptions(){
  printf("----------------------------------------------------\n");
  printf("This test harness operates with one linked list.\n");
  printf("Use any of the following options to manipulate it:\n");
  printf("\t* af <num> --- add integer to front\n");
  printf("\t* ab <num> --- add integer to back\n");
  printf("\t* rf       --- remove front element\n");
  printf("\t* rb       --- remove back element\n");
  printf("\t* p        --- print list forward\n");
  printf("\t* help     --- print off this list\n");
  printf("\t* -1       --- exit harness\n\n");
}

int isNumber(const char* token){
  int length, i = 0;
  if (token == NULL)	return 0;
  if(token[0] == '-') 	i = 1;
  length = strlen(token);
  for (; i < length; i++){
    if (!isdigit(token[i]))
      return 0;
  }

  return 1;
}

int isEmpty(const char* input){
  while (*input != '\0'){
    if (!isspace((unsigned char)*input))
      return 0;
    input++;
  }

  return 1;
}
