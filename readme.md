**- OVERVIEW -**<br />
This repository at https://github.com/tedhavelka/nRF9160-work a starting point for some mostly general explorations in coding for the ARM Cortex-M33 processor in Nordicsemi's nRF9160 System in Package (SiP).

**- SUPPORTING MATERIAL -**<br />
Work here beginning with programming and experimentation with Sparkfun's "nRF9160 Thing Plus" board. This development kit detailed at:
*  https://learn.sparkfun.com/tutorials/nrf9160-thing-plus-hookup-guide#introduction

And some instructions with get a developer pretty far toward compiling and running demo firmwares for this board:
*  https://learn.sparkfun.com/tutorials/nrf9160-thing-plus-hookup-guide#example---blinky

What seems missing from above toolchain and SDK install instructions, are specific steps to obtain a recent 'ncs' software development kit.  Here 'ncs' stands for Nordic Connect SDK.  The following Nordic web page, however, talks about a specific release of 'ncs':
*  https://developer.nordicsemi.com/nRF_Connect_SDK/doc/1.4.1/nrf/gs_installing.html

At a typical Unix or Linux shell prompt the following -- assuming tools installed -- will clone ncs version 1.4.1 to local work station, along with some other repositories:

$ west init -m https://github.com/nrfconnect/sdk-nrf --mr v1.4.1

An additional step (or steps) are needed to amend this SDK with example Zephyr RTOS oriented code demos from CircuitDojo.  With these amendments, one then has firmware example code with board support for Sparkfun's Thing Plus development board.

**- GOALS -**<br />
Primary goals include:
1.  find and leverage or develop code to realize I2C, SPI and serial protocols in the nRF9160
2.  communicate with and log data from Sparkfun nRF9160 Thing Plus development board
3.  craft a GNU make or cmake based project to manage builds of building block, experimental firmwares

**- REFERENCES -**
Hardware datasheets
<ul><!-- wrong use of HTML 'ul' tag pair, must find markdown indenting syntax - TMH -->
*  https://www.st.com/resource/en/datasheet/lis2dh12.pdf
</ul>

