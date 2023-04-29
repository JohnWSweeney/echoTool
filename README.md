# echoTool

A Windows console UDP echo server app. Packets are echoed on the port(s) specified by the user. Incoming packets' source IP address, source port, payload size (bytes), and payload are displayed in the console. App supports multithreading, allowing echo function calls on multiple ports simultaneously.

To start or stop a thread running the echo function, enter:
> *echo start portNumber*

> *echo stop*

To stop all active threads and exit the program, enter:
> *exit*

Commands are case-sensitive.

### Motivation
I needed a simple UDP diagnostic tool to troubleshoot an FPGA ethernet project. Acheiving that goal really leveled up my C++ skills, requiring me to learn classes, multithreading, basic networking, and more complex program stuctures.  

The udpSocket class (udp.h and udp.cpp) is a drop-in solution for anyone needing UDP functionality. 

### Future Updates
- See my ethernetTool project repository.

### Download ##
[echoTool v1.0.1](https://github.com/JohnWSweeney/echoTool/releases/download/v1.0.1/echoTool_v1_0_1.exe) [170 kB]
