#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void read_image(int num_rows, int num_cols, 
                int arr[num_rows][num_cols], FILE *fp);
void print_image(int num_rows, int num_cols, int arr[num_rows][num_cols]);

// function prototype to count the cells, which will return an int
int count_cells(int num_rows, int num_cols, int arr[num_rows][num_cols]);

int main(int argc, char **argv) {
    // Print a message to stderr and exit with an argument of 1
    // if there are not the right number of parameters, or if
    // there is a second argument that is not -p

    // The following snippet helps you check your arguments.
    // strcmp returns 0 if the strings are equal and
    // you haven't learned about this yet.
    // Notice that this is NOT COMPLETE, but we have given you this
    // much to show you how to check '-p' and print to stderr.
    // Be careful with the array indexing!

    // if there are less than 2 arguments (not enough arguments),
    // or if there is a third argument not '-p' (while having 3 arguments),
    // or if there are more than 3 arguments (too many arguments),
    // program will exit with return code of 1.
    if (argc<2 || (argc == 3 && strcmp(argv[2], "-p") != 0) || argc >3) {
        fprintf(stderr, "Usage: count_cells <imagefile.txt> [-p]\n");
        return 1;
    }

    int should_print_image;  
    if(argc == 3) {
        should_print_image = 1;  // true
    } else {
        should_print_image = 0;  // false
    }

    char *filename = argv[1];  // gets the input from the command line argument
    
    FILE *file = fopen(filename, "r");  // open the file. 
    if(!file) {  // if the file fails to open, returns an error
        perror("Error: can't open the file");
        return 1;  // terminate program, error
    }

    int rows; 
    int cols;
    // if there weren't two items from the file, print error to standard error stream
    if(fscanf(file, "%d %d", &rows, &cols) != 2) {
        fprintf(stderr, "Error reading image.");
        fclose(file);
        return 1;
    }

    int array[rows][cols];
    read_image(rows, cols, array, file);
    fclose(file);

    if (should_print_image) {
        print_image(rows, cols, array);
    }

    // call the count_cells function and print the result
    int cell_count = count_cells(rows, cols, array);
    printf("Number of Cells is %d\n", cell_count);

    return 0;  // terminate program
}


