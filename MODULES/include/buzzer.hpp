/******************************************************************************
 * @file        buzzer.hpp
 * @brief       Active buzzer module for GuardianBand.
 *
 * @details
 * Provides a simple interface for controlling the active buzzer using the
 * GPIO driver. The module supports basic ON/OFF control, output toggling,
 * and a timed beep function for notifications.
 *
 * Application-specific alarm patterns are intentionally excluded and should
 * be implemented in the application layer.
 *
 * Author : Aswin Babu K
 ******************************************************************************/

#ifndef BUZZER_HPP
#define BUZZER_HPP

#include "gpio_driver.hpp"
#include "esp_err.h"

class Buzzer
{
public:

    Buzzer();

    ~Buzzer() = default;

    Buzzer(const Buzzer&) = delete;
    Buzzer& operator=(const Buzzer&) = delete;

    /**
     * @brief Initialize buzzer GPIO.
     *
     * @return ESP_OK on success.
     */
    esp_err_t init();

    /**
     * @brief Turn buzzer ON.
     *
     * @return ESP_OK on success.
     */
    esp_err_t on();

    /**
     * @brief Turn buzzer OFF.
     *
     * @return ESP_OK on success.
     */
    esp_err_t off();

    /**
     * @brief Toggle buzzer state.
     *
     * @return ESP_OK on success.
     */
    esp_err_t toggle();

    /**
     * @brief Generate a single beep.
     *
     * @param durationMs Beep duration in milliseconds.
     *
     * @return ESP_OK on success.
     */
    esp_err_t beep(uint32_t durationMs);

private:

    GpioDriver m_gpio;
};

#endif // BUZZER_HPP