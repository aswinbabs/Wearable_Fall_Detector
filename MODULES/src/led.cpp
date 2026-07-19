/******************************************************************************
 * @file    led.cpp
 * @brief   Status LED module implementation.
 *
 * Author : Aswin Babu K
 ******************************************************************************/

#include "led.hpp"
#include "board_config.hpp"

Led::Led()
    :
    m_gpio(
        {
            BoardConfig::LED,
            GPIO_MODE_OUTPUT,
            GPIO_PULLUP_DISABLE,
            GPIO_PULLDOWN_DISABLE,
            GPIO_INTR_DISABLE
        })
{
}

esp_err_t Led::init()
{
    return m_gpio.init();
}

esp_err_t Led::on()
{
    return m_gpio.write(BoardConfig::LED_ON);
}

esp_err_t Led::off()
{
    return m_gpio.write(BoardConfig::LED_OFF);
}

esp_err_t Led::toggle()
{
    return m_gpio.toggle();
}