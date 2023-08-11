/*
 * BIT_MATH.h
 *
 *  Created on: Aug 3, 2023
 *      Author: marka
 */

#ifndef LIBRARY_BIT_MATH_H_
#define LIBRARY_BIT_MATH_H_





#define SET_BIT(REG,BIT_NO) (REG|=(1<<BIT_NO))

#define CLEAR_BIT(REG,BIT_NO) (REG&=(~(1<<BIT_NO)))

#define TOGGLE_BIT(REG,BIT_NO) (REG^=(1<<BIT_NO))

#define GIT_BIT(REG,BIT_NO) ((1>>BIT_NO)&1)


#endif /* LIBRARY_BIT_MATH_H_ */
