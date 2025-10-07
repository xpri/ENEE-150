#include <stdio.h>

int main() {
    char str[20] = "abCde";  // Input string
    int i = 0;

    while (str[i]) {
        if (str[i] >= 97 && str[i] <= 122)      //uses ascii codes 97 (a) to 112 (z) and checks if it is in the lowercase range and then translates it into the uppercase range by subtracting 32.
        {
            str[i] = str[i] - 32;
        } else if (str[i] >= 65 && str[i] <= 90)        //uses ascii codes 65 (A) to 90 (Z) and checks if it is in the uppercase range and then translates it into the lowercase range by adding 32.
        {
            str[i] = str[i] + 32;
        }
        i++;
    }

    // Output the modified string
    printf("Modified string: %s\n", str);

    return 0;
}