# CS429 - Chat Application

### Introduction 

Per the specifications noted in file `COMP429-PA1.pdf`, this project implements
a simple chat application in C++ for message exchange among remote peers. In this 
program, both client and server functionality are implemented. 


### Installation 

This application is implemented with no additional library dependencies outside of the
standard `pthread` library. As a result, the application can be built by simply running
the included Makefile at the root project directory.

```
make
```

This will produce an executable with the name `chat`. 


### Usage

Per the specifications, the program should be executed on the command line with 1 
CLI argument, indicating the port number the `chat` application should listen on for
incoming client connections. 

```
./chat <port no>
```

On startup, the user is presented with a shell prompt `>> ` and can then enter any 
commands the program implements, which can be found by executing

```
>> help
```


### Errors / Logging

This application has a logging interface which stores all notable debugging and error
information in a file located at the directory `~/.chatlogs/`. The log file will be
titled with the current date, and appended by the suffix `.log`

To follow the log trace during execution

```
tail -f ~/.chatlogs/10-26-2020.log
```

If today's date was 10/26/2020. 


### Contributions

##### Nick Martinez

* Overall program structure
* `Server` class/functionality
* `Client` class/functionality
* `Connector` class/functionality
* `Logger` class/functionality
* `Shell`  class/functionality
* `Signals` class/functionality
* Facade design pattern implementation
* Commands implemented:
    * `help`
    * `myip`
    * `myport`
    * `connect`
    * `send`
    * `exit`