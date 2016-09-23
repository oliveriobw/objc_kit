# objc_kit

Useful macros to simplify objective-c development. Logging and exceptions.  
  
 NSLog(); is fine, but it's unconditional, and no-one wants that. Compile with ENABLE_LOGGING in configurations where you want logging and wg_log calls are switched on and off at build time. Can be easily tweaked to support different log levels, and persistance. 
 
 Exceptions thrown from blocks are tricky to cope with - some simple macros to cleanly call your blocks when things go wrong.    

## Logging Examples:

wg_log(@"prints using NSLog internally");  
wg_log(@"like a variadic printf as you'd expect %d %@ etc", 10, self);  

## Exception Examples:

wg_try   
//.. some code likely to throw exceptions  
wg_catch  
 
## Exception Examples with Blocks: 
 
//A block may never get called if an exception is thrown in the  
//function. These helpers ensure the block gets invoked after   
//an exception is thrown.    
  
//Here the block (taking a single bool argument) is  
//invoked with false if it throws:  
wg_try  
[obj some_method:my_block];  
wg_catch_b(my_block,false)  
   
//Here the block (taking bool and int arguments) is invoked with   
//false and 23 if it throws:    
wg_try   
[obj some_method:my_block];   
wg_catch_b(my_block,false,23)   
    
//wg_nserr creates an NSError instance. Usually requires copiuous typing.    
//Here it's created with a code of -1, and an error message    
NSError* e = wg_nserr(-1,@"my message");   
  
  
//Here the block (taking an NSException) is invoked with a code 22 and   
//some text if it throws:   
wg_try   
[obj some_method:my_block];   
wg_catch_b(my_block,wg_nserr(22,@"something threw an exception"))   




