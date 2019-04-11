#include <stdio.h>
#include <string.h>

//prototypes for all different cipher types
char encryptRot(char *input);
//int decryptRotgiven_all(void); 
char encryptSub(char *input);
//int decrpytSubgiven_all(void);
//int decryptRotgiven_cipher(void);
//int decryptSubgiven_cipher(void);*/

int main() {
//NEXT TASK: CONVERT WRITTEN INPUT into identifiable/modifiable text
//TURN THE ALPHABET INTO A FUNCTION SO IT IS NOT BLOCKED INTO THE MIDDLE OF MAIN
    char input[50] = {};
    int pick = 0;
    printf("What is the message you wish to encrypt/decrypt?\n");
    scanf("%s", input); //needs to be able to scan given letters (probably not an integer but will be a string), may need to be implemented into each function
    int fail=1;
    while (fail==1) {
    printf("Which of the following options do you wish to do with this message? (Select 1-n)\n"); //list printed over several lines, so it is easier to read
    printf("1. Rotation encryption\n2. Decryption of a rotation cipher, given the cipher text and rotation amount\n");
    printf("3. Substitution encryption\n4. Decryption of a substitution cipher, given the cipher text and rotation amount\n");
    printf("5. Decryption of a rotation cipher, given the cipher text\n6. Decryption of a substitution cipher, given the cipher text\n");
    scanf("%d", &pick);//deciding which cipher subject is to be used*/
    switch (pick){ 
        case (1): encryptRot(input); fail=0; break; //calls the rotation encryption function and reassigns input to the encryption
        //case (2): decryptRotgiven_all(input); fail=0; break;
        case (3): encryptSub(input); fail=0; break;
        //case (4): decryptSubgiven_all(input); fail=0; break;
        //case (5): decryptRotgiven_cipher(input); fail=0; break;
        //case (6): decryptSubgiven_cipher(input); fail=0; break;
        default: printf("Option selected does not exist\nEnsure the option chosen is the number corresponding to the option desired\n"); fail = 1;
        }
    }
    printf("%s\n", input);
    return 0;
}

//defintion of the cipher functions
char encryptRot (char *input) { //is functioning - CANNOT READ WHITE SPACE CURRENTLY
    //char input[200] = {}; //defining a string for the initial message
    int i, n;
    //printf("This is rotation encryption.\nEnter the message you wish to encrypt: \n");
    //scanf("%s", input); //reading the input from the user until a white space
    printf("What is the rotation number for this cipher?\n");
    scanf("%d", &n); //n = rotation key scale
    if (n!=0) {
    for (i=0; input[i]; i++) {
            input[i] = (char)input[i] + n; //for whatever rotation keys, the function will add/substitute each element of the string by what rotation key scale has been given
            if (input[i] > 90)
                input[i] = (char)(input[i]) - 26; //if the encryption rotation exceeds the ASCII limit, this will allow it to return to our range of 65 - 90 characters
            if (input[i] < 65)
                input[i] = (char)(input[i]) + 26; //if the encryption rotation is below the ASCII limit, this will allow it to return to our range of 65 - 90 characters  
            }
        }
    else if (n==0) //if the rotation number is 0, nothing will change, so it skips reassignment of the string
        printf("Since the rotation number is 0, the message will not change\n");
    printf("Encryption key: %d\n", n);
    return *input; //reassigns the string input to the main function which can be freely manipulated
}
/*
int decryptRotgiven_all(void) {
    
}*/

char encryptSub(char *input) { //incomplete
    //int i, n;
    char alphabet[50]; //normal alphabet
    char key[50]; //encryption key alphabet
    srand(time(NULL)); //makes it so every rand value allocated will be randomised/a new value from the last
    for (char c=0; c<=26; c++) { //[ is one ASCII value higher than Z
        if (c>25) { 
            alphabet[c] = '\0'; break;
        }
        alphabet [c] = c+65; //assigning alphabet to an element in this string
}
    for (char c=0; c<=26; c++) {
        if (c>25) {
            key[c] = '\0'; break
        }
        key[c] = alphabet[c] + (int)(rand() % 26); //adds a value to each element which will be randomly allocated and will not exceed the ASCII limit - ideally.
        //This won't work because how will you then allocate a value to the lower numbered ASCII's such as A or B.
    }
    //each value needs to randomly assigned to a different variable with the key stored, additionally, values cannot be assigned to the same value.
    //using this string change each value to something + rand() % 26 + 1 (and watch for ASCII limit), as well as something to make sure two values cannot be the same.
    //will need to apply something similar to the previous rotation encryption to ensure it does not exceed the limit
    return 0;
}
/*
int decryptSubgiven_all(void) {
    
}*/
