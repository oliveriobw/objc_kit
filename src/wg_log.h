//
// wg_log.h
//
#import <Foundation/Foundation.h>

#ifdef ENABLE_LOGGING

//change to own prefix
#define wg_prefix          @"wglog"

#define wg_basic(fmt,...) 	do{[WgLog trace: fmt,##__VA_ARGS__,nil];}while(0)
#define wg_log(fmt,...)	    wg_basic(fmt,##__VA_ARGS__,nil)
#define wg_logl         	wg_basic(@"%s:%d INF", __FUNCTION__, __LINE__)
#define wg_err(n)         	wg_basic(@"%s:%d ERR: %@", __FUNCTION__, __LINE__,n)

@interface WgLog : NSObject
+ (void)trace:  (NSString *)format, ...  NS_REQUIRES_NIL_TERMINATION;
@end

#else

//ENABLE_LOGGING OFF

#define wg_basic(fmt,...) 
#define wg_log(fmt,...)
#define wg_logl
#define wg_err(n)

#endif
