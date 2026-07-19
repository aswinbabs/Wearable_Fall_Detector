idf_component_register(

    SRCS
        "src/gpio_driver.cpp"

    INCLUDE_DIRS
        "include"

    REQUIRES
        esp_driver_gpio
)