# Lab 1 - Time and Forking Children

![](https://github.com/xdmtk/comp322-spring2020/blob/master/lab1/misc/labtest.gif)
### Introduction
This lab when executed forks a child process and collects various PID, return value, and running time
information, storing them in a struct representing the child and parent.

### Building 
Simply run the included Makefile using `make`. This should output an executable with the filename `time-4-baby-and-me`.

### Usage
```asm
./time-4-baby-and-me
```

### Documentation
All formal documentation is located in the header files. All code is documented inline as well.


### Activity log
```
commit bd21543616391b79a7e37378cbe8985095d8cb29
Author: Nick Martinez <nick@xdmtk.org>
Date:   Wed Feb 26 14:43:03 2020 -0800

    Add Makefile

commit 2ce9e4398a30ae381a5685f292926f262829ef5b
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Feb 25 23:25:51 2020 -0800

    Add newline to last line in output

commit fbb75ad3ab63eb43a984b817de92989c1e047924
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Feb 25 16:44:56 2020 -0800

    Used shared memory to fill child and parent structs

commit 6fa423dd2ef313988c717c6a6bbf0d14b3772d42
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Feb 25 15:16:15 2020 -0800

    Add all required information in run()

commit 7828cc9d9584ba7f0b9dbf4a5656adf4eb030368
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Feb 24 22:43:32 2020 -0800

    Add YCM config

commit 10da089515703ace06968b71d1deb7206aff6c6a
Author: Nick Martinez <nick@xdmtk.org>
Date:   Wed Feb 19 06:26:08 2020 -0800

    Encrypted files

commit 16c2d3e1c96caa6ab84fd911f7e222dfc2f54f67
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Feb 18 11:52:26 2020 -0800

    lab1 changes

commit 758423a1c74834fbfd35dcbcfc9bdfbc6efc26df
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat Feb 15 10:06:51 2020 -0800

    Basic parent/child process setup

commit b5d4b59ece95f628e4c7509c1e8ddda030088ada
Merge: eae0e24 8d4c2db
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat Feb 15 09:34:52 2020 -0800

    Merge branch 'master' of github.com:xdmtk/comp322-spring2020

commit eae0e248b8d9318f39e9835c8e717750d37203f6
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat Feb 15 09:34:44 2020 -0800

    Lab1 Initial commit
```
