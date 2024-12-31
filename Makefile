# SPDX-License-Identifier: Apache-2.0
# Copyright (c) 2019 KapaXL (kapa.xl@outlook.com)

LD = $(CROSS_COMPILE)ld
CC = $(CROSS_COMPILE)gcc
STRIP = $(CROSS_COMPILE)strip

LIB = $(shell $(CC) -print-file-name=libgcc.a) -L$(MBEDTEE_LIBC) -lc

CFLAGS = -Wall -Werror -O2 -nostdlib -std=gnu99 ${ARCH_CFLAGS} -I$(MBEDTEE_INC) -I$(MBEDTEE_INC)/tee

LDFLAGS = -EL -pie -nostdlib -z max-page-size=4096

APP = mbedtee-helloworld-ta
MOD = mbedtee-helloworld-temp

SRCS = mbedtee-helloworld-ta.c
OBJS = ${SRCS:.c=.o}

all : ${MOD}.mk
	${MAKE} -f ${MOD}.mk ${OBJS}
	${LD} $(LDFLAGS) -o ${APP} ${OBJS} ${LIB}
	${STRIP} -d -R .comment ${APP}

${MOD}.mk : ${SRCS}
	@cp -f Makefile $@ && chmod +w $@
	@${CC} ${CFLAGS} -M ${SRCS} >> $@

clean :
	@rm -rf ${OBJS} ${MOD}.mk
