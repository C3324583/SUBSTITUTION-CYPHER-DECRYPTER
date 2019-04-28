#include <stdio.h>
#include <stdlib.h>

int main(){
    //initialisation of variables and arrays
	char text[10000];
	int number_of_letter[127] = {0};
	int n, i, x, ascii, first=0, second=0, third=0, fourth=0, fifth=0;
	const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char substitution[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	for (int i = 0; i < 26; i++) {    // shuffle array
    int x = substitution[i];
    int random_i = rand() % 25 + 'A';
    substitution[i] = substitution[random_i];
    substitution[random_i] = x;
    }

	printf("Enter message: ");//prompts the user to imput a message
	scanf(" %[^\n]s", text);//stores the text imputted by the user in the array "text"

    
    
    
    
    //Counts the number of times each letter is repeated in "text" and stores it in the array "number_of_letter"
    for(ascii='A'; ascii<='Z'; ascii++){
	    for(i=0; text[i] != '\0'; i++){
	        if(ascii==text[i]){
	            number_of_letter[ascii]++;
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

    //Substitutes the most common letters with the most commonly used letters in English
	for(int i = 0; i < 26; i++){
	    if(ALPHABET[i] == first){
	        substitution[i] = 'E';
	        for(int x = 0; x < 26; x++){
	            if(substitution[x] == 'E' && x != i){
	                substitution[x] == first;
	            }
            }
	    }
	    if(ALPHABET[i] == second){
	        substitution[i] = 'T';
	        for(int x = 0; x < 26; x++){
	            if(substitution[x] == 'T' && x != i){
	                substitution[x] == second;
	            }
            }
	    }
	    if(ALPHABET[i] == third){
	        substitution[i] = 'A';
	        for(int x = 0; x < 26; x++){
	            if(substitution[x] == 'A' && x != i){
	                substitution[x] == third;
	            }
            }
	    }
	    if(ALPHABET[i] == fourth){
	        substitution[i] = 'O';
	        for(int x = 0; x < 26; x++){
	            if(substitution[x] == 'O' && x != i){
	                substitution[x] == fourth;
	            }
            }
	    }
	    if(ALPHABET[i] == fifth){
	        substitution[i] = 'I';
	        for(int x = 0; x < 26; x++){
	            if(substitution[x] == 'I' && x != i){
	                substitution[x] == fifth;
	            }
            }
	    }	    
    }
    
    

//This executes the substitution
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
 
             
            /* This "if" statement tests if the charater in "text" at index "n" is equal to any character in 
            "substitution" by running through all possible indices "i". If true, the character at the same index "i" of 
            "ALPHABET" is printed to the screen */
            if (text[n] == ALPHABET[i]){
                printf("%c", substitution[i]);
            }
        }
    }

    return 0;
}