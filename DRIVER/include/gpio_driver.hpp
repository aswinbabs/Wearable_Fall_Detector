/******************************************************************************
 * @file    gpio_driver.hpp
 * @brief   GPIO driver abstraction for GuardianBand.
 *
 * This driver provides a lightweight C++ wrapper around the ESP-IDF GPIO
 * driver. It abstracts GPIO initialization and basic digital I/O operations,
 * allowing higher-level modules to interact with GPIO pins without directly
 * depending on ESP-IDF APIs.
 *
 * Features:
 *  - GPIO initialization
 *  - Digital output control
 *  - Digital input reading
 *  - Output toggle
 *  - Configurable pull-up/pull-down resistors
 *  - Interrupt configuration (reserved for future use)
 *
 * Author : Aswin Babu K
 ******************************************************************************/

#pragma once

#include "driver/gpio.h"
#include "esp_err.h"

/*==============================================================================
 * GPIO Configuration Structure
 *============================================================================*/

struct GpioConfig
{
    gpio_num_t         pin;
    gpio_mode_t        mode;
    gpio_pullup_t      pullUp;
    gpio_pulldown_t    pullDown;
    gpio_int_type_t    interruptType;
};

/*==============================================================================
 * GPIO Driver Class
 *============================================================================*/

class GpioDriver
{
public:

    explicit GpioDriver(const GpioConfig& config);

    ~GpioDriver() = default;

    GpioDriver(const GpioDriver&) = delete;
    GpioDriver& operator=(const GpioDriver&) = delete;

    /**
     * @brief Configure the GPIO peripheral.
     *
     * @return ESP_OK on success.
     */
    esp_err_t init();

    /**
     * @brief Set GPIO output level.
     *
     * @param level Logic level (0 or 1)
     *
     * @return ESP_OK on success.
     */
    esp_err_t write(uint32_t level);

    /**
     * @brief Read GPIO level.
     *
     * @return Current logic level.
     */
    uint32_t read() const;

    /**
     * @brief Toggle GPIO output.
     *
     * @return ESP_OK on success.
     */
    esp_err_t toggle();

private:

    gpio_num_t      m_pin;

    gpio_config_t   m_gpioConfig;

    uint32_t        m_level;
};