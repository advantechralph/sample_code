#ifndef __instrument_h__
#define __instrument_h__
#include "basic.h"
extern "C" __attribute__ ((no_instrument_function)) void __cyg_profile_func_enter(void*, void*);
extern "C" __attribute__ ((no_instrument_function)) void __cyg_profile_func_exit(void*, void*);
#if 0
__attribute__ ((no_instrument_function))
void /*__cyg_*/profile_func_enter(void* this_func, void* call_site){
#else
void __attribute__((no_instrument_function))
  __cyg_profile_func_enter(void *this_func, void *call_site){
#endif
  printf("Enter:\t%p\n", this_func);
}

#if 0
__attribute__ ((no_instrument_function))
void /*__cyg_*/profile_func_exit(void* this_func, void* call_site){
#else
void __attribute__((no_instrument_function))
  __cyg_profile_func_exit(void *this_func, void *call_site){
#endif
  printf("Exit: \t%p\n", this_func);
}
#endif /*__instrument_h__*/
