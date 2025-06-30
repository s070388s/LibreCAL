#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ENABLE_UART
// Log output disabled
#define LOG_CRIT(fmt, ...)
#define LOG_ERR(fmt, ...)
#define LOG_WARN(fmt, ...)
#define LOG_INFO(fmt, ...)
#define LOG_DEBUG(fmt, ...)
#else

#define LOG_UART_ID		uart1
#define LOG_UART_PIN	24

#define LOG_SENDBUF_LENGTH	1024

#define LOG_LEVEL_DEBUG	4
#define LOG_LEVEL_INFO	3
#define LOG_LEVEL_WARN	2
#define LOG_LEVEL_ERR	1
#define LOG_LEVEL_CRIT	0

#define LOG_LEVEL_DEFAULT	LOG_LEVEL_ERR

#ifndef LOG_LEVEL
#define LOG_LEVEL	LOG_LEVEL_DEFAULT
#endif

#ifndef LOG_MODULE
#define LOG_MODULE	"Log"
#endif

#if LOG_LEVEL >= LOG_LEVEL_CRIT
#define LOG_CRIT(fmt, ...)		_log_write(LOG_MODULE, "CRT", fmt, ## __VA_ARGS__)
#else
#define LOG_CRIT(fmt, ...)
#endif
#if LOG_LEVEL >= LOG_LEVEL_ERR
#define LOG_ERR(fmt, ...)		_log_write(LOG_MODULE, "ERR", fmt, ## __VA_ARGS__)
#else
#define LOG_ERR(fmt, ...)
#endif
#if LOG_LEVEL >= LOG_LEVEL_WARN
#define LOG_WARN(fmt, ...)		_log_write(LOG_MODULE, "WRN", fmt, ## __VA_ARGS__)
#else
#define LOG_WARN(fmt, ...)
#endif
#if LOG_LEVEL >= LOG_LEVEL_INFO
#define LOG_INFO(fmt, ...)		_log_write(LOG_MODULE, "INF", fmt, ## __VA_ARGS__)
#else
#define LOG_INFO(fmt, ...)
#endif
#if LOG_LEVEL >= LOG_LEVEL_DEBUG
#define LOG_DEBUG(fmt, ...)		_log_write(LOG_MODULE, "DBG", fmt, ## __VA_ARGS__)
#else
#define LOG_DEBUG(fmt, ...)
#endif

#include <stdint.h>

void Log_Init();
typedef void (*log_redirect_t)(const char *line, uint16_t length);
void _log_write(const char *module, const char *level, const char *fmt, ...);

#endif

#ifdef __cplusplus
}
#endif
