/*
 * comm.h
 *
 * Communication protocol between co-worker processes.
 */
#include <unordered_map>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifndef COMM_H_
#define COMM_H_

#if 0
// A hash table of co-worker address list.
typedef
    std::unordered_map<id_type, struct sockaddr_in>
CWList;
#endif

class Communication {
public:
    static void init(void);
    static void end(void);

private:
    //@ static CWList m_CWList;
    static uint8_t m_no_of_process;
    static in_port_t m_my_port, m_next_port, m_prev_port;

    static bool m_initialized;
};

#endif