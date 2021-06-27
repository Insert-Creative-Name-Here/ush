#include "aliases.h"

char *aliases[] = {
    "m",
    "v"
};

char *alias_expansion[] = {
    "make",
    "nvim"
};

int num_aliases(void) {
    return sizeof(aliases) / sizeof(char *);
}
