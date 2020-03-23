# Lab 3 - Catcher

![](https://github.com/xdmtk/comp322-spring2020/blob/master/lab3/misc/catcher.gif)
_catcher demo_

### Introduction

This lab contains the source for the `catcher` program. On exeuction, the user passes a space delimited list of valid signals (without the SIG prefix) 
to the program. The program then registers the CLI signal arguments against a unified handler that prints out the name of the signal caught, and
the time it was caught at. After handler registration, the program enters an infinite `pause()` loop, re-registering the signal handlers after
each signal caught (to catch unreliable signals that uninstall its handler after being caught). If `SIGTERM` was specified as a signal `catcher` should
handle, the program will exit naturally after `SIGTERM` has been caught and handled 3 times. 

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

```
./catcher { <SIGNAL_LIST> }
```

Where `SIGNAL_LIST` is a space delimited list of valid signals


### Documentation
Code is heavily documented in the source files. 


### Activity Log 
```
commit b0fc208bb493a412a45f97f98a641c81cc51f202 (HEAD -> master)
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Mar 23 09:42:20 2020 -0700

    Last minute addition to count total signals caught by program

commit 53367db8200b1913776db7f84500ae265be9ac62 (origin/master, origin/HEAD)
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Mar 23 09:28:39 2020 -0700

    Remove catcher executable

commit 67067a3d4c35c9a6f959d0dc324686ce931f1baf
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Mar 23 09:28:17 2020 -0700

    Decrypt Lab3

commit a7bca02ddbed51be267983e20b2f69ace3be3b19
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sun Mar 22 14:44:17 2020 -0700

    Add git log output to README and make demo gif

commit 508478358eaad85bf6a4766a0869a5c4fd560980 (HEAD -> master, origin/master, origin/HEAD)
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sun Mar 22 14:05:40 2020 -0700

    Re-register for unreliable signals, tidy up README

commit bb6b6ab7390c6646bf20b3264f592f8deae71deb
Author: Nick Martinez <nick@xdmtk.org>
Date:   Sat Mar 14 00:22:38 2020 -0700

    Unencrypt files

commit fd7a18bf378bc23db85e7556f9880fc0d4eaa768
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Mar 9 22:11:55 2020 -0700

    Add length variable to keep track of amount of signals parsed from CLI

commit 2786357b958aafe9b0cc481dfcfe651f526488b1
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Mar 9 21:41:27 2020 -0700

    Finalize lab3

commit c541928557ea0e4a62f31fd2f1931e2191642d2b
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Mar 9 19:25:51 2020 -0700

    Add signal table for indexing when registering signals

commit 1c9f3a910e6c623aba55fcc9dfcabadac894ec88
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Mar 9 15:15:48 2020 -0700

    Add signal argument validation and signal registration

commit 25ce667f54d1cfed88e8e01029ec77565d178f04
Author: Nick Martinez <nick@xdmtk.org>
Date:   Mon Mar 9 15:00:47 2020 -0700

    Begin Lab 3

```
