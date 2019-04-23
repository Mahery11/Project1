#include <stdio.h>
#include <string.h>

//prototypes for all different cipher types
void encryptRot(char *str_adj, char *alpha, char *key);
void decryptRotgiven_all(char *str_adj, char *alpha, char *key); 
char encryptSub(char *str_adj, char *alpha);
//int decrpytSubgiven_all(void);
//int decryptRotgiven_text(void);
//int decryptSubgiven_text(void);
void Alphabet_f(char *alpha);

int main() {
//NEXT TASK: CONVERT WRITTEN str_adj into identifiable/modifiable text
//TURN THE ALPHABET INTO A FUNCTION SO IT IS NOT BLOCKED INTO THE MIDDLE OF MAIN
    char alpha[26]; //creates a string for the basic alphabet string to exist
    char key[26]; //EXISTS AS SOMETHING TO BE COMPARED TO THE ALPHABET FUNCTION TO SHOW THE KEY
    char str_adj[50] = "THIS is a MEsSage with WhiTe SpaCEs"; //CURRENTLY HARD CODED AND MUST BE REPLACED BY FILE I/O
    char origin_mes[50];
    int pick = 0;
    for (int i=0; str_adj[i]; i++) { //retains the original message and it's respective characters
        origin_mes[i] = str_adj[i]; //Need to apply a null factor at the end of this, for some reason capital letters are unaffected and this string prints out normally
                                    //However if it finishes with a lower case it is followed by an @ symbol in the final output.
        }
    Alphabet_f(alpha); //assigns a letter from A-Z to each element of the string AND FIXES ANY ANOMALIES IN THE MESSAGE (may implement later for shorter functions)
    //printf("What is the message you wish to encrypt/decrypt?\n");
    //scanf("%s", str_adj); //replace with File I/O to read white space
    int fail=1;
    while (fail==1) {
    printf("Which of the following options do you wish to do with this message? (Select 1-n)\n"); //list printed over several lines, so it is easier to read
    printf("1. Rotation encryption\n2. Decryption of a rotation cipher, given the cipher text and rotation amount\n");
    printf("3. Substitution encryption\n4. Decryption of a substitution cipher, given the cipher text and rotation amount\n");
    printf("5. Decryption of a rotation cipher, given the cipher text\n6. Decryption of a substitution cipher, given the cipher text\n");
    scanf("%d", &pick);//deciding which cipher subject is to be used*/
    switch (pick){ 
        case (1): encryptRot(str_adj, alpha, key); fail=0; break; //calls the rotation encryption function and reassigns str_adj to the encryption
        case (2): decryptRotgiven_all(str_adj, alpha, key); fail=0; break;
        case (3): encryptSub(str_adj, alpha); fail=0; break;
        //case (4): decryptSubgiven_all(str_adj); fail=0; break;
        //case (5): decryptRotgiven_text(str_adj); fail=0; break;
        //case (6): decryptSubgiven_text(str_adj); fail=0; break;
        default: printf("Option selected does not exist\nEnsure the option chosen is the number corresponding to the option desired\n"); fail = 1;
        }
    }
    printf("Entered message:  %s\nCiphered message: %s\n", origin_mes, str_adj);
    printf("Encryption key: \n%s\n%s\n", alpha, key);
    return 0;
}


//defintion of the cipher functions
void encryptRot (char *str_adj, char *alpha, char *key) { //is functioning - CANNOT READ WHITE SPACE CURRENTLY
    int i, n;
    printf("What is the rotation number for this cipher? (Scale exists between -25 and 25)\n");
    scanf("%d", &n); //n = rotation key scale
    if (n!=0) {
    for (i=0; str_adj[i]; i++) {
            if (str_adj[i]>=97 && str_adj[i]<=122) //checking for lowercase
                str_adj[i] = str_adj[i] - 32; //fixing lowercase
            if (str_adj[i]<65 || str_adj[i]>122) //checks if it is not within the ASCII range and does not change it if is
                str_adj[i] = str_adj[i];
            else { //if it is in the correct range it will continue as normal.
            str_adj[i] = (char)str_adj[i] + n; //for whatever rotation keys, the function will add/substitute each element of the string by what rotation key scale has been given
            if (str_adj[i] > 90)
                str_adj[i] = (char)(str_adj[i]) - 26; //if the encryption rotation exceeds the ASCII limit, this will allow it to return to our range of 65 - 90 characters
            if (str_adj[i] < 65) //UNSURE: Why are the white spaces not being affected by this?
                str_adj[i] = (char)(str_adj[i]) + 26; //if the encryption rotation is below the ASCII limit, this will allow it to return to our range of 65 - 90 characters  
                }
            }
        }
    else if (n==0) //if the rotation number is 0, nothing will change, so it skips reassignment of the string
    printf("Since the rotation number is 0, the message will not change\n");
    for (i=0; alpha[i]; i++) { //creates a string that is the key of the cipher which can be clearly observed in the final output
        key[i] = alpha[i] + n;
            if (key[i] > 90)
                key[i] = (char)(key[i]) - 26; //if the encryption rotation exceeds the ASCII limit, this will allow it to return to our range of 65 - 90 characters
            if (key[i] < 65)
                key[i] = (char)(key[i]) + 26; //if the encryption rotation is below the ASCII limit, this will allow it to return to our range of 65 - 90 characters  
    }
}

void decryptRotgiven_all(char *str_adj, char *alpha, char *key) { //THERE IS A LOT OF BUGS IN THIS CODE
//WHITE SPACE IS STILL BEING CHANGED UNLIKE THE ENCRYPTION
//Scaling works correctly, now it is simply accounting for white space
    int i, k, n; //declaring multiple variables that will be used for different things
    printf("What is the key of this cipher?\n1. Determine the scale with a number\n2. Enter the exact key (all caps, no spaces)\n");
    scanf("%d", &k); //scanned for an option as to how the cipher will be entered
    if (k == 1) { //option 1
        printf("What is the rotation number for this cipher? (Scale exists between -25 and 25)\n");
        scanf("%d", &n); //the user provides an integer of the rotation number that the cipher works under
        n = -(n % 26); //this number is a negative as the scale will have to work in reverse, it has a modulus in case the number exceeds the given domain
        for (i=0; alpha[i]; i++) { //creates a string that is the key of the cipher which can be clearly observed in the final output
            key[i] = alpha[i] - n; //creating the cipher key since the exact key has not been given, just the rotation number
            if (key[i] > 90)
                key[i] = (char)(key[i]) - 26; //if the encryption rotation exceeds the ASCII limit, this will allow it to return to our range of 65 - 90 characters
            if (key[i] < 65)
                key[i] = (char)(key[i]) + 26; //if the encryption rotation is below the ASCII limit, this will allow it to return to our range of 65 - 90 characters  
            }
    }
    if (k == 2) { //if the user inputs the exact key with no spaces in all caps, it can be directly transferred into the string and be used
        printf("Enter the exact key of this cipher: ");
        scanf("%s", key); //no & needed as this will apply the input directly into the string - which also doesn't need to worry about white space since it is one line
    }
    for (i=0; str_adj[i]; i++) {
        if (k==1) { //checks if a rotation number has been given or if it must be calculated
            //a filter for white space needs to be added here - also unsure if they are even elements that even exist.
            str_adj[i] = str_adj[i] + n; //STILL NEEDS TO ACCOUNT FOR WHITE SPACE, this adjusts the string according to the rotation number (which will usually be 
            // changed in sign as it must have the reverse effect of a rotation encryption)
        }
        else { //if the rotation number has not been given, it must be calculated by finding the difference between the cipher string and the regular alphabet string
               //using ASCII numbers
            n = -((char)key[0] - (char)alpha[0]); //this number is a negative as the scale will have to work in reverse
            i--; //since a this has been one loop, the increment must be cancelled with a decrement
            k = 1; //now that the rotation number is defined/has been found, the string can be decrypted
        }
    }
}

char encryptSub(char *str_adj, char *alpha) { //incomplete
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