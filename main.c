#include <stdio.h>
#include "IntVector.h"

int main()
{
    IntVector *v = int_vector_new(10);
    printf("-Create vector-\n");
    printf(" Capacity: %ld\n", int_vector_get_capacity(v));
    printf(" Size: %ld\n", int_vector_get_size(v));
    int_vector_resize(v, v->capacity);
    printf("-Resize vector-\n");
    printf("-Capacity: %ld\n", int_vector_get_capacity(v));
    printf("-Size: %ld\n", int_vector_get_size(v));
    int i;
    printf("-Set items-\n");
    for(i = 0; i < v->size; ++i)
    {
        int_vector_set_item(v, i, i);
    }
    printf("There're what we set:\n");
    for(i = 0; i < v->size; ++i)
    {
        printf("%d ", int_vector_get_item(v, i));
    }
    printf("\n");
    printf("The 8th item is %d\n", int_vector_get_item(v, 8));
    int_vector_reserve(v, 12);
    printf("-Reserve vector-\n");
    printf("-Capacity: %ld\n", int_vector_get_capacity(v));
    printf("-Size: %ld\n", int_vector_get_size(v));
    int_vector_shrink_to_fit(v);
    printf("-Shrink to fit-\n");
    printf("-Capacity: %ld\n", int_vector_get_capacity(v));
    printf("-Size: %ld\n", int_vector_get_size(v));
    int_vector_resize(v, 12);
    printf("-Resize vector-\n");
    printf("-Capacity: %ld\n", int_vector_get_capacity(v));
    printf("-Size: %ld\n", int_vector_get_size(v));
    printf("-Vector looks like: ");
    for(i = 0; i < v->size; ++i)
    {
        printf("%d ", int_vector_get_item(v, i));
    }   
    printf("\n");
    int_vector_resize(v, 5);
    printf("-Resize vector again-\n");
    printf("-Capacity: %ld\n", int_vector_get_capacity(v));
    printf("-Size: %ld\n", int_vector_get_size(v));
    printf("-Now vector looks like: ");
    for(i = 0; i < v->size; ++i)
    {
        printf("%d ", int_vector_get_item(v, i));
    }
    printf("\n");
    int_vector_pop_back(v);
    printf("-Pop it back-\n");
    printf("-Capacity: %ld\n", int_vector_get_capacity(v));
    printf("-Size: %ld\n", int_vector_get_size(v));
    printf("-Now vector looks like: ");
    for(i = 0; i < v->size; ++i)
    {
        printf("%d ", int_vector_get_item(v, i));
    }
    printf("\n");
    int_vector_reserve(v,9);
    printf("-Capacity: %ld\n", int_vector_get_capacity(v));
    int_vector_resize(v, 7);
    printf("-Now vector looks like: ");
    for(i = 0; i < v->size; ++i)
    {
        printf("%d ", int_vector_get_item(v, i));
    }
    printf("\n");
    printf("-Capacity: %ld\n", int_vector_get_capacity(v));
    printf("-Size: %ld\n", int_vector_get_size(v));
    int_vector_resize(v, 0);
    printf("-Resize vector again-\n");
    printf("-Capacity: %ld\n", int_vector_get_capacity(v));
    printf("-Size: %ld\n", int_vector_get_size(v));
    int_vector_push_back(v, 10);
    printf("-Push it back-\n");
    printf("-Capacity: %ld\n", int_vector_get_capacity(v));
    printf("-Size: %ld\n", int_vector_get_size(v));
    printf("-Now vector looks like: ");
    for(i = 0; i < v->size; ++i)
    {
        printf("%d ", int_vector_get_item(v, i));
    }
    printf("\n");
    IntVector *copy_v = int_vector_copy(v);
    printf("-Create vector's copy-\n");
    printf("-Copy's cap: %ld\n", int_vector_get_capacity(copy_v));
    printf("-Copy's size: %ld\n", int_vector_get_size(copy_v));
    int_vector_reserve(copy_v, 6);
    printf("-Reserve vector's copy-\n");
    printf("-Copy's cap: %ld\n", int_vector_get_capacity(copy_v));
    printf("-Copy's size: %ld\n", int_vector_get_size(copy_v));
    int_vector_resize(copy_v, copy_v->capacity);
    printf("-Resize vector's copy*\n");
    printf("-Copy's cap: %ld\n", int_vector_get_capacity(copy_v));
    printf("-Copy's size: %ld\n", int_vector_get_size(copy_v));
    printf("-Set items-\n");
    for(i = 1; i < copy_v->size; ++i)
    {
        int_vector_set_item(copy_v, i, 15* i);
    }
    printf("-There're what we set: ");
    for(i = 0; i < copy_v->size; ++i)
    {
        printf("%d ", int_vector_get_item(copy_v, i));
    }
    printf("\n");
    int_vector_resize(copy_v, 6);
    printf("-Resize vector's copy*\n");
    printf("-Copy's cap: %ld\n", int_vector_get_capacity(copy_v));
    printf("-Copy's size: %ld\n", int_vector_get_size(copy_v));
    printf("-Now vector's copy looks like: ");
    for(i = 0; i < copy_v->size; ++i)
    {
        printf("%d ", int_vector_get_item(copy_v, i));
    }
    printf("\n");
    printf("-Lets free memory-\n");
    int_vector_free(v);
    int_vector_free(copy_v);
    printf("-Now memory is free-\n");
    //Проверка Ресайза
    IntVector *vc = int_vector_new(10);
    printf("-Create vector again-\n");
    printf(" Capacity: %ld\n", int_vector_get_capacity(vc));
    printf(" Size: %ld\n", int_vector_get_size(vc));
    int_vector_resize(vc,5);
    printf("-Resize vector-\n");
    printf(" Size: %ld\n", int_vector_get_size(vc));
    printf("-Now vector looks like: ");
    for(i = 0; i < vc->size; i++)
    {
        printf("%d ", int_vector_get_item(vc, i));
    }
    printf("\n");

    printf(" Capacity: %ld\n", int_vector_get_capacity(vc));
    printf("-Set items-\n");
    for(i = 0; i < vc->size; ++i)
    {
        int_vector_set_item(vc, i, i);
    }
    printf("There're what we set: ");
    for(i = 0; i < vc->size; ++i)
    {
        printf("%d ", int_vector_get_item(vc, i));
    }
    printf("\n");
    int_vector_resize(vc, 7);
    printf("-Resize vector-\n");
    printf(" Size: %ld\n", int_vector_get_size(vc));
    printf("-Now vector looks like: ");
    for(i = 0; i < vc->size; i++)
    {
        printf("%d ", int_vector_get_item(vc, i));
    }
    printf("\n");
    printf(" Capacity: %ld\n", int_vector_get_capacity(vc));
    int_vector_free(vc);
    return 0;
}