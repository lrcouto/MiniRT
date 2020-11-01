# MiniRT
A basic raytracer made as a student project at 42 São Paulo. It is currently a work in progress, and you can check the work history on the collapsible section below.

# How to Run It

MiniRT relies on its libft submodule and on the MiniLibX library to run.

On your terminal, run:

```
git clone http://github.com/lrcouto/MiniRT.git && cd MiniRT && git clone http://github.com/lrcouto/libft.git && git clone https://github.com/42Paris/minilibx-linux.git libs/minilibx-linux
```

Inside the libs directory on the MiniRT folder, you will find the MiniLibX library. Follow the install instructions contained on the library folder, then, on the root of the MiniRT directory, run *make*.

You can use *SANITIZE_L=true* or *SANITIZE_A=true* with make to compile the program with the *-fsanitize=leak* and *-fsanitize=address* flags respectively.

Run MiniRT with a .rt file as an argument.

# Work History
<details>
  <summary>Click to expand!</summary>

---

August 14th 2020 - Started building the basic functions and structures to open a file, parse its content and process the information accordingly.

August 17th 2020 - Cleaned up the Makefile a little bit, so that .o files will go on their own folder and it keeps Libft as it's own submodule so it can be updated/modified easily. Doing some more work on the file parsing structure, and managed to get information from a file and put it on a struct to use later, plus some very basic error returns for invalid file structures.

August 18th 2020 - Integrated file parsing functions with MiniLibX functions to use information contained on a file to set the resolution of an output window.

August 19th 2020 - Restructuring some functions to comply with The Norme. Integrated get_next_line to libft.

August 20th 2020 - Wrote the functions needed to parse ambient lighting parameters from an input file, and right now what they do is set the color of the output window. Having trouble with The Norme because of error messages being too long, and functions having more than 25 lines. We need to figure out a more succint way to write error messages. Also, we need to code our own ASCII-to-Float function, since we are forbidden to use the one from stdlib.h.

September 3rd 2020 - Created a system to handle error messages in a more convenient way, allowing us to store the messages themselves on an external file. Norme is still being troublesome.

September 4th 2020 - Finally fixed the code so it complies with The Norme, though the end result is a bit jumbled. Will add comments later. Wrote an AtoF function to replace the one from stdlib.h that we were forbidden to use. Also added some additional error verification, and we are now starting to write the code to handle the information regarding cameras, lights and polygons.

September 5th 2020 - Developed the functions to handle parameters regarding cameras, and all the error handling related to this task. Starting to work on integrating a camera linked list to our main scene struct. Having some trouble with pointers.

September 6th 2020 - Linked list holding values for cameras works correctly, and we're able to de-allocate it properly after using it. We also corrected all memory leaks up to this point, and made all our relevant code compliant with The Norme. We made a mistake interpreting the subject in regard to the ambient light input parameters, and must correct it in the near future.

September 8th 2020 - Streamlined functions regarding ambient light parsing and wrote functions regarding scene light parsing. Re-structured the library to make it more readable. Integrated our AtoF to libft.

September 10th 2020 - Sphere and plane parsing work, and the functions are already Norme compliant. Fixed some other minor issues with the file parsing structure, now allowing the program to read the file if you skip lines between parameters, which was a requisite in the subject.

September 11th 2020 - File parser is now finished. Tested it for memory leaks and NOrme compliance, and everything seems to be working accordingly. Now we can move to the actual raytracing part.

September 12th 2020 - Created function to verify if the input file extension is valid, and started implementing vector operations. Trying to reorganize the project a little bit but having a lot of trouble with the Makefile. Incredibly frustrating.

September 13th 2020 - After one poorly-slept night, Makefile now works to compile files in separate folders, allowing us to organize the project much better. Wrote vector operations and did initial tests on putting pixels on a canvas based on a vector trajectory.

September 26th 2020 - Wrote color normalizing operations, and some matrix operations. Lots of work to do still. Not Norme-complying at this point.

October 7th 2020 - Implemented matrix 3D operations, translation, rotation, scaling, shearing.

October 17th 2020 - Tested combined transformations and how to use them with MiniLibX to put pixels to the screen. Also played a bit with MiniLibX key hooks and loops for shits and giggles.

October 18th 2020 - Started on ray/sphere intersections, and created the structures and functions to handle this task. Streamlined our polygon structs to make them easier to use with the ray casting functions.

October 24th 2020 - Started to build the scaffolding for a linked list containing the data from every ray/poly intersection we are going to use, a way to identify those polys, and trying to ensure there are no memory leaks in this process.

October 27th 2020 - Further developed the linked list containing intersection data, and created a function to determine if a ray has "hit" an object based on intersection data. Dealt with the Norme and some memory leaks.

October 31st 2020 - Added MiniLibX - Linux as a submodule to ensure we always run the program with the most recent version of the library directly from the 42 repository. Implemented ray and sphere transformation functions and started our first tests with actual raytracing. Managed to render a constant-shaded sphere. Yay!

November 1st 2020 - Cleaned up our raycasting functions and fixed a pesky little bug caused by the computer not calculating floating point values correctly after a certain point. Fixed it by using the round() function since the difference was so minimal.

___

</details>
