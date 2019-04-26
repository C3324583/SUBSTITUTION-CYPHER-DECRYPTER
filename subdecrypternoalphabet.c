#include <stdio.h>
#include <stdlib.h>


int main(){
    //initialisation of variables and arrays
	char text[1000];
	int number_of_letter[127] = {0};
	int n, i, x, ascii, rotationey, MAX = 0;
	
	printf("Enter message: ");//prompts the user to imput a message
	scanf(" %[^\n]s", text);//stores the text imputted by the user in the array "text"
   
   /*This for loop executes for all characters in the array "text" until the chracter occupying index i is a
    "NULL" character*/
    for(n=0; text[n]!='\0'; n++){
  
	    //turns lowercase letters in the array "text" into UPPERCASE by subtracting 32
     	if(text[n] >= 'a' && text[n] <= 'z'){
		    text[n] = text[n] - 32;
     	}
     
        //prints the character at index "n" to the screen if it is not a letter
        if(text[n] < 'A' || text[n] > 'Z'){
                printf("%c", text[n]);
        }
    }
    
	for(ascii='A'; ascii<='Z'; ascii++){
	    for(i=0; text[i] != '\0'; i++){
	        if(ascii==text[i]){
	            number_of_letter[ascii]++;
	        }
        } 
	}
	
	for (x=0; number_of_letter[x] != '\0'; x++){
	    if(number_of_letter[x] > MAX){
	        MAX = number_of_letter[x];
	        common_letter = x;
	    }
	}
	
	rotationkey = common_letter - 'E';
	
	return 0;
}