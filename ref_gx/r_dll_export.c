#include <stdlib.h>
#include "r_context.c"

extern int dll_register(const char *name, dllexport_t *exports);

dllexport_t wii_graphics_exports[] = {
    { "GetRefAPI", (void*)GetRefAPI },
    { NULL, NULL },
};

// long name lol
extern int setup_wii_dll_functions( void )
{
    return dll_register( "libref_gx.so", wii_graphics_exports );
}
