#ifndef E_SESSION_STATUS_H
#define E_SESSION_STATUS_H

/* Enumerated_Data_Type */
/*
Allows to model a data representing the status of a session opened between a client and a 
cryptographic server.
*/
typedef enum E_SESSION_STATUS {
    SESSION_STATUS_UNKNOWN_CLIENT, /* The client_id has not been allocated by the server. */
	SESSION_STATUS_IDLE, /* The server has an opened session with the client, but there is no 
	                        pending request. */
    SESSION_STATUS_MESSAGE_TREATMENT /* The server is treating the message from the client. */
} E_SESSION_STATUS;

#endif