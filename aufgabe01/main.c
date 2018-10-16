#include <stdlib.h>
#include <stdio.h>
#include "myDynamicPersonList.h"

int main( int argc, char const *argv[] )
{
  if ( argc == 2 )
  {
    node* head = read_file( argv[1] );
    print_list( head );
    free_list( head );
  }
  else
  {
    printf( "Wrong argument, please give a filename of file in this directory!\n" );
  }
  return 0;
}
