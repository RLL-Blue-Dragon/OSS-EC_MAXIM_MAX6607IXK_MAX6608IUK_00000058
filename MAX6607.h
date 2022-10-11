// License       : License.txt
// Specifications: Spec-MAX6607IXK_MAX6608IUK.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MAX6607.h
// Reason for change: 01.00.00 : 10/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __MAX6607_H__
#define __MAX6607_H__

#include "user_define.h"

// Components number
#define iMAX6607                112U                    // Maxim Integrated MAX6607IXK,MAX6608IUK

// MAX6607IXK,MAX6608IUK System Parts definitions
#define iMAX6607_xoff           0.5F                    // X offset [V]
#define iMAX6607_yoff           0.0F                    // Y offset [degree celsius]
#define iMAX6607_gain           0.01F                   // Gain [V/degree celsius]
#define iMAX6607_max            85.0F                   // Temperature Max [degree celsius]
#define iMAX6607_min            -20.0F                  // Temperature Min [degree celsius]

extern const tbl_adc_t tbl_MAX6607;

#endif /*__MAX6607_H__*/
