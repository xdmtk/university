#ifndef CHAT_SHELL_H
#define CHAT_SHELL_H
#include <string>

#define USER_PROMPT ">> "
#define DESCRIPTION_HELP "Display information about the available user interface options or command manual."
#define DESCRIPTION_MYIP "Display the IP address of this process. Note:The IP should not be your “Local” address (127.0.0.1). "\
"It should be the actual IP of the computer."
#define DESCRIPTION_MYPORT "Display the port on which this process is listening for incoming connections."
#define DESCRIPTION_CONNECT "This command establishes a new TCP connection to the specified <destination> at the specified <port no>. "\
"The <destination> is the IP address of the computer. Any attempt to connect to an invalid IP should be "\
"rejected and suitable error message should be displayed. Success or failure in connections between two "\
"peers should be indicated by both the peers using suitable messages. Self-connections and duplicate "\
"connections should be flagged with suitable error messages."
#define DESCRIPTION_LIST "Display a numbered list of all the connections this process is part of. This numbered list will include "\
"connections initiated by this process and connections initiated by other processes. The output "\
"should display the IP address and the listening port of all the peers the process is connected to. E.g., "\
"id: IP addressPort No.1: 192.168.21.2045452: 192.168.21.2154543: 192.168.21.2350004: 192.168.21.245000"
#define DESCRIPTION_TERMINATE "This command will terminate the connection listed under the specified number when LIST is used to "\
"display all connections. E.g., terminate 2. In this example, the connection with 192.168.21.21 should "\
"end. An error message is displayed if a valid connection does not exist as number 2. If a remote "\
"machine terminates one of your connections, you should also display a message. "
#define DESCRIPTION_SEND "(For example, send 3 Oh! This project is a piece of cake). This will send the message to the host on the connection "\
"that is designated by the number 3 when command “list” is used. The message to be sent can be up-to 100 "\
"characters long, including blank spaces. On successfully executing the command, the sender should display "\
"“Message sent to <connection id>” on the screen. On receiving any message from the peer, the receiver should "\
"display the received message along with the sender information. (Eg. If a process on 192.168.21.20 sends a message "\
"to a process on 192.168.21.21 then the output on 192.168.21.21 when receiving a message should display as shown: "\
"Message received from 192.168.21.20 Sender’s Port: <The port no. of the sender>Message: “<received message>”"
#define DESCRIPTION_EXIT "Close all connections and terminate this process. The other peers should also update their connection list by "\
"removing the peer that exits. "
class Shell {

public:
    enum ShellCommand {
        Help, GetIp, GetPort, Connect, ListConnections,
        TerminateConnection, SendMessage, InvalidCommand,
        EmptyCommand, QuitProgram
    };
    ShellCommand getUserCommand();
    void printHelpPage();
    std::string getLastUserInput() {return userInput;}

private:
    std::string userInput;

    inline void emitPrompt();
    std::string formatHelpPageArguments(std::string args);
};


#endif
