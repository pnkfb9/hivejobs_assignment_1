#include <stdio.h>
#include <stdlib.h>

#include <dynamic_float_array.h>


void initialize_array(dynamic_float_array_t *ar,size_t size){

  ar->array = (float *)malloc(size * sizeof(float));
  ar->used = 0;
  ar->size = size;

}

void insert_array_element(dynamic_float_array_t *ar, float element){
  
  if(ar->used == ar->size)          //no more space left, adding one more entry
  {
    ar->size += 1;
    ar->array = (float*)realloc(ar->array, ar->size * sizeof(float));
  }
  ar->array[ar->used++] = element;

}

float get_array_element_at(dynamic_float_array_t *ar, int index)
{

    return ar->array[index];
}

int is_valid_array_index(dynamic_float_array_t *ar, int index)
{
    if( index >= 0 && index < ar->used)
    {
      return true;
    }
    else
    {
      return false;
    }
}

void free_array(dynamic_float_array_t *ar)
{
  ar->array = NULL;
  ar->size = ar->used = 0;

}
