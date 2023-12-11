#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#include <time.h>

void drawNecessaryPart(int numLives) {
    switch (numLives) {
        case 5:
            circle(100, 75, 20); // head
            break;
        case 4:
            line(100, 95, 100, 150); // body
            break;
        case 3:
            line(100, 95, 75, 120); // left arm
            break;
        case 2:
            line(100, 95, 125, 120); // right arm
            break;
        case 1:
            line(100, 150, 75, 175); // left leg
            break;
    }
}

void singlePlayer(int level, char guessWords[8][16]) {
    if (level == 6) {
        printf("Congratulations! You won the game");
        return;
    }

    line(50, 20, 50, 200);  // pole base
    line(50, 20, 100, 20);  // pole upper stick
    line(100, 20, 100, 55); // rope/noose

    srand(time(NULL)); // for random nr

    int randomIndex = rand() % 8;
    while (guessWords[randomIndex] == "") {
        randomIndex = rand() % 8;
    }

    int numLives = 6;
    int currentCount = 0; // incremented only when correct letter is entered
    int oldCount = 0; // for checking if any correct letter was entered

    int lengthOfWord = strlen(guessWords[randomIndex]);

    int letterGuessed[24]; // for storing indexes of guessed letters as 1

    int reguessed = 0;

    char guess[24];
    char letterEntered;

    printf("\nLevel %d", level);

    while (currentCount < lengthOfWord) {
        printf("\n\nWord:");

        // print current word:
        for (int loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) {
            if (letterGuessed[loopIndex] == 1) {
                printf("%c", guessWords[randomIndex][loopIndex]);
            } else {
                printf("_");
            }
        }

        printf("\n");
        printf("Enter a guess letter:");
        scanf("%s", guess);

        letterEntered = guess[0];
        reguessed = 0;

        oldCount = currentCount;

        for (int loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) {
            // check if entered letter was already guessed
            if (letterGuessed[loopIndex] == 1) {
                if (guessWords[randomIndex][loopIndex] == letterEntered) {
                    reguessed = 1;
                    break;
                }
                continue;
            }

            // if it was not guessed
            if (letterEntered == guessWords[randomIndex][loopIndex]) {
                letterGuessed[loopIndex] = 1;
                currentCount++;
            }
        }

        // if no correct letter was entered
        if (oldCount == currentCount && reguessed == 0) {
            numLives--;
            printf("Sorry, wrong guess\n");
            drawNecessaryPart(numLives);
            if (numLives == 0) {
                break;
            }
        } else if (reguessed == 1) {
            printf("Already Guessed!!\n");
        } else {
            printf("Correct guess :)\n");
        }
    }

    if (numLives == 0) {
        line(100, 150, 125, 175); // right leg
        delay(3000);
        printf("\nSorry you lose, the word was: %s\n", guessWords[randomIndex]);
    } else {
        printf("\nYOU WIN!!! The word: %s\n", guessWords[randomIndex]);
        cleardevice();
        strcpy(guessWords[randomIndex], "");
        singlePlayer(level+1, guessWords);
    }

}

void multiPlayer() {
    char guessWord[16];
    printf("Input word: ");
    scanf("%s", guessWord);

    int numLives = 6;
    int currentCount = 0; // incremented only when correct letter is entered
    int oldCount = 0; // for checking if any correct letter was entered

    int lengthOfWord = strlen(guessWord);

    int letterGuessed[24]; // for storing indexes of guessed letters as 1

    int reguessed = 0;

    char guess[24];
    char letterEntered;

    while (currentCount < lengthOfWord) {
        printf("\n\nWord:");

        // print current word:
        for (int loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) {
            if (letterGuessed[loopIndex] == 1) {
                printf("%c", guessWord[loopIndex]);
            } else {
                printf("_");
            }
        }

        printf("\n");
        printf("Enter a guess letter:");
        scanf("%s", guess);

        letterEntered = guess[0];
        reguessed = 0;

        oldCount = currentCount;

        for (int loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) {
            // check if entered letter was already guessed
            if (letterGuessed[loopIndex] == 1) {
                if (guessWord[loopIndex] == letterEntered) {
                    reguessed = 1;
                    break;
                }
                continue;
            }

            // if it was not guessed
            if (letterEntered == guessWord[loopIndex]) {
                letterGuessed[loopIndex] = 1;
                currentCount++;
            }
        }

        // if no correct letter was entered
        if (oldCount == currentCount && reguessed == 0) {
            numLives--;
            printf("Sorry, wrong guess\n");
            drawNecessaryPart(numLives);
            if (numLives == 0) {
                break;
            }
        } else if (reguessed == 1) {
            printf("Already Guessed!!\n");
        } else {
            printf("Correct guess :)\n");
        }
    }


    if (numLives == 0) {
        line(100, 150, 125, 175); // right leg
        delay(30000);
        printf("\nSorry you lose, the word was: %s\n", guessWord);
    } else {
        printf("\nYOU WIN!!! The word: %s\n", guessWord);
    }

}

int main() {
    int gameType;
    printf("Choose game mode\n");
    printf("Type 1 for one player, and 2 for multiplayer: ");
    scanf("%d", &gameType);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    char guessWords[8][16] = {
        "program",
        "black",
        "purple",
        "windows",
        "linux",
        "white",
        "blue",
        "orange"
    };

    if (gameType == 1) {
        singlePlayer(1, guessWords);
    } else if (gameType == 2) {
        multiPlayer();
    } else {
        printf("Invalid input\n");
    }

    return 0;
}
