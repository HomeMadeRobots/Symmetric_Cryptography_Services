#ifndef E_SESSION_REQUEST_STATUS_H
#define E_SESSION_REQUEST_STATUS_H

/* Enumerated_Data_Type */
/*
Allows to model a data representing the status of a opening session request from a client to a 
cryptographic server.
*/
typedef enum E_SESSION_REQUEST_STATUS {
    INVALID_KEY, /* The key has been checked and is invalid. */
    SESSION_OPENED /* The session is opened. The key has been checked and is correct. */
} E_SESSION_REQUEST_STATUS;

#endif