/*
 * agentic_kit_config.h -- per-product knob overrides for the esp-agentic-kit
 * component. Picked up by common/log.h's override search (this directory is on
 * the component's include path), BEFORE any SDK-side #ifndef default -- plain
 * #defines only, no #ifndef here.
 *
 * One override this project needs: the SDK's log facade defaults to stderr,
 * which goes nowhere on ESP-IDF. AGENTIC_KIT_LOG remaps every SDK log line
 * (iot, tai, ble, mqtt, http, ...) straight into ESP-IDF logging,
 * macro-to-macro: no va_list round trip, and each line keeps its real module
 * tag. The AGENTIC_KIT_LOG_LEVEL ceiling still applies upstream, so lines
 * above the ceiling never reach this macro at all.
 */
#ifndef AGENTIC_KIT_CONFIG_H
#define AGENTIC_KIT_CONFIG_H

#include "esp_log.h"

/* level arrives as LOG_ERROR..LOG_DEBUG (1..4); map onto esp_log_level_t.
 * ESP_LOG_LEVEL_LOCAL keeps its own runtime check against the local
 * verbosity, same as a direct ESP_LOGx call. */
#define AGENTIC_KIT_LOG(level, tag, fmt, ...)                                   \
    ESP_LOG_LEVEL_LOCAL((level) == LOG_ERROR ? ESP_LOG_ERROR :                  \
                        (level) == LOG_WARN ? ESP_LOG_WARN :                    \
                        (level) == LOG_INFO ? ESP_LOG_INFO :                    \
                                              ESP_LOG_DEBUG,                    \
                        tag, fmt, ##__VA_ARGS__)

#endif /* AGENTIC_KIT_CONFIG_H */
