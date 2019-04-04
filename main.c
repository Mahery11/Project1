#include <stdio.h>

//prototypes for all different cipher types
/*int encryptRot(void);
int decryptRotgiven_all(void); 
int encryptSub(void);
int decrpytSubgiven_all(void);
int decryptRotgiven_cipher(void);
int decryptSubgiven_cipher(void);*/

int main() {
    char alphabet[1] = {1}; //123 values
    int pick = 0, startup = 1, x = 0;
    //while (startup == 1) { //(ensure the code exits when it is meant to)
        printf("What is the message you wish to encrypt/decrypt?\n");
        scanf("%d", &x); //needs to be able to scan given letters (probably not an integer but will be a string)
        printf("Which of the following options do you wish to do with this message? (Select 1-n)\n"); //list printed over several lines, so it is easier to read
        printf("1. Rotation encryption\n2. Decryption of a rotation cipher, given the cipher text and rotation amount\n");
        printf("3. Substitution encryption\n4. Decryption of a substitution cipher, given the cipher text and rotation amount\n");
        printf("5. Decryption of a rotation cipher, given the cipher text\n6. Decryption of a substitution cipher, given the cipher text\n");
        printf("%s %d %d\n", alphabet, pick, startup); //this is to make the compiler stop complaining
        scanf("%d", &pick);//deciding which cipher subject is to be used
        /*switch (pick){ 
            case (1): encryptRot(x); //x is the value to be encrypted/decrypted
            case (2): decryptRotgiven_all(x);
            case (3): encryptSub(x);
            case (4): decryptSubgiven_all(x);
            case (5): decryptRotgiven_cipher(x);
            case (6): decryptSubgiven_cipher(x);
            default: //restart/reask question
        }
    }*/

    return 0;
}

//ASCII alphabet, 0(48)-9(59), A(65)-Z(90), a(97)-z(122)
//defintion of the cipher functions
/*int encryptRot (void) { 
    
}

int decryptRotgiven_all(void) {
    
}

int encryptSub(void) {
    
}

int decryptSubgiven_all(void) {
    
}*/