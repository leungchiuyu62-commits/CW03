#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_1_PATH "src/file_1.txt"
#define FILE_2_PATH "src/file_2.txt"

#define MAX_LINE_LEN 1000

int compare_files(  FILE *file_1, FILE *file_2,
                    char *line_1, char *line_2, int *line_number )
{
    *line_number = 0;

    while ( 1 )
    {
        int got_1 = ( fgets(line_1, MAX_LINE_LEN, file_1) != NULL );
        int got_2 = ( fgets(line_2, MAX_LINE_LEN, file_2) != NULL );

        (*line_number)++;

        if ( got_1 && got_2 )
        {
            if ( strcmp(line_1, line_2) != 0 )
            {
                return 1;   /* first difference found */
            }
        }
        else if ( !got_1 && !got_2 )
        {
            return 0;       /* both files ended at the same time: same file */
        }
        else
        {
            /* one file is shorter: line buffer of the shorter one is empty */
            if ( !got_1 ) line_1[0] = '\0';
            if ( !got_2 ) line_2[0] = '\0';
            return 1;
        }
    }
}

// DO NOT change the code below
#ifndef ___TEST___
int main()
{
    char line_1[MAX_LINE_LEN];
    char line_2[MAX_LINE_LEN];
    int line_number = 1;
    FILE *file_1;
    FILE *file_2;
    file_1 = fopen(FILE_1_PATH, "r");
    file_2 = fopen(FILE_2_PATH, "r");
    if ( compare_files(file_1, file_2, line_1, line_2, &line_number) != 0 )
    {
        printf("file1 [%d]: %s", line_number, line_1);
        printf("file2 [%d]: %s", line_number, line_2);
    }
    fclose(file_1);
    fclose(file_2);
    return 0;
}
#endif
// DO NOT change the code above
