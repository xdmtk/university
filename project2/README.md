# CS429 - Distance Vector Routing Application

### Introduction 

Per the specifications noted in file `COMP429-PA2.pdf`, this project implements
a networking application in C++ for implementing Distance Vector Routing among remote peers. 
In this program, both client and server functionality are implemented. 


### Installation 

This application is implemented with no additional library dependencies outside of the
standard `pthread` library. As a result, the application can be built by simply running
the included Makefile at the root project directory.

```
make
```

This will produce an executable with the name `dvr`. 


### Usage

Per the specifications, the program should be executed on the command line with 2 
CLI arguments, indicated by the flags `-t` and `-i`

```
./dvr -t <topology file path> -i <update interval>
```

On startup, the user is presented with a shell prompt `>> ` and can then enter any 
command the program implements. These commands can be found in the project specifications
file. 


### Errors / Logging

This application has a logging interface which stores all notable debugging and error
information in a file located at the directory `~/.dvrlogs/`. The log file will be
titled with the current date, and appended by the suffix `.log`

To follow the log trace during execution

```
tail -f ~/.dvrlogs/11-30-2020.log
```

If today's date was 11/30/2020. 


### Contributions

##### Nick Martinez

* Overall program structure
* Recycled program infrastructure from Project 1
    * `Server` class/functionality
    * `Client` class/functionality
    * `Connector` class/functionality
    * `Logger` class/functionality
    * `Shell`  class/functionality
    * `Signals` class/functionality
    * Facade design pattern implementation
* Topology File parser (`Topology` class base)
* Startup Connector - Waits for all clients to connect before starting Vector Routing routines
* Routing Updates - Base implementation (`Updater` class base) - Kyle improved/fixed bugs with implementation
* Commands implemented:
    * `step`
    * `update`

##### Gage Aschenbrenner

* Reworked invalid command handler from Project 1
* Commands implemented:
    * `display`
    * `crash`
    
##### Kyle Strem

* Reformatted routing table update behavior
* Created data structures and helper functions to quickly determine relative server ID
* Created `Message Received` functionality
* Improved QoL of the overall behavior of the program
* Commands implemented:
   * `packets`
