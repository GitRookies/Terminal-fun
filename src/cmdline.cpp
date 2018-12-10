#include "cmdline.h"

std::string CommandLine :: m_no_of_process;
std::string CommandLine :: m_my_port;
std::string CommandLine :: m_next_port;
std::string CommandLine :: m_prev_port;

bool CommandLine :: m_no_exec = false;

void CommandLine :: parse(int argc, char * const argv[]) {
    int c;
    const char *options = "n:p:t:m:h";
    opterr = 0;

    // Parsing using getopt() API...
    while ((c = getopt (argc, argv, options)) != -1) {
        switch (c) {

            case 'n':   // Next port no.
                m_next_port = std::string(optarg);
                break;
            
            case 'p':   // Prev port no.
                m_prev_port = std::string(optarg);
                break;
            
            case 't':   // Total no of processes.
                m_no_of_process = std::string(optarg);
                break;
            
            case 'm':   // My port no.
                m_my_port = std::string(optarg);
                break;
            
            case 'h':   // Usage message.
                m_no_exec = true;
                SHOW_USAGE();
                break;
            
            case '?':   // Arg value missing.
                m_no_exec = true;
                if(std::string(options).find(optopt) == std::string::npos)
                    throw std::invalid_argument("Unknown option -" + std::to_string(optopt));
                    //std::cerr << "Unknown option -" << optopt << std::endl;
                else
                    throw std::invalid_argument("Option -" + std::to_string(optopt) + " requires a value."); //FIXME
                    //std::cerr << "Option -" << optopt << " requires a value." << std::endl;
                
            default:
                m_no_exec = true;
                throw std::invalid_argument("getopt() unknown error.");
        }
    }


}