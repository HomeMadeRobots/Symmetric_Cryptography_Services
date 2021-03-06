#ifndef E_CRYPTO_SESSION_REQUEST_STATUS_H
#define E_CRYPTO_SESSION_REQUEST_STATUS_H

/* Enumerated_Data_Type */
/*
Allows to model a data representing the status of a opening session request from
a client to a cryptographic server.
*/
typedef enum {
    /* The key has been checked and is invalid. */
    CRYPTO_SESSION_REQUEST_STATUS_INVALID_KEY,
    
    /* The session is opened. The key has been checked and is correct. */
    CRYPTO_SESSION_REQUEST_STATUS_SESSION_OPENED

} E_Crypto_Session_Request_Status;

#endif