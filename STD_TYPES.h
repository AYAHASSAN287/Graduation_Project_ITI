/******************************************/
/* Auther :Manar 					     */
/*Date :4 Feb 2019                      */
/* Version :V01                        */
/**************************************/
/**Description */
/*--------------                     */
/*This component is used to define the basic standard */
/*types used in sys developes in couurse */
/* header file gaurds*/

#ifndef STD_TYPES_H
#define STD_TYPES_H
/* unsigned 8 bits type 				*/
typedef unsigned char u8;

/* unsigned 16 bits type 				*/
typedef unsigned short int u16;

/* unsigned 32 bits type				 */
typedef unsigned long int u32;

/* signed 8 bits type 					*/
typedef signed char s8;

/* signed 16 bits type 			     	*/
typedef signed short int s16;

/* signed 32 bits type				   */
typedef signed long int s32;

/*float 32 bits type				   */
typedef float f32 ;
/*float 64 bits type 				  */
typedef double f64 ;
/*8bit reg*/
typedef union
{
	struct
	{
		u8 BIT0 :1;
		u8 BIT1 :1;
		u8 BIT2 :1;
		u8 BIT3 :1;
		u8 BIT4 :1;
		u8 BIT5 :1;
		u8 BIT6 :1;
		u8 BIT7 :1;
	}BitAccess;
	u8 ByteAccess;
}Register_8bit;
typedef union
	{
		struct
		{
			u32 BIT0:1;
			u32 BIT1:1;
			u32 BIT2:1;
			u32 BIT3:1;
			u32 BIT4:1;
			u32 BIT5:1;
			u32 BIT6:1;
			u32 BIT7:1;
			u32 BIT8:1;
			u32 BIT9:1;
			u32 BIT10:1;
			u32 BIT11:1;
			u32 BIT12:1;
			u32 BIT13:1;
			u32 BIT14:1;
			u32 BIT15:1;
			u32 BIT16:1;
			u32 BIT17:1;
			u32 BIT18:1;
			u32 BIT19:1;
			u32 BIT20:1;
			u32 BIT21:1;
			u32 BIT22:1;
			u32 BIT23:1;
			u32 BIT24:1;
			u32 BIT25:1;
			u32 BIT26:1;
			u32 BIT27:1;
			u32 BIT28:1;
			u32 BIT29:1;
			u32 BIT30:1;
			u32 BIT31:1;
		}BitAccess;

		u32 ByteAccess;
	}Register_32bit;

#endif
