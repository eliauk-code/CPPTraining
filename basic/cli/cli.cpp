#include <iostream>
#include <getopt.h>

void printHelp()
{
    std::cout << "Usage: cli [options]\n";
    std::cout << "Options:\n";
    std::cout << "  -h, --help     Show this help message\n";
    std::cout << "  -v, --version  Show version information\n";
}
void printVersion()
{
    std::cout << "Version 1.0.0\n";
}
// 这是一个简单的命令行工具，演示了如何处理命令行参数。
// 它支持短选项（-h, -v）和长选项（--help, --version），并且可以接收参数值（-c config.txt）。
// 这个工具的主要功能是打印帮助信息和版本信息，
// 以及处理配置文件参数。
int main(int argc, char *argv[])
{
    // argc: 命令行参数的数量
    // argv: 命令行参数的数组，argv[0] 是程序名，argv[1] 是第一个参数，依此类推
    // 如果没有参数，显示帮助信息
    if (argc == 1)
    {
        printHelp();
        return 0;
    }
    // 处理命令行参数
    // for (int i = 1; i < argc; ++i)
    // {
    //     std::string arg = argv[i];
    //     if (arg == "--help" || arg == "-h")
    //     {
    //         printHelp();
    //         return 0;
    //     }
    //     else if (arg == "--version" || arg == "-v")
    //     {
    //         printVersion();
    //         return 0;
    //     }
    //     else if (arg == "--config" || arg == "-c")
    //     {
    //         if (i + 1 < argc)
    //         {
    //             std::string configFile = argv[++i];
    //             std::cout << "Config file: " << configFile << "\n";
    //         }
    //         else
    //         {
    //             std::cout << "Error: No config file specified\n";
    //             return 1;
    //         }
    //     }
    //     else
    //     {
    //         std::cout << "Unknown option: " << arg << "\n";
    //         std::cout << "Use -h or --help for help.\n";
    //         return 1;
    //     }
    // }
    // 使用 getopt_long 处理命令行参数
    int opt;
    char *configFile = NULL;
    const char *short_options = "c:hv";
    const struct option long_options[] = {
        {"config", required_argument, nullptr, 'c'},
        {"help", no_argument, nullptr, 'h'},
        {"version", no_argument, nullptr, 'v'},
        {nullptr, 0, nullptr, 0}}; // 结束标志
    while ((opt = getopt_long(argc, argv, short_options, long_options, nullptr)) != -1)
    {
        switch (opt)
        {
        case 'h':
            printHelp();
            return 0;
        case 'v':
            printVersion();
            return 0;
        case 'c':
            configFile = optarg;
            if (!configFile)
            {
                std::cout << "Error: No config file specified\n";
                return 1;
            }
            std::cout << "Config file: " << configFile << "\n";
            continue;
        default:
            std::cout << "Unknown option: " << optopt << "\n";
            std::cout << "Use -h or --help for help.\n";
            return 1;
        }
    }

    return 0;
}