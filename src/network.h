/* 
*/

#ifndef	_NETWORK_H
# define _NETWORK_H 1

extern int establish_listening_socket ( unsigned short port_number, char *peer_ip_address, int bytes);
extern int connect_to_socket ( char *host_ip_number, unsigned short port_number );

extern int write_to_socket ( int connected_socket, char *buffer, int bytes );
extern int read_from_socket ( int connected_socket, char *buffer, int bytes );

extern void give_local_IP ( char * local_ip_address, int bytes );

#endif	/* _NETWORK_H */
