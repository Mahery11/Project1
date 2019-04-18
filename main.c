#include <stdio.h>
#include <string.h>

//prototypes for all different cipher types
int encryptRot(char *input);
//int decryptRotgiven_all(void); 
char encryptSub(char *input, char *alpha);
//int decrpytSubgiven_all(void);
//int decryptRotgiven_cipher(void);
//int decryptSubgiven_cipher(void);*/
void Alphabet_f(char *alpha);

int main() {
//NEXT TASK: CONVERT WRITTEN INPUT into identifiable/modifiable text
//TURN THE ALPHABET INTO A FUNCTION SO IT IS NOT BLOCKED INTO THE MIDDLE OF MAIN
    char alpha[26]; //creates a string for the basic alphabet string to exist
    Alphabet_f(alpha); //assigns a letter from A-Z to each element of the string
    char input[50]/* = "HELLO"*/; //Added "HELLO" and commented out standard input for time sake
    int pick = 0, Rkey;
    printf("What is the message you wish to encrypt/decrypt?\n");
    scanf("%s", input); //replace with File I/O to read white space
    int fail=1;
    while (fail==1) {
    printf("Which of the following options do you wish to do with this message? (Select 1-n)\n"); //list printed over several lines, so it is easier to read
    printf("1. Rotation encryption\n2. Decryption of a rotation cipher, given the cipher text and rotation amount\n");
    printf("3. Substitution encryption\n4. Decryption of a substitution cipher, given the cipher text and rotation amount\n");
    printf("5. Decryption of a rotation cipher, given the cipher text\n6. Decryption of a substitution cipher, given the cipher text\n");
    scanf("%d", &pick);//deciding which cipher subject is to be used*/
    switch (pick){ 
        case (1): Rkey = encryptRot(input); fail=0; break; //calls the rotation encryption function and reassigns input to the encryption
        //case (2): decryptRotgiven_all(input); fail=0; break;
        case (3): encryptSub(input, alpha); fail=0; break;
        //case (4): decryptSubgiven_all(input); fail=0; break;
        //case (5): decryptRotgiven_cipher(input); fail=0; break;
        //case (6): decryptSubgiven_cipher(input); fail=0; break;
        default: printf("Option selected does not exist\nEnsure the option chosen is the number corresponding to the option desired\n"); fail = 1;
        }
    }
    printf("%s\n", input);
    printf("Encryption key: %d\n", Rkey);
    return 0;
}


//defintion of the cipher functions
int encryptRot (char *input) { //is functioning - CANNOT READ WHITE SPACE CURRENTLY
    int i, n;
    printf("What is the rotation number for this cipher?\n");
    scanf("%d", &n); //n = rotation key scale
    if (n!=0) {
    for (i=0; input[i]; i++) {
            if (input[i]>=97 && input[i]<=122) //checking for lowercase
                input[i] = input[i] - 32; //fixing lowercase
            if (input[i]<65 || input[i]>122) //checks if it is not within the ASCII range and does not change it if is
                input[i] = input[i];
            else { //if it is in the correct range it will continue as normal.
            input[i] = (char)input[i] + n; //for whatever rotation keys, the function will add/substitute each element of the string by what rotation key scale has been given
            if (input[i] > 90)
                input[i] = (char)(input[i]) - 26; //if the encryption rotation exceeds the ASCII limit, this will allow it to return to our range of 65 - 90 characters
            if (input[i] < 65)
                input[i] = (char)(input[i]) + 26; //if the encryption rotation is below the ASCII limit, this will allow it to return to our range of 65 - 90 characters  
                }
            }
        }
    else if (n==0) //if the rotation number is 0, nothing will change, so it skips reassignment of the string
        printf("Since the rotation number is 0, the message will not change\n");
    return n; //reassigns the string input to the main function which can be freely manipulated
}
/*
int decryptRotgiven_all(void) {
    
}*/

char encryptSub(char *input, char *alpha) { //incomplete
    //int i, n;
    char key[50]; //encryption key alphabet
    //srand(time(NULL)); //makes it so every rand value allocated will be randomised/a new value from the last
    for (int c=0; c<=26; c++) {
        if (c>25) {
            key[c] = '\0'; break;
        }
        //key[c] = alpha[c] + (int)(rand() % 26); //adds a value to each element which will be randomly allocated and will not exceed the ASCII limit - ideally.
        //if ((char)key[c]>90)
            //key[c] = key[c] - 26;
        //This won't work because how will you then allocate a value to the lower numbered ASCII's such as A or B.
        //Figuring out how to create the encryption cipher is next challenge
    }
    printf("%s\n", key);
    //each value needs to randomly assigned to a different variable with the key stored, additionally, values cannot be assigned to the same value.
    //using this string change each value to something + rand() % 26 + 1 (and watch for ASCII limit), as well as something to make sure two values cannot be the same.
    //will need to apply something similar to the previous rotation encryption to ensure it does not exceed the limit
    return 0;
}
/*
int decryptSubgiven_all(void) {
    
}*/

void Alphabet_f(char *alpha) { //function to create an alphabet at the beginning of the program when it is executed
    for (int c=0; c<=26; c++) { //assigns from elements 0 to 25 letters A-Z
        if (c>25) { //if the 25th element is exceed (Z), a null character will be applied to the end of the string - I often find bugs when I do not do this
            alpha[c] = '\0'; break;
        }
        alpha[c] = c+65; //assigning a letter to an element in this string regarding its ASCII number, creating an alphabet by defining each letter in the string
    }      
}