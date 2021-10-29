/*
******************************************************************************
**

**  File        : LinkerScript.ld
**
**
**  Abstract    : Linker script for STM32H7 series
**                1024Kbytes FLASH and 192Kbytes RAM
**
**                Set heap size, stack size and stack location according
**                to application requirements.
**
**                Set memory bank area and size if external memory is used.
**
**  Target      : STMicroelectronics STM32
**
**  Distribution: The file is distributed as is, without any warranty
**                of any kind.
**
*****************************************************************************
** @attention
**
** Copyright (c) 2019 STMicroelectronics.
** All rights reserved.
**
** This software component is licensed by ST under BSD 3-Clause license,
** the "License"; You may not use this file except in compliance with the
** License. You may obtain a copy of the License at:
**                        opensource.org/licenses/BSD-3-Clause
**
****************************************************************************
*/

/* Entry Point */
ENTRY(Reset_Handler)

/* Highest address of the user mode stack */
_estack = 0x20020000;    /* end of RAM */
/* Generate a link error if heap and stack don't fit into RAM */
_Min_Heap_Size = 0x2000 ;      /* required amount of heap  */
_Min_Stack_Size = 0x4000 ; /* required amount of stack */

/* Specify the memory areas */
MEMORY
{
FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 1024K
FLASH1 (rx)      : ORIGIN = 0x08100000, LENGTH = 1024K
QSPI (rx)      : ORIGIN = 0x90000000, LENGTH = 128M
RAM (xrw)      : ORIGIN = 0x20000000, LENGTH = 128K

ITCMRAM (xrw)      : ORIGIN = 0x00000000, LENGTH = 64K
AXIRAM (rw)      : ORIGIN = 0x24000000, LENGTH = 512K

AHBRAM (rw)      : ORIGIN = 0x30040000, LENGTH = 32K

SDRAM (rw)      : ORIGIN = 0xD0000000, LENGTH = 64M

}

/* Define output sections */
SECTIONS
{
  /* The startup code goes first into FLASH */
  .isr_vector :
  {
    . = ALIGN(4);
    KEEP(*(.isr_vector)) /* Startup code */
    . = ALIGN(4);
  } >FLASH
  
  
  
  .SdramRTOSHeap (NOLOAD) : { *(.SdramRTOSHeap) } >SDRAM
  .SdramLCDHeap (NOLOAD) : { *(.SdramLCDHeap) } >SDRAM
  
  
/* The IOQUAKE3 program code and data goes into QSPI */

  .qtext :
  {
    . = ALIGN(4);   
    ioquake3/*.o (.text)     
    ioquake3/*.o (.text*)  
    _eqtext = .;       
    . = ALIGN(4);
  } >QSPI

  
  /* Constant data goes into FLASH */
  .qrodata :
  {
    . = ALIGN(4);
    ioquake3/*.o (.rodata)     
    ioquake3/*.o (.rodata*)  
    . = ALIGN(4);
  } >QSPI
  
  /* used by the startup to initialize data */
  _siqdata = LOADADDR(.qdata);

  /* Initialized data sections goes into RAM, load LMA copy after code */
  .qdata : 
  {
    . = ALIGN(4);
    _sqdata = .;        /* create a global symbol at data qstart */
    ioquake3/*.o (.data)       
    ioquake3/*.o (.data*)         

    . = ALIGN(4);
    _eqdata = .;        /* define a global symbol at data qend */
  } >SDRAM AT> QSPI

  
  /* Uninitialized data section */
  . = ALIGN(4);
  .qbss :
  {
    /* This is used by the startup in order to initialize the .bss secion */
    _sqbss = .;         /* define a global symbol at bss start */
    __qbss_start__ = _sqbss;
    ioquake3/*.o (.bss)
    ioquake3/*.o (.bss*)
    ioquake3/*.o (COMMON)

    . = ALIGN(4);
    _eqbss = .;         /* define a global symbol at bss end */
    __qbss_end__ = _eqbss;
  } >SDRAM








  /* The program code and other data goes into FLASH */
  .text :
  {
    . = ALIGN(4);
    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
    *(.glue_7)         /* glue arm to thumb code */
    *(.glue_7t)        /* glue thumb to arm code */
    *(.eh_frame)

    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(4);
    _etext = .;        /* define a global symbols at end of code */
  } >FLASH

  /* Constant data goes into FLASH */
  .rodata :
  {
    . = ALIGN(4);
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    . = ALIGN(4);
  } >FLASH

  .ARM.extab   : { *(.ARM.extab* .gnu.linkonce.armextab.*) } >FLASH
  .ARM : {
    __exidx_start = .;
    *(.ARM.exidx*)
    __exidx_end = .;
  } >FLASH

  .preinit_array     :
  {
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array*))
    PROVIDE_HIDDEN (__preinit_array_end = .);
  } >FLASH
  .init_array :
  {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array*))
    PROVIDE_HIDDEN (__init_array_end = .);
  } >FLASH
  .fini_array :
  {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array*))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } >FLASH

  /* used by the startup to initialize data */
  _sidata = LOADADDR(.data);

  /* Initialized data sections goes into RAM, load LMA copy after code */
  .data : 
  {
    . = ALIGN(4);
    _sdata = .;        /* create a global symbol at data start */
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */

    . = ALIGN(4);
    _edata = .;        /* define a global symbol at data end */
  } >RAM AT> FLASH

  
  /* Uninitialized data section */
  . = ALIGN(4);
  .bss :
  {
    /* This is used by the startup in order to initialize the .bss secion */
    _sbss = .;         /* define a global symbol at bss start */
    __bss_start__ = _sbss;
    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);
    _ebss = .;         /* define a global symbol at bss end */
    __bss_end__ = _ebss;
  } >RAM
  

  /* User_heap_stack section, used to check that there is enough RAM left */
  ._user_heap_stack :
  {
    . = ALIGN(8);
    PROVIDE ( end = . );
    PROVIDE ( _end = . );
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(8);
  } >RAM
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  . = ALIGN(4);
  .itcmram :
  {
    . = ALIGN(4);
    *(.itcmram*)
    . = ALIGN(4);
  } >ITCMRAM
  
  
  . = ALIGN(4);
  .axiram :
  {
    . = ALIGN(4);
    *(.axiram*)
    . = ALIGN(4);
  } >AXIRAM
  
  
  
  . = ALIGN(4);
  .ahbram :
  {
    _sahbram = .;         /* define a global symbol at bss start */
    __ahbram_start__ = _sahbram;
    KEEP(*(.ahbram*))
    . = ALIGN(4);
    _eahbram = .;         /* define a global symbol at bss end */
    __ahbram_end__ = _eahbram;
  } >AHBRAM
  

  

  /* Remove information from the standard libraries */
  /DISCARD/ :
  {
    libc.a ( * )
    libm.a ( * )
    libgcc.a ( * )
  }

  .ARM.attributes 0 : { *(.ARM.attributes) }
  
  .ItcmRamSection (NOLOAD) : { *(.ItcmRamSection) } >ITCMRAM
  .AxiRamSection (NOLOAD) : { *(.AxiRamSection) } >AXIRAM
  .AhbRamSection (NOLOAD) : { *(.AhbRamSection) } >AHBRAM
}


