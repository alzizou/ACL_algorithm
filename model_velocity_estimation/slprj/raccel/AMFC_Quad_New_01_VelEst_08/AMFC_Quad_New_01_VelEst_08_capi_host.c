#include "AMFC_Quad_New_01_VelEst_08_capi_host.h"
static AMFC_Quad_New_01_VelEst_08_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        AMFC_Quad_New_01_VelEst_08_host_InitializeDataMapInfo(&(root), "AMFC_Quad_New_01_VelEst_08");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
