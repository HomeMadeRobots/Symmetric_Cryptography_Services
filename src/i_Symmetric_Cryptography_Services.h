#ifndef I_SYMMETRIC_CRYPTOGRAPHY_SERVICES_H
#define I_SYMMETRIC_CRYPTOGRAPHY_SERVICES_H

/* Data type */
#include "stdint.h"
#include "E_CRYPTO_ACTION.h"
#include "E_SESSION_REQUEST_STATUS.h"
#include "E_SESSION_STATUS.h"

/* For Asynchronous_Operation */
#include "Asynchronous_Operation_Manager.h"

/* Client_Server_Interface */
/*
Gathers operations that can be realized by a server Component_Type providing symmetric cryptography
services.
*/
class i_Symmetric_Cryptography_Services {
public :
	/*--------------------------------------------------------------------------------------------*/
	/* Asynchronous_Operation */
	/* 
	Allows to open a session between a client and a cryptographic server.

	The key size depends on the kind of the algorithm.

	If the server is full (not able to manage an additional client), the operation is refused : 
	request_status and client_id are not set by the server.

	If the server is available, the operation is accepted. 
	If the key is valid, request_status is set to SESSION_OPENED and client_id is set to any valid 
	value ( > 0). This ID will be used by the client for further communications with the server.
	If the key is invalid, request_status is set to INVALID_KEY and client_id is set to 0 (invalid 
	client ID). The client will not be able to communicate with the server.
	*/
    virtual bool Open_Session( 
		Asynchronous_Operation_Manager* async_op_mgr, 
		const uint8_t* key,
		E_SESSION_REQUEST_STATUS* request_status,
		uint8_t* client_id ) = 0;


	/*--------------------------------------------------------------------------------------------*/
    /* Synchronous_Operation */
    /* Allows the client of a crypto server to close its opened session. */
    virtual void Close_Session( uint8_t client_id ) = 0;


	/*--------------------------------------------------------------------------------------------*/
	/* Synchronous_Operation */
    /*
	A the client of a crypto server to know the status of its session.

	If the client_id is unknown by the server or invalid (=0), the server will return a status to 
	UNKNOWN_CLIENT.

	If the client_id is known by the server, the server will return a status to IDLE if there is no
	pending request, it will return MESSAGE_TREATMENT is if the server as queued a request.
	*/
	virtual void Get_Session_Status( uint8_t client_id, E_SESSION_STATUS* status ) = 0;


	/*--------------------------------------------------------------------------------------------*/
	/* Asynchronous_Operation */
	/*
	Allows the client of a cryptographic server to request the treatment of a message.

	If the client_id is unknown by the server or invalid (=0), the server will refuse the operation.

	The client shall specify the number of bytes of the message to treat using the message_length 
	input argument.
	The client shall specify the cryptographic operation using the action argument : CIPHER or 
	DECIPHER.
	The treated message is provided by the server through the output_message output argument.
	*/
    virtual bool Treat_Message(
		Asynchronous_Operation_Manager* async_op_mgr, 
		uint8_t client_id,
		const uint8_t* input_message,
		uint16_t message_length,
		E_CRYPTO_ACTION action,
		uint8_t* output_message) = 0;
	
};

#endif