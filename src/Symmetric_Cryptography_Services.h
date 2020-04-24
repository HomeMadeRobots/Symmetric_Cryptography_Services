#ifndef SYMMETRIC_CRYPTOGRAPHY_SERVICES_H
#define SYMMETRIC_CRYPTOGRAPHY_SERVICES_H

/* Data type */
#include <stdint.h>
#include "E_Crypto_Action.h"
#include "E_Crypto_Session_Request_Status.h"
#include "E_Crypto_Session_Status.h"

/* For Asynchronous_Operation */
#include "Asynchronous_Operation_Manager.h"

/* Client_Server_Interface */
/* Gathers operations that can be realized by a server Component_Type providing
symmetric cryptography services. */
typedef struct  {
    
	/*------------------------------------------------------------------------*/
	/* Asynchronous_Operation */
	/* Allows to open a session between a client and a cryptographic server.

	The key size depends on the kind of the algorithm.

	If the server is full (not able to manage an additional client), the 
    operation is refused : request_status and client_id are not set by the
    server.

	If the server is available, the operation is accepted. 
	If the key is valid, request_status is set to SESSION_OPENED and client_id
    is set to any valid value ( > 0). This ID will be used by the client for 
    further communications with the server.
	If the key is invalid, request_status is set to INVALID_KEY and client_id is
    set to 0 (invalid client ID). The client will not be able to communicate 
    with the server. */
    void (*Open_Session) (
		const Asynchronous_Operation_Manager* async_op_mgr, 
		const uint8_t* key,
		E_Crypto_Session_Request_Status* request_status,
		uint8_t* client_id );


	/*------------------------------------------------------------------------*/
    /* Synchronous_Operation */
    /* Allows the client of a crypto server to close its opened session. */
    void (*Close_Session) ( uint8_t client_id );


	/*------------------------------------------------------------------------*/
	/* Synchronous_Operation */
    /* A the client of a crypto server to know the status of its session.

	If the client_id is unknown by the server or invalid (=0), the server will
    return a status to UNKNOWN_CLIENT.

	If the client_id is known by the server, the server will return a status to
    IDLE if there is no	pending request, it will return MESSAGE_TREATMENT is if
    the server as queued a request.	*/
	void (*Get_Session_Status) ( 
        uint8_t client_id,
        E_Crypto_Session_Status* status );


	/*------------------------------------------------------------------------*/
	/* Asynchronous_Operation */
	/* Allows the client of a cryptographic server to request the treatment of 
    a message.

	If the client_id is unknown by the server or invalid (=0), the server will
    refuse the operation.

	The client shall specify the number of bytes of the message to treat using
    the message_length input argument.
	The client shall specify the cryptographic operation using the action
    argument : CIPHER or DECIPHER.
	The treated message is provided by the server through the output_message 
    output argument. */
    void (*Treat_Message) (
		const Asynchronous_Operation_Manager* async_op_mgr, 
		uint8_t client_id,
		const uint8_t* input_message,
		uint16_t message_length,
		E_Crypto_Action action,
		uint8_t* output_message );
	
} Symmetric_Cryptography_Services;

#endif