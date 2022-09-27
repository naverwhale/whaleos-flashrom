/*
 * This file is part of the flashrom project.
 *
 * Copyright 2021 Google LLC
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "wp_chip_info.h"
#include "flashchips.h"

const struct wp_chip_info chips_to_test[] = {
	{ 0x9C, 0, 0, 0, 0, 0x7c, "A25L040" },
	{ 0x9C, 1, 1, 0, 0, 0x7c, "AT25SF128A" },
	{ 0x9C, 1, 1, 0, 0, 0x7c, "AT25SL128A" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "EN25F40" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "EN25Q128" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "EN25Q32(A/B)" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "EN25Q40" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "EN25Q64" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "EN25Q80(A)" },
	{ 0x9C, 0, 1, 0, 0, 0x7c, "EN25QH128" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "EN25S64" },
	{ 0xFC, 0, 1, 0, 0, 0x7c, "GD25LQ128C/GD25LQ128D" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "GD25LQ32" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "GD25LQ64(B)" },
	{ 0x9C, 0, 1, 0, 0, 0x7c, "GD25Q127C/GD25Q128C" },
	{ 0x9C, 1, 0, 0, 0, 0x7c, "GD25Q256D" },
	{ 0xFC, 0, 1, 0, 0, 0x7c, "GD25Q32(B)" },
	{ 0x9C, 0, 1, 0, 0, 0x7c, "GD25Q40(B)" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "GD25Q64(B)" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "MX25L1005(C)/MX25L1006E" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "MX25L1605" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "MX25L2005(C)/MX25L2006E" },
	{ 0xBC, 0, 0, 1, 0, 0x3c, "MX25L25635F/MX25L25645G" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "MX25L3205(A)" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "MX25L4005(A/C)/MX25L4006E" },
	{ 0xBC, 0, 0, 0, 0, 0x3c, "MX25L6405" },
	{ 0xBC, 0, 0, 1, 0, 0x3c, "MX25L6495F" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "MX25L8005/MX25L8006E/MX25L8008E/MX25V8005" },
	{ 0x9C, 1, 0, 1, 0, 0x3c, "MX25U12835F" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "MX25U3235E/F" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "MX25U6435E/F" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "N25Q064..1E" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "N25Q064..3E" },
	{ 0x9C, 0, 0, 0, 1, 0x1c, "S25FL256S Large Sectors" },
	{ 0x9C, 0, 0, 0, 1, 0x1c, "S25FL256S Small Sectors" },
	{ 0x9C, 0, 0, 0, 1, 0x1c, "S25FS128S Large Sectors" },
	{ 0x9C, 0, 0, 0, 1, 0x1c, "S25FS128S Small Sectors" },
	{ 0x9C, 1, 1, 0, 0, 0x7c, "W25Q128.JW.DTR" },
	{ 0x9C, 1, 1, 0, 0, 0x7c, "W25Q128.V" },
	{ 0x9C, 0, 1, 0, 0, 0x7c, "W25Q128.V..M" },
	{ 0x9C, 1, 1, 0, 0, 0x7c, "W25Q128.W" },
	{ 0x9C, 1, 0, 0, 0, 0x7c, "W25Q16.V" },
	{ 0x9C, 1, 1, 0, 0, 0x7c, "W25Q256JV_M" },
	{ 0x9C, 1, 1, 0, 0, 0x7c, "W25Q256.V" },
	{ 0x9C, 1, 0, 0, 0, 0x7c, "W25Q32JW...M" },
	{ 0x9C, 1, 0, 0, 0, 0x7c, "W25Q32.V" },
	{ 0x9C, 1, 0, 0, 0, 0x7c, "W25Q32.W" },
	{ 0x9C, 1, 0, 0, 0, 0x7c, "W25Q64.V" },
	{ 0x9C, 1, 0, 0, 0, 0x7c, "W25Q64.W" },
	{ 0x9C, 1, 0, 0, 0, 0x7c, "W25Q80.V" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "W25X10" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "W25X20" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "W25X40" },
	{ 0x9C, 0, 0, 0, 0, 0x7c, "W25X80" },
	{ 0x9C, 1, 1, 0, 0, 0x7c, "XM25QH128C" },
	{ 0x9C, 1, 1, 0, 0, 0x7c, "XM25QH256C" },

	// Not testable:
	// Opaque flash chip
	// Variable Size SPI chip
};

const size_t chips_to_test_len = sizeof(chips_to_test) / sizeof(struct wp_chip_info);

