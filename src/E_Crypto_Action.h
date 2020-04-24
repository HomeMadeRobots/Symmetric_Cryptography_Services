#ifndef E_CRYPTO_ACTION_H
#define E_CRYPTO_ACTION_H

/* Enumerated_Data_Type */
/* Allows to model a data representing an action of a symmetric cryptography 
algorithm. */
typedef enum {
    CRYPTO_ACTION_CIPHER,
	CRYPTO_ACTION_DECIPHER
} E_Crypto_Action;

#endif