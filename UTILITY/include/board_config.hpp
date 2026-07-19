#pragma once

#ifndef BOARD_CONFIG_HPP
#define BOARD_CONFIG_HPP

/******************************************************************************
 * @file    board_config.hpp
 * @brief   GuardianBand board-specific hardware configuration.
 *
 * Defines GPIO assignments and electrical states for all peripherals
 * used by the GuardianBand wearable.
 *
 * Author : Aswin Babu K
 ******************************************************************************/


#include "driver/gpio.h"

namespace BoardConfig
{
    /*--------------------------------------------------------------------------
     * Board Information
     *------------------------------------------------------------------------*/

    constexpr char BOARD_NAME[] = "LOLIN D32";

    /*--------------------------------------------------------------------------
     * GPIO Pin Configuration
     *------------------------------------------------------------------------*/

    constexpr gpio_num_t LED    = GPIO_NUM_2;   // On-board Status LED
    constexpr gpio_num_t BUTTON = GPIO_NUM_25;  // User Push Button
    constexpr gpio_num_t BUZZER = GPIO_NUM_18;  // Piezo Buzzer

    /*--------------------------------------------------------------------------
     * GPIO Active States
     *------------------------------------------------------------------------*/

    constexpr uint32_t LED_ON  = 1U;
    constexpr uint32_t LED_OFF = 0U;

    constexpr uint32_t BUZZER_ON  = 1U;
    constexpr uint32_t BUZZER_OFF = 0U;

    constexpr uint32_t BUTTON_PRESSED  = 0U;    // Active Low (using internal pull-up)
    constexpr uint32_t BUTTON_RELEASED = 1U;

    /*--------------------------------------------------------------------------
     * I2C Configuration (MPU6050)
     *------------------------------------------------------------------------*/

    constexpr gpio_num_t I2C_SDA = GPIO_NUM_21;
    constexpr gpio_num_t I2C_SCL = GPIO_NUM_22;
}

#endif // BOARD_CONFIG_HPP