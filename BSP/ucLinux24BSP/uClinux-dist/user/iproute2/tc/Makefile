TCOBJ=tc.o tc_qdisc.o tc_class.o tc_filter.o tc_util.o m_police.o m_estimator.o

include ../Config

TCMODULES :=
TCMODULES += strtod.o #mcli add
TCMODULES += q_fifo.o
TCMODULES += q_sfq.o
TCMODULES += q_red.o
TCMODULES += q_prio.o
TCMODULES += q_tbf.o
TCMODULES += q_cbq.o
TCMODULES += f_rsvp.o
TCMODULES += f_u32.o
TCMODULES += f_route.o
TCMODULES += f_fw.o
ifeq ($(TC_CONFIG_DIFFSERV),y)
  TCMODULES += q_dsmark.o
  TCMODULES += q_gred.o
  TCMODULES += f_tcindex.o
  TCMODULES += q_ingress.o
  CFLAGS += -DTC_CONFIG_DIFFSERV
endif
ifeq ($(TC_CONFIG_ATM),y)
  TCMODULES += q_atm.o
  LDLIBS += -latm
  CFLAGS += -DTC_CONFIG_ATM
endif

#TCMODULES += q_csz.o
#TCMODULES += q_hpfq.o
#TCMODULES += q_hfsc.o

TCOBJ += $(TCMODULES)

TCLIB := tc_core.o
TCLIB += tc_red.o
TCLIB += tc_cbq.o
TCLIB += tc_estimator.o

LDLIBS := -L. -ltc -lm $(LDLIBS)
# LDFLAGS += -Wl,-export-dynamic

all: libtc.a tc

tc:$(TCOBJ) $(LIBNETLINK) $(LIBUTIL) $(TCLIB)

libtc.a: $(TCLIB)
	$(CROSS)ar rcs $@ $(TCLIB)

romfs:
	$(ROMFSINST) -e CONFIG_USER_IPROUTE2_TC_TC /bin/tc

clean:
	rm -f $(TCOBJ) $(TCLIB) libtc.a tc *.gdb

