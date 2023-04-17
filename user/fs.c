#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fsstat.h"
#include "user.h"

#define DEFAULT 0x1FF

void checkArguments(int argc, char* argv[], int* flag) {
    flag[0] = 0;

    for(int i = 1; i < argc; ++i) {
        if     (!strcmp(argv[i], "-db")   || !strcmp(argv[i], "--data-block"))
            flag[0] |= FSSTAT_DATA_BLOCK_COUNT;
        else if(!strcmp(argv[i], "-ob")   || !strcmp(argv[i], "--occupied-block"))
            flag[0] |= FSSTAT_OCCUPIED_BLOCK_COUNT;
        else if(!strcmp(argv[i], "-fb")   || !strcmp(argv[i], "--free-block"))
            flag[0] |= FSSTAT_FREE_BLOCK_COUNT;
        else if(!strcmp(argv[i], "-ec")   || !strcmp(argv[i], "--entry-count"))
            flag[0] |= FSSTAT_FILE_SYSTEM_ENTRY_COUNT;
        else if(!strcmp(argv[i], "-dc")   || !strcmp(argv[i], "--directory-count"))
            flag[0] |= FSSTAT_DIRECTORY_COUNT;
        else if(!strcmp(argv[i], "-fc")   || !strcmp(argv[i], "--file-count"))
            flag[0] |= FSSTAT_FILE_COUNT;
        else if(!strcmp(argv[i], "-devc") || !strcmp(argv[i], "--device-count"))
            flag[0] |= FSSTAT_DEVICE_COUNT;
        else if(!strcmp(argv[i], "-fs")   || !strcmp(argv[i], "--files-size"))
            flag[0] |= FSSTAT_FILES_SIZE;
        else if(!strcmp(argv[i], "-fos")  || !strcmp(argv[i], "--files-occupied-size"))
            flag[0] |= FSSTAT_FILES_OCCUPIED_SIZE;
        }

    if(!flag[0]) flag[0] = DEFAULT;
}

void printFileSystemStatus(int flag) {
    int value;

    if(flag & FSSTAT_DATA_BLOCK_COUNT) {
        filesystem(FSSTAT_DATA_BLOCK_COUNT, &value);
        printf("Data blocks: %d\n", value);
    }

    if(flag & FSSTAT_OCCUPIED_BLOCK_COUNT) {
        filesystem(FSSTAT_OCCUPIED_BLOCK_COUNT, &value);
        printf("Occupied data blocks: %d\n", value);
    }

    if(flag & FSSTAT_FREE_BLOCK_COUNT) {
        filesystem(FSSTAT_FREE_BLOCK_COUNT, &value);
        printf("Free data blocks: %d\n", value);
    }

    if(flag & FSSTAT_FILE_SYSTEM_ENTRY_COUNT) {
        filesystem(FSSTAT_FILE_SYSTEM_ENTRY_COUNT, &value);
        printf("Entries count: %d\n", value);
    }

    if(flag & FSSTAT_DIRECTORY_COUNT) {
        filesystem(FSSTAT_DIRECTORY_COUNT, &value);
        printf("Directories count: %d\n", value);
    }

    if(flag & FSSTAT_FILE_COUNT) {
        filesystem(FSSTAT_FILE_COUNT, &value);
        printf("Files count: %d\n", value);
    }

    if(flag & FSSTAT_DEVICE_COUNT) {
        filesystem(FSSTAT_DEVICE_COUNT, &value);
        printf("Devices count: %d\n", value);
    }

    if(flag & FSSTAT_FILES_SIZE) {
        filesystem(FSSTAT_FILES_SIZE, &value);
        printf("Total file size: %dB\n", value);
    }

    if(flag & FSSTAT_FILES_OCCUPIED_SIZE) {
        filesystem(FSSTAT_FILES_OCCUPIED_SIZE, &value);
        printf("Total file size on disk: %dB\n", value);
    }
}

int main(int argc, char* argv[]) {
    int flag;

    checkArguments(argc, argv, &flag);
    printFileSystemStatus(flag);

    exit();
}
