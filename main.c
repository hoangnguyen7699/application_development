#include <stdlib.h> // for random numbers
#include "screen.h"
// #include <time.h> // for randomization (using system time)
#include <stdio.h>
#include "sound.h"
#include <signal.h> // able to use Ctrl-C
#include "comm.h"

int main(){
	FILE *f;
	short sd[RATE];
	for (;;){ // alway be right
		int ret = system(RCMD);
		if (ret == SIGINT) break;
		f = fopen("test.wav","r");
		if (f == NULL){
			printf("Cannot open the file\n");
			return 1;
		}

		clearScreen();
		struct WAVHDR hdr;
		fread(&hdr, sizeof(hdr), 1, f); // read WAV header
		fread(&sd, sizeof(sd), 1, f); // read WAV data
		fclose(f);
		displayWAVHDR(hdr);
		displayWAVDATA(sd);
		sendData(sd);
	}
	resetColors();

//	getchar();

}
