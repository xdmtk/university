# Lab 4 - Rice Rice Rice

![](https://github.com/xdmtk/comp322-spring2020/blob/master/lab4/misc/dining-p.gif)

### Introduction

This lab contains the source code implementing a demonstration of the _Dining Philosophers_ problem. The source file `dining-p.c` builds an executable representing a single philosopher at the table, with a specified seat position and table size. 

While it is possible to execute the executable by itself, in order to represent the Dining Philosphers problem accurately, multiple instances of the binary must be running at the same time with similar position/table size parameters.

The included `launch-philosophers.sh` script handles this by automatically executing the number of philosphers and their respective positions based on a table size parameter given to the script.


### Building 

To build: 
```
make
```

To clean generated files and executable:
```
make clean
```



### Usage

To launch the dining philosophers simulation
```
./launch-philosphers.sh [table-size] 
```

To kill the running philosophers, the `launch-philosophers.sh` script generates another script, `kill_philosophers`, that issues the `kill` command with the corresponding process group ID for the philosopher processes. 

To stop the simulation
```
./kill_philosophers
```

### Documentation
Code is heavily documented in the source files. 


### Activity Log 


```
commit f55a4c47d3c0dfac7a4fb4691c2361351f236dd1
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Apr 20 09:20:51 2020 -0700

    Decrypt Lab4

commit 06bb537d4e3370f086f49a914ef1eae8b0bc53b0
Author: Nick Martinez <nick@xdmtk.org>
Date:   Thu Apr 16 21:57:28 2020 -0700

    Update README, add demo gif, and add comments to bash scripts

commit 8ac62592bd091398c4e9db6c533f58b7f5c724dc
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sun Apr 12 22:39:33 2020 -0700

    Add manual process group ID set

commit a82a479618904863ddeba394a83eeceb36fbb14d
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Apr 7 17:15:55 2020 -0700

    Add kill philosophers exit script +  busy wait on the allocator semaphore

commit d9116bf4b498a984672225d13a97a1fdd26ec4e8
Author: Nick Martinez <nick@xdmtk.org>
Date:   Tue Apr 7 16:29:25 2020 -0700

    Add Hold and Wait function, block until chopstick critical section has been completed

commit 50fde4383c8a9352525a5a8d160536a2f4248aaa
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sun Apr 5 21:28:29 2020 -0700

    Add Launch Philosophers bash script, echo group id and kill command

commit fe5938b9e527ac04c7351bd864d4b80432dc8f0d
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sun Apr 5 16:53:57 2020 -0700

    Link semaphore wait/post to eat/think functions

commit cf023fbd39da57e0fe163b512039d9718944e785
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sun Apr 5 16:20:53 2020 -0700

    Add semaphore creation, closing, and unlinking

commit 3685725823d64522511de2adf2231d1e2e889718
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sun Apr 5 14:41:11 2020 -0700

    Add handler for SIGINT (CTRL-C exits)

commit b2828454b621dcc85f8beea587c2fc93b372713f
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sun Apr 5 14:09:47 2020 -0700

    Add Eat/Think functions, add signal handler for sig term

commit cec69d45f63a5e2e7b27ef0a1832de68ed475737
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat Apr 4 17:06:00 2020 -0700

    Initial commit on Lab 4
```
