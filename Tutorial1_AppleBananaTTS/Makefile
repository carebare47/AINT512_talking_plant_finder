#
# Makefile for first UNIX Nuance Application
# described in the Get Started booklet
# The ONLY env var that need be set is NUANCE
#

INCDIR = $(NUANCE)/include
BINDIR = .
OBJDIR = .
LIBDIR = $(NUANCE)/lib/$(MACHINE_TYPE)$(OPTION)

include $(NUANCE)/common/Makefile.include.$(MACHINE_TYPE)

$(BINDIR)/uxApp:	$(OBJDIR)/app1.o
	$(CXX) -o $@ $(OBJDIR)/app1.o -L$(LIBDIR) $(RCAPI_LIB) $(LDFLAGS)

$(OBJDIR)/app1.o:	app1.c
	$(CXX) -c $(NUANCE_CFLAGS) -I$(INCDIR) -o $@ app1.c

clean:
	rm -f $(BINDIR)/uxApp $(OBJDIR)/app1.o
