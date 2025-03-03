#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    int rc1 = trace("test_4.c");
    int x1 = gettracecount();
    
    int i;
    for (i = 0; i < 1000; i++) {
        int f = open("test_4.c", 0x0); // 0x0 is O_RDONLY
        close(f);
    }
    for (i = 0; i < 1000; i++) {
        int f = open("test_3.c", 0x0);
        close(f);
    }
    int x2 = gettracecount();
    int rc2 = trace("test_3.c");
    int x3 = gettracecount();
    int f = open("test_3.c", 0x0);
    close(f);
    int x4 = gettracecount();
    printf(1, "XV6_TEST_OUTPUT %d %d %d %d %d %d\n", rc1, rc2, x1, x2, x3, x4);
    exit();
}
