#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
    HANDLE hSlot, hFile;
    DWORD bytesWritten, bytesRead;
    char message[] = "Hello, message queue using Windows mailslot!";
    char buffer[200];

    hSlot = CreateMailslotA(
        "\\\\.\\mailslot\\OSLabQueue",
        0,
        MAILSLOT_WAIT_FOREVER,
        NULL
    );

    if (hSlot == INVALID_HANDLE_VALUE)
    {
        printf("CreateMailslot failed. Error: %lu\n", GetLastError());
        return 1;
    }

    hFile = CreateFileA(
        "\\\\.\\mailslot\\OSLabQueue",
        GENERIC_WRITE,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE)
    {
        printf("CreateFile failed. Error: %lu\n", GetLastError());
        CloseHandle(hSlot);
        return 1;
    }

    WriteFile(hFile, message, strlen(message) + 1, &bytesWritten, NULL);

    printf("Producer: Data sent to message queue: %s\n", message);

    CloseHandle(hFile);

    ReadFile(hSlot, buffer, sizeof(buffer), &bytesRead, NULL);

    printf("Consumer: Data received from message queue: %s\n", buffer);

    CloseHandle(hSlot);

    return 0;
}