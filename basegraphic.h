/*
 * basegraphic.h
 *
 *  Created on: 03-07-2012
 *      Author: Skubany
 */

#ifndef BASEGRAPHIC_H_
#define BASEGRAPHIC_H_

/**
  * @brief   BaseGraphicObject specific methods.
  */
#define _base_graphic_object_methods                                         \
   /* Display graphic.*/                                                     \
   uint32_t (*display)(void *instance, uint16_t x, uint16_t y);

/**
  * @brief   @p BaseGraphicObject specific data.
  */
#define _base_graphic_object_data                                            \
uint16_t sizeX;                                                              \
uint16_t sizeY;


/**
  * @brief   @p BaseGraphicObject virtual methods table.
  */
struct BaseGraphicObjectVMT {
  _base_graphic_object_methods
};

/**
 * @brief   Base graphic object class.
 * @details This class represents a generic graphic object.
 */
typedef struct {
  /** @brief Virtual Methods Table.*/
  const struct BaseGraphicObjectVMT *vmt;
  _base_graphic_object_data
} BaseGraphicObject;

/**
 * @name    Macro Functions (BaseGraphicObject)
 * @{
 */
/**
 * @brief   Display Graphic Object.
 * @details The function displays object on the screen starting from specified
 * point.
 *
 * @param[in] ip        pointer to a @p BaseSequentialStream or derived class
 * @param[in] x         x coordinates
 * @param[in] y         y coordinates
 * @return              todo
 *
 * @api
 */
#define anDisplay(ip, x, y) ((ip)->vmt->display(ip, x, y))
/** @} */

#endif /* BASEGRAPHIC_H_ */
