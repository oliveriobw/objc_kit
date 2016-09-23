//
//
//
#import "wg_log.h"

@implementation   WgLog

+ (void)trace : (NSString *)format, ...
{
    va_list args;
    va_start(args, format);
    NSString* _tmp = [[NSString alloc] initWithFormat:format arguments:args];
    va_end(args);
    NSLog(@"%@ %@", wg_prefix, _tmp);
}

@end
