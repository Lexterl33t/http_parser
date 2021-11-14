#pragma once

typedef struct http_parsed http_parsed_t;

struct http_parsed {
	char *header;
	char *value;
	http_parsed_t *next;	
};

typedef struct http_list http_list_t;

struct http_list {
	http_parsed_t *first;
};	

http_list_t *init_http_list();
http_parsed_t *insert_header_and_value(http_list_t *list, char *header, char *value);
http_list_t *http_parser(char *header_result);
http_parsed_t *get(http_list_t *list, char *header);
void print_all(http_list_t *list);
