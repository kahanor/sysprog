#include <stdlib.h>
#include <stdio.h>
#include "myDynamicPersonList.h"

int main( int argc, char const *argv[] )
{
  if ( argc == 2 )
  {
    node* head = read_file( argv[1] );
    printf( "1" );
    return 0;
    print_list( head );
    free_list( head );
  }
  else
  {
    printf( "Wrong arguments, please try again!" );
  }
  return 0;
}
