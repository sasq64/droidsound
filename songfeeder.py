#!/usr/bin/python

import sys
import struct
import string
import socket
import time
import thread
import os

from array import array
from select import *
from threading import *
from copy import copy


class ClientSession(Thread) :

	def __init__(self):
		Thread.__init__(self)
		self.doquit = False

	def run(self) :
		print "Starting client thread"
		self.init()
		self.doquit = False
		while not self.doquit :
			self.update()
		if self.sock :
			self.sock.close()

	def update(self) :
		
		if not self.sock :
			thread.exit()
			return False
		try :
			s0,s1,s2 = select([self.sock],[],[], 0.5)
		except :
			self.close()
			return False
		if s0 :
			try:
				line = self.sock.recv(8192)
			except socket.error:
				self.close()
				return False
			if not line :
				self.close()
				return False
			self.handle_line(line)
		return True
	
	
	def handle_line(self, line):
		pass
	
	def handle_disconnect(self):
		pass
	
	def close(self):
		if self.sock :
			print "Closing socket"
			self.sock.close()
			self.sock = None
		self.handle_disconnect()
		self.doquit = True


class Server :
	def __init__(self, port):
		self.port = port
		self.start()
		
	def start(self):
		pass
	
	def run(self):
		sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) 
		sock.bind(('', self.port))
		sock.listen(5)
		
		while True:
			s0,s1,s2 = select([sock],[],[], 0.2)
			if s0 :
				print "Trying to accept"
				try:
					newsock,peer = sock.accept()
					#newsock.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE,1)
					print "New connection from " + peer[0]
					t = self.handle_connection(peer)
					if t :
						t.server = self
						t.sock = newsock
						t.start()
				except socket.error:
					print "Failed to accept"





class TestSession(ClientSession)  :	
	
		
	def init(self) :
		self.rootDir = "/home/sasq/iconmax"
		self.curDir = "/"
		self.files = None
		pass
	
	def handle_line(self, line):
		print line
		curdir = self.rootDir + self.curDir		
		if not self.files :
			self.files = os.listdir(curdir)  
		
		cmds = line.strip().split()
		if cmds[0] == 'ls' :
			for f in self.files :
				self.sock.send(f + '\n')
		elif cmds[0] == 'cd' :
			try :
				offset = int(cmds[1])
				if offset == -1 :
					pass
				elif offset >= 0 and offset < len(self.files) :
					newdir = curdir + self.files[offset]
					if os.access(newdir, os.F_OK) == True :
						newdir = self.curDir + self.files[offset] + '/'
						self.files = os.listdir(self.rootDir + newdir)  
						self.curDir = newdir
			except :
				self.sock.send('ERROR\n')
		elif cmds[0] == 'dl' :
			try :
				offset = int(cmds[1])
				name = self.files[offset]
				f = open(curdir + name)
				data = f.read()
				self.sock.send('FILE %s %d\n' % (name, len(data)))
				self.sock.send(data)
			except :
				self.sock.send('ERROR\n')
		elif cmds[0] == 'path' :
			self.sock.send(self.curDir + '\n')
		elif cmds[0] == 'get' :
			path = cmds[1].split('/')
			realpath = []
			for p in path :
				print p
				if len(p) == 0 :
					break
				if p[0] == '.' :
					break
				if p.find(':') != -1 :
					break
				if p.find('\\') != -1 :
					break
				realpath.append(p)
				
			newpath = '/'.join(realpath)
			print newpath + " vs " + cmds[1]
			if newpath == cmds[1] :
				newpath = self.rootDir + '/' + newpath 
				print newpath
				f = open(newpath)
				data = f.read()
				self.sock.send('FILE %s %d\n' % (cmds[1], len(data)))
				self.sock.send(data)
		elif cmds[0] == 'quit' :
			self.close()
		else :
			self.sock.send('WHAT\n')

		

class FileServer(Server) :
	
	def start(self):
		self.sessions = []
	
	def handle_connection(self, peer):
		t = TestSession()
		self.sessions.append(t)
		return t
	
	

def main(argv) :	
	server = FileServer(3333)
	server.run()


if __name__ == "__main__":
	main(sys.argv[1:])
