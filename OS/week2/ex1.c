#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int i = INT_MIN;
    float f = FLT_MAX;
    double d = DBL_MAX;

    printf("Values:\ni = %lu\nf = %lu\nd = %lu", i, f, d);
    printf("\nSizes:\ni = %lu\nf = %lu\nd = %lu", sizeof(i), sizeof(f), sizeof(d));

    return 0;
}
