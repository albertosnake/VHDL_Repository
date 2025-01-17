/*****************************************************************************
* Filename:          C:\Xilinx\PRACTICAS_FPGA\P3_INTENTO2\ficheros_p1\pr_1/drivers/simon_periferico_v1_00_a/src/simon_periferico.h
* Version:           1.00.a
* Description:       simon_periferico Driver Header File
* Date:              Wed Dec 27 09:35:57 2017 (by Create and Import Peripheral Wizard)
*****************************************************************************/

#ifndef SIMON_PERIFERICO_H
#define SIMON_PERIFERICO_H

/***************************** Include Files *******************************/

#include "xbasic_types.h"
#include "xstatus.h"
#include "xio.h"

/************************** Constant Definitions ***************************/


/**
 * User Logic Slave Space Offsets
 * -- SLV_REG0 : user logic slave module register 0
 * -- SLV_REG1 : user logic slave module register 1
 * -- SLV_REG2 : user logic slave module register 2
 * -- SLV_REG3 : user logic slave module register 3
 * -- SLV_REG4 : user logic slave module register 4
 * -- SLV_REG5 : user logic slave module register 5
 */
#define SIMON_PERIFERICO_USER_SLV_SPACE_OFFSET (0x00000000)
#define SIMON_PERIFERICO_SLV_REG0_OFFSET (SIMON_PERIFERICO_USER_SLV_SPACE_OFFSET + 0x00000000)
#define SIMON_PERIFERICO_SLV_REG1_OFFSET (SIMON_PERIFERICO_USER_SLV_SPACE_OFFSET + 0x00000004)
#define SIMON_PERIFERICO_SLV_REG2_OFFSET (SIMON_PERIFERICO_USER_SLV_SPACE_OFFSET + 0x00000008)
#define SIMON_PERIFERICO_SLV_REG3_OFFSET (SIMON_PERIFERICO_USER_SLV_SPACE_OFFSET + 0x0000000C)
#define SIMON_PERIFERICO_SLV_REG4_OFFSET (SIMON_PERIFERICO_USER_SLV_SPACE_OFFSET + 0x00000010)
#define SIMON_PERIFERICO_SLV_REG5_OFFSET (SIMON_PERIFERICO_USER_SLV_SPACE_OFFSET + 0x00000014)

/**************************** Type Definitions *****************************/


/***************** Macros (Inline Functions) Definitions *******************/

/**
 *
 * Write a value to a SIMON_PERIFERICO register. A 32 bit write is performed.
 * If the component is implemented in a smaller width, only the least
 * significant data is written.
 *
 * @param   BaseAddress is the base address of the SIMON_PERIFERICO device.
 * @param   RegOffset is the register offset from the base to write to.
 * @param   Data is the data written to the register.
 *
 * @return  None.
 *
 * @note
 * C-style signature:
 * 	void SIMON_PERIFERICO_mWriteReg(Xuint32 BaseAddress, unsigned RegOffset, Xuint32 Data)
 *
 */
#define SIMON_PERIFERICO_mWriteReg(BaseAddress, RegOffset, Data) \
 	XIo_Out32((BaseAddress) + (RegOffset), (Xuint32)(Data))

/**
 *
 * Read a value from a SIMON_PERIFERICO register. A 32 bit read is performed.
 * If the component is implemented in a smaller width, only the least
 * significant data is read from the register. The most significant data
 * will be read as 0.
 *
 * @param   BaseAddress is the base address of the SIMON_PERIFERICO device.
 * @param   RegOffset is the register offset from the base to write to.
 *
 * @return  Data is the data from the register.
 *
 * @note
 * C-style signature:
 * 	Xuint32 SIMON_PERIFERICO_mReadReg(Xuint32 BaseAddress, unsigned RegOffset)
 *
 */
#define SIMON_PERIFERICO_mReadReg(BaseAddress, RegOffset) \
 	XIo_In32((BaseAddress) + (RegOffset))


/**
 *
 * Write/Read 32 bit value to/from SIMON_PERIFERICO user logic slave registers.
 *
 * @param   BaseAddress is the base address of the SIMON_PERIFERICO device.
 * @param   RegOffset is the offset from the slave register to write to or read from.
 * @param   Value is the data written to the register.
 *
 * @return  Data is the data from the user logic slave register.
 *
 * @note
 * C-style signature:
 * 	void SIMON_PERIFERICO_mWriteSlaveRegn(Xuint32 BaseAddress, unsigned RegOffset, Xuint32 Value)
 * 	Xuint32 SIMON_PERIFERICO_mReadSlaveRegn(Xuint32 BaseAddress, unsigned RegOffset)
 *
 */
#define SIMON_PERIFERICO_mWriteSlaveReg0(BaseAddress, RegOffset, Value) \
 	XIo_Out32((BaseAddress) + (SIMON_PERIFERICO_SLV_REG0_OFFSET) + (RegOffset), (Xuint32)(Value))
#define SIMON_PERIFERICO_mWriteSlaveReg1(BaseAddress, RegOffset, Value) \
 	XIo_Out32((BaseAddress) + (SIMON_PERIFERICO_SLV_REG1_OFFSET) + (RegOffset), (Xuint32)(Value))
#define SIMON_PERIFERICO_mWriteSlaveReg2(BaseAddress, RegOffset, Value) \
 	XIo_Out32((BaseAddress) + (SIMON_PERIFERICO_SLV_REG2_OFFSET) + (RegOffset), (Xuint32)(Value))
#define SIMON_PERIFERICO_mWriteSlaveReg3(BaseAddress, RegOffset, Value) \
 	XIo_Out32((BaseAddress) + (SIMON_PERIFERICO_SLV_REG3_OFFSET) + (RegOffset), (Xuint32)(Value))
#define SIMON_PERIFERICO_mWriteSlaveReg4(BaseAddress, RegOffset, Value) \
 	XIo_Out32((BaseAddress) + (SIMON_PERIFERICO_SLV_REG4_OFFSET) + (RegOffset), (Xuint32)(Value))
#define SIMON_PERIFERICO_mWriteSlaveReg5(BaseAddress, RegOffset, Value) \
 	XIo_Out32((BaseAddress) + (SIMON_PERIFERICO_SLV_REG5_OFFSET) + (RegOffset), (Xuint32)(Value))

#define SIMON_PERIFERICO_mReadSlaveReg0(BaseAddress, RegOffset) \
 	XIo_In32((BaseAddress) + (SIMON_PERIFERICO_SLV_REG0_OFFSET) + (RegOffset))
#define SIMON_PERIFERICO_mReadSlaveReg1(BaseAddress, RegOffset) \
 	XIo_In32((BaseAddress) + (SIMON_PERIFERICO_SLV_REG1_OFFSET) + (RegOffset))
#define SIMON_PERIFERICO_mReadSlaveReg2(BaseAddress, RegOffset) \
 	XIo_In32((BaseAddress) + (SIMON_PERIFERICO_SLV_REG2_OFFSET) + (RegOffset))
#define SIMON_PERIFERICO_mReadSlaveReg3(BaseAddress, RegOffset) \
 	XIo_In32((BaseAddress) + (SIMON_PERIFERICO_SLV_REG3_OFFSET) + (RegOffset))
#define SIMON_PERIFERICO_mReadSlaveReg4(BaseAddress, RegOffset) \
 	XIo_In32((BaseAddress) + (SIMON_PERIFERICO_SLV_REG4_OFFSET) + (RegOffset))
#define SIMON_PERIFERICO_mReadSlaveReg5(BaseAddress, RegOffset) \
 	XIo_In32((BaseAddress) + (SIMON_PERIFERICO_SLV_REG5_OFFSET) + (RegOffset))

/************************** Function Prototypes ****************************/


/**
 *
 * Run a self-test on the driver/device. Note this may be a destructive test if
 * resets of the device are performed.
 *
 * If the hardware system is not built correctly, this function may never
 * return to the caller.
 *
 * @param   baseaddr_p is the base address of the SIMON_PERIFERICO instance to be worked on.
 *
 * @return
 *
 *    - XST_SUCCESS   if all self-test code passed
 *    - XST_FAILURE   if any self-test code failed
 *
 * @note    Caching must be turned off for this function to work.
 * @note    Self test may fail if data memory and device are not on the same bus.
 *
 */
XStatus SIMON_PERIFERICO_SelfTest(void * baseaddr_p);

#endif /** SIMON_PERIFERICO_H */
