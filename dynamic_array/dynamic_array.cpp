#include <cstdio>
#include <cstdlib>
#include <cassert>

typedef int s32; 
typedef unsigned int u32;

namespace tf
{
    struct DArray
    {
        s32* _data = nullptr;
        u32 _size = 0;
        u32 _reserved_size;
    };

    void DArray_GrowTo(DArray* da, u32 grow_to)
    {
        assert((da != nullptr) && "[DArray_GrowTo] da is null");
        da->_reserved_size = grow_to;
        if(!da->_data)
        {
            da->_data = (s32*) malloc(grow_to * sizeof(s32));
            return;
        }
        
        da->_data = (s32*) realloc(da->_data, grow_to * sizeof(s32));
    }

    inline void DArray_PushBack(DArray* da, s32 element)
    {
        assert((da != nullptr) && "[DArray_PushBack] da is null");
        assert(da->_size < da->_reserved_size && "[DArray_PushBack] need to explicitly grow it");
        da->_data[da->_size++] = element;
    }

    inline DArraya_At(DArray* da, u32 index)
    {
        assert((da != nullptr) && "[DArraya_At] da is null");
        assert(index < da->_size && "[DArraya_At] index greater than _size");
        return da->_data[index];
    }

    inline DArraya_SetAt(DArray* da, u32 index, s32 val)
    {
        assert(index < da->_size && "[DArraya_SetAt] index greater than _size");
        return da->_data[index] = val;
    }

    inline DArraya_Size(DArray* da)
    {
        assert((da != nullptr) && "[DArraya_Size] da is null");
        return da->_size;
    }

    inline DArraya_ReservedSize(DArray* da)
    {
        assert((da != nullptr) && "[DArraya_ReservedSize] da is null");
        return da->_reserved_size;
    }

    void DArray_Destroy(DArray* da)
    {
        assert((da != nullptr) && "[DArray_Destroy] da is null");
        free(da->_data);
        da->_data = nullptr;
        da->_size = 0;
        da->_reserved_size = 0;
    }
}

int main()
{
    tf::DArray array;
    tf::DArray_GrowTo(&array, 10);
    
    printf("reserved_size: %d\n", array._reserved_size);

    for(u32 i = 0;i < 10;++i)
    {
        tf::DArray_PushBack(&array, i);
        printf("%d: %d size: %d\n", i, array._data[i], array._size);
    }
    
    tf::DArray_GrowTo(&array, array._reserved_size + 10);
    printf("reserved_size: %d\n", array._reserved_size);

    DArray_PushBack(&array, 10);
    DArray_PushBack(&array, 11);
    DArray_PushBack(&array, 12);

    for(u32 i = array._size;i < array._reserved_size;++i)
    {
        tf::DArray_PushBack(&array, i);
    }
    
    for(u32 i = 0;i < array._size;++i)
    {
        printf("%d: %d size: %d\n", i, array._data[i], array._size);
    }

    tf::DArray_Destroy(&array);

    // grow again (reuse it)
    DArray_GrowTo(&array, 10);
        
    printf("reserved_size: %d\n", array._reserved_size);

    for(u32 i = 0;i < 10;++i)
    {
        tf::DArray_PushBack(&array, i);
        printf("%d: %d size: %d\n", i, array._data[i], array._size);
    }
    
    tf::DArray_GrowTo(&array, array._reserved_size + 10);
    printf("reserved_size: %d\n", array._reserved_size);

    DArray_PushBack(&array, 10);
    DArray_PushBack(&array, 11);
    DArray_PushBack(&array, 12);

    for(u32 i = array._size;i < array._reserved_size;++i)
    {
        tf::DArray_PushBack(&array, i);
    }
    
    for(u32 i = 0;i < array._size;++i)
    {
        printf("%d: %d size: %d\n", i, DArraya_At(&array, i), array._size);
    }

    tf::DArray_Destroy(&array);

	return(0);
}