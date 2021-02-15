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

November 11st 2020 - Small fixes. Connected sphere scaling to the input on the .rt file so we don't have to hardcode it, and made so the program closes correctly when you click the close window button.

November 12st 2020 - Starting work on a Phong reflection model. Created the underlying structures to handle light and color, and functions to handle surface normals and reflections.

November 14st 2020 - Lighting function works! We now have a render of a shaded sphere, using a Phong material model! Still need to do some cleanup, but it surely feels like hitting a milestone.

December 5th 2020 - Preparing the ground to build a full rendered scene. Refactored the way our intersections work so we can sort them more easily. 

December 6th 2020 - Huge struggle to sort a linked list, thanks to the confusing syntax that C has. A couple dozen segfaults later, we figured it out. Also streamlined our shader functions a little bit. A lot of the code feels bloated and needs refactoring, but we are getting some steady progress.

December 12th 2020 - Our raytracer now supports rendering multiple spheres, with multiple point light sources! We made it store data from all objects in the scene, even if they're not visible, as setup for a possible reflection/refraction feature, and it's currently renders inverted normals, but we want to make this toggleable. We also made sure everything was Norme-compliant and that we had no memory leaks.

December 13th 2020 - Started to implement functions to have an actual camera that can be moved and adjusted properly. Still untested, not Norme-compliant, and not functional.

December 29th 2020 - Preparing terrain to change our simple raycaster to an actual render function that will account for both camera positioning, camera FoV and pixel color. This will need a considerable amount of re-structuring. We also need to consider how to make MiniLibX work with multiple cameras and switch between them i.e. have multiple images stored. 2020 is almost over and this project is taking way longer than we expected.

January 1st 2021 - Fixed an error on sphere translation where our program wasn't calculating the center of the world correctly, and now we can render multiple spheres with different center points. Finished implementing a functional camera. Next step is casting shadows. Happy New Year!

January 3rd 2021 - We made a little loading bar for our program that prints the render progress on stdout. Now we can see if the program has crashed or if the render is just taking long.

January 10th 2021 - Our raytracer now casts shadows, though it only handles hard shadows from a point light and the visual effect is not as pretty as we'd like it to be. Might try to implement soft shadows later. We are starting to work on implementing planes.

January 16th 2021 - We found out that our parser has a couple mistakes in it and we have to rewrite some segments. Found out that we have a problem on our view transformation that causes an error when a specific camera orientation is input. We don't know why this happens yet. Frustrating.

January 23th 2021 - After bumping into several parser errors that we hadn't noticed before, we finally managed to implement and render a plane! Next step is to be able to rotate it, so our scenes can have "walls", "floors" and "ceilings".

January 24th 2021 - Plane rotation and translation working correctly, after a day of struggling with hard maths. Next step is refactoring the code a little bit, because the project is getting rather large, and implementing some side features, like the ability to save image files and deal with multiple cameras.

January 30th 2021 - We implemented squares, after struggling a bit to find a way to limit their boundaries for the renderer. We also, as a little treat for ourselves, decided to implement actual raytraced reflections, with rays bouncing from one object to the other. Manually limited the number of bounces to prevent our computers from exploding. Also started working on a way to save our renders as .bmp files. Feels like we're on the final stretch of this project and we can see the light at the end of the tunnel.

January 31st 2021 - Cylinders are now implemented and functional. Now triangles are the only mandatory primitive left to implement. Looking forward to seeing if our little raytracer can handle some more complex models.

February 2nd 2021 - Wrote the functions to have the option to save our render as a .bmp file. It was more straightforward than I thought it would be, which was a pleasant surprise.

February 4th 2021 - Triangles are implemented, and I can't wait to try our little raytracer on some more complex models!

February 6th 2021 - Took some time to fix the Norme, which is almost done except for some rendering functions that we are still going to tweak anyway. Tested our render on a classic Utah Teapot model and it worked decently, though it was painfully slow.

February 7th 2021 - Our raytracer now renders multiple cameras and is officially done! We still want to do some improvements to the parser so we can individually control material parameters in separate objects, and make it 100% norme-compliant, but this absolute gauntlet of a project is done now.

February 10th 2021 - Updated our parser to be able to control material properties of different objects separately. If no material parameters are input, the program will fall back on default values.

February 12th 2021 - Did some minor additions to the program. The user can now directly control the raytracing recursion limit through a new parameter on the .rt file, with a "bn" identifier followed by a single int between 0 and 12. Also fixed some very minor memory leaks, and made our loading bar a little prettier.

February 13th 2021 - Did a lot of testing and  error-proofing on our input system, and ironed out some last minute mistakes and errors on the structure of our program. Seems like it runs smoothly now, and we're preparing our scenes to deliver.

February 15th 2021 - Some final tweaks on the code, made it compliant with the latest version of MiniLibX, tested it on the 42 Linux VM, and double checked the Norme and memory leaks. Seems like everything is working, and we are now ready to turn in!
___

</details>
