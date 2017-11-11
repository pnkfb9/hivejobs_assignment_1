#include <stdio.h>
#include <stdlib.h>

#include <dynamic_float_array.h>


int main(void){

 dynamic_float_array_t res;

 initialize_array(&res,3);
 insert_array_element(&res,3.2f);
 insert_array_element(&res,1.2f);
 insert_array_element(&res,4.2f);
 insert_array_element(&res,5.2f);
  insert_array_element(&res,1.2f);
   insert_array_element(&res,12.2f);

 for(int i=0 ; i<10;i++)
 {
   if(is_valid_array_index(&res,i))
   {
     printf("array element: %f\n",get_array_element_at(&res,i));
   }
 }

 return 0;

}
