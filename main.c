//  AUTOMATY ZADANIE 6 

#include "led.h"
#include "keyboard.h"

int iTimeDelay;
int iStepCounter;

enum eLedState {RIGHT_DIRECTION, LEFT_DIRECTION, STOP};										

void Delay(int iMiliseconds)
{
    int iLoopIteration;
    iTimeDelay = (iMiliseconds * 5456);

    for(iLoopIteration = 0; iLoopIteration < iTimeDelay; iLoopIteration++)
    {
    }
}

int main()
{
    enum eLedState eLedState = STOP;													
		
    LedInit();
    KeyboardInit();
    
    while(1)
    {
        switch(eLedState)
        {
            case STOP:
                if(eKeyboardRead() == BUTTON_0)
                {
                    eLedState = LEFT_DIRECTION;
                }
                else if(eKeyboardRead() == BUTTON_2)
                {
                    eLedState = RIGHT_DIRECTION;
                }
                break;
                
            case RIGHT_DIRECTION:
                if(eKeyboardRead() == RELASED)
                {
                    LedStepRight();
                }
                else if(eKeyboardRead() == BUTTON_1)
                {
                    eLedState = STOP;
                }
                break;
                
            case LEFT_DIRECTION:
                if(eKeyboardRead() == RELASED)
                {
                    LedStepLeft();
                }
                else if(eKeyboardRead() == BUTTON_1)
                {
                    eLedState = STOP;
                }
                break;
        }
        Delay(100);
    }
}
