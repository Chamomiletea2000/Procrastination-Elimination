#include "GameScreen.h"
#include "Character.h"
#include <chrono>
#include <thread>

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

int _windowX=720;
int _windowY=640;

class Display
{
//some code
private:
	GameScreen *screen;
public:
	void addChar(Character &player)
	{
		screen.SetPlayer(player);
		
	}

    void run() {
    screen(_windowX, _windowY);
    
    // Frame duration for 60 FPS
    std::chrono::milliseconds targetFrameDuration(1000 / 60);

    while(true)
    {
        auto frameStart = std::chrono::steady_clock::now();

        system("clear"); // Clear screen on UNIX (Linux/Mac)
        // If on Windows, use: system("cls");
		if (kbhit()) {
		    char ch = getchar();
		    screen.Setkeylastpressed(ch);
		    screen.Notify();
		    std:this_thread::sleep_for(1);
		}
        screen.display();

        auto frameEnd = std::chrono::steady_clock::now();
        auto frameDuration = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);

        if(frameDuration < targetFrameDuration)
        {
            std::this_thread::sleep_for(targetFrameDuration - frameDuration);
        }
    }
}
	
// Check if a key has been pressed
int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

int main() {
    Display display;
    Character player=new Player("Ron",0,0);
    display.addChar(player);
    display.run();
    return 0;
}

main();