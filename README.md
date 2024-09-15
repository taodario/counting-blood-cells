# counting-blood-cells
 This program implements a simple form of red blood cell counting from blood smear images. It processes segmented black and white images (represented as text files) to count the number of blood cells present.

# Features
Reads blood cell images from text files
Counts the number of cells in the image
Optionally prints the pixel matrix

# Files
count_cells.c: Contains the main function and program logic
image.c: Implements image processing functions

# Compilation
Compile the program using the following command:
Copygcc -Wall -g -std=gnu99 -o count_cells count_cells.c image.c

# Usage
Run the program with the following command:
Copy./count_cells <image_file> [-p]

<image_file>: Name of the blood cell image text file
-p (optional): If present, prints the pixel matrix before other output

# Input File Format
The input file should be a text file containing integers separated by spaces:

First line: number of rows and columns
Subsequent lines: pixel values (0 for black, 255 for white)

# Output
The program outputs the number of cells detected in the image:
CopyNumber of Cells is <count>
If the -p option is used, it will also print the pixel matrix.
Implementation Details

Uses a flood fill algorithm to count adjacent white pixels as a single cell
Assumes the input file is correctly formatted
Does not perform extensive error checking on file opening or format

# Notes

This program is part of a course assignment (CSC209)
The original images were in BMP format, converted to text for easier processing
