/*
 * C Program to List Files in Directory
 */
#include <dirent.h>
#include <stdio.h>
#include <string.h>
void ListDirectory(const char *dpath) {
  //printf("lising files in %s ----------------------\n", dpath);
  DIR *d;
  struct dirent *dir;
  d = opendir(dpath);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      //printf("looking at %s\n", dir->d_name);
      // Ignore the lost+found folder
      if (strcmp(dir->d_name, ".") == 0)
        continue;
      if (strcmp(dir->d_name, "..") == 0)
        continue;
      if (dir->d_type == DT_DIR) {
        char sub_path[1024];
        snprintf(sub_path, sizeof(sub_path), "%s/%s", dpath, dir->d_name);
        //printf("%s =---------=\n", dir->d_name);
        ListDirectory(sub_path);
        continue;
      }
      //printf("here\n");
      printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
}
int main(void) {
  ListDirectory(".");
  return (0);
}
