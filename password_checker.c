//sorc code

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main(void) {
    char password[MAX_LEN];
    int length, hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    printf("== Password Strength Checker ==\n");
    printf("Enter a password: ");

    if (fgets(password, sizeof(password), stdin) == NULL) {
        printf("No input received.\n");
        return 1;
    }

    int truncated = (strchr(password, '\n') == NULL) && (strlen(password) == MAX_LEN - 1);

    password[strcspn(password, "\n")] = '\0';
    length = (int)strlen(password);

    for (int i = 0; i < length; i++) {
        unsigned char c = (unsigned char)password[i];
        if (isupper(c)) hasUpper = 1;
        else if (islower(c)) hasLower = 1;
        else if (isdigit(c)) hasDigit = 1;
        else hasSpecial = 1;
    }

    int varietyScore = hasUpper + hasLower + hasDigit + hasSpecial;

    int lengthScore = 0;
    if (length >= 16) lengthScore = 2;
    else if (length >= 8) lengthScore = 1;

    int score = varietyScore + lengthScore; 

    printf("\n-- Analysis --\n");
    if (truncated) {
        printf("Note: input was longer than %d characters and was truncated.\n", MAX_LEN - 1);
    }
    printf("Length: %d characters %s\n", length,
           (length >= 16) ? "(great)" : (length >= 8) ? "(OK, 16+ is stronger)" : "(too short, use 8+)");
    printf("Uppercase letter: %s\n", hasUpper ? "Yes" : "No");
    printf("Lowercase letter: %s\n", hasLower ? "Yes" : "No");
    printf("Number: %s\n", hasDigit ? "Yes" : "No");
    printf("Special character: %s\n", hasSpecial ? "Yes" : "No");

    printf("\nStrength: ");
    if (score <= 2)
        printf("Weak\n");
    else if (score <= 4)
        printf("Moderate\n");
    else
        printf("Strong\n");

    return 0;
}

//END
