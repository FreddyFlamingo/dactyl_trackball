// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Enables This makes it easier for fast typists to use dual-function keys */
#define PERMISSIVE_HOLD

/* layer config */
#define TAPPING_TOGGLE 2

#define MASTER_RIGHT
#define MATRIX_ROWS 12
#define MATRIX_COLS 6
#define SPLIT_MATRIX_ENABLE

/* Communication method used */ 
#define SERIAL_USART_FULL_DUPLEX 
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

/* SPI settings for PWM3389 FOR FUTURE */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MOSI_PIN GP19
#define SPI_MISO_PIN GP16
#define PMW33XX_CS_PIN GP17

#define POINTING_DEVICE_INVERT_Y

#define PMW33XX_CPI 800 // default is 1600
#define PMW33XX_LIFTOFF_DISTANCE 0x01