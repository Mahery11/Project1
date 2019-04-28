#include <stdio.h>
#include <string.h>

//prototypes for all different cipher types - has a void return type as a return is not required since all strings that need to be changed have pointers
void encryptRot(char *str_adj, char *alpha, char *key);
void decryptRotgiven_all(char *str_adj, char *alpha, char *key); 
void encryptSub(char *str_adj, char *alpha, char *key);
void decrpytSubgiven_all(char *str_adj, char *alpha, char *key);
//void decryptRotgiven_text(char *str_adj, char *alpha, char *key);
//void decryptSubgiven_text(char *str_adj, char *alpha, char *key);
void startupf(char *alpha, char *str_adj, char *origin_mes);

int main() {
    FILE *input; 
    char str_adj[100]; //creates an empty string that will be used to copy the original message from the input.txt and also be used throughout, changing to meet the cipher 
    input = fopen("input.txt", "r"); //reads from the text in the input txt file
    if (input==NULL) //tests if the File I/O implementation has an error or failure and does not proceed normally, but instead prints an error
        perror("File did not open correctly");
    else {
        fgets(str_adj, 100, input); //makes the text from the input txt file into a string
        fclose(input); //closes the file, as it is no longer needed
    }
    FILE *cipher;
    char key[27]; //creates an empty string that will be used throughout as the cipher key - this step will be irrelevant if options 5 or 6 are selected in the user interface
    cipher = fopen("cipher.txt", "r+"); //reads from the text in the cipher txt file
    if (cipher==NULL) //tests if the File I/O implementation has an error or failure and does not proceed normally, but instead prints an error
        perror("File did not open correctly");
    else {
        fgets(key, 27, cipher); //makes the text from the cipher txt file into a string that will be used as a key
        fclose(cipher); //closes the file, as it is no longer needed
    }
    char origin_mes[100]; //creates a string that will not change throughout the course of the program as it exists simply to store the original message for later comparison
    char alpha[27]; //creates a string for the basic alphabet string to exist, which will be used in determining keys and or editing messages and for final comparison
    startupf(alpha, str_adj, origin_mes); //calls a function which will assign many prerequisite values required in the above variables (also makes the main less messy)
    int pick = 0;
    int fail = 1;
    while (fail==1) { //this condition exists in case an incorrect option is entered below that is not within the 1-6 range of options provided, allowing it to continue
                      //until a real option is met, by which it will break the loop and enter the final stage of the program.
        printf("Which of the following options do you wish to do with this message? (Select 1-6)\n"); //list printed over several lines, so it is easier to read
        printf("1. Rotation encryption\n2. Decryption of a rotation cipher, given the cipher text and rotation amount\n");
        printf("3. Substitution encryption\n4. Decryption of a substitution cipher, given the cipher text and rotation amount\n");
        printf("5. Decryption of a rotation cipher, given the cipher text\n6. Decryption of a substitution cipher, given the cipher text\n");
        scanf("%d", &pick); //deciding which cipher subject is to be used
        switch (pick){ 
            case (1): encryptRot(str_adj, alpha, key); break; //calls the rotation encryption function and using a pointer passes the adjustable string, alphabet and key
            case (2): decryptRotgiven_all(str_adj, alpha, key); break; //calls the substitution encryption function and using a pointer passes the adjustable string, alphabet and key
            case (3): encryptSub(str_adj, alpha, key); break; //calls the rotation decryption function and using a pointer passes the adjustable string, alphabet and key
            case (4): decrpytSubgiven_all(str_adj, alpha, key); break; //calls the substitution decryption function and using a pointer passes the adjustable string, alphabet and key
            //case (5): decryptRotgiven_text(str_adj, alpha, key); break;
            //case (6): decryptSubgiven_text(str_adj, alpha, key); break;
            //case (7): unknown_decrypt(str_adj, alpha, key); break;
            default: printf("Option selected does not exist\nEnsure the option chosen is the number corresponding to the option desired\n");
            }
    }
    //at this point add the File Output to a separate txt file and add the option if they want the results to be printed to stdout (the screen)
    FILE *results;
    results = fopen("results.txt", "w"); //opens a separate file that can be written to from this program and will operate as a file to record the final results
    if (results==NULL) //tests if the File I/O implementation has an error or failure and does not proceed normally, but instead prints an error
        perror("Results file did not open correctly");
    else {
        fprintf(results, "Entered message: %s\nAltered message: %s\nAlphabet:   %s\nCipher Key: %s\n", origin_mes, str_adj, alpha, key);
        //the line 59, writes the information of the original message and the adjusted message to the txt file called "results.txt"
        //additionally this line also writes information of the cipher key alongside the alphabet for ease of translation or verification if needed
        fclose(results); //the file has already been written to, hence it no longer needs to remain open, therefore it is closed
    }
    int i;
    printf("The results of the cryptography method chosen have been written to file \"results.txt\".\nThese results can also be printed to the screen.\n");
    printf("Enter \"1\" to see results printed, or any other number to exit the program: ");
    scanf("%d", &i); //provides an additional option if the user wants to the results to be printed to the screen
    if (i==1) {
        printf("Entered message: %s\nAltered message: %s\n", origin_mes, str_adj); //prints the originally entered message and the ciphered message on different lines
        printf("Alphabet:   %s\nCipher Key: %s\n", alpha, key); //prints the encryption key by showing a comparison of the alphabet to the ciphered alphabet
    }
    return 0;
}


//defintion of the cipher functions
void encryptRot (char *str_adj, char *alpha, char *key) { //defining the function to do a rotation encryption of the given message with the cipher key given
    int i, n;
    n = ((char)key[0] - (char)alpha[0]);
    if (n!=0) {
    for (i=0; str_adj[i]; i++) {
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
}

void decryptRotgiven_all(char *str_adj, char *alpha, char *key) { //defining the function to decrypt the given message in the form of a rotation encryption with the cipher key given
    int i, n; //declaring multiple variables that will be used for different things
    n = -((char)key[0] - (char)alpha[0]); //calculates the rotation number of the cipher
    for (i=0; str_adj[i]; i++) {
        if (str_adj[i]<65 || str_adj[i]>122) //checks if it is not within the ASCII range and does not change it if is
            str_adj[i] = str_adj[i];
        else {
            str_adj[i] = str_adj[i] + n; //this adjusts the string according to the rotation number
            if (str_adj[i]<65)
                str_adj[i] = str_adj[i] + 26; //if a letter exits the ASCII range of capital letters, this will rectify it.
            }
        }
}

void encryptSub(char *str_adj, char *alpha, char *key) { //defining the function to do a substitution encrypt the given message with the cipher key given
    int i, n;
    for (i=0; str_adj[i]; i++) {
            if (str_adj[i]<65 || str_adj[i]>90) { //if the string element exists outside the newly rectified ASCII range, it will ignore it, allowing white space
                str_adj[i] = str_adj[i];          //to be included in the encryption
            }
            else { //if it is a normal character within the ASCII range of capital letters, the following will proceed
                for (n=0; alpha[n]; n++){ //this loop checks every element in the alphabet function in ascending order
                    if (str_adj[i]==alpha[n]) { //every cycle, the loop checks which nth element of alpha is equal to our given message
                         //the number of this element (n) is recorded to be used later as the strings correlate as can be seen in the final screen when compared
                        break;
                    } 
                }
            str_adj[i] = key[n]; //reassigns the ith element of the message to the corresponding letter of the key as determined from above, encrypting the message
            }
    }
}

void decrpytSubgiven_all(char *str_adj, char *alpha, char *key) { //defining the function to decrypt the given message in the form of a substitution encryption with the cipher key given
    int i, n;
    for (i=0; str_adj[i]; i++) {
        if (str_adj[i]<65 || str_adj[i]>90) { //if the string element exists outside the newly rectified ASCII range, it will ignore it, allowing white space to be included
            str_adj[i] = str_adj[i];
            }
        else { //if it is a normal character within the ASCII range of capital letters, the following will proceed
            for (n=0; alpha[n]; n++){ //this loop checks every element in the alphabet function in ascending order
                if (str_adj[i]==key[n]) { //every cycle, the loop checks which nth element of alpha is equal to our given message
                    //the number of this element (n) is recorded to be used later as the strings correlate as can be seen in the final screen when compared
                    break;
                    } 
                }
            str_adj[i] = alpha[n]; //reassigns the ith element of the message to the corresponding letter of the key as determined from above, decrypting the message
            }
    }
}

/*void decryptRotgiven_text(char *str_adj, char *alpha, char *key) { //defining the function to decrypt the given message without a given cipher key (rotation)
    int i, n;
    for (n=0; n<26; n++) { //n is the rotation number, which will increase incremently with each key tested
        for (i=0; str_adj[i]; i++) {
            if (str_adj[i]<65 || str_adj[i]>90)  //if the string element exists outside the newly rectified ASCII range, it will ignore it, allowing white space
                str_adj[i] = str_adj[i];
                
            str_adj[i] = str_adj[i] + n;
            if (str_adj[i] > 90)
                str_adj[i] = (char)(str_adj[i]) - 26; //if the encryption rotation exceeds the ASCII limit, this will allow it to return to our range of 65 - 90 characters  
            }
        
        }
    }
    //We will be given the string of the message
    //Various keys will need to be tested incremently, changing the encrypted message
    //This changed message will need to be tested to see if any common words can be found in its arrangement
    //If successful it will exit the testing loop, if not it will continue.
    
    //Difficulty: Finding a particular word within the string and making the dictionary string/file to be compared to.
    
    //this will need an extra array/function of the dictionary, which may have to be implemented using File I/O (Might be for the best)
}*/

/*void decryptSubgiven_text(char *str_adj, char *alpha, char *key) { //defining the function to decrypt the given message without a given key (substitution)
    
}*/

void startupf(char *alpha, char *str_adj, char *origin_mes) { //function to create an alphabet at the beginning of the program when it is executed
    for (int c=0; c<=26; c++) { //assigns from elements 0 to 25 letters A-Z
        if (c>25) { //if the 25th element is exceed (Z), a null character will be applied to the end of the string - I often find bugs when I do not do this
            alpha[c] = '\0'; break;
        }
        alpha[c] = c+65; //assigning a letter to an element in this string regarding its ASCII number, creating an alphabet by defining each letter in the string
    }
    for (int i=0; i<=(strlen(str_adj)+1); i++) { //retains the original message and it's respective characters
        if (i>strlen(str_adj))
            origin_mes[i] = '\0'; //resolves a bug that occurred due to a missing null character which produced a symbol at the end of the string where it was not specified
        origin_mes[i] = str_adj[i]; //it'd be smart to replace this with strcpy(s1, s2) - unfortunately I came into trouble using this for an unknown reason and hence will continue to use what works
    }  
    for (int i=0; str_adj[i]; i++) { 
        if (str_adj[i]>=97 && str_adj[i]<=122) //checking for lowercase
            str_adj[i] = str_adj[i] - 32; //fixing lowercase
    }
}