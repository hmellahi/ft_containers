#include <stdio.h>
// #i DEBUG
#define INFO(msg) fprintf(stderr, "info: %s:%d: ", __FILE__, __LINE__); fprintf(stderr, "%s", msg);