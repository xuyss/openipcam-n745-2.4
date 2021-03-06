/* $Id: inet_aton.h,v 1.1.1.1 2006-07-11 09:33:11 andy Exp $ */

#ifndef _BSD_INET_ATON_H
#define _BSD_INET_ATON_H

#include "config.h"

#ifndef HAVE_INET_ATON
int inet_aton(const char *cp, struct in_addr *addr);
#endif /* HAVE_INET_ATON */

#endif /* _BSD_INET_ATON_H */
