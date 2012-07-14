/*
 * basestring.h
 *
 *  Created on: 03-07-2012
 *      Author: Skubany
 */

#ifndef BASESTRING_H_
#define BASESTRING_H_

/**
  * @brief   BaseStringObject specific methods.
  */
#define _base_string_object_methods                                          \
   /* Get pointer to string.*/                                               \
   void* (*gets)(void *instance, uint16_t n);


/**
  * @brief   @p BaseStringObject specific data.
  */
#define _base_string_object_data

/**
  * @brief   @p BaseStringObject virtual methods table.
  */
struct BaseStringObjectVMT {
     _base_string_object_methods
};

/**
 * @brief   Base string object class.
 * @details This class represents a generic string object.
 */
typedef struct {
  /** @brief Virtual Methods Table.*/
  const struct BaseFontObjectVMT *vmt;
  _base_string_object_data
} BaseStringObject;

/**
 * @name    Macro Functions (BaseStringObject)
 * @{
 */
/**
 * @brief   Get string pointer.
 * @details The function returns pointer to requested string.
 * point.
 *
 * @param[in] ip        pointer to a @p BaseFontObject or derived class
 * @param[in] n         index of string, for simplest derived classes
 *                      might be 0
 * @return              pointer to a string
 *
 * @api
 */
#define anGetString(ip, n) ((ip)->vmt->gets(ip, n))
/** @} */

#endif /* BASESTRING_H_ */
