#ifndef _VECTOR_
#define _VECTOR_

#include <Arduino.h>

#define ITEM_SIZE sizeof(void*)


class Vector
{
    private:
        void** items;
        size_t size;
        size_t capacity;

        void resize(size_t);

    public:
        void  init();
        void  add(void*);
        void* get(size_t);
        void  del(size_t);
        void  set(size_t, void*);

        size_t len() const { return size; }
};

#endif
