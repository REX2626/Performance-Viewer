#include <math.h>
#include <pdh.h>
#include <pdhmsg.h>
#include <tchar.h>
#include "stats.h"



PDH_HQUERY cpuQuery;
PDH_HCOUNTER cpuTotal;
MEMORYSTATUSEX memInfo;
float t = 0;

int initStats() {
    DWORD_PTR userData = {0};
    if (PdhOpenQuery(NULL, userData, &cpuQuery) != ERROR_SUCCESS) return -1;
    if (PdhAddEnglishCounter(cpuQuery, "\\Processor(_Total)\\% Processor Time", userData, &cpuTotal) != ERROR_SUCCESS) return -1;
    if (PdhCollectQueryData(cpuQuery) != ERROR_SUCCESS) return -1;  // First query causes PDH_INVALID_DATA for PdhGetFormattedCounterValue

    return 0;
}

float getProcessorUsage(void) {
    PDH_FMT_COUNTERVALUE counterVal;

    if (PdhCollectQueryData(cpuQuery) != ERROR_SUCCESS) return -1;
    PDH_STATUS retCode = PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal);
    if (retCode != ERROR_SUCCESS && retCode != PDH_CALC_NEGATIVE_DENOMINATOR) return -1;
    return counterVal.doubleValue / 100;
}

float getMemoryUsage(void) {
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    if (GlobalMemoryStatusEx(&memInfo) == 0) return -1;
    DWORDLONG totalMem = memInfo.ullTotalPhys;
    DWORDLONG totalMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

    return (float) totalMemUsed / totalMem;
}

float dummy(void) {
    t += 0.000005;
    if (t > 1) t == 0;
    return (sin(t) + 1) / 2;
}
