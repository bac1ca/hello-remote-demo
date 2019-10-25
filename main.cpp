#include <iostream>
#include <sys/utsname.h>

int main()  {
    struct utsname name{};
    if(uname(&name)) exit(-1);
    std::cout << "Hello!!! Your computer's OS is " << name.sysname << " " << name.release << std::endl;

#if defined(__APPLE__) && defined(__MACH__)
    std::cout << "OS: APPLE" << std::endl;
#elif defined(__linux__)
    std::cout << "OS: LINUX" << std::endl;
#else //#if defined(_WIN32) || defined(_WIN64)
    std::cout << "OS: WINDOWS" << std::endl;
#endif

    return 0;
}