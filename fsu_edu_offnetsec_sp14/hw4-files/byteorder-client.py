# this file is tab-delimited with a tab-space of 2

# client program to interact with byteorder.x
# parts of the program not finished and need to be filled in by the student

import socket
import struct

HOST	=	'localhost'	# name of the host machine (localhost is fine)
PORT	=	0						# port of the service running (will not be 0)

# grab the message structure from server
def get_msg_text(s):
	# grab value
	buff = s.recv(4)
	t = struct.unpack(">I", buff);

	# grab data
	buff2 = s.recv(44)
	l,d = struct.unpack("<I40s", buff2)
	
	return t[0],l,d

# grab the question structure from server
def get_question(s):
	# grab initial portion of question header
	buff = s.recv(1)
	e = struct.unpack("c", buff)
	
	# grab rest of message (value to be converted)
	d = s.recv(11)
	return e[0],d

# ask question to user
def ask_question(e, d):
	n = ''
	if e == '<':
		n = 'little-endian'
	else:
		n = 'big-endian'
	print 'Please return the value, {0}, as an integer in {1} value.'.format(d, n)

######### IMPLEMENT THIS FUNCTION #########
# answer the question to the server
def send_answer(s,e,d):
	pass	# delete this and fill with your implementation
######### IMPLEMENT THIS FUNCTION #########

# main program
def main():
	finished = 0x00

	s = socket.socket()
	try:
		s.connect((HOST, PORT)) 

		# grab intro message
		t,l,d = get_msg_text(s)
		print d	

		while (finished < 0x02):
			# get byte-order question
			e,d = get_question(s)

			# parse data to display to user
			ask_question(e, d)

			# send data back to the server to check -- IMPLEMENT THIS FUNCTION
			send_answer(s,e,d)
		
			# find out if we are correct or incorrect
			t,l,d = get_msg_text(s)
			print d

			finished = t

		t,l,d = get_msg_text(s)
		print "Secret Value {0}".format(d)

	except socket.error:
		print "Failed to connect to server."

	s.close()
# start the program
if __name__ == '__main__':
	main()