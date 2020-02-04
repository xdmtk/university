# Lab 0 -  Making Sense of Ones and Zeros

![](https://github.com/xdmtk/comp322-spring2020/blob/master/lab0/misc/lab0.gif)
### Introduction
This lab should take for input the bit level representation of regular, non-extended 7 bit ASCII, and 
output a table with the corresponding 8 bit binary string, the ASCII character 
(or mnemonic indicated in the `ascii` manual page), the decimal value, and the parity of the 8 bit 
representation.

### Building 
Simply run the included Makefile using `make`. This should output an executable with the filename `lab0`.

### Usage
```asm
./lab0 <optional file path>
```
Without arguments, the executable will read characters from `stdin`, otherwise the program will parse the
included file path, and if the file path is valid, proceed to parse text from the file.

### Documentation
All formal documentation is located in the header files. All code is documented inline as well.


### Notes
**Buffer Size**: The maximum amount of characters that can be parsed by the program is 65536. The specification 
doesn't say too much about being robust, so I decided to implement a fixed sized buffer instead of a 
dynamically resized container. 

