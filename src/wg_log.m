//
//
//
#import "wg_log.h"

#ifdef ENABLE_LOGGING

@implementation   WgLog

+ (void)trace : (NSString *)format, ...
{
    va_list args;
    va_start(args, format);
    NSString* _tmp = [[NSString alloc] initWithFormat:format arguments:args];
    va_end(args);
    NSLog(@"%@ %@", wg_prefix, _tmp);
}

+ (void)trace:  (const char*) fnc : (int) line
{
    NSLog(@"%@ %s:%d", wg_prefix,fnc,line);
}

+ (void)trace:  (NSString *) preamble : (const char*) fnc : (int) line : (NSString *)format, ...
{
    va_list args;
    va_start(args, format);
    NSString* _tmp = [[NSString alloc] initWithFormat:format arguments:args];
    va_end(args);
    NSLog(@"%@:%@ %s:%d %@", wg_prefix, preamble,fnc,line, _tmp);
}

@end

#endif

