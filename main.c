#include <stdio.h>
#include <stdlib.h>
#include "include/http_parser.h"

int	main(int argc, char **argv)
{
	char response[] = "Content-Type:test\r\nOrigin:lol.com";
	
	http_list_t *parsed_data = http_parsers(response);
	
	return(0);
}	
