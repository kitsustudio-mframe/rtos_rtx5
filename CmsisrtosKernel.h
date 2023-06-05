/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef CMSISRTOS_C1A0226D_E4B5_422B_A56F_BD06A64E5A65
#define CMSISRTOS_C1A0226D_E4B5_422B_A56F_BD06A64E5A65

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./CmsisrtosConfig.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace cmsisrtos{
  class CmsisrtosKernel;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class cmsisrtos::CmsisrtosKernel :public lang::Object, 
public lang::Kernel{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private:
    
    cmsisrtos::CmsisrtosConfig& mConfig;
    int mLockStack;
  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  public: 
    /**
     *
     */
    CmsisrtosKernel(cmsisrtos::CmsisrtosConfig& config);
    
    /**
     *
     */
    virtual ~CmsisrtosKernel(void) override;
  
  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */
  public:
    /**
     * @brief 核心初始化，再調用所有核心方法時必須先初始化，否則將會調用失敗
     * 
     * @return true 初始化成功
     * @return false 初始化失敗，可能核心已經被初始化
     */
    virtual bool kernelInitialize(void) override;

    /**
     * @brief 核心啟動，作業系統開始
     * 
     * @param runnable 主執行緒事件
     * @param stackSize 主執行緒記憶體堆疊大小
     */
    virtual void kernelStart(lang::Runnable& runnable, uint32_t stackSize) override;

    /**
     * @brief 核心鎖定，在調用kernelUnlock以前將不會進行context switch
     * 
     * @return int lock調用層數
     */
    virtual int kernelLock(void) override;

    /**
     * @brief 
     * 
     * @return int lock調用剩餘層數，當值為0時核心解鎖
     */
    virtual int kernelUnlock(void) override;

    /**
     * @brief 取得核心tick數
     * 
     * @return uint32_t tick數
     */
    virtual uint32_t kernelGetTickCount(void) override;

    /**
     * @brief 取得核心運作頻率
     * 
     * @return uint32_t Hz頻率
     */
    virtual uint32_t kernelGetTickFreq(void) override;
    
    /**
     * @brief 執行緒延遲，並交還CPU使用權
     * 
     * @param milliseconds 延遲時間，毫秒 
     * @return true 延遲執行成功
     * @return false 延遲執行失敗，可能要求時間過長
     */
    virtual bool kernelDelay(uint32_t milliseconds) const override;
    
    /**
     * @brief 執行緒等待，直到超時或是被喚醒，並交還CPU使用權
     * 
     * @param timeout 等待超時，0為永不超時直到notify
     * @return true 執行緒進入等待
     * @return false 執行緒進入等待失敗，可能在中斷或是核心啟動失敗
     */
    virtual bool kernelWait(uint32_t timeout) const override;
    
    /**
     * @brief 核心重啟
     *
     */
    virtual void kernelReboot(void) override;
    
    /**
     * @brief 建立一個執行緒，指定堆疊記憶體來源
     *
     * @param task 工作事件
     * @return null 建立失敗
     * @return Thread 建立成功
     */
    virtual lang::Thread* kernelAllocThread(lang::Runnable& task, lang::Data& stackMemory) override;
    
    /**
     * @brief 建立一個執行緒，限定堆疊大小
     *
     * @param task 工作事件
     * @param uint32_t 堆疊大小
     * @return null 建立失敗
     * @return Thread 建立成功
     */
    virtual lang::Thread* kernelAllocThread(lang::Runnable& task, uint32_t stackSize) override;
      
    /**
     * @brief 取得當前執行緒
     *
     * @return null 可能為核心尚未啟動、當前正在中斷事件
     * @return Thread 獲取成功
     */
    virtual lang::Thread* kernelGetCurrentThread(void) override;
    
    /**
     * @brief 
     *
     * @return
     */
    virtual lang::OutputStream* kernelGetOutputStream(void) override;
    
    /**
     * @brief 
     *
     * @return
     */
    virtual lang::InputStream* kernelGetInputStream(void) override;
    
    /**
     * @brief 取得核心運作頻率
     *
     * @return 
     */
    virtual uint32_t kernelGetCoreClock(void) override;
    
    /**
     * @brief 該函數將控制權傳遞給處於 READY 狀態且具有相同優先級的下一個線程。
     *        如果在READY狀態下沒有其他優先級相同的線程，則當前線程繼續執行，不會發生線程切換。
     *        不會將線程設置為 BLOCKED 狀態。 
     *        因此，即使處於READY狀態的線程可用，也不會調度優先級較低的線程。
     *       
     * @return true 控制權已成功傳遞給下一個線程。
     * @return false 發生了未指定的錯誤。該函數不能從中斷服務程序中調用。
     */
    virtual bool kenrelYield(void) override;
  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */

};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* CMSISRTOS_C1A0226D_E4B5_422B_A56F_BD06A64E5A65 */
