#include <stdio.h>
#include <stdlib.h>
#include "include/http_parser.h"

int	main(int argc, char **argv)
{
	char response[] = "Content-Type:test\r\nOrigin:lol.com\r\nLocation: google.fr";
	http_parsed_t *http_response_parsed;

	http_list_t *parsed_data = http_parsers(response);
	
	http_response_parsed = get(parsed_data, "Location");
	if(http_response_parsed)
		printf("Header => %s\nValue => %s\n", http_response_parsed->header, http_response_parsed->value);		
	else 
		printf("Unknow header\n");
	return(0);
}	
