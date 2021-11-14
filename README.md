## HTTP Parser

### Using

```c
#include <stdio.h>
#include "include/http_parser.h"

int main(int argc, char **argv)
{
    char response[] = "Content-Type:test\r\nOrigin:lol.com\r\nLocation: google.fr"; // response to parse
    
    http_parsed_t *http_response_parsed; // init pointer to element in linked list
    
    http_list_t *parsed_data = http_parses(response); // parse data
    
    http_response_parsed = get(parsed_data, "Content-Type");
    
    printf("Header => %s\nValue => %s\n"); 
    // Header => Content-Type
    // Value => test 
}
```

