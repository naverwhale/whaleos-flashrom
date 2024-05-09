/*
 * This file is part of the flashrom project.
 *
 * Copyright (C) 2011 The Chromium OS Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 *
 * power.c: power management routines
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>

#include "flash.h"	/* for msg_* */
#include "power.h"

/*
 * Returns the path to a lock file in which flashrom's PID should be written to
 * instruct powerd not to suspend or shut down.
 *
 * powerd checks for arbitrary lock files within /run/lock/power_override.
 */
#define POWERD_LOCK_FILE_PATH "/run/lock/power_override/flashrom.lock"

int disable_power_management(void)
{
	FILE *lock_file = NULL;
	int rc = 0;
	mode_t old_umask;

	msg_pdbg("%s: Disabling power management.\n", __func__);

	old_umask = umask(022);
	lock_file = fopen(POWERD_LOCK_FILE_PATH, "w");
	umask(old_umask);
	if (!lock_file) {
		msg_perr("%s: Failed to open %s for writing: %s\n",
			__func__, POWERD_LOCK_FILE_PATH, strerror(errno));
		return 1;
	}

	if (fprintf(lock_file, "%ld", (long)getpid()) < 0) {
		msg_perr("%s: Failed to write PID to %s: %s\n",
			__func__, POWERD_LOCK_FILE_PATH, strerror(errno));
		rc = 1;
	}

	if (fclose(lock_file) != 0) {
		msg_perr("%s: Failed to close %s: %s\n",
			__func__, POWERD_LOCK_FILE_PATH, strerror(errno));
	}
	return rc;

}

int restore_power_management(void)
{
	int result = 0;

	msg_pdbg("%s: Re-enabling power management.\n", __func__);

	result = unlink(POWERD_LOCK_FILE_PATH);
	if (result != 0 && errno != ENOENT)  {
		msg_perr("%s: Failed to unlink %s: %s\n",
			__func__, POWERD_LOCK_FILE_PATH, strerror(errno));
		return 1;
	}
	return 0;
}
