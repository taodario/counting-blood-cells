#include <stdio.h>
#include <stdlib.h>

// Open file fp is read to 2d array, the the num_rows and num_cols specifies the array dimensions
void read_image(int num_rows, int num_cols, int arr[num_rows][num_cols], FILE *fp) {
    for(int row=0; row<num_rows; row++)  // loop through rows
        for(int col=0; col<num_cols; col++) { // loop through cols
            int count_of_read = fscanf(fp, "%d", &arr[row][col]); 
            if(count_of_read != 1) {
                fprintf(stderr, "Unable to read the pixel at position (%d, %d) from the file!\n", row, col);
                exit(EXIT_FAILURE); // Exit the program with a failure status code
            }
        }
}

// prints the contents of the array to the standard output
void print_image(int num_rows, int num_cols, int arr[num_rows][num_cols]) {
    for(int row=0; row<num_rows; row++) {
        for(int col=0; col<num_cols; col++)
            printf("%d ", arr[row][col]);
        printf("\n");
    }
}

// Helper function to perform flood fill
// Citation for the flood fill algorithm:
// "Understanding the Flood Fill Algorithm and the StackOverflowError" by Saturn Cloud, Tuesday, July 18th, 2023
// https://saturncloud.io/blog/understanding-the-flood-fill-algorithm-and-the-stackoverflowerror/#:~:text=The%20Flood%20Fill%20algorithm%20is%20a%20popular%20technique%20used%20for,the%20boundary%20of%20the%20region.
void flood_fill(int row, int col, int num_rows, int num_cols, int arr[num_rows][num_cols]) {
    // Base case:
    // Checks whether or not the specified pixel is within the bounds of the array or not
    if(row<0 || row>=num_rows || col<0 || col>=num_cols) {
        return;  // returns to exit if pixel out of bounds of array
    }

    // check if the pixel is white (255)
    if(arr[row][col] != 255) {
        return; // returns to exit if the pixel isn't the target we want (white)
    }

    arr[row][col] = 0; // Marks the specified pixel as visited, by setting it to 0
    
    flood_fill(row - 1, col, num_rows, num_cols, arr); // recursively calls the flood fill algo on the top pixel
    flood_fill(row + 1, col, num_rows, num_cols, arr); // recursively calls the flood fill algo on the bottom pixel
    flood_fill(row, col - 1, num_rows, num_cols, arr); // recursively calls the flood fill algo on the left pixel
    flood_fill(row, col + 1, num_rows, num_cols, arr); // recursively calls the flood fill algo on the right pixel
}

// Function to count cells in the given image array
int count_cells(int num_rows, int num_cols, int arr[num_rows][num_cols]) {
    int counter = 0;
    for (int row=0; row<num_rows; row++) {
        for (int col=0; col<num_cols; col++) {
            if (arr[row][col] == 255) {  // if the pixel at the specified spot in the array is a white pixel (255)
                counter = counter+1; // adds a count of a new cell
                flood_fill(row, col, num_rows, num_cols, arr); // Call the flood fill algorithm (helper function) to mark the specified cells
            }
        }
    }
    return counter;  // returns the counter. Counts the number of cells, and returns the number.
}