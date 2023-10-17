#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int countWords(char text[], int length) {
    int count = 0;
    
    for (int i = 0; i < length; i++) {
        if (text[i] != ' ') {
            count++;
            while (i < length && text[i] != ' ') {
                i++;
            }
        }
    }
    
    return count;
}

int countPunctuationMarks(char text[], int length) {
    int count = 0;
    
    for (int i = 0; i < length; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?' 
        ||text[i] == ';' || text[i] == ':' || text[i] == ',' 
        || text[i] == '\'' || text[i] == '\"' || text[i] == '(' || text[i] == ')'
        || text[i] == '[' || text[i] == ']' || text[i] == '-') {
            count++;
        }
    }
    
    return count;
}


bool checkEmail(char email[], int length) {
    int atPos = -1;  // Position of '@'
    int dotPos = -1; // Position of '.'
    bool spaces = false;
    bool dotAfterDot = false;
    bool firstDot = false;
    bool dotAfterAtOrAtAfterDot = false;
    // Check if the email is empty
    if (strlen(email) == 0) {
        return false;
    }

if (email[0] == '.') {
    firstDot = true;
}
for (int i = 0; i < strlen(email)-1; i++) {
    if ((email[i] == '.' && email[i+1] == '@') || (email[i] == '@' && email[i+1] == '.')) {
        dotAfterAtOrAtAfterDot = true;
    }
}
    // check if there exists . after @
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            atPos = i;
        } else if (email[i] == '.') {
            dotPos = i;
    }
    }
    // check if there are spaces between chars
    for (int i = 0; i < strlen(email); i++) {
    if (email[i] == " ") {
        spaces = true;
    }
    }
    // check if there exist . after .
    for (int i = 0; i < strlen(email)-1; i++) {
        if (email[i] == '.' && email[i+1] == '.') {
            dotAfterDot = true;
        }
    }
    // Check if email is valid
    if (atPos == -1 || dotPos == -1 || atPos >= dotPos || atPos == 0 || dotPos == strlen(email) - 1 || spaces == true || dotAfterDot == true || firstDot == true || dotAfterAtOrAtAfterDot == true) {
        return false;
    } else {
        return true;
    }
}

int main() {
    char text[1000];
    printf("Enter text: ");
    scanf("%[^\n]s", text);
    
    // Kulev task - find the number of words
    int wordsLength = countWords(text, strlen(text));
    printf("\nThere are %d words", wordsLength);

    // Medium - function that reads a sentence from the user and counts the number of punctuation marks (e.g., periods, commas, question marks) in the sentence
    printf("\nThere are %d punctuation marks\n", countPunctuationMarks(text, strlen(text)));
    
    // Medium - function that reads a string from the user and checks if it is a valid email address based on simple criteria (e.g., contains ”@” and ”.” symbols in the right places)
    char email[1000];
    printf("\nEnter email: ");
    scanf("%s", email);
    bool checked = checkEmail(email, strlen(email));
    if (checked) {
        printf("Valid email");
    } else {
        printf("Invalid email");
    }

    return 0;
}
