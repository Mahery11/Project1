#include <stdio.h>
#include <string.h>

//prototypes for all different cipher types
/*void encryptRot(void);
int decryptRotgiven_all(void); 
int encryptSub(void);
int decrpytSubgiven_all(void);
int decryptRotgiven_cipher(void);
int decryptSubgiven_cipher(void);*/

int main() {
//NEXT TASK: CONVERT WRITTEN INPUT into identifiable/modifiable text
//TURN THE ALPHABET INTO A FUNCTION SO IT IS NOT BLOCKED INTO THE MIDDLE OF MAIN

    //char x[];
    int pick = 0;
    //printf("What is the message you wish to encrypt/decrypt?\n");
    //scanf("%s", &x); //needs to be able to scan given letters (probably not an integer but will be a string), may need to be implemented into each function
    printf("Which of the following options do you wish to do with this message? (Select 1-n)\n"); //list printed over several lines, so it is easier to read
    printf("1. Rotation encryption\n2. Decryption of a rotation cipher, given the cipher text and rotation amount\n");
    printf("3. Substitution encryption\n4. Decryption of a substitution cipher, given the cipher text and rotation amount\n");
    printf("5. Decryption of a rotation cipher, given the cipher text\n6. Decryption of a substitution cipher, given the cipher text\n");
    printf("%s %d %d\n", alphabet, pick, startup); //this is to make the compiler stop complaining
    scanf("%d", &pick);//deciding which cipher subject is to be used*/
    switch (pick){ 
        case (1): encryptRot(); break;
        //case (2): decryptRotgiven_all(x); break;
        //case (3): encryptSub(x); break;
        //case (4): decryptSubgiven_all(x); break;
        //case (5): decryptRotgiven_cipher(x); break;
        //case (6): decryptSubgiven_cipher(x); break;
        default: printf("Option selected does not exist\nEnsure the option chosen is the number corresponding to the option desired"); continue;//restart/reask question, use continue or something else?
    }
    return 0;
}

//defintion of the cipher functions
void encryptRot (void) { 
    char input[200] = {};
    scanf("%s", input);
    int i;
    for (i=0; input[]; i++) {
        input[i] = (char)input[i] + 2;
        if (input[i] > 90)
            input[i] = (char)(input[i]) - 26;
    }
    printf("%s\n", input);
}
/*
int decryptRotgiven_all(void) {
    
}

int encryptSub(void) {
    
}

int decryptSubgiven_all(void) {
    
}*/
