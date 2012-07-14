/*
 * basefont.h
 *
 *  Created on: 03-07-2012
 *      Author: Skubany
 */

#ifndef BASEFONT_H_
#define BASEFONT_H_

/**
  * @brief   BaseFontObject specific methods.
  */
#define _base_font_object_methods                                            \
   /* Printf text object.*/                                                  \
   uint32_t (*printf)(void *instance, void* textinstance,                    \
                      uint16_t x, uint16_t y, ...);                          \
   /* Printf text object.*/                                                  \
   uint32_t (*wprintf)(void *instance, void* textinstance,                   \
                      void *w, ...);                                         \
   /* Set size in pixels (if possoble).*/                                    \
   uint32_t (*setsize)(void *instance, uint8_t size);                        \
   /* Get size of font in pixels.*/                                          \
   uint32_t (*getsize)(void *instance, uint8_t size);                        \
   /* Set font object flag.*/                                                \
   void (*setflag)(void *instance, uint8_t flag);

/**
  * @brief   @p BaseFontObject specific data.
  */
#define _base_font_object_data                                               \
   uint8_t size;                                                             \
   uint8_t flag;

/**
  * @brief   @p BaseFontObject virtual methods table.
  */
struct BaseFontObjectVMT {
     _base_font_object_methods
};

/**
 * @brief   Base font object class.
 * @details This class represents a generic font object.
 */
typedef struct {
  /** @brief Virtual Methods Table.*/
  const struct BaseFontObjectVMT *vmt;
  _base_font_object_data
} BaseFontObject;

/**
 * @name    Macro Functions (BaseFontObject)
 * @{
 */
/**
 * @brief   Display formated string .
 * @details The function displays string stored in BaseStringObject with specified format.
 * point.
 *
 * @param[in] ip        pointer to a @p BaseFontObject or derived class
 * @param[in] sp        pointer to a @p BaseStringObject or derived class
 * @param[in] x         x coordinates
 * @param[in] y         y coordinates
 * @param[in] ...       format parameters
 * @return              todo
 *
 * @api
 */
#define anPrintf(ip, sp, x, y, ...) ((ip)->vmt->printf(ip, sp, x, y, ...))

/**
 * @name    Macro Functions (BaseStringObject)
 * @{
 */
/**
 * @brief   Display formated string in specified window.
 * @details The function displays string stored in BaseStringObject with specified format.
 * point.
 *
 * @param[in] ip        pointer to a @p BaseFontObject or derived class
 * @param[in] sp        pointer to a @p BaseStringObject or derived class
 * @param[in] w         pointer to a @p window_t structure
 * @param[in] ...       format parameters
 * @return              todo
 *
 * @api
 */
#define anWPrintf(ip, sp, w, ...) ((ip)->vmt->wprintf(ip, sp, w, ...))

/**
 * @brief   Set size of font .
 * @details The function set size of font if its not available it returns zero.
 * point.
 *
 * @param[in] ip        pointer to a @p BaseFontObject or derived class
 * @param[in] s         font size
 * @return              font size
 *
 * @api
 */
#define anSetFontSize(ip, s) ((ip)->vmt->setsize(ip, s))

/**
 * @brief   Get size of font.
 * @details The function returns size of font.
 * point.
 *
 * @param[in] ip        pointer to a @p BaseFontObject or derived class
 * @param[in] s         font size
 * @return              font size
 *
 * @api
 */
#define anGetFontSize(ip, s) ((ip)->vmt->getsize(ip, s))


/**
 * @brief   Set font flag.
 * @details The function sets font flag.
 * point.
 *
 * @param[in] ip        pointer to a @p BaseFontObject or derived class
 * @param[in] f         flag value (to display transparent or filled with background color)
 * @noreturn
 *
 * @api
 */
#define anSetFlag(ip, s) ((ip)->vmt->setflag(ip, s))
/** @} */

#endif /* BASEFONT_H_ */
