#include <stdio.h>
#include <stdlib.h>


int main(){
    //initialisation of variables and arrays
	char text[1000], substitution[100];
	int number_of_letters[27] = "0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0";
	const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n, i, x = 0, ascii;
	
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
	            number_of_letters[x]++;
	        }
        } 
        x++;
	}
	
	find greatest number in array number_of_letters and assign 
	return 0;
}