# MiniRT
A basic raytracer made as a student project at 42 São Paulo.

# Work History

August 14th 2020 - Started building the basic functions and structures to open a file, parse its content and process the information accordingly.

August 17th 2020 - Cleaned up the Makefile a little bit, so that .o files will go on their own folder and it keeps Libft as it's own submodule so it can be updated/modified easily. Doing some more work on the file parsing structure, and managed to get information from a file and put it on a struct to use later, plus some very basic error returns for invalid file structures.

August 18th 2020 - Integrated file parsing functions with MiniLibX functions to use information contained on a file to set the resolution of an output window.

August 19th 2020 - Restructuring some functions to comply with The Norme. Integrated get_next_line to libft.

August 20th 2020 - Wrote the functions needed to parse ambient lighting parameters from an input file, and right now what they do is set the color of the output window. Having trouble with The Norme because of error messages being too long, and functions having more than 25 lines. We need to figure out a more succint way to write error messages. Also, we need to code our own ASCII-to-Float function, since we are forbidden to use the one from stdlib.h.
