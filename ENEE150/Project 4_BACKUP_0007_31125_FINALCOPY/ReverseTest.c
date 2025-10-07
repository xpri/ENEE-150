#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "abCde";  // Input string
    int length = strlen(str);  // Find the length of the string
    char reversed[length + 1];  // Create an array to store the reversed string

    // Use a for loop to reverse the string
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];  // Copy characters from the end to the new string
    }

    reversed[length] = '\0';  // Null-terminate the reversed string

    // Output the reversed string
    printf("Reversed string: %s\n", reversed);

    return 0;
}
