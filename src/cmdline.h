#ifndef CMDLINE_H_
#define CMDLINE_H_

#include <iostream>
#include <cstdint>
#include <unistd.h>
//#include <sys/types.h>
//#include <sys/socket.h>
#include <netinet/in.h>

class CommandLine {
public:
    static void parse(int argc, char * const argv[]);

    // Other modules can get the values from here.
    static inline std::string nProcess(void) { return m_no_of_process; }
    static inline std::string myPort(void) { return m_my_port; }
    static inline std::string nextPort(void) { return m_next_port; }
    static inline std::string prevPort(void) { return m_prev_port; }

    // Return value:
    //   true:  If the program can proceed further.
    //   false: If the program cannot proceed further
    // It is the opposite meaning of m_no_exec.
    // XXX... Yes it seems complicated on this side, but it is easier
    // in the parse() function to set the value of m_no_exec as its meaning.
    static inline bool execCanProceed(void) { return !m_no_exec; }

private:
    static std::string m_no_of_process;
    static std::string m_my_port, m_next_port, m_prev_port;
    
    // Special flag.
    // This flag indicates the program to not execute its actual(just exit afore) tasks because
    // of some issue in parsing args or if -h arg is provided.
    // For example: If user passes a -h option then the program will not
    // execute its actual tasks. It will just show the usage message string.
    static bool m_no_exec;
};



/*----------------------------
 * Usage message
 *----------------------------
 */
static const std::string usage_str =
    "USAGE:\n  $ term-fun -t <N_processes> -m <my_port_no> [-n <next_port_no> -p <prev_port_no>]\n\n\
  * <N_processes> is the no of cooperative process that will be involved including itself.\n\
  * <my_port_no> is the current process's port no.\n\
  * <next_port_no> are provided for the nodes {1...N-1}.\n\
  * <prev_port_no> are provided for the nodes {2...N}.\n\
  * Both <next_port_no> and <prev_port_no> are provided for nodes {2...N-1}.\n\
  * Example diagram of cooperating processes:\n\n\
    P1 <--> P2 <--> P3 <--> P4 <--> ... <--> P(N-1) <--> P(N)\n\n\
    As you can see P1 has no <prev_port_no> and P(N) has no <next_port_no>.\n\n\
  * If no arguments are provided then the process will just show a simple scroll and exit.";

#define SHOW_USAGE()    std::cout << std::endl << usage_str << std::endl;

//----------------------------

#endif