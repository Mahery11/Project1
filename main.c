#include <stdio.h>
#include <string.h>

//prototypes for all different cipher types - has a void return type as a return is not required since all strings that need to be changed have pointers
void encryptRot(char *str_adj, char *alpha, char *key);
void decryptRotgiven_all(char *str_adj, char *alpha, char *key); 
void encryptSub(char *str_adj, char *alpha, char *key);
void decrpytSubgiven_all(char *str_adj, char *alpha, char *key);
void decryptRotgiven_text(char *str_adj, char *alpha, char *key);
//void decryptSubgiven_text(char *str_adj, char *alpha, char *key);
void lower_case(/*char *alpha, */char *str_adj);
void upper_case(char *str_adj);
void startupf(char *alpha, char *str_adj, char *origin_mes, char *key);
void copy(char *str_adj, char *str2);

int main() {
    char str_adj[100]; //creates an empty string that will be used to copy the original message from the input.txt and also be used throughout, changing to meet the cipher 
    char key[27]; //creates an empty string that will be used throughout as the cipher key - this step will be irrelevant if options 5 or 6 are selected in the user interface
    char origin_mes[100]; //creates a string that will not change throughout the course of the program as it exists simply to store the original message for later comparison
    char alpha[27]; //creates a string for the basic alphabet string to exist, which will be used in determining keys and or editing messages and for final comparison
    startupf(alpha, str_adj, origin_mes, key); //calls a function which will assign many prerequisite values required in the above variables (also makes the main less messy)
    int pick = 0;
    int fail = 1;
    while (fail==1) { //this condition exists in case an incorrect option is entered below that is not within the 1-6 range of options provided, allowing it to continue
                      //until a real option is met, by which it will break the loop and enter the final stage of the program.
        printf("Which of the following options do you wish to do with this message? (Select 1-6)\n"); //list printed over several lines, so it is easier to read
        printf("1. Rotation encryption\n2. Decryption of a rotation cipher, given the cipher text and rotation amount\n");
        printf("3. Substitution encryption\n4. Decryption of a substitution cipher, given the cipher text and rotation amount\n");
        printf("5. Decryption of a rotation cipher, given the cipher text\n6. Decryption of a substitution cipher, given the cipher text\n");
        printf("7. Decryption of a ciphered message, where the type of cryptography and the key is unknown\n");
        scanf("%d", &pick); //deciding which cipher subject is to be used
        switch (pick){ 
            case (1): encryptRot(str_adj, alpha, key); fail=0; break; //calls the rotation encryption function and using a pointer passes the adjustable string, alphabet and key
            case (2): decryptRotgiven_all(str_adj, alpha, key); fail=0; break; //calls the substitution encryption function and using a pointer passes the adjustable string, alphabet and key
            case (3): encryptSub(str_adj, alpha, key); fail=0; break; //calls the rotation decryption function and using a pointer passes the adjustable string, alphabet and key
            case (4): decrpytSubgiven_all(str_adj, alpha, key); fail=0; break; //calls the substitution decryption function and using a pointer passes the adjustable string, alphabet and key
            case (5): decryptRotgiven_text(str_adj, alpha, key); fail=0; break;
            //case (6): decryptSubgiven_text(str_adj, alpha, key); fail=0; break;
            //case (7): unknown_decrypt(str_adj, alpha, key); fail=0; break;
            default: printf("Option selected does not exist\nEnsure the option chosen is the number corresponding to the option desired\n");
            }
    }
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
                str_adj[i] = str_adj[i] + 26; //if a letter exits outside the ASCII range of capital letters, this will rectify it.
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

void decryptRotgiven_text(char *str_adj, char *alpha, char *key) { //defining the function to decrypt the given message without a given cipher key (rotation)
    int i, k=1, n=1, j, leave=0;
    char str2[100];
    copy(str_adj, str2);
    FILE *words = fopen("words.txt", "r");
    char string[5000];
    for (k=1; k<26; k++) {
        for (i=0; str2[i]; i++) { //loop serves the purpose of changing the entered message to a different key to be tested
                if (str2[i]<65 || str2[i]>90)  //if the string element exists outside the newly rectified ASCII range, it will ignore it, allowing white space
                    str2[i] = str2[i];
                else {
                    str2[i] = str2[i] + n; //is not lower case due to the difficulties of being so close to the ASCII limit of 127
                }
                if (str2[i] > 90)
                    str2[i] = (char)(str2[i]) - 26; //if the encryption rotation exceeds the ASCII limit, this will allow it to return to our range of 65 - 90 characters  
            }
        lower_case(str2);
        printf("%s\n", str2);
        while (!feof(words) && k<48) { //where the problem exists - it needs to restart to begin checking other keys
            fgets(string, 5001, words);
            for (j=0; (strlen(str2) + 1); j++) {
                printf("%c -- %c\n", str2[j], string[j]);
                /*if (j > strlen(str2))
                    leave = 1;
                    break;*/
                if (strcmp(str2[j], string[j])==0) { //why won't this work ;-;
                    printf("str2:%c  string:%c  \n", str2[j], string[j]);
                    }
                else {
                    break;
                }
            }
            k++;
        }
        rewind(words);
            /*i = strcmp(str2, string); //compares the input with the dictionary to test if any words are correct with the dictionary
            if (i>0)
                continue;
            else if (i<0) {
                continue;
            }
            else if (i==0) {
                leave=1; //they must be equal
                break;
            }*/
        if (leave == 1)
            break;
        upper_case(str2);
    }
    k = k - 47;
    printf("%d\n", k);
    fclose(words); //closes the file, as it is no longer needed
    for (i=0; alpha[i]; i++) { //determines the key for later comparison
        key[i] = alpha[i] + k;
        if (key[i]>90)
            key[i] = key[i] - 26;
    }
    n = -((char)key[0] - (char)alpha[0]);
    upper_case(str_adj);
    for (i=0; str_adj[i]; i++) {
        if (str_adj[i]<65 || str_adj[i]>122) //checks if it is not within the ASCII range and does not change it if is
            str_adj[i] = str_adj[i];
        else {
            str_adj[i] = str_adj[i] + n; //this adjusts the string according to the rotation number
            if (str_adj[i]<65)
                str_adj[i] = str_adj[i] + 26; //if a letter exits outside the ASCII range of capital letters, this will rectify it.
            }
    }
} 

//void decryptSubgiven_text(char *str_adj, char *alpha, char *key) { //defining the function to decrypt the given message without a given key (substitution)
//    
//}

void startupf(char *alpha, char *str_adj, char *origin_mes, char *key) { //function to create an alphabet at the beginning of the program when it is executed
    FILE *input; 
    input = fopen("input.txt", "r"); //reads from the text in the input txt file
    if (input==NULL) //tests if the File I/O implementation has an error or failure and does not proceed normally, but instead prints an error
        perror("File did not open correctly");
    else {
        fgets(str_adj, 100, input); //makes the text from the input txt file into a string
        fclose(input); //closes the file, as it is no longer needed
    }
    FILE *cipher;
    cipher = fopen("cipher.txt", "r+"); //reads from the text in the cipher txt file
    if (cipher==NULL) //tests if the File I/O implementation has an error or failure and does not proceed normally, but instead prints an error
        perror("File did not open correctly");
    else {
        fgets(key, 27, cipher); //makes the text from the cipher txt file into a string that will be used as a key
        fclose(cipher); //closes the file, as it is no longer needed
    }
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
    upper_case(str_adj);
}

void lower_case(/*char *alpha, */char *str_adj) { //since the dictionary that has been given is in lower case, it is faster to change our input rather than 10000 elements.
    for (int i=0; str_adj[i]; i++) { 
        if (str_adj[i]>=65 && str_adj[i]<=90) //checking for uppercase
            str_adj[i] = str_adj[i] + 32; //adjusting to lowercase
        else { //if it is outside the range that is being changed it will be ignored (mostly for white space)
            str_adj[i] = str_adj[i]; 
        }
    }
}

void upper_case(char *str_adj) { //created due to the annoyances involved with lower_case characters and the dictionary string
    for (int i=0; str_adj[i]; i++) { 
        if (str_adj[i]>=97 && str_adj[i]<=122) //checking for lowercase
            str_adj[i] = str_adj[i] - 32; //fixing lowercase
        else { //if it is outside the range that is being changed it will be ignored (mostly for white space)
            str_adj[i] = str_adj[i]; 
        }
    }
}

void copy(char *str_adj, char *str2) {
    for (int i=0; i<=(strlen(str_adj)+1); i++) { //retains the original message and it's respective characters
        if (i>strlen(str_adj))
            str2[i] = 10; //resolves a bug that occurred due to a missing null character which produced a symbol at the end of the string where it was not specified
        str2[i] = str_adj[i]; //it'd be smart to replace this with strcpy(s1, s2) - unfortunately I came into trouble using this for an unknown reason and hence will continue to use what works
    } 
    char delim[] = " ";
    char *ptr = strtok(str2, delim);
    while (ptr!=NULL) {
        ptr = strtok(NULL, delim); //gives it the same style as the word.txt, not that it helps too much]
    }
    FILE *input_a = fopen("input_a", "w");
    fprintf(input_a, "%s", str2);
    fclose(input_a);
    FILE *input_m = fopen("input_a", "r");
    fgets(str2, 100, input_m);
    fclose(input_m);
}
