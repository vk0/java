import os
import sys

# script = sys.argv[0]
# ip = sys.argv[1]
# port = sys.argv[2]

# print "[+] The script name is: "+script
# print "[+] The IP is: "+ip+" and the port is: "+port

class Domain:
    def __init__(self, domain, port, protocol):
# Stores the variabled passed inside two variables
        self.domain=domain
        self.port=port
        self.protocol=protocol
# Defines a method to build a URL
    def URL(self):
        if self.protocol == 'https':
            URL = 'https://'+self.domain+':'+self.port+'/'
        if self.protocol == 'http':
            URL = 'http://'+self.domain+':'+self.port+'/'
        return URL
# Sets up a method to lookup resolve domain to IP using host command via os.system
    def lookup(self):
        os.system("host "+self.domain)

domain=Domain('google.com', '443', 'https')
dir(domain)
print domain.URL()
#domain.ip
print domain.port
print domain.protocol
print domain.lookup()