#include <stdio.h>
#include <string.h>

//prototypes for all different cipher types - has a void return type as a return is not required since all strings that need to be changed have pointers
void encryptRot(char *str_adj, char *alpha, char *key);
void decryptRotgiven_all(char *str_adj, char *alpha, char *key); 
void encryptSub(char *str_adj, char *alpha, char *key);
void decrpytSubgiven_all(char *str_adj, char *alpha, char *key);
void decryptRotgiven_text(char *str_adj, char *alpha, char *key);
//void decryptSubgiven_text(char *str_adj, char *alpha, char *key);
void lower_case(char *str_adj);  //function to change the entered strings letters all to lower case
void upper_case(char *str_adj); //function to change the entered strings letters all to upper case
void startupf(char *alpha, char *str_adj, char *origin_mes, char *key); //function used at the beginning of the program to assign many required strings
void copy(char *str_adj, char *str2, char *strf);
void rotate(char *str2, char *strf);

int main() {
    char str_adj[1000]; //creates an empty string that will be used to copy the original message from the input.txt and also be used throughout, changing to meet the cipher 
    char key[27]; //creates an empty string that will be used throughout as the cipher key - this step will be irrelevant if options 5 or 6 are selected in the user interface
    char origin_mes[1000]; //creates a string that will not change throughout the course of the program as it exists simply to store the original message for later comparison
    char alpha[27]; //creates a string for the basic alphabet string to exist, which will be used in determining keys and or editing messages and for final comparison
    startupf(alpha, str_adj, origin_mes, key); //calls a function which will assign many prerequisite values required in the above variables (also makes the main less messy)
    int pick = 0; //simple integer to be used in assisting the user in picking whichever option they would like to use
    int fail = 1; //a variable used to maintain the loop if an invalid option is selected
    while (fail==1) { //this condition exists in case an incorrect option is entered below that is not within the 1-6 range of options provided, allowing it to continue
                      //until a real option is met, by which it will break the loop and enter the final stage of the program.
        //the following print statements provide a user prompt, making the options of this program significantly easier to use  
        printf("Which of the following options do you wish to do with this message? (Select 1-6)\n"); //list printed over several lines, so it is easier to read
        printf("1. Rotation encryption\n2. Decryption of a rotation cipher, given the cipher text and rotation amount\n");
        printf("3. Substitution encryption\n4. Decryption of a substitution cipher, given the cipher text and rotation amount\n");
        printf("5. Decryption of a rotation cipher, given the cipher text\n"/*6. Decryption of a substitution cipher, given the cipher text\n*/);
        //printf("7. Decryption of a ciphered message, where the type of cryptography and the key is unknown\n");
        scanf("%d", &pick); //deciding which cipher subject is to be used
        switch (pick){ //this is used as a list of ascending integers has been used for options, hence it is ideal rather than many if statements
            case (1): encryptRot(str_adj, alpha, key); fail=0; break; //calls the rotation encryption function and using a pointer passes the adjustable string, alphabet and key
            case (2): decryptRotgiven_all(str_adj, alpha, key); fail=0; break; //calls the substitution encryption function and using a pointer passes the adjustable string, alphabet and key
            case (3): encryptSub(str_adj, alpha, key); fail=0; break; //calls the rotation decryption function and using a pointer passes the adjustable string, alphabet and key
            case (4): decrpytSubgiven_all(str_adj, alpha, key); fail=0; break; //calls the substitution decryption function and using a pointer passes the adjustable string, alphabet and key
            case (5): decryptRotgiven_text(str_adj, alpha, key); fail=0; break; //calls the rotation decryption function, nd using a pointer passes the adjustable string, alphabet
                                                                                //and key(even though it doesn't exist yet)
            //case (6): decryptSubgiven_text(str_adj, alpha, key); fail=0; break; //incomplete function
            //case (7): unknown_decrypt(str_adj, alpha, key); fail=0; break; //incomplete function
            default: printf("Option selected does not exist\nEnsure the option chosen is the number corresponding to the option desired\n");//clarifying when a mistake is made
        }
    }
    FILE *results; //creates a pointer which will be used to store a file's data in the next lines
    results = fopen("results.txt", "w+"); //opens a file that can be written to and will operate as a file to record the final results
    if (results==NULL) //tests if the File I/O implementation has an error or failure and does not proceed normally
        perror("Results file did not open correctly"); //if there is a failure it prints this error, and does not proceed
    else {
        fprintf(results, "Entered message: %s\nAltered message: %s\nAlphabet:   %s\nCipher Key: %s\n", origin_mes, str_adj, alpha, key);
        //the line 49, writes the information of the original message and the adjusted message to the txt file called "results.txt"
        //additionally this line also writes information of the cipher key alongside the alphabet for ease of translation or verification if needed
        printf("The results of the cryptography method used have been written to file \"results.txt\".\nThese results will also be printed to the screen: \n");
        fclose(results); //the file has already been written to, hence it no longer needs to remain open, therefore it is closed
    }
        printf("Entered message: %s\nAltered message: %s\n", origin_mes, str_adj); //prints the originally entered message and the ciphered message on different lines
        printf("Alphabet:   %s\nCipher Key: %s\n", alpha, key); //prints the encryption key by showing a comparison of the alphabet to the ciphered alphabet
    return 0;
}


//defintion of the cipher functions
void encryptRot (char *str_adj, char *alpha, char *key) { //defining the function to do a rotation encryption of the given message with the cipher key given
    int i, n;
    n = ((char)key[0] - (char)alpha[0]); //rotation number determined from the difference between the given key and the alphabet function
    if (n!=0) { //checks if the rotation is valid.
        for (i=0; str_adj[i]; i++) {
                if (str_adj[i]<65 || str_adj[i]>90) //checks if it is not within the ASCII range and does not change it if is; 65 = 'A', 90 = 'Z'
                    str_adj[i] = str_adj[i];
                else { //if it is in the correct range it will continue as normal.
                str_adj[i] = (char)str_adj[i] + n; //for whatever rotation keys, the function will add/substitute each element of the string by what rotation key scale has been given
                if (str_adj[i] > 90) //90 = 'Z'
                    str_adj[i] = (char)(str_adj[i]) - 26; //if the encryption rotation exceeds the ASCII limit, this will allow it to return to our range of 65 - 90 characters
                if (str_adj[i] < 65) //65 = 'A'
                    str_adj[i] = (char)(str_adj[i]) + 26; //if the encryption rotation is below the ASCII limit, this will allow it to return to our range of 65 - 90 characters  
                }
            }
    }
    else if (n==0) { //if the rotation number is 0, nothing will change, hence the encryption is simply skipped
        printf("It appears a key has been entered that is the same as the alphabet, hence it will have no effect.");
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

//this is a decryption of a rotation cipher when the key is not given to the program. It works by checking each key and validating whether one is correct if one of the words
//of the original string rotated matches that of a list of commonly used words, once this is found the rotation number is stored and the key and decrypted message can be found 
void decryptRotgiven_text(char *str_adj, char *alpha, char *key) { //defining the function to decrypt the given message without a given cipher key (rotation)
    int i, k=1, j, leave=0, count; //i and j are to move through different elements of strings, replacing k, leave is simply for when a loop needs to break, 
                                   //count is used to count how many letters of the input will match that of words from the list of words
    char str2[100]; //alternate string that will take form of str_adj
    char strf[100]; //alternate string that will be a word from str_adj
    copy(str_adj, str2, strf); //creates a string that copies the first word of the adjustable string (the reason for this is the method required alters the string too greatly)
    FILE *words = fopen("words.txt", "r"); //imports a file containing a long list of words that can be read as shown by the "r" format specifier
    if (words==NULL) //tests if the File I/O implementation has an error or failure and does not proceed normally
        perror("Results file did not open correctly"); //if there is a failure it prints this error, and does not proceed
    char string[10000]; //creates a large string that will be able to hold the words from the list
    for (k=1; k<26; k++) { //creates a loop - the value of k will determine the rotation number of the cipher key
        rotate(str2, strf); //calls a function which will rotate each of the two strings by +1
        lower_case(str2); //calls a function to change all of the letters in the input to lower case (the dictionary/word list being used is in lower case)
        while (!feof(words)) { //while the words.txt file is not at the end of the file, this will run - additionally, this will cycle through each word, allowing each word to
                               //be tested
            fgets(string, 10001, words); //assigns an individual word to string[] which will then be tested against our rotated words from the entered message
                                         //if the string is not this large, a stack smashing error will occur; the string isn't large enough to store the data
            for (i=0; string[i]; i++) { //encountered a bug where the length of the string was incorrect, hence this exists to counteract that bug
                if (string[i]>122 || string[i]<97) //confirming whether all letters in the word chosen from the word list exist as lower case
                    string[i] = '\0'; //null factor consolidates the true length of the string, example "everybody" was 11 characters long rather than 9, which is used soon
            }
            count = 0; //resets the count, so that the following string will work as intended (if it had previously stored values it would detect an incorrect word as correct)
            for (j=0; str2[j]; j++) { //works similar to how i has been used throughout, it allows to move through each element of a string
                if ((str2[j] == string[j])) { //if the jth letter of the strings are equal, it will be counted
                    count++; //explained previously to be used to determine whether ALL letters in the two given words match
                    if ((count == strlen(str2)) && count == (strlen(string))) { //commences if all of the letters all the same between the word in the list and the entered message
                        leave = 1; //condition required to leave the overall loop and move onto the next steps
                        break; //breaks this while loop
                    }  //for some reason this one does not decrypt the einstein quote as it did previously
                }
                else {
                    break; //if there is no similar letters the loop breaks early as further testing would be redundant
                }
            }
            if (leave == 1) //if a word has been matched, the loop is broken and the key and message can be solved
                break; //this break occurs if str2 matched to a word and will then not compare strf to that word, as it is unnecessary
            count = 0; //resets the count, so that the following string will work as intended (if it had previously stored values it would detect an incorrect word as correct)
            for (j=0; strf[j]; j++) { //works similar to how i has been used throughout, it allows to move through each element of a string
                if ((strf[j] == string[j])) { //if the jth letter of the strings are equal, it will be counted
                count++; //explained previously to be used to determine whether ALL letters in the two given words match
                    if ((count == strlen(strf)) && count == (strlen(string))) { //commences if all of the letters all the same between the word in the list and the entered message
                        leave = 1; //condition required to leave the overall loop and move onto the next steps
                        break; //breaks this while loop
                    }   
                }
                else {
                    break; //if there is no similar letters the loop breaks early as further testing would be redundant
                }
            }
            if (leave == 1) //if a word has been matched, the loop is broken and the key and message can be solved
                break; //this break will occur if strf has matched to a word and will then break the loop, preventing unnecessary testing
        }
        if (leave == 1) //if a word has been matched, the loop is broken and the key and message can be solved
            break; //this breaks exits the for loop involving k - this is important since k is stored as the rotation number
        rewind(words); //this sets the file position back to the beginning of the file, allowing it to repeat for further tests/
        upper_case(str2); //calls a function to change all of the letters in the input to upper case (must be done to make sure the next rotation numbers will work)
                          //also, working with lower case in ASCII is annoying because the ASCII limit is 127 and 'z' = 122, which makes dealing with rotation numbers painful
    }
    fclose(words); //closes the file, as it is no longer needed
    for (i=0; alpha[i]; i++) { //determines the key for later comparison
        key[i] = alpha[i] + k; //changing the key according to the rotation number found
        if (key[i]>90) //if this exceeds the ASCII limit of capital letters
            key[i] = key[i] - 26; //this will rectify exceeding the ASCII limit specified
    }
    for (i=0; str_adj[i]; i++) { //creates a loop to change each individual element within the adjustable string
        if (str_adj[i]<65 || str_adj[i]>122) //checks if it is not within the ASCII range and does not change it if is
            str_adj[i] = str_adj[i]; //this is 
        else {
            str_adj[i] = str_adj[i] + k; //this adjusts the string according to the rotation number
            if (str_adj[i]>90) //if this exceeds the ASCII limit of capital letters
                str_adj[i] = str_adj[i] - 26; //if a letter exits outside the ASCII range of capital letters, this will rectify it.
        }
    }
} 

//void decryptSubgiven_text(char *str_adj, char *alpha, char *key) { //defining the function to decrypt the given message without a given key (substitution)
//unfortunately, this function was not completed.
//}

//this is a startup function to essentially assign the correct values to the many strings used throughout the program
void startupf(char *alpha, char *str_adj, char *origin_mes, char *key) { //function to create an alphabet at the beginning of the program when it is executed
    FILE *input; 
    input = fopen("input.txt", "r"); //reads from the text in the input txt file
    if (input==NULL) //tests if the File I/O implementation has an error or failure and does not proceed normally, but instead prints an error
        perror("File did not open correctly");
    else {
        fgets(str_adj, 1000, input); //makes the text from the input txt file into a string
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

//a simple function to change values of the adjustable string to lower_case
void lower_case(char *str_adj) { //since the dictionary that has been given is in lower case, it is faster to change our input rather than 10000 elements.
    for (int i=0; str_adj[i]; i++) { 
        if (str_adj[i]>=65 && str_adj[i]<=90) //checking for uppercase
            str_adj[i] = str_adj[i] + 32; //adjusting to lowercase
        else { //if it is outside the range that is being changed it will be ignored (mostly for white space)
            str_adj[i] = str_adj[i]; 
        }
    }
}

//a simple function to change values of the adjustable string to upper_case
void upper_case(char *str_adj) { //created due to the annoyances involved with lower_case characters and the dictionary string
    for (int i=0; str_adj[i]; i++) { 
        if (str_adj[i]>=97 && str_adj[i]<=122) //checking for lowercase
            str_adj[i] = str_adj[i] - 32; //fixing lowercase
        else { //if it is outside the range that is being changed it will be ignored (mostly for white space)
            str_adj[i] = str_adj[i]; 
        }
    }
}

//this function's purpose is to create two strings that contain a single word from the adjustable string(entered message). The words chosen from the string are
//the first word and the fourth (I picked a random place for the fourth)
void copy(char *str_adj, char *str2, char *strf) { 
    int i;
    for (i=0; i<=(strlen(str_adj)+1); i++) { //retains the original message and it's respective characters - essentially this loop copies the adjustable string to str2
        if (i>strlen(str_adj))
            str2[i] = 10; //resolves a bug that occurred due to a missing null character which produced a symbol at the end of the string where it was not specified
        str2[i] = str_adj[i]; //it'd be smart to replace this with strcpy(s1, s2) - unfortunately I came into trouble using this for an unknown reason and hence will continue to use what works
    } 
    char delim[] = " "; //this is an array with only the element of white space - this is a delimiter which is used to split characters in a string into tokens
    char *ptr = strtok(str2, delim); //strtok receives values from two strings, the first is the string to be split, the second is the delimiter; decides how it will be split
    while (ptr!=NULL) { //this continues while there is still some value in str2, as this needs to be run multiple times to completely split each word
        ptr = strtok(NULL, delim); //strtok modifies the string, and through the pointer will return a value for each token, separating the words by inserting a null factor
                                   //'\0' after every time when strtok is run. The NULL is a parameter, so that with each new token, it's starting position will be where the
                                   //last one ended
    }
    FILE *input_a = fopen("input_a", "w"); //opens a file to be written to from the program
    if (input_a==NULL) //tests if the File I/O implementation has an error or failure and does not proceed normally
        perror("Results file did not open correctly"); //if there is a failure it prints this error, and does not proceed
    fprintf(input_a, "%s", str2); //prints str2 to this file and exists in a format similar to that of the word list
    fclose(input_a); //this is then closed - even though this is used later, I did this here and split it into another pointer just to make sure it would work
    FILE *input_m = fopen("input_a", "r"); //reopens the same file, but this time it can only be read in the program
    if (input_m==NULL) //tests if the File I/O implementation has an error or failure and does not proceed normally
        perror("Results file did not open correctly"); //if there is a failure it prints this error, and does not proceed
    fgets(str2, 100, input_m); //assigns a string of the first word in the entered message
    i=0; //start of an integer used for counting
    while (!feof(input_m)) { //while the input_a.txt file is not at the end of the file, this will run.
        if (i==3) { //on the fourth word it will be recorded after i increments to 3 (starts at 0)
            fgets(strf, 1000, input_m); //assigns a string of the fourth word in the entered message - it is meant to
            }
        i++; //increments to achieve a different word in the input_a.txt
    }
    fclose(input_m); //closes the file
    for (i=0; strf[i]; i++) {
                if (strf[i]>122 || strf[i]<97) //unsure about this variable as it always returns a blank space when printed, yet the Mon Motha decryption works as Mon is not in
                                               //the word list, so it must be doing something
                    strf[i] = '\0'; //null factor consolidates the true length of the string
            }
}

//a function that exists to rotate the letters of the tested words in the rotation decryption without a key by a factor of 1
void rotate(char *str2, char *strf) {
    int i, n=1;
    for (i=0; str2[i]; i++) { //loop serves the purpose of changing the entered message to a different key to be tested
                if (str2[i]<65 || str2[i]>90)  //if the string element exists outside the newly rectified ASCII range, it will ignore it, allowing white space
                    str2[i] = str2[i]; //nothing changes
                else {
                    str2[i] = str2[i] + n; //changes the entire string by 1, effectively rotating the cipher.
                }
                if (str2[i] > 90) //if the string eventually exceeds its ASCII range
                    str2[i] = (char)(str2[i]) - 26; //if the encryption rotation exceeds the ASCII limit, this will return this element to the correct range of 65 - 90 characters  
        }
    for (i=0; strf[i]; i++) { //loop serves the purpose of changing the entered message to a different key to be tested
                if (strf[i]<65 || strf[i]>90)  //if the string element exists outside the newly rectified ASCII range, it will ignore it, allowing white space
                    strf[i] = strf[i]; //nothing changes
                else {
                    strf[i] = strf[i] + n; //changes the entire string by 1, effectively rotating the cipher.
                }
                if (strf[i] > 90) //if the string eventually exceeds its ASCII range
                    strf[i] = (char)(strf[i]) - 26; //if the encryption rotation exceeds the ASCII limit, this will return this element to the correct range of 65 - 90 characters  
        }
}
