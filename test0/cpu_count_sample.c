#include <stdio.h>
#include <sys/sysinfo.h>
//-------------------------
//(c)Dirk-Jan Kroon on 2010-06-09
//-------------------------
#ifdef _WIN32
#include <windows.h>
#elif MACOS
#include <sys/param.h>
#include <sys/sysctl.h>
#else
#include <unistd.h>
#endif

int getNumberOfCores() {
#ifdef WIN32
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    return sysinfo.dwNumberOfProcessors;
#elif MACOS
    int nm[2];
    size_t len = 4;
    uint32_t count;
 
    nm[0] = CTL_HW; nm[1] = HW_AVAILCPU;
    sysctl(nm, 2, &count, &len, NULL, 0);
 
    if(count < 1) {
    nm[1] = HW_NCPU;
    sysctl(nm, 2, &count, &len, NULL, 0);
    if(count < 1) { count = 1; }
    }
    return count;
#else
    return sysconf(_SC_NPROCESSORS_ONLN);
#endif
}
//-----------------------------------------
//(c)Dirk-Jan Kroon on 2010-06-09 (end)
//-----------------------------------------

//-----------------------------------------
//(c)https://stackoverflow.com/questions/4586405/how-to-get-the-number-of-cpus-in-linux-using-c
//-----------------------------------------
int main(int argc, char *argv[])
{
    printf("This system has %d processors configured and "
        "%d processors available.\n",
        get_nprocs_conf(), get_nprocs());
        
        
    printf("Second method: cpu cores =%d\n"getNumberOfCores() )
    return 0;
}
//-----------------------------------------
//(c)https://stackoverflow.com/questions/4586405/how-to-get-the-number-of-cpus-in-linux-using-c (end)
//-----------------------------------------