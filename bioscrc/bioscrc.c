// Simple tool to calculate and write a checksum into a PC BIOS ROM image

#include "portable/print.h"

#include <dos.h>
#include <fcntl.h>

#define ROMSIZE 0x2000

uint8_t buf[ROMSIZE+1];

static int do_checksum(char* in,char* out){
	unsigned count;
	int f;
	if(_dos_open(in,O_RDONLY,&f)) return 1;
	_dos_read(f,buf,ROMSIZE+1,&count);
	_dos_close(f);

	uint8_t sum=0;
	for(int i=0;i<(ROMSIZE-1);++i){
		sum+=buf[i];
	}
	buf[ROMSIZE-1]=0-sum;

	if(_dos_creat(out,_A_NORMAL,&f)) return 2;
	_dos_write(f,buf,ROMSIZE,&count);
	_dos_close(f);
	return 0;
}

int main(int argc,char**argv){
	if(argc!=3){
		print("Usage: ");
		print(argv[0]);
		print(" <infile> <outfile>");
		return 1;
	}
	return do_checksum(argv[1],argv[2]);
}

