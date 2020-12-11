#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32)
    #define PLATFORM_NAME 'W' // Windows
#elif defined(_WIN64)
    #define PLATFORM_NAME 'W' // Windows
#elif defined(__CYGWIN__) && !defined(_WIN32)
    #define PLATFORM_NAME 'W' // Windows (Cygwin POSIX under Microsoft Window)
#elif defined(__linux__)
    #define PLATFORM_NAME 'L' // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#elif defined(__sun) && defined(__SVR4)
    #define PLATFORM_NAME 'S' // Oracle Solaris, Open Indiana
#else
    #define PLATFORM_NAME 'N'
#endif

#if  PLATFORM_NAME == 'L' 
#include <termios.h>
static struct termios stored_settings;
void set_keypress();
void reset_keypress();
#endif

int main()
{
    printf("Hello World!\n");
    
	//1: code for pause with "any key" without "Enter" win/linux
	
	#if PLATFORM_NAME == 'W'
		printf("Platform: Windows. ");
		system("pause");
	#elif PLATFORM_NAME == 'L'
	    printf("Platform: Linux. Press any key for exit...\n");
		set_keypress();
		getchar();
		reset_keypress();
	#else
		printf("Platform: Linux. Press \"Enter\" for exit...\n");
	    getchar();
	#endif
	//end 1: 
    return 0;
}

// source :https://habr.com/ru/post/124789/

#if  PLATFORM_NAME == 'L' 
void set_keypress()
{
	struct termios new_settings;

	tcgetattr(0,&stored_settings); /* get current terminal attirbutes; 0 is the file descriptor for stdin */

	new_settings = stored_settings;

	new_settings.c_lflag &= (~ICANON); /* disable canonical mode */
	new_settings.c_lflag &= (~ECHO); /* disable console output */
	new_settings.c_cc[VTIME] = 0;/* no timeout */
	new_settings.c_cc[VMIN] = 1;/* wait until at least one keystroke available */

	tcsetattr(0,TCSANOW,&new_settings);/* set immediately */
}

void reset_keypress()
{
	tcsetattr(0,TCSANOW,&stored_settings);/* get standart terminal attirbutes; 0 is the file descriptor for stdin */
}
#endif