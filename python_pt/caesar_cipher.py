#!/usr/bin/python
#python caesar_cipher.py OMQEMDUEQMEK
import sys

ctext = sys.argv[1]
alphabet = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
plaintext = ""
shift = 1

while shift <= 26:
 for c in ctext:
  if c in alphabet:
   plaintext += alphabet[(alphabet.index(c)+shift)%(len(alphabet))]
 print("Shift used: " + str(shift))
 print("Ciphertext: " + ctext)
 print("Plaintext: " + plaintext)
 shift = shift + 1
 plaintext = ""