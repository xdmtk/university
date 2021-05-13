# Lab 7 - Asynchronous Elephant

![](https://github.com/xdmtk/comp322-spring2020/blob/master/lab7/misc/lab7.gif)

### Introduction

This lab contains the source for the _Asynchronous Elephant_ lab, utilzing the `aio_**()` functions 
to read/write to optimize matrix scalar addition. 

This lab builds two executables. One program,`matrix_gen` to generate a matrix of a given size, and another,
`matrix_add` to read in the matrix of a given size, at intervals of a given block size, and add a randomly
generated scalar to each number in the matrix, outputting a new matrix.

NOTE: As it appears to state in the Lab instructions, the benefits of asynchronous operations seem to be
cancelled out by the fact that the actual matrix addition code is still synchronous. This means that,
matrix addition on a block cannot be executed immediately after a call to `aio_read()`, because 
the asynchronous nature of the call `aio_read()` cannot guarenteee the block has completed reading 
by the time a synchronous call to `matrix_add()` is made. 

In this code, this issue is offset by busy waiting on `aio_error()`, until it returns a value that is NOT 
`EINPROGRESS`, indicating that the read/write operation has completed. However, this also means the code,
at the end of the day, operates as if it were synchronous code. 



### Building 

To build all targets
```
make
```

To build just the matrix generation binary
```
make matrix_gen
```

To build just the matrix addition binary
```
make matrix_add
```

To clean the build directory 
```
make clean
```


### Usage

The matrix generation binary outputs a formatted matrix to `stdout`. Ideally this output should be 
redirected to a file for the `matrix_add` program to read. 

This can be done by
```
./matrix_gen [size] > [matrix_file]
```

To operate the matrix additon program, the size and block size must be specified. Likewise you must also
redirect the contents of the matrix file to `stdin` of the program.
```
./matrix_add [size] [block_size] < [matrix_file]
```

Likewise you may want to output the contents of the `matrix_add` program to a file. The lab instructions
say to use the `>` operator for indirection, though for this program you may need to use the `>>` operator instead
because the write operations get `fsync`'d after each write, and may flush the buffer too soon, resulting 
in a file with only a block size worth of the matrix. 


### Documentation
Code is heavily documented in the source files. 


### Notes
For both the `matrix_gen` and `matrix_add` programs, there was no format specified for how the matrix 
should look like, except for that the format should be compatible with both programs. 

The intuitive format might have been to generate a square, maybe something that looks like 
```
1   2   3   4   5   6 
7   8   9  10  11  12
13  14  15 16  17  18
```

But I decided against that because accounting for the newline characters in determining 
how many bytes to read for a block becomes more complicated than necessary. 

Because of this, my file format is simply 4 byte width entrys for every number, indicating columns.
Those entry are padded with spaces when the max value of the number does not take up all 4 digits.
The rows are implied by the matrix generation program when the size is specified. 

This makes reading blocks and parsing their contents much easier.


### Activity Log 
```
commit df93aefe5a2b595d87c94a820a4a6d3bec3b2ce3
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue May 5 17:07:55 2020 -0700

    Successful write out to stdout - Nearly finished

commit dae34608a02e7935620cf9209bb823c167363e50
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue May 5 16:33:01 2020 -0700

    Turns out aio_write() buffer was NOT full, infact, it was getting zeroed out every time I converted a read-bound aiocb struct to a write-bound struct, also needed to aio_fsync()!

commit 70c63f00b64e5ea57c7b453f762316d97388ae03
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat May 2 17:47:36 2020 -0700

    Need to figure out why aio_write() to STDOUT_FILENO with full buffer produces no output

commit 9f06ab0278cd2c398960f2a17679e94074b0e1e5
Author: Nick Martinez <nick@xdmtk.org>
Date:   Wed Apr 29 14:16:31 2020 -0700

    Fix equivalence bug in set_aio_attributes causing fault on aio_buf

commit 5475d7d28da1e11e265ed9d435711b291c39cd8f
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Apr 28 18:04:39 2020 -0700

    Drain the pump by writing the last block

commit 3b15f84ce755d3c7d9dd88c4db2243e2663d366b
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Apr 28 18:01:24 2020 -0700

    Finish matrix_add function - Drawn out process of moving buffers around...

commit 0f5355ef9766c657aa19794edd905106d685014d
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Apr 28 17:46:44 2020 -0700

    Begin actual matrix_add function

commit dfb04cb0d7b816b59baba514f66403e37fc37c88
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Apr 28 17:39:08 2020 -0700

    Create an attributes setter for the aiocb structs based on read or write operations

commit cddb6391a2534a761e34cd643bc16e647e0f8102
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Apr 28 16:36:41 2020 -0700

    Begin matrix async processing loop

commit 03e4e3edac6fe85f6fec17ea308fa771d2541c05
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Apr 28 15:03:27 2020 -0700

    Begin matrix_add

commit d6cf5d4ecbc037a6239041b5de35765bb06395a9
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Apr 28 14:47:45 2020 -0700

    Simplify matrix gen columnns at 4 bytes each, no header since it specified as an argument for matrix_add

commit 39c28d064924454acb00919866d6554b78fccc1a
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Apr 28 14:21:57 2020 -0700

    Finish matrix generation, 6 byte cell blocks for each column and a 32 byte header line to indicate size X size content

commit 0ce321749f868d5e0b2b5bb5bce9aea24ca4813b
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Apr 28 14:12:35 2020 -0700

    Test Matrix gen, begin designing shared matrix file structure protocol

commit c1f61d95895d3da197593794e0793ef81d504d79
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Apr 27 22:43:56 2020 -0700

    Validate matrix generator CLI arguments

commit c217f6f4fb7c8b3a79811dcb1a570b9fbd69f0a0
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Apr 27 22:37:58 2020 -0700

    Begin lab 7 - Begin matrix gen program
```
