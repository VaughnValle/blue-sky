/* SLiM - Simple Login Manager
   Copyright (C) 2009 Eygene Ryabinkin <rea@codelabs.ru>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
*/

#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "util.h"

/*
 * Interface for random number generator.  Just now it uses ordinary
 * random/srandom routines and serves as a wrapper for them.
 */
void Util::srandom(unsigned long seed)
{
	::srandom(seed);
}

long Util::random(void)
{
	return ::random();
}

/*
 * Makes seed for the srandom() using "random" values obtained from
 * getpid(), time(NULL) and others.
 */
long Util::makeseed(void)
{
	struct timespec ts;
	long pid = getpid();
	long tm = time(NULL);

	if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0)
		ts.tv_sec = ts.tv_nsec = 0;

	return pid + tm + (ts.tv_sec ^ ts.tv_nsec);
}
