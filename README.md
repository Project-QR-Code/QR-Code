# QR-Code 
[![build](https://github.com/Project-QR-Code/QR-Code/workflows/C/C++%20CI/badge.svg)](https://github.com/Project-QR-Code/QR-Code/actions)


## How-To
### Steps to run

1. Run `make` (linux terminal) in the root folder of the project
2. Execute `write` executable in the root folder to create QR-Code
3. Execute `read` executable in the root folder to read QR-Code

Execute `make test` in the main directory to compile test.c file in tests folder, the executable is in the main folder. This file is used to test individual functions. Before pushing to GitHub execute `make clean`, this removes all executables and cleans the project.

## Software used

- Documentation: Doxygen
- CI/CD: Github Actions

## Project Structure

Folders of the Project explained:

| Folder name  | Explanation                                                  |
| ------------ | --------------------- |
| **`/docs`** | Holds doxygen config file and documentation |
| **`/lib`**   | All the libraries and header files  (no external library used) (Libraries explained in table below) |
| **`/src`**   | Holds the main function, read and write files |
| **`/tests`** | Holds one test file with main function to test functions |


Library Functions in `/lib`:
| Folder name              | Explanation                                                  |
| ------------------------ | ------------------------------------------------------------ |
| **`/binaryConverter`**   | Utility functions to convert binary and decimal numbers      |
| **`/drawQr`**            | Functions to create a 2d matrix with QR-Code and bitmap image |
| **`/QRCode`**            | Holds struct of QR-Code model with data and information      |
| **`/QRCodeStructToRaw`** | Converts QR-Code model to raw array with ECC (Error Correction Codes) |
| **`/rawToQrCodeStruct`** | Converts the raw array back to a QR-Code model with the message in ascii |
| **`/readQr`**            | Reads raw data array out of bitmap image                     |
| **`/reedSolomon`**       | Implementation for the reed solomon code (implemented ourselfes) |

