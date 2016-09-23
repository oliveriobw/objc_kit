//
// general utils
//

#define cb_ready(cxn,sel)   ( cxn &&  cxn.delegate && [cxn.delegate respondsToSelector:sel] )
#define str_ok(n)           ( (n!=nil) && (n.length != 0) )
