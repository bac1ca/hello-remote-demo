#include <iostream>
#include <fstream>
#include <string>
#include <sys/utsname.h>

void readProcInfo();

int main()  {
    struct utsname name{};
    if(uname(&name)) exit(-1);
    std::cout << "Hello!!! Your computer's OS is " << name.sysname << " " << name.release << std::endl;

#if defined(__APPLE__) && defined(__MACH__)
    std::cout << "OS: APPLE" << std::endl;
#elif defined(__linux__)
    std::cout << "OS: LINUX" << std::endl;
    readProcInfo();
#else //#if defined(_WIN32) || defined(_WIN64)
    std::cout << "OS: WINDOWS" << std::endl;
#endif

    return 0;
}

void readProcInfo() {
    std::string line;
    std::ifstream myfile ("/proc/cpuinfo");
    std::cout << "\n\n------------- /proc/cpuinfo -----------" << std::endl;
    if (myfile.is_open()) {
        while ( getline (myfile,line) ){
            std::cout << line << '\n';
        }
        myfile.close();
    }
}
