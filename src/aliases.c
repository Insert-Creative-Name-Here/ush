#include "ush.h"

char *aliases[] = {
    "m"
};

char *alias_expansion[] = {
    "make"
};

int num_aliases(void) {
    return sizeof(aliases) / sizeof(char *);
}
