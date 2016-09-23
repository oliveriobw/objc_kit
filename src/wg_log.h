//
// wg_log.h
//
#import <Foundation/Foundation.h>

//change to own prefix
#define wg_prefix          @"wglog"

#define wg_basic(fmt,...) 	do{[WgLog trace: fmt,##__VA_ARGS__,nil];}while(0)
#define wg_log(fmt,...)	    wg_basic(fmt,##__VA_ARGS__,nil)
#define wg_logl         	wg_basic(@"%s:%d INF", __FUNCTION__, __LINE__)
#define wg_err           	wg_basic(@"%s:%d ERR", __FUNCTION__, __LINE__)

@interface WgLog : NSObject
+ (void)trace:  (NSString *)format, ...  NS_REQUIRES_NIL_TERMINATION;
@end
