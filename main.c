#include <stdlib.h> // for random numbers
#include "screen.h"
// #include <time.h> // for randomization (using system time)
#include <stdio.h>
#include "sound.h"
#include <signal.h> // able to use Ctrl-C
#include "comm.h"

int main(int argc, char **argv){
	if(argc >1){
		printf("Test tone generator\n");
		int fR, fL, ch;
		float duration;
		printf("No. of channels (1 or 2): ");
		scanf("%d", &ch);
		if(ch==1){
			prinf("Mono Frequency: ");
			scanf("%d", &fL);
		}else if (ch==2){
			printf("Give me Left and Right freq: ");
			scanf("%d %d", &fL, &fR)
		}else{
			printf("Wrong number of channels\n");
			return 1;
		}
		printf("Duration of sound: ");
		scanf("%f", &duration);
		testTone(ch, fL, fR, duration);
		return 0;
	}
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
