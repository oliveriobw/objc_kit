# objc_kit

Useful macros to simplify objective-c development. Covers logging, exceptions, notifications, and so on.   
   
If Objective-C seems like a drain on all your resources, if you like succinct code, if you want to forget about all the intricacies of instatiating an NSString, if you'd rather focus on the interesting stuff, and if you don't get religeous about using preprocessor macros, then take a look. 
  
 
## Logging Examples:

NSLog(); is fine, but it's unconditional, and no-one wants that. Compile with  
ENABLE_LOGGING in configurations where you want logging (eg: your DEBUG build)  
and wg_log calls are switched on and off.   
   
wg_log(@"prints using NSLog internally");  
wg_log(@"like a variadic printf as you'd expect %d %@ etc", 10, self);  

## Exception Examples:  
  
Exceptions thrown from blocks are tricky to cope with - some simple macros to   
cleanly call your blocks when things go wrong.      
  
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

## String examples: 

NSString* a = nstradd(some_nstring, @"- and another"); //concats together  
NSString* b = nsstr(@"%d = %@", 1, some_string); //variadic string create   
NSString* c = nstra("nsstring from a string literal");
NSString* d = nstr8("nsstring from a utf8 string literal");




