# NoDelay Library

This is a library for using the builtin Arduino mills function without all the setup.

The write up for this library can be found Here
    ------> http://mario.mtechcreations.com/programing/nodelay-arduino-library/

## About this Library ##

To start create a noDelay variable. From here you are able to set a delay time, a dealy time and
function to run or nothing at all.

To check it if the delay time has past, call the update function check time and 
run the set function.

Using the start function, you are able to restart the timer for delay. This allows you more
control over then a delay with trigger.


The delay time can be change using setDelay using a time in miliseconds. 

The use of the fupdate function is not Deprecated and will be removed in the future.

Written by Mario Avenoso of mtechcreations.com

MIT license, check license.txt for more information

## Quick Usage ##

To create a NoDelay object:
```
noDelay someKindofDelay(1000); Makes a delay object of given time in ms
noDelay someKindofDelay(1000, some_function_to_call); Makes a delay object of given time in ms that will call the given void function
noDelay someKindofDelay(1000, false); Makes a delay object of given time in ms but keeps it from running
noDelay someKindofDelay(1000, some_function_to_call, false); Makes a delay object of given time in ms that will call the given void function but keeps it from running
```

### NoDelay Functions:

**update()** : When called it will check if the amount of time set has passed. If the object was only set with a delay time, the function will return true, otherwise it will return false. If a function was passed to the object when created, after the amount of time specified has passed, when checking update, the function will be called and return a true. This function will always return false if NoDelay is set to stop

**setdelay()** :  This function is used to adjust the amount of time it takes for NoDelay to wait for. This is useful if you want something to happen faster or slower that the time originally set when the NoDelay object was created. Setting the time to zero will also allow you to bypass any delay at all. With a delay time of zero every time update() is called you will receive a true and or a function will be called. This will not be true if NoDelay is set to stop


**start()** : Start is used to reset the timer or to start NoDelay again when it has been stopped. When called the zero point the timer counts from is reset to the time start() was called. If you needed something to happen a few seconds after another part of you code is run, you can use start() to start the clock at that moment. Then when update() is called it will activate as close to the delay time as possible.

*Example*: If you wanted a light to light up 10 seconds after a button was pressed, you would call yourDelayvar.start() when the button was pressed. Then keep calling youDelayvar.update() in your main loop, after 10 seconds has passed the next time update() is called whatever action you setup to happen will happen.
start() will also allow you to start or restart NoDelay if stop() was used.


**stop()** : This function will keep NoDelay from returning true or running a function when calling update(). When set update() will always return false even if the amount of time has passed set for the delay. This is useful if you only want delayed actions to happen only after something else has happened.

*Example*: If you wanted check a sensor ever 5 seconds but only after a switch was flipped. You would stop NoDelay either but setting NoDelay to false when creating the object or by using stop(). Then when the switch is flipped set youDelayvar.start(). This will allow the delay to go though. When the switch is flipped back off, set youDelayvar.stop()

**enabled** : Check to see if NoDelay is enabled or not. If timer is enabled (start) retuns true, otherwise returns false (stop).


**fupdate** : This function is deprecated and should not be used as it will be removed at some point in the future. If has the same functionality as update() but only for NoDelay objects that have been created with a function to call. Unlike update(), fupdate() does not return anything and will only call the function it was set to when the delay time has passed. It will also not work when stop() has been set. With update() being able to be used for both functions and non function delays, this is no longer needed and only being kept around to keep old code compatibly for now
