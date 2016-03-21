/*
 * Simple app. to do memory accesses via /dev/mem.
 *
 *
 * Copyright (c) Richard Hirst <rhirst@linuxcare.com>
 * Copyright (c) Thomas Langer <thomas.langer@infineon.com>
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MEM_READ  0
#define MEM_WRITE 1
#define MEM_AND   2
#define MEM_OR    3

static void
usage (char *argv0)
{
	fprintf(stderr,
"Raw memory i/o utility - $Revision: 2.0 $\n\n"
"%s -v -1|2|4 -r|w|a|o [-l <len>] [-f <file>] <addr> [<value>]\n\n"
"    -v         Verbose, asks for confirmation\n"
"    -1|2|4     Sets memory access size in bytes (default byte)\n"
"    -l <len>   Length in bytes of area to access (defaults to\n"
"               one access, or whole file length)\n"
"    -r|w|a|o   Read from or Write to memory (default read)\n"
"               optional write with modify (and/or)\n"
"    -f <file>  File to write on memory read, or\n"
"               to read on memory write\n"
"    <addr>     The memory address to access\n"
"    <val>      The value to write (implies -w)\n\n"
"Examples:\n"
"    %s 0x1000                  Reads one byte from 0x1000\n"
"    %s 0x1000 0x12             Writes 0x12 to location 0x1000\n"
"    %s -2 -l 8 0x1000          Reads 8 words from 0x1000\n"
"    %s -r -f dmp -l 100 200    Reads 100 bytes from addr 200 to file\n"
"    %s -w -f img 0x10000       Writes the whole of file to memory\n"
"\n"
"Note access size (-1|2|4) does not apply to file based accesses.\n\n",
		argv0, argv0, argv0, argv0, argv0, argv0);
	exit(1);
}


static void
memread_memory(unsigned long phys_addr, void *addr, int len, int iosize)
{
	int i;

	while (len) {
		printf("%08lx: ", phys_addr);
		i = 0;
		while (i < 16 && len) {
			switch(iosize) {
			case 1:
				printf(" %02x", *(unsigned char *)addr);
				break;
			case 2:
				printf(" %04x", *(unsigned short *)addr);
				break;
			case 4:
				printf(" %08lx", *(unsigned long *)addr);
				break;
			}
			i += iosize;
			addr += iosize;
			len -= iosize;
		}
		phys_addr += 16;
		printf("\n");
	}
}


static void
write_memory(unsigned long phys_addr, void *addr, int len, int iosize, unsigned long value)
{
	switch(iosize) {
	case 1:
		while (len) {
			*(unsigned char *)addr = value;
			len -= iosize;
			addr += iosize;
		}
		break;
	case 2:
		while (len) {
			*(unsigned short *)addr = value;
			len -= iosize;
			addr += iosize;
		}
		break;
	case 4:
		while (len) {
			*(unsigned long *)addr = value;
			len -= iosize;
			addr += iosize;
		}
		break;
	}
}


static void
and_write_memory(unsigned long phys_addr, void *addr, int len, int iosize, unsigned long value)
{
	switch(iosize) {
	case 1:
		while (len) {
			*(unsigned char *)addr &= value;
			len -= iosize;
			addr += iosize;
		}
		break;
	case 2:
		while (len) {
			*(unsigned short *)addr &= value;
			len -= iosize;
			addr += iosize;
		}
		break;
	case 4:
		while (len) {
			*(unsigned long *)addr &= value;
			len -= iosize;
			addr += iosize;
		}
		break;
	}
}


static void
or_write_memory(unsigned long phys_addr, void *addr, int len, int iosize, unsigned long value)
{
	switch(iosize) {
	case 1:
		while (len) {
			*(unsigned char *)addr |= value;
			len -= iosize;
			addr += iosize;
		}
		break;
	case 2:
		while (len) {
			*(unsigned short *)addr |= value;
			len -= iosize;
			addr += iosize;
		}
		break;
	case 4:
		while (len) {
			*(unsigned long *)addr |= value;
			len -= iosize;
			addr += iosize;
		}
		break;
	}
}


int
main (int argc, char **argv)
{
  printf("Hej!! I did it!!!!!\n");
	return 0;
}

