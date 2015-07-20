/**************************************************************************/
/*!
    @file     NoDelay.cpp
    @author   Mario Avenoso (M-tech Creations)
    @license  MIT (see license.txt)

    Library for using Arduino's mills function without all the setup

    @section  HISTORY

    v1.0 - First release
*/
/**************************************************************************/

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include "NoDelay.h"



/*========================================================================*/
/*                            CONSTRUCTORS                                */
/*========================================================================*/

/**************************************************************************/
/*!
    Constructor
*/
/**************************************************************************/
noDelay::noDelay(void)
{
	preMills = 0;
	setdelay(0);
}
noDelay::noDelay(int dtime)
{
	preMills = 0;
	setdelay(dtime);
}

noDelay::noDelay(int dtime, funTocall funcall)
{
	preMills = 0;
	setdelay(dtime);
	_funcall = funcall;
}

/*========================================================================*/
/*                           PUBLIC FUNCTIONS                             */
/*========================================================================*/

/**************************************************************************/
/*!
     @brief  Sets the amount of time the delay should wait before
				the next update
     
     @params[in] dtime
     Time in miliseconds to wait
     
*/
/**************************************************************************/
void noDelay::setdelay(unsigned long dtime)
{
	delaytime = dtime;
}

/**************************************************************************/
/*!
     @brief  Checks to see is delay time has passed and can then run code
     
     @returns boot: true if time to update, false if not 
*/
/**************************************************************************/
bool noDelay::update()
{
	curMills = millis();
	if (curMills - preMills >= delaytime)
	{
		preMills = curMills;
		return true;
	}
	
	else
		return false;
		
}

/**************************************************************************/
/*!
     @brief  Checks to see is delay time has passed and then runs function
     
     
*/
/**************************************************************************/
void noDelay::fupdate()
{
	curMills = millis();
	if (curMills - preMills >= delaytime)
	{
		preMills = curMills;
		_funcall();
	}
		
}