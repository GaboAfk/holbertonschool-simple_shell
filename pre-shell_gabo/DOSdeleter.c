#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av) {

    if (ac != 3)
        printf("USAGE ./DOSdeleter input output\n");
    
    FILE *input_file = fopen(av[1], "r");
    FILE *output_file = fopen(av[2], "w");

    if (input_file == NULL || output_file == NULL) {
        perror("Error opening files");
        return 1;
    }

    int prev_char = '\0';
    int current_char;

    while ((current_char = fgetc(input_file)) != EOF) {
        if (prev_char == '\r' && current_char == '\n') {
            // Skip writing '\r', write only '\n'
            fputc('\n', output_file);
        } else {
            fputc(prev_char, output_file);
            prev_char = current_char;
        }
    }

    // Write the last character if not written yet
    if (prev_char != EOF) {
        fputc(prev_char, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}