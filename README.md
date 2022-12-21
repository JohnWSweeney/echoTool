# echoTool

A simple command line interface UDP echo server. Packets are echoed on a port specified by the user. Incoming packets' source IP address, source port, payload size (bytes), and payload are displayed in the console.

The app accepts three commands: start, stop, and exit.

Enter *echo start port number* to start the echo server on the desired port. For example:
> echo start 123
echoes packets on port 123.

echo stop

exit

Future updates:
- Client mode
- TCP support
