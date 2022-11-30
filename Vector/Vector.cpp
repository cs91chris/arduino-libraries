#include "Vector.h"


void Vector::init()
{
    size = 0;
    capacity = ITEM_SIZE;
    items = malloc(ITEM_SIZE * capacity);
}

void Vector::resize(size_t c)
{
    void** newitems = realloc(items, ITEM_SIZE * c);

    if(newitems != NULL) {
        items = newitems;
        capacity = c;
    }
}

void Vector::add(void* item)
{
    if(capacity == size) {
        resize(capacity * 2);
	}

    items[size] = item;
    size++;
}

void Vector::set(size_t index, void* item)
{
    if(index >= 0 && index < size) {
        items[index] = item;
	}
}

void* Vector::get(size_t index)
{
    if(index >= 0 && index < size) {
        return items[index];
	}

    return NULL;
}

void Vector::del(size_t index)
{
    if(index < 0 || index >= size) {
        return;
	}

    items[index] = NULL;

    for(size_t i = index; i < size - 1; i++) {
        items[i] = items[i + 1];
        items[i + 1] = NULL;
    }

    size--;

    if(size > 0 && size == capacity / ITEM_SIZE) {
        resize(capacity / 2);
	}
}
