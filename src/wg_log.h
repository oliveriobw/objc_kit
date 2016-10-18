//
// wg_log.h
//
#import <Foundation/Foundation.h>

#ifdef ENABLE_LOGGING

//change to own prefix
#define wg_prefix          @"wglog"

#define wg_log(fmt,...) 	        do{[WgLog trace:@"INF":  __FUNCTION__ : __LINE__ : fmt,##__VA_ARGS__,nil];}while(0)
#define wg_warn(fmt,...) 	        do{[WgLog trace:@"WARN": __FUNCTION__ : __LINE__ : fmt,##__VA_ARGS__,nil];}while(0)
#define wg_err(fmt,...) 	        do{[WgLog trace:@"ERR":  __FUNCTION__ : __LINE__ : fmt,##__VA_ARGS__,nil];}while(0)
#define wg_basic(fmt,...)       	do{[WgLog trace: fmt,##__VA_ARGS__,nil];}while(0)
#define wg_logl         	        do{[WgLog trace: __FUNCTION__ :__LINE__ ];}while(0)

#ifdef VERBOSE_LOGGING
    #define wg_verb(fmt,...) 	        do{[WgLog trace:@"VERB": __FUNCTION__ : __LINE__ : fmt,##__VA_ARGS__,nil];}while(0)
#else
    #define wg_verb(fmt,...)
#endif

@interface WgLog : NSObject
+ (void)trace:  (NSString *)format, ...  NS_REQUIRES_NIL_TERMINATION;
+ (void)trace:  (NSString *) preamble : (const char*) fnc : (int) line : (NSString *)format, ...  NS_REQUIRES_NIL_TERMINATION;
+ (void)trace:  (const char*) fnc : (int) line ;
@end

#else

//ENABLE_LOGGING OFF

#define wg_basic(fmt,...) 
#define wg_log(fmt,...)
#define wg_logl
#define wg_err(n)

#endif
