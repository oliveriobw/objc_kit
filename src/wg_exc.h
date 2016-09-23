//
// exception utils
//

#import <Foundation/Foundation.h>

// change to own custom domain string
#define wg_err_domain @"wg_err_domain"

// try block
#define wg_try    NS_DURING

// simplify catch handling
#define wg_catch                               \
    NS_HANDLER                                 \
    wg_log(@"exception handled %s:%d obj=%@",  \
    __FUNCTION__,__LINE__,localException);     \
    NS_ENDHANDLER

#define wg_err_desc(_descr)  @{NSLocalizedDescriptionKey : _descr }

// simplify NSError instance cration
#define wg_nserr(_code,_info)  \
     [NSError errorWithDomain: \
     wg_err_domain \
     code:_code \
     userInfo:  wg_err_desc(_info)]

// simplify catch and invoke a block of any sort
#define wg_catch_b(_a_block,...)  \
    NS_HANDLER     \
    wg_log(@"exception handled %s:%d obj=%@",  \
    __FUNCTION__,__LINE__,localException);     \
    _a_block(__VA_ARGS__) ; \
    NS_ENDHANDLER


