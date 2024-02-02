#include "cli/cli.h"
#include "fmt/fmt.h"

int main(int argc, char *argv[]) {
    CliParser *parser = cli_parser_create("MyApp");
    
    if (parser == NULL) {
        fmt_fprintf(stderr, "Failed to create CLI parser\n");
        return -1;
    }


    // Deallocate the CLI parser and all associated resources
    cli_parser_deallocate(parser);
    return 0;
}
