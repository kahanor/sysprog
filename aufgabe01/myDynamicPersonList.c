#include <stdlib.h>
#include <stdio.h>
#include "myDynamicPersonList.h"
#include <string.h>

/*
 * Erstellt neuen node fuer verkettete Listen
 */
node* create_new_node( char** a_forename, char** a_surname )
{
  node* new_node = malloc( sizeof(node) );
  new_node->next = NULL;
  new_node->forename = *a_forename;
  new_node->surname = *a_surname;
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
  else if ( strcmp( a_head->surname, new_node->surname ) > 0 || ( strcmp( a_head->surname, new_node->surname ) == 0 && strcmp( a_head->forename, new_node->forename ) > 0 ) )
  {
    // Wenn new_node kleiner als a_head ist, wird new_node vor a_head eingefuegt und new_node zurueckgegeben
    new_node->next = a_head;
    return new_node;
  }
  else
  {
    // Wenn new_node groesser als a_head ist wird die Liste bis zu dem Punkt durchgegangen, wo new_node hingehoert
    node* cursor = a_head;
    while( cursor->next != NULL && strcmp( cursor->next->surname, new_node->surname ) < 0 )
    {
      if ( strcmp( cursor->next->surname, new_node->surname ) == 0 && strcmp( cursor->next->forename, new_node->forename ) > 0 )
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
  node* cursor = a_head;
  while ( cursor != NULL )
  {
    printf("%s %s\n", cursor->forename, cursor->surname );
    cursor = cursor->next;
  }
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
  FILE* fp = fopen ( a_filename, "r" );
  if ( fp!=NULL )
  {
    while ( 1 )
    {
      char* next_forename = malloc( 100 * sizeof(char) );
      char* next_surname = malloc( 100 * sizeof(char) );
      if ( fscanf( fp, "%s", next_forename ) == EOF || fscanf( fp, "%s", next_surname ) == EOF )
      {
        free( next_forename );
        free( next_surname );
        break;
      }
      node* new_node = create_new_node( &next_forename, &next_surname );
      head = insert_sorted( head, new_node );
    }
    fclose ( fp );
  }
  return head;
}
