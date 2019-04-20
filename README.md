# This is application development  ----- by Hoang Nguyen

This application offers a possibility to turn a Raspherry Pi as a sound
device. The application comes with 2 functions: a sound collector and a test tone generator.




# List of Content
   1. Congfiguration Instruction
   2. Installation Instruction
   3. Operating Instructions
   4. List of Files
   5. Copyright / CopyLeft
   6. Contact Info.
   7.Credits and Acknowlegements


# 1.Configuration Instruction
	* This application is running on Raspberry Pi 3 model B (Linux). Users should have a USB sound card, a microphone and network connection.
  * 1.1 Configure USB sound card as default audio device
	* Connect USB sound card into your Raspberry.
	* Use "lsusb" command to check if your USB sound card is mounted.
	* Use "sudo nano /etc/asound.conf" command and put following content to the file:
	```
	pcm.!default {
 	 type plug
  	slave {
   	 pcm "hw:1,0"
  	}
	}
	ctl.!default {
    	type hw
    	card 1
	}
	```
	* Go to your home directory. Use .nano .asoundrc. command and put the same content to the file.
	* Run "alsamixer" you should be able to see that USB sound card is the default audio device. For a more sensitive sound detection, it is better to maximize the volume of "Mic".
  *1.2 Install libcurl library
	* First use command "ls /usr/include/curl" or "ls /usr/include/arm-linux-gnueabihf/curl" to identify that libcurl library is installed.
	* If the folder doesn't exist. Run "sudo apt-get update" to update the application list.
	* Run "sudo apt-get install libcurl3" to install the libcurl3.
	* Run "sudo apt-get install libcurl4-openssl-dev" to install the development API of libcurl4.
# 2.Installation Instructions.
  	* In your installation directory, type "make" command to make executable file.
	* Type "ls" command, you should see a file named "sound.out".
# 3.Operating Instructions
  * 3.1 Display bar chart about frequency and peak counting.
	* Run file "sound.out" by typing "./sound.out" command. You should be able to see a bar char on terminal. Try to make noise around microphone and see the difference on bar chart.
	* To stop the program, type "Ctrl" + "C".
  * 3.2 Generate the sound file we had done above.
	* Type "make clean" to deleted all excutable file, the type "make" again.
# 4.List file are contained in program:
  * README.md: contains all information about the project.
  * comm.c and comm.h: calculate and send data (decibel values) using curl library to URL (POST mathod).
  * screen.c and screen.h: contains all functions that set colors and display barchart on terminal.
  * sound.c and sound.h: contains all functions that process sound(peaks,samples, calculate 80 pieces of decibel values,...) and generate Tone. It is also used for debug program. 
  * makefile: to run program and clean it by simple command.
  * main.c: get parameter for generating Test Tone and call to run another part of program (to display barchart).
  * sound.php: php file to get data and write it to a text file in your home directory server.
  * testcurl.c: To test test data is sent or not.
# 5. Copyright/Copyleft.
  * Coppyright 2019: All the source code were written by Hoang Nguyen
  * Coppyleft 2019: This application is done under instruction of mr. Gao Chao
# 6.Contact Information
  * email: nhoang0708@gmail.com
  * github: www.github.com/hoangnguyen7699 
  * phone number: 046 547 1090
# 7. Credits and Acknowledgements
  * Hoang Nguyen- Application Developer
  * Gao Chao- Instructor
# Note:
 * I had a problem with my OS on last two weeks, so I have to install again my OS. That's why you see the date I commit code is diffrent with other students. However, I followed all topics in this course and hopefully you will accept it.
	
  


	
