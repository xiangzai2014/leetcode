#输出DNS

import sys,socket
result=socket.getaddrinfo(sys.argv[1],None)
print (result) #(family, socktype,proto,canonname,sockaddr)
