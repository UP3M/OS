#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define MinHardlink 2
#define display 0
#define Directory "./tmp"

void findLink(const char *path, const ino_t inum[], int index) {
    struct stat stats;
    struct dirent *opNew;
    char buffer[1024];
    DIR *dir_2 = opendir(path);
    while ((opNew = readdir(dir_2)) != NULL) {
        snprintf(buffer, sizeof(buffer), "%s/%s", path, opNew->d_name);
        stat(buffer, &stats);
        if (inum[index] == stats.st_ino) {
            printf("%s ", opNew->d_name);
        }
    }
    closedir(dir_2);
    printf("\n");
}


int compare(const ino_t inum[], struct stat stats) {

    int flag = 0;
    for (int i = 0; i < 10; i++) {
        if (inum[i] == stats.st_ino) {
            flag = 1;
            break;
        }
    }
    if (flag)
        return 1;
    return 0;
}


int main() {
    const char *path = Directory;
    DIR *dir = opendir(path);

    struct dirent *ent;
    struct stat stats;
    char buf[1024];
    ino_t inum[10] = {0};
    int index = 0;
    while ((ent = readdir(dir)) != NULL) {
        snprintf(buf, sizeof(buf), "%s/%s", path, ent->d_name);
        if (stat(buf, &stats) < 0) {
            perror("stats");
            continue;
        }

        if (display == 1) {
            if (compare(inum, stats) == 1)
                continue;
        }

        if (!S_ISREG(stats.st_mode))
            continue;
        if (stats.st_nlink >= MinHardlink
      ) {
            inum[index] = stats.st_ino;
            printf("%s(%lu) -> ", ent->d_name, inum[index]);
        } else { continue; }

        findLink(path, inum, index);

        index++;
    }
    closedir(dir);

    return 0;
}