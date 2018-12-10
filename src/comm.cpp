/*
 * comm.cpp
 */
#include <iostream>
#include <exception>
#include "comm.h"
#include "cmdline.h"

uint8_t Communication :: m_no_of_process = 0;
in_port_t Communication :: m_my_port = 0;
in_port_t Communication :: m_next_port = 0;
in_port_t Communication :: m_prev_port = 0;

bool Communication :: m_initialized = false;

void Communication :: init(void) {
    
    // These two are compulsory options.
    try {
        m_no_of_process = std::stoi(CommandLine::nProcess());
        m_my_port = std::stoi(CommandLine::myPort());
    } catch (std::invalid_argument &e) { //stoi() throws logic_error so we must receive that.
        throw std::invalid_argument("Arguments -m and -t are not provided or have invalid values.");
    }

    // Verify other options.
    if(CommandLine::nextPort().empty())
        throw std::invalid_argument("Argument -n missing.");
    if(CommandLine::prevPort().empty())
        throw std::invalid_argument("Argument -p missing.");
    try {
        m_next_port = std::stoi(CommandLine::nextPort());
        m_prev_port = std::stoi(CommandLine::prevPort());
    } catch (std::invalid_argument &e) { //stoi() throws logic_error so we must receive that.
        throw std::invalid_argument("Arguments -n and/or -p might have invalid values.");
    }
    
#if 0
    // Validate arguments provided.
    if(m_no_of_process <= 0) {
        throw std::invalid_argument("No. of processes cannot be <= 0.");
    }

    // Configure the role of the process:
    // - Initiator (id = 0)
    // - Intermediate forwarding node (id = {1..N-2})
    // - Terminator (id = N-1)
    
    if(m_self_id == 0) {
        std::stoi(argv[4]);
    }
#endif
    m_initialized = true;
}

void Communication :: end(void) {
    if(!m_initialized)
        return;
    
    // Destruction code.
}