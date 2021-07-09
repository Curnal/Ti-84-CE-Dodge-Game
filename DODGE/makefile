# ----------------------------
# Makefile Options
# ----------------------------

NAME ?= DODGE
ICON ?= icon.png
DESCRIPTION ?= "First Game. Dodge the randomly gen circles!"
COMPRESSED ?= NO
ARCHIVED ?= NO

CFLAGS ?= -Wall -Wextra -Oz
CXXFLAGS ?= -Wall -Wextra -Oz

# ----------------------------

ifndef CEDEV
$(error CEDEV environment path variable is not set)
endif

include $(CEDEV)/meta/makefile.mk
