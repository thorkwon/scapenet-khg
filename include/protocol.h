#ifndef _PROTOCOL
#define _PROTOCOL

#include <netinet/ip.h>
#include <netinet/tcp.h>

/* ARP Header, (assuming Ethernet+IPv4)            */
#define ARP_REQUEST 1   /* ARP Request             */
#define ARP_REPLY 2     /* ARP Reply               */

typedef struct etherhdr {
	u_char h_dest[6];
	u_char h_source[6];
	unsigned short h_proto;
} etherhdr_t;

typedef struct arphdr {
	u_int16_t htype;    /* Hardware Type           */
	u_int16_t ptype;    /* Protocol Type           */
	u_char hlen;        /* Hardware Address Length */
	u_char plen;        /* Protocol Address Length */
	u_int16_t oper;     /* Operation Code          */
	u_char sha[6];      /* Sender hardware address */
	u_char spa[4];      /* Sender IP address       */
	u_char tha[6];      /* Target hardware address */
	u_char tpa[4];      /* Target IP address       */
}arphdr_t;

typedef struct device_info {
	u_char macaddr[6];
	u_char ipaddr[4];
} device_info;

#endif
