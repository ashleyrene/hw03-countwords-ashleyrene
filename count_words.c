#include "count_words.h"

int countWord(char* filename, char* word, char* line, int size) 
{
    //open a file whose name is filename for reading
    FILE *file = fopen(filename, "r");
    if (!file) 
    {
        //if fopen fails, return -1
        return -1;  
    }
    
    int ret = 0;  //set ret to zero
    size_t word_len = strlen(word);
    
    //use fgets to read the file line-by-line
    while (fgets(line, size, file))
        {
        char *pos = line;
        
        //use strstr to find occurrences of word in line
        while ((pos = strstr(pos, word))) 
        {
            ret++;  //increment ret when word is found
            pos += word_len;  //move pointer forward to prevent overlapping matches
        }
    }
    
    //close the file
    fclose(file); 
    //return the final count
    return ret; 
}
