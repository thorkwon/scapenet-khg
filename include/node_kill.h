#ifndef _NODEKILL
#define _NODEKILL

#include <pcap.h>
#include <string.h>
#include <unistd.h>
#include "protocol.h"

typedef struct killnode_list {
	u_char target_ip[255];
} killnode_list;

typedef struct network_grub_args {
	killnode_list k_list;
	u_char g_ip;
} network_grub_args;

typedef struct sendkill_grub_args {
	pcap_t *descr;
	device_info *gate_info;
	network_grub_args *n_args;
} sendkill_grub_args;

void *send_kill_packet(void *);
u_char *make_kill_packet(device_info, u_char, u_char);
int gateway_get(const u_char *, u_char, device_info *);

#endif
