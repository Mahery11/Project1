#include <stdio.h>
#include <string.h>

//prototypes for all different cipher types
/*int encryptRot(void);
int decryptRotgiven_all(void); 
int encryptSub(void);
int decrpytSubgiven_all(void);
int decryptRotgiven_cipher(void);
int decryptSubgiven_cipher(void);*/
int checkAlphabet(); //used to list each number and letter to their corresponding value

int main() {
    char alphabet[61]; //starting the string for the alphabet
    
    for (char c = '0'; c <= ':'; c++) { //0=0, 1=1, ...
         if (c > '9') { //applying a null factor, as not applying this creates unspecified values in the string
            alphabet[c-48] = '\0';
            //printf("%s\n", alphabet); 
            break;
        }
        alphabet[c-48] = c; //assigning alphabet to its proper set number using ASCII numbers
        //printf("%s\n", alphabet); //checking if the output is correct
    }
    for (char c = 'A'; c <= '['; c++) { //10=A, 11=B ... 35=Z
        if (c > 'Z') { //applying a null factor, as not applying this creates unspecified values in the string
            alphabet[c-55] = '\0';
            //printf("%s\n", alphabet); 
            break;
        }        
        alphabet[c-55] = c; //assigning alphabet to its proper set number using ASCII numbers
        //printf("%s\n", alphabet); //checking if the output is correct
    }
    for (char c = 'a'; c <= '{'; c++) { //36=a, 37=b... 61=z
        if (c > 'z') { //applying a null factor, as not applying this creates unspecified values in the string
            alphabet[c-61] = '\0';
            //printf("%s\n", alphabet); 
            break;
        }        
        alphabet[c-61] = c; //assigning alphabet to its proper set number using ASCII numbers
        //printf("%s\n", alphabet); //checking if the output is correct
    }

    checkAlphabet(alphabet); //if the values of the alphabet are unclear

//NEXT TASK: CONVERT WRITTEN INPUT into identifiable/modifiable text
//TURN THE ALPHABET INTO A FUNCTION SO IT IS NOT BLOCKED INTO THE MIDDLE OF MAIN

    /*char x[];
    int pick = 0, startup = 1;
    //while (startup == 1) { //(ensure the code exits when it is meant to)
        printf("What is the message you wish to encrypt/decrypt?\n");
        scanf("%s", &x); //needs to be able to scan given letters (probably not an integer but will be a string)
        printf("Which of the following options do you wish to do with this message? (Select 1-n)\n"); //list printed over several lines, so it is easier to read
        printf("1. Rotation encryption\n2. Decryption of a rotation cipher, given the cipher text and rotation amount\n");
        printf("3. Substitution encryption\n4. Decryption of a substitution cipher, given the cipher text and rotation amount\n");
        printf("5. Decryption of a rotation cipher, given the cipher text\n6. Decryption of a substitution cipher, given the cipher text\n");
        printf("%s %d %d\n", alphabet, pick, startup); //this is to make the compiler stop complaining
        scanf("%d", &pick);//deciding which cipher subject is to be used*/
        /*switch (pick){ 
            case (1): encryptRot(x); break; //x is the value to be encrypted/decrypted
            case (2): decryptRotgiven_all(x); break;
            case (3): encryptSub(x); break;
            case (4): decryptSubgiven_all(x); break;
            case (5): decryptRotgiven_cipher(x); break;
            case (6): decryptSubgiven_cipher(x); break;
            default: printf("Option selected does not exist\nEnsure the option chosen is the number corresponding to the option desired"); continue;//restart/reask question, use continue or something else?
        }
    }*/

    return 0;
}

//defintion of the cipher functions
/*int encryptRot (void) { 
    
}

int decryptRotgiven_all(void) {
    
}

int encryptSub(void) {
    
}

int decryptSubgiven_all(void) {
    
}*/
int checkAlphabet(char check[]) {
    int i;
    for (i=0; i<=61; i++) {
        printf("%d %c\n", i, check[i]);
    }
    return 0;
}