# 
# Copyright (C) 2007 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=hej
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/hej
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=example hopefully it will work
  URL:=http://www.none.c
endef

define Package/hej/description
	This tool can be used to access physical memory addresses from userspace. 
	It can be useful to access hardware for which no device driver exists!
endef

define Build/Prepare
	$(INSTALL_DIR) $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -Os $(PKG_BUILD_DIR)/hej.c -o $(PKG_BUILD_DIR)/$(PKG_NAME)
endef

define Package/hej/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/hej $(1)/usr/bin/
endef

$(eval $(call BuildPackage,hej))
