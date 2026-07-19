/******************************************************************************
 * @file    led.hpp
 * @brief   Status LED module for GuardianBand.
 *
 * Provides a simple interface for controlling the onboard status LED.
 * Internally uses the GPIO driver and board configuration.
 *
 * Author : Aswin Babu K
 ******************************************************************************/

#pragma once

#include "gpio_driver.hpp"

class Led
{
public:

    Led();

    esp_err_t init();

    esp_err_t on();

    esp_err_t off();

    esp_err_t toggle();

private:

    GpioDriver m_gpio;
};