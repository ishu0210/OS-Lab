#include <stdio.h>
#include <string.h>
#include <windows.h>

#define BUF_SIZE 1024
#define SHM_NAME "Local\\OSLabSharedMemory"

int main()
{
    HANDLE hMapFile;
    char *sharedData;

    hMapFile = CreateFileMappingA(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        BUF_SIZE,
        SHM_NAME
    );

    if (hMapFile == NULL)
    {
        printf("CreateFileMapping failed. Error: %lu\n", GetLastError());
        return 1;
    }

    sharedData = (char *)MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        BUF_SIZE
    );

    if (sharedData == NULL)
    {
        printf("MapViewOfFile failed. Error: %lu\n", GetLastError());
        CloseHandle(hMapFile);
        return 1;
    }

    strcpy(sharedData, "Hello, shared memory using Windows API!");

    printf("Data written to shared memory: %s\n", sharedData);

    UnmapViewOfFile(sharedData);
    CloseHandle(hMapFile);

    return 0;
}