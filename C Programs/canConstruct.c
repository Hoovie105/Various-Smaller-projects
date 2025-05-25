#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool canConstruct(char *ransomNote, char *magazine) {
    int letters[26] = {0}; // frequency table for letters a-z

    // Count each letter in the magazine
    for (int i = 0; magazine[i] != '\0'; i++) {
        letters[magazine[i] - 'a']++;
    }

    // Check if ransomNote can be constructed
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        if (letters[ransomNote[i] - 'a'] == 0) {
            return false; // Not enough of this letter
        }
        letters[ransomNote[i] - 'a']--;
    }

    return true;
}
