# echoTool

A Windows console UDP echo server app. Packets are echoed on the port specified by the user. Incoming packets' source IP address, source port, payload size (in bytes), and payload are displayed in the console. The app supports multithreading, allowing echo function calls on multiple ports simultaneously.

### Motivation
I needed a simple UDP diagnostic tool to troubleshoot an FPGA ethernet project. I didnt know much C++ at the time, so this project was an opportunity to learn more of the basics, such as classes, basic networking, and even multithreading. If you like this app but are looking for more TCP/IP functionality, check out my [ethernetTool](https://github.com/JohnWSweeney/ethernetTool) repo. 

The udpSocket class (udp.h and udp.cpp) is a drop-in solution for anyone needing basic C++ UDP functionality. 

## Functions
The app opens a console window on startup. Enter the *command* keywords separated by a space. Commands are currently case-sensitive and must be lower-case.

## Echo Function
To start or stop a thread running the echo function, enter:
> *echo start localPortNumber* <br/>
> *echo stop* <br/>

where *localPortNumber* is the port on your PC where you expect to receive packets. The echo function is threaded, so you can echo on multiple ports at the same time.

### App Control
To stop all active threads, enter:
> *stop all*

To stop all active threads and exit the program, enter:
> *exit*

## Future Updates
- See my [ethernetTool](https://github.com/JohnWSweeney/ethernetTool) project repository. 

## Download ##
[echoTool v1.0.3](https://github.com/JohnWSweeney/echoTool/releases/download/v1.0.3/echoTool_v1_0_3.exe) [32 kB]

## ChangeLog <br/>
v1.0.3
- Each .cpp now has its own header.
- Moved echo function's atomic bool status variable to separate .h/.cpp files.
- Added console output of total packets echoed since runtime.
- Integrated start function into main(). 
- Added stop all threads function.

v1.0.2
- Compliled for "release" instead of "debug" (oops). 
- Added (rxReady < 0) condition to socketReadStatus function in udp.cpp to prevent looping in echo function on release build.