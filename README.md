# objc_kit

Useful macros to simplify objective-c development. Logging and exceptions. 

## Logging Examples:

wg_log(@"prints using NSLog internally");  
wg_log(@"like a variadic printf as you'd expect %d %@ etc", 10, self);  

## Exception Examples:

wg_try   
//.. some code likely to throw exceptions  
wg_catch  
 
## Exception Examples with Blocks: 
 
//A block may never get called if an exception is thrown in the  
//function. Here the block (with a single bool argument) is  
//invoked with false if it throws:  
 
wg_try  
[obj some_method:my_block];  
wg_catch_b(my_block,false)  
   
//Here the block (with bool and int arguments) is invoked with   
//false and 23 if it throws:    
wg_try   
[obj some_method:my_block];   
wg_catch_b(my_block,false,23)   
 
//Here the block (with an NSException) is invoked with a code 22 and   
//some text if it throws:   
wg_try   
[obj some_method:my_block];   
wg_catch_b(my_block,wg_nserr(22,@"something threw and exception"))   




