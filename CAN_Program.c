/*
 * CAN_Program.c
 *
 *  Created on: Mar 31, 2019
 *      Author: aya
 */
#include "STD_TYPES.h"
#include "stm32f10x_can.h"
#define CAN_MCR ((Register_32bit*)0x40006400)
#define CAN_MSR ((Register_32bit*)0x40006404)
u8 check=0;
void CAN_INIT_MODE(void){
//SET THE INIT REQUEST BIT IN THE MCR REGISTER AND WAITS TILL THE ACK BIT SET

//To initialize the CAN Controller, software has to set up the Bit Timing (CAN_BTR) and CAN
//options (CAN_MCR) registers.

//To initialize the registers associated with the CAN filter banks (mode, scale, FIFO
//assignment, activation and filter values), software has to set the FINIT bit (CAN_FMR).
//The filter scale and mode configuration must be configured before entering Normal Mode.

//If software requests entry to initialization mode by setting the INRQ bit while bxCAN is in
//Sleep mode, it must also clear the SLEEP bit. CHK ON SLEEP ACK BIT
	//exit sleep mode
		(CAN1->MCR)&=0x00010000;
		(CAN_MCR->ByteAccess)=0x00010000;
		//ENTER INIT MODE
		(CAN1->MCR)&=0x00010001;
	(CAN_MCR->ByteAccess)=0x00010001;

	//WAIT FOR ACK BIT OF ENTERING INIT MODE

	//while(!check)
	check=Get_Bit((CAN_MSR->ByteAccess),0);
}

void CAN_NORMAL_MODE(void){
//to enter Normal mode is issued by clearing the INRQ bit in the CAN_MCR
//register.
//CLEAR SLEEP BIT AND INIT REQUEST BIT AND CHECK ON SLEEP &INIT ACK

/* Normal mode and is ready to take part in bus activities when it
has synchronized with the data transfer on the CAN bus. This is done by waiting for the
occurrence of a sequence of 11 consecutive recessive bits (Bus Idle state). The switch to
Normal mode is confirmed by the hardware by clearing the INAK bit in the CAN_MSR
register.*/
	//CLR INIT RQ BIT TO ENTER NORMAL MODE
	(CAN1->MCR)|=(0<<0);
	//WAIT FOR INIT ACK TO BE CLERAED
	while((CAN1->MSR & (1<<0)));
}
void CAN_LOOP_BACK_MODE(void){
//by setting the LBKM bit in the CAN_BTR
//register.
	//ENTERING LOOPBACK MODE
	CAN1->BTR|=(1<<30);
}
void CAN_DEBUG_MODE(void){
//the DBG_CAN1_STOP bit for CAN1 or the DBG_CAN2_STOP bit for CAN2 in the
//DBG module
}
void CAN_TRANSMIT(void){
/*one empty transmit mailbox, set
up the identifier, the data length code (DLC) and the data before requesting the transmission
by setting the corresponding TXRQ bit in the CAN_TIxR register*/
}
void GET_TRANSMIT_STATE(u8 mailBox_Num){
/* RQCP and TXOK bits in the CAN_TSR
register.
If the transmission fails, the cause is indicated by the ALST bit in the CAN_TSR register in
case of an Arbitration Lost, and/or the TERR bit, in case of transmission error detection*/
}
void Get_Mailbox_OVERRUN_State(){
//	the FOVR bit in the CAN_RFR register
}
void Get_MAILBOX_STATE(void){
/*Once a message has been stored in the FIFO, the FMP[1:0] bits are updated and an
interrupt request is generated if the FMPIE bit in the CAN_IER register is set.
When the FIFO becomes full (i.e. a third message is stored) the FULL bit in the CAN_RFR
register is set and an interrupt is generated if the FFIE bit in the CAN_IER register is set.
On overrun condition, the FOVR bit is set and an interrupt is generated if the FOVIE bit in
the CAN_IER register is set.*/
}
void ENABLE_IDENTIFER_MODE(u8 ID){

}
void Set_Scalable_Width(u8 Width){

}
void ENABLE_TIME_TRIGGERED(u8 Time){
//Time Stamp value stored in the CAN_RDTxR/CAN_TDTxR registers
}
void ENABLE_TRANSMIT_FIFO(void){
/*	by setting the TXFP bit in the
CAN_MCR register.*/
}
void RELEASE_MAILBOX(void){
//release the output mailbox by setting the RFOM bit,
}
void CAN_TRANSMISSION_ABORT(u8 mailBox_Num ){

}

void CAN_TEST_MODE(void){
//????
/*can be selected by the SILM and LBKM bits in the CAN_BTR register. These bits
must be configured while bxCAN is in Initialization mode. Once test mode has been
selected, the INRQ bit in the CAN_MCR register must be reset to enter Normal mode.
*/ }
void CAN_SILENT_MODE(void){
//????
/*can be selected by the SILM a bits in the CAN_BTR register.
*/ }

void CAN_SLEEP_MODE(u8 SLEEPING_MODE_TYPE){
//CLR INIT RQ AND CHK ON INIT ACK
//setting the SLEEP bit in the CAN_MCR register.

//If the AWUM bit is
//cleared, software has to clear the SLEEP bit when a wakeup interrupt occurs, in order to exit
//from Sleep mode.
}

void CAN_Filter_Modify(void){
//to be able to modify filter values software has to set the FINIT bit or
//by deactivating the associated filter activation bits (in the CAN_FA1R register).

/*CAN_FMR register*/
//FILTER SCALE FSCx bit in the CAN_FS1R register
/*The identifier list or identifier mask mode for the
	corresponding Mask/Identifier registers is configured by means of the FBMx bits in the
	CAN_FMR register.*/
}

