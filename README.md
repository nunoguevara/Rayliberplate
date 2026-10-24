# Rayliberplate🍽️
A convenient, minuscule, QoL-first, easy-to-use unofficial wrapper for raylib's window initializations!

## Highlights
- Fast⚡
- Minimum boilerplate🍽️
- QoL-oriented🌱
- Very lightweight🪶
- C++ compatible🔗

## Available functions
`SetWindowPosCenter(void);`
Centers the window on its current monitor.

`InitRelativeWindowPercentage(double pct_covx, double pct_covy, const char *title);`
Initializes a window using percentages of monitor's dimensions.
E.g,:
`InitRelativeWindowPercentage(75, 50, "My Game");`
Initializes a window titled "My Game" with the width of 75% of the monitor's dimension, and the height of 50% of the monitor's dimension.

`InitRelativeWindowDivisor(double div_covx, double div_covy, const char *title);`
Initializes a window using divisors of the monitor's dimensions.
E,g:
`InitRelativeWindowDivisor(1, 2, "My Game");`
Initializes a window with the width of monitor's width divided by 1 and the height of monitor's height divided by 2.

`SetWindowSizePercentage(double pct_covx, double pct_covy);`
Set the window size using percentages of monitor's dimensions, it requires a window to be initialized first.
E,g:
`SetWindowSizePercentage(75, 50);`
Set the window size to the 75% of monitor's width and 50% of monitor's height.

`SetWindowSizeDivisor(double div_covx, double div_covy);`
Set the window size based on the divisor of the monitor's dimension.
E,g:
`SetWindowSizeDivisor(1, 2);`
Set the window's width to the monitor's width divided by 1, and the window's height to the monitor's height divided by 2.

# Installation Process📂
## Dependencies
To install Rayliberplate, you need these to be installed first below:
1. Git
2. CMake
3. [raylib](https://github.com/raysan5/raylib) by [raysan5](https://github.com/raysan5)

## Linux🐧
First, you may need to clone the GitHub repository first with the provided command below:
```Shell
git clone https://github.com/nunoguevara/Rayliberplate.git
cd Rayliberplate
```

Then, you can either configure Rayliberplate normally (commonly `usr/local` on Linux) with:
```Shell
cmake -S . -B build 
```
Or,  for installation under `/usr`, you can use:
```Shell
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=/usr
```
After that, you are ready to use the library and compile your code with it (Don't forget to include the header or the header's directory, and link the library or directory of the library)!

E,g. (if Rayliberplate is installed under `/usr/local/`):
```Shell
cc main.c -o my_game \
  -I/usr/local/include \
  -L/usr/local/lib \
  -lrayliberplate -lraylib
```
