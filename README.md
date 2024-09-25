Rendering requirements:
- [x] Rendering Julia sets passing different parameters through the CLI
- [x] Rendering the Mandelbrot set through the CLI
- [x] BONUS Rendering another set through the CLI
- [ ] Use colors to show depth of each fractal (meaning how many iterations it takes to go to chaos, infinity)

Graphical interface requirements:
- [ ] Display the image in a window (using MiniLibX)
- [ ] Mouse wheel zooms in and out
- [ ] BONUS Zoom follows the actual mouse position (EVENT)
- [ ] BONUS Moving the view by pressing the arrows keys (EVENT)
- [ ] Pressing ESC must close the window and quit the program (EVENT)
- [ ] Clicking on the cross on the window’s frame must close the window and quit the program (EVENT)

Input handling requirements:
- [ ] Each kind of set, Julia sets (handles more parameters to differentiate which set), Mandebrot and another one will be input by the user on the CLI
- [ ] If user inputs invalid parameter, the program displays a list of available parameters and exits properly

Files:
- [ ] Makefile
  - [x] NAME = fractol
  - [ ] all
  - [ ] clean
  - [ ] fclean
  - [ ] re
- [ ] fractol.h
  - [x] include MiniLibx
  - [x] #include <unistd.h> for open, close, read, write
  - [x] #include <stdlib.h> for malloc, free,
  - [x] #include <stdio.h> for what?
  - [x] #include <math.h>
  - [ ] structures (which ones?)
  - [ ] macros? (which ones?)
- [ ] main.c
  - [ ] main function should take different parameters
  - [ ] main function should act as a high-level overview of the program's flow
- Modularization
  - [ ] Which modules do I need? How can I know that? I realize it would be good to have one for handling events, like mouse wheel, mouse position, and arrows, maybe one for initializing the window and handling which parameters are going to be send to the graphic interface, one for handling the complex equations to add pixel by pixel on the image on the window of the graphic interface. So that would be events.c, init.c, equations.c. But actually I still feel a bit lost on how to determine that, should I start writing the code (or even a pseudo code) on the main.c first and then start modularizing or should I try to modularize from the get go?
