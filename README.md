# echoTool

A console TCP/IP echo server app. Packets are echoed on the port specified by the user. Incoming packets' source IP address, source port, payload size (in bytes), and payload are displayed in the console. The app supports TCP/UDP protocols and multithreading, allowing echo function calls on multiple ports simultaneously.

### Motivation
I needed a simple UDP diagnostic tool to troubleshoot an FPGA ethernet project. I didnt know much C++ at the time, so this project was an opportunity to learn more of the basics, such as classes, basic networking, and even multithreading. If you like this app but are looking for more TCP/IP functionality, check out my [ethernetTool](https://github.com/JohnWSweeney/ethernetTool) repo. 

The udpSocket class (udp.h and udp.cpp) is a drop-in solution for anyone needing basic C++ UDP functionality. 

## Functions
The app opens a console window on startup. Enter the *command* keywords separated by a space. Commands are currently case-sensitive and must be lower-case.

## Echo Functions
### UDP Echo
To start or stop a thread running the udp echo function, enter:
> `echo start portNumber` <br/>
> `echo stop` <br/>

where *portNumber* is the port where you expect to receive packets. Received packets' source address/port, payload, payload size (bytes), and number of packets echoed since runtime are printed to the console.The echo function is threaded, so you can echo on multiple ports at the same time.

NOTE: I haven't yet figured out to control individual threads (assuming it's possible), so *echo stop* will terminate *all* active echo threads.

### TCP Echo Server
Similarly, to start or stop a thread running the TCP echo server, enter:
> `server start portNumber` <br/>
> `server stop` <br/>

### App Control
To stop all active threads, enter:
> `stop all`

To stop all active threads and exit the program, enter:
> `exit`

## Future Updates
- Command case-insensitivity.
- See my [ethernetTool](https://github.com/JohnWSweeney/ethernetTool) project repository. 

## Download
[echoTool v1.1.1](https://github.com/JohnWSweeney/echoTool/releases/download/v1.1.1/echoTool_v1_1_1.exe) [40 kB]

## ChangeLog
v1.1.1
- Sessions are now threaded.
- Added session and server classes.

v1.1.0
- Added tcp class and tcp echo server function/thread.

v1.0.4
- Updated error handling in udp class and echo, startEchoThread functions.
- Updated recvfrom buffer to maximum possible size of 65,527 bytes.

v1.0.3
- Each .cpp now has its own header.
- Moved echo function's atomic bool status variable to separate .h/.cpp files.
- Added console output of total packets echoed since runtime.
- Integrated start function into main(). 
- Added stop all threads function.

v1.0.2
- Compliled for "release" instead of "debug" (oops). 
- Added (rxReady < 0) condition to socketReadStatus function in udp.cpp to prevent looping in echo function on release build.