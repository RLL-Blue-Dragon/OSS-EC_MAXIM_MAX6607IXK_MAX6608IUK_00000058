// License       : License.txt
// Specifications: Spec-MAX6607IXK_MAX6608IUK.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MAX6607.cpp
// Reason for change: 01.00.00 : 10/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "MAX6607.h"

#if     iMAX6607_ma == iSMA                             // Simple moving average filter
static float32 MAX6607_sma_buf[iMAX6607_SMA_num];
static sma_f32_t MAX6607_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iMAX6607_SMA_num ,                              // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &MAX6607_sma_buf[0]                             // buffer
};

#elif   iMAX6607_ma == iEMA                             // Exponential moving average filter
static ema_f32_t MAX6607_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iMAX6607_EMA_K                                  // Exponential smoothing factor
};

#elif   iMAX6607_ma == iWMA                             // Weighted moving average filter
static float32 MAX6607_wma_buf[iMAX6607_WMA_num];
static wma_f32_t MAX6607_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iMAX6607_WMA_num ,                              // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iMAX6607_WMA_num * (iMAX6607_WMA_num + 1)/2 ,   // kn sum
        &MAX6607_wma_buf[0]                             // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_MAX6607 =
{
        iMAX6607                ,
        iMAX6607_pin            ,
        iMAX6607_xoff           ,
        iMAX6607_yoff           ,
        iMAX6607_gain           ,
        iMAX6607_max            ,
        iMAX6607_min            ,
        iMAX6607_ma             ,
        
#if     iMAX6607_ma == iSMA                             // Simple moving average filter
        &MAX6607_Phy_SMA        ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iMAX6607_ma == iEMA                             // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &MAX6607_Phy_EMA        ,
        (wma_f32_t*)iDummy_adr
#elif   iMAX6607_ma == iWMA                             // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &MAX6607_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
