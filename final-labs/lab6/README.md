# Lab 6 - Wack a Mole

![](https://github.com/xdmtk/comp322-spring2020/blob/master/lab6/misc/lab6.gif)

### Introduction

This lab contains the source for the Wack a Mole `spiritd` daemon and the `mole` program. By executing the `spiritd` executable,
the program launches a daemon that listens on a specified interval for the signals `USR1`, `USR2`, and `TERM`. After catching either
`USR1` or `USR2`, the daemon executes the `mole` binary with either the argument "mole1" or "mole2".

The `mole` binary writes to a logfile at the base of the users home directory either a string "Pop Mole1" or "Pop Mole2", depending
on the contents of the argument vector passed to it from the daemon program. 


### Building 

To build all targets 
```
make
```

To build only the daemon
``` 
make spiritd
```

To build only the mole
``` 
make moles
```

To clean build directory
```
make clean
```


### Usage

Begin by executing the `spiritd` with no arguments
```
./spiritd
```

Next grab the PID for the daemon via
```
ps -ax | grep "spiritd"
```

Now you can begin sending signals to the daemon via
```
kill -<SIGNAL> <PID>
```

Observe at the `/home/$USER` directory the creation of the logfile `lab6.log`

You can continously monitor this log file as signals are sent to the daemon by
```
tail -f ~/lab6.log
```


### Documentation
Code is heavily documented in the source files. 


### Activity Log 

```
commit 4da4e88303166679860c0dda8cfb58d21cff0e84
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Apr 27 15:06:43 2020 -0700

    Fix execve() issue, fix mole path issue, success on writing to log file

commit c78c30ac0d8982b370df1a04107977c4a8b8bf7b
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Apr 27 14:41:28 2020 -0700

    Debug execve() issue, needed a null terminator arg vector, and now work on getting the USER environment variable from the mole when called from a daemon

commit 626e390dbe2195797d6af0fbe1c1016a34fe3c0a
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Apr 27 13:30:54 2020 -0700

    Inspect execve issue on spiritd forks

commit dc282916bad6b2f2310d7d49506857d4b1294523
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Apr 27 12:48:34 2020 -0700

    Tidy up Makefile, build mole and spiritd

commit e5be82e3b3117768fd7cc9dfc8e9afa51b0a19f8
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Apr 27 12:37:47 2020 -0700

    Finish mole program, begin tests

commit 10e314d83fb5f87c6ec06f4355ce26a8ebad440a
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Apr 27 12:15:12 2020 -0700

    Add execve() calls to mole programs from spiritd signal response loop

commit c8c5577a11cce637e7b362f5c38e71841cbaaba7
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sun Apr 26 22:11:56 2020 -0700

    Test call to mole executable

commit 5216d7f27d96db2cec58c45d4fce70bbc12e6c3d
Author: Nick Martinez <nick@xdmtk.org>
Date:   Fri Apr 24 17:58:11 2020 -0700

    Find mole executable path for later calls to execve()

commit 93304a8198e2cf75d78638cc2ce23ed2f8656b82
Author: Nick Martinez <nick@xdmtk.org>
Date:   Fri Apr 24 17:40:49 2020 -0700

    Forking conditions for mole execution

commit 4cb8ba8906eb1371d29642123a430c95398d4a70
Author: Nick Martinez <nick@xdmtk.org>
Date:   Fri Apr 24 13:40:37 2020 -0700

    Setup signal handlers, setup main daemon loop, setup daemon response to signals

commit 8783c344a0eff2b871b467fca35dad9d0185deae
Author: Nick Martinez <nick@xdmtk.org>
Date:   Thu Apr 23 17:14:27 2020 -0700

    Setup daemon init - File mask, fork and exit, sessions, chdir and fds

commit 7649c52b96dd14eb9f212cbbf0e03eb194099c77
Author: Nick Martinez <nick@xdmtk.org>
Date:   Thu Apr 23 16:34:18 2020 -0700

    Begin lab6
```
