#include <math.h>
#include <pdh.h>
#include <tchar.h>
#include "stats.h"



PDH_HQUERY cpuQuery;
PDH_HCOUNTER cpuTotal;
MEMORYSTATUSEX memInfo;
float t = 0;

void initStats() {
    DWORD_PTR userData = {0};
    PdhOpenQuery(NULL, userData, &cpuQuery);
    PdhAddEnglishCounter(cpuQuery, "\\Processor(_Total)\\% Processor Time", userData, &cpuTotal);
    PdhCollectQueryData(cpuQuery);
}

float getProcessorUsage(void) {
    PDH_FMT_COUNTERVALUE counterVal;

    PdhCollectQueryData(cpuQuery);
    PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal);
    return counterVal.doubleValue / 100;
}

float getMemoryUsage(void) {
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    DWORDLONG totalMem = memInfo.ullTotalPhys;
    DWORDLONG totalMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

    return (float) totalMemUsed / totalMem;
}

float dummy(void) {
    t += 0.01;
    if (t > 1) t == 0;
    return (sin(t) + 1) / 2;
}
