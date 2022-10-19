import time
import socket
import sys
import os

# Initialize soc to socket
soc = socket.socket()

# Initialize the host
host = "127.0.0.1"

# Initialize the port
port = 8080

# bind the socket with port and host
soc.connect((host, port))
print("Connected to Server.")

# receive the command from server program
command = soc.recv(1024)
command = command.decode()

# match the command and execute it on client system
if command == "open":
    print("Command is :", command)
    soc.send("Command received".encode())

    # #give the file name as input
    os.system('test.bat')