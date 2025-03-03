#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    int rc1 = trace("test_5.c");
    int x1 = gettracecount();
    int rc2 = fork();

    int i;
    for (i = 0; i < 1000; i++) {
        int f = open("test_5.c", 0x0); // 0x0 is O_RDONLY
        close(f);
    }

    if (rc2 == 0) {
        int i;
        for (i = 0; i < 1000; i++) {
            int f = open("test_5.c", 0x0);
            close(f);
        }
        exit();
    } else {
        wait();
        int x2 = gettracecount();
        int f = open("test_5.c", 0x0);
        close(f);
        int x3 = gettracecount();
        printf(1, "XV6_TEST_OUTPUT %d %d %d %d\n", rc1, x1, x2, x3);
    }
    exit();
}
