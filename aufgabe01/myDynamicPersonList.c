#include <stdlib.h>
#include <stdio.h>
#include "myDynamicPersonList.h"
#include <string.h>

/*
 * Erstellt neuen node fuer verkettete Listen
 */
node* create_new_node( char* a_forename, char* a_surname )
{
  node* new_node = malloc( sizeof(node) );
  new_node->next = NULL;
  printf( "7" );
  //return new_node;
  new_node->forename = malloc( 100 * sizeof(char) );
  new_node->surname = malloc( 100 * sizeof(char) );
  printf( "8" );
  return new_node;
  strcpy( new_node->forename, a_forename );
  printf( "9" );
  return new_node;
  strcpy( new_node->surname, a_surname );
  return new_node;
}

/*
 * Fuegt node in sortierte Liste ein
 */
node* insert_sorted( node* a_head, node* new_node )
{
  if ( a_head == NULL )
  {
    // Wenn a_head == NULL gilt wird der neue node als erstes in die Liste eingefuegt
    a_head = new_node;
    return a_head;
  }
  else if ( strcmp( a_head->surname, new_node->surname ) < 0 || ( strcmp( a_head->surname, new_node->surname ) == 0 && strcmp( a_head->forename, new_node->forename ) < 0 ) )
  {
    // Wenn new_node kleiner als a_head ist, wird new_node vor a_head eingefuegt und new_node zurueckgegeben
    new_node->next = a_head;
    return new_node;
  }
  else
  {
    // Wenn new_node groesser als a_head ist wird die Liste bis zu dem Punkt durchgegangen, wo new_node hingehoert
    node* cursor = a_head;
    node* pre_cursor = NULL;
    while( cursor->next != NULL && strcmp( cursor->next->surname, new_node->surname ) > 0 )
    {
      if ( strcmp( cursor->next->surname, new_node->surname ) == 0 && strcmp( cursor->next->forename, new_node->forename ) < 0 )
      {
        break;
      }
      cursor = cursor->next;
    }
    new_node->next = cursor->next;
    cursor->next = new_node;
    return a_head;
  }

}

/*
 * Gibt Liste aus
 */
void print_list( node* a_head )
{
  char* text = "";
  node* cursor = a_head;
  while ( cursor != NULL )
  {
    strcat( text, cursor->forename );
    strcat( text, " " );
    strcat( text, cursor->surname );
    strcat( text, "\n" );
    cursor = cursor->next;
  }
  printf( text );
}

/*
 * Gibt den allokierten Speicherplatz einer Liste frei
 */
void free_list( node* a_head )
{
  node* cursor = a_head;
  while ( cursor != NULL )
  {
    node* next = cursor->next;
    free( cursor->forename );
    free( cursor->surname );
    free( cursor );
    cursor = next;
  }
}

/*
 * liest Datei in Liste ein.
 */
node* read_file( const char* a_filename )
{
  node* head = NULL;
  printf( "2" );
  //return head;
  FILE* fp = fopen ( a_filename, "r" );
  printf( "3" );
  //return head;
  if ( fp!=NULL )
  {
    while ( 1 )
    {
      printf( "4" );
      //return head;
      char* next_forename;
      char* next_surname;
      if ( fscanf( fp, "%s", &next_forename ) == EOF || fscanf( fp, "%s", &next_surname ) == EOF )
      {
        printf( "0" );
        return head;
        break;
      }
      printf( "5" );
      //return head;
      printf( "%s %s\n", next_forename, next_surname );
      return head;
      node* new_node = create_new_node( next_forename, next_surname );
      printf( "6" );
      return head;
      head = insert_sorted( head, new_node );
    }
    fclose ( fp );
  }
  return head;
}
