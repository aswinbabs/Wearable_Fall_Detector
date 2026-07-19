/******************************************************************************
 * @file        button.cpp
 * @brief       Push button module implementation.
 *
 * @details
 * Implements the GuardianBand push button module using the GPIO driver.
 *
 * Author : Aswin Babu K
 ******************************************************************************/

#include "button.hpp"
#include "board_config.hpp"

Button::Button()
    :
    m_gpio(
        {
            BoardConfig::BUTTON,
            GPIO_MODE_INPUT,
            GPIO_PULLUP_ENABLE,
            GPIO_PULLDOWN_DISABLE,
            GPIO_INTR_DISABLE
        })
{
}

esp_err_t Button::init()
{
    return m_gpio.init();
}

void Button::update()
{
    /* Reserved for future button state machine implementation */
}

bool Button::isPressed() const
{
    /* Button is active LOW */
    return (m_gpio.read() == 0U);
}