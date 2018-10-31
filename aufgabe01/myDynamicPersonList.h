#pragma once

typedef struct node
{
  char* forename;
  char* surname;
  struct node* next;
} node;

/*
 * Erstellt neuen node fuer verkettete Listen
 */
node* create_new_node( char** a_forename, char** a_surname );

/*
 * Fuegt node in sortierte Liste ein
 */
node* insert_sorted( node* a_head, node* new_node );

/*
 * Gibt Liste aus
 */
void print_list( node* a_head );

/*
 * Gibt Speicherplatz einer Liste frei
 */
void free_list( node* a_head );

/*
 * liest Datei in Liste ein.
 */
node* read_file( const char* a_filename );
