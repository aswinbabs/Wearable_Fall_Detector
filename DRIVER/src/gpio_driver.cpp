/******************************************************************************
 * @file    gpio_driver.cpp
 * @brief   GPIO driver implementation.
 *
 * Implements the GPIO abstraction layer for GuardianBand.
 *
 * Author : Aswin
 ******************************************************************************/

#include "gpio_driver.hpp"

/*==============================================================================
 * Constructor
 *============================================================================*/

GpioDriver::GpioDriver(const GpioConfig& config)
    :
    m_pin(config.pin),
    m_gpioConfig{},
    m_level(0U)
{
    m_gpioConfig.pin_bit_mask = (1ULL << config.pin);

    m_gpioConfig.mode = config.mode;

    m_gpioConfig.pull_up_en = config.pullUp;

    m_gpioConfig.pull_down_en = config.pullDown;

    m_gpioConfig.intr_type = config.interruptType;
}

/*==============================================================================
 * Public Functions
 *============================================================================*/

esp_err_t GpioDriver::init()
{
    return gpio_config(&m_gpioConfig);
}

esp_err_t GpioDriver::write(uint32_t level)
{
    m_level = level;

    return gpio_set_level(m_pin, level);
}

uint32_t GpioDriver::read() const
{
    return gpio_get_level(m_pin);
}

esp_err_t GpioDriver::toggle()
{
    return write(!m_level);
}