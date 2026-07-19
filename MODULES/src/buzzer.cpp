/******************************************************************************
 * @file        buzzer.cpp
 * @brief       Active buzzer module implementation.
 *
 * @details
 * Implements the active buzzer interface using the GPIO driver.
 *
 * Author : Aswin Babu K
 ******************************************************************************/

#include "buzzer.hpp"

#include "board_config.hpp"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

Buzzer::Buzzer()
    :
    m_gpio(
        {
            BoardConfig::BUZZER,
            GPIO_MODE_OUTPUT,
            GPIO_PULLUP_DISABLE,
            GPIO_PULLDOWN_DISABLE,
            GPIO_INTR_DISABLE
        })
{
}

esp_err_t Buzzer::init()
{
    return m_gpio.init();
}

esp_err_t Buzzer::on()
{
    return m_gpio.write(1U);
}

esp_err_t Buzzer::off()
{
    return m_gpio.write(0U);
}

esp_err_t Buzzer::toggle()
{
    return m_gpio.toggle();
}

esp_err_t Buzzer::beep(uint32_t durationMs)
{
    esp_err_t ret = on();

    if (ret != ESP_OK)
    {
        return ret;
    }

    vTaskDelay(pdMS_TO_TICKS(durationMs));

    return off();
}