#include "count_words.h"

int countWord(char* filename, char* word, char* line, int size) {
    // Open a file whose name is filename for reading
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1;  // If fopen fails, return -1
    }
    
    int ret = 0;  // Set ret to zero
    size_t word_len = strlen(word);
    
    // Use fgets to read the file line-by-line
    while (fgets(line, size, file)) {
        char *pos = line;
        
        // Use strstr to find occurrences of word in line
        while ((pos = strstr(pos, word))) {
            ret++;  // Increment ret when word is found
            pos += word_len;  // Move pointer forward to prevent overlapping matches
        }
    }
    
    fclose(file);  // Close the file
    return ret;  // Return the final count
}
