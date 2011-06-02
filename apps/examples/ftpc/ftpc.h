/****************************************************************************
 * apps/examples/ftpc/ftpc.h
 *
 *   Copyright (C) 2011 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <spudmonkey@racsa.co.cr>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __APPS_EXAMPLES_FTPC_FTPC_H
#define __APPS_EXAMPLES_FTPC_FTPC_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>

#include <apps/ftpc.h>

/****************************************************************************
 * Definitions
 ****************************************************************************/

/* Maximum size of one command line */

#ifndef CONFIG_FTPC_LINELEN
#  define CONFIG_FTPC_LINELEN 80
#endif

/* If CONFIG_STDIO_LINEBUFFER is defined, the STDIO buffer will be flushed
 * on each new line.  Otherwise, STDIO needs to be explicitly flushed to
 * see the output in context.
 */

#if CONFIG_NFILE_DESCRIPTORS > 0 && CONFIG_NFILE_STREAMS > 0 && \
    CONFIG_STDIO_BUFFER_SIZE > 0 && !defined(CONFIG_STDIO_LINEBUFFER)
#  define FFLUSH() fflush(stdout)
#else
#  define FFLUSH()
#endif

/****************************************************************************
 * Public Types
 ****************************************************************************/

typedef int (*cmd_t)(SESSION handle, int argc, char **argv);

/****************************************************************************
 * Public Data
 ****************************************************************************/

extern const char g_ftpcgreeting[];
extern const char g_ftpcprompt[];
extern const char g_fmtcmdfailed[];

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/* Network initialization */

extern int ftpc_netinit(void);

/* Current working directory support */

extern char *ftpc_getfullpath(const char *relpath);
extern void ftpc_freefullpath(char *relpath);

/* FTP command handlers */

extern int cmd_login(SESSION handle, int argc, char **argv);
extern int cmd_quit(SESSION handle, int argc, char **argv);
extern int cmd_chdir(SESSION handle, int argc, char **argv);
extern int cmd_rpwd(SESSION handle, int argc, char **argv);
extern int cmd_cdup(SESSION handle, int argc, char **argv);
extern int cmd_mkdir(SESSION handle, int argc, char **argv);

extern int cmd_rmdir(SESSION handle, int argc, char **argv);
extern int cmd_unlink(SESSION handle, int argc, char **argv);
extern int cmd_chmod(SESSION handle, int argc, char **argv);
extern int cmd_rename(SESSION handle, int argc, char **argv);
extern int cmd_size(SESSION handle, int argc, char **argv);
extern int cmd_time(SESSION handle, int argc, char **argv);
extern int cmd_idle(SESSION handle, int argc, char **argv);
extern int cmd_noop(SESSION handle, int argc, char **argv);
extern int cmd_rhelp(SESSION handle, int argc, char **argv);
extern int cmd_rls(SESSION handle, int argc, char **argv);
extern int cmd_get(SESSION handle, int argc, char **argv);
extern int cmd_put(SESSION handle, int argc, char **argv);

#endif /* __APPS_EXAMPLES_FTPC_FTPC_H */