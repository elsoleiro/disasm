default:
	cl /c -Wall src/disasm.c /Fodisasm.o
	link /OUT:build/bin.exe disasm.o
