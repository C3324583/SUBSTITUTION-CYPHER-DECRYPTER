#include <stdio.h>
#include <stdlib.h>

void rotation(int x, int z, char text[]);
void rotationdefault(char text[]);
 
int main(){
    //initialisation of variables and arrays
	char text[10000];
	int number_of_letter[127] = {0};
	int n, i, x, s=1, ascii, first=0, second=0, third=0, fourth=0, fifth=0;
	const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char substitution[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	for (int i = 0; i < 26; i++) {    // shuffle array
    int x = substitution[i];
    int random_i = rand() % 25 + 'A';
    substitution[i] = substitution[random_i];
    substitution[random_i] = x;
 
	
	printf("Enter message: ");//prompts the user to imput a message
	scanf(" %[^\n]s", text);//stores the text imputted by the user in the array "text"
   
   /*This for loop executes for all characters in the array "text" until the chracter occupying index i is a
    "NULL" character*/
    for(n=0; text[n]!='\0'; n++){
  
	    //turns lowercase letters in the array "text" into UPPERCASE by subtracting 32
     	if(text[n] >= 'a' && text[n] <= 'z'){
		    text[n] = text[n] - 32;
     	}
    }
   
   
    for(n=0; text[n]!='\0'; n++){
  
	    //turns lowercase letters in the array "text" into UPPERCASE by subtracting 32
     	if(text[n] >= 'a' && text[n] <= 'z'){
		    text[n] = text[n] - 32;
     	}
     
        //prints the character at index "n" to the screen if it is not a letter
        if(text[n] < 'A' || text[n] > 'Z'){
                printf("%c", text[n]);
        }
        
        /* This loop tests if the character at index "n" is equal to any of the letters in the array "substitution" 
        (index 0 to index 25), and if true, the character is substituted with the corresponding chracter in the 
        array "ALPHABET" */
        for(i=0; i<26; i++){
            
            /* This "if" statement turns lowercase letters in the array "substitution" into UPPERCASE by subtracting
            32 before the substitution is done */
            if(substitution[i] >= 'a' && substitution[i] <= 'z'){
		        substitution[i] = substitution[i] - 32;
	        }
             
            /* This "if" statement tests if the charater in "text" at index "n" is equal to any character in 
            "substitution" by running through all possible indices "i". If true, the character at the same index "i" of 
            "ALPHABET" is printed to the screen */
            if (text[n] == substitution[i]){
                printf("%c", ALPHABET[i]);
            }
        }
    }
   
	
	for (x=0; x<126; ++x){
	    if(number_of_letter[x] > number_of_letter[first]){
	        first = x;
	    }
	}
	
	for (x=0; x<126; ++x){
	    if(x != first && number_of_letter[x] <= number_of_letter[first] && number_of_letter[x] > number_of_letter[second]){
	        second = x;
	    }
	}
	
    for (x=0; x<126; ++x){
	    if(x != first && x != second && number_of_letter[x] <= number_of_letter[second] && number_of_letter[x] > number_of_letter[third]){
	        third = x;
	    }
	}	
	
	for (x=0; x<126; ++x){
	    if(x != first && x != second && x != third && number_of_letter[x] <= number_of_letter[third] && number_of_letter[x] > number_of_letter[fourth]){
	        fourth = x;
	    }
	}	
	
	for (x=0; x<126; ++x){
	    if(x != first && x != second && x != third && x != fourth && number_of_letter[x] <= number_of_letter[fourth] && number_of_letter[x] > number_of_letter[fifth]){
	        fifth = x;
	    }
	}


    substitution(first, text);
    substitution(second, text);
    substitution(third, text);
    substitution(fourth, text);
    substitution(fifth, text);
    
	return 0;
}


void rotation(int x, int z, char text[]){
    char txt[10000];
    for(int y=0;text[y] != '\0'; y++){
        txt[y]=text[y];
    }
    int rotationkey = x - z;
	int success;
    for(int i=0; txt[i] != '\0'; i++){
        if(txt[i] >= 'A' && txt[i] <= 'Z'){
    		txt[i] = txt[i] - rotationkey;
    		if(txt[i]>'Z'){
		        txt[i] = txt[i] - 26;
		    }
		    if(txt[i]<'A'){
		        txt[i] = txt[i] + 26;
		    }    
		}
    }

	printf("Is this the correct message: %s\n", txt); //prints the rotated message to the screen
	printf("Yes - Press 1 and then <enter> \nNo - Press 0 and then <enter> \n");
	scanf("%d", &success);
	if(success == 1){
	    exit(0);
    }
}

