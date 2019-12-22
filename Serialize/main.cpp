#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cassert>

typedef long long s64;
typedef unsigned long long u64;

typedef int s32;
typedef unsigned int u32;

typedef short s16;
typedef unsigned short u16;

typedef char s8;
typedef unsigned char u8;

typedef float f32;
typedef double f64;

struct Data
{
    s32 s32_Field;
    u32 u32_Field;
    u8 u8_ArrField[4];
};



// size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );

void Data_Serialize(const Data* data, FILE* file)
{
    fwrite((void*) data, sizeof(Data), 1, file);
}

// size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );

void Data_Unserialize(const Data* data, FILE* file)
{
    fread((void*) data, sizeof(Data), 1, file);
}

void Data_Print(const Data* readData)
{
    printf("%X\n", readData->s32_Field);
    printf("%X\n", readData->u32_Field);
    for(int i = 0;i < 4;++i)
        printf("%X\n", readData->u8_ArrField[i]);
}

int main()
{
    FILE* serialFile = fopen("data.serial", "rwb");

    if(!serialFile)
    {
        std::cerr << "file open failed\n";
        return 1;
    }

    Data data;

    data.s32_Field = 0x11111111;
    data.u32_Field = 0x22222222;
    data.u8_ArrField[0] = 0x33;
    data.u8_ArrField[1] = 0x44;
    data.u8_ArrField[2] = 0x55;
    data.u8_ArrField[3] = 0x66;

    Data_Serialize(&data, serialFile);
    
    fflush(serialFile);
    fseek(serialFile, 0, SEEK_SET);

    Data readData;
    Data_Unserialize(&readData, serialFile);

    Data_Print(&readData);

    assert(data.s32_Field == readData.s32_Field);
    assert(data.u32_Field == readData.u32_Field);

    fclose(serialFile);
    return 0;
}