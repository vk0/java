import os
import sys
import subprocess
chances = 4
end_prog = 0


def menu2(): 
	cidr = raw_input("Please enter the network cider or IP to be scanned EX:192.168.1.0/16 or 10.10.1.4 ")
	return cidr

def menu1(chances): 
	print "\n(1) Host Discovery: "
	print "(2) Port & Service Discovery (top ports only): "
	print "(3) Port & Service Discovery (All 65536): " 
	print "(4) OS Discovery: "
	print "(5) RUN ALL \n"
	
	choice1 = raw_input("What type of scan would you like to run? ")
	
	if choice1 == '3':
		print "\n******* If you are running this against a network range it will take a while! Best if used agaist a single IP or small range of addresses *******\n"
	if choice1 not in ("1", "2", "3", "4", "5"):
		if chances <= 1: 
			exit()
		chances = chances - 1
		print "Error, Please check your answer choice and try again: %d tries remaining: " % (chances)
		menu1(chances)
	else:
		print "Choice Successful" 
		return choice1
def menu3(chances, end_prog):
	if chances > 1:
		choice3 = raw_input("would you like to run another scan? (y or n) ")
		choice3 = choice3.lower()
		if choice3 not in ('y', 'n'):
			print "*** INPUT ERROR, Please enter either y or n ***"
			chances = chances - 1
			menu3(chances, end_prog)
	if str(choice3) == 'n':
		exit()
def scanner(cidr, choice1, chances):
	if choice1 == '1':
		subprocess.check_call(['nmap', '-n', '-v', '-PN', '-sn', '-PE', '-PP', '-T4', '-ohostlist.UP', cidr])
	elif choice1 == '2': 
		subprocess.check_call(['nmap', '-n', '-v', '-PN', '-sV','-oservices2',cidr])  
	elif choice1 == '3':
		subprocess.check_call(['nmap', '-n', '-v', '-PN', '-sV', '-p 1-65535', '-oservices3', cidr])
	elif choice1 == '4':
		subprocess.check_call(['nmap', '-n', '-v', '-Pn', '-O', '-oosversions', cidr])
	elif choice1 == '5': 
		subprocess.check_call(['nmap', '-n', '-v', '-PN', '-sn', '-PE', '-PP', '-T4', '-ohostlist.UP', cidr])
		subprocess.check_call(['nmap', '-n', '-v', '-PN', '-sV', '-p 1-65535', '-oservices3', cidr])
		subprocess.check_call(['nmap', '-n', '-v', '-Pn', '-O', '-oosversions', cidr])
	else:
		return
while (1):
	choice1 = menu1(chances)
	cidr = menu2()
	scanner(cidr, choice1, chances)
	menu3(chances, end_prog)



