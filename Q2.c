#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
char buff0[1000001], buff1[1000001];

int main(int argc, char *argv[])
{

    long long int i = 0, s, size1, ans;
    int ch = 0, count = 0, var = 0;
    int fp1 = open(argv[1], O_RDONLY);
    int fp2 = open(argv[2], O_RDONLY);
    struct stat fileStat;
    if (stat(argv[3], &fileStat) == 0 && S_ISDIR(fileStat.st_mode))
    {
        write(1, "Directory is created: Yes\n", strlen("Directory is created: Yes\n"));
    }
    else
    {
        write(1, "Directory is created: No\n", strlen("Directory is created: No\n"));
    }

    long long int cnt = lseek(fp1, 0, SEEK_END);

    while (i < cnt / 1000000)
    {
        i++;

        lseek(fp1, -i * 1000000, SEEK_END);
        read(fp1, buff0, 1000000);
        read(fp2, buff1, 1000000);
        for (int i = 0; i < 1000000; i++)
        {
            if (buff0[i] == buff1[99999 - i])
            {
                count = 0;
            }
            else
            {
                count = 1;
                break;
            }
        }
        if (count == 1)
            break;
        int yo = cnt % 1000000;

        lseek(fp1, 0, SEEK_SET);

        read(fp1, buff0, yo);
        read(fp2, buff1, yo);
        for (int i = 0; i < yo; i++)
        {
            if (buff0[i] == buff1[yo - i])
            {
                count = 0;
            }
            else
            {
                count = 1;
                break;
            }
        }
        if (count == 1)
            break;
    }
    if (count == 0)
    {
        write(1, "Whether file contents are reversed in newfile : Yes\n", strlen("Whether file contents are reversed in newfile : Yes"));
    }
    else
    {
        write(1, "Whether file contents are reversed in newfile : No\n", strlen("Whether file contents are reversed in newfile : No"));
    }
    write(1, "\n\n", 2);
    /////////////////////////////////////////////////1
    write(1, "Old-File-Permissions :  \n", strlen("\nOld-File-Permissions :  \n"));
    write(1, "\n\n", 2);
    if (stat(argv[1], &fileStat) < 0)
    {
        write(1, "error reading file\n\n", 20);
    }
    else
    {
        ///user
        if (fileStat.st_mode & S_IRUSR)
            write(1, "User has read permission on oldfile: Yes\n", strlen("User has read permissioin on oldfile: Yes\n"));
        else
            write(1, "User has read permission on oldfile: No\n", strlen("User has read permissioin on oldfile: No\n"));
    }

    if (fileStat.st_mode & S_IWUSR)
    {
        write(1, "User has write permission on oldfile: Yes\n", strlen("User has write permissioin on oldfile: Yes\n"));
    }
    else
    {
        write(1, "User has write permission on oldfile: No\n", strlen("User has write permissioin on oldfile: No\n"));
    }

    if (fileStat.st_mode & S_IXUSR)
    {
        write(1, "User has execute permission on oldfile: Yes\n", strlen("User has write permissioin on oldfile: Yes\n"));
    }
    else
    {
        write(1, "User has execute permission on oldfile: No\n", strlen("User has write permissioin on oldfile: No\n"));
    }
    write(1, "\n\n\n", 3);
    //group
    if (fileStat.st_mode & S_IRGRP)
        write(1, "group has read permission on oldfile: Yes\n", strlen("group has read permissioin on oldfile: Yes\n"));
    else
        write(1, "group has read permission on oldfile: No\n", strlen("group has read permissioin on oldfile: No\n"));

    if (fileStat.st_mode & S_IWGRP)
    {
        write(1, "group has write permission on oldfile: Yes\n", strlen("group has write permissioin on oldfile: Yes\n"));
    }
    else
    {
        write(1, "group has write permission on oldfile: No\n", strlen("group has write permissioin on oldfile: No\n"));
    }

    if (fileStat.st_mode & S_IXGRP)
    {
        write(1, "group has execute permission on oldfile: Yes\n", strlen("group has write permissioin on oldfile: Yes\n"));
    }
    else
    {
        write(1, "group has execute permission on oldfile: No\n", strlen("group has write permissioin on oldfile: No\n"));
    }
    write(1, "\n\n\n", 3);
    ///other
    if (fileStat.st_mode & S_IROTH)
        write(1, "other has read permission on oldfile: Yes\n", strlen("other has read permissioin on oldfile: Yes\n"));
    else
        write(1, "other has read permission on oldfile: No\n", strlen("other has read permissioin on oldfile: No\n"));

    if (fileStat.st_mode & S_IWOTH)
    {
        write(1, "other has write permission on oldfile: Yes\n", strlen("other has write permissioin on oldfile: Yes\n"));
    }
    else
    {
        write(1, "other has write permission on oldfile: No\n", strlen("other has write permissioin on oldfile: No\n"));
    }

    if (fileStat.st_mode & S_IXOTH)
    {
        write(1, "other has execute permission on oldfile: Yes\n", strlen("other has write permissioin on oldfile: Yes\n"));
    }
    else
    {
        write(1, "other has execute permission on oldfile: No\n", strlen("other has write permissioin on oldfile: No\n"));
    }
    write(1, "\n\n\n", 3);
    ///////////////////////////////////////////////////////////2
    write(1, "New-File-Permissions :  \n", strlen("New-File-Permissions :  "));
    write(1, "\n\n", 2);
    struct stat fileStat1;
    if (stat(argv[2], &fileStat1) < 0)
    {
        write(1, "error reading file\n\n", 20);
    }
    else
    {
        ///user
        if (fileStat1.st_mode & S_IRUSR)
            write(1, "User has read permission on newfile: Yes\n", strlen("User has read permissioin on newfile: Yes\n"));
        else
            write(1, "User has read permission on newfile: No\n", strlen("User has read permissioin on newfile: No\n"));
    }

    if (fileStat1.st_mode & S_IWUSR)
    {
        write(1, "User has write permission on newfile: Yes\n", strlen("User has write permissioin on newfile: Yes\n"));
    }
    else
    {
        write(1, "User has write permission on newfile: No\n", strlen("User has write permissioin on newfile: No\n"));
    }

    if (fileStat1.st_mode & S_IXUSR)
    {
        write(1, "User has execute permission on newfile: Yes\n", strlen("User has write permissioin on newfile: Yes\n"));
    }
    else
    {
        write(1, "User has execute permission on newfile: No\n", strlen("User has write permissioin on newfile: No\n"));
    }
    write(1, "\n\n\n", 3);
    //group
    if (fileStat1.st_mode & S_IRGRP)
        write(1, "group has read permission on newfile: Yes\n", strlen("group has read permissioin on newfile: Yes\n"));
    else
        write(1, "group has read permission on newfile: No\n", strlen("group has read permissioin on newfile: No\n"));

    if (fileStat1.st_mode & S_IWGRP)
    {
        write(1, "group has write permission on newfile: Yes\n", strlen("group has write permissioin on newfile: Yes\n"));
    }
    else
    {
        write(1, "group has write permission on newfile: No\n", strlen("group has write permissioin on newfile: No\n"));
    }

    if (fileStat1.st_mode & S_IXGRP)
    {
        write(1, "group has execute permission on newfile: Yes\n", strlen("group has write permissioin on newfile: Yes\n"));
    }
    else
    {
        write(1, "group has execute permission on newfile: No\n", strlen("group has write permissioin on newfile: No\n"));
    }
    write(1, "\n\n\n", 3);
    ///other
    if (fileStat1.st_mode & S_IROTH)
        write(1, "other has read permission on newfile: Yes\n", strlen("other has read permissioin on newfile: Yes\n"));
    else
        write(1, "other has read permission on newfile: No\n", strlen("other has read permissioin on newfile: No\n"));

    if (fileStat1.st_mode & S_IWOTH)
    {
        write(1, "other has write permission on newfile: Yes\n", strlen("other has write permissioin on newfile: Yes\n"));
    }
    else
    {
        write(1, "other has write permission on newfile: No\n", strlen("other has write permissioin on newfile: No\n"));
    }

    if (fileStat1.st_mode & S_IXOTH)
    {
        write(1, "other has execute permission on newfile: Yes\n", strlen("other has write permissioin on newfile: Yes\n"));
    }
    else
    {
        write(1, "other has execute permission on newfile: No\n", strlen("other has write permissioin on newfile: No\n"));
    }
    write(1, "\n\n\n", 3);
    ////////////////////////////////////////////3
    write(1, "Directory-Permissions :  \n", strlen("Directory-Permissions :  "));
    write(1, "\n\n", 2);
    struct stat fileStat2;
    if (stat(argv[2], &fileStat2) < 0)
    {
        write(1, "error reading file\n\n", 20);
    }
    else
    {
        ///user
        if (fileStat2.st_mode & S_IRUSR)
            write(1, "User has read permission on directory: Yes\n", strlen("User has read permissioin on directory: Yes\n"));
        else
            write(1, "User has read permission on directory: No\n", strlen("User has read permissioin on directory: No\n"));
    }

    if (fileStat2.st_mode & S_IWUSR)
    {
        write(1, "User has write permission on directory: Yes\n", strlen("User has write permissioin on directory: Yes\n"));
    }
    else
    {
        write(1, "User has write permission on directory: No\n", strlen("User has write permissioin on directory: No\n"));
    }

    if (fileStat2.st_mode & S_IXUSR)
    {
        write(1, "User has execute permission on directory: Yes\n", strlen("User has write permissioin on directory: Yes\n"));
    }
    else
    {
        write(1, "User has execute permission on directory: No\n", strlen("User has write permissioin on directory: No\n"));
    }
    write(1, "\n\n\n", 3);
    //group
    if (fileStat2.st_mode & S_IRGRP)
        write(1, "group has read permission on directory: Yes\n", strlen("group has read permissioin on directory: Yes\n"));
    else
        write(1, "group has read permission on directory: No\n", strlen("group has read permissioin on directory: No\n"));

    if (fileStat2.st_mode & S_IWGRP)
    {
        write(1, "group has write permission on directory: Yes\n", strlen("group has write permissioin on directory: Yes\n"));
    }
    else
    {
        write(1, "group has write permission on directory: No\n", strlen("group has write permissioin on directory: No\n"));
    }

    if (fileStat2.st_mode & S_IXGRP)
    {
        write(1, "group has execute permission on directory: Yes\n", strlen("group has write permissioin on directory: Yes\n"));
    }
    else
    {
        write(1, "group has execute permission on directory: No\n", strlen("group has write permissioin on directory: No\n"));
    }
    write(1, "\n\n\n", 3);
    ///other
    if (fileStat2.st_mode & S_IROTH)
        write(1, "other has read permission on directory: Yes\n", strlen("other has read permissioin on directory: Yes\n"));
    else
        write(1, "other has read permission on directory: No\n", strlen("other has read permissioin on directory: No\n"));

    if (fileStat2.st_mode & S_IWOTH)
    {
        write(1, "other has write permission on directory: Yes\n", strlen("other has write permissioin on directory: Yes\n"));
    }
    else
    {
        write(1, "other has write permission on directory: No\n", strlen("other has write permissioin on directory: No\n"));
    }

    if (fileStat2.st_mode & S_IXOTH)
    {
        write(1, "other has execute permission on directory: Yes\n", strlen("other has write permissioin on directory: Yes\n"));
    }
    else
    {
        write(1, "other has execute permission on directory: No\n", strlen("other has write permissioin on directory: No\n"));
    }

    write(1, "\n\n\n", 3);
}
