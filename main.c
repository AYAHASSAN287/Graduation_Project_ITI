/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
#include "stm32f10x_can.h"
#include "Timer.h"
#include "BlinkLed.h"
#include "STD_TYPES.h"
#include "Bit_calc.h"

// ----------------------------------------------------------------------------
//
// Standalone STM32F1 led blink sample (trace via DEBUG).
//
// In debug configurations, demonstrate how to print a greeting message
// on the trace device. In release configurations the message is
// simply discarded.
//
// Then demonstrates how to blink a led with 1 Hz, using a
// continuous loop and SysTick delays.
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//
// The external clock frequency is specified as a preprocessor definition
// passed to the compiler via a command line option (see the 'C/C++ General' ->
// 'Paths and Symbols' -> the 'Symbols' tab, if you want to change it).
// The value selected during project creation was HSE_VALUE=8000000.
//
// Note: The default clock settings take the user defined HSE_VALUE and try
// to reach the maximum possible system clock. For the default 8 MHz input
// the result is guaranteed, but for other values it might not be possible,
// so please adjust the PLL settings in system/src/cmsis/system_stm32f10x.c
//

// ----- Timing definitions -------------------------------------------------

// Keep the LED on for 2/3 of a second.
#define BLINK_ON_TICKS  (TIMER_FREQUENCY_HZ * 3 / 4)
#define BLINK_OFF_TICKS (TIMER_FREQUENCY_HZ - BLINK_ON_TICKS)
#define CAN_MCR ((Register_32bit*)0x40006400)
#define CAN_MSR ((Register_32bit*)0x40006404)

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"
//#define CAN_MCR ((Register_32bit*)0x40006400)
int
main(int argc, char* argv[])
{ u8 mesg,check=0;
//exit sleep mode
	(CAN1->MCR)&=0x00010000;
	(CAN_MCR->ByteAccess)=0x00010000;
	//ENTER INIT MODE
	(CAN1->MCR)&=0x00010001;
(CAN_MCR->ByteAccess)=0x00010001;

//WAIT FOR ACK BIT OF ENTERING INIT MODE

//while(!check)
check=Get_Bit((CAN_MSR->ByteAccess),0);

//SETTING FILTERS FOR CAN2 STARTING FROM 8
(CAN1->FMR)|=(8<<8);
//FILTER ID MODE FOR CAN1 AND CAN2 FILTERS
(CAN1->FM1R)|=(0XFF<<0);
//FILTER SINGLE 32 BIT REGISTER
(CAN1->FS1R)|=(0XFF<<0);
//ACTIVE FILTERS
(CAN1->FA1R)|=(0XFF<<0);
//SETTING ID 1 FOR FIRST FILTER
CAN1->sFilterRegister[0].FR1=1;
CAN1->sFilterRegister[0].FR2=1;




//ENTERING LOOPBACK MODE
CAN1->BTR|=(1<<30);
//SETTING ID FOR THE FIRST MWSG IN FIRST MAILBOX
(CAN1->sTxMailBox[0].TIR)|=(1<<21);
//CLR THE RTR TO INDICTE STARNDARD IDE
(CAN1->sTxMailBox[0].TIR)|=(1<<2);
 //CLR RTR BIT TO INDICATE DATA FRAME 1001 ^ 0010
(CAN1->sTxMailBox[0].TIR)&=~(1<<1);
//CHHOSING NUMBER OF BYTES TO BE SENT IN DATA FRAME
(CAN1->sTxMailBox[0].TDTR)|=(1<<0);
//WRITE DATA TO BE SENT
(CAN1->sTxMailBox[0].TDLR)|=(3<<0);

/****************************************************************/
//CONFIGRUATION FOR RECEIVER
// ID FOR RECEICE=VING MESG
(CAN1->sFIFOMailBox[0].RIR)|=(1<<21);
//CHOSING STANDARD IDENTIFER
(CAN1->sFIFOMailBox[0].RIR)|=(0<<2);
//CHOOSING DATA FRAME
(CAN1->sFIFOMailBox[0].RIR)|=(0<<1);
//GETTING THE INDEX OF THE MATCHED FILTER
u8 filter_index=(((CAN1->sFIFOMailBox[0].RDTR)&(0XFF<<8))>>8);
//GETTING THE DATA
//GETTING THE INDEX OF THE MATCHED FILTER
u8 RECEIVED_MESG=(((CAN1->sFIFOMailBox[0].RDTR)&(0XFF<<0))>>0);
/***************************************************************/
//CLR INIT RQ BIT TO ENTER NORMAL MODE
(CAN1->MCR)|=(0<<0);
//WAIT FOR INIT ACK TO BE CLERAED
while((CAN1->MSR & (1<<0)));





//REQST TRANSMISSION OF FRAME
(CAN1->sTxMailBox[0].TIR)|=(1<<0);
//CHECK IF THERE ARE MESSAGES IN FIFO
mesg=CAN1->RF0R;
  while (1)
    {

    }
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
