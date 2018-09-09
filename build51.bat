set Path=C:\apps\arm-gcc\bin;%PATH%
rem make PLATFORM=nRF51822 NRF51_SDK_PATH=../nrf51_sdk_v4_4_2_33551 %1
make PLATFORM=nRF51822 NRF51_SDK_PATH=../nRF5_SDK_12.3.0_d7731ad %1
