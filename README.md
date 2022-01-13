# RainSensor
Diploma thesis rain sensor library


# Usage
Connect the rain sensor to an GPIO pin of your microcontroller.

Do not forget to add the minimal-printf-enable-floating-point flag
by adding this:
  
      "target_overrides": {
        "*": {
            "target.printf_lib": "minimal-printf-enable-floating-point"
        }
    }
    
to  mbed_app.json
