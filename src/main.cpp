#include "gui.h"
#include <iostream>
#include <string>

void printUsage(const char* programName) {
    std::cout << "Usage: " << programName << " [--adaptive|--simple|--medium|--complex]\n";
    std::cout << "Options:\n";
    std::cout << "  --adaptive   Use adaptive algorithm\n";
    std::cout << "  --simple     Use simple algorithm\n";
    std::cout << "  --medium     Use medium algorithm\n";
    std::cout << "  --complex    Use complex algorithm\n";
    std::cout << "  (no flag)    Run without flag\n";
}

int main(int argc, char* argv[]) {
    std::string flag = "";
    
    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "--adaptive" || arg == "--simple" || arg == "--medium" || arg == "--complex") {
            flag = arg;
        } else if (arg == "--help" || arg == "-h") {
            printUsage(argv[0]);
            return 0;
        } else {
            std::cerr << "Error: Unknown flag '" << arg << "'\n";
            printUsage(argv[0]);
            return 1;
        }
    }
    
    Gui gui(flag);
    gui.loop();
    return 0;
}
