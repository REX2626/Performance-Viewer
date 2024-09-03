#include "stats.h"



MEMORYSTATUSEX memInfo;

float getMemoryUsage(void) {
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    DWORDLONG totalMem = memInfo.ullTotalPhys;
    DWORDLONG totalMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

    return (float) totalMemUsed / totalMem;
}
