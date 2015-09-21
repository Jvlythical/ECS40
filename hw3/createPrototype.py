#!/opt/python3/bin/python3

import re, os, sys

def main():
	path = "mscp.cc"
	fp = open (path, "r")
	file_size = os.stat(path).st_size
	pattern = ".*(?=\n{)"
	pattern2 = "(?<=\n).*\n{([^}])*?board(.|\s)*?}(?=\n\n)"
	content = fp.read (file_size)

	function_ar = []
	function_str = ""
	header_ar = []
	header_str = ""

	while 1: 
		functions = re.search (pattern2, content)

		if (functions):
			function = content[functions.start():functions.end()]
			content = content[functions.end():]
			function_ar.append (function)
			
			header = re.search (pattern, function)
			
			if (header):
				save = function[header.start():header.end()]
				header_ar.append (save)
		else: 
			break;

	for i in range (0, len (header_ar)):
		header_str = header_str + header_ar[i] + '\n'

	for i in range (0, len (function_ar)):
		function_str = function_str + function_ar[i] + '\n'
	
	fp = open ("function.h", "w+")
	fp.write ("%s" % function_str)
	#fp = open ("test2.h", "w+")
	#fp.write ("%s" % header_str)

if (__name__ == "__main__"):
	main ()
