#include "Cooperative_Quad_09_VelEst_02_capi_host.h"
static Cooperative_Quad_09_VelEst_02_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        Cooperative_Quad_09_VelEst_02_host_InitializeDataMapInfo(&(root), "Cooperative_Quad_09_VelEst_02");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
