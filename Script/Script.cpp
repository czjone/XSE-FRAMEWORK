#include "Script.h"
#include <glib/glib.h>
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

void Test(){
    MonoDomain *domain;
    domain = mono_jit_init ("s");
    domain = mono_jit_init_version ("myapp", "v2.0.50727");
    MonoAssembly *assembly;
    
    assembly = mono_domain_assembly_open (domain, "file.exe");
//    if (!assembly) error ();
//    int retval = mono_jit_exec (domain, assembly, argc - 1, argv + 1);
//    mono_config_parse (NULL);
//    mono_config_parse ("my_mappings");
//    mono_set_dirs (myapp_lib, myapp_etc);
}