/**************************************************************************/
/*!
    @file     NoDelay.cpp
    @author   Mario Avenoso (M-tech Creations)
    @license  MIT (see license.txt)

    Library for using Arduino's mills function without all the setup

    @section  HISTORY

    v1.0 - First release
	v1.1 - Fixed issue with int vs unsigned long for time limit
	v2.0 - Changed need for separate update checks / function calls
	       Added start function to restart the timer when you want
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
noDelay::noDelay(unsigned long dtime)
{
	preMills = 0;
	setdelay(dtime);
}

noDelay::noDelay(unsigned long dtime, funTocall funcall)
{
	preMills = 0;
	setdelay(dtime);
	_funcall = funcall;
	use_function = true;
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

/*!
     @brief  Used to restart the Delay Time to 0.
            Allows you to better time when delays happen as the 0 time
			happens when this is called
     
     
*/
/**************************************************************************/
void noDelay::start()
{
	preMills = 0;
}

/**************************************************************************/
/*!
     @brief  Checks to see is delay time has passed and can then run code
	 Will run function call if one was used
     
     @returns boot: true if time to update, false if not 
*/
/**************************************************************************/
bool noDelay::update()
{
	curMills = millis();
	if (curMills - preMills >= delaytime)
	{
		preMills = curMills;
		if (use_function == true){
			_funcall();
			return true;
		}
		else{
			return true;
		}
		
	}
	
	else
		return false;
		
}

/**************************************************************************/
/*!
     @brief  Checks to see is delay time has passed and then runs function
     Deprecated 
     
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