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
Without arguments, the executable will read a filename from `stdin`, otherwise the program will parse the
included file path, and if the file path is valid, proceed to parse text from the file.

### Documentation
All formal documentation is located in the header files. All code is documented inline as well.


### Notes
**Buffer Size**: The maximum amount of characters that can be parsed by the program is 65536. The specification 
doesn't say too much about being robust, so I decided to implement a fixed sized buffer instead of a 
dynamically resized container. 


### Activity log
```asm

commit 0c72cd8806c17d9c5a362f3a83d601d48087873c
Author: Nick Martinez <nick@xdmtk.org>
Date:   Fri Feb 7 13:54:41 2020 -0800

    Update parse methods to read only from file, and use stdin for naming the file, instead of parsing tokens

commit ec4f2b674867ad32fb8a9a767918dd1323397071
Author: Nick Martinez <nick@xdmtk.org>
Date:   Wed Feb 5 12:05:38 2020 -0800

    Remove unused define directives and unused functions

commit 9a1ffeeb86b4c2bfdc7e705b36cbfc9b2ea5c65d
Author: Nick Martinez <nick@xdmtk.org>
Date:   Wed Feb 5 12:02:45 2020 -0800

    Make input more robust against delimiters, specify sources in make file

commit 687dedddf7963389b989ae44101762e1675d16ec
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Feb 4 08:19:05 2020 -0800

    Update README

commit ab208c028c07713c037c96d592e9019600ec958c
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Feb 3 22:34:42 2020 -0800

    Allow for newline within input file

commit 41169faadb21e8b2200f69368e5d357cd3cf7ee5
Author: Nick Martinez <36802059+xdmtk@users.noreply.github.com>
Date:   Mon Feb 3 22:27:48 2020 -0800

    Update README.md

commit 09ca2f180fcd8c5e5f645bd686fd3fe9f7907ce8
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Feb 3 22:26:31 2020 -0800

    Add README

commit 3465ed59c676de4284f5012cdfdf9ec2fa91b39d
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Feb 3 16:25:30 2020 -0800

    Implement read() call wrapper

commit 885031aedd3b6b200bb9649c5c7fe56df1977a76
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Feb 3 15:08:39 2020 -0800

    Ignore the left most bit and drop T-Error

commit 800fc077e5c36e395d347889b2e15ac5e40f5838
Author: Nick Martinez <nick@xdmtk.org>
Date:   Wed Jan 29 18:45:17 2020 -0800

    Update CMake and remove unused includes

commit d3127a90bc748417bb483c78d0aac6b8c4c8b85e
Author: Nick Martinez <nick@xdmtk.org>
Date:   Wed Jan 29 18:40:04 2020 -0800

    Basic makefile

commit a06f1f7d552e94012c2b3ff4a4f434f4d3d01931
Author: Nick Martinez <nick@xdmtk.org>
Date:   Wed Jan 29 11:40:09 2020 -0800

    Add comments

commit bd61e1c1e27243d8ecd44f716cc94b41609c7234
Author: Nick Martinez <nick@xdmtk.org>
Date:   Wed Jan 29 11:33:54 2020 -0800

    Break for newline on stdin processing

commit 8958d6866abfe3c7e8244c9f76602b05f6ab32fe
Author: Nick Martinez <nick@xdmtk.org>
Date:   Wed Jan 29 11:29:33 2020 -0800

    Revise continuous dynamic allocation to chunk based allocation

commit dbed8896454a6a89fd74d496c72b7306daffd81b
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Jan 28 20:51:50 2020 -0800

    Add stddef include for size_t

commit 038a466bd2e20568f78e5cd1f449fbfe02f60c6b
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Jan 27 16:12:03 2020 -0800

    Comments, reverse binary string output, and safely parse short tokens

commit 850e061061f6f74616889c8d1d918c59c2252f5e
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Jan 27 15:43:54 2020 -0800

    Reverse binary string output

commit f44e24a7dc15ab8d9b59dbfa90a00e2dbee841e4
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sun Jan 26 15:32:23 2020 -0800

    Implement table printer

commit 7a068e3a6dc8a6d6c2fae069a3adbe667bce322e
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sun Jan 26 20:33:56 2020 -0800

    Add null termination on binary strings

commit 7b37c7dddaf7dd59d046008ef160d69e5591715f
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat Jan 25 15:49:47 2020 -0800

    Implement binary string get function

commit 56c23cb7b0e89245be80a7e23e0a230e52b8e7b1
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat Jan 25 15:45:19 2020 -0800

    Begin printer representation implementation

commit 4ee0e63caff960927d3049690153c5ba5657ad4d
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat Jan 25 14:12:19 2020 -0800

    Begin converter implementation

commit 66fbbb9946c55cddffef7b720067170569dd5511
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat Jan 25 13:18:56 2020 -0800

    Handle parse failures

commit 0d30d490bc688b36103f612af5c2fca7a80806b2
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat Jan 25 13:13:26 2020 -0800

    Implement stdin parser

commit 236b80bae9bffd25af42f9995aaf159c62c35058
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat Jan 25 13:07:24 2020 -0800

    Organize file structure, separate parsing functions, add stdin parser signature

commit cbd9da1f82c7a0fa6c29e9c3b414fe44bb8e6c57
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat Jan 25 12:15:38 2020 -0800

    Add comments

commit 48a68f1d8e850f1292736cf4dee355c9709bea45
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat Jan 25 10:55:58 2020 -0800

    Reorganize file structure for multiple lab assignments

commit e6a147a175cdbfa483a80bdae34d76479efb1a1a
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat Jan 25 10:53:12 2020 -0800

    Initial commit - Lab0 - Add basic file read and token parsing function
```
