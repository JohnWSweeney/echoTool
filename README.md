# echoTool

A simple command line interface UDP echo server. Packets are echoed on a port specified by the user. Incoming packets' source IP address, source port, payload size (bytes), and payload are displayed in the console.

The app accepts three case-sensitive commands: start, stop, and exit. 

Enter *echo start port number* to start the echo server on the desired port. For example,
> echo start 123

echoes packets on local port 123.

Enter *echo stop* to stop the echo server.

Ener *exit* to exit the app.

Future updates:
- Client mode
- TCP support
