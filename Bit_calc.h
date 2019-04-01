/*
 * Bit_calc.h
 *
 *  Created on: Jan 30, 2019
 *      Author: Manar
 */

#ifndef BIT_CALC_H_
#define BIT_CALC_H_

#ifndef Bit_calc_H
#define Bit_calc_H
#define set_bit(var,bit_num) var|=1<<bit_num
#define clr(var,bit_num) var&=~(1<<bit_num)
#define toggle_bit(var,bit_num) var^=(1<<bit_num)
#define Get_Bit(var,bit_num) (((var) & (1<<bit_num))>>bit_num)
#define assign_bit(var,bit_num,value) do{ if (value==1) \
											var|=1<<bit_num; \
											else \
											var&=~(1<<bit_num); \
											 }while(0)



#endif



#endif /* BIT_CALC_H_ */
