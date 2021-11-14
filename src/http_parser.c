#include <stdio.h>
#include <stdlib.h>
#include "../include/http_parser.h"

/*
//////////////////////////////////
	INIT LINKED LIST
/////////////////////////////////
*/

http_list_t *init_http_list()
{
	http_list_t *http_list = malloc(sizeof(*http_list)); 
	http_parsed_t *http_parsed = malloc(sizeof(*http_parsed));

	if(http_list == NULL || http_parsed == NULL)
		exit(EXIT_FAILURE);
	
	http_parsed->header = "None";
	http_parsed->value = "NULL";
	http_list->first = http_parsed;

	return(http_list);
}

/*
////////////////////////////////////
       INSERT ELEMENT IN LINKED
     AND RETURN THIS SAME ELEMENT
///////////////////////////////////
*/

http_parsed_t *insert_header_and_value(http_list_t *list, char *header, char *value)
{
	http_parsed_t *http_element = malloc(sizeof(*http_element));

	if(http_element == NULL || list == NULL)
		exit(EXIT_FAILURE);
	
	http_element->header = header;
	http_element->value = value;
	http_element->next = list->first;
	list->first = http_element;
	
	return(http_element);
}

/*
//////////////////////////////////
	  HTTP PARSER
//////////////////////////////////
*/

http_list_t *http_parser(char *response)
{
	char *tmp = response;

	while(*tmp) {
		while(*tmp != '\r' || *tmp != '\n') {
			tmp++;
		}

		printf("%s\n", response);
		tmp++;
	}

	// In working.......
}

/*
///////////////////////////////
	SHOW ALL LINKED
//////////////////////////////
*/

void print_all(http_list_t *list)
{
	if(list == NULL)
		exit(EXIT_FAILURE);

	http_parsed_t *actual_element = list->first;

	while(actual_element != NULL) {
		printf("%s:%s\n", actual_element->header, actual_element->value);
		actual_element = actual_element->next;
	}
}	
