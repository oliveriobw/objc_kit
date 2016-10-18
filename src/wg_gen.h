//
// general utils
//
// simpler to read, easy to remember
//

#define cb_ready(cxn,sel)     ( cxn &&  cxn.delegate && [cxn.delegate respondsToSelector:sel] )
#define del_ready(del,sel)    ( del && [del respondsToSelector:sel] )
#define str_ok(n)             ( (n!=nil) && (n.length != 0) )
#define inst_memb(inst,prop)  ( ((inst!=nil) && (inst.prop!=nil))  ? inst.prop : nil )
#define str_nonull(n)         ( n != nil ? n : @"" )

#define nsbool(n)       ((NSNumber*)[NSNumber numberWithBool:(n)])
#define nsnumber(n)     ((NSNumber*)[NSNumber numberWithInt:(n)])
#define nsnumberll(n)   ((NSNumber*)[NSNumber numberWithLongLong:(n)])
#define nsdouble(n)     ((NSNumber*)[NSNumber numberWithDouble:(n)])
#define nsstr(fmt,...)  ([NSString stringWithFormat:fmt,##__VA_ARGS__,nil ])
#define nstra(txt)      ([NSString stringWithCString:txt encoding:NSASCIIStringEncoding])
#define nstr8(txt)      ([NSString stringWithCString:txt encoding:NSUTF8StringEncoding])
#define nstradd(lhs,rhs)   (nsstr(@"%@%@",lhs,rhs))
