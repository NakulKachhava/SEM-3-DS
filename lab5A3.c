#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int are_anagrams(char *str1, char *str2) {
	int i,j;
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }

    char temp1[100], temp2[100];
    strcpy(temp1, str1);
    strcpy(temp2, str2);

    for ( i = 0; temp1[i] != '\0'; i++) {
        for ( j = i + 1; temp1[j] != '\0'; j++) {
            if (temp1[i] > temp1[j]) {
                char temp = temp1[i];
                temp1[i] = temp1[j];
                temp1[j] = temp;
            }
        }
    }

    for ( i = 0; temp2[i] != '\0'; i++) {
        for ( j = i + 1; temp2[j] != '\0'; j++) {
            if (temp2[i] > temp2[j]) {
                char temp = temp2[i];
                temp2[i] = temp2[j];
                temp2[j] = temp;
            }
        }
    }

    return strcmp(temp1, temp2) == 0;
}

 int main() {
    int n,i;
    
    srand(time(0));
    
    printf("Enter the number of words: ");
    scanf("%d", &n);

    char words[n][100];

    for ( i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i]);
    }

    int random_index = rand() % n;

    printf("\nHere is your word to guess its anagram: %s\n", words[random_index]);

    char user_input[100];
    printf("Enter the anagram of the word: ");
    scanf("%s", user_input);

    if (are_anagrams(words[random_index], user_input)) {
        printf("You found the anagram.\n");
    } else {
        printf("you did not found the anagram.\n");
    }

    return 0;
}
