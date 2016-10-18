//
// notify utils
//

#define wg_watch(_fnc,_id,_obj) [[NSNotificationCenter defaultCenter] addObserver:self selector:_fnc name:_id object:_obj]
#define wg_unwatch()            [[NSNotificationCenter defaultCenter] removeObserver:self]
#define wg_post(_id,_obj)       [[NSNotificationCenter defaultCenter] postNotificationName:_id object:_obj]
