# QR-Code 
[![build](https://github.com/Project-QR-Code/QR-Code/workflows/C/C++%20CI/badge.svg)](https://github.com/Project-QR-Code/QR-Code/actions)


## How-To
Execute `make test` in the main directory to compile test.c file in tests folder, the executable is in the main folder. This file is used to test individual functions. Execute `make` to compile read.c and write.c in src, these are the main files which are used in production. Before pushing to GitHub execute `make clean`, this removes all executables and cleans the project.
## Project Structure
In the folder `/test` there is one main file where you can put the code to test individual functions. You can also add more files to that folder. In the `/src` folder there are two files, `read.c`, to read the QR-Code and `write.c`, to create the QR-Code. The `/lib` folder is here to store all the libraries that we need, also small utility functions belong there. You should make a new folder for every library and create a .h and .c file.

