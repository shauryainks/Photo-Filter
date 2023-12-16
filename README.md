# Image Filtering Program

This C program reads a bitmap image file, applies various filters, and writes the processed image to a new file. The filters include blur, grayscale, reflection, and sepia.

## Prerequisites

- C compiler
- Bitmap image file (BMP) as input
- Header file "helpers.h" containing the data structure definition (e.g., BITMAPFILEHEADER and BITMAPINFOHEADER) and function prototypes for image processing

## Usage

Compile the program using a C compiler:

```bash
gcc -o filter program.c helpers.c -std=c11 -lm
```

Run the program with the following command:

```bash
./filter [flag] infile outfile
```

- `[flag]`: Filter type - 'b' for blur, 'g' for grayscale, 'r' for reflection, 's' for sepia.
- `infile`: Input BMP file.
- `outfile`: Output BMP file.

## Program Flow

1. **Command Line Arguments:**
   - The program expects command line arguments specifying the filter type, input file, and output file.
   - Only one filter flag is allowed.

2. **File Handling:**
   - The input file is opened for reading (`"r"` mode), and the output file is opened for writing (`"w"` mode).
   - If the input file cannot be opened, an error message is displayed, and the program exits with an error code.

3. **Header Validation:**
   - The program reads the bitmap file header (BITMAPFILEHEADER) and information header (BITMAPINFOHEADER) from the input file.
   - It checks if the file format is supported by verifying specific header values.
   - If the file format is unsupported, an error message is displayed, and the program exits with an error code.

4. **Memory Allocation:**
   - Memory is allocated for a 2D array (`image`) to store the RGB pixel values of the image.
   - If there is insufficient memory, an error message is displayed, and the program exits with an error code.

5. **Image Reading:**
   - The program reads the pixel values from the input file into the allocated `image` array, considering padding for scanlines.

6. **Filter Application:**
   - Based on the provided filter flag, the program applies one of the following filters:
     - Blur (`'b'`): Applies a simple blur effect.
     - Grayscale (`'g'`): Converts the image to grayscale.
     - Reflection (`'r'`): Reflects the image horizontally.
     - Sepia (`'s'`): Applies a sepia tone to the image.

7. **Image Writing:**
   - The program writes the modified image data to the output file, including the file headers.

8. **Memory Deallocation:**
   - The memory allocated for the `image` array is freed.

9. **File Closure:**
   - Both the input and output files are closed.

10. **Exit Code:**
    - If the program executes successfully, it returns with an exit code of 0.
    - Otherwise, it exits with an appropriate error code indicating the encountered issue.

## Example Usage

```bash
./filter b input.bmp output_blurred.bmp
```

This command applies the blur filter to the input BMP file (`input.bmp`) and saves the result to the output file (`output_blurred.bmp`).

## License

This program is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
