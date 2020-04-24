#ifndef E_CRYPTO_SESSION_STATUS_H
#define E_CRYPTO_SESSION_STATUS_H

/* Enumerated_Data_Type */
/*
Allows to model a data representing the status of a session opened between a 
client and a cryptographic server.
*/
typedef enum {
    /* The client_id has not been allocated by the server. */
    CRYPTO_SESSION_STATUS_UNKNOWN_CLIENT, 

    /* The server has an opened session with the client, but there is no 
    pending request. */
	CRYPTO_SESSION_STATUS_IDLE, 

    /* The server is treating the message from the client. */
    CRYPTO_SESSION_STATUS_MESSAGE_TREATMENT

} E_Crypto_Session_Status;

#endif