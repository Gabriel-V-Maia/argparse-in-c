#define _GNU_SOURCE
#include <argp.h>
#include <stdio.h>
#include <stdlib.h>

const char* argp_program_version     = "manpagehatespreader 0.1";
const char* argp_program_bug_address = "odeioMANpages@email.com";

typedef struct {
    int debug;
} Args;

static struct argp_option options[] = {
    {"debug", 'd', 0, 0, "Habilita debug", 0}, {0}};


static error_t parse_opt(int key, char* arg, struct argp_state* state)
{
  Args *args = state->input;
  
    switch (key) {
        case 'd':
            args->debug = 1;
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp argp_config = { options, parse_opt, 0, "meu programa" };

int main(int argc, char* argv[])
{
    Args args = {0};  

    argp_parse(&argp_config, argc, argv, 0, 0, &args);

    if (args.debug)
        printf("debug ativo\n");

    return 0;
}
